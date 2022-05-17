#!/usr/bin/env bash

root=./problems/$1
rm -rf $root/input
rm -rf $root/output
mkdir -p $root/input
mkdir -p $root/output

for i in $(seq 1 $2)
do
    cp $root/testcase/$i.in $root/input/input$i.txt
    cp $root/testcase/$i.out $root/output/output$i.txt
done
