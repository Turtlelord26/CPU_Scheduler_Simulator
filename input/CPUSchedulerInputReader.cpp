/**
 * Author: James Talbott
 * Date: 03-15-2021
 * Version: 1.0
 */
#include "CPUSchedulerInputReader.h"
#include <fstream>

CPUSchedulerInputReader::CPUSchedulerInputReader() {}

vector<string> CPUSchedulerInputReader::getInput(char* filepath) {
    vector<string> lines;
    ifstream infile;
    infile.open(filepath);
    char readIn[32];
    string line;
    while(! infile.fail() && ! infile.eof()) {
        infile.getline(readIn, 32, '\n');
        line = readIn;
        if (! line.empty()) {lines.push_back(line);}
    }
    infile.close();
    return lines;
}