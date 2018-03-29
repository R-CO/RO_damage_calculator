/**
*** Author: R-CO
*** E-Mail: daniel1820kobe@gmail.com
*** Date:   2018-03-29
**/

#include "RO_cannon_spear.h"

#include "../utility.h"

double rco::CannonSpear::CalcSkillRatio(const RoDamageCalculator &ro_damage_calculator, const int skill_level)
{
    double skill_ratio = 0.0;

    skill_ratio =
        (Utility::IntToPercent(50 * skill_level) + (ro_damage_calculator.str_ * 0.05)) *
        Utility::IntToPercent(ro_damage_calculator.charater_level_);

    return skill_ratio;
}
