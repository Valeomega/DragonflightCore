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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellScript.h"
#include "Player.h"
#include "Group.h"
#include "GameEventMgr.h"
#include "SharedDefines.h"


enum DeathlyUsher
{
    SPELL_TELEPORT_SINGLE = 12885,
    SPELL_TELEPORT_SINGLE_IN_GROUP = 13142,
    SPELL_TELEPORT_GROUP = 27686
};

enum Npc
{
    NPC_GOSSIP_MENU = 9733
};

enum eSpells
{
    SPELL_TIME_TRAVELLING = 176111
};

// PNJ Permettant un passage entre nouveau/anciennes terres foudroyes
class npc_zidormi : public CreatureScript
{
public:
    npc_zidormi() : CreatureScript("npc_zidormi") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (player->GetLevel() < 10)
            return true;

        if (player->GetMapId() == 1190)
        {
            AddGossipItemFor(player, NPC_GOSSIP_MENU, 1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 0);
        }
        else if (player->GetMapId() == 0)
        {
            AddGossipItemFor(player, NPC_GOSSIP_MENU, 2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        }

        SendGossipMenuFor(player, player->GetGossipTextId(creature), creature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_INFO_DEF + 0)
        {
            player->CastSpell(player, SPELL_TIME_TRAVELLING, true);
            player->SeamlessTeleportToMap(MAP_EASTERN_KINGDOMS);
        }
        else if (action == GOSSIP_ACTION_INFO_DEF + 1)
        {
            player->RemoveAurasDueToSpell(SPELL_TIME_TRAVELLING);
            player->SeamlessTeleportToMap(MAP_WOD_BLASTED_LANDS_PHASE);
        }

        CloseGossipMenuFor(player);
        return true;
    }
};

// Archmage Khadgar - 76643
class npc_archmage_khadgar_gossip : public CreatureScript
{
public:
    npc_archmage_khadgar_gossip() : CreatureScript("npc_archmage_khadgar_gossip") { }

    enum TanaanQuests
    {
        QuestStartDraenor = 34398,
        //QuestStartDraenor                   = 36881,
        QuestDarkPortal = 34398,
        QuestAzerothsLastStand = 35933,
        QuestOnslaughtEnd = 34392,
        QuestThePortalPower = 34393,
        QuestBledDryAlly = 35240,
        QuestBledDryHorde = 34421,
        QuestCostOfWar = 34420,
        QuestBlazeOfGlory = 34422,
        QuestAltarAltercation = 34423,
        QuestAPotentialAlly = 34478,
        QuestAPotentialAllyHorde = 34427,
        QuestKargatharProvingGrounds = 34425,
        QuestKillYourHundred = 34429,
        QuestMastersOfShadowAlly = 34431,
        QuestMastersOfShadowHorde = 34737,
        QuestKeliDanTheBreakerHorde = 34741,
        QuestKeliDanTheBreakerAlly = 34436,
        QuestTheGunpowderPlot = 34987,
        QuestATasteOfIron = 34445,
        QuestTheHomeStretchHorde = 34446,
        QuestTheHomeStretchAlly = 35884,
        QuestYrelHorde = 34740,
        QuestYrelTanaan = 34434,
        QuestABattleToPrepareAlly = 35019,
        QuestABattleToPrepareHorde = 35005,
        QuestTheBattleOfTheForge = 34439,
        QuestTakingATripToTheTopOfTheTank = 35747,
        QuestGaNarOfTheFrostwolf = 34442,
        QuestTheProdigalFrostwolf = 34437,
    };

    bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
    {
        if (player->GetQuestStatus(QuestStartDraenor) == QUEST_STATUS_NONE)
            return true;

        if (player->GetQuestStatus(TanaanQuests::QuestTheHomeStretchHorde) == QUEST_STATUS_REWARDED)
        {
            player->TeleportTo(MAP_DRAENOR, 5538.213379f, 5015.2690f, 13.0f, player->GetOrientation());
            return true;
        }
        else if (player->GetQuestStatus(TanaanQuests::QuestTheHomeStretchAlly) == QUEST_STATUS_REWARDED)
        {
            player->TeleportTo(MAP_DRAENOR, 2308.9621f, 454.9409f, 6.0f, player->GetOrientation());
            return true;
        }

        if (player->GetQuestStatus(QuestStartDraenor) == QUEST_STATUS_INCOMPLETE)
        {
            player->AddMovieDelayedAction(199, [player]
                {
                    player->TeleportTo(1265, 4066.7370f, -2381.9917f, 94.858f, 2.90f);
                });
            player->SendMovieStart(199);
            player->KilledMonsterCredit(78419);
            return true;
        }

        Position teleportPos;

        if ((player->GetQuestStatus(QuestStartDraenor) == QUEST_STATUS_COMPLETE ||
            player->GetQuestStatus(QuestStartDraenor) == QUEST_STATUS_REWARDED) &&
            player->GetQuestStatus(TanaanQuests::QuestThePortalPower) != QUEST_STATUS_REWARDED)
        {
            teleportPos = { 4066.7370f, -2381.9917f, 94.858f, 2.90f };
        }
        else if (player->GetQuestStatus(TanaanQuests::QuestThePortalPower) == QUEST_STATUS_REWARDED &&
            player->GetQuestStatus(TanaanQuests::QuestBlazeOfGlory) != QUEST_STATUS_REWARDED)
        {
            teleportPos = { 3949.97f, -2515.91f, 69.756538f, 2.454291f };
        }
        else if (player->GetQuestStatus(TanaanQuests::QuestBlazeOfGlory) == QUEST_STATUS_REWARDED &&
            player->GetQuestStatus(TanaanQuests::QuestAltarAltercation) != QUEST_STATUS_REWARDED)
        {
            teleportPos = { 3841.56f, -2775.08f, 93.84f, 5.34f };
        }
        else if (player->GetQuestStatus(TanaanQuests::QuestAltarAltercation) == QUEST_STATUS_REWARDED &&
            player->GetQuestStatus(TanaanQuests::QuestKargatharProvingGrounds) != QUEST_STATUS_REWARDED)
        {
            teleportPos = { 4227.83f, -2810.83f, 17.19f, 6.15f };
        }
        else if (player->GetQuestStatus(TanaanQuests::QuestKargatharProvingGrounds) == QUEST_STATUS_REWARDED &&
            player->GetQuestStatus(TanaanQuests::QuestKeliDanTheBreakerHorde) != QUEST_STATUS_REWARDED &&
            player->GetQuestStatus(TanaanQuests::QuestKeliDanTheBreakerAlly) != QUEST_STATUS_REWARDED)
        {
            teleportPos = { 4509.39f, -2632.79f, 1.84f, 0.0f };
        }
        else if (player->GetQuestStatus(TanaanQuests::QuestKeliDanTheBreakerHorde) == QUEST_STATUS_REWARDED &&
            player->GetQuestStatus(TanaanQuests::QuestKeliDanTheBreakerAlly) == QUEST_STATUS_REWARDED &&
            player->GetQuestStatus(TanaanQuests::QuestTheBattleOfTheForge) != QUEST_STATUS_REWARDED)
        {
            teleportPos = { 4616.05f, -2245.06f, 14.75f, 1.89f };
        }
        else if (player->GetQuestStatus(TanaanQuests::QuestTheBattleOfTheForge) == QUEST_STATUS_REWARDED &&
            player->GetQuestStatus(TanaanQuests::QuestTheHomeStretchHorde) != QUEST_STATUS_REWARDED &&
            player->GetQuestStatus(TanaanQuests::QuestTheHomeStretchAlly) != QUEST_STATUS_REWARDED)
        {
            teleportPos = { 4055.08f, -2018.38f, 73.20f, 3.14f };
        }

        player->TeleportTo(MAP_TANAAN_JUNGLE_INTRO, teleportPos);

        return true;
    }
};

void AddSC_burning_steppes()
{
    RegisterCreatureAI(npc_zidormi);
    new npc_archmage_khadgar_gossip();
}
