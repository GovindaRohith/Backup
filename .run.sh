#! /bin/bash
if [[ $1 == *.c ]]
then
    gcc $1
    valgrind ./a.out
    rm a.out
elif [[ $1 == *.cpp ]]
then
    g++ $1
    valgrind ./a.out
    rm a.out
elif [[ $1 == *.java ]]
then
    javac $1
    IFS='.'
    read -ra arr <<< $1
    java ${arr}
    rm *.class
else
    echo "Unknown language/wrongly entered/i haven't learned it yet"
fi