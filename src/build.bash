#!/usr/bin/env bash

root=src/problems/$1

g++ $root/gen.cpp -o $root/gen -std=c++17 -O3 -Isrc/vendor -lm

if [ $2 ]
then
    g++ $root/$2/grader.cpp -o $root/sol $root/sol.cpp -std=c++17 -O2 -lm -I$root/$2
else
    g++ $root/sol.cpp -o $root/sol -std=c++17 -O2 -Isrc/vendor -lm
fi
