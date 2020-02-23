/**
 * Title  : CircuitsAnalysisFunctions.cpp
 * Course : Computational Problem Solving II (CPET-321)
 * Author : Brian Zarzuela
 * Date   : Fall 2019 (2191)
 * Description: Header file for CircuitsAnalysis.cpp
 *
 * Last Modified : 29 Aug 2019 at 4:21pm
 */

#ifndef CIRCUITSANALYSIS_H_
#define CIRCUITSANALYSIS_H_

#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>
using namespace std;

const int SIZE = 3; // SIZE of the circuit (i.e. # of branches)

void Init_Coefficient(float [][SIZE+1]);
void Gauss_Elimination(float [][SIZE+1], float []);
void Print_Current_Values(float []);

#endif /* CIRCUITSANALYSIS_H_ */
