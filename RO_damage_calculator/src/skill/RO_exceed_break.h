/**
*** Author: R-CO
*** E-Mail: daniel1820kobe@gmail.com
*** Date:   2018-03-30
**/

#ifndef _RO_EXCEED_BREAK_H_
#define _RO_EXCEED_BREAK_H_

#include "..\RO_damage_calculator.h"

namespace rco {

class ExceedBreak
{
public:
    static double CalcSkillRatio(const RoDamageCalculator &ro_damage_calculator, const int skill_level = 5);
}; // end of class "ExceedBreak"

} // end of namespace "rco"

#endif // end of define "_RO_EXCEED_BREAK_H_"
