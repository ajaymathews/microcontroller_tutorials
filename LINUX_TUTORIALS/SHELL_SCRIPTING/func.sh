#!/bin/bash
<< fun_cmmnt

fun()
{
disk_name=$1//in here the $1 means the aargumnets passed to this fun
echo "disk free space and details are"
df -kh $(disk_name)
}
fun 

fun_cmmnt
