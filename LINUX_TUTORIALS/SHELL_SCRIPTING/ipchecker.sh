#!/bin/bash

echo "enter some ip adress seprtd by space"
read -a ip

for i in ${ip[@]}
do
	echo " ...................."
	ping -c 1 -w 3 $i 2>&1 >/dev/null
	if [ $? -eq 0 ]
	then 
		echo "HOST $i is alive"
	else
		echo "HOST $i is down"
	fi
done

