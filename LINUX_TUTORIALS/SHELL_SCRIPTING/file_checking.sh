#!/bin/bash
#b -> file exists and block file
#c -> file exists and charcter file
#d file exists and a directory
#-e file exists
#-f reular file


check_file=$1

if [ -e  $check_file ]
then 
	echo "file exists"
fi

if [ -f  $check_file ]
then 
        echo "its a regular file"
fi

if [ -c  $check_file ]
then 
        echo "charcter file"
fi

if [ -b  $check_file ]
then 
        echo "its a block file"
fi

if [ -d  $check_file ]
then 
        echo "its a directory"
fi
