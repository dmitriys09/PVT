/*
 * loop.c:
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "hpctimer.h"

enum { n = 64 * 1024 * 1024 };

int main()
{
    int *v, i, sum;
    double t;
    int t1, t2, t3, t4, t5, t6, t7, t8,
    t9, t10, t11, t12, t13, t14, t15, t16;
    if ( (v = malloc(sizeof(*v) * n)) == NULL) {
        fprintf(stderr, "No enough memory\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n; i++)
        v[i] = 1;
   
    t = hpctimer_wtime();
    /* TODO: Unroll this loop */
    t1 = t2 = t3 = t4 = t5 = t6 = t7 = t8 = 
    t9 = t10 = t11 = t12 = t13 = t14 = t15 = t16 = 0;
    for (sum = 0, i = 15; i < n; i += 16) {
        //sum += v[i];
        t1 += v[i - 15];
        t2 += v[i - 14];
        t3 += v[i - 13];
        t4 += v[i - 12];
        t5 += v[i - 11];
        t6 += v[i - 10];
        t7 += v[i - 9];
        t8 += v[i - 8];
        t9 += v[i - 7];
        t10 += v[i - 6];
        t11 += v[i - 5];
        t12 += v[i - 4];
        t13 += v[i - 3];
        t14 += v[i - 2];
        t15 += v[i - 1];
        t16 += v[i];
    }
    sum = t1 + t2 + t3 + t4 + t5 + t6 + t7 + t8 + t9 + t10 +
    t11 + t12 + t13 + t14 + t15 + t16;
    t = hpctimer_wtime() - t;

    printf("Sum = %d\n", sum);
    printf("Elapsed time (sec.): %.6f\n", t);

    free(v);
    return 0;
}
