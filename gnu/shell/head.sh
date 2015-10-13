#!/bin/bash
if [ $# -ne 1 -a $# -ne 3 ]
then
    echo Command error"(" arguments error")"
    exit 0
fi

if [ $# -eq 1 ]
then
    if [ ! -f $1 ]
    then
        echo this file does not exist
        exit 0
    fi
    head -n -2 $1
fi

if [ $# -eq 3 ]
then
    if [ ! -f $3 ]
    then
        echo this file does not exist
        exit 0
    fi
    if [ $1 != "-n" ]
    then
        echo Command error
        exit 0
    fi
    if [[ "$2" =~ ^[0-9]+$  ]]
    then
        head -n $2 $3
    else
        echo line number is invalid
        exit 0
    fi
else
    echo Command error
    exit 0
fi
