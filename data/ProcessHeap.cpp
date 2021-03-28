/**
 * Author: James Talbott
 * Date: 03-15-2021
 * Version: 1.0
 */
#include "ProcessHeap.h"
#include <algorithm>

#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

ProcessHeap::ProcessHeap(processCompare compare) {
    data = vector<Process*>();
    this->compare = compare;
}

ProcessHeap::ProcessHeap(const ProcessHeap& base) {
    this->data = vector<Process*>(base.data);
    this->compare = base.compare;
}

ProcessHeap::~ProcessHeap() {
    for (Process* p : data) {delete p;}
}

ProcessHeap& ProcessHeap::operator =(const ProcessHeap& right) {
    this->data = right.data;
    this->compare = right.compare;
    return *this;
}

void ProcessHeap::push(Process* p) {
    data.push_back(p);
    push_heap(data.begin(), data.end(), compare);
    if (! is_heap(data.begin(), data.end(), compare)) {cout << "NO LONGER A HEAP!!!!\n";}
}

Process* ProcessHeap::top() {
    return data.front();
}

void ProcessHeap::pop() {
    pop_heap(data.begin(), data.end(), compare);
    data.pop_back();
}

void ProcessHeap::replace(Process* p) {
    pop_heap(data.begin(), data.end(), compare);
    data.back() = p;
    push_heap(data.begin(), data.end(), compare);
}

int ProcessHeap::size() {
    return data.size();
}

bool ProcessHeap::empty() {
    return data.empty();
}

bool ProcessHeap::notEmpty() {
    return ! empty();
}