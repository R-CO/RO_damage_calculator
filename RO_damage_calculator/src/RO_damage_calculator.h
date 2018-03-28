/**
*** Author: R-CO
*** E-Mail: daniel1820kobe@gmail.com
*** Date:   2018-03-25
**/

#ifndef _RO_DAMAGE_CALCULATOR_H_
#define _RO_DAMAGE_CALCULATOR_H_

#include "RO_character_states.h"

#include "utility.h"

namespace rco {

class RoDamageCalculator
{
public:
    RoDamageCalculator(RoCharacterStates character_states) 
        : character_states_(character_states)
    {
        charater_level_ = character_states_.level_;
        str_ = character_states_.str_ + character_states_.str_extra_;
        agi_ = character_states_.agi_ + character_states_.agi_extra_;
        vit_ = character_states_.vit_ + character_states_.vit_extra_;
        int_ = character_states_.int_ + character_states_.int_extra_;
        dex_ = character_states_.dex_ + character_states_.dex_extra_;
        luk_ = character_states_.luk_ + character_states_.luk_extra_;
        /*str_ = 204;
        agi_ = 140;
        vit_ = 120;
        int_ = 65;
        dex_ = 132;
        luk_ = 68;*/

        weapon_basic_atk_       = 130;
        weapon_level_           = 4;
        weapon_upgrade_level_   = 14;
        weapon_weight_          = 0;
        weapon_max_upgrade_atk_ = 238;
        weapon_min_upgrade_atk_ = 98;

        atk_extra_                = 374;
        atk_extra_by_skill_       = 0;
        atk_extra_percentage_     = 43;
        atk_weapon_practiced_     = 50;
        race_extra_percentage_    = 195;
        element_extra_percentage_ = 0;
        size_extra_percentage_    = 0;
        boss_extra_percentage_    = 0;
        range_extra_percentage_   = 38;
        cri_extra_percentage_     = 0;
        skill_extra_percentage_   = 175;
        def_ignored_percentage_   = 100;

        size_percentage_               = 100;
        element_percentage_            = 100;
        element_afterwards_percentage_ = 100;
        element_discount_percentage_   = 0;

        atk_states_          = CalcStatesAtk();
        special_enhancement_ = CalcSpecialEnhancement();
        weapon_max_value_    = CalcMaxWeaponValue();
        weapon_min_value_    = CalcMinWeaponValue();
        atk_afterwards_max_  = CalcMaxAfterwardsAtk();
        atk_afterwards_min_  = CalcMinAfterwardsAtk();

        int max_damage = 
            (atk_afterwards_max_ + (atk_states_ * 2 + atk_weapon_practiced_))*
            (1 + Utility::IntToPercent(range_extra_percentage_)) *
            (1 + Utility::IntToPercent(skill_extra_percentage_)) *
            ((Utility::IntToPercent(250) + (str_ * 0.05)) * Utility::IntToPercent(charater_level_));

        int min_damage = 
            (atk_afterwards_min_ + (atk_states_ * 2 + atk_weapon_practiced_))*
            (1 + Utility::IntToPercent(range_extra_percentage_)) *
            (1 + Utility::IntToPercent(skill_extra_percentage_)) *
            ((Utility::IntToPercent(250) + (str_ * 0.05)) * Utility::IntToPercent(charater_level_));

        max_damage = max_damage;
        min_damage = min_damage;
    }

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
    int skill_extra_percentage_;
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
