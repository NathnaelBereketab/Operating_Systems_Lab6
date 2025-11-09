#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "process.h"

Process *parse_file(FILE *f) {
    size_t idx = 0;
    char *headers = NULL;
    size_t len = 0;

    // skip header line
    getline(&headers, &len, f);
    free(headers);

    Process *list = malloc(P_SIZE * sizeof(Process));
    while (!feof(f) && idx < P_SIZE) {
        int id, arrival, prio;
        fscanf(f, "%d,%d,%d\n", &id, &arrival, &prio);
        process_ctr(&list[idx++], id, arrival, prio);
    }
    return list;
}
