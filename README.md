A CPU Process Scheduling Simulator.

The simulator runs on the command line and compiles with g++ 10.2.0. Compile command below:
`g++ Driver.cpp CPUSchedulerSimulator.cpp structs/Process.cpp structs/SimOutput.cpp data/ProcessHeap.cpp input/CPUSchedulerInputReader.cpp input/CPUSchedulerInputInterpreter.cpp output/CPUSchedulerOutputProcessor.cpp process_comparators/ArrivalTimeComparator.cpp process_comparators/AlgorithmicProcessComparator.cpp process_comparators/PreemptiveProcessComparator.cpp process_comparators/OutputComparator.cpp process_comparators/NonpreemptivePriorityComparator.cpp process_comparators/PreemptivePriorityComparator.cpp process_comparators/ShortestJobFirstComparator.cpp process_comparators/ShortestRemainingTimeComparator.cpp -o simulator -std=c++11`

To use, run the .exe with two arguments. The first is a plaintext file with process-defining input. The second is a string that determines the sorting algorithm the scheduler uses.
Recognized algorithms are:
- SJF: Shortest Job First
- SRTF: Shortest Remaining Time First
- NP: Non-preemptive Priority
- PP: Preemptive Priority
Ex: simulator.exe input.txt SRTF

The input file is expected to consist of 4 integers per line, separated by a single space. In order, these should be the process ID, arrival time, CPU Burst Duration, and Priority.
This simulator does not at this time validate the input file's contents, and its behavior with malformatted input is not defined.

On completion, the simulator will print statistics to the console. In order:
- A time-sorted list of which processes begin an execution period at what time, including idle periods.
- The utilization time of the CPU, as a percentage
- The average waiting time of the input processes
- The worst waiting time of the input processes