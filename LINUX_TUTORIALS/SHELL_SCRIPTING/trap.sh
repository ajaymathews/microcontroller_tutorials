#!/bin/bash

<<test1
	function fun()
	{
	echo " function is called "
	}
	trap 'fun' SIGHUP SIGINT SIGTRAP SIGILL #this will execute function  fun, when the signal interrupt, trap, up orillegal comes
	trap ' echo "    you are interrupting by cntrl+c"' SIGINT
test1

<<test2
	function fun1()
	{
	echo "fun is invoked"
	echo "by the signal $1"
	}

	trap 'fun1 SIGINT; continue ' SIGINT
	trap 'fun1 SIGHUP; exit 1' SIGHUP
	trap 'fun1 SIGILL; exit 1' SIGILL
	while [ 1 ]
	do
		echo "the loop is running"
		sleep 1
	done
test2



#this will only exit if 3 times cntrl+c is pressed, first time goes to fun1, then to fun2, and thento trap thus one more will exit.

	function fun2()
	{
	echo "fun2 is invoked"
	trap - SIGINT
	}

	function fun1()
	{
	echo "fun1 is invoked"
	trap fun2 SIGINT
	}

	trap 'fun1 SIGINT; continue ' SIGINT
	trap 'fun1 SIGHUP; exit 1' SIGHUP
	trap 'fun1 SIGILL; exit 1' SIGILL
	while [ 1 ]
	do
		echo "the loop is running"
		sleep 1
	done




#we can use any signal by using the commnd  ' kill COMMND_no process_no'
#in  this find the commnd_no for corresponding trap, such as 4 is SIGILL
#9 is SIGKILL, and find the process id from another terminal while trap.sh is running
#using 'ps -ef | grep trap' and enter any of the kill commnd.  
