/***************************************************************
 * Name:      wxkitApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2016-12-31
 * Copyright:  ()
 * License:
 **************************************************************/

#include "wxkitApp.h"

//(*AppHeaders
#include "wxkitMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(wxkitApp);

bool wxkitApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	wxkitFrame* Frame = new wxkitFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
