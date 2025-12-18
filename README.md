# Round-robin-scheduling-Operating-System-Mini-Project-
A CPU Scheduling Simulator implementing the Round Robin (RR) algorithm using Shell Script and C. The project simulates process execution, generates Gantt charts, computes waiting time, turnaround time, completion time, CPU utilization, and demonstrates fair preemptive scheduling as part of an Operating Systems minor project.
<br>
# 🖥️ Round Robin CPU Scheduling Simulator (OS Minor Project)

This repository contains the implementation of a **CPU Scheduling Simulator** using the **Round Robin (RR)** scheduling algorithm.  
The project is developed as part of an **Operating Systems Minor Project** and demonstrates how modern operating systems fairly allocate CPU time among multiple processes.

The simulator is implemented using:
- **Shell Script (Bash)**
- **C Programming Language**

---

## 📌 Project Objectives

The objectives of this project are to:

- Understand how CPU scheduling works in operating systems
- Implement **Round Robin scheduling**, a preemptive and fair algorithm
- Simulate real-time process execution using:
  - Arrival Time
  - Burst Time
  - Time Quantum
- Generate a **Gantt Chart** representing CPU allocation
- Calculate important scheduling metrics:
  - Completion Time (CT)
  - Turnaround Time (TAT)
  - Waiting Time (WT)
  - Average WT and TAT
  - CPU Utilization
- Gain hands-on experience with OS-level simulation and queue management

---

## 🧠 Theory Overview

### CPU Scheduling
CPU scheduling determines which process gets access to the CPU when multiple processes are ready to execute. Efficient scheduling improves:
- CPU utilization
- Throughput
- Response time
- Fairness

### Round Robin Scheduling
Round Robin is a **preemptive scheduling algorithm** where:
- Each process gets a fixed **time quantum**
- If a process does not finish within the quantum, it is preempted and placed at the end of the ready queue
- Starvation is avoided
- Suitable for interactive and time-sharing systems

---

## 📊 Key Scheduling Parameters

| Term | Description |
|----|------------|
| Arrival Time (AT) | Time when a process enters the ready queue |
| Burst Time (BT) | Total CPU time required |
| Remaining Time (RT) | Remaining execution time |
| Completion Time (CT) | Time at which process completes |
| Turnaround Time (TAT) | CT − AT |
| Waiting Time (WT) | TAT − BT |
| Time Quantum | Fixed CPU time slice |

---

## ⚙️ Algorithm (Round Robin)

1. Input number of processes
2. Read Arrival Time and Burst Time for each process
3. Input Time Quantum
4. Initialize Remaining Time = Burst Time
5. Maintain a ready queue
6. Execute processes in round-robin fashion
7. Preempt processes exceeding time quantum
8. Update completion, waiting, and turnaround times
9. Compute averages and CPU utilization
10. Display Gantt Chart and results

---

## 🛠️ Implementation Details

### 🐚 Shell Script
- Implements Round Robin scheduling logic
- Uses arrays to track process attributes
- Generates a textual Gantt Chart
- Computes average waiting and turnaround time
- Calculates CPU utilization

