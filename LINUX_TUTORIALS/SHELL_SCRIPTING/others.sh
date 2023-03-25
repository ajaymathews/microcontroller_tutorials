#!/bin/bash
 

#<------------exit------------->	
<<exit_cmmnt

	#./nil.sh #calling non-existing shell script will return error
	./loops.sh
	if [ $? -ne 0 ] #anything non-zero is an errorr
	then
	echo "executed some errors"
	else
	echo "code executed sucessfully"
	fi

exit_cmmnt

#<------------random------------->
<<random_cmmnt

	echo $RANDOM #this will print the numbers in large number
	i=0
	while [ $i -lt 10 ] 
	do
		echo $((RANDOM%1000)) #this will print the number below 1000
		i=$((i+1))
	done

random_cmmnt
