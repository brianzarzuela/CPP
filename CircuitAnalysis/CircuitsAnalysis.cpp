/**
 * Title  : CircuitsAnalysis.cpp
 * Course : Computational Problem Solving II (CPET-321)
 * Author : Brian Zarzuela
 * Date   : Fall 2019 (2191)
 * Description: Program to calculate the branch currents for a three loop
 * 				mesh circuit given the circuit's Resistors and Voltage source
 * 				values. This program utilizes the Gauss-Elimination method.
 *
 * Notes :
 * 	- version 2 completed 28 Aug 2019
 * 	- version 3 completed 28 Aug 2019
 * 	- version 4 completed 29 Aug 2019
 * 	- version 5 completed 30 Aug 2019
 *
 * Last Modified : 30 Aug 2019 at 12:55am
 */

#include "CircuitsAnalysis.h"

int main()
{
	float coef[SIZE][SIZE+1];	// declare an array to store the coefficients
								// note : format is [ROW][COLUMN]

	float ans[SIZE];			// declare an array to store answers

	Init_Coefficient(coef);

	Gauss_Elimination(coef, ans);

	Print_Current_Values(ans);

	return 0;
}
