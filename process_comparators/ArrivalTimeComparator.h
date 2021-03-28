/**
 * Author: James Talbott
 * Date: 03-15-2021
 * Version: 1.0
 */
#ifndef __ARRIVALTIMECOMPARATOR_H
#define __ARRIVALTIMECOMPARATOR_H

#include "../structs/Process.h"
#include "../types/processCompare.h"

class ArrivalTimeComparator {

    public:
        ArrivalTimeComparator();

        /**
         * Provides a Process comparison function that operates on arrival time.
         * Return: a pointer to compare
         */
        processCompare getAlgorithm();

    private:
        static bool compare(const Process*, const Process*);
};

#endif //__ARRIVALTIMECOMPARATOR_H