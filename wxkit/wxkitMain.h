/***************************************************************
 * Name:      wxkitMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2014-09-08
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef WXKITMAIN_H
#define WXKITMAIN_H

//(*Headers(wxkitFrame)
#include <wx/msgdlg.h>
#include <wx/spinctrl.h>
#include <wx/listctrl.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/filedlg.h>
#include <wx/panel.h>
#include <wx/slider.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class wxkitFrame: public wxFrame
{
    public:

        wxkitFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~wxkitFrame();

    private:

        //(*Handlers(wxkitFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnTextCtrl1Text(wxCommandEvent& event);
        void Save(wxCommandEvent& event);
        void Load(wxCommandEvent& event);
        void OnListCtrl1BeginDrag(wxListEvent& event);
        void OnTextCtrl1Text1(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnPanel1Paint(wxPaintEvent& event);
        void CoordRefresh(wxPaintEvent& event);
        void CoordPaint(wxPaintEvent& event);
        void RedrawPlot(wxScrollEvent& event);
        void OnPanel1Paint1(wxPaintEvent& event);
        void OnXspinChange(wxSpinEvent& event);
        void OnYspinChange(wxSpinEvent& event);
        void OnrelXCmdScroll(wxScrollEvent& event);
        void OnrelYCmdScroll(wxScrollEvent& event);
        void ColClick(wxListEvent& event);
        void SelectCoord(wxListEvent& event);
        void OnButton4Click(wxCommandEvent& event);
        void OnButton5Click(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnButton3Click1(wxCommandEvent& event);
        void OnListAbsCordBeginDrag(wxListEvent& event);
        void OnButton4Click1(wxCommandEvent& event);
        void OnButton5Click1(wxCommandEvent& event);
        void NewAbsCoord(wxCommandEvent& event);
        void deleteSelected(wxCommandEvent& event);
        void ModifySelected(wxCommandEvent& event);
        void G2O(wxCommandEvent& event);
        void HN(wxCommandEvent& event);
        //*)

        //(*Identifiers(wxkitFrame)
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_LISTCTRL1;
        static const long ID_LISTCTRL2;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_SLIDER2;
        static const long ID_SLIDER1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_SPINCTRL1;
        static const long ID_SPINCTRL2;
        static const long ID_STATICTEXT5;
        static const long ID_STATICTEXT4;
        static const long ID_BUTTON3;
        static const long ID_BUTTON4;
        static const long ID_BUTTON5;
        static const long ID_BUTTON6;
        static const long ID_STATICTEXT7;
        static const long ID_STATICTEXT8;
        static const long ID_BUTTON7;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long MENU_LOAD;
        static const long MENU_SAVE;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        static const long ID_MESSAGEDIALOG1;
        //*)

        //(*Declarations(wxkitFrame)
        wxListCtrl* ListAbsCord;
        wxPanel* Panel1;
        wxStatusBar* StatusBar1;
        wxSpinCtrl* Yspin;
        wxSlider* relY;
        wxButton* Button4;
        wxButton* Button1;
        wxStaticText* DistText;
        wxButton* Button2;
        wxListCtrl* ListRelCord;
        wxButton* Button3;
        wxStaticText* StaticText1;
        wxStaticText* StaticText3;
        wxMessageDialog* MessageDialog1;
        wxMenuItem* MenuItem3;
        wxButton* Button5;
        wxFileDialog* FileDialog1;
        wxStaticText* StaticText7;
        wxTextCtrl* TextCtrl1;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStaticText* StaticText2;
        wxMenuItem* MenuItem4;
        wxButton* Button7;
        wxSpinCtrl* Xspin;
        wxSlider* relX;
        wxButton* Button6;
        //*)

        void myRefresh();
        void Paint();
        void Rescale();
        void FillRelative();
        void FillAbsolute();
        void ReadIn();

        DECLARE_EVENT_TABLE()
};

#endif // WXKITMAIN_H
