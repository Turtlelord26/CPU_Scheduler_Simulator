/**
 * Author: James Talbott
 * Date: 03-15-2021
 * Version: 1.0
 */
#ifndef __SIMOUTPUT_H__
#define __SIMOUTPUT_H__

struct SimOutput {

    public:
        int processID; //Process identifier. Strictly positive for all processes, -1 for Idle (created during simulation for statistics)
        int beginExecution; //Strictly nonnegative. Clock cycle the process begins or resumes executing
        SimOutput(const int, const int);
        SimOutput(const SimOutput&);
        SimOutput& operator =(const SimOutput&);
};

#endif // __SIMOUTPUT_H__