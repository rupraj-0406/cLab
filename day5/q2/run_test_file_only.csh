#!/bin/csh

# Compile the C program
gcc 2.c -o 2.out

# Check for compilation errors
if ($status != 0) then
    echo "Compilation failed."
    exit 1
endif

# Clear previous output file
rm -f tst/output.txt

# Change to the tst directory to find test cases
foreach file (`ls tst/test*.txt`)
    echo "Running test case $file..." >> tst/output.txt
    
    # Run the C program with input from the test file and append output to output.txt
    ./2.out < $file >> tst/output.txt
    echo "" >> tst/output.txt
end

echo "All test cases completed. Output saved to tst/output.txt"