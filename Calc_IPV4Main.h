/***************************************************************
 * Name:      Calc_IPV4Main.h
 * Purpose:   Defines Application Frame
 * Author:    lehouck_v ()
 * Created:   2018-04-05
 * Copyright: lehouck_v ()
 * License:
 **************************************************************/

#ifndef CALC_IPV4MAIN_H
#define CALC_IPV4MAIN_H

//(*Headers(Calc_IPV4Frame)
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

class Calc_IPV4Frame: public wxFrame
{
    public:

        Calc_IPV4Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~Calc_IPV4Frame();

    private:

        //(*Handlers(Calc_IPV4Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void Onb_ipClick(wxCommandEvent& event);
        void OnTextCtrl1Text(wxCommandEvent& event);
        void Onmask_cidrClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(Calc_IPV4Frame)
        static const long txt_ip;
        static const long txt_cidr;
        static const long ID_BUTTON1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT9;
        static const long ID_STATICTEXT6;
        static const long ID_STATICTEXT8;
        static const long ID_STATICTEXT7;
        static const long ID_STATICTEXT5;
        static const long ID_STATICTEXT11;
        static const long ID_STATICTEXT12;
        static const long ID_STATICTEXT13;
        static const long ID_STATICTEXT14;
        static const long ID_STATICTEXT10;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(Calc_IPV4Frame)
        wxStaticText* res_machines;
        wxButton* b_ip;
        wxStaticText* res_mask;
        wxTextCtrl* t_cidr;
        wxStaticText* res_broadcast;
        wxStaticText* StaticText2;
        wxStaticText* StaticText6;
        wxStaticText* StaticText1;
        wxStaticText* StaticText3;
        wxStaticText* res_netmask;
        wxStaticText* res_ip;
        wxStaticText* StaticText5;
        wxStaticText* StaticText7;
        wxStatusBar* StatusBar1;
        wxTextCtrl* ip;
        wxStaticText* StaticText4;
        wxStaticText* ip_2;
        wxStaticText* res_wildcard;
        //*)

        DECLARE_EVENT_TABLE()
};



#endif // CALC_IPV4MAIN_H
