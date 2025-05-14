#!/bin/bash

# Check for at least one argument
if [ "$#" -lt 2 ]; then
    echo "Usage: ./compile.sh output_filename input1.cpp input2.cpp [...]"
    exit 1
fi

# First argument is the output filename
OUTPUT="$1"
shift  # Shift arguments so $@ now contains only input files

# Build and run the compilation
g++ "$@" -o "$OUTPUT" -std=c++20

# Check success
if [ $? -eq 0 ]; then
    echo "Compiled successfully to ./$OUTPUT"
else
    echo "Compilation failed"
fi
