$(function() {
    $.ajax({
        method: 'GET',
        url: 'storageShare',
        dataType: 'json',
        success: function(data) {
            $('#modeList').val(data.mode);
            $('#permissionList').val(data.login);
            $('#usernameVal').val(data.username);
            $('#passwordVal').val(data.password);
        }
    });

    $('#saveButton').click(function() {
        var reg = /^[a-zA-Z0-9_]{1,30}$/;
        var username = document.getElementById('usernameVal').value;
        var password = document.getElementById('passwordVal').value;
        var username_error_msg = "username should only contains char,number and underline(length is from 1 - 30)";
        var password_error_msg = "password should only contains char,number and underline(length is from 1 - 30)";
        if(!username.match(reg))
        {
            alert(username_error_msg);
            username = '';
            return false;
        }
        if(!password.match(reg))
        {
            alert(password_error_msg);
            password = '';
            return false;
        }
        $.ajax({
            method: 'POST',
            url: 'storageShare',
            dataType: 'json',
            data:JSON.stringify({
                "mode":$('modeList').val(),
                "login":$('permissionList').val(),
                "username":$('usernameVal').val(),
                "password":$('passwordVal').val(),
            }),
            success: function(data) {
                alert('post successful');
                alert('the content of the storageShare is '+data.mode+'---'+data.login+'---'+data.username+'---'+data.password);
            }
        });
    });
});

