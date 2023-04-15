/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Scripts for spells with SPELLFAMILY_EVOKER and SPELLFAMILY_GENERIC spells used by evoker players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_evo_".
 */

#include "Containers.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "SpellDefines.h"


enum EvokerSpells
{
    SPELL_EVOKER_ANIMOSITY                 = 375797,
    SPELL_EVOKER_DRAGONRAGE                = 375087,
    SPELL_EVOKER_ENERGIZING_FLAME          = 400006,
    SPELL_EVOKER_GLIDE_KNOCKBACK           = 358736,
    SPELL_EVOKER_HOVER                     = 358267,
    SPELL_EVOKER_LIVING_FLAME              = 361469,
    SPELL_EVOKER_LIVING_FLAME_DAMAGE       = 361500,
    SPELL_EVOKER_LIVING_FLAME_HEAL         = 361509,
    SPELL_EVOKER_SOAR_RACIAL               = 369536,
    SPELL_EVOKER_VISAGE                    = 372014,
    SPELL_EVOKER_VISAGE_AURA               = 372014,
    SPELL_EVOKER_CALL_OF_YSERA_AURA        = 373835,
    SPELL_EVOKER_JUST_IN_TIME              = 376204,
    SPELL_EVOKER_BRONZE_TIME_DILATION      = 357170,
    SPELL_EVOKER_PANACEA                   = 387761,
    SPELL_EVOKER_PANACEA_HEAL              = 387763,
    SPELL_EVOKER_GREEN_EMERALD_BLOSSOM     = 355913,
    SPELL_EVOKER_BLUE_DISINTEGRATE         = 356995,
    SPELL_EVOKER_BLUE_DISINTEGRATE_2       = 369093,
    SPELL_EVOKER_ECHO                      = 364343,
    SPELL_EVOKER_DREAM_PROJECTION          = 377509,
    SPELL_EVOKER_SKYWARD_ASCENT            = 367033,
    SPELL_EVOKER_FIREBREATH                = 357209,
    SPELL_EVOKER_SURGE_FORWARD             = 369541
};

// 362969 - Azure Strike (blue)
class spell_evo_azure_strike : public SpellScript
{
    PrepareSpellScript(spell_evo_azure_strike);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove(GetExplTargetUnit());
        Trinity::Containers::RandomResize(targets, GetEffectInfo(EFFECT_0).CalcValue(GetCaster()) - 1);
        targets.push_back(GetExplTargetUnit());
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_evo_azure_strike::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
    }
};

// 358733 - Glide (Racial)
class spell_evo_glide : public SpellScript
{
    PrepareSpellScript(spell_evo_glide);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_EVOKER_GLIDE_KNOCKBACK, SPELL_EVOKER_HOVER, SPELL_EVOKER_SOAR_RACIAL });
    }

    SpellCastResult CheckCast()
    {
        Unit* caster = GetCaster();

        if (!caster->IsFalling())
            return SPELL_FAILED_NOT_ON_GROUND;

        if (caster->HasAura(SPELL_EVOKER_VISAGE))
            return SPELL_FAILED_DONT_REPORT;

        return SPELL_CAST_OK;
    }

    void HandleCast()
    {
        Player* caster = GetCaster()->ToPlayer();
        if (!caster)
            return;

        caster->CastSpell(caster, SPELL_EVOKER_GLIDE_KNOCKBACK, true);

        caster->GetSpellHistory()->StartCooldown(sSpellMgr->AssertSpellInfo(SPELL_EVOKER_HOVER, GetCastDifficulty()), 0, nullptr, false, 250ms);
        caster->GetSpellHistory()->StartCooldown(sSpellMgr->AssertSpellInfo(SPELL_EVOKER_SOAR_RACIAL, GetCastDifficulty()), 0, nullptr, false, 250ms);
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_evo_glide::CheckCast);
        OnCast += SpellCastFn(spell_evo_glide::HandleCast);
    }
};

// 361469 - Living Flame (Red)
class spell_evo_living_flame : public SpellScript
{
    PrepareSpellScript(spell_evo_living_flame);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo ({ SPELL_EVOKER_LIVING_FLAME_DAMAGE, SPELL_EVOKER_LIVING_FLAME_HEAL, SPELL_EVOKER_ENERGIZING_FLAME });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* hitUnit = GetHitUnit();
        if (caster->IsFriendlyTo(hitUnit))
            caster->CastSpell(hitUnit, SPELL_EVOKER_LIVING_FLAME_HEAL, true);
        else
            caster->CastSpell(hitUnit, SPELL_EVOKER_LIVING_FLAME_DAMAGE, true);
    }

    void HandleLaunchTarget(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (caster->IsFriendlyTo(GetHitUnit()))
            return;

        if (AuraEffect* auraEffect = caster->GetAuraEffect(SPELL_EVOKER_ENERGIZING_FLAME, EFFECT_0))
        {
            int32 manaCost = GetSpell()->GetPowerTypeCostAmount(POWER_MANA).value_or(0);
            if (manaCost != 0)
                GetCaster()->ModifyPower(POWER_MANA, CalculatePct(manaCost, auraEffect->GetAmount()));
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_evo_living_flame::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnEffectLaunchTarget += SpellEffectFn(spell_evo_living_flame::HandleLaunchTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_evoker_panacea : public SpellScript
{
    PrepareSpellScript(spell_evoker_panacea);

    void HandleOnHit()
    {
        Player* player = GetCaster()->ToPlayer();
        if (player->HasSpell(SPELL_EVOKER_PANACEA))
            player->CastSpell(player, SPELL_EVOKER_PANACEA_HEAL, TRIGGERED_ALLOW_PROC);
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_evoker_panacea::HandleOnHit);
    }
};

class spell_evoker_just_in_time : public SpellScript
{
    PrepareSpellScript(spell_evoker_just_in_time);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_EVOKER_GREEN_EMERALD_BLOSSOM,
            SPELL_EVOKER_BLUE_DISINTEGRATE,
            SPELL_EVOKER_BLUE_DISINTEGRATE_2,
            SPELL_EVOKER_ECHO,
            SPELL_EVOKER_DREAM_PROJECTION
            });
    }

    void HandleOnCast()
    {
        Player* caster = GetCaster()->ToPlayer();
        if (Aura* aura = caster->GetAura(SPELL_EVOKER_JUST_IN_TIME))
            caster->GetSpellHistory()->ModifyCooldown(SPELL_EVOKER_BRONZE_TIME_DILATION, -Seconds(-GetEffectInfo(EFFECT_0).BasePoints));
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_evoker_just_in_time::HandleOnCast);
    }
};

class spell_evoker_soar : public SpellScript
{
    PrepareSpellScript(spell_evoker_soar);

    void HandleOnHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();

        if (caster == NULL)
            return;

        // Increase flight speed by 830540%
        caster->SetSpeedRate(MOVE_FLIGHT, 83054.0f);

        Player* player = GetHitPlayer();
        // Add "Skyward Ascent" and "Surge Forward" to the caster's spellbook
        player->LearnSpell(SPELL_EVOKER_SKYWARD_ASCENT, false);
        player->LearnSpell(SPELL_EVOKER_SURGE_FORWARD, false);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_evoker_soar::HandleOnHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_evoker_fire_breath : public AuraScript
{
    PrepareAuraScript(spell_evoker_fire_breath);

    void HandleAfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();

        if (caster == NULL || GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_CANCEL)
            return;

        caster->CastSpell(caster, SPELL_EVOKER_FIREBREATH, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_evoker_fire_breath::HandleAfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

//hack 351239
class spell_cosmic_evoker_visage : public SpellScript
{
    PrepareSpellScript(spell_cosmic_evoker_visage);

    void HandleCast()
    {
        Unit* caster = GetCaster();

        if (caster->HasAura(SPELL_EVOKER_VISAGE_AURA))
        {
            // Dracthyr Form
            caster->RemoveAurasDueToSpell(SPELL_EVOKER_VISAGE_AURA);
            caster->CastSpell(caster, 97709, true);
            caster->SendPlaySpellVisual(caster, 118328, 0, 0, 60, false);
            caster->SetDisplayId(108590);
        }
        else
        {
            // Visage Form
            if (caster->HasAura(97709))
                caster->RemoveAurasDueToSpell(97709);

            caster->CastSpell(caster, SPELL_EVOKER_VISAGE_AURA, true);
            caster->SendPlaySpellVisual(caster, 118328, 0, 0, 60, false);
            caster->SetDisplayId(104597);
        }
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_cosmic_evoker_visage::HandleCast);
    }
};

void AddSC_evoker_spell_scripts()
{
    RegisterSpellScript(spell_cosmic_evoker_visage);
    RegisterSpellScript(spell_evoker_fire_breath);
    RegisterSpellScript(spell_evoker_just_in_time);
    RegisterSpellScript(spell_evoker_panacea);
    RegisterSpellScript(spell_evo_azure_strike);
    RegisterSpellScript(spell_evo_glide);
    RegisterSpellScript(spell_evo_living_flame);
}
