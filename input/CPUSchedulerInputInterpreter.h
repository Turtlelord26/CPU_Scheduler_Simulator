/**
 * Author: James Talbott
 * Date: 03-15-2021
 * Version: 1.0
 */
#ifndef CPUSCHEDULERINPUTINTERPRETER_H
#define CPUSCHEDULERINPUTINTERPRETER_H

#include "../data/ProcessHeap.h"
#include "../types/processCompare.h"
#include <string>
#include <vector>
using namespace std;

class CPUSchedulerInputInterpreter {

    public:
        CPUSchedulerInputInterpreter();

        /**
         * Turns input strings into Processes, sorted according to a provided function.
         * Param: vector<string> - a collection of the input file lines, separated into individual strings.
         * Param: processCompare - a function pointer to a Process comparison function.
         * Return: A min heap of Processes.
         * Pre: Input lines must be well-formatted according to assignment specification.
         * Post: Returned heap will be empty if input vector was empty.
         */
        ProcessHeap getProcessInput(vector<string>, processCompare);

    private:
        const int maxCharactersPerAttribute = 4;
        Process* convertLineOfInputToProcess(string);
};

#endif