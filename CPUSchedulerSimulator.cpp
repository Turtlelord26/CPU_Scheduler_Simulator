/**
 * Author: James Talbott
 * Date: 03-15-2021
 * Version: 1.0
 */
#include "CPUSchedulerSimulator.h"
using namespace std;

CPUSchedulerSimulator::CPUSchedulerSimulator(ProcessHeap& processes, processCompare readyCompare) : 
    CPUSchedulerSimulator(processes, readyCompare, nullptr) {}

CPUSchedulerSimulator::CPUSchedulerSimulator(ProcessHeap& processes, processCompare readyCompare, processCompare interruptCompare) : 
    processes(processes), 
    ready(ProcessHeap(readyCompare)), 
    finished(new vector<Process*>()), 
    activeProcess(nullptr), 
    clock(0),
    interruptCompare(interruptCompare) {}

vector<Process*>* CPUSchedulerSimulator::simulate() {
    clock = 0;
    initializeActiveProcess();
    while (processesRemainUnfinished()) {

        checkForAndAcceptArrivingProcesses();

        ifTerminatingReassignActiveProcess();

        if (isActiveProcessInterruptable()) {interrupt();}

        if (activeProcess != nullptr) {activeProcess->burstDuration--;}//Execute one clock cycle of progress on the active process

        clock++;
    }
    return finished;
}

void CPUSchedulerSimulator::initializeActiveProcess() {
    checkForAndAcceptArrivingProcesses();
    assignNextActiveProcess();
}

bool CPUSchedulerSimulator::processesRemainUnfinished() {
    return processes.notEmpty() || ready.notEmpty() || (activeProcess != nullptr && activeProcess->burstDuration >= 0);
}

void CPUSchedulerSimulator::checkForAndAcceptArrivingProcesses() {
    while (checkForArrivingProcess()) {takeInArrivingProcess();}
}

bool CPUSchedulerSimulator::checkForArrivingProcess() {
    return processes.notEmpty() && processes.top()->arrivalTime <= clock;
}

void CPUSchedulerSimulator::takeInArrivingProcess() {
    ready.push(processes.top());
    processes.pop();
}

void CPUSchedulerSimulator::ifTerminatingReassignActiveProcess() {
    if (activeProcess != nullptr && activeProcess->burstDuration <= 0) {
        sendActiveProcessToFinished();
        assignNextActiveProcess();
    }
}

void CPUSchedulerSimulator::sendActiveProcessToFinished() {
    addExecutionEndTime();
    finished->push_back(activeProcess);
}

void CPUSchedulerSimulator::assignNextActiveProcess() {
    getNextReadyProcessOrIfNoneIdle();
    if (activeProcess != nullptr) {addExecutionStartTime();}
}

void CPUSchedulerSimulator::getNextReadyProcessOrIfNoneIdle() {
    if (ready.notEmpty()) {getNextReadyProcess();}
    else if (processes.notEmpty()) {makeIdleProcess();}
    else activeProcess = nullptr;
}

void CPUSchedulerSimulator::getNextReadyProcess() {
    Process* p = ready.top();
    ready.pop();
    activeProcess = p;
}

void CPUSchedulerSimulator::makeIdleProcess() {
    int interimTime = processes.top()->arrivalTime - clock;
    activeProcess = new Process(-1, clock, interimTime, 0);
}

void CPUSchedulerSimulator::addExecutionEndTime() {
    activeProcess->endExecutionTimes.push_back(clock);
}

void CPUSchedulerSimulator::addExecutionStartTime() {
    activeProcess->beginExecutionTimes.push_back(clock);
}

bool CPUSchedulerSimulator::isActiveProcessInterruptable() {
    return interruptCompare != nullptr && activeProcess != nullptr && ready.notEmpty() && interruptCompare(activeProcess, ready.top());
}

void CPUSchedulerSimulator::interrupt() {
    //Set aside interrupted process
    Process* interrupted = activeProcess;
    addExecutionEndTime();
    //get next process from ready
    activeProcess = ready.top();
    addExecutionStartTime();
    //Put interrupted process back into ready
    ready.replace(interrupted);
}