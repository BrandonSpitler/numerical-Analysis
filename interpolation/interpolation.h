#ifndef INTERPOLATION_H
#define INTERPOLATION_H
#include <iostream>
using namespace std;

class interpolation{
private:
	int NumberOfPoints;
	
public:
	double ** PointsArray;
	double ** newtonsCoef;
	interpolation(int nNumberOfPoints,double **arr);
	void setNumberOfPoints(int nNumberOfPoints);
	int getNumberOfPoints() { return NumberOfPoints; }
	double lagrange(double alpha);
	double nevilles(double alpha);
	double setNewtonsCoef();
	double newtonsInterp(double alpha);
	double clampedCubicSpline(double FPO, double FPN);
	double naturalCubicSpline();
	void deconstructor();
};
#endif