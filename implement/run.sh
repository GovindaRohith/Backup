#! /bin/bash
g++ $1.cpp
./a.out
rm ./a.out
#valgrind --tool=memcheck ./a.out
