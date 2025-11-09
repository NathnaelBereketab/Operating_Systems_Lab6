#ifndef PROCESS_H
#define PROCESS_H

#define P_SIZE 7   // Number of processes expected from the input file

typedef struct _process {
    int pid;          // Unique process ID
    int arrival_time; // Lower value means earlier
    int priority;     // Lower value = higher priority
} Process;

void process_ctr(Process *p, int pid, int arrival_time, int priority);

#endif
