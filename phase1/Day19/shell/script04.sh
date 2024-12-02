#!/bin/bash
read -p "Enter number: " num
tenpercent=$(( (num / 100) * 10 ))
newNum=$(( num + tenpercent ))
echo "10% raised number of $num is $newNum."
