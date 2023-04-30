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

void AddSC_burning_steppes()
{
    RegisterCreatureAI(npc_zidormi);
}
