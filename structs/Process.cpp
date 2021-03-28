/**
 * Author: James Talbott
 * Date: 03-15-2021
 * Version: 1.0
 */
#include "Process.h"
using namespace std;

Process::Process(int processID, int arrivalTime, int burstDuration, int priority) : 
    processID(processID),
    arrivalTime(arrivalTime),
    burstDuration(burstDuration),
    priority(priority),
    beginExecutionTimes(vector<int>()),
    endExecutionTimes(vector<int>()) {}
    
Process::Process(const Process& base) : 
    processID(base.processID),
    arrivalTime(base.arrivalTime),
    burstDuration(base.burstDuration),
    priority(base.priority),
    beginExecutionTimes(vector<int>()),
    endExecutionTimes(vector<int>()) {}

Process& Process::operator =(const Process& right) {
    this->processID = right.processID;
    this->arrivalTime = right.arrivalTime;
    this->burstDuration = right.burstDuration;
    this->priority = right.priority;
    this->beginExecutionTimes = right.beginExecutionTimes;
    this->endExecutionTimes = right.endExecutionTimes;
    return *this;
}