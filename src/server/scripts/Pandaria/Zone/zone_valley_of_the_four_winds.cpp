/*
 * Copyright (C) 2016-2017 DeathCore <http://www.noffearrdeathproject.org/>
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
#include "ScriptedEscortAI.h"

enum eBonobosSpells
{
    SPELL_GOING_BANANAS     = 125363,
	SPELL_BANANARANG		= 125311,
    SPELL_TOSS_FILTH		= 125365,
};

enum eBonobosEvents
{
    EVENT_GOING_BANANAS         = 1,
	EVENT_BANANARANG			= 2,
    EVENT_TOSS_FILTH		    = 3,
};

class mob_bonobos : public CreatureScript
{
    public:
        mob_bonobos() : CreatureScript("mob_bonobos") 
		{ 
		}

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_bonobosAI(creature);
        }

        struct mob_bonobosAI : public ScriptedAI
        {
            mob_bonobosAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset() override
            {
                events.Reset();
                
                events.ScheduleEvent(EVENT_GOING_BANANAS,		12000);
                events.ScheduleEvent(EVENT_BANANARANG,			 8000);
                events.ScheduleEvent(EVENT_TOSS_FILTH,			15000);
            }

            void JustDied(Unit* /*killer*/) override
            {
            }

            void JustSummoned(Creature* summon) override
            {
                summon->DespawnOrUnsummon(12000);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;
				
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);
                

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_GOING_BANANAS:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_GOING_BANANAS, false);
                            events.ScheduleEvent(EVENT_GOING_BANANAS,      10000);
                            break;
                        case EVENT_BANANARANG:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_BANANARANG, false);
                            events.ScheduleEvent(EVENT_BANANARANG, 20000);
                            break;
                        case EVENT_TOSS_FILTH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_TOSS_FILTH, false);
                            events.ScheduleEvent(EVENT_TOSS_FILTH, 15000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eSeleNaSpells
{
    SPELL_RAIN_DANCE    = 124860,
	SPELL_TORRENT		= 124935,
    SPELL_WATER_BOLT    = 124854,
};

enum eSeleNaEvents
{
    EVENT_RAIN_DANCE        = 1,
	EVENT_TORRENT			= 2,
    EVENT_WATER_BOLT        = 3,
};

class mob_sele_na : public CreatureScript
{
    public:
        mob_sele_na() : CreatureScript("mob_sele_na") 
		{ 
		}

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_sele_naAI(creature);
        }

        struct mob_sele_naAI : public ScriptedAI
        {
            mob_sele_naAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset() override
            {
                events.Reset();
                
                events.ScheduleEvent(EVENT_RAIN_DANCE,		 5000);
                events.ScheduleEvent(EVENT_TORRENT,			15000);
                events.ScheduleEvent(EVENT_WATER_BOLT,		25000);
            }

            void JustDied(Unit* /*killer*/) override
            {
            }

            void JustSummoned(Creature* summon) override
            {
                summon->DespawnOrUnsummon(12000);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;
				
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);
                

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_RAIN_DANCE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_RAIN_DANCE, false);
                            events.ScheduleEvent(EVENT_RAIN_DANCE,       5000);
                            break;
                        case EVENT_TORRENT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_TORRENT, false);
                            events.ScheduleEvent(EVENT_TORRENT, 15000);
                            break;
                        case EVENT_WATER_BOLT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_WATER_BOLT, false);
                            events.ScheduleEvent(EVENT_WATER_BOLT, 25000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eBlackhoofSpells
{
    SPELL_BELLOWING_RAGE    = 124297,
	SPELL_RUSHING_RAGE		= 124302,
    SPELL_YAUNGOL_STOMP     = 124289,
};

enum eBlackhoofEvents
{
    EVENT_BELLOWING_RAGE        = 1,
	EVENT_RUSHING_RAGE			= 2,
    EVENT_YAUNGOL_STOMP         = 3,
};

class mob_blackhoof : public CreatureScript
{
    public:
        mob_blackhoof() : CreatureScript("mob_blackhoof") 
		{ 
		}

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_blackhoofAI(creature);
        }

        struct mob_blackhoofAI : public ScriptedAI
        {
            mob_blackhoofAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset() override
            {
                events.Reset();
                
                events.ScheduleEvent(EVENT_RUSHING_RAGE,		 5000);
                events.ScheduleEvent(EVENT_YAUNGOL_STOMP,		15000);
                events.ScheduleEvent(EVENT_BELLOWING_RAGE,	    25000);
            }

            void JustDied(Unit* /*killer*/) override
            {
            }

            void JustSummoned(Creature* summon) override
            {
                summon->DespawnOrUnsummon(12000);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;
				
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);
                

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BELLOWING_RAGE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_BELLOWING_RAGE, false);
                            events.ScheduleEvent(EVENT_BELLOWING_RAGE,       25000);
                            break;
                        case EVENT_RUSHING_RAGE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_RUSHING_RAGE, false);
                            events.ScheduleEvent(EVENT_RUSHING_RAGE, 5000);
                            break;
                        case EVENT_YAUNGOL_STOMP:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_YAUNGOL_STOMP, false);
                            events.ScheduleEvent(EVENT_YAUNGOL_STOMP, 15000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eIkThikWarriorSpells
{
    SPELL_PIERCE_ARMOR      = 6016,
    SPELL_SHOCK_AND_AWE		= 118538,
};

enum eIkThikWarriorEvents
{
    EVENT_PIERCE_ARMOR          = 1,
    EVENT_SHOCK_AND_AWE			= 2,
};

class mob_ik_thik_warrior : public CreatureScript
{
    public:
        mob_ik_thik_warrior() : CreatureScript("mob_ik_thik_warrior")
        {
        }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_ik_thik_warriorAI(creature);
        }

        struct mob_ik_thik_warriorAI : public ScriptedAI
        {
            mob_ik_thik_warriorAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_PIERCE_ARMOR,		 5000);
                events.ScheduleEvent(EVENT_SHOCK_AND_AWE,		15000);
            }

            void JustDied(Unit* /*killer*/) override
            {
            }

            void JustSummoned(Creature* summon) override
            {
                summon->DespawnOrUnsummon(12000);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_PIERCE_ARMOR:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_PIERCE_ARMOR, false);
                            events.ScheduleEvent(EVENT_PIERCE_ARMOR,       25000);
                            break;
                        case EVENT_SHOCK_AND_AWE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_SHOCK_AND_AWE, false);
                            events.ScheduleEvent(EVENT_SHOCK_AND_AWE, 40000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

void AddSC_valley_of_the_four_winds()
{
    // Rare Mobs
    new mob_bonobos();
    new mob_sele_na();
    new mob_blackhoof();

    // Standard Mobs
    new mob_ik_thik_warrior();
}