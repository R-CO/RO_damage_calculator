/**
*** Author: R-CO
*** E-Mail: daniel1820kobe@gmail.com
*** Date:   2018-03-29
**/

#include "RO_over_brand.h"

#include "../utility.h"

double rco::OverBrand::CalcSkillRatioPartOne(const RoDamageCalculator &ro_damage_calculator, const int skill_level, const int spear_quicken_level)
{
    double skill_ratio = 0.0;

    skill_ratio =
        (Utility::IntToPercent(200 * skill_level) + Utility::IntToPercent(50 * spear_quicken_level)) *
        Utility::IntToPercent(ro_damage_calculator.charater_level_);

    return skill_ratio;
}

double rco::OverBrand::CalcSkillRatioPartTwo(const RoDamageCalculator &ro_damage_calculator, const int skill_level)
{
    double skill_ratio = 0.0;

    skill_ratio =
        (Utility::IntToPercent(100 * skill_level) + Utility::IntToPercent(ro_damage_calculator.str_ + ro_damage_calculator.dex_)) *
        Utility::IntToPercent(ro_damage_calculator.charater_level_);

    return skill_ratio;
}

double rco::OverBrand::CalcSkillRatioPartThree(const RoDamageCalculator &ro_damage_calculator, const int skill_level)
{
    double skill_ratio = 0.0;

    skill_ratio =
        (Utility::IntToPercent(100 * skill_level) + Utility::IntToPercent(100)) *
        Utility::IntToPercent(ro_damage_calculator.charater_level_);

    return skill_ratio;
}

