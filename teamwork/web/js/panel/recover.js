(function($) {

    var moduleName = 'backup';
    var operation = {
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

    var amountPerPage = 10;
    var $headerRow;
    var $pagination;

    var msgList;

    var curMsgDetailIndex;
    var curPageNum = 0;
    var totalPageNum = 0;
    var displayLastMessage = false;

    var gettingMessage = false;

    function langSwitch() {
        $.i18n.elementLocalization('#adv_panel-wrapper', ['label', 'span', 'button']);
        $.i18n.switchFont();
    }

    /* show information by pages */
    function showMessageDetail(index) {
        if (index < 0) {
            if (curPageNum !== 1) {
                displayLastMessage = true;
                $pagination.pagination('toPage', curPageNum - 1);
            }
            return;
        } else if (index >= msgList.length){
            if (curPageNum !== totalPageNum) {
                displayLastMessage = false;
                $pagination.pagination('toPage', curPageNum + 1);
            }
            return;
        }

        curMsgDetailIndex = index;
        if (curPageNum <= 1 && curMsgDetailIndex ===0) {
            $('#prevMessageBtn').addClass('disabled');
        } else {
            $('#prevMessageBtn').removeClass('disabled');
        }

        if (curPageNum >= totalPageNum && curMsgDetailIndex === msgList.length - 1) {
            $('#nextMessageBtn').addClass('disabled');
        } else {
            $('#nextMessageBtn').removeClass('disabled');
        }

        var msg = msgList[index];
        $('#msgDetailNumber').text(msg.to);
        $('#msgDetailDate').text(msg.timestamp);
        $('#msgDetailText').text(msg.remark);
    }

    /* set the Content of Table */
    function setTableContent(datas) {
        $headerRow.nextAll().remove();
        msgList = datas.item;
        if(!msgList || msgList.length === 0) {
            $('#deleteMessage').addClass('disable');
            $('#deleteMessage').unbind('click');
        }else {
            $('#deleteMessage').removeClass('disable');
            $('#deleteMessage').unbind('click').click(function() {
                if ($headerRow.nextAll().find('input:checked').length > 0) {
                    $('#deletePopup').popup('show');
                } else {
                    $('#deleteEmptyPopup').popup('show');
                }
            });
        }

        var contentHTML = '',
            row = 0,
            msg = {};

        /* code for create table */

        for (row = 0; row < amountPerPage && row < msgList.length; row++) {
            msg = msgList[row];
            contentHTML += '<tr><td><label class="checkbox child">' +
                '<input type="checkbox" id="dbid' + msg.dbid + '">' +
                '<span class="icon-unchecked"></span>' +
                '</label></td><td id="timestamp' +msg.dbid + '"></td>' +
                '<td class="sms-content" id="remark'+ msg.dbid + '"></td>';
        }
        var $content = $(contentHTML);
        $headerRow.after($content);
        for (row = 0; row < amountPerPage && row < msgList.length; row++) {
            msg = msgList[row];
            $("#timestamp"+msg.dbid).text(msg.timestamp);
            $("#remark"+msg.dbid).text(msg.remark);
        }
////////
        if ((typeof(datas.usedvolume)==='undefined')&&(typeof(datas.fullvolume)==='undefined')){
            $("#used").css('display','none');
            $("#full").css('display','none');
        }else{
            $("#used").text("[ used : "+datas.usedvolume);
            $("#full").text(", total : "+datas.fullvolume+" ]");
        }

        $content.find('.checkbox').checkbox();
        $content.find('.checkbox').click( function() {
            var i = 0;
            var father = $(":checkbox").index($(this).find(':checkbox'));
            var son ;
            $content.find('.checkbox input').each(function() {
                son = $(":checkbox").index($(this));
                if (son != father){
                    $(this).removeAttr("checked");
                    $(this).next().removeClass("icon-checked").addClass('icon-unchecked');
                }
                if($(this).prop('checked')) {
                    i++;
                }

                if(i === msgList.length) {
                    $('#selectAll').checkbox('setChecked', true);
                }else {
                    $('#selectAll').checkbox('setChecked', false);
                }
            });
        });

        $content.click(function(event) {
            if ($(event.target).closest('td').prev().length === 0) { return; }
            showMessageDetail($(this).index() - 1);
            $('#msgDetailContent').show();
            $('#outboxContent').hide();
        });

        if ($('#msgDetailContent').is(':visible')) {
            if (displayLastMessage) {
                showMessageDetail(msgList.length - 1);
            } else {
                showMessageDetail(0);
            }
        }

        totalPageNum = Math.ceil(10/amountPerPage);
        $pagination.pagination('pageCount', totalPageNum);
        $('#selectAll').checkbox('change', false);
    }

    function getMessages(page) {
        var req = {};
        req.pageNumber = page;
        req.amountPerPage = amountPerPage;
        req.box = 1;

        if (gettingMessage === true) { return; }
        gettingMessage = true;

        /*  getMessages */
        callJSON(moduleName,operation.get_List,req,function(data) {
            switch(data.result)
            {
            case 1:
                gettingMessage = false;
                if(data.usedvolume ===0 ){
                    Settings.showFailedDialog($.i18n.prop('sms8'));
                }
                setTableContent(data);
                curPageNum = page > totalPageNum ? totalPageNum : page;
                break;
            case 2:
                Settings.showFailedDialog($.i18n.prop('sms6'));
                data.item = [];
                gettingMessage = false;
                setTableContent(data);
                curPageNum = page > totalPageNum ? totalPageNum : page;
                break;
            case 3:
                Settings.showFailedDialog($.i18n.prop('sms7'));
                data.item = [];
                gettingMessage = false;
                setTableContent(data);
                curPageNum = page > totalPageNum ? totalPageNum : page;
                break;
            default:
                Settings.showFailedDialog($.i18n.prop('deleteFailedText'));
                break;
            }
        }, function() {
            gettingMessage = false;
        });
    }

    function deleteMessage() {
        var id ;
        $headerRow.nextAll().find('input:checked').each(function() {
            id = parseInt($(this).attr('id').substring(4));
        });

        var req = {};
        req.box = 1;
        req.dbid = id;
        callJSON(moduleName, operation.recover, req, function(response) {
            $pagination.pagination('refresh');
            switch(response.result)
            {
            case 1:
                Settings.showSavedDialog($.i18n.prop('deleteSuccessText'));
                break;
            case 2:
                Settings.showFailedDialog($.i18n.prop('sms6'));
                break;
            case 3:
                Settings.showFailedDialog($.i18n.prop('sms7'));
                break;
            default:
                Settings.showFailedDialog($.i18n.prop('recoverFailedText'));
                break;
            }

        });
        Settings.showWaitingDialog($.i18n.prop('recovering'));
    }

    function initUI() {
        $headerRow = $('#outboxHeaderRow');
        $('#selectAll').checkbox('.checkbox.child');
        $pagination = $('#outboxPagination');
        $pagination.pagination({onChanged: getMessages});
        /* refresh button */
        $("#refreshOutbox").click(function() {
            $('#tableOutbox td').empty();
            $pagination.pagination('toPage', 1);
        });
        $('#deletePopup').popup({$closeButtons: $('#deleteCancel')});

        /** delete Message **/
        $('#recoverOK').click(function() {
            $('#deletePopup').popup('hide');
            deleteMessage();
        });
        $('#deleteEmptyPopup').popup({$closeButtons: $('#deleteEmptyOK')});

        /** delete Message **/
        $('#deleteMessage').click(function() {
            if ($headerRow.nextAll().find('input:checked').length > 0) {
                $('#deletePopup').popup('show');
            } else {
                $('#deleteEmptyPopup').popup('show');
            }
        });

        $('#smsBack').click(function() {
            $('#outboxContent').show();
            $('#msgDetailContent').hide();
        });
        $('#prevMessageBtn').click(function() {
            showMessageDetail(curMsgDetailIndex - 1);
        });
        $('#nextMessageBtn').click(function() {
            showMessageDetail(curMsgDetailIndex + 1);
        });
    }

    $.recover = {
        onLoad: function() {
            langSwitch();
            initUI();
        },
        onLeave: function() {
            msgList = null;
            curPageNum = totalPageNum = 0;
            gettingMessage = false;
        }
    };
})(jQuery);

