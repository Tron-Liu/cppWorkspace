#!/bin/bash
g++ $1.cpp -o $1 && ./$1 && rm $1.exe