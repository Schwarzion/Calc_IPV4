/***************************************************************
 * Name:      Calc_IPV4Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    lehouck_v ()
 * Created:   2018-04-05
 * Copyright: lehouck_v ()
 * License:
 **************************************************************/

#include "Calc_IPV4Main.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(Calc_IPV4Frame)
#include <wx/settings.h>
#include <wx/intl.h>
#include <wx/string.h>
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

//(*IdInit(Calc_IPV4Frame)
const long Calc_IPV4Frame::txt_ip = wxNewId();
const long Calc_IPV4Frame::txt_cidr = wxNewId();
const long Calc_IPV4Frame::ID_BUTTON1 = wxNewId();
const long Calc_IPV4Frame::ID_STATICTEXT2 = wxNewId();
const long Calc_IPV4Frame::ID_STATICTEXT1 = wxNewId();
const long Calc_IPV4Frame::ID_STATICTEXT4 = wxNewId();
const long Calc_IPV4Frame::ID_STATICTEXT3 = wxNewId();
const long Calc_IPV4Frame::ID_STATICTEXT9 = wxNewId();
const long Calc_IPV4Frame::ID_STATICTEXT6 = wxNewId();
const long Calc_IPV4Frame::ID_STATICTEXT8 = wxNewId();
const long Calc_IPV4Frame::ID_STATICTEXT7 = wxNewId();
const long Calc_IPV4Frame::ID_STATICTEXT5 = wxNewId();
const long Calc_IPV4Frame::ID_STATICTEXT11 = wxNewId();
const long Calc_IPV4Frame::ID_STATICTEXT12 = wxNewId();
const long Calc_IPV4Frame::ID_STATICTEXT13 = wxNewId();
const long Calc_IPV4Frame::ID_STATICTEXT14 = wxNewId();
const long Calc_IPV4Frame::ID_STATICTEXT10 = wxNewId();
const long Calc_IPV4Frame::idMenuQuit = wxNewId();
const long Calc_IPV4Frame::idMenuAbout = wxNewId();
const long Calc_IPV4Frame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Calc_IPV4Frame,wxFrame)
    //(*EventTable(Calc_IPV4Frame)
    //*)
END_EVENT_TABLE()

Calc_IPV4Frame::Calc_IPV4Frame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Calc_IPV4Frame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(649,322));
    ip = new wxTextCtrl(this, txt_ip, wxEmptyString, wxPoint(16,48), wxSize(184,21), 0, wxDefaultValidator, _T("txt_ip"));
    t_cidr = new wxTextCtrl(this, txt_cidr, wxEmptyString, wxPoint(216,48), wxSize(24,21), 0, wxDefaultValidator, _T("txt_cidr"));
    b_ip = new wxButton(this, ID_BUTTON1, _("Ok"), wxPoint(256,48), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    res_ip = new wxStaticText(this, ID_STATICTEXT2, wxEmptyString, wxPoint(376,32), wxSize(216,16), 0, _T("ID_STATICTEXT2"));
    res_ip->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));
    res_mask = new wxStaticText(this, ID_STATICTEXT1, wxEmptyString, wxPoint(376,72), wxSize(216,16), 0, _T("ID_STATICTEXT1"));
    res_mask->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Adresse IPV4"), wxPoint(72,32), wxSize(88,13), 0, _T("ID_STATICTEXT4"));
    StaticText4->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_GRAYTEXT));
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("CIDR"), wxPoint(216,32), wxSize(32,13), 0, _T("ID_STATICTEXT3"));
    StaticText3->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_GRAYTEXT));
    ip_2 = new wxStaticText(this, ID_STATICTEXT9, wxEmptyString, wxPoint(112,136), wxSize(152,13), 0, _T("ID_STATICTEXT9"));
    res_machines = new wxStaticText(this, ID_STATICTEXT6, wxEmptyString, wxPoint(112,232), wxSize(152,13), 0, _T("ID_STATICTEXT6"));
    res_wildcard = new wxStaticText(this, ID_STATICTEXT8, wxEmptyString, wxPoint(112,208), wxSize(152,13), 0, _T("ID_STATICTEXT8"));
    res_netmask = new wxStaticText(this, ID_STATICTEXT7, wxEmptyString, wxPoint(112,184), wxSize(152,13), 0, _T("ID_STATICTEXT7"));
    res_broadcast = new wxStaticText(this, ID_STATICTEXT5, wxEmptyString, wxPoint(112,160), wxSize(152,13), 0, _T("ID_STATICTEXT5"));
    StaticText2 = new wxStaticText(this, ID_STATICTEXT11, _("Réseau"), wxPoint(24,136), wxSize(48,16), 0, _T("ID_STATICTEXT11"));
    StaticText5 = new wxStaticText(this, ID_STATICTEXT12, _("Broadcast"), wxPoint(24,160), wxSize(48,16), 0, _T("ID_STATICTEXT12"));
    StaticText6 = new wxStaticText(this, ID_STATICTEXT13, _("Netmask"), wxPoint(24,184), wxSize(48,16), 0, _T("ID_STATICTEXT13"));
    StaticText7 = new wxStaticText(this, ID_STATICTEXT14, _("Wildcard"), wxPoint(24,208), wxSize(48,16), 0, _T("ID_STATICTEXT14"));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT10, _("Machines"), wxPoint(24,232), wxSize(48,16), 0, _T("ID_STATICTEXT10"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
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

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Calc_IPV4Frame::Onb_ipClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Calc_IPV4Frame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Calc_IPV4Frame::OnAbout);
    //*)
}
////////////Tools///////////

struct infos
{
    int    cidr;
    wxString  netmask;
    wxString    available_ip;
    wxString    wildcard;
};

infos tab[32] = {
    {1, "128.0.0.0", "2147483646"},
    {2, "192.0.0.0", "1073741822"},
    {3, "224.0.0.0", "536870910"},
    {4, "240.0.0.0", "268435454"},
    {5, "248.0.0.0", "134217726"},
    {6, "252.0.0.0", "67108862"},
    {7, "254.0.0.0", "33554430"},
    {8, "255.0.0.0", "16777214"},
    {9, "255.128.0.0", "8388606"},
    {10, "255.192.0.0", "4194302"},
    {11, "255.224.0.0", "2097150"},
    {12, "255.240.0.0", "1048574"},
    {13, "255.248.0.0", "524286"},
    {14, "255.252.0.0", "262142"},
    {15, "255.254.0.0", "131070"},
    {16, "255.255.0.0", "65534"},
    {17, "255.255.128.0", "32766"},
    {18, "255.255.192.0", "16382"},
    {19, "255.255.224.0", "8190"},
    {20, "255.255.240.0", "4094"},
    {21, "255.255.248.0", "2046"},
    {22, "255.255.252.0", "1022"},
    {23, "255.255.254.0", "510"},
    {24, "255.255.255.0", "254"},
    {25, "255.255.255.128", "126"},
    {26, "255.255.255.192", "62"},
    {27, "255.255.255.224", "30"},
    {28, "255.255.255.240", "14"},
    {29, "255.255.255.248", "6"},
    {30, "255.255.255.252", "2"},
    {31, "255.255.255.254", "2"},
    {32, "255.255.255.255", "1"},
};

Calc_IPV4Frame::~Calc_IPV4Frame()
{
    //(*Destroy(Calc_IPV4Frame)
    //*)
}

void Calc_IPV4Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void Calc_IPV4Frame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

////////////Events///////////

void Calc_IPV4Frame::Onb_ipClick(wxCommandEvent& event)
{
    wxString wxS_cidr(wxT(""));
    wxString wxS_ip(wxT(""));
    wxString wxS_netmask(wxT(""));
    wxString wxS_broadcast(wxT(""));
    wxString wxS_machines(wxT(""));
    wxString wxS_wildcard;
    wxS_ip = ip->GetValue();
    int cidr;
    wxString wxS_ip_broad = wxS_ip;
    cidr = wxAtoi(t_cidr->GetValue());
    //ip_2->SetLabel(wxS_ip);

    if (wxS_cidr != "" || wxS_ip != "")
    {
        if (cidr < 1 || cidr > 32)
        {
            //error.log
            wxMessageBox(wxT("CIDR must be a number between 1 and 32 included."));
        }
        else
        {
            wxS_netmask = tab[cidr - 1].netmask;  //attribution netmask
            res_netmask->SetLabel(wxS_netmask);
            res_mask->SetLabel(wxS_netmask);
            wxS_machines = tab[cidr - 1].available_ip; //attribution machine
            res_machines->SetLabel(wxS_machines);
            res_ip->SetLabel(wxS_ip);

            wxString wxS_adresse_IP(wxT(""));
            wxString wxS_adresse_IP3(wxT(""));
            wxString wxS_adresse_IP2(wxT(""));
            wxString wxS_adresse_IP1(wxT(""));
            wxString wxS_adresse_IP0(wxT(""));
            int mask1,mask2,mask3,mask4;
            int I_pos_point;

            wxS_adresse_IP = wxS_netmask;
            I_pos_point = wxS_adresse_IP.Find(".");
            wxS_adresse_IP3 = wxS_adresse_IP.Left(I_pos_point);
            wxS_adresse_IP.Remove(0,(I_pos_point+1));

            I_pos_point = wxS_adresse_IP.Find(".");
            wxS_adresse_IP2 = wxS_adresse_IP.Left(I_pos_point);
            wxS_adresse_IP.Remove(0,(I_pos_point+1));

            I_pos_point = wxS_adresse_IP.Find(".");
            wxS_adresse_IP1 = wxS_adresse_IP.Left(I_pos_point);
            wxS_adresse_IP.Remove(0,(I_pos_point+1));

            wxS_adresse_IP0 = wxS_adresse_IP;

            mask1 = 255 - wxAtoi(wxS_adresse_IP0);
            mask2 = 255 - wxAtoi(wxS_adresse_IP1);
            mask3 = 255 - wxAtoi(wxS_adresse_IP2);
            mask4 = 255 - wxAtoi(wxS_adresse_IP3);
            wxS_wildcard<<mask4<<'.'<<mask3<<'.'<<mask2<<'.'<<mask1;
            res_wildcard->SetLabel(wxS_wildcard);


            wxString wxS_IP0, wxS_IP1, wxS_IP2, wxS_IP3;
            I_pos_point = wxS_ip_broad.Find(".");
            wxS_IP3 = wxS_ip_broad.Left(I_pos_point);
            wxS_ip_broad.Remove(0,(I_pos_point+1));

            I_pos_point = wxS_ip_broad.Find(".");
            wxS_IP2 = wxS_ip_broad.Left(I_pos_point);
            wxS_ip_broad.Remove(0,(I_pos_point+1));

            I_pos_point = wxS_ip_broad.Find(".");
            wxS_IP1 = wxS_ip_broad.Left(I_pos_point);
            wxS_ip_broad.Remove(0,(I_pos_point+1));

            wxS_IP0 = wxS_ip_broad;
            int ip0 = wxAtoi(wxS_IP0);
            int ip1 = wxAtoi(wxS_IP1);
            int ip2 = wxAtoi(wxS_IP2);
            int ip3 = wxAtoi(wxS_IP3);

            unsigned broad0 = ip0 | mask1;
            unsigned broad1 = ip1 | mask2;
            unsigned broad2 = ip2 | mask3;
            unsigned broad3 = ip3 | mask4;
            wxString wxS_broad(wxT(""));
            wxS_broad<<broad3<<"."<<broad2<<"."<<broad1<<"."<<broad0;
            res_broadcast->SetLabel(wxS_broad);

            unsigned ad_res1 = ip0 & wxAtoi(wxS_adresse_IP0);
            unsigned ad_res2 = ip1 & wxAtoi(wxS_adresse_IP1);
            unsigned ad_res3 = ip2 & wxAtoi(wxS_adresse_IP2);
            unsigned ad_res4 = ip3 & wxAtoi(wxS_adresse_IP3);
            wxString wxS_adresse_reseau(wxT(""));
            wxS_adresse_reseau<<ad_res4<<"."<<ad_res3<<"."<<ad_res2<<"."<<ad_res1;
            ip_2->SetLabel(wxS_adresse_reseau);
        }
    }
    else
        wxMessageBox( wxT("Please fill the blanks with IPV4 address and CIDR.") );
}

void Calc_IPV4Frame::OnTextCtrl1Text(wxCommandEvent& event)
{
}

void Calc_IPV4Frame::Onmask_cidrClick(wxCommandEvent& event)
{
}
