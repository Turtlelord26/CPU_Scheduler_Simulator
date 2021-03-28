/**
 * Author: James Talbott
 * Date: 03-15-2021
 * Version: 1.0
 */
#include "SimOutput.h"

SimOutput::SimOutput(const int processID, const int beginExecution) : processID(processID), beginExecution(beginExecution) {}

SimOutput::SimOutput(const SimOutput& base) : processID(base.processID), beginExecution(base.beginExecution) {}

SimOutput& SimOutput::operator =(const SimOutput& right) {
    this->processID = right.processID;
    this->beginExecution = right.beginExecution;
    return *this;
}