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
public:
    RoCharacterStates()
    {
        // TODO:
    }

    ~RoCharacterStates()
    {
        // TODO:
    }

private:
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
