/**
*** Author: R-CO
*** E-Mail: daniel1820kobe@gmail.com
*** Date:   2018-03-29
**/

#ifndef _RO_SKILL_BASE_H_
#define _RO_SKILL_BASE_H_

#include "utility.h"

namespace rco {

class RoSkillBase
{
public:
    virtual double GetSkillRatio() {
        return skill_ratio;
    }
    
protected:
    double skill_ratio_;
    
private:
    RoSkillBase() {
    }
}; // end of class "RoSkillBase"

} // end of namespace "rco"

#endif // end of define "_RO_SKILL_BASE_H_"
