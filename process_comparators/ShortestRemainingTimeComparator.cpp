/**
 * Author: James Talbott
 * Date: 03-15-2021
 * Version: 1.0
 */
#include "ShortestRemainingTimeComparator.h"

ShortestRemainingTimeComparator::ShortestRemainingTimeComparator() : PreemptiveProcessComparator() {}

processCompare ShortestRemainingTimeComparator::getAlgorithm() {return compare;}

processCompare ShortestRemainingTimeComparator::getInterruptAlgorithm() {return interruptCompare;}

bool ShortestRemainingTimeComparator::compare(const Process* p1, const Process* p2) {
    if (p1->burstDuration == p2->burstDuration) {
        return p1->processID > p2->processID;
    }
    return p1->burstDuration > p2->burstDuration;
}

bool ShortestRemainingTimeComparator::interruptCompare(const Process* p1, const Process* p2) {
    return p1->burstDuration > p2->burstDuration;
}