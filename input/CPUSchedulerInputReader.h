/**
 * Author: James Talbott
 * Date: 03-15-2021
 * Version: 1.0
 */
#ifndef CPUSCHEDULERINPUTREADER_H
#define CPUSCHEDULERINPUTREADER_H

#include <string>
#include <vector>
using namespace std;

class CPUSchedulerInputReader {

    public:
        CPUSchedulerInputReader();

        /**
         * Reads input from a filepath and stores it line by line in a vector.
         * Param: char* - filepath to input
         * Return: A vector of lines from the input file.
         * Post: If a file read error occurs, the output will be empty.
         */
        vector<string> getInput(char*);
};

#endif