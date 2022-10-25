#include <stdio.h>
#include "hashmap.h"

int main(void)
{
    HashMap *hm = new_hashmap();

    for (int i = 0, j = 10000; i < 10000; i++, j--)
    {
        if (hashmap_insert(hm, i, j))
        {
            fprintf(stderr, "Error on inserting %d:%d\n", i, j);
        }
    }

    for (int i = 2500; i < 7500; i++)
    {
        if (hashmap_remove(hm, i))
        {
            fprintf(stderr, "Error, key %d not in hashmap\n", i);
        }
    }

    int res = 0;
    for (int i = 0; i < 10000; i++)
    {
        int err = hashmap_get(hm, i, &res);
        printf("%d:%d\n", i, err ? -1 : res);
        res = 0;
    }

    destroy_hashmap(hm);
    return 0;
}

