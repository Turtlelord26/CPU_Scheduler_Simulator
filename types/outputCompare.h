/**
 * Author: James Talbott
 * Date: 03-15-2021
 * Version: 1.0
 */
#ifndef __OUTPUTCOMPARE_H__
#define __OUTPUTCOMPARE_H__

#include "../structs/SimOutput.h"

/**
 * Function pointer used in heap sorting SimOutputs
 * Param: SimOutput - The two targets of the comparison
 * Return: bool - The result of the comparison
 */
typedef bool (*outputCompare)(const SimOutput&, const SimOutput&);

#endif // __OUTPUTCOMPARE_H__