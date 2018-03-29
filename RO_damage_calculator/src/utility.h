/**
*** Author: R-CO
*** E-Mail: daniel1820kobe@gmail.com
*** Date:   2018-03-27
**/

#ifndef _RO_UTILITY_H_
#define _RO_UTILITY_H_

namespace rco {

class Utility
{
public:
    static double IntToPercent(int integer) {
        return static_cast<double>(integer) / 100.0;
    }
}; // end of class "Utility"

} // end of namespace "rco"

#endif // end of _RO_UTILITY_H_
