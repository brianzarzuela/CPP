/**
 * Title  : CircuitsAnalysisFunctions.cpp
 * Course : Computational Problem Solving II (CPET-321)
 * Author : Brian Zarzuela
 * Date   : Fall 2019 (2191)
 * Description: Function file for CircuitsAnalysis.cpp
 *
 * Last Modified : 30 Aug 2019 at 12:55am
 */

#include "CircuitsAnalysis.h"

void Init_Coefficient(float coef[][SIZE+1])
{
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Constant and variable declarations
	// *From  data file circuit.dat
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	double R1;		// Value for resistor R1
	double R2;		// Value for resistor R2
	double R3;		// Value for resistor R3
	double R4;		// Value for resistor R4
	double R5;		// Value for resistor R5
	double V1;		// Value for voltage source V1
	double V2;		// Value for voltage source V2

	ifstream datafile ("circuit.dat");
	if (datafile.is_open())
		datafile >> R1 >> R2 >> R3 >> R4 >> R5 >> V1 >> V2;
	else
	{
		cout << "circuit.dat could not be opened\nprogram terminating...";
		exit(1);
	}

	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Construct the coefficient array using the given Resistor and Voltage source values.
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	coef[0][0] = (R1 + R2);
	coef[0][1] = -(R2);
	coef[0][2] = 0;
	coef[0][3] = V1;
	coef[1][0] = -(R2);
	coef[1][1] = (R2 + R3 + R4);
	coef[1][2] = -(R4);
	coef[1][3] = 0;
	coef[2][0] = 0;
	coef[2][1] = -(R4);
	coef[2][2] = (R4 + R5);
	coef[2][3] = -(V2);
}

void Gauss_Elimination(float coef[][SIZE+1], float ans[])
{
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Gauss-Elimination for solving a System of Linear Equations
	//
	//  Steps:  1) Pivotisation
	//			2) Gauss Elimination
	//			3) Back-Substitution
	//
	//  For more details on the Gauss-Elimination process please see:
	//           https://en.wikipedia.org/wiki/Gaussian_elimination
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	int r, c, k;				// loop control variables

	// Steps #1 : Pivotisation +++++++++++++++++++++++++++++++++++++++++++++
	double tmp1;

	for (r=0; r<SIZE; r++)
		for (k=r+1; k<SIZE; k++)
			if (abs(coef[r][r]) < abs(coef[k][r]))
				for (c=0; c<=SIZE; c++)
				{
					tmp1 = coef[r][c];
					coef[r][c] = coef[k][c];
					coef[k][c] = tmp1;
				}
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	// Steps #2 : Gauss Elimination ++++++++++++++++++++++++++++++++++++++++
	double tmp2;
	for (r=0; r<SIZE-1; r++)
		for (k=r+1; k<SIZE; k++)
		{
			tmp2 = coef[k][r] / coef[r][r];
			for (c=0; c<=SIZE; c++)
				coef[k][c] = coef[k][c] - tmp2 * coef[r][c];
		}
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	// Steps #3 : Back-Substitution ++++++++++++++++++++++++++++++++++++++++
	for (r=SIZE-1; r>=0; r--)
	{
		ans[r] = coef[r][SIZE];
		for (c=r+1; c<SIZE; c++)
			if (c!=r)
				ans[r] = ans[r] - coef[r][c] * ans[c];
		ans[r] = ans[r] / coef[r][r];
	}
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
}

void Print_Current_Values(float ans[])
{
	// Print the calculated branch currents ++++++++++++++++++++++++++++++++
	cout<<"\nThe branch currents are as follows:" << endl;
	cout << fixed << setprecision(3);
	for (int i = 0; i < SIZE; i++)
		cout << "i[" << i + 1 << "] = " << setw(8) << ans[i] <<endl;
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
}


