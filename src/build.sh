g++ src/problems/$1/gen.cpp -o src/problems/$1/gen -std=c++17 -O3 -I./src/vendor
g++ src/problems/$1/sol.cpp -o src/problems/$1/sol -std=c++17 -O2 -I./src/vendor
