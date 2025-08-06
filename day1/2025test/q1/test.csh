#!/bin/csh

g++ -g -Wall q1.cpp

set i = 1

while ($i < 11)
	./a.out < ./testcases/input_25-1-$i.txt > l 
	diff -qsbBw l ./testcases/output_25-1-$i.txt
    @ i++
end
rm -rf l a.out
