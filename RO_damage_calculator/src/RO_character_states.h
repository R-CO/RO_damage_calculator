/**
*** Author: R-CO
*** E-Mail: daniel1820kobe@gmail.com
*** Date:   2018-03-25
**/

#ifndef _RO_CHARACTER_STATES_H_
#define _RO_CHARACTER_STATES_H_

namespace rco {

class RoCharacterStates
{
    friend class RoDamageCalculator;

public:
    RoCharacterStates()
    {
        // do nothing
    }

    RoCharacterStates(int level = 175, int job_level = 60, 
                      int str = 1, int agi = 1, int vit = 1, int intelligence = 1, int dex = 1, int luk = 1,
                      int str_extra = 0, int agi_extra = 0, int vit_extra = 0, int int_extra = 0, int dex_extra = 0, int luk_extra = 0
                      )
        : level_(level), job_level_(job_level),
          str_(str), agi_(agi), vit_(vit), int_(intelligence), dex_(dex), luk_(luk),
          str_extra_(str_extra), agi_extra_(agi_extra), vit_extra_(vit_extra), int_extra_(int_extra), dex_extra_(dex_extra), luk_extra_(luk_extra)
    {
        // do nothing
    }

    ~RoCharacterStates()
    {
        // TODO:
    }

private:
    int level_;
    int job_level_;

    int str_;
    int agi_;
    int vit_;
    int int_;
    int dex_;
    int luk_;

    int str_extra_;
    int agi_extra_;
    int vit_extra_;
    int int_extra_;
    int dex_extra_;
    int luk_extra_;
}; // end of class "RoCharacterStates"

} // end of namespace "rco"

#endif // end of _RO_CHARACTER_STATES_H_
