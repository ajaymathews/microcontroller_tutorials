#! /bin/bash

read -p "Enter the username: " uname
read -p "Enter the password: " upass
read -p "confirm the pasword: " upass1
echo "enter the erray elemnts seperated by space"
read -a  arr

if [ $upass1 == $upass ]
then
	echo "password confirmed"
	for i in ${arr[@]}
	do 
		echo "enterd value is $i"
	done

else
	echo "password incorrect"
	echo "now you can create a user from the shell"
fi



