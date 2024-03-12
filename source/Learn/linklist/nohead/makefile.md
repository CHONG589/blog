---
author: Chong
title: makefile
date: 2024-03-12 20:52:00
---

```
main: main.o list.o
	$(CC)  $^ -o $@

main.o: main.c 
	$(CC) $^ -c -g -o $@

list.o: list.c
	$(CC) $^ -c -g -o $@

clean:
	rm *.o main -rf
```

