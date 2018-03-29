/**
*** Author: R-CO
*** E-Mail: daniel1820kobe@gmail.com
*** Date:   2018-03-29
**/

#include "RO_banishing_point.h"

#include "../utility.h"

double rco::BanishingPoint::CalcSkillRatio(const RoDamageCalculator &ro_damage_calculator, const int skill_level, const int bash_level)
{
    double skill_ratio = 0.0;

    skill_ratio =
        (Utility::IntToPercent(50 * skill_level) + Utility::IntToPercent(30 * bash_level)) *
        Utility::IntToPercent(ro_damage_calculator.charater_level_);

    return skill_ratio;
}
