#!/bin/bash

# Script to print the maximum process ID value
if [ -r /proc/sys/kernel/pid_max ]; then
	max_pid=$(cat /proc/sys/kernel/pid_max)
	echo "The maximum value a process ID can be is: $max_pid"
else
	echo "Error: Cannot read /proc/sys/kernel/pid_max."
	exit 1
fi
