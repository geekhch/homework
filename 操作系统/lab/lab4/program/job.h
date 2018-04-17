#ifndef JOB_H
#define JOB_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <signal.h>
#include <sys/types.h>

#define	FIFO "/home/student/SVRFIFO"

#ifndef DEBUG
 #define DEBUG
#endif

#undef DEBUG

#define BUFLEN 100
#define GLOBALFILE "screendump"

enum jobstate {
  READY, RUNNING, DONE
};

enum cmdtype {
  ENQ = -1, DEQ = -2, STAT = -3
};

/* this is data passed in fifo */
struct jobcmd {
  enum	cmdtype type;
  int	argnum;
  int	owner;
  int	defpri;
  char	data[BUFLEN];
};

#define DATALEN sizeof(struct jobcmd)
#define error_sys printf

struct jobinfo {
  int    jid;                 /* job id */
  int    pid;                 /* process id */
  char** cmdarg;              /* the command & args to execute */
  int    defpri;              /* default priority */
  int    curpri;              /* current priority */
  int    ownerid;             /* the job owner id */
  int    wait_time;           /* the time job in waitqueue */
  time_t create_time;         /* the time job create */
  int    run_time;            /* the time job running */
  enum   jobstate state;      /* job state */
};

struct waitqueue {            /* double link list */
  struct waitqueue *next;
  struct jobinfo *job;
};

void schedule();
void sig_handler(int sig, siginfo_t *info, void *notused);
int  allocjid();
void do_enq(struct jobinfo *newjob, struct jobcmd enqcmd);
void do_deq(struct jobcmd deqcmd);
void do_stat();
void updateall();
struct waitqueue* jobselect();
void jobswitch();

#endif
