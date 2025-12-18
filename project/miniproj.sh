#!/bin/bash

echo "----- ROUND ROBIN CPU SCHEDULER -----"

# Input number of processes
read -p "Enter number of processes: " n

# Input Arrival and Burst Times
for ((i=1;i<=n;i++)); do
    read -p "Enter Arrival Time of P$i: " at[$i]
    read -p "Enter Burst Time of P$i: " bt[$i]
    rt[$i]=${bt[$i]}   # Remaining time
done

# Time Quantum
read -p "Enter Time Quantum: " q

time=0
completed=0
idleTime=0

echo -e "\nGANTT CHART:"
echo -n "| "

while [ $completed -lt $n ]; do
    executed=false

    for ((i=1;i<=n;i++)); do

        if [ ${rt[$i]} -gt 0 ] && [ ${at[$i]} -le $time ]; then
            executed=true

            if [ ${rt[$i]} -gt $q ]; then
                echo -n "P$i | "
                time=$((time + q))
                rt[$i]=$((rt[$i] - q))
            else
                echo -n "P$i | "
                time=$((time + rt[$i]))
                rt[$i]=0
                ct[$i]=$time
                completed=$((completed + 1))
            fi
        fi
    done

    if ! $executed; then
        echo -n "Idle | "
        idleTime=$((idleTime + 1))
        time=$((time + 1))
    fi
done

echo -e "\n"

# Table Header
printf "%-10s %-5s %-5s %-5s %-6s %-5s\n" "Process" "AT" "BT" "CT" "TAT" "WT"
echo "-------------------------------------------------------"

totalWT=0
totalTAT=0

# Calculate & Display Metrics
for ((i=1;i<=n;i++)); do
    tat[$i]=$((ct[$i] - at[$i]))
    wt[$i]=$((tat[$i] - bt[$i]))

    totalWT=$((totalWT + wt[$i]))
    totalTAT=$((totalTAT + tat[$i]))

    printf "%-10s %-5s %-5s %-5s %-6s %-5s\n" "P$i" "${at[$i]}" "${bt[$i]}" "${ct[$i]}" "${tat[$i]}" "${wt[$i]}"
done

# Averages (using bc)
avgWT=$(echo "scale=2; $totalWT / $n" | bc)
avgTAT=$(echo "scale=2; $totalTAT / $n" | bc)
cpu_util=$(echo "scale=2; (($time - $idleTime) / $time) * 100" | bc)

echo ""
echo "Average Waiting Time       : $avgWT"
echo "Average Turnaround Time    : $avgTAT"
echo "CPU Utilization            : $cpu_util %"
