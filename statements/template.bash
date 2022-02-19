#!/usr/bin/env bash

bruh=statements/template

if [ $1 == "en" ]
then
    cp $bruh/en.tex statements/$2.tex
elif [ $1 == "th" ]
then
    cp $bruh/th.tex statements/$2.tex
else
    echo "Invalid Language!"
fi
