---
author: Chong
title: list.h
date: 2024-03-12 20:49:00
---

```
#ifndef LIST_H__
#define LIST_H__

#define NAMESIZE    32

typedef struct score_st {

    int id;
    char name[NAMESIZE];
    int math;
    int chinese;

} score;

typedef struct node_st {

    score data;
    struct node_st *next;

} stu_node;

stu_node *list_insert1 (stu_node *, score *data);

int list_insert (stu_node **list, score *data);

void list_show (stu_node *);

int list_delete (stu_node **list);

int list_find (stu_node *, int id);

void list_destroy (stu_node *);


#endif
```




