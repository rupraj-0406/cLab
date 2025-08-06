#!/bin/csh

# Step 1: Compile C program
echo "Compiling main.c..."
gcc 1.c -o program

# Check if compilation succeeded
if ($status != 0) then
    echo "Compilation failed!"
    exit 1
endif

# Step 2: Run the compiled program for each test input
foreach i (`seq 1 10`)
    echo "=== Test $i ==="
    echo "Input (test$i.txt): "
    cat test$i.txt

    echo "\nOutput: "
    ./program < test$i.txt

    echo "==============="
end
