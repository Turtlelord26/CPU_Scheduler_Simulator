/**
 * Author: James Talbott
 * Date: 03-15-2021
 * Version: 1.0
 */
#ifndef __NONPREEMPTIVEPRIORITYCOMPARATOR_H
#define __NONPREEMPTIVEPRIORITYCOMPARATOR_H

#include "AlgorithmicProcessComparator.h"

class NonpreemptivePriorityComparator : public AlgorithmicProcessComparator {

    public:
        NonpreemptivePriorityComparator();

        /**
         * Provides a Process comparison function that operates on priority.
         * Return: a pointer to compare
         */
        virtual processCompare getAlgorithm() override;
    
    private:
        static bool compare(const Process*, const Process*);
};

#endif //__NONPREEMPTIVEPRIORITYCOMPARATOR_H