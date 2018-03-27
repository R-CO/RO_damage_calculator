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
    RoDamageCalculator() {
        charater_level_ = 175;
        str_ = 204;
        agi_ = 140;
        vit_ = 120;
        int_ = 65;
        dex_ = 132;
        luk_ = 68;

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
        range_extra_percentage_   = 38;
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

        int damage = atk_afterwards_max_ * 
            (1 + ToPercentage(range_extra_percentage_)) *
            (1 + ToPercentage(skill_extra_percentage_)) *
            ((ToPercentage(250) + (str_ * 0.05)) * ToPercentage(175));

       damage;
    }

private:
    int CalcStatesAtk() {
        int states_atk = 0;

        states_atk = str_ + (luk_ / 3) + (dex_ / 5) + (charater_level_ / 4);

        return states_atk;
    }

    double CalcSpecialEnhancement() {
        double special_enhancement = 0.0;

        special_enhancement = (1 + static_cast<double>(atk_extra_percentage_) / 100) *
            (1 + static_cast<double>(race_extra_percentage_) / 100) *
            (1 + static_cast<double>(element_extra_percentage_) / 100) *
            (1 + static_cast<double>(size_extra_percentage_) / 100);

        return special_enhancement;
    }

    int CalcMaxAfterwardsAtk() {
        int max_afterwards_atk = 0;

        max_afterwards_atk = static_cast<int>((CalcMaxWeaponValue() * ToPercentage(size_percentage_) + atk_extra_) * CalcSpecialEnhancement());

        return max_afterwards_atk;
    }

    int CalcMinAfterwardsAtk() {
        int min_afterwards_atk = 0;

        min_afterwards_atk = static_cast<int>((CalcMinWeaponValue() * ToPercentage(size_percentage_) + atk_extra_) * CalcSpecialEnhancement());

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

        max_total_atk = static_cast<int>((CalcMaxAfterwardsAtk() * (1 - (static_cast<double>(element_discount_percentage_) / 100)) * (static_cast<double>(element_afterwards_percentage_) / 100)) +
            ((CalcStatesAtk() * 2 + atk_weapon_practiced_) * (static_cast<double>(element_percentage_) / 100)));

        return max_total_atk;
    }

    int CalcMinTotalAtkAffectedByElement() {
        int min_total_atk = 0;

        min_total_atk = static_cast<int>((CalcMinAfterwardsAtk() * (1 - (static_cast<double>(element_discount_percentage_) / 100)) * (static_cast<double>(element_afterwards_percentage_) / 100)) +
            ((CalcStatesAtk() * 2 + atk_weapon_practiced_) * (static_cast<double>(element_percentage_) / 100)));

        return min_total_atk;
    }

    double ToPercentage(const int percentage) {
        return static_cast<double>(percentage) / 100.0;
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
    int range_extra_percentage_;
    int skill_extra_percentage_;
    int def_ignored_percentage_;
    int weapon_max_upgrade_atk_;
    int weapon_min_upgrade_atk_;

    int size_percentage_;
    int element_percentage_;
    int element_afterwards_percentage_;
    int element_discount_percentage_;

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

#endif // end of _RO_DAMAGE_CALCULATOR_H_
