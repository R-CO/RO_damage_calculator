/**
*** Author: R-CO
*** E-Mail: daniel1820kobe@gmail.com
*** Date:   2018-03-30
**/

#include "RO_exceed_break.h"

#include "../utility.h"

double rco::ExceedBreak::CalcSkillRatio(const RoDamageCalculator &ro_damage_calculator, const int skill_level)
{
    double skill_ratio = 0.0;
    skill_ratio =
        (Utility::IntToPercent(50 * skill_level) + Utility::IntToPercent(10 * ro_damage_calculator.job_level_)) +
        (Utility::IntToPercent(ro_damage_calculator.weapon_weight_ * ro_damage_calculator.weapon_level_) * Utility::IntToPercent(ro_damage_calculator.charater_level_));

    return skill_ratio;
}
