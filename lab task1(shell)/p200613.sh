#!/bin/bash
touch p200613.c
cat p200613.txt > p200613.c

x=$1
if [ $x -eq 1 ] ; then
	gcc p200613.c -o p200613
fi
if [ $x -eq 2 ] ; then
	gcc p200613.c -o p200613 && ./p200613
fi
if [$x -eq 3 ] ; then 
	cat gcc p200613.c 
fi
exit 0
