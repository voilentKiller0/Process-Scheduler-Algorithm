# Process Schedulers Implementation in C++

## Overview
This C++ project implements various process scheduling algorithms to simulate the execution of processes in an operating system. The implemented schedulers include:


1. First Come First Serve (FCFS) [🔗](https://www.javatpoint.com/os-fcfs-scheduling)
2. Shortest Job First (SJF) [🔗](https://www.javatpoint.com/os-sjf-scheduling)
3. Shortest Remaining Time First (SRTF) [🔗](https://www.javatpoint.com/os-srtf-scheduling-algorithm)
4. Round Robin (RR) [🔗](https://www.javatpoint.com/os-round-robin-scheduling-algorithm)
5. Longest Job First (LJF) [🔗](https://edurev.in/t/248589/Longest-Job-First--LJF--CPU-Scheduling-Algorithm)
6. Longest Remaining Time First (LRTF) [🔗](https://www.geeksforgeeks.org/longest-remaining-time-first-lrtf-cpu-scheduling-algorithm/)
7. Highest Response Time First (HRTF) - Non-preemptive [🔗](https://www.javatpoint.com/os-hrrn-scheduling)

## Getting Started
### Prerequisites
Make sure you have the following installed on your system:

* C++ compiler (e.g., g++)
* Git (optional, for cloning the repository)

### Installation

1. Clone the repository:
   ```
   git clone https://github.com/voilentKiller0/Process-Scheduler-Algorithm.git
   ```
2. Navigate to the project directory:
   ```
   cd Process-Scheduler-Algorithm
   ```
3. Compile the source code:
   ```
   g++ "main.cpp" -o "main.exe"
   ```

### USage

Run the compiled executable:
```
.\main.exe
```
The program will first prompt you to choose the type of input you want to provide, whether it is through the terminal or from an input.txt file. Then, you will be asked to provide the time quantum for the Round Robin Algorithm. 
After that, you will be prompted to enter the number of processes you want to schedule. 
Finally, you will need to enter the arrival time and burst time for each process, separated by a space.

### File Structure 

* main.cpp : Entry point of the program.
* input.txt : For file input.

## Output

```
PS D:\Scheduler> cd "d:\Scheduler\" ; if ($?) { g++ "main.cpp" -o "main.exe" } ; if ($?) { & ".\main.exe" }
For taking input from file enter 1 or manual input enter 2
1

=================================================================================================================
|                                                                                         First Come First Serve|
-----------------------------------------------------------------------------------------------------------------
|     Process No|   Arrival Time|     Burst Time|  Response Time|Completion Time|            TAT|             WT|
----------------+---------------+---------------+---------------+---------------+---------------+---------------+
|              1|              0|              3|              0|              3|              3|              0|
|              2|              2|              6|              1|              9|              7|              1|
|              3|              4|              4|              5|             13|              9|              5|
|              4|              6|              5|              7|             18|             12|              7|
|              5|              8|              2|             10|             20|             12|             10|
-----------------------------------------------------------------------------------------------------------------
Average Response Time : 4.6
Average Completion Time : 12.6
Average Tunr Around Time (TAT) Time : 8.6
Average Waiting Time (WT) Time : 4.6


=================================================================================================================
|                                                                                             Shortest Job First|
-----------------------------------------------------------------------------------------------------------------
|     Process No|   Arrival Time|     Burst Time|  Response Time|Completion Time|            TAT|             WT|
----------------+---------------+---------------+---------------+---------------+---------------+---------------+
|              1|              0|              3|              0|              3|              3|              0|
|              2|              2|              6|              1|              9|              7|              1|
|              3|              4|              4|              7|             15|             11|              7|
|              4|              6|              5|              9|             20|             14|              9|
|              5|              8|              2|              1|             11|              3|              1|
-----------------------------------------------------------------------------------------------------------------
Average Response Time : 3.6
Average Completion Time : 11.6
Average Tunr Around Time (TAT) Time : 7.6
Average Waiting Time (WT) Time : 8.2


=================================================================================================================
|                                                                                  Shortest Reamining Time First|
-----------------------------------------------------------------------------------------------------------------
|     Process No|   Arrival Time|     Burst Time|  Response Time|Completion Time|            TAT|             WT|
----------------+---------------+---------------+---------------+---------------+---------------+---------------+
|              1|              0|              3|              0|              3|              3|              0|
|              2|              2|              6|              1|             15|             13|              7|
|              3|              4|              4|              0|              8|              4|              0|
|              4|              6|              5|              9|             20|             14|              9|
|              5|              8|              2|              0|             10|              2|              0|
-----------------------------------------------------------------------------------------------------------------
Average Response Time : 2
Average Completion Time : 11.2
Average Tunr Around Time (TAT) Time : 7.2
Average Waiting Time (WT) Time : 3.2


=================================================================================================================
|                                                                                        Round Robin with TQ = 3|
-----------------------------------------------------------------------------------------------------------------
|     Process No|   Arrival Time|     Burst Time|  Response Time|Completion Time|            TAT|             WT|
----------------+---------------+---------------+---------------+---------------+---------------+---------------+
|              1|              0|              3|              0|              3|              3|              0|
|              2|              2|              6|              1|             15|             13|              7|
|              3|              4|              4|              2|             18|             14|             10|
|              4|              6|              5|              3|             20|             14|              9|
|              5|              8|              2|              7|             17|              9|              7|
-----------------------------------------------------------------------------------------------------------------
Average Response Time : 2.6
Average Completion Time : 14.6
Average Tunr Around Time (TAT) Time : 10.6
Average Waiting Time (WT) Time : 6.6


=================================================================================================================
|                                                                                              Longest Job First|
-----------------------------------------------------------------------------------------------------------------
|     Process No|   Arrival Time|     Burst Time|  Response Time|Completion Time|            TAT|             WT|
----------------+---------------+---------------+---------------+---------------+---------------+---------------+
|              1|              0|              3|              0|              3|              3|              0|
|              2|              2|              6|              1|              9|              7|              1|
|              3|              4|              4|             10|             18|             14|             10|
|              4|              6|              5|              3|             14|              8|              3|
|              5|              8|              2|             10|             20|             12|             10|
-----------------------------------------------------------------------------------------------------------------
Average Response Time : 4.8
Average Completion Time : 12.8
Average Tunr Around Time (TAT) Time : 8.8
Average Waiting Time (WT) Time : 11.4


=================================================================================================================
|                                                                                   Longest Remaining Time First|
-----------------------------------------------------------------------------------------------------------------
|     Process No|   Arrival Time|     Burst Time|  Response Time|Completion Time|            TAT|             WT|
----------------+---------------+---------------+---------------+---------------+---------------+---------------+
|              1|              0|              3|              0|             16|             16|             13|
|              2|              2|              6|              0|             17|             15|              9|
|              3|              4|              4|              1|             18|             14|             10|
|              4|              6|              5|              0|             19|             13|              8|
|              5|              8|              2|              6|             20|             12|             10|
-----------------------------------------------------------------------------------------------------------------
Average Response Time : 1.4
Average Completion Time : 18
Average Tunr Around Time (TAT) Time : 14
Average Waiting Time (WT) Time : 10


=================================================================================================================
|                                                                   Highest Response Time First (Non-Preemptive)|
-----------------------------------------------------------------------------------------------------------------
|     Process No|   Arrival Time|     Burst Time|  Response Time|Completion Time|            TAT|             WT|
----------------+---------------+---------------+---------------+---------------+---------------+---------------+
|              1|              0|              3|              0|              3|              3|              0|
|              2|              2|              6|              1|              9|              7|              1|
|              3|              4|              4|              5|             13|              9|              5|
|              4|              6|              5|              9|             20|             14|              9|
|              5|              8|              2|              5|             15|              7|              5|
-----------------------------------------------------------------------------------------------------------------
Average Response Time : 4
Average Completion Time : 12
Average Tunr Around Time (TAT) Time : 8
Average Waiting Time (WT) Time : 4

```


