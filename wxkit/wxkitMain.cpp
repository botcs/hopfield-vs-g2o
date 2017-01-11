/***************************************************************
 * Name:      wxkitMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2014-09-08
 * Copyright:  ()
 * License:
 **************************************************************/

#include "wxkitMain.h"
#include <wx/msgdlg.h>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <wx/dcclient.h>

using namespace std;
using pt = pair<int,int>;
vector<pt> coords;

//(*InternalHeaders(wxkitFrame)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(wxkitFrame)
const long wxkitFrame::ID_STATICTEXT1 = wxNewId();
const long wxkitFrame::ID_TEXTCTRL1 = wxNewId();
const long wxkitFrame::ID_LISTCTRL1 = wxNewId();
const long wxkitFrame::ID_LISTCTRL2 = wxNewId();
const long wxkitFrame::ID_BUTTON1 = wxNewId();
const long wxkitFrame::ID_BUTTON2 = wxNewId();
const long wxkitFrame::ID_SLIDER2 = wxNewId();
const long wxkitFrame::ID_SLIDER1 = wxNewId();
const long wxkitFrame::ID_STATICTEXT2 = wxNewId();
const long wxkitFrame::ID_STATICTEXT3 = wxNewId();
const long wxkitFrame::ID_SPINCTRL1 = wxNewId();
const long wxkitFrame::ID_SPINCTRL2 = wxNewId();
const long wxkitFrame::ID_STATICTEXT5 = wxNewId();
const long wxkitFrame::ID_STATICTEXT4 = wxNewId();
const long wxkitFrame::ID_BUTTON3 = wxNewId();
const long wxkitFrame::ID_BUTTON4 = wxNewId();
const long wxkitFrame::ID_BUTTON5 = wxNewId();
const long wxkitFrame::ID_BUTTON6 = wxNewId();
const long wxkitFrame::ID_STATICTEXT7 = wxNewId();
const long wxkitFrame::ID_STATICTEXT8 = wxNewId();
const long wxkitFrame::ID_BUTTON7 = wxNewId();
const long wxkitFrame::ID_PANEL1 = wxNewId();
const long wxkitFrame::idMenuQuit = wxNewId();
const long wxkitFrame::MENU_LOAD = wxNewId();
const long wxkitFrame::MENU_SAVE = wxNewId();
const long wxkitFrame::idMenuAbout = wxNewId();
const long wxkitFrame::ID_STATUSBAR1 = wxNewId();
const long wxkitFrame::ID_MESSAGEDIALOG1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wxkitFrame,wxFrame)
    //(*EventTable(wxkitFrame)
    //*)
END_EVENT_TABLE()

wxkitFrame::wxkitFrame(wxWindow* parent,wxWindowID id)
{


    //(*Initialize(wxkitFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(1000,600));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(104,128), wxSize(1000,600), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Coord Gate"), wxPoint(456,24), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxPoint(440,48), wxSize(100,296), wxTE_MULTILINE|wxVSCROLL|wxHSCROLL, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    ListRelCord = new wxListCtrl(Panel1, ID_LISTCTRL1, wxPoint(776,88), wxSize(100,216), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL1"));
    ListAbsCord = new wxListCtrl(Panel1, ID_LISTCTRL2, wxPoint(656,88), wxSize(100,216), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL2"));
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("--->"), wxPoint(552,200), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button2 = new wxButton(Panel1, ID_BUTTON2, _("<---"), wxPoint(552,144), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    relX = new wxSlider(Panel1, ID_SLIDER2, 0, 0, 399, wxPoint(88,376), wxSize(160,24), 0, wxDefaultValidator, _T("ID_SLIDER2"));
    relY = new wxSlider(Panel1, ID_SLIDER1, 0, 0, 399, wxPoint(16,144), wxSize(24,160), wxSL_VERTICAL, wxDefaultValidator, _T("ID_SLIDER1"));
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Rel Y"), wxPoint(16,72), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Rel X"), wxPoint(272,376), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    Yspin = new wxSpinCtrl(Panel1, ID_SPINCTRL1, _T("0"), wxPoint(8,104), wxSize(72,21), wxTAB_TRAVERSAL, -1000000, 1000000, 0, _T("ID_SPINCTRL1"));
    Yspin->SetValue(_T("0"));
    Xspin = new wxSpinCtrl(Panel1, ID_SPINCTRL2, _T("0"), wxPoint(304,376), wxSize(80,21), wxTAB_TRAVERSAL, -1000000, 1000000, 0, _T("ID_SPINCTRL2"));
    Xspin->SetValue(_T("0"));
    StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, _("Absolute coord"), wxPoint(664,64), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Relative coord"), wxPoint(784,64), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    Button3 = new wxButton(Panel1, ID_BUTTON3, _("Greedy-2-Opt"), wxPoint(440,392), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    Button4 = new wxButton(Panel1, ID_BUTTON4, _("Add current"), wxPoint(720,392), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    Button5 = new wxButton(Panel1, ID_BUTTON5, _("Delete Selected"), wxPoint(712,360), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    Button6 = new wxButton(Panel1, ID_BUTTON6, _("Modify selected to current"), wxPoint(688,328), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
    StaticText7 = new wxStaticText(Panel1, ID_STATICTEXT7, _("Distance: "), wxPoint(432,360), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    DistText = new wxStaticText(Panel1, ID_STATICTEXT8, _("0"), wxPoint(504,360), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    Button7 = new wxButton(Panel1, ID_BUTTON7, _("Hopfield"), wxPoint(448,432), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuItem3 = new wxMenuItem(Menu1, MENU_LOAD, _("Load"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(Menu1, MENU_SAVE, _("Save"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem4);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    FileDialog1 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, _("*.txt"), wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    MessageDialog1 = new wxMessageDialog(this, _("Rerouting wont work correctly with duplicated points"), _("DUPLICATE POINT"), wxOK|wxCANCEL|wxICON_ERROR, wxDefaultPosition);

    Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&wxkitFrame::SelectCoord);
    Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_COL_CLICK,(wxObjectEventFunction)&wxkitFrame::ColClick);
    Connect(ID_LISTCTRL2,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&wxkitFrame::SelectCoord);
    Connect(ID_LISTCTRL2,wxEVT_COMMAND_LIST_COL_CLICK,(wxObjectEventFunction)&wxkitFrame::ColClick);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxkitFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxkitFrame::OnButton2Click);
    Connect(ID_SLIDER2,wxEVT_SCROLL_TOP|wxEVT_SCROLL_BOTTOM|wxEVT_SCROLL_LINEUP|wxEVT_SCROLL_LINEDOWN|wxEVT_SCROLL_PAGEUP|wxEVT_SCROLL_PAGEDOWN|wxEVT_SCROLL_THUMBTRACK|wxEVT_SCROLL_THUMBRELEASE|wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&wxkitFrame::OnrelXCmdScroll);
    Connect(ID_SLIDER2,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&wxkitFrame::OnrelXCmdScroll);
    Connect(ID_SLIDER1,wxEVT_SCROLL_TOP|wxEVT_SCROLL_BOTTOM|wxEVT_SCROLL_LINEUP|wxEVT_SCROLL_LINEDOWN|wxEVT_SCROLL_PAGEUP|wxEVT_SCROLL_PAGEDOWN|wxEVT_SCROLL_THUMBTRACK|wxEVT_SCROLL_THUMBRELEASE|wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&wxkitFrame::OnrelYCmdScroll);
    Connect(ID_SLIDER1,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&wxkitFrame::OnrelYCmdScroll);
    Connect(ID_SPINCTRL1,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&wxkitFrame::OnYspinChange);
    Connect(ID_SPINCTRL2,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&wxkitFrame::OnXspinChange);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxkitFrame::G2O);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxkitFrame::NewAbsCoord);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxkitFrame::deleteSelected);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxkitFrame::ModifySelected);
    Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxkitFrame::HN);
    Panel1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&wxkitFrame::OnPanel1Paint1,0,this);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxkitFrame::OnQuit);
    Connect(MENU_LOAD,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxkitFrame::Load);
    Connect(MENU_SAVE,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxkitFrame::Save);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxkitFrame::OnAbout);
    //*)


    myRefresh();

    ListRelCord->InsertColumn(0, "x");
    ListRelCord->InsertColumn(1, "y");
    ListRelCord->SetColumnWidth(0, 50);
    ListRelCord->SetColumnWidth(1, 50);

    ListAbsCord->InsertColumn(0, "x");
    ListAbsCord->InsertColumn(1, "y");
    ListAbsCord->SetColumnWidth(0, 50);
    ListAbsCord->SetColumnWidth(1, 50);
}

wxkitFrame::~wxkitFrame()
{

    //(*Destroy(wxkitFrame)
    //*)
}

void wxkitFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void wxkitFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void wxkitFrame::Save(wxCommandEvent& event)
{
    if (FileDialog1->ShowModal() == wxID_CANCEL) return;

    TextCtrl1->SaveFile(FileDialog1->GetFilename());
}

void wxkitFrame::Load(wxCommandEvent& event)
{
    if (FileDialog1->ShowModal() == wxID_CANCEL) return;
    TextCtrl1->LoadFile(FileDialog1->GetFilename());


}

wxString conv(int i)
{
    wxString s;
    s << i;
    return s;
}

int conv(std::string s)
{
    std::stringstream ss;
    int i;
    ss << s;
    ss >> i;
    return i;
}

void wxkitFrame::ReadIn()
{
    ListAbsCord->DeleteAllItems();
    coords.clear();
    stringstream ss;
    ss << TextCtrl1->GetValue();
    int x, y;

    size_t ind = 0;
    while (ss.good())
    {
        string a, b;
        getline(ss, a, ',');
        getline(ss, b);
        stringstream t;
        t << a << ' ' << b;
        if(t >> x >> y)
        {
            coords.push_back(pt{x, y});
            ListAbsCord->InsertItem( ind , "item" );
            ListAbsCord->SetItem(ind,0,conv(x));
            ListAbsCord->SetItem(ind,1,conv(y));


            ind++;
        }
    }

    Rescale();
    myRefresh();
}


void wxkitFrame::OnButton1Click(wxCommandEvent& event)
{
    ReadIn();
}


void wxkitFrame::Paint()
{
    wxClientDC dc(Panel1);
	dc.Clear();
    dc.SetPen(*wxWHITE_PEN);
    dc.SetBrush(*wxWHITE_BRUSH);

    int  c_x = 100, c_y = 100, c_w = 250, c_h = 250, offset = 9, posX = 0, posY = 0;


    dc.DrawRectangle(c_x - offset, c_y - offset, c_w + 2*offset, c_h + 2*offset);
    for (size_t i = 0; i < coords.size(); i++)
    {
        dc.SetPen(*wxBLUE_PEN);
        const int& x = (coords[i].first-relX->GetMin())/double(relX->GetMax()-relX->GetMin()) * c_w;

        const int& y = (coords[i].second-relY->GetMin())/double(relY->GetMax()-relY->GetMin()) * c_h;

        if (i) dc.DrawLine(c_x + posX, c_y + posY, c_x + x, c_y + y);

        dc.SetPen(*wxRED_PEN);
        dc.DrawCircle(c_x + x, c_y + y, offset+2);
        posX = x, posY = y;
    }

    posX= c_x + (relX->GetValue()-relX->GetMin())/double(relX->GetMax()-relX->GetMin()) * c_w;
    posY= c_y + (relY->GetValue()-relY->GetMin())/double(relY->GetMax()-relY->GetMin()) * c_h;
    dc.SetPen(*wxRED_PEN);
    //MAGIC NUMBERS TO FIT CIRCLE!
    dc.DrawLine(posX - offset+1, posY - offset+1, posX + offset, posY + offset);
    dc.DrawLine(posX - offset+1, posY + offset-1, posX + offset, posY - offset);

}



void wxkitFrame::OnButton2Click(wxCommandEvent& event)
{
    TextCtrl1->Clear();
    for(auto& it : coords)
        *TextCtrl1 << it.first << ',' << it.second << '\n';
}



void wxkitFrame::FillRelative()
{
    ListRelCord->DeleteAllItems();
    size_t ind = 0;
    for (auto& c : coords)
    {
        ListRelCord->InsertItem( ind , "item" );
        ListRelCord->SetItem(ind,0,conv(c.first-relX->GetValue()));
        ListRelCord->SetItem(ind,1,conv(c.second-relY->GetValue()));
        ind++;
    }
}
void wxkitFrame::FillAbsolute()
{
    ListAbsCord->DeleteAllItems();
    size_t ind = 0;
    for (auto& c : coords)
    {
        ListAbsCord->InsertItem( ind , "item" );
        ListAbsCord->SetItem(ind,0,conv(c.first));
        ListAbsCord->SetItem(ind,1,conv(c.second));
        ind++;
    }
    myRefresh();

}

auto eucledian_sqdist = [&](const size_t& a, const size_t& b){
        double dx = coords[a].first - coords[b].first;
        double dy = coords[a].second - coords[b].second;
        return dx*dx+dy*dy;
    };

void wxkitFrame::myRefresh()
{
    Rescale();

    relX->SetValue(Xspin->GetValue());
    relY->SetValue(Yspin->GetValue());

    FillRelative();


    double dist = 0;
    for(int i=1; i<coords.size(); i++)
        dist+=sqrt(eucledian_sqdist(i, i-1) );

    DistText->SetLabel(conv(dist));

    this->Refresh();
    //Update();
}


void wxkitFrame::OnPanel1Paint1(wxPaintEvent& event)
{

    Paint();
}

void wxkitFrame::Rescale()
{
    #define stdminx 0
    #define stdmaxx 699
    #define stdminy 0
    #define stdmaxy 699
    int min_x, max_x, min_y, max_y;

    auto stdsize = [&](){
        min_x = stdminx,
        max_x = stdmaxx,
        min_y = stdminy,
        max_y = stdmaxy;
    };


    if(coords.size()>5){
        min_x = max_x = coords[0].first;
        min_y = max_y = coords[0].second;
    } else
        stdsize();


    for (auto& c : coords)
    {
        auto& x = c.first;
        auto& y = c.second;

        if(x < min_x) min_x = x;
        else if (x > max_x) max_x = x;

        if(y < min_y) min_y = y;
        else if (y > max_y) max_y = y;
    }



    const int& x = Xspin->GetValue();
    const int& y = Yspin->GetValue();



    if(x < min_x) min_x = x;
    else if (x > max_x) max_x = x;

    if(y < min_y) min_y = y;
    else if (y > max_y) max_y = y;

    relX->SetMax(max_x);
    relX->SetMin(min_x);

    relY->SetMax(max_y);
    relY->SetMin(min_y);


}

void wxkitFrame::OnXspinChange(wxSpinEvent& event)
{
    myRefresh();
}

void wxkitFrame::OnYspinChange(wxSpinEvent& event)
{
    myRefresh();
}

void wxkitFrame::OnrelXCmdScroll(wxScrollEvent& event)
{
    Xspin->SetValue(relX->GetValue());
    myRefresh();
}

void wxkitFrame::OnrelYCmdScroll(wxScrollEvent& event)
{
    Yspin->SetValue(relY->GetValue());
    myRefresh();
}

int wxCALLBACK
MyCompareFunction(wxIntPtr item1, wxIntPtr item2, wxIntPtr WXUNUSED(sortData))
{
    // inverse the order
    if (item1 < item2)
        return 1;
    if (item1 > item2)
        return -1;

    return 0;
}
//COPIED FROM HERE https://github.com/wxWidgets/wxWidgets/blob/master/samples/listctrl/listtest.cpp

#include <algorithm>
//#define SORT_MODIFIES_ORDER
void wxkitFrame::ColClick(wxListEvent& event)
{
    #ifdef SORT_MODIFIES_ORDER
    ListAbsCord->SortItems(MyCompareFunction, 0);
    ListRelCord->SortItems(MyCompareFunction, 0);
    //Couldn't make it work of course :)
    #endif // SORT_MODIFIES_ORDER

    #ifndef SORT_MODIFIES_ORDER
    sort(coords.begin(), coords.end(),[&](const pt& lhv, const pt& rhv)
              {
                if (event.GetColumn())
                    return lhv.second<rhv.second;
                return lhv.first<rhv.first;

              });
    #endif // SORT_MODIFIES_ORDER

    FillAbsolute();
    myRefresh();
}

void wxkitFrame::SelectCoord(wxListEvent& event)
{
    auto& p = coords[size_t(event.GetIndex())];
    Xspin->SetValue(p.first);
    Yspin->SetValue(p.second);

    myRefresh();
}



#include "kdtree.h"



void wxkitFrame::NewAbsCoord(wxCommandEvent& event)
{
    coords.emplace_back(Xspin->GetValue(), Yspin->GetValue());
    FillAbsolute();
}

void wxkitFrame::deleteSelected(wxCommandEvent& event)
{
    if(coords.empty()) return;
    auto pos = ListAbsCord->GetNextItem(-1,wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);
    coords.erase(coords.begin() + size_t(pos));
    FillAbsolute();
}

void wxkitFrame::ModifySelected(wxCommandEvent& event)
{
    if(coords.empty()) return;
    size_t ind = ListAbsCord->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);
    auto& p = coords[ind];
    p = pt{Xspin->GetValue(), Yspin->GetValue()};
    FillAbsolute();
    myRefresh();
}



void wxkitFrame::G2O(wxCommandEvent& event)
{
    if(coords.size()<3)return;
    using c 	= vector<int>;
    using p		= pair<c, bool>;


    /**GREEDY CONSTRUCT*/

    vector<p> kdt_coords;
    for(auto& i : coords)
        kdt_coords.push_back(p{c{i.first, i.second}, false});
    kdtree<2, int, bool> KDT;
    try{

        KDT.insert(kdt_coords);
        kdtree<2, int, bool>::iterator current = KDT.nearest_neighbour(kdt_coords[0].first, false);
        for (int i=0; i<coords.size(); i++)
        {
            //Visit node
            current.val() = true;
            coords[i] = pt{current.key()[0], current.key()[1]};

            size_t n=2;
            auto NNs = KDT.n_nearest_neighbour(n, current.key(), current.val());

            while(NNs.front().val() && n <= KDT.size()){
                NNs = KDT.n_nearest_neighbour(n, current.key(), current.val());
                n++;
            }
            current = NNs.front();
        }
    } catch (const exception& e) {
        ofstream F("log.txt");
        F<<e.what()<<endl;
		cout << "HIBA: " << e.what() << endl;
		MessageDialog1->Show();
		return;
	}

    /**2-OPT*/

    if(coords.size()>4){
        vector<size_t> tour, new_tour;
        for(size_t ind= 0; ind < coords.size(); ind++) {
                tour.emplace_back(ind);
                new_tour.emplace_back(ind);
        }

        auto TwoOptSwap = [&](const size_t& a, const size_t& b){
            for(size_t i=0; i < a; i++)
                new_tour[i] = tour[i];

            for(size_t i=0; i <= b-a; i++){
                new_tour[a+i] = tour[b-i];
            }

            for(size_t i=b+1; i < coords.size(); i++)
                new_tour[i] = tour[i];

        };


        cout<<"\n \n";

        vector<vector<double> > DistanceMatrix;
        for(int i =0; i<coords.size(); i++)
        {
            vector<double> row;
            for(int j =0; j<i; j++)
            {
                row.emplace_back(eucledian_sqdist(i, j));
            }
            DistanceMatrix.push_back(move(row));
        }

        auto GetMatrDist = [&](const size_t& a, const size_t& b){
            if(a == b) return double(0);

            return DistanceMatrix[a<b ? b : a ] [a<b ? a : b];
        };

        auto TourDistance = [&](const vector<size_t>& _tour){
            double dist = 0;
            for(size_t i=1; i < _tour.size(); i++)
                dist += GetMatrDist(_tour[i], _tour[i-1]);

            return dist;
        };






        int improve = 0;
        while ( improve <coords.size()/3)
        {
            double best_distance = TourDistance(tour);

            for ( int i = 1; i < coords.size() - 1; i++ )
            {
                for ( int k = i + 1; k < coords.size(); k++)
                {
                    TwoOptSwap( i, k );

                    auto new_distance = TourDistance(new_tour);
                    for(auto a: new_tour)cout<<a<<',';
                    if ( new_distance < best_distance )
                    {
                        // Improvement found so reset

                        improve = 0;
                        tour = new_tour;
                        best_distance = new_distance;
                    }
                }
            }

            improve ++;
        }


        vector<pt> new_coords(coords.size());
        for(int i=0; i<coords.size(); i++)
        {
            new_coords[i] = std::move(coords[tour[i] ]);

        }
        coords = std::move(new_coords);
    }

    FillAbsolute();
    myRefresh();
}

void wxkitFrame::HN(wxCommandEvent& event)
{
    system("./rm TSP-coords.txt HN-solution.txt");
    TextCtrl1->SaveFile("TSP-coords.txt");
    system("./tsp-hn-backend.py");
    system("./rm TSP-coords.txt");
    TextCtrl1->LoadFile("HN-solution.txt");
    ReadIn();
}
