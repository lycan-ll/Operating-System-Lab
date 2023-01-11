#!/bin/bash
touch p200613_s.c
cat p200613.txt > p200613_s.c
swit(){
	x=$1
	case $x in 
		1) 
			gcc p200613_s.c -o p200613_s
			;;
		2)
		       	gcc p200613_s.c -o p200613_s && ./p200613_s
                        ;;
		3)
		       	cat p20013_s.c 
			;;
		*) 
			echo "this is default level"
			ls
			;;
	esac
}
swit 3
exit 0

