/**
 * Author: James Talbott
 * Date: 03-15-2021
 * Version: 1.0
 */
#ifndef __CPUSCHEDULEROUTPUTPROCESSOR_H__
#define __CPUSCHEDULEROUTPUTPROCESSOR_H__

#include "../structs/Process.h"
#include "../structs/SimOutput.h"
#include <vector>

class CPUSchedulerOutputProcessor {
    public:
        /**
         * Default constructor deleted, setup occurs in parametrized constructor.
         */
        CPUSchedulerOutputProcessor() = delete;

        /**
         * Parametrized constructor evaluates and stores simulation data
         * Param: vector<Process*> - the post-simulation Processes
         */
        CPUSchedulerOutputProcessor(std::vector<Process*>&);

        /**
         * Prints simulation results to cout
         */
        void printOutput();
    
    private:
        std::vector<SimOutput> executions;//Stores all timestamps of processes becoming active
        double percentUtilization;
        double averageWaiting;
        int worstWaiting;
        int calculateTotalExecutionTime(Process*);
        int calculateProcessWaitingTime(Process*);
        void sortExecutions();
};

#endif // __CPUSCHEDULEROUTPUTPROCESSOR_H__