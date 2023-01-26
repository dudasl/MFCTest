// ComboBoxEdit.cpp : implementation file
//

#include "pch.h"
#include "MFCTest.h"
#include "ComboBoxEdit.h"


// ComboBoxEdit

IMPLEMENT_DYNAMIC(ComboBoxEdit, CEdit)

ComboBoxEdit::ComboBoxEdit()
{

}

ComboBoxEdit::~ComboBoxEdit()
{
}


BEGIN_MESSAGE_MAP(ComboBoxEdit, CEdit)
END_MESSAGE_MAP()


// ComboBoxEdit message handlers

BOOL ComboBoxEdit::PreTranslateMessage(MSG* pMsg)
{
    if (pMsg->message == WM_SETTEXT && this->filter_next_set_text_message_) {
        this->filter_next_set_text_message_ = false;
        return TRUE;
    }

    return CEdit::PreTranslateMessage(pMsg);
}
