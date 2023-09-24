#include<bits/stdc++.h>

using namespace std;

class Process{
    private:
        int processNo;
        int arrivalTime;
        int burstTime;
        int completionTime;
        int responseTime;
        bool response;
    
    public:
        /**
        * / / object / string. This is a bit complex. We need to be able to pass a string to the object
        */
        Process(){
            this -> processNo = 0;
            this -> arrivalTime = 0;
            this -> burstTime = 0;
            this -> completionTime = 0;
            this -> responseTime = 0;
            this -> response = false;
        }
        /**
        * @param processNo
        * @param arrivalTime
        * @param burstTime
        */
        Process(int processNo, int arrivalTime, int burstTime){
            this -> processNo = processNo;
            this -> arrivalTime = arrivalTime;
            this -> burstTime = burstTime;
            this -> completionTime = 0;
            this -> responseTime = 0;
            this -> response = false;
        }
        /**
        * @return Process number of this process. This is the same as the value returned by process
        */
        int getProcessNo(){
            return this -> processNo;
        }
        /**
        * @return Time in ms until arrival. 0 means no
        */
        int getArrivalTime(){
            return this -> arrivalTime;
        }
        /**
        * @return Time in milliseconds since the last burst of the data
        */
        int getBurstTime(){
            return this -> burstTime;
        }
        /**
        * @return time in ms until completion or - 1 if not
        */
        int getCompletionTime(){
            return this -> completionTime;
        }
        /**
        * @return Time the response was received in nanoseconds since the start of the
        */
        int getResponseTime(){
            return this -> responseTime;
        }
        /**
        * @return true if response is true false otherwise ( this is a request
        */
        bool getResponse(){
            return this -> response;
        }
        /**
        * @param arrivalTime
        */
        void setArrivalTime(int arrivalTime){
            this -> arrivalTime = arrivalTime;
        }
        /**
        * @param burstTime
        */
        void setBurstTime(int burstTime){
            this -> burstTime = burstTime;
        }
        /**
        * @param completionTime
        */
        void setCompletionTime(int completionTime){
            this -> completionTime = completionTime;
        }
        /**
        * @param responseTime
        */
        void setResponseTime(int responseTime){
            this -> responseTime = responseTime;
        }
        /**
        * @param response
        */
        void setResponse(bool response){
            this -> response = response;
        }
};


// First Come First Serve
class FCFSSchesduler{
    private:
        vector<Process> vectorOfProcess;
        
    public:
        /**
        * @param vectorOfProcess
        */
        FCFSSchesduler(vector<Process> vectorOfProcess){
            this  -> vectorOfProcess = vectorOfProcess;
        }
        class Compare{
            public:
                /**
                * @param p1
                * @param p2
                * 
                * @return True if p1 is greater than p2 false otherwise
                */
                bool operator() (Process p1, Process p2){
                    return (p1.getArrivalTime() == p2.getArrivalTime()) ? p1.getProcessNo() > p2.getProcessNo() : p1.getArrivalTime() > p2.getArrivalTime();
                };
        };
        vector<Process> schedule(){
            vector<Process> scheduledProcess;
            priority_queue<Process, vector<Process>, Compare> runningQueue;

            int time = 0;
            
            while (!vectorOfProcess.empty() || !runningQueue.empty()){
                while (!vectorOfProcess.empty() && time >= vectorOfProcess[0].getArrivalTime()){
                    runningQueue.push(vectorOfProcess[0]);
                    vectorOfProcess.erase(vectorOfProcess.begin());
                }
                if (!runningQueue.empty()){
                    Process p = runningQueue.top(); runningQueue.pop();
                    p.setResponseTime(time - p.getArrivalTime());
                    time += p.getBurstTime();
                    p.setCompletionTime(time);
                    scheduledProcess.push_back(p);
                }else{
                    time++;
                }
                
            }
            return scheduledProcess;
        }

};

// Shortest Job First
class SJFScheduler{
    private:
        vector<Process> vectorOfProcess;
        
    public:
        /**
        * @param vectorOfProcess
        */
        SJFScheduler(vector<Process> vectorOfProcess){
            this  -> vectorOfProcess = vectorOfProcess;
        }
        class Compare{
            public:
                /**
                * @param p1
                * @param p2
                * 
                * @return True if p1 is greater than p2 false otherwise
                */
                bool operator() (Process p1, Process p2){
                    return (p1.getBurstTime() == p2.getBurstTime()) ? p1.getArrivalTime() > p2.getArrivalTime() : p1.getBurstTime() > p2.getBurstTime();
                };
        };
        vector<Process> schedule(){
            vector<Process> scheduledProcess;
            priority_queue<Process, vector<Process>, Compare> runningQueue;

            int time = 0;
            
            while (!vectorOfProcess.empty() || !runningQueue.empty()){
                while (!vectorOfProcess.empty() && time >= vectorOfProcess[0].getArrivalTime()){
                    runningQueue.push(vectorOfProcess[0]);
                    vectorOfProcess.erase(vectorOfProcess.begin());
                }
                if (!runningQueue.empty()){
                    Process p = runningQueue.top(); runningQueue.pop();
                    p.setResponseTime(time - p.getArrivalTime());
                    time += p.getBurstTime();
                    p.setCompletionTime(time);
                    scheduledProcess.push_back(p);
                }else{
                    time++;
                }
                
            }
            return scheduledProcess;
        }
};


// Shortest Remaining Time First
class SRTFSchedule{
    private:
        vector<Process> vectorOfProcess;
        
    public:
        /**
        * @param vectorOfProcess
        */
        SRTFSchedule(vector<Process> vectorOfProcess){
            this  -> vectorOfProcess = vectorOfProcess;
        }
        class Compare{
            public:
                /**
                * @param p1
                * @param p2
                * 
                * @return True if p1 is greater than p2 false otherwise
                */
                bool operator() (Process p1, Process p2){
                    return (p1.getBurstTime() == p2.getBurstTime()) ? p1.getArrivalTime() > p2.getArrivalTime() : p1.getBurstTime() > p2.getBurstTime();
                };
        };
        vector<Process> schedule(){
            vector<Process> scheduledProcess;
            priority_queue<Process, vector<Process>, Compare> runningQueue;
            map<int, int> preservedBT;

            int time = 0;
            while (!vectorOfProcess.empty() || !runningQueue.empty()){
                while (!vectorOfProcess.empty() && time >= vectorOfProcess[0].getArrivalTime()){
                    runningQueue.push(vectorOfProcess[0]);
                    preservedBT[vectorOfProcess[0].getProcessNo()] = vectorOfProcess[0].getBurstTime();
                    vectorOfProcess.erase(vectorOfProcess.begin());
                }
                if (!runningQueue.empty()){
                    Process p = runningQueue.top(); runningQueue.pop();

                    if (!p.getResponse()){
                        p.setResponseTime(time - p.getArrivalTime());
                        p.setResponse(true);
                    }

                    p.setBurstTime(p.getBurstTime() - 1);
                    time++;
                    if (p.getBurstTime() == 0){
                        p.setCompletionTime(time);
                        scheduledProcess.push_back(p);
                    }else{
                        runningQueue.push(p);
                    }
                    
                }else{
                    time++;
                }
                
            }
            for (int i = 0 ; i < scheduledProcess.size() ; i++){
                scheduledProcess[i].setBurstTime(preservedBT[scheduledProcess[i].getProcessNo()]);
            }
            return scheduledProcess;
        }
};


// Round Robin Scheduler
class RRSchedule{
    private:
        vector<Process> vectorOfProcess;
        int timequant;
    public:
        /**
        * @param vectorOfProcess
        * @param timequant
        */
        RRSchedule(vector<Process> vectorOfProcess, int timequant){
            this -> vectorOfProcess = vectorOfProcess;
            this -> timequant = timequant; 
        }
        vector<Process> schedule(){
            vector<Process> scheduledProcess;
            queue<Process> runningQueue;
            map<int, int> preservedBT;

            int time = 0;
            while (!vectorOfProcess.empty() || !runningQueue.empty()){
                while (!vectorOfProcess.empty() && time >= vectorOfProcess[0].getArrivalTime()){
                    runningQueue.push(vectorOfProcess[0]);
                    preservedBT[vectorOfProcess[0].getProcessNo()] = vectorOfProcess[0].getBurstTime();
                    vectorOfProcess.erase(vectorOfProcess.begin());
                }

                if (!runningQueue.empty()){
                    Process p = runningQueue.front(); runningQueue.pop();

                    if (!p.getResponse()){
                        p.setResponseTime(time - p.getArrivalTime());
                        p.setResponse(true);
                    }
                    if (p.getBurstTime() <= timequant){
                        time += p.getBurstTime();
                        p.setCompletionTime(time);
                        scheduledProcess.push_back(p);
                    }else{
                        time += timequant;
                        p.setBurstTime(p.getBurstTime() - timequant);
                        while (!vectorOfProcess.empty() && time >= vectorOfProcess[0].getArrivalTime()){
                            runningQueue.push(vectorOfProcess[0]);
                            preservedBT[vectorOfProcess[0].getProcessNo()] = vectorOfProcess[0].getBurstTime();
                            vectorOfProcess.erase(vectorOfProcess.begin());
                        }
                        runningQueue.push(p);
                    }
                    
                }else{
                    time++;
                }
                
            }
            for (int i = 0 ; i < scheduledProcess.size() ; i++){
                scheduledProcess[i].setBurstTime(preservedBT[scheduledProcess[i].getProcessNo()]);
            }
            return scheduledProcess;
        }
};


// Longest Job First
class LJFScheduler{
    private:
        vector<Process> vectorOfProcess;
        
    public:
        /**
        * @param vectorOfProcess
        */
        LJFScheduler(vector<Process> vectorOfProcess){
            this  -> vectorOfProcess = vectorOfProcess;
        }
        class Compare{
            public:
                /**
                * @param p1
                * @param p2
                * 
                * @return True if p1 is higher than p2 false otherwise
                */
                bool operator() (Process p1, Process p2){
                    return (p1.getBurstTime() == p2.getBurstTime()) ? p1.getArrivalTime() > p2.getArrivalTime() : p1.getBurstTime() < p2.getBurstTime();
                };
        };
        vector<Process> schedule(){
            vector<Process> scheduledProcess;
            priority_queue<Process, vector<Process>, Compare> runningQueue;

            int time = 0;
            
            while (!vectorOfProcess.empty() || !runningQueue.empty()){
                while (!vectorOfProcess.empty() && time >= vectorOfProcess[0].getArrivalTime()){
                    runningQueue.push(vectorOfProcess[0]);
                    vectorOfProcess.erase(vectorOfProcess.begin());
                }
                if (!runningQueue.empty()){
                    Process p = runningQueue.top(); runningQueue.pop();
                    p.setResponseTime(time - p.getArrivalTime());
                    time += p.getBurstTime();
                    p.setCompletionTime(time);
                    scheduledProcess.push_back(p);
                }else{
                    time++;
                }
                
            }
            return scheduledProcess;
        }
};


// Longest Remaining Time First
class LRTFSchedule{
    private:
        vector<Process> vectorOfProcess;
        
    public:
        /**
        * @param vectorOfProcess
        */
        LRTFSchedule(vector<Process> vectorOfProcess){
            this  -> vectorOfProcess = vectorOfProcess;
        }
        class Compare{
            public:
                /**
                * @param p1
                * @param p2
                * 
                * @return True if p1 is higher than p2 false otherwise
                */
                bool operator() (Process p1, Process p2){
                    return (p1.getBurstTime() == p2.getBurstTime()) ? p1.getArrivalTime() > p2.getArrivalTime() : p1.getBurstTime() < p2.getBurstTime();
                };
        };
        vector<Process> schedule(){
            vector<Process> scheduledProcess;
            priority_queue<Process, vector<Process>, Compare> runningQueue;
            map<int, int> preservedBT;

            int time = 0;
            while (!vectorOfProcess.empty() || !runningQueue.empty()){
                while (!vectorOfProcess.empty() && time >= vectorOfProcess[0].getArrivalTime()){
                    runningQueue.push(vectorOfProcess[0]);
                    preservedBT[vectorOfProcess[0].getProcessNo()] = vectorOfProcess[0].getBurstTime();
                    vectorOfProcess.erase(vectorOfProcess.begin());
                }
                if (!runningQueue.empty()){
                    Process p = runningQueue.top(); runningQueue.pop();

                    if (!p.getResponse()){
                        p.setResponseTime(time - p.getArrivalTime());
                        p.setResponse(true);
                    }

                    p.setBurstTime(p.getBurstTime() - 1);
                    time++;
                    if (p.getBurstTime() == 0){
                        p.setCompletionTime(time);
                        scheduledProcess.push_back(p);
                    }else{
                        runningQueue.push(p);
                    }
                    
                }else{
                    time++;
                }
                
            }
            for (int i = 0 ; i < scheduledProcess.size() ; i++){
                scheduledProcess[i].setBurstTime(preservedBT[scheduledProcess[i].getProcessNo()]);
            }
            return scheduledProcess;
        }
};

// Highest Response Time First Scheduler (Non-premptive)
class HRTFSchedule{
    private:
        vector<Process> vectorOfProcess;
        
    public:
        /**
        * @param vectorOfProcess
        */
        HRTFSchedule(vector<Process> vectorOfProcess){
            this -> vectorOfProcess = vectorOfProcess;
        }
        vector<Process> schedule(){
            vector<Process> scheduledProcess;
            int time = 0;
            auto compare = [&time](Process p1, Process p2){
                float hr1 = (float)((time - p1.getArrivalTime()) + p1.getBurstTime()) / (float)p1.getBurstTime();
                float hr2 = (float)((time - p2.getArrivalTime()) + p2.getBurstTime()) / (float)p2.getBurstTime();
                return (hr1 == hr2) ? p1.getArrivalTime() > p2.getArrivalTime() : hr1 < hr2;
            };

            priority_queue<Process, vector<Process>, decltype(compare)> runningQueue(compare);
            

            while (!vectorOfProcess.empty() || !runningQueue.empty()){
                while (!vectorOfProcess.empty() && time >= vectorOfProcess[0].getArrivalTime()){
                    runningQueue.push(vectorOfProcess[0]);
                    vectorOfProcess.erase(vectorOfProcess.begin());
                }
                if (!runningQueue.empty()){
                    Process p = runningQueue.top(); runningQueue.pop();
                    p.setResponseTime(time - p.getArrivalTime());
                    time += p.getBurstTime();
                    p.setCompletionTime(time);
                    scheduledProcess.push_back(p);
                    if (runningQueue.size() > 1){
                        Process temp = runningQueue.top(); runningQueue.pop();
                        runningQueue.push(temp);
                    }
                }else{
                    time++;
                }
                
            }
            return scheduledProcess;
        }
};

/**
* Displays the information of a process. This function is called from the command line to display the information of a process.
* 
* @param name - The name of the process. This is used to display the process name when the user presses Enter.
* @param scheduledProcess - A vector containing the number of processes in the schedule
*/
void display(string name, vector<Process> scheduledProcess){
    sort(scheduledProcess.begin(), scheduledProcess.end(), [](Process p1, Process p2){
        return p1.getProcessNo() < p2.getProcessNo();
    });
    int numProcess = scheduledProcess.size();
    float avgResponseTime, avgCompletionTime, avgTAT, avgWT;

    cout << "=================================================================================================================" << endl;
    cout << "|"<< setw(111) << name << "|" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|" << setw(15) << "Process No" << "|" << setw(15) << "Arrival Time" << "|"  << setw(15) << "Burst Time" << "|"  << setw(15) << "Response Time" << "|"  << setw(15) << "Completion Time" << "|" << setw(15) << "TAT" << "|" << setw(15) << "WT" << "|" << endl;
    cout << "----------------+---------------+---------------+---------------+---------------+---------------+---------------+" << endl;
    for (Process p : scheduledProcess){
        cout <<  "|" << setw(15) << p.getProcessNo() << "|" << setw(15) << p.getArrivalTime() << "|" << setw(15) << p.getBurstTime() << "|" << setw(15) << p.getResponseTime() << "|" << setw(15) << p.getCompletionTime() << "|" << setw(15) << p.getCompletionTime() - p.getArrivalTime() << "|" << setw(15) << (p.getCompletionTime() - p.getArrivalTime()) - p.getBurstTime() << "|" << endl;
        avgResponseTime += p.getResponseTime();
        avgCompletionTime += p.getCompletionTime();
        avgTAT += (p.getCompletionTime() - p.getArrivalTime());
        avgWT += ((p.getCompletionTime() - p.getArrivalTime()) - p.getBurstTime());
    }

    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;

    cout << "Average Response Time : " << setprecision(3) << avgResponseTime/numProcess << endl;
    cout << "Average Completion Time : " << setprecision(3) << avgCompletionTime/numProcess << endl;
    cout << "Average Tunr Around Time (TAT) Time : " << setprecision(3) << avgTAT/numProcess << endl;
    cout << "Average Waiting Time (WT) Time : " << setprecision(3) << avgWT/numProcess << endl << endl << endl;
}

/**
* Main function for the program. Reads input from file and calls p () for each process.
* 
* 
* @return The number of processes in the simulation or - 1 if
*/
int main(){

    int numberOfProcess;
    int tq;
    int choice;
    vector<Process> vectorOfProcess;
    bool flag = false;
    int at, bt;

    cout << "For taking input from file enter 1 or manual input enter 2" << endl;
    cin >> choice;

    // Enter the choice 1 or 2.
    if (choice == 1){
        fstream file;
        file.open("input.txt");
        file >> tq;
        file >> numberOfProcess;
        // This method is used to push the vector of processes to the vector of processes.
        for (int i = 0 ; i < numberOfProcess ; i++){
            file >> at >> bt;
            Process p(i+1, at, bt);
            vectorOfProcess.push_back(p);
        }
        flag = true;
    // Enter the choice 2 or 3
    }else if(choice == 2){
        cout << "Enter time quantum for Round Robin Scheduler : ";
        cin >> tq;
        cout << "Enter the number of Process : ";
        cin >> numberOfProcess;
        cout << "Enter Arrival Time and Burst Time of process with space seperated : " << endl;
        // This method is used to push the vector of processes to the vector of processes.
        for (int i = 0 ; i < numberOfProcess ; i++){
            cin >> at >> bt;
            Process p(i+1, at, bt);
            vectorOfProcess.push_back(p);
        }
        flag = true;
    }else{
        cout << "Enter valid input" << endl;
    }
    cout << endl;

    // sort the list of processes and return true if the flag is set
    if (flag){
        sort(vectorOfProcess.begin(), vectorOfProcess.end(), [](Process p1, Process p2){
            return p1.getArrivalTime() < p2.getArrivalTime();
        });

        FCFSSchesduler fcfs(vectorOfProcess);
        display("First Come First Serve", fcfs.schedule());

        SJFScheduler sjf(vectorOfProcess);
        display("Shortest Job First", sjf.schedule());

        SRTFSchedule srtf(vectorOfProcess);
        display("Shortest Reamining Time First", srtf.schedule());

        RRSchedule rr(vectorOfProcess, tq);
        display("Round Robin with TQ = " + to_string(tq), rr.schedule());

        LJFScheduler ljf(vectorOfProcess);
        display("Longest Job First", ljf.schedule());

        LRTFSchedule lrtf(vectorOfProcess);
        display("Longest Remaining Time First", lrtf.schedule());

        HRTFSchedule hrtf(vectorOfProcess);
        display("Highest Response Time First (Non-Preemptive)", hrtf.schedule());
    }else{
        cout << "Something error with input try again" << endl;
    }

    return 0;
}