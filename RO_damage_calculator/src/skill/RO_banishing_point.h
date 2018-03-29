/**
*** Author: R-CO
*** E-Mail: daniel1820kobe@gmail.com
*** Date:   2018-03-29
**/

#ifndef _RO_BANISHING_POINT_H_
#define _RO_BANISHING_POINT_H_

#include "..\RO_damage_calculator.h"

namespace rco {

class BanishingPoint
{
public:
    static double CalcSkillRatio(const RoDamageCalculator &ro_damage_calculator, const int skill_level = 10, const int bash_level = 10);
}; // end of class "BanishingPoint"

} // end of namespace "rco"

#endif // end of define "_RO_BANISHING_POINT_H_"
