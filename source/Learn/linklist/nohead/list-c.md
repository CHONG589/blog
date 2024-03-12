---
author: Chong
title: list.c
date: 2024-03-12 20:48:00
---

```
#include <stdio.h>
#include <stdlib.h>

#include "list.h"


stu_node *list_insert1 (stu_node *list, score *data) {

    stu_node *new;

    new = malloc (sizeof (*new));
    if (new == NULL) {
        return NULL;
    }

    new -> data = *data;
    // new -> next = NULL;

    new -> next = list;
    list = new;

    return list;

}

// 因为工程中最好还是用 int 作为返回值，这样在判断错误的时候才能具体知道是那种错误，
// 如：-1 表示内存分配失败，-2 表示参数不对......,而若用指针作为返回值，这样全部错
// 误都为 NULL 表示，具体哪种错误就很难知道。
int list_insert (stu_node **list, score *data) {

    stu_node *new;

    new = malloc (sizeof (*new));
    if (new == NULL) {
        return -1;          // 分配内存失败
    }

    new -> data = *data;

    new -> next = *list;
    *list = new;

    return 0;

}

void list_show (stu_node *list) {

    stu_node *cur;

    for (cur = list; cur != NULL; cur = cur -> next) {
        printf ("%d %s %d %d\n", cur -> data.id, cur -> data.name, cur -> data.math, cur -> data.chinese);
    }

}

int list_delete (stu_node **list) {

    stu_node *cur;

    if (*list == NULL) {
        return -1;
    }

    cur = *list;
    *list = (*list) -> next;

    free (cur);

    return 0;

}

int list_find (stu_node *list, int id) {

    stu_node *cur;

    for (cur = list; cur != NULL; cur = cur -> next) {
        if (cur -> data.id == id) {
            printf ("%d %s %d %d\n", cur ->data.id, cur ->data.name, cur -> data.math, cur -> data.chinese);
            return 0 ;
        }
    }

    return -1;

}

void list_destroy (stu_node *list) {

    stu_node *cur;
    
    if (list == NULL) {
        return ;
    }

    for (cur = list; cur != NULL; cur = list) {
        list = cur -> next;
        free (cur);
        cur = NULL;
    }

}
```