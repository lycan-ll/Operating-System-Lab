#!/bin/bash

echo "Enter the OOP marks"
read opp
echo "Enter the Data marks"
read data
echo "Enter the os marks"
read os
echo "Enter the pf marks"
read pf
echo "Enter the Calculus marks"
read cal
echo $'\n' #newline


marks_to_grade()
{
	 if [ $1 -ge 80 -a $1 -le 100 ] ; then
	    grade1="A"
             echo "A"
	 fi

        if [ $1 -ge 60 -a $1 -le 79 ] ; then
		grade1="B"
                echo "B"
		
        fi
	 if [ $1 -ge 40 -a $1 -le 59 ] ; then
		grade1="C"
                echo "C"
		
        fi
	 if [ $1 -ge 30 -a $1 -le 39 ] ; then
		grade1="D"
                echo "D"
		
        fi
	 if [ $1 -ge 20 -a $1 -le 29 ] ; then
		grade1="F"
                echo "F"
	 fi
 }


grade_to_point(){
	if [ "$grade1" = "A" ] ; then
		echo "4.00" $'\n'
	fi
	if [ "$grade1" = "B" ] ; then
		echo "3.00" $'\n'
	fi
	if [ "$grade1" = "C" ] ; then
		echo "2.00" $'\n'
	fi
	if [ "$grade1" = "D" ] ; then
		echo "1.00" $'\n'
	fi
	if [ "$grade1" = "F" ] ; then
		echo "0" $'\n'
	fi

}


marks_to_grade $opp
grade_to_point $oop

marks_to_grade $data
grade_to_point $data

marks_to_grade $os
grade_to_point $os


marks_to_grade $pf
grade_to_point $pf

marks_to_grade $cal
grade_to_point $cal

