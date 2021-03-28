/**
 * Author: James Talbott
 * Date: 03-15-2021
 * Version: 1.0
 */
#ifndef __CPUSCHEDULERSIMULATOR_H
#define __CPUSCHEDULERSIMULATOR_H

#include "data/ProcessHeap.h"
#include "types/processCompare.h"
#include <vector>
using namespace std;

class CPUSchedulerSimulator {

    public:
        CPUSchedulerSimulator() = delete;//Require all necessary data on initialization.

        /**
         * Parametrized constructor. Initializes a nonpreemptive simulator with interruptCompare = nullptr.
         * Param: ProcessHeap - the processes to simulate.
         * Param: readyCompare - the ready queue algorithm.
         */
        CPUSchedulerSimulator(ProcessHeap&, processCompare);

        /**
         * Parametrized constructor. Initializes a preemptive simulator.
         * Param: ProcessHeap - the processes to simulate.
         * Param: processCompare - the ready queue algorithm.
         * Param: processCompare - the interrupt check algorithm.
         */
        CPUSchedulerSimulator(ProcessHeap&, processCompare, processCompare);

        /**
         * Simulates a CPU Scheduler on a set of processes. Context switching is instant.
         * Param: ProcessHeap: the processes to simulate.
         * Param: processCompare: the sorting algorithm to use in the ready queue.
         */
        vector<Process*>* simulate();
    
    private:
        ProcessHeap processes;
        ProcessHeap ready;
        vector<Process*>* finished;
        Process* activeProcess;
        int clock;
        processCompare interruptCompare;
        void initializeActiveProcess();
        bool processesRemainUnfinished();
        void checkForAndAcceptArrivingProcesses();
        bool checkForArrivingProcess();
        void takeInArrivingProcess();
        void ifTerminatingReassignActiveProcess();//post: return will be nullptr iff the last process has completed
        void sendActiveProcessToFinished();//Pre: activeProcess is not nullptr
        void assignNextActiveProcess();
        void getNextReadyProcessOrIfNoneIdle();
        void getNextReadyProcess();
        void makeIdleProcess();//Pre: processes is not empty
        void addExecutionEndTime();//Records on the active process that it has ended a period of execution.
                                   //Pre: argument is not nullptr
        void addExecutionStartTime();//Records on the active process that it has begun a period of execution.
                                     //Pre: argument is not nullptr
        bool isActiveProcessInterruptable();
        void interrupt();//Interrupts a running process, putting it back into ready and retrieving the next process.
                         //Pre: activeProcess is not nullptr
};

#endif // __CPUSCHEDULERSIMULATOR_H