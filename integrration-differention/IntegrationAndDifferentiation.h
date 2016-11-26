#ifndef INTEGRATIONANDDIFFERENTIAION_H
#define INTEGRATIONANDDIFFERENTIAION_H
#include <iostream>
using namespace std;

float compositeMidPointRule(double **xyArr, int size, float h);
float simpComposite(double **xyArr, int size, float a, float b, float h);
float trapRule(double **xyArr, int size);
#endif // !INTEGRATIONANDDIFFERENTIAION_H

