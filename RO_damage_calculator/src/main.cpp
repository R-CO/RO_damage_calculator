/**
*** Author: R-CO
*** Mail: daniel1820kobe@gmail.com
*** Date: 2016-01-09
***/
#include "main.h"

#include <wx/wx.h>

// Include main_frame.h here

#include "RO_damage_calculator.h"
#include "character_states.h"
#include "weapon_info.h"

IMPLEMENT_APP(WxProjectTemplateApp)

bool WxProjectTemplateApp::OnInit()
{
    wxFrame *main_frame = new wxFrame(NULL, wxID_ANY, wxT("hello world!"));

    rco::CharacterStates character_states(175, 60,
                                          120, 100, 97, 40, 100, 54,
                                          36, 17, 23, 18, 22, 14);
    rco::WeaponInfo      weapon_info(130, 4, 14, 0);

    rco::RoDamageCalculator ro_damage_calculator(character_states, weapon_info);

    ro_damage_calculator;

    return main_frame->Show();
}
