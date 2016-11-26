#include <math.h>
#include <iostream>
using namespace std;

float compositeMidPointRule(double **xyArr, int size, float h) {
	float sum = 0;
	for (int n = 0; n < size - 1; n++) {
		float c_n = (xyArr[n][1] + xyArr[n + 1][1]) / 2;
		cout << c_n*h << endl;

		sum = sum + h*c_n;
	}
	return sum;
}

float simpComposite(double **xyArr, int size, float a, float b, float h) {


	float xZero = xyArr[0][1] - xyArr[size - 1][1];
	float xTwo = 0;
	float xOne = 0;
	for (int i = 0; i < size - 1; i += 2) {
		xTwo = xTwo + xyArr[i][1];
	}
	for (int i = 1; i < size - 1; i += 2) {
		xOne = xOne + xyArr[i][1];

	}
	cout << xZero << " " << xTwo << " " << xOne << endl;
	return (h * (xZero + 2 * xTwo + 4 * xOne) / 3);
}

float trapRule(double **xyArr, int size) {
	float sum = 0;
	for (int n = 0; n < size - 1; n++) {
		float slope = (xyArr[n][1] - xyArr[n][1]) / (xyArr[n + 1][0] - xyArr[n][0]);
		float integral = -slope * pow((xyArr[n][0] - xyArr[n + 1][0]), 2) / 2 + xyArr[n + 1][0] * xyArr[n + 1][1] - xyArr[n][0] * xyArr[n + 1][1];
		cout << integral << endl;
		sum = sum + integral;
	}
	return sum;

}