/**
 * Author: James Talbott
 * Date: 03-15-2021
 * Version: 1.0
 */
#include "CPUSchedulerInputInterpreter.h"
#include <sstream>
using namespace std;

CPUSchedulerInputInterpreter::CPUSchedulerInputInterpreter() {}

ProcessHeap CPUSchedulerInputInterpreter::getProcessInput(vector<string> input, processCompare compare) {
    ProcessHeap processes(compare);
    int size = input.size();
    for (int i = 0; i < size; i++) {
        processes.push(convertLineOfInputToProcess(input.at(i)));
    }
    return processes;
}

Process* CPUSchedulerInputInterpreter::convertLineOfInputToProcess(string line) {
    stringstream stream;
    char* args = new char[maxCharactersPerAttribute];
    stream.str(line);

    stream.getline(args, maxCharactersPerAttribute, ' ');
    int processID = stoi(string(args));

    stream.getline(args, maxCharactersPerAttribute, ' ');
    int arrivalTime = stoi(string(args));

    stream.getline(args, maxCharactersPerAttribute, ' ');
    int burstDuration = stoi(string(args));

    stream.getline(args, maxCharactersPerAttribute, '\n');
    int priority = stoi(string(args));

    stream.clear();
    delete args;
    return new Process(processID, arrivalTime, burstDuration, priority);
}