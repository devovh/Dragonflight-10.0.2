#include "ScriptMgr.h"
#include "hellfire_citadel.h"

enum Spells
{
};

enum Events
{
    // Intro
    EVENT_INTRO = 1,
};

enum Phases
{
    PHASE_NORMAL,
    PHASE_INTRO
};

struct boss_hellfire_gurtogg_bloodboil : public BossAI
{
    boss_hellfire_gurtogg_bloodboil(Creature* creature) : BossAI(creature, DATA_GURTOGG_BLOODBOIL) { Initialize(); }

    void Initialize()
    {
        PhaseStatus = Phases::PHASE_INTRO;
        hp20 = false;
    }

    void ScheduleTasks() override
    {
    }

    void ExecuteEvent(uint32 eventId) override
    {
        if (!hp20 && HealthBelowPct(20))
        {
            hp20 = true;
        }

        switch (eventId)
        {
        case EVENT_INTRO:
        {
            break;
        }
        default:
            break;
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (who->IsPlayer() && me->IsWithinDist(who, 25.0f, false))
        {
           // IsLock = true;
            me->RemoveUnitFlag(UnitFlags( UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));
            events.ScheduleEvent(EVENT_INTRO, 1s, PHASE_NORMAL);
        }
    }
    uint8 PhaseStatus;
    bool hp20;
};

void AddSC_boss_hellfire_gurtogg_bloodboil()
{
    RegisterCreatureAI(boss_hellfire_gurtogg_bloodboil);
}
