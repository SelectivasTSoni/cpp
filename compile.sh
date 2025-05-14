#!/bin/bash

# Check if an argument was provided
if [ -z "$1" ]; then
    echo "Usage: ./compile.sh filename_without_extension"
    exit 1
fi

# Build the full input and output filenames
SOURCE="$1.cpp"
OUTPUT="$1"

# Compile using g++ with C++20
g++ "$SOURCE" -o "$OUTPUT" -std=c++20

# Check success
if [ $? -eq 0 ]; then
    echo "Compiled successfully. Run with ./$OUTPUT"
else
    echo "Compilation failed"
fi
