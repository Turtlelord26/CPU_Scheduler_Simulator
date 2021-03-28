/**
 * Author: James Talbott
 * Date: 03-15-2021
 * Version: 1.0
 */
#ifndef SHORTESTREMAININGTIMESCHEDULER_H
#define SHORTESTREMAININGTIMESCHEDULER_H

#include "PreemptiveProcessComparator.h"

class ShortestRemainingTimeComparator : public PreemptiveProcessComparator {

    public:
        ShortestRemainingTimeComparator();

        /**
         * Provides a Process comparison function that operates on remaining burst time.
         * Return: a pointer to compare
         */
        virtual processCompare getAlgorithm() override;

        /**
         * Provides a Process comparison function without tiebreaks that operates on priority.
         * Return: a pointer to interruptCompare
         */
        virtual processCompare getInterruptAlgorithm() override;
    
    private:
        static bool compare(const Process*, const Process*);
        static bool interruptCompare(const Process*, const Process*);
};

#endif