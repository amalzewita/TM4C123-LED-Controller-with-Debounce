#include "scheduler.h"


//typedef void (*func)(void);
task t_identifier;
task array[20];
int task_i=0;
int i=0;


void task_init(void (*p)(void),int period)
{
  t_identifier.pointer=p;
  t_identifier.period=period;
  array[task_i]=t_identifier;
  task_i++;
}



void task_sched(void)
{
  while(1)
  {
    i=counter;
    __asm(" CPSID I");
    if(i==0)
    {
    }
    else{
          if(flag==0)
      {
    for(int x=0;x<task_i;x++)
    {

      if(i%(array[x].period)==0)
      {
        (*array[x].pointer)();
      }
     }
      flag=1;
    }
    }

    
    __asm(" CPSIE I");
    
  }
  
}
