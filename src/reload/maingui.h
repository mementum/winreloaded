///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __MAINGUI_H__
#define __MAINGUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/listbox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/notebook.h>
#include <wx/frame.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame 
{
	private:
	
	protected:
		wxNotebook* m_notebook1;
		wxPanel* m_panel2;
		wxListBox* m_listBoxWindows;
		wxButton* m_button4;
		wxButton* m_button2;
		wxButton* m_button3;
		wxButton* m_button1;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnButtonClickStartChildProcesses( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClickReloadWindow( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClickClearList( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClickExit( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~MyFrame1();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame2
///////////////////////////////////////////////////////////////////////////////
class MyFrame2 : public wxFrame 
{
	private:
	
	protected:
	
	public:
		
		MyFrame2( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 100,150 ), long style = wxCAPTION|wxCLOSE_BOX|wxFRAME_TOOL_WINDOW|wxSTAY_ON_TOP|wxTAB_TRAVERSAL );
		
		~MyFrame2();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog1
///////////////////////////////////////////////////////////////////////////////
class MyDialog1 : public wxDialog 
{
	private:
	
	protected:
		wxNotebook* m_notebook1;
		wxPanel* m_panel2;
		wxListBox* m_listBoxWindows;
		wxButton* m_button4;
		wxButton* m_button2;
		wxButton* m_button3;
		wxButton* m_button1;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnButtonClickStartChildProcesses( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClickReloadWindow( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClickClearList( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClickExit( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MyDialog1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
		~MyDialog1();
	
};

#endif //__MAINGUI_H__
