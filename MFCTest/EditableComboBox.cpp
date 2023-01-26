// EditableComboBox.cpp : implementation file
//

#include "pch.h"
#include "MFCTest.h"
#include "EditableComboBox.h"


// EditableComboBox

IMPLEMENT_DYNAMIC(EditableComboBox, CComboBoxEx)

EditableComboBox::EditableComboBox()
{

}

EditableComboBox::~EditableComboBox()
{
}


BEGIN_MESSAGE_MAP(EditableComboBox, CComboBoxEx)
END_MESSAGE_MAP()



// EditableComboBox message handlers


void EditableComboBox::PreSubclassWindow()
{
    //COMBOBOXINFO combobox_info{};
    //combobox_info.cbSize = sizeof(combobox_info);

    //if (this->GetComboBoxInfo(&combobox_info)) {
    //    if (combobox_info.hwndItem != NULL) {
    //        edit_ctrl_.SetOwner(this);
    //        edit_ctrl_.SubclassWindow(combobox_info.hwndItem);
    //    }
    //}

    CComboBoxEx::PreSubclassWindow();
}
