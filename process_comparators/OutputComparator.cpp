/**
 * Author: James Talbott
 * Date: 03-15-2021
 * Version: 1.0
 */
#include "OutputComparator.h"

OutputComparator::OutputComparator() {}

outputCompare OutputComparator::getAlgorithm() {return compare;}

bool OutputComparator::compare(const SimOutput& p1, const SimOutput& p2) {
    return p1.beginExecution > p2.beginExecution;
}