#include <stdio.h>
#include "hashmap.h"
#include <sys/time.h>

int main(void)
{
    HashMap *hm = new_hashmap();

    struct timeval start,end;
    gettimeofday(&start, NULL);
    for (int i = 0, j = 10000; i < 10000; i++, j--)
    {
        if (hashmap_insert(hm, i, j))
        {
            // fprintf(stderr, "Error on inserting %d:%d\n", i, j);
        }
    }
    gettimeofday(&end, NULL);
    long timeuse = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("time=%f\n",timeuse / 1000000.0);

    for (int i = 2500; i < 7500; i++)
    {
        if (hashmap_remove(hm, i))
        {
            // fprintf(stderr, "Error, key %d not in hashmap\n", i);
        }
    }

    int res = 0;
    for (int i = 0; i < 10000; i++)
    {
        int err = hashmap_get(hm, i, &res);
        // printf("%d:%d\n", i, err ? -1 : res);
        res = 0;
    }

    destroy_hashmap(hm);
    return 0;
}

