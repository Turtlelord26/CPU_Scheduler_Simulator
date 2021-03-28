/**
 * Author: James Talbott
 * Date: 03-15-2021
 * Version: 1.0
 */
#include "CPUSchedulerOutputProcessor.h"
#include "../process_comparators/OutputComparator.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

CPUSchedulerOutputProcessor::CPUSchedulerOutputProcessor(vector<Process*>& data) {
    worstWaiting = 0;
    int timeIdle = 0, totalTime = 0, totalTimeWaiting = 0, numProcesses = 0, size, time, timeWaited;
    executions = vector<SimOutput>();
    Process* p;
    while (data.size() > 0) {
        //loop variable iteration
        p = data.back();
        data.pop_back();

        //Record each time the process came off the ready queue and became active
        size = p->beginExecutionTimes.size();
        for (int i = 0; i < size; i++) {
            executions.push_back(SimOutput(p->processID, p->beginExecutionTimes.at(i)));
        }

        //Record time spent executing.
        time = calculateTotalExecutionTime(p);
        totalTime += time;

        //For Idles, add to time spent idling. For Processes, calculate waiting times.
        if (p->processID == -1) {timeIdle += time;}
        else {
            numProcesses++;
            timeWaited = calculateProcessWaitingTime(p);
            totalTimeWaiting += timeWaited;
            if (timeWaited > worstWaiting) {worstWaiting = timeWaited;}
        }
    }
    percentUtilization = 100. * ((double) totalTime - (double) timeIdle) / (double) totalTime;
    averageWaiting = (double) totalTimeWaiting / (double) numProcesses;
    sortExecutions();
}

void CPUSchedulerOutputProcessor::printOutput() {
    //The sort leaves executions in descending order, so we iterate backwards
    for (int i = executions.size() - 1; i >= 0; i--) {
        SimOutput s = executions.at(i);
        cout << "Time: " << s.beginExecution << " ";
        if (s.processID == -1) {cout << "Idle\n";}
        else {cout << "Process: " << s.processID << "\n";}
    }
    cout.setf(ios::fixed, ios::floatfield);
    cout << "CPU Utilization: " << setprecision(0) << percentUtilization << "%\n";
    cout << "Average waiting time: " << setprecision(2) << averageWaiting << endl;
    cout << "Worst-case waiting time: " << worstWaiting << endl;
}

int CPUSchedulerOutputProcessor::calculateTotalExecutionTime(Process* p) {
    int time = 0;
    int size = p->beginExecutionTimes.size();
    for (int i = 0; i < size; i++) {
        time += p->endExecutionTimes.at(i) - p->beginExecutionTimes.at(i);
    }
    return time;
}

int CPUSchedulerOutputProcessor::calculateProcessWaitingTime(Process* p) {
    int timeWaited = p->beginExecutionTimes.front() - p->arrivalTime;
    int size = p->beginExecutionTimes.size();
    for (int i = 1; i < size; i++) {
        timeWaited += p->beginExecutionTimes.at(i) - p->endExecutionTimes.at(i - 1);
    }
    return timeWaited;
}

void CPUSchedulerOutputProcessor::sortExecutions() {
    outputCompare compare = OutputComparator().getAlgorithm();
    make_heap(executions.begin(), executions.end(), compare);
    sort_heap(executions.begin(), executions.end(), compare);
}
