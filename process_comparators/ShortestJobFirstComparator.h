/**
 * Author: James Talbott
 * Date: 03-15-2021
 * Version: 1.0
 */
#ifndef SHORTESTJOBFIRSTCOMPARATOR_H
#define SHORTESTJOBFIRSTCOMPARATOR_H

#include "AlgorithmicProcessComparator.h"

class ShortestJobFirstComparator : public AlgorithmicProcessComparator {

    public:
        ShortestJobFirstComparator();

        /**
         * Provides a Process comparison function that operates on remaining burst time.
         * Return: a pointer to compare
         */
        virtual processCompare getAlgorithm() override;
    
    private:
        static bool compare(const Process*, const Process*);
};

#endif