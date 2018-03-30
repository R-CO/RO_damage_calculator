/**
*** Author: R-CO
*** E-Mail: daniel1820kobe@gmail.com
*** Date:   2018-03-29
**/

#ifndef _RO_SKILL_LIST_H_
#define _RO_SKILL_LIST_H_

#include <string>
#include <vector>

#include "RO_cannon_spear.h"
#include "RO_banishing_point.h"
#include "RO_over_brand.h"
#include "RO_exceed_break.h"

enum RoSkill {
    kCannonSpear,
    kBanishingPoint,
    kOverBrand,
    kExceedBreak
#if __cplusplus == 199711L
    ,kSkillCount
#endif

}; // end of enum "RoSkill"

#if __cplusplus > 199711L
extern const std::vector<std::string> RoSkillNames;
#endif

#endif // end of define "_RO_SKILL_LIST_H_"
