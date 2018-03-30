#include "RO_damage_calculator.h"

namespace rco {

RoDamageCalculator::RoDamageCalculator(const RoCharacterStates &character_states) 
        : character_states_(character_states),
#if __cplusplus > 199711L
          skill_extra_percentage_(RoSkillNames.size())
#else
          skill_extra_percentage_(kSkillCount)
#endif
{
    charater_level_ = character_states_.level_;
    job_level_      = character_states_.job_level_;
    str_ = character_states_.str_ + character_states_.str_extra_;
    agi_ = character_states_.agi_ + character_states_.agi_extra_;
    vit_ = character_states_.vit_ + character_states_.vit_extra_;
    int_ = character_states_.int_ + character_states_.int_extra_;
    dex_ = character_states_.dex_ + character_states_.dex_extra_;
    luk_ = character_states_.luk_ + character_states_.luk_extra_;

    
    
    
    //
    // R-CO with Glorious Spear
    //
    weapon_basic_atk_       = 130;
    weapon_level_           = 4;
    weapon_upgrade_level_   = 14;
    weapon_weight_          = 0;
    weapon_max_upgrade_atk_ = 238;
    weapon_min_upgrade_atk_ = 98;
    
    atk_extra_                            = 374+380;
    atk_extra_by_skill_                   = 0;
    atk_extra_percentage_                 = 43;
    atk_weapon_practiced_                 = 50;
    race_extra_percentage_                = 195;
    element_extra_percentage_             = 0;
    size_extra_percentage_                = 0;
    boss_extra_percentage_                = 0;
    range_extra_percentage_               = 38;
    cri_extra_percentage_                 = 0;
    skill_extra_percentage_[kCannonSpear] = 175;
    skill_extra_percentage_[kOverBrand]   = 35;
    def_ignored_percentage_               = 100;

    // R-CO with Hunting Spear
    /*weapon_basic_atk_       = 180;
    weapon_level_           = 4;
    weapon_upgrade_level_   = 12;
    weapon_weight_          = 420;
    weapon_max_upgrade_atk_ = 196;
    weapon_min_upgrade_atk_ = 84;
    
    atk_extra_                            = 374;
    atk_extra_by_skill_                   = 0;
    atk_extra_percentage_                 = 43;
    atk_weapon_practiced_                 = 50;
    race_extra_percentage_                = 20;
    element_extra_percentage_             = 0;
    size_extra_percentage_                = 0;
    boss_extra_percentage_                = 0;
    range_extra_percentage_               = 38+16;
    cri_extra_percentage_                 = 0;
    skill_extra_percentage_[kCannonSpear] = 175;
    skill_extra_percentage_[kOverBrand]   = 35;
    def_ignored_percentage_               = 100;*/

    //
    // ??? with Hunting Spear
    //
    /*weapon_basic_atk_       = 180;
    weapon_level_           = 4;
    weapon_upgrade_level_   = 9;
    weapon_weight_          = 420;
    weapon_max_upgrade_atk_ = 133;
    weapon_min_upgrade_atk_ = 63;
    
    atk_extra_                            = 320;
    atk_extra_by_skill_                   = 0;
    atk_extra_percentage_                 = 16;
    atk_weapon_practiced_                 = 50;
    race_extra_percentage_                = 0;
    element_extra_percentage_             = 0;
    size_extra_percentage_                = 0;
    boss_extra_percentage_                = 0;
    range_extra_percentage_               = 0;
    cri_extra_percentage_                 = 6+30+24+20;
    skill_extra_percentage_[kCannonSpear] = 175;
    skill_extra_percentage_[kOverBrand]   = 35;
    def_ignored_percentage_               = 100;*/

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
        (atk_afterwards_max_ + (atk_states_ * 2 + atk_weapon_practiced_)) *
        (1 + Utility::IntToPercent(range_extra_percentage_)) *
        (1 + Utility::IntToPercent(skill_extra_percentage_[kCannonSpear])) *
        CannonSpear::CalcSkillRatio(*this, 5);

    int min_damage = 
        (atk_afterwards_min_ + (atk_states_ * 2 + atk_weapon_practiced_)) *
        (1 + Utility::IntToPercent(range_extra_percentage_)) *
        (1 + Utility::IntToPercent(skill_extra_percentage_[kCannonSpear])) *
        CannonSpear::CalcSkillRatio(*this, 5);

    max_damage = max_damage;
    min_damage = min_damage;

    max_damage = 
        (atk_afterwards_max_ + (atk_states_ * 2 + atk_weapon_practiced_)) *
        (1 + Utility::IntToPercent(range_extra_percentage_)) *
        (1 + Utility::IntToPercent(skill_extra_percentage_[kBanishingPoint])) *
        BanishingPoint::CalcSkillRatio(*this, 10, 10);

    min_damage = 
        (atk_afterwards_min_ + (atk_states_ * 2 + atk_weapon_practiced_)) *
        (1 + Utility::IntToPercent(range_extra_percentage_)) *
        (1 + Utility::IntToPercent(skill_extra_percentage_[kBanishingPoint])) *
        BanishingPoint::CalcSkillRatio(*this, 10, 10);

    max_damage = max_damage;
    min_damage = min_damage;

    int damage_part_one = 
        (atk_afterwards_max_ + (atk_states_ * 2 + atk_weapon_practiced_)) *
        (1 + Utility::IntToPercent(skill_extra_percentage_[kOverBrand])) *
        OverBrand::CalcSkillRatioPartOne(*this, 5, 10);

    int damage_part_two = 
        (atk_afterwards_max_ + (atk_states_ * 2 + atk_weapon_practiced_)) *
        (1 + Utility::IntToPercent(skill_extra_percentage_[kOverBrand])) *
        OverBrand::CalcSkillRatioPartTwo(*this, 5);

    damage_part_one = damage_part_one;
    damage_part_two = damage_part_two;
    max_damage = damage_part_one + damage_part_two;

    damage_part_one = 
        (atk_afterwards_min_ + (atk_states_ * 2 + atk_weapon_practiced_)) *
        (1 + Utility::IntToPercent(skill_extra_percentage_[kOverBrand])) *
        OverBrand::CalcSkillRatioPartOne(*this, 5, 10);

    damage_part_two = 
        (atk_afterwards_min_ + (atk_states_ * 2 + atk_weapon_practiced_)) *
        (1 + Utility::IntToPercent(skill_extra_percentage_[kOverBrand])) *
        OverBrand::CalcSkillRatioPartTwo(*this, 5);

    damage_part_one = damage_part_one;
    damage_part_two = damage_part_two;
    min_damage = damage_part_one + damage_part_two;

    max_damage = max_damage;
    min_damage = min_damage;
    
    max_damage = 
        (atk_afterwards_max_ + (atk_states_ * 2 + atk_weapon_practiced_)) *
        (1 + Utility::IntToPercent(cri_extra_percentage_)) *
        (1 + Utility::IntToPercent(skill_extra_percentage_[kExceedBreak])) *
        ExceedBreak::CalcSkillRatio(*this, 5);

    min_damage = 
        (atk_afterwards_min_ + (atk_states_ * 2 + atk_weapon_practiced_)) *
        (1 + Utility::IntToPercent(cri_extra_percentage_)) *
        (1 + Utility::IntToPercent(skill_extra_percentage_[kExceedBreak])) *
        ExceedBreak::CalcSkillRatio(*this, 5);

    max_damage = max_damage;
    min_damage = min_damage;
}

}
