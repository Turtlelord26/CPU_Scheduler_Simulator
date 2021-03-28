/**
 * Author: James Talbott
 * Date: 03-15-2021
 * Version: 1.0
 */
#ifndef __BEGINEXECUTIONTIMECOMPARATOR_H
#define __BEGINEXECUTIONTIMECOMPARATOR_H

#include "../structs/SimOutput.h"
#include "../types/outputCompare.h"

class OutputComparator {

    public:
        OutputComparator();

        /**
         * Provides a SimOutput comparison function that operates on execution start time.
         * Return: a pointer to compare
         */
        outputCompare getAlgorithm();
    
    private:
        static bool compare(const SimOutput&, const SimOutput&);
};

#endif // __BEGINEXECUTIONTIMECOMPARATOR_H