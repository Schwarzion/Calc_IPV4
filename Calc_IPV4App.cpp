/***************************************************************
 * Name:      Calc_IPV4App.cpp
 * Purpose:   Code for Application Class
 * Author:    lehouck_v ()
 * Created:   2018-04-05
 * Copyright: lehouck_v ()
 * License:
 **************************************************************/

#include "Calc_IPV4App.h"

//(*AppHeaders
#include "Calc_IPV4Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(Calc_IPV4App);

bool Calc_IPV4App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Calc_IPV4Frame* Frame = new Calc_IPV4Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
