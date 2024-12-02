#!/bin/bash
read -p "Enter number: " num
tenpercent=$(expr $num / 100 \* 10)
newNum=$(expr $num + $tenpercent)
echo "10% raised number of $num is $newNum."
