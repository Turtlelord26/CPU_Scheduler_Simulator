/**
 * Author: James Talbott
 * Date: 03-15-2021
 * Version: 1.0
 */
#ifndef __PROCESSHEAP_H__
#define __PROCESSHEAP_H__

#include "../structs/Process.h"
#include "../types/processCompare.h"
#include <vector>

class ProcessHeap {

    public:
        ProcessHeap() = delete;//Require a function pointer to initialize a ProcessHeap
        ProcessHeap(processCompare);
        ProcessHeap(const ProcessHeap&);
        virtual ~ProcessHeap();
        ProcessHeap& operator =(const ProcessHeap&);

        /**
         * Pushes the argument onto the heap and resorts.
         * Param: Process - an element to insert into the heap.
         */
        void push(Process*);
        
        /**
         * Returns the top element of the heap. The heap remains unchanged.
         * Return: The top element of the heap.
         */
        Process* top();
        
        /**
         * Removes the top element of the heap and resorts.
         */
        void pop();
        
        /**
         * Removes the top element of the heap and replaces it with the input, then resorts.
         * Param: Process - an element to insert into the heap.
         */
        void replace(Process*);
        
        /**
         * Gets the number of elements in the underlying data structure.
         * Return: the number of elements in this heap.
         */
        int size();
        
        /**
         * Checks whether the underlying data structure is empty.
         * Return: True if empty, False otherwise.
         */
        bool empty();

        /**
         * Checks whether the underlying data structure is empty.
         * Return: True if not empty, False otherwise.
         */
        bool notEmpty();

    private:
        processCompare compare; //comparison function pointer
        std::vector<Process*> data;

};

#endif // __PROCESSHEAP_H__