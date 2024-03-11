---
author: Chong
title: 重定义 typedef
date: 2024-02-06 14:36:57
tags:
categories:
thumbnail: ./xcode-clean.png
---

##### typedef 与 define 的区别

```
#define IP int *

IP p, q;    --> int *, q;
```
```
typedef int *IP;

IP p, q;    --> int *p, *q;
```
define 只是简单的替换，typedef 是由编译器执行解释的，#define 语句是由预编译器进行处理的。

##### typedef 的本质

```
typedef int ARR[6];         --> int [6] -> ARR;  // int [6] 为数组的本质

ARR a; --> int a[6];

// ------------------------------------------------------

typedef int FUNC (int);     --> int (int)   FUNC;
FUNC f; --> int f(int); 

typedef int *FUNCP (int);
FUNC p; --> int *p (int);
```
