/**
*** Author: R-CO
*** E-Mail: daniel1820kobe@gmail.com
*** Date:   2018-03-29
**/

#ifndef _RO_OVER_BRAND_H_
#define _RO_OVER_BRAND_H_

#include "..\RO_damage_calculator.h"

namespace rco {

class OverBrand
{
public:
    static double CalcSkillRatioPartOne(const RoDamageCalculator &ro_damage_calculator, const int skill_level = 5, const int spear_quicken_level = 10);
    static double CalcSkillRatioPartTwo(const RoDamageCalculator &ro_damage_calculator, const int skill_level = 5);
    static double CalcSkillRatioPartThree(const RoDamageCalculator &ro_damage_calculator, const int skill_level = 5);
}; // end of class "OverBrand"

} // end of namespace "rco"

#endif // end of define "_RO_OVER_BRAND_H_"
