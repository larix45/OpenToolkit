#include "NewDialog.h"

//(*InternalHeaders(NewDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(NewDialog)
const long NewDialog::ID_ANIMATIONCTRL1 = wxNewId();
const long NewDialog::ID_BUTTON1 = wxNewId();
const long NewDialog::ID_STATICTEXT1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(NewDialog,wxDialog)
	//(*EventTable(NewDialog)
	//*)
END_EVENT_TABLE()

NewDialog::NewDialog(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(NewDialog)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
		wxAnimation anim_1(wxEmptyString);
	AnimationCtrl1 = new wxAnimationCtrl(this, ID_ANIMATIONCTRL1, anim_1, wxPoint(184,240), wxDefaultSize, wxAC_DEFAULT_STYLE, _T("ID_ANIMATIONCTRL1"));
	Button1 = new wxButton(this, ID_BUTTON1, _("Label"), wxPoint(120,280), wxSize(208,112), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Label"), wxPoint(128,144), wxSize(144,64), 0, _T("ID_STATICTEXT1"));

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&NewDialog::OnButton1Click);
	//*)
}

NewDialog::~NewDialog()
{
	//(*Destroy(NewDialog)
	//*)
}


void NewDialog::OnButton1Click(wxCommandEvent& event)
{
    std::cout << "XD";
}
