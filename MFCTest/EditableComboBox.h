#pragma once

#include "ComboBoxEdit.h"

// EditableComboBox

class EditableComboBox : public CComboBoxEx
{
	DECLARE_DYNAMIC(EditableComboBox)

public:
	EditableComboBox();
	virtual ~EditableComboBox();

    void SetFilterNextSetTextMessage() { filter_next_set_text_message_ = true; }

protected:
	DECLARE_MESSAGE_MAP()

private:
    bool filter_next_set_text_message_ = false;

    ComboBoxEdit edit_ctrl_;

public:
//    virtual BOOL PreTranslateMessage(MSG* pMsg);
    virtual void PreSubclassWindow();
};


