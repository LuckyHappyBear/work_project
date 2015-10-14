(function($) {
    var moduleName = 'backup';
    var serverData,
        submitData = {};
    var operation =
    {
        get_List: 0,
        back_Up: 1,
        recover: 2,
        delete_item: 3,
        upIp: 4,
        queryIp: 5
    };

    function langSwitch() {
        $.i18n.elementLocalization('#adv_panel-wrapper', ['label', 'span', 'button']);
        $.i18n.switchFont();
    }

    function validateForm() {
        $('#dhcpSaveBtn').click(function() {
            submitData.ip = $('#ipAddressInput').val();
            callJSON(moduleName,operation.upIp,submitData, function(data) {
                switch(data.result)
                {
                case 1:
                    Settings.showSavedDialog($.i18n.prop('configSuccess'));
                    break;
                case 2:
                    Settings.showSavedDialog($.i18n.prop('sms6'));
                    break;
                default:
                    Settings.showSavedDialog($.i18n.prop('sms6'));
                    break;
                }
            });
            Settings.showWaitingDialog($.i18n.prop('processing'));
        });
    }

    function setContent() {
        req ={};
        callJSON(moduleName,operation.queryIp,req, function(data) {
            switch(data.result)
            {
            case 1:
                $('#ipAddressInput').val(data.ip);
                $('.dhcpSection').show();
                break;
            case 2:
                Settings.showSavedDialog($.i18n.prop('sms6'));
                break;
            default:
                Settings.showSavedDialog($.i18n.prop('sms6'));
                break;
            }
        });
    }

    $.configIp = {
        onLoad: function() {
            langSwitch();
            validateForm();
            setContent();
        }
    };
})(jQuery);
