/**
*** Author: R-CO
*** E-Mail: daniel1820kobe@gmail.com
*** Date:   2018-03-25
**/

#ifndef _RO_DAMAGE_CALCULATOR_H_
#define _RO_DAMAGE_CALCULATOR_H_

namespace rco {

class RoDamageCalculator
{
public:

private:
    int CalcStatesAtk() {
        int states_atk = 0;

        states_atk = str_ + (luk_ / 3) + (dex_ / 5) + (charater_level_ / 4);

        return states_atk;
    }

    int CalcMaxWeaponValue() {
        int max_weapon_value = 0;

        max_weapon_value = weapon_basic_atk_ +
            (weapon_basic_atk_ * weapon_level_ * 0.05) +
            (weapon_basic_atk_ * str_ / 200) +
            atk_extra_by_skill_ +
            weapon_max_upgrade_atk_;

        return max_weapon_value;
    }

    int CalcMinWeaponValue() {
        int min_weapon_value = 0;

        min_weapon_value = weapon_basic_atk_ -
            (weapon_basic_atk_ * weapon_level_ * 0.05) +
            (weapon_basic_atk_ * str_ / 200) +
            atk_extra_by_skill_ +
            weapon_max_upgrade_atk_;

        return min_weapon_value;
    }

    int charater_level_;
    int weapon_basic_atk_;
    int weapon_level_;
    int atk_states_;
    int atk_extra_;
    int atk_extra_by_skill_; // ex: hit enhancement
    int atk_weapon_practiced_;
    int atk_percentage_;
    int race_percentage_;
    int element_percentage_;
    int size_percentage_;
    int range_percentage_;
    int skill_percentage_;
    int def_ignored_percentage_;
    int weapon_max_upgrade_atk_;
    int weapon_min_upgrade_atk_;
    int weapon_max_atk_;
    int weapon_min_atk_;

    int str_;
    int agi_;
    int vit_;
    int int_;
    int dex_;
    int luk_;
}; // end of class "RoDamageCalculator"

} // end of namespace "rco"

#endif // end of _RO_DAMAGE_CALCULATOR_H_
