---
author: Chong
title: main.c
date: 2024-03-12 20:46:00
---

```
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main () {

    stu_node *list = NULL;
    score tmp;                      // 采用变量的形式定义，不然用指针还要为它分配内存
    int i, ret;

    for (i = 0; i < 7; i++) {

        tmp.id = i;
        snprintf (tmp.name, NAMESIZE, "str%d", i);
        tmp.math = rand () % 100;
        tmp.chinese = rand () % 100;

        // list = list_insert1(list, &tmp);
        ret = list_insert (&list, &tmp);
        if (ret != 0) {
            exit (1);
        }
        
    }

    list_show (list);

    // list_delete (&list);
    printf ("\n");

    // list_show (list);

    int id = 6;
    list_find (list, id);

    list_destroy (list);

    list_show (list);

    exit (0);
}

```




