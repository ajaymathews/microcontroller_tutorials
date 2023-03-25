#!/bin/bash

#<-------- if_elseif statemnt---------->
<<cond_cmmnt

	a=$1 #entered via inline commnd, thre shouldnt be any space 
	b=$2 #entered as 2nd commnd line argumnt
	if [ $a == $b ] 
#	if [ $a -eq $b ]
	then
		printf "$a and $b are same"
	elif [ $a -gt $b ] # -lt is for lesser than 
	then
		printf "$a is greater than $b"
	else
		printf "$b is greater than $a"
	fi

cond_cmmnt

#<----------if_else------------->
<<cond_cmmnt2

	MY_VAR=$1 #NOT THAT NO SPACE IN BETWEEN '=', otherwise it shows error
	
	if[ -z $MY_VAR ] #-n will true if length is non-zero
	then
        	echo "the length of string enterd is zero"
	fi
	
	if [ $MY_VAR == "HELLO" ]
	then
        	echo "hi"
	else
        	echo "unknown commnd"
	fi

cond_cmmnt2

#<---------------CASE ----------------->
	var=$1 #the assignment operation should have no space
	case $var in
		1)echo "Its number 1"
			;;
		"hii")echo "Its a string"
			;;
		*)echo "default operation"
			;;
	esac
