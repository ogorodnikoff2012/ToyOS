#ifndef TIMER_H
#define TIMER_H

#include "common.h"

#define DEFAULT_FREQUENCY 50

void init_timer(u32int freq);
u32int uptime();

#endif // TIMER_H
