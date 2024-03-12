---
author: Chong
title: makefile
date: 2024-03-12 20:22:00
---

```
main: main.o sqlist.o
	$(CC)  $^ -o $@

main.o: main.c 
	$(CC) $^ -c -Wall -g -o $@

sqlist.o: sqlist.c
	$(CC) $^ -c -Wall -g -o $@

clean:
	rm *.o main -rf
```

