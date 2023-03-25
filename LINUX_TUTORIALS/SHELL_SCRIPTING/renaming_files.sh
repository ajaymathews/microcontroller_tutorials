#! /bin/bash

TXT=$(ls *txt)
DATE=$(date +%s)


for text in $TXT
do
	echo "renaming $text to $DATE"
	mv $text $DATE-$text
done
