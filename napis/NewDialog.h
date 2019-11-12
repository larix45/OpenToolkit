#ifndef NEWDIALOG_H
#define NEWDIALOG_H

//(*Headers(NewDialog)
#include <wx/animate.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/stattext.h>
//*)

class NewDialog: public wxDialog
{
	public:

		NewDialog(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~NewDialog();

		//(*Declarations(NewDialog)
		wxAnimationCtrl* AnimationCtrl1;
		wxButton* Button1;
		wxStaticText* StaticText1;
		//*)

	protected:

		//(*Identifiers(NewDialog)
		static const long ID_ANIMATIONCTRL1;
		static const long ID_BUTTON1;
		static const long ID_STATICTEXT1;
		//*)

	private:

		//(*Handlers(NewDialog)
		void OnButton1Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
