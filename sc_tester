#!/bin/bash

if [ -z "$1" ]; then
	check_num='100'
else
	check_num=$1
fi

inst_check_3_arg ()
{
	ARG=`ruby -e "puts (1..3).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
}

inst_check_5_arg ()
{
	ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
}

inst_check_10_arg ()
{
	ARG=`ruby -e "puts (1..10).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
}

inst_check_100_arg ()
{
	ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
}

inst_check_500_arg ()
{
	ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
}


ok_check_3_arg ()
{
	ARG=`ruby -e "puts (1..3).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
	echo "$ARG" > logs_1
}

ok_check_5_arg ()
{
	ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
	echo "$ARG" > logs_5
}

ok_check_10_arg ()
{
	ARG=`ruby -e "puts (1..10).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
	echo "$ARG" > logs_10
}

ok_check_100_arg ()
{
	ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
	echo "$ARG" > logs_100
}

ok_check_500_arg ()
{
	ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
	echo "$ARG" > logs_500
}

test_inst_3 ()
{
	count=0
	max=0
	min=0
	while [ $count -le $check_num ]
	do
		ret=$( inst_check_3_arg )
		if [ $ret -le $min ] || [ $min -eq 0 ]; then
			min=$ret
		fi
		if [ $ret -ge $max ]; then
			max=$ret
		fi
		ave=$(($ave + $ret))
		((count++))
	done

	ave=$(($ave / count))
	echo FOR 3 NB
	printf "Min ops =\t%d\nMax ops =\t%d\nAverage ops =\t%d\n" $min $max $ave
}

test_inst_5 ()
{
	count=0
	max=0
	min=0
	while [ $count -le $check_num ]
	do
		ret=$( inst_check_5_arg )
		if [ $ret -le $min ] || [ $min -eq 0 ]; then
			min=$ret
		fi
		if [ $ret -ge $max ]; then
			max=$ret
		fi
		ave=$(($ave + $ret))
		((count++))
	done

	ave=$(($ave / count))
	echo FOR 5 NB
	printf "Min ops =\t%d\nMax ops =\t%d\nAverage ops =\t%d\n" $min $max $ave
}

test_inst_10 ()
{
	count=0
	max=0
	min=0
	while [ $count -le $check_num ]
	do
		ret=$( inst_check_10_arg )
		if [ $ret -le $min ] || [ $min -eq 0 ]; then
			min=$ret
		fi
		if [ $ret -ge $max ]; then
			max=$ret
		fi
		ave=$(($ave + $ret))
		((count++))
	done

	ave=$(($ave / count))
	echo FOR 10 NB
	printf "Min ops =\t%d\nMax ops =\t%d\nAverage ops =\t%d\n" $min $max $ave
}

test_inst_100 ()
{
	count=0
	max=0
	min=0
	while [ $count -le $check_num ]
	do
		ret=$( inst_check_100_arg )
		if [ $ret -le $min ] || [ $min -eq 0 ]; then
			min=$ret
		fi
		if [ $ret -ge $max ]; then
			max=$ret
		fi
		ave=$(($ave + $ret))
		((count++))
	done

	ave=$(($ave / count))
	echo FOR 100 NB
	printf "Min ops =\t%d\nMax ops =\t%d\nAverage ops =\t%d\n" $min $max $ave
}

test_inst_500 ()
{
	count=0
	max=0
	min=0
	while [ $count -le $check_num ]
	do
		ret=$( inst_check_500_arg )
		if [ $ret -le $min ] || [ $min -eq 0 ]; then
			min=$ret
		fi
		if [ $ret -ge $max ]; then
			max=$ret
		fi
		ave=$(($ave + $ret))
		((count++))
	done

	ave=$(($ave / count))
	echo FOR 500 NB
	printf "Min ops =\t%d\nMax ops =\t%d\nAverage ops =\t%d\n" $min $max $ave
}

test_ok_3 ()
{
	echo 'Checker 1:'
	count=0
	while [ $count -le $check_num ];
	do
		if [ $( ok_check_3_arg )  != 'OK' ]; then
			echo False
			return 0
		fi
		((count++))
	done
	echo True
}

test_ok_5 ()
{
	echo 'checker 5:'
	count=0
	while [ $count -le $check_num ];
	do
		if [ $( ok_check_5_arg )  != 'OK' ]; then
			echo False
			return 0
		fi
		((count++))
	done
	echo True
}

test_ok_10 ()
{
	echo 'Checker 10:'
	count=0
	while [ $count -le $check_num ];
	do
		if [ $( ok_check_10_arg )  != 'OK' ]; then
			echo False
			return 0
		fi
		((count++))
	done
	echo True
}

test_ok_100 ()
{
	echo 'Checker 100:'
	count=0
	while [ $count -le $check_num ];
	do
		if [ $( ok_check_100_arg )  != 'OK' ]; then
			echo False
			return 0
		fi
		((count++))
	done
	echo True
}

test_ok_500 ()
{
	echo 'Checker 500:'
	count=0
	while [ $count -le $check_num ];
	do
		if [ $( ok_check_500_arg )  != 'OK' ]; then
			echo False
			return 0
		fi
		((count++))
	done
	echo True
}

t1=$(test_inst_3 &)
t2=$(test_inst_5 &)
t3=$(test_inst_10 &)
t4=$(test_inst_100 &)
t5=$(test_inst_500 &)
wait

echo "$t1"
echo
echo "$t2"
echo
echo "$t3"
echo
echo "$t4"
echo
echo "$t5"
echo

test_ok_3
test_ok_5
test_ok_10
test_ok_100
test_ok_500
