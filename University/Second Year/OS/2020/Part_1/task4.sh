#!/bin/bash

read string
read file

cat $file | grep $string | wc -l
