#!/bin/csh

g++ -g -Wall temperatures.c

set i = 1

while ($i < 11)
	./a.out < ./testcases/input_25-3-$i.txt > l 
	diff -qsbBw l ./testcases/output_25-3-$i.txt
    @ i++
end
rm -rf l a.out
