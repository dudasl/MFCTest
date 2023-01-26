#pragma once


// ComboBoxEdit

class ComboBoxEdit : public CEdit
{
	DECLARE_DYNAMIC(ComboBoxEdit)

public:
	ComboBoxEdit();
	virtual ~ComboBoxEdit();

    void SetFilterNextSetTextMessage() { filter_next_set_text_message_ = true; }

protected:
	DECLARE_MESSAGE_MAP()

private:
    bool filter_next_set_text_message_ = false;

public:
    virtual BOOL PreTranslateMessage(MSG* pMsg);
};


