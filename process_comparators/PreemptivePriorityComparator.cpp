/**
 * Author: James Talbott
 * Date: 03-15-2021
 * Version: 1.0
 */
#include "PreemptivePriorityComparator.h"

PreemptivePriorityComparator::PreemptivePriorityComparator() : PreemptiveProcessComparator() {}

processCompare PreemptivePriorityComparator::getAlgorithm() {return compare;}

processCompare PreemptivePriorityComparator::getInterruptAlgorithm() {return interruptCompare;}

bool PreemptivePriorityComparator::compare(const Process* p1, const Process* p2) {
    if (p1->priority == p2->priority) {
        return p1->processID > p2->processID;
    }
    return p1->priority > p2->priority;
}

bool PreemptivePriorityComparator::interruptCompare(const Process* p1, const Process* p2) {
    return p1->priority > p2->priority;
}