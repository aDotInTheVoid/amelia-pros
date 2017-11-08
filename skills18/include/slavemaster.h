#ifndef _SLAVE_MASTER_H_
#define _SLAVE_MASTER_H_

#include "main.h"

typedef struct SlaveMasterParams {
    int master;
    int slave;
    int initial_speed;
    int slave_encoder;
    int master_encoder;
    double cog_diff;
    int *current_state;
    Mutex mutex;
} smp;

typedef struct SlaveMasterData {
    int *state;
    Mutex mutex;
    int speed;
} smd;

smd setup_slave_master(int mst, int slv, int ispeed,
    int s_enc, int m_enc, double diff);

void slave_master(void * params);

#endif /* end of include guard: _SLAVE_MASTER_H_ */
