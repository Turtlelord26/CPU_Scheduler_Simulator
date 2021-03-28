/**
 * Author: James Talbott
 * Date: 03-15-2021
 * Version: 1.0
 */
#ifndef PROCESS_H
#define PROCESS_H

#include <vector>

struct Process {

    public:
        int processID; //Unique process identifier. Strictly positive for all processes, -1 for Idle (created during simulation for statistics)
        int arrivalTime; //Strictly nonnegative, Clock cycle in which the process is discovered by the CPU
        int burstDuration; //Strictly positive, Number of clock cycles necessary to execute the process
        int priority; //Strictly nonnegative, lower number is a more important process
        std::vector<int> beginExecutionTimes; //Members strictly nonnegative, Set during simulation for statistics
        std::vector<int> endExecutionTimes; //Members strictly positive, Set during simulation for statistics
        Process(int, int, int, int);
        Process(const Process&);
        Process& operator =(const Process&);
};

#endif