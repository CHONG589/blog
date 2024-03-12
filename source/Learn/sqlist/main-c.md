---
author: Chong
title: main.c
date: 2024-03-12 20:04:00
---

```
#include <stdio.h>
#include <stdlib.h>

#include "sqlist.h"

int main () {

    sqlist *list = NULL, *list1 = NULL;

    datatype arr[] = {12, 23, 34, 45, 56};
    datatype arr1[] = {78, 89, 56, 23, 10};

    int i, k = -1;
    int err;

    list = sqlist_create ();
    if (list == NULL) {
        fprintf (stderr, "sqlist_create () failed!\n");
        exit (1);
    }
    
    list1 = sqlist_create ();
    if (list1 == NULL) {
        fprintf (stderr, "sqlist_create () failed!\n");
        exit (1);
    }


    for (i = 0; i < sizeof (arr) / sizeof (*arr); i++)          // 将数组后面的 \0 也赋值做去了?
        if ((err = sqlist_insert (list, 0, &arr[i])) != 0) {
            // 根据插入函数的编写可知，当 err 为 -1 时，为数组满了，当 err 为 -2 时，为 i 不合法。
            if (err == -1) {
                fprintf (stderr, "The arr is full.\n");
            }else if(err == -2) {
                fprintf (stderr, "The pos you want to insert is wrong!\n");
            }else {
                fprintf (stderr, "Error!\n");
            }
            exit (1);
        }
        
    sqlist_display (list);

    for (i = 0; i < sizeof (arr1) / sizeof (*arr1); i++)          // 将数组后面的 \0 也赋值做去了?
        if ((err = sqlist_insert (list1, 0, &arr1[i])) != 0) {
            // 根据插入函数的编写可知，当 err 为 -1 时，为数组满了，当 err 为 -2 时，为 i 不合法。
            if (err == -1) {
                fprintf (stderr, "The arr is full.\n");
            }else if(err == -2) {
                fprintf (stderr, "The pos you want to insert is wrong!\n");
            }else {
                fprintf (stderr, "Error!\n");
            }
            exit (1);
        }

    sqlist_display (list1);

    // sqlist_delete (list, 1);

    // sqlist_display (list);

    // k = sqlist_find (list, &arr[0]);
    // printf ("k = %d\n", k);

    sqlist_union (list, list1);

    sqlist_display (list);

    sqlist_destroy (list);
    sqlist_destroy (list1);

    exit (0);
}

```




