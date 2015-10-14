(function($) {
    var moduleName = "backup",
    operation = {
        get_List: 0,
        back_Up: 1,
        recover: 2,
        delete_item: 3,
        upIp: 4,
        queryIp: 5
    };
    var returnCode = {
        returnSuccess : 0,
        returnError : 1
    };

    var passedMsg = null;
    var letterOnlyCodeLen = 60;
    var otherCodeLen = 70;
    var codeTypeLen, unitLen;
    var smsNumMax = 5;
    var textAreaLenLast = letterOnlyCodeLen;
    var checkTimes = 0;
    var MAX_CHECK_TIME = 20;
    var MAX_CHECK_TIME_LONG_SMS = 30;
    var maxCheckTime;
    var smsCount;

    function validateForm() {
        $.Validator.addRule('countChars', function() {
            return countChars();
        }, $.i18n.prop('errMsgCountExceed'));

        $('#backUpSection').validate({
            rules: {
                nContentInput: {
                    //'required': true,
                    'countChars': true
                }
            }
        });
    }

    function countChars()
    {
        var text = $('#nContentInput').val();
        var charCounters = text.length;
        var i;

        if (charCounters <= textAreaLenLast || codeTypeLen !== otherCodeLen) {
            for (i = 0; i < charCounters; i++) {
                if (text.charCodeAt(i) >= 0x80) {
                    codeTypeLen = otherCodeLen;
                    break;
                }
            }
            if (i === charCounters) {
                codeTypeLen = letterOnlyCodeLen;
            }
        }

        if (!text) {
            codeTypeLen = letterOnlyCodeLen;
        }

        unitLen = codeTypeLen;
        if (charCounters > unitLen) {
            if (codeTypeLen === letterOnlyCodeLen) {
                unitLen = codeTypeLen - 7;
            } else if(codeTypeLen === otherCodeLen) {
                unitLen = codeTypeLen - 3;
            }
        }
        var tmp = charCounters % unitLen;
        smsCount = (tmp === 0) ? (charCounters/unitLen) :
                         ((charCounters-tmp+unitLen)/unitLen);

        var charRemain = (tmp === 0 && smsCount > 0)?tmp:(unitLen - tmp);
        $('#wordCount').text(charRemain + "/" + smsCount);
        textAreaLenLast = charCounters;

        if (smsCount > smsNumMax) {
            text = text.substring(0, smsNumMax*unitLen);
            smsCount = smsNumMax;
            tmp = unitLen;
            return false;
        }else {
            return true;
        }
    }

    function sendMessage() {
        var content = $('#nContentInput').val();

        /*  check the table is valid or not  */
        if (!$('#backUpSection').valid()) {
            return;
        }

        var date = new Date();
        var dateString = [date.getFullYear(), date.getMonth()+1, date.getDate(),
                date.getHours(), date.getMinutes(), date.getSeconds()].join(',');

        var req = {};

        /* the data sent to server*/
        req.sendMessage = {
            remark : content,
        };

        if (passedMsg && passedMsg.index !== undefined) {
            req.sendMessage.index = passedMsg.index;
        }

        callJSON(moduleName,operation.back_Up,req.sendMessage, function(data) {
            switch(data.result)
            {
            case 1:
                $('#nContentInput').val('');
                checkTimes = 0;
                countChars();
                passedMsg = null;
                Settings.showSavedDialog($.i18n.prop('smsSent'));
                break;
            case 2:
                $('#errMessage').text($.i18n.prop('sms2'));
                $('#errMessagePopup').popup('show');
                Settings.closeWaitingDialog();
                break;
            case 3:
                $('#errMessage').text($.i18n.prop('sms3'));
                $('#errMessagePopup').popup('show');
                Settings.closeWaitingDialog();
                break;
            case 4:
                $('#errMessage').text($.i18n.prop('sms4'));
                $('#errMessagePopup').popup('show');
                Settings.closeWaitingDialog();
                break;
            case 5:
                $('#errMessage').text($.i18n.prop('sms5'));
                $('#errMessagePopup').popup('show');
                Settings.closeWaitingDialog();
                break;
            default:
                $('#errMessage').text($.i18n.prop('smsSendUnknownError'));
                $('#errMessagePopup').popup('show');
                Settings.closeWaitingDialog();
                break;
            }
        });
        Settings.showWaitingDialog($.i18n.prop('smsSending'));
    }

    function setupListeners() {
        $('#BackUpBtn').click(function() {
            sendMessage();
        });
        $('#nContentInput').bind('input propertychange blur change', countChars);
    }

    function langSwitch() {
        $.i18n.elementLocalization('#adv_panel-wrapper', ['label', 'span','button']);
        $.i18n.switchFont();
    }


    function setContent() {
        getConfigJSON(moduleName, loadData);
    }

    function loadData(data) {

    }

    $.backup = {
        onLoad: function() {
            langSwitch();
            setContent();
            $('#errMessagePopup').popup({$closeButtons: $('#errOK')});
            validateForm();
            if (Settings.passedMsg) {
                passedMsg = Settings.passedMsg;
                Settings.passedMsg = null;

                if (passedMsg.content !== undefined) {
                    $('#nContentInput').val(passedMsg.content);
                } else {
                    $('#nContentInput').focus();
                }
            } else {
                passedMsg = null;
            }

            setupListeners();
            countChars();
        },
        onLeave: function() {
            passedMsg = null;
        }
    };
})(jQuery);
