---
author: Chong
title: sqlist.c
date: 2024-03-12 20:16:00
---

```
#include <stdio.h>
#include <stdlib.h>

#include "sqlist.h"

sqlist *sqlist_create () {

    sqlist *me;

    me = malloc (sizeof (*me));
    // me 表示指针，*me 表示取值，即结构体的值，这里获取结构体的大小,将分配 *me 大小的空间的首地址赋给 me.     
    if (me == NULL)
        return NULL;
    me -> last = -1;

    return me;

}  

// 或采用二级指针返回一个指针       
void sqlist_create1 (sqlist **ptr) {
    *ptr = malloc (sizeof (**ptr));
    // 同样，sizeof 里面要对应结构体的大小，因为要创造一个结构体保存数组，二级指针获取结构体就是 **ptr, 
    // 这样才是取最终结构体的值
    if (*ptr == NULL)
        return ;
    
    (*ptr) -> last = -1;
    return ;
}

// datatype 这里不太适合传数据过来，即传值，因为你不知道datatype 为什么类型，
// 是 int 还是结构体,如果是结构体，显然你直接传值是不对的,因为你又不是把整个
// 结构体赋给它,而是把它里面的数据给它正确的应该为传变量的地址。
// i 的位置来做插入。
int sqlist_insert (sqlist *me, int i, datatype *data) {
    int j;

    if (me -> last == DATASIZE - 1)
        return -1;

    // 保证 i 值合法，因为存储的位置为连续存储，且 元素个数为 1 时，last 为 0，
    // 为了让 last 与 下标对应，所以最后一个值不是 last - 1, 而是就是 last;
    if(i < 0 || i > me ->last + 1)
        return -2;

    for (j = me -> last; j >= i; j--)
        me -> data[j + 1] = me -> data[j];

    me -> data[i] = *data;
    me -> last++;
    
    return 0;       // 程序一般 0 表示正常，非 0 表示异常终止
    
}   

int sqlist_delete (sqlist *me, int i) {

    int j;

    if (i < 0 || i > me -> last)
        return -1;
    
    for (j = i + 1; j <= me -> last; j++){
        me -> data[j - 1] = me -> data[j];
    }

    me -> last--;

    return 0;
}

int sqlist_find (sqlist *me, datatype *data) {
    int i;

    if (sqlist_isempty (me) == 0)
        return -1;  // 为空返回 -1;

    for (i = 0; i <= me -> last; i++) {
        if (me -> data[i] == *data){
            return i;
        }
    }
    return -2;  // 不为空，但找不到，返回 -2;
}

int sqlist_isempty (sqlist *me) {

    if (me -> last == -1)
        return 0;
    else
        return -1;
}

int sqlist_setempty (sqlist *me) {

    me -> last = -1;
    return 0;
}

int sqlist_getnum (sqlist *me) {

    // 当数组元素为空时，me -> last == -1;且 last 是从 0 开始的，所以当返回数组个数时只需 last + 1 即可 
    return (me -> last + 1);
}

void sqlist_display (sqlist *me) {
    
    int i;
    if (me -> last == -1)
        return ;

    for (i = 0; i <= me -> last; i++)
        printf ("%d ", me -> data[i]);
    printf ("\n");

    return ;
}

int sqlist_destroy (sqlist *me) {

    free (me);
    return 0;
}

int sqlist_union (sqlist *list1, sqlist *list2) {
    // list1 -> 12, 23, 34, 45, 56;
    // list2 -> 78, 89, 56, 23, 10;

    int i = 0;

    for (i = 0; i <= list2 -> last; i++) {
        if (sqlist_find (list1, &(list2 -> data[i])) < 0) {
            sqlist_insert (list1, 0, &(list2 -> data[i]));
        }
    }

    return 0;

}
```