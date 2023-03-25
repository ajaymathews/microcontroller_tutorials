#!/bin/bash

	declare -a arr

	i=0;
#<----------first method of array init----------->
<< array_cmnnt1  #this a commnt to commnt multilines
	
	arr[0]="hello"
	arr[1]=27
	arr[2]='x'

array_cmnnt1
#<------2nd method of array init----------->
#	arr=("hello" 27 "x")


#<------enetering array------------->
<<array_cmmnt2

	echo "enter arr[] elemnts sepertd by space :"
	read -a arr

	while [ $i -lt 3 ]
	do
		echo "arr [ $i ] = ${arr[$i]} "
		i=$((i+1))
	done
array_cmmnt2
