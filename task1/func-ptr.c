#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "process.h"
#include "util.h"

#define DEBUG 0

typedef int (*Comparer)(const void *, const void *);

/* Custom comparer for qsort:
   - Sort by priority ascending  (lower = higher priority)
   - If equal, sort by arrival_time ascending
   - If still equal, sort by pid ascending
*/
int my_comparer(const void *lhs, const void *rhs) {
    const Process *a = (const Process *)lhs;
    const Process *b = (const Process *)rhs;

    if (a->priority != b->priority)
        return a->priority - b->priority;
    if (a->arrival_time != b->arrival_time)
        return a->arrival_time - b->arrival_time;
    return a->pid - b->pid;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: ./qsort <input-file>\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("File open failed");
        return 1;
    }

    Process *arr = parse_file(fp);
    qsort(arr, P_SIZE, sizeof(Process), my_comparer);

#if DEBUG
    printf("After sort:\n");
#endif
    for (int i = 0; i < P_SIZE; i++)
        printf("%d (%d, %d)\n", arr[i].pid, arr[i].priority, arr[i].arrival_time);

    free(arr);
    fclose(fp);
    return 0;
}
