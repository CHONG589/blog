---
author: Chong
title: sqlist.h
date: 2024-03-12 20:19:00
---

```
#ifndef SQLIST_H__              // 条件编译的功能，防止头文件被重复包含
#define SQLIST_H__              // SQLIST_H__ 为宏名，下面的全为宏体

#define DATASIZE    1024
typedef   int   datatype;

typedef struct node_st {

    datatype data [DATASIZE];
    int last;
} sqlist;

// 或采用二级指针返回一个指针       
sqlist *sqlist_create (); 

void sqlist_create1 (sqlist **);

// datatype 这里不太适合传数据过来，即传值，因为你不知道datatype 为什么类型，
// 是 int 还是结构体,如果是结构体，显然你直接传值是不对的,因为你又不是把整个
// 结构体赋给它,而是把它里面的数据给它正确的应该为传变量的地址
int sqlist_insert (sqlist *, int i, datatype *);   

int sqlist_delete (sqlist *, int i);

int sqlist_find (sqlist *, datatype *);

int sqlist_isempty (sqlist *);

int sqlist_setempty (sqlist *);

int sqlist_getnum (sqlist *);

void sqlist_display (sqlist *);

int sqlist_destroy (sqlist *);

int sqlist_union (sqlist *, sqlist *);

#endif
```




