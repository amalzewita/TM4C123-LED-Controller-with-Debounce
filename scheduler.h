#ifndef __Scheduler__
#define __Scheduler__


extern int counter;
extern int flag;

typedef struct{
  void (*pointer)(void);
  int period;
}task;


void task_sched(void);
void task_init(void (*p)(void),int period);

#endif
