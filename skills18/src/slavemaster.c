#include "main.h"
#include "config.h"
#include "slavemaster.h"

void slave_master (void *params) {
    smp * smps = (smp*) params;
    double error = 0.0;
    int slspeed = smps->initial_speed * smps->cog_diff;
    const double kp = 0.2;
    int master_ime;
    int slave_ime;
    imeReset(smps->master_encoder);
    imeReset(smps->slave_encoder);
    while (1) {
        int cst = *(smps->current_state);
        motorSet(smps->master, cst * smps->initial_speed);
        motorSet(smps->slave, cst * slspeed);
        imeGet(smps->master_encoder, &master_ime);
        imeGet(smps->slave_encoder, &slave_ime);
        error = master_ime - (slave_ime * smps->cog_diff);
        slspeed += error * kp;
        imeReset(smps->master_encoder);
        imeReset(smps->slave_encoder);
        delay(50);
    }
}

int* setup_slave_master(int mst, int slv, int ispeed,
    int s_enc, int m_enc, double diff)
{
    int * cst = (int*) malloc(sizeof(int));
    cst = 0;
    smp params = (smp) {
        mst, slv, ispeed, s_enc, m_enc, diff, cst
    };
    taskCreate(slave_master, TASK_DEFAULT_STACK_SIZE, &params, TASK_PRIORITY_DEFAULT);
    return cst;
}
