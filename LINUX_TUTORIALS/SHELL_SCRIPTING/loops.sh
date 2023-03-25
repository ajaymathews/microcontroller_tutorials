#!/bin/bash


#<-----while loop-----> 
<<while_cmmnt

 	i=0;
 	while [ $i -lt 10 ]    #the space after while and inside the [] is must,-lt is for less than
 	do 
		echo $i
		i=$((i+1))
        	sleep 1
		if [ $var == 7 ] #we can break from the loop using break statement
		then
			echo "exiting via break"
			break
		fi
                               #this is the method to incremnt a varaible
	done

while_cmmnt


#  while [ 1 ] or while: is an infinite loop
#whole opertion can be done on the shell itself without the script
# while :; do echo hello; sleep 1; done




#<--------until loop--------->
<<until_cmmnt

	i=10
	until [ $i -le 0 ]      #until runs if the condition is false, -le is lessthan or equalto
	do
		echo "hello"
		i=$((i-1))
		sleep 1
	done

until_cmmnt


#<------for loop------->
<<for_cmmnt

#	for var in 1 2 3 a b c "hello" #for loop will run by changing the value of $var through 1,2..'hello'
#	for var in {1..25}             #another method for for loop till 1-25
#	for var in {0..25..5}          #prints the number from 0-25 incremnts by 5
	for ((var=0; var<=10; var++))
	do 
		echo $var
		sleep 1
		if [ $var == 7 ]
		then
			echo "exiting via break"
			break
		fi
	done
	printf "the last value after loop is $var"

for_cmmnt
