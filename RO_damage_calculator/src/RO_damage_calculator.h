/**
*** Author: R-CO
*** E-Mail: daniel1820kobe@gmail.com
*** Date:   2018-03-25
**/

#ifndef _RO_DAMAGE_CALCULATOR_H_
#define _RO_DAMAGE_CALCULATOR_H_

#include "utility.h"

#include "RO_character_states.h"

#include "skill/RO_skill_list.h"

namespace rco {

class CannonSpear;

class RoDamageCalculator
{
// skill class
    friend class CannonSpear;
    friend class BanishingPoint;
    friend class OverBrand;
    friend class ExceedBreak;
    
public:
    RoDamageCalculator(const RoCharacterStates &character_states);

private:
    int CalcStatesAtk() {
        int states_atk = 0;

        states_atk = str_ + (luk_ / 3) + (dex_ / 5) + (charater_level_ / 4);

        return states_atk;
    }

    double CalcSpecialEnhancement() {
        double special_enhancement = 0.0;

        special_enhancement = 
            (1 + Utility::IntToPercent(atk_extra_percentage_)) *
            (1 + Utility::IntToPercent(race_extra_percentage_)) *
            (1 + Utility::IntToPercent(element_extra_percentage_)) *
            (1 + Utility::IntToPercent(size_extra_percentage_));

        return special_enhancement;
    }

    int CalcMaxAfterwardsAtk() {
        int max_afterwards_atk = 0;

        max_afterwards_atk = static_cast<int>((CalcMaxWeaponValue() * Utility::IntToPercent(size_percentage_) + atk_extra_) * CalcSpecialEnhancement());

        return max_afterwards_atk;
    }

    int CalcMinAfterwardsAtk() {
        int min_afterwards_atk = 0;

        min_afterwards_atk = static_cast<int>((CalcMinWeaponValue() * Utility::IntToPercent(size_percentage_) + atk_extra_) * CalcSpecialEnhancement());

        return min_afterwards_atk;
    }

    int CalcMaxWeaponValue() {
        int max_weapon_value = 0;

        max_weapon_value = static_cast<int>(weapon_basic_atk_ +
            (weapon_basic_atk_ * weapon_level_ * 0.05) +
            (weapon_basic_atk_ * str_ / 200.0) +
            atk_extra_by_skill_ +
            weapon_max_upgrade_atk_);

        return max_weapon_value;
    }

    int CalcMinWeaponValue() {
        int min_weapon_value = 0;

        min_weapon_value = static_cast<int>(weapon_basic_atk_ -
            (weapon_basic_atk_ * weapon_level_ * 0.05) +
            (weapon_basic_atk_ * str_ / 200.0) +
            atk_extra_by_skill_ +
            weapon_min_upgrade_atk_);

        return min_weapon_value;
    }

    int CalcMaxTotalAtkAffectedByElement() {
        int max_total_atk = 0;

        max_total_atk = static_cast<int>((CalcMaxAfterwardsAtk() * (1 - Utility::IntToPercent(element_discount_percentage_)) * Utility::IntToPercent(element_afterwards_percentage_)) +
            ((CalcStatesAtk() * 2 + atk_weapon_practiced_) * Utility::IntToPercent(element_percentage_)));

        return max_total_atk;
    }

    int CalcMinTotalAtkAffectedByElement() {
        int min_total_atk = 0;

        min_total_atk = static_cast<int>((CalcMinAfterwardsAtk() * (1 - Utility::IntToPercent(element_discount_percentage_)) * Utility::IntToPercent(element_afterwards_percentage_)) +
            ((CalcStatesAtk() * 2 + atk_weapon_practiced_) * Utility::IntToPercent(element_percentage_)));

        return min_total_atk;
    }

// input
    int weapon_basic_atk_;
    int weapon_level_;
    int weapon_upgrade_level_;
    int weapon_weight_;

    int atk_extra_;
    int atk_extra_by_skill_; // ex: hit enhancement
    int atk_extra_percentage_;
    int atk_weapon_practiced_;
    int race_extra_percentage_;
    int element_extra_percentage_;
    int size_extra_percentage_;
    int boss_extra_percentage_;
    int range_extra_percentage_;
    int cri_extra_percentage_;
    std::vector<int> skill_extra_percentage_;
    int def_ignored_percentage_;
    int weapon_max_upgrade_atk_;
    int weapon_min_upgrade_atk_;

    int size_percentage_;
    int element_percentage_;
    int element_afterwards_percentage_;
    int element_discount_percentage_;

    int enemy_minus_def_;
    int enemy_multiply_def_;
    int enemy_discount_;

    RoCharacterStates character_states_;

// meta data
    int charater_level_;
    int job_level_;
    int str_;
    int agi_;
    int vit_;
    int int_;
    int dex_;
    int luk_;

// output


    int atk_states_;
    int atk_afterwards_max_;
    int atk_afterwards_min_;
    
    int weapon_max_value_;
    int weapon_min_value_;

    double special_enhancement_;
}; // end of class "RoDamageCalculator"

} // end of namespace "rco"

#endif // end of define "_RO_DAMAGE_CALCULATOR_H_"
