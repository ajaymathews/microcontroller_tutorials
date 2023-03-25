#!/bin/bash

#<---------method 1----------->

#	cat sample_file.txt | while read Line #similar to store file name in a variable and use 'cat var | while read line
#	do
#		echo $Line
#		sleep 1
#	done
#in this method the piping opeartion is done in seperte terminal, thus counting variable gets initialized


#<------------Method2-------------->

	while read line
	do
		echo $line
		sleep 1
	done < sample_file.txt
	exit 10 #this will return a 10 same as 0 or 1 in void main()




