/**
 * Author: James Talbott
 * Date: 03-15-2021
 * Version: 1.0
 */
#include "ShortestJobFirstComparator.h"

ShortestJobFirstComparator::ShortestJobFirstComparator() : AlgorithmicProcessComparator() {}

processCompare ShortestJobFirstComparator::getAlgorithm() {return compare;}

bool ShortestJobFirstComparator::compare(const Process* p1, const Process* p2) {
    if (p1->burstDuration == p2->burstDuration) {
        return p1->processID > p2->processID;
    }
    return p1->burstDuration > p2->burstDuration;
}