/**
 * Author: James Talbott
 * Date: 03-15-2021
 * Version: 1.0
 */
#ifndef __PROCESSCOMPARE_H__
#define __PROCESSCOMPARE_H__

#include "../structs/Process.h"

/**
 * Function pointer used in heap sorting Processes
 * Param: Process - The two targets of the comparison
 * Return: bool - The result of the comparison
 */
typedef bool (*processCompare)(const Process*, const Process*);

#endif // __PROCESSCOMPARE_H__