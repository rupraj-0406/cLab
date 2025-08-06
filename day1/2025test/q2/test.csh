#!/bin/csh

g++ -g -Wall digital-root.c

set i = 1

while ($i < 11)
	./a.out < ./testcases/input_25-2-$i.txt > l 
	diff -qsbBw l ./testcases/output_25-2-$i.txt
    @ i++
end
rm -rf l a.out
