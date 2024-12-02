#!/bin/bash
read -p "Enter number: " num
let tenpercent=num/100*10
let newNum=num+tenpercent
echo "10% raised number of $num is $newNum."
