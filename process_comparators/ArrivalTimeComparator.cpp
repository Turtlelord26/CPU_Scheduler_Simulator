/**
 * Author: James Talbott
 * Date: 03-15-2021
 * Version: 1.0
 */
#include "ArrivalTimeComparator.h"

ArrivalTimeComparator::ArrivalTimeComparator() {}

processCompare ArrivalTimeComparator::getAlgorithm() {return compare;}

bool ArrivalTimeComparator::compare(const Process* p1, const Process* p2) {
    if (p1->arrivalTime == p2->arrivalTime) {
        return p1->processID > p2->processID;
    }
    return p1->arrivalTime > p2->arrivalTime;
}