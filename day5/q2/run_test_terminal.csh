#!/bin/csh

# Compile the C program
gcc 2.c -o 2.out

# Check for compilation errors
if ($status != 0) then
    echo "Compilation failed."
    exit 1
endif

# Change to the tst directory to find test cases
foreach file (`ls tst/test*.txt`)
    echo "-----------------------------------"
    echo "Test Case: $file"
    echo "Input Data:"
    cat $file
    echo "Output:"

    # Run the C program with input from the test file
    ./2.out < $file
    echo "-----------------------------------"
    echo ""
end

echo "All test cases displayed."