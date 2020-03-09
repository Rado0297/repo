#!/bin/bash

read file1
read file2
read file3

cat $file1 $file2 | sort > $file3

wc -c $file1 | cut -f 1 -d " "
wc -c $file2 | cut -f 1 -d " "
wc -c $file3 | cut -f 1 -d " "
