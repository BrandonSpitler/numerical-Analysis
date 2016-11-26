
#include <iostream>
#include "interpolation/interpolation.h"
#include "integrration-differention\IntegrationAndDifferentiation.h"
#include <math.h>
using namespace std;

int main() {
	//cout << "hello world";


	double ** arrayXY;
	int numberOfPoints = 8;
	arrayXY = new double *[8];
	for (int i = 0; i < numberOfPoints; i++) {
		arrayXY[i] = new double[2];
		arrayXY[i][0] = .25*i;
		arrayXY[i][1] = pow(.25*i, 2)*exp(-pow(.25*i, 2));


	}


	cout << "mid point rule is " << compositeMidPointRule(arrayXY, numberOfPoints, (float) .25) << endl;
	cout << "trap rule is " << trapRule(arrayXY, 8) << endl;
	cout << "simpson rule is " << simpComposite(arrayXY, 8, arrayXY[0][0], arrayXY[7][0], .25) << endl;





	int pause = 0;
	cin >> pause;


    //interpolation examples
	/*
	double ** arrayXY;
	int numberOfPoints = 4;
	arrayXY = new double *[numberOfPoints];
	for (int i = 0; i < numberOfPoints; i++) {
		arrayXY[i] = new double[2];
	}
	arrayXY[0][0] = 8.1; arrayXY[0][1] = 16.94410;
	arrayXY[1][0] = 8.3; arrayXY[1][1] = 17.56492;
	arrayXY[2][0] = 8.6; arrayXY[2][1] = 18.50515;
	arrayXY[3][0] = 8.7; arrayXY[3][1] = 18.82091;
	*/
	/*
	arrayXY[0][0] = 1; arrayXY[0][1] = .7651977;
	arrayXY[1][0] = 1.3; arrayXY[1][1] = .6200860;
	arrayXY[2][0] = 1.6; arrayXY[2][1] = .4554022;
	arrayXY[3][0] = 1.9; arrayXY[3][1] = .2818186;
	arrayXY[4][0] = 2.2; arrayXY[4][1] = .1103623;*/
	/*
	arrayXY[0][0] = 0; arrayXY[0][1] = 1;
	arrayXY[1][0] = 1; arrayXY[1][1] = exp(1);
	arrayXY[2][0] = 2; arrayXY[2][1] = exp(2);
	arrayXY[3][0] = 3; arrayXY[3][1] = exp(3);
	*/
	/*arrayXY[0][0] = -3; arrayXY[0][1] = pow(-3,4);
	arrayXY[1][0] = -1; arrayXY[1][1] = pow(-1,4);
	arrayXY[2][0] = 1; arrayXY[2][1] = pow(1,4);
	arrayXY[3][0] = 3; arrayXY[3][1] = pow(3,4);*/
	/*
	arrayXY[0][0] = -1; arrayXY[0][1] = 1;
	arrayXY[1][0] = 0; arrayXY[1][1] = 0;
	arrayXY[2][0] = 1; arrayXY[2][1] = 1;
	*/
	/*
	arrayXY[0][0] = 1; arrayXY[0][1] = 2;
	arrayXY[1][0] = 2; arrayXY[1][1] = 3;
	arrayXY[2][0] = 3; arrayXY[2][1] = 5;
	*/
	/*

	interpolation example(numberOfPoints, arrayXY);
	for (int i = 0; i < numberOfPoints; i++) {
		delete[] arrayXY[i];
	}
	delete[] arrayXY;
	
	cout << "nevilles example is: " << example.nevilles(8.5) << endl;
	cout << "lagranges is " << example.lagrange(8.5) << endl;
	example.setNewtonsCoef();
	cout << "newtons is: " << example.newtonsInterp(8.5) << endl;*/
	//cout << "spines is: " << example.clampedCubicSpline(1,exp(3)) << endl;
	//cout << "spines is: " << example.naturalCubicSpline() << endl;

	//cout << "spines is: " << example.clampedCubicSpline(4 * pow(-3, 3), 4 * pow(3, 3)) << endl;
	//cout << "spines is: " << example.clampedCubicSpline(-1,1) << endl;

	/*example.deconstructor();

	*/

	//end interoplation example
	cin.get();
	//arrayXY = new double *[5];

	return 0;
}