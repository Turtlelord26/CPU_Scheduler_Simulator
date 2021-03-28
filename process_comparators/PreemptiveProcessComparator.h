#ifndef __PREEMPTIVEPROCESSCOMPARATOR_H__
#define __PREEMPTIVEPROCESSCOMPARATOR_H__

#include "AlgorithmicProcessComparator.h"
#include "../types/processCompare.h"

class PreemptiveProcessComparator : public AlgorithmicProcessComparator {

    public:
        PreemptiveProcessComparator();
        virtual ~PreemptiveProcessComparator();
        virtual processCompare getAlgorithm() = 0;
        virtual processCompare getInterruptAlgorithm() = 0;
};

#endif // __PREEMPTIVEPROCESSCOMPARATOR_H__