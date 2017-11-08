#ifndef _ARM_H_
#define _ARM_H_

#include "slavemaster.h"

void armSet(bool up, bool down, smd data);
smd armSetup(int speed);
void armSetTarget(int angle);

#endif /* end of include guard: _ARM_H_ */
