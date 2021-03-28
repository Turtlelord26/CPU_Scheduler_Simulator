/**
 * Author: James Talbott
 * Date: 03-15-2021
 * Version: 1.0
 */
#ifndef __PREEMPTIVEPRIORITYCOMPARATOR_H
#define __PREEMPTIVEPRIORITYCOMPARATOR_H

#include "PreemptiveProcessComparator.h"

class PreemptivePriorityComparator : public PreemptiveProcessComparator {

    public:
        PreemptivePriorityComparator();

        /**
         * Provides a Process comparison function with tiebreaks that operates on priority.
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

#endif //__PREEMPTIVEPRIORITYCOMPARATOR_H