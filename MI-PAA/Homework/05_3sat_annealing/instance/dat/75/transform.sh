#!/bin/bash

for file in ./*.3sat
do
	COUNT="`cat $file | wc -l`"
	HEAD="p cnf 75 $(($COUNT-1))"
	echo "$HEAD" > "${file}.cnf"
	while read LINE
	do
		if [ ${#LINE} -gt 12 ]
		then
			echo "w $LINE" >> "${file}.cnf"
		else 
			echo "$LINE 0" >> "${file}.cnf"
		fi

	done < $file 
done
