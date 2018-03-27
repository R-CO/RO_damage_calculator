/**
*** Author: R-CO
*** Mail: daniel1820kobe@gmail.com
*** Date: 2016-01-09
***/
#include "main.h"

#include <wx/wx.h>

// Include main_frame.h here

#include "RO_damage_calculator.h"
#include "RO_character_states.h"

IMPLEMENT_APP(WxProjectTemplateApp)

bool WxProjectTemplateApp::OnInit()
{
    wxFrame *main_frame = new wxFrame(NULL, wxID_ANY, wxT("hello world!"));

    rco::RoCharacterStates ro_character_states(175, 60,
                                               120, 100, 97, 40, 100, 54,
                                               36);
    rco::RoDamageCalculator ro_damage_calculator(ro_character_states);

    ro_damage_calculator;

    return main_frame->Show();
}
