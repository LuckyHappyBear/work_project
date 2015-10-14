var AUTH_MODULE = 'authenticator',
    WEB_CGI     = 'cgi-bin/web_cgi',
    AUTH_CGI    = 'cgi-bin/auth_cgi',
    BACKUP_CGI   = 'cgi-bin/backup_cgi',
    authAction  = { LOAD:0, LOGIN:1, CHECK_ATTEMPT:2, CLOSE:3, UPDATE:4 },
    unsetFacAction = 3,
    ajaxTimeout = 10 * 1000;

var AUTH_RES = {
    success: 0,
    hasLogin: 1,
    pwdWrong: 2,
    ipLocked: 3,
    otherLogin: 4,
    unknownResult: 5
};

function callJSON(moduleName, action, data, onSuccess, onError, timeout, isAsync, contOnPageChanged) {
    if (typeof moduleName === 'undefined' || typeof action === 'undefined') {
        throw 'moduleName or action can not be empty';
    }

    var jsonObj = $.extend({module: moduleName, action: action}, data);

    // Add Token to ajax data
    if (moduleName === AUTH_MODULE) {
        // For auth module, carry token only when CLOSE or UPDATE
        if (action === authAction.CLOSE || action === authAction.UPDATE) {
            var token = AuthModel.getToken();
            if (!token) { return; }
            jsonObj = $.extend({token: token}, jsonObj);
        }
    } else if (!((moduleName === 'webServer' && action !== unsetFacAction) ||
             (moduleName === 'status' && (window.location.pathname.indexOf('login.html') !== -1) ||
              window.location.pathname.indexOf('browserWarning.html') !== -1))) {
        // Carry token for all other modules
        var tokenStr = AuthModel.getToken();
        if (!tokenStr) { return; }
        jsonObj = $.extend({token: tokenStr}, jsonObj);
    }

    var url = (moduleName === AUTH_MODULE ? AUTH_CGI : WEB_CGI);

    if (moduleName === 'backup'){
        url = BACKUP_CGI;
    }
    var ret = null;
    //var pageID = g_curPageID;

    $.ajax({
        type        : 'POST',
        url         : url,
        async       : isAsync === false ? false : true,
        data        : JSON.stringify(jsonObj),
        dataType    : 'json',
        processData : false,
        cache       : false,
        timeout     : typeof timeout === 'number' ? timeout : ajaxTimeout,
        success: function(responseData, textStatus, jqXHR) {
            //if (!contOnPageChanged && pageID !== g_curPageID) { return; }

            if (typeof responseData === 'string') {
                try { responseData = JSON.parse(responseData); }
                catch(e) { if (typeof onError === 'function') { onError(e); } return; }
            }

            if (responseData.result < 0) {
                AuthModel.removeAuthToken();
                if (responseData.result === -2) {
                    AuthModel.kickedOut();
                } else if (responseData.result === -3) {
                    AuthModel.authTimeout();
                } else {
                    AuthModel.promptNotAuth();
                }
                return;
            }
            if (typeof onSuccess === 'function') {
                onSuccess(responseData, textStatus, jqXHR);
            }

            if (isAsync === false) { ret = responseData; }
        },
        error: function(jqXHR, textStatus, errorThrown) {
            //if (!contOnPageChanged && pageID !== g_curPageID) { return; }

            if (typeof onError === 'function') { onError(jqXHR, textStatus, errorThrown); }
            if (isAsync === false) {return null; }
        }
    });

    //if (!contOnPageChanged && pageID !== g_curPageID) { return; }
    if (isAsync === false) { return  ret; }
    // contentType (default: 'application/x-www-form-urlencoded; charset=UTF-8')
    // Use UTF-8 for everything, static files, post data, etc.
}

// Helper method for GET Request
function getConfigJSON(moduleName, onSuccess, onError, timeout, isAsync) {
    callJSON(moduleName, 0, null, onSuccess, onError, timeout, isAsync); // 0: GET_CONFIG
}

var AuthModel = {
    // In case cookie is disabled, store token in JS context
    g_token: '',
    // Login begins. Get nonce information first
    //login: function(username, password, loginCallback) {
    login: function(password, loginCallback) {
        if (!password) {
            return null;
        }
        var loadAuthRes = callJSON(AUTH_MODULE, authAction.LOAD, null,
                 null, null, ajaxTimeout, false);

        if (loadAuthRes === null) {
            console.log('Auth Request Error');
            return;
        }
        //var hash = CryptoJS.MD5([username, password, loadAuthRes.nonce].join(':')).toString();
        var hash = CryptoJS.MD5([password, loadAuthRes.nonce].join(':')).toString();
        var loginRes = callJSON(AUTH_MODULE, authAction.LOGIN, {'digest': hash},
                 null, null, ajaxTimeout, false);

        switch (loginRes.result) {
            case 0:
                AuthModel.setAuthToken(loginRes.token);
                loginCallback(AUTH_RES.success);
                break;
            case 1:
                loginCallback(AUTH_RES.pwdWrong);
                break;
            default:
                loginCallback(AUTH_RES.unknownResult);
                break;
        }
    },
    // Save token to session cookie or global JS context
    setAuthToken: function(token) {
        if (AuthModel.isCookieEnable()) { $.cookie('tpweb_token', token); }
        else { AuthModel.g_token = token; }
    },
    // Remove session cookie or reset JS token value
    removeAuthToken: function() {
        if (AuthModel.isCookieEnable()) { $.removeCookie('tpweb_token'); }
        else { AuthModel.g_token = ''; }
    },
    // Do logout and remove session cookie
    logout: function(callback) {
        // SET to sync so as cookie will always be removed
        var result = callJSON(AUTH_MODULE, authAction.CLOSE, null,
                 null, null, ajaxTimeout, false);
        AuthModel.removeAuthToken();                 // always removed
        callback(result);
    },
    // Get token. If not found, redirect to login page
    getToken: function() {
        var retToken = '';
        if (AuthModel.isCookieEnable()) {
            var tokenCookie = $.cookie('tpweb_token');
            if (!tokenCookie) { AuthModel.promptNotAuth(); }
            else { retToken = tokenCookie; }
        } else {
            if (!AuthModel.g_token) { AuthModel.promptNotAuth(); }
            else { retToken = g_token; }
        }
        return retToken;
    },
    promptNotAuth: function() {
        if (isPhone()){
            window.location.href = 'phoneIndex.html';
        } else if (window.location.pathname.indexOf('login.html') === -1) {
            window.location.href = 'login.html';
        }
    },
    authTimeout: function() {
        if (isPhone()){
            window.location.href = 'phoneIndex.html?timeout';
        } else if (window.location.pathname.indexOf('login.html') === -1) {
            window.location.href = 'login.html?timeout';
        }
    },
    kickedOut: function() {
        if (isPhone()){
            window.location.href = 'phoneIndex.html?kickedOut';
        } else if (window.location.pathname.indexOf('login.html') === -1) {
            window.location.href = 'login.html?kickedOut';
        }
    },
    // Check if cookie is enabled
    isCookieEnable: function() {
        $.cookie('check_cookie', 'check_cookie', { path: '/' });
        var ret = $.cookie('check_cookie') === 'check_cookie';
        if (ret) { $.removeCookie('check_cookie'); }
        return ret;
    }
};
