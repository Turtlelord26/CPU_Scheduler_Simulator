/**
 * Author: James Talbott
 * Date: 03-15-2021
 * Version: 1.0
 */
#ifndef __ALGORITHMICPROCESSCOMPARATOR_H
#define __ALGORITHMICPROCESSCOMPARATOR_H

#include "../structs/Process.h"
#include "../types/processCompare.h"

class AlgorithmicProcessComparator {

    public:
        AlgorithmicProcessComparator();
        virtual ~AlgorithmicProcessComparator();

        /**
         * Retrieves a function pointer to a Process comparator. Must be overridden by subclasses
         * Return: a Process comparison function.
         */
        virtual processCompare getAlgorithm() = 0;
};

#endif //__ALGORITHMICPROCESSCOMPARATOR_H