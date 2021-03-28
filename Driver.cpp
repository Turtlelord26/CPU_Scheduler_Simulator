/**
 * Author: James Talbott
 * Date: 03-15-2021
 * Version: 1.0
 */
#include "CPUSchedulerSimulator.h"
#include "data/ProcessHeap.h"
#include "input/CPUSchedulerInputInterpreter.h"
#include "input/CPUSchedulerInputReader.h"
#include "output/CPUSchedulerOutputProcessor.h"
#include "process_comparators/ArrivalTimeComparator.h"
#include "process_comparators/NonpreemptivePriorityComparator.h"
#include "process_comparators/PreemptivePriorityComparator.h"
#include "process_comparators/ShortestJobFirstComparator.h"
#include "process_comparators/ShortestRemainingTimeComparator.h"
#include <iostream>
#include <string>
using namespace std;

const string wrongNumberArgsError = "Error: Exactly two command line arguments are required. The first is an input .txt file and the second is a scheduling algorithm.";
const string fileReadError  = "Error: Given input file does not exist or could not be accessed.";
const string unrecognizedSchedulingAlgorithmError = "Error: Unrecognized scheduling algorithm.\nRecognized commands are SJF, SRTF, NP, PP.";

/**
 * Simulates CPU Scheduling from command line arguments supplying a process file and algorithm name.
 * param: int - command line argument count - must be 3.
 * param: char** - command line argument list.
 * return: exit code.
 */
int main(int, char**);

/**
 * Selects comparison algorithms given the relevant command line input.
 * Param: string - Command line argument for agorithm selection.
 * Param: processCompare - (out parameter) the comparator with which to sort ready processes
 * Param: processCompare - (out parameter) the comparator with which to determine interruptability
 * Return: 0 if successful, an error code for main to return otherwise.
 */
int getCompares(string, processCompare&, processCompare&);

/**
 * Runs the scheduling simulator.
 * Param: ProcessHeap - the processes under simulation.
 * Param: processCompare - the comparator with which to sort ready processes
 * Param: processCompare - the comparator with which to determine interruptability
 * Return: List of simulated processes containgng simulation data.
 */
vector<Process*>* simulate(ProcessHeap&, processCompare, processCompare);

/**
 * Prints the results of the simulation to cout.
 * param: vector<Process*> - Post-simulation process data.
 */
void printOutput(vector<Process*>);

int main(int argc, char* argv[]) {
    //Verify number of command line arguments
    if (argc != 3) {
        cout << wrongNumberArgsError << endl;
        return 1;
    }

    //Read input file
    vector<string> input = CPUSchedulerInputReader().getInput(argv[1]);
    if (input.size() == 0) {
        cout << fileReadError << endl;
        return 2;
    }

    //Interpret input file into list of processes
    ProcessHeap processes = CPUSchedulerInputInterpreter().getProcessInput(input, ArrivalTimeComparator().getAlgorithm());

    //Select comparators according to input
    processCompare readyCompare, interruptCompare;
    int argCheck = getCompares(argv[2], readyCompare, interruptCompare);
    if (argCheck != 0) {return argCheck;}

    //Run simulation
    vector<Process*>* finishedProcesses = simulate(processes, readyCompare, interruptCompare);

    //Print output
    printOutput(*finishedProcesses);
    delete finishedProcesses;
    return 0;
}

int getCompares(string arg, processCompare& readyCompare, processCompare& interruptCompare) {
    if (arg == "SJF") {
        AlgorithmicProcessComparator* algorithm = new ShortestJobFirstComparator();
        readyCompare = algorithm->getAlgorithm();
        interruptCompare = nullptr;
    } else if (arg == "SRTF") {
        PreemptiveProcessComparator* algorithm = new ShortestRemainingTimeComparator();
        readyCompare = algorithm->getAlgorithm();
        interruptCompare = algorithm->getInterruptAlgorithm();
    } else if (arg == "NP") {
        AlgorithmicProcessComparator* algorithm = new NonpreemptivePriorityComparator();
        readyCompare = algorithm->getAlgorithm();
        interruptCompare = nullptr;
    } else if (arg == "PP") {
        PreemptiveProcessComparator* algorithm = new PreemptivePriorityComparator();
        readyCompare = algorithm->getAlgorithm();
        interruptCompare = algorithm->getInterruptAlgorithm();
    } else {
        cout << unrecognizedSchedulingAlgorithmError << endl;
        return 3;
    }
    return 0;
}

vector<Process*>* simulate(ProcessHeap& processes, processCompare readyCompare, processCompare interruptCompare) {
    return CPUSchedulerSimulator(processes, readyCompare, interruptCompare).simulate();
}

void printOutput(vector<Process*> output) {
    CPUSchedulerOutputProcessor(output).printOutput();
}