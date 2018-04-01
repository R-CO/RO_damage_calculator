/**
*** Author: R-CO
*** E-Mail: daniel1820kobe@gmail.com
*** Date:   2018-04-01
**/

#ifndef _WEAPON_INFO_H_
#define _WEAPON_INFO_H_

namespace rco {

class WeaponInfo
{
    //friend class RoDamageCalculator;

public:
    WeaponInfo(
        int basic_atk, int level, int upgrade_level, int weight
    )
        : basic_atk_(basic_atk), level_(level), upgrade_level_(upgrade_level), weight_(weight)
    {
        // do nothing
    }

    ~WeaponInfo()
    {
        // TODO:
    }

//
// Getters
//
    inline int GetBasicAtk() const {
        return basic_atk_;
    }

    inline int GetLevel() const {
        return level_;
    }

    inline int GetUpgradeLevel() const {
        return upgrade_level_;
    }

    inline int GetWeight() const {
        return weight_;
    }

//
// Setters
//
    inline void SetBasicAtk(const int basic_atk) {
        basic_atk_ = basic_atk;
    }

    inline void SetLevel(const int level) {
        level_ = level;
    }

    inline void SetUpgradeLevel(const int upgrade_level) {
        upgrade_level_ = upgrade_level;
    }

    inline void SetWeight(const int weight) {
        weight_ = weight;
    }

private:
    int basic_atk_;
    int level_;
    int upgrade_level_;
    int weight_;
}; // end of class "WeaponInfo"

} // end of namespace "rco"

#endif // end of define "_WEAPON_INFO_H_"
