	#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
extern int free_frame;    //change

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int add;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  add = myproc()->sz;
  //myproc()->oldsz = myproc()->sz;
  myproc()->sz +=n;   //change
  if(n<0){
    deallocuvm(myproc()->pgdir, add, myproc()->sz);
}
  //if(growproc(n) < 0)   //change
    //return -1;    //change
  return add;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int 
sys_cps(void)                 //oldchange
{
  //cprintf("Hi! Welcome to the world of xv6!\n");
  return cps();
}


int
sys_chpr(void)          //oldchange
{
  int pid, pr;
  if(argint(0,&pid) <0)
     return -1;
  if(argint(1,&pr) < 0)
     return -1;

  return chpr(pid,pr);
}


int
sys_print_free_frame(void){         ///change
  cprintf("No. of free frames = %d\n", free_frame);
    return 0;
}
