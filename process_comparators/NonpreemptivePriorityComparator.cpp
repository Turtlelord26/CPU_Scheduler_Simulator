/**
 * Author: James Talbott
 * Date: 03-15-2021
 * Version: 1.0
 */
#include "NonpreemptivePriorityComparator.h"

NonpreemptivePriorityComparator::NonpreemptivePriorityComparator() : AlgorithmicProcessComparator() {}

processCompare NonpreemptivePriorityComparator::getAlgorithm() {return compare;}

bool NonpreemptivePriorityComparator::compare(const Process* p1, const Process* p2) {
    if (p1->priority == p2->priority) {
        return p1->processID > p2->processID;
    }
    return p1->priority > p2->priority;
}