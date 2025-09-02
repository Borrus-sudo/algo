#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

struct PCB
{
    int pid;
    int et;
    int at = 0;
    int priority = 0;
    PCB(int pid, int et) : pid(pid), et(et) {}
    PCB(int pid, int et, int priority) : pid(pid), et(et), priority(priority) {}
};

struct Record
{
    string pid;
    string ct;
    string tat;
    string wt;
    string et;
    Record(string pid, string ct, string wt, string tat, string et) : pid(pid), ct(ct), tat(tat), wt(wt), et(et) {}
};

string padTo(std::string str, const size_t num, const char paddingChar = ' ')
{
    if (num > str.size())
        str.insert(0, num - str.size(), paddingChar);
    return str;
}

class FCFS
{
    queue<PCB *> processes;
    vector<Record> records;
    float avgWaitingTime = 0;
    float avgCompletionTime = 0;
    float avgTurnaroundTime = 0;

public:
    void input()
    {
        int no;
        cout << "Enter number of processes: ";
        cin >> no;
        for (int pid = 1; pid <= no; pid++)
        {
            int et;
            cout << "Enter execution time: ";
            cin >> et;
            processes.push(new PCB(pid, et));
        }
    };
    void schedule()
    {
        // fcfs strategy
        int time = 0;
        int n = processes.size();
        while (!processes.empty())
        {
            auto process = processes.front();
            time += process->et;
            int ct = time;
            int tat = ct - 0;
            int wt = tat - process->et;

            records.push_back(Record(to_string(process->pid), to_string(ct), to_string(wt), to_string(tat), to_string(process->et)));

            avgTurnaroundTime += tat;
            avgCompletionTime += ct;
            avgWaitingTime += (wt);
            processes.pop();
        }
        avgWaitingTime /= n;
        avgTurnaroundTime /= n;
        avgCompletionTime /= n;
    }
    void print()
    {
        int len = 17;
        string header = "";

        header += padTo("Process", len);
        header += padTo("Completion", len);
        header += padTo("Turnaround", len);
        header += padTo("Waiting", len);
        header += padTo("Burst", len);

        cout << header << endl;

        for (auto record : records)
        {
            string line = "";
            line += padTo(record.pid, len);
            line += padTo(record.ct, len);
            line += padTo(record.tat, len);
            line += padTo(record.wt, len);
            // line += padTo(record.ct, len);
            line += padTo(record.et, len);
            cout << line << endl;
        }

        cout << "Average Waiting Time: " << avgWaitingTime << "ms" << endl;
        cout << "Average Turnaround Time: " << avgTurnaroundTime << "ms" << endl;
        cout << "Average Completion Time: " << avgCompletionTime << "ms" << endl;
    }
};

class RR
{
    queue<PCB *> processes;
    vector<Record> records;
    float avgWaitingTime = 0;
    float avgCompletionTime = 0;
    float avgTurnaroundTime = 0;
    int quant = 2;

public:
    void input()
    {
        int no;
        cout << "Enter number of processes: ";
        cin >> no;
        for (int pid = 1; pid <= no; pid++)
        {
            int et;
            cout << "Enter execution time: ";
            cin >> et;
            processes.push(new PCB(pid, et));
        }
        cout << "Enter time quanta ";
        cin >> quant;
    };
    void schedule()
    {
        // fcfs strategy
        int time = 0;
        int n = processes.size();
        unordered_map<int, int> execTimeTable;
        while (!processes.empty())
        {
            auto process = processes.front();
            int timeLeft = process->et - quant;

            if (timeLeft > 0)
            {
                time += quant;
                execTimeTable[process->pid] += quant;
                process->et = timeLeft;
                processes.pop();
                processes.push(process);
            }
            else
            {
                time += process->et;
                execTimeTable[process->pid] += process->et;

                int ct = time;
                int tat = ct - 0;
                int wt = tat - execTimeTable[process->pid];

                // records.emplace_back(to_string(process->pid), to_string(ct), to_string(wt), to_string(tat), to_string(execTimeTable[process->pid]));
                records.push_back(Record(to_string(process->pid), to_string(ct), to_string(wt), to_string(tat), to_string(execTimeTable[process->pid])));

                avgTurnaroundTime += (tat);
                avgCompletionTime += (ct);
                avgWaitingTime += (wt);

                processes.pop();
            }
        }
        avgWaitingTime /= n;
        avgTurnaroundTime /= n;
        avgCompletionTime /= n;
    }
    void print()
    {
        int len = 17;
        string header = "";

        header += padTo("Process", len);
        header += padTo("Completion", len);
        header += padTo("Turnaround", len);
        header += padTo("Waiting", len);
        header += padTo("Burst", len);

        cout << header << endl;

        for (auto record : records)
        {
            string line = "";
            line += padTo(record.pid, len);
            line += padTo(record.ct, len);
            line += padTo(record.tat, len);
            line += padTo(record.wt, len);
            // line += padTo(record.ct, len);
            line += padTo(record.et, len);
            cout << line << endl;
        }
        cout << "Average Waiting Time: " << avgWaitingTime << "ms" << endl;
        cout << "Average Turnaround Time: " << avgTurnaroundTime << "ms" << endl;
        cout << "Average Completion Time: " << avgCompletionTime << "ms" << endl;
    }
};

class SJF
{
    vector<PCB *> processes;
    vector<Record> records;
    float avgWaitingTime = 0;
    float avgCompletionTime = 0;
    float avgTurnaroundTime = 0;

public:
    void input()
    {
        int no;
        cout << "Enter number of processes: ";
        cin >> no;
        for (int pid = 1; pid <= no; pid++)
        {
            int et;
            cout << "Enter execution time: ";
            cin >> et;
            processes.push_back(new PCB(pid, et));
        }
    };
    void schedule()
    {
        // fcfs strategy
        sort(processes.begin(), processes.end(), [](auto a, auto b)
             { return a->et < b->et; });
        int time = 0;
        int n = processes.size();
        for (auto process : processes)
        {

            time += process->et;
            int ct = time;
            int tat = ct - process->at;
            int wt = tat - process->et;
            records.push_back(Record(to_string(process->pid), to_string(ct), to_string(wt), to_string(tat), to_string(process->et)));

            avgTurnaroundTime += tat;
            avgCompletionTime += ct;
            avgWaitingTime += (wt);
        }
        avgWaitingTime /= n;
        avgTurnaroundTime /= n;
        avgCompletionTime /= n;
    }
    void print()
    {
        int len = 17;
        string header = "";

        header += padTo("Process", len);
        header += padTo("Completion", len);
        header += padTo("Turnaround", len);
        header += padTo("Waiting", len);
        header += padTo("Burst", len);

        cout << header << endl;

        for (auto record : records)
        {
            string line = "";
            line += padTo(record.pid, len);
            line += padTo(record.ct, len);
            line += padTo(record.tat, len);
            line += padTo(record.wt, len);
            // line += padTo(record.ct, len);
            line += padTo(record.et, len);
            cout << line << endl;
        }
        cout << "Average Waiting Time: " << avgWaitingTime << "ms" << endl;
        cout << "Average Turnaround Time: " << avgTurnaroundTime << "ms" << endl;
        cout << "Average Completion Time: " << avgCompletionTime << "ms" << endl;
    }
};

class PriorityScheduling
{
    vector<PCB *> processes;
    vector<Record> records;
    float avgWaitingTime = 0;
    float avgCompletionTime = 0;
    float avgTurnaroundTime = 0;

public:
    void input()
    {
        int no;
        cout << "Enter number of processes: ";
        cin >> no;
        for (int pid = 1; pid <= no; pid++)
        {
            int et, priority;
            cout << "Enter execution time: ";
            cin >> et;
            cout << "Priority: ";
            cin >> priority;
            processes.push_back(new PCB(pid, et, priority));
        }
    };
    void schedule()
    {
        // fcfs strategy
        sort(processes.begin(), processes.end(), [](auto a, auto b)
             { return a->priority < b->priority; });
        int time = 0;
        int n = processes.size();
        for (auto process : processes)
        {

            time += process->et;
            int ct = time;
            int tat = ct - process->at;
            int wt = tat - process->et;
            records.push_back(Record(to_string(process->pid), to_string(ct), to_string(wt), to_string(tat), to_string(process->et)));

            avgTurnaroundTime += tat;
            avgCompletionTime += ct;
            avgWaitingTime += (wt);
        }
        avgWaitingTime /= n;
        avgTurnaroundTime /= n;
        avgCompletionTime /= n;
    }
    void print()
    {
        int len = 17;
        string header = "";

        header += padTo("Process", len);
        header += padTo("Completion", len);
        header += padTo("Turnaround", len);
        header += padTo("Waiting", len);
        header += padTo("Burst", len);

        cout << header << endl;

        for (auto record : records)
        {
            string line = "";

            line += padTo(record.pid, len);
            line += padTo(record.ct, len);
            line += padTo(record.tat, len);
            line += padTo(record.wt, len);
            line += padTo(record.et, len);

            cout << line << endl;
        }
        cout << "Average Waiting Time: " << avgWaitingTime << "ms" << endl;
        cout << "Average Turnaround Time: " << avgTurnaroundTime << "ms" << endl;
        cout << "Average Completion Time: " << avgCompletionTime << "ms" << endl;
    }
};

int main()
{
    while (true)
    {
        cout << "Jinmay Jhaveri 241080027" << endl;
        cout << "Enter Scheduling Algorithm: " << endl;
        cout << "1. First Come First Serve" << endl;
        cout << "2. Shortest Job First" << endl;
        cout << "3. Round Robin" << endl;
        cout << "4. Priority Scheduling" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter option number (1/2/3/4/5) ";
        char opt;
        cin >> opt;
        if (opt == '1')
        {
            FCFS scheduler;
            scheduler.input();
            scheduler.schedule();
            scheduler.print();
        }
        else if (opt == '2')
        {
            SJF scheduler;
            scheduler.input();
            scheduler.schedule();
            scheduler.print();
        }
        else if (opt == '3')
        {
            RR scheduler;
            scheduler.input();
            scheduler.schedule();
            scheduler.print();
        }
        else if (opt == '4')
        {
            PriorityScheduling scheduler;
            scheduler.input();
            scheduler.schedule();
            scheduler.print();
        }
        else if (opt == '5')
        {
            return 0;
        }
        else
            continue;
    }
    return 0;
}