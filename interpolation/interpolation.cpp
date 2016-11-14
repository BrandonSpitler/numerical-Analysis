
#include "interpolation.h"

interpolation::interpolation(int nNumberOfPoints, double ** arr) {
	setNumberOfPoints(nNumberOfPoints);
	PointsArray = new double*[nNumberOfPoints];
	newtonsCoef = NULL;
	for (int i = 0; i < nNumberOfPoints; i++) {
		PointsArray[i] = new double[2];//2 dem for now
		for (int n = 0; n < 2; n++) {
			PointsArray[i][n] = arr[i][n];
		}
	}
}

void interpolation::setNumberOfPoints(int nNumberOfPoints) {

	NumberOfPoints = nNumberOfPoints;
}

void interpolation::deconstructor() {
	for (int i = 0; i < NumberOfPoints; i++) {
		delete PointsArray[i];
		if (newtonsCoef != NULL  && i!=NumberOfPoints-1) {
			delete newtonsCoef[i];
		}
	}
	if (newtonsCoef != NULL) {
		delete newtonsCoef;
	}
	delete PointsArray;
	
}

double interpolation::lagrange(double alpha) {
	int k = 0; int i;
	double sum = 0;
	double product;
	while (k<NumberOfPoints) {
		product = 1; i = 0;
		while (i < NumberOfPoints) {

			if (k != i) {
				product = product*(alpha - PointsArray[i][0]) / (PointsArray[k][0] - PointsArray[i][0]);
			}

			i++;
		}
		sum = sum + product*PointsArray[k][1];

		k++;

	}
	return sum;
}

double interpolation::nevilles(double alpha) {
	double ** inBetweenPoly = new double*[NumberOfPoints - 1];
	int i = 0;

	for (i = 1; i < NumberOfPoints; i++) {
		inBetweenPoly[i - 1] = new double[i];

		for (int n = 0; n < i; n++) {
			if (n == 0) {
				inBetweenPoly[i - 1][n] =
					((alpha - PointsArray[i - 1][0])*PointsArray[i][1]
						- (alpha - PointsArray[i][0])*PointsArray[i - 1][1])
					/ (PointsArray[i][0] - PointsArray[i - 1][0]);
				cout << inBetweenPoly[i - 1][n] << "     ";
			}

			else {
				inBetweenPoly[i - 1][n] =
					((alpha - PointsArray[i - n - 1][0])*inBetweenPoly[i - 1][n - 1]
						- (alpha - PointsArray[i][0])*inBetweenPoly[i - 2][n - 1])
					/ (PointsArray[i][0] - PointsArray[i - n - 1][0]);
				cout << inBetweenPoly[i - 1][n] << "     ";
			}
		}
		cout << endl;
	}
	double x = inBetweenPoly[NumberOfPoints - 2][NumberOfPoints - 2];

	for (int z = 0; z < NumberOfPoints - 1; z++) {

		delete[] inBetweenPoly[z];
	}

	delete[] inBetweenPoly;
	return x;
}

double interpolation::setNewtonsCoef() {
	newtonsCoef = new double*[NumberOfPoints - 1];


	for (int i = NumberOfPoints - 1; i >= 1; i--) {
		newtonsCoef[NumberOfPoints - i - 1] = new double[i];
		for (int n = 0; n < i; n++) {
			if (i == NumberOfPoints - 1) {
				newtonsCoef[NumberOfPoints - i - 1][n] =
					(PointsArray[n + 1][1] - PointsArray[n][1])
					/ (PointsArray[n + 1][0] - PointsArray[n][0]);
			}
			else {
				newtonsCoef[NumberOfPoints - i - 1][n] =
					(newtonsCoef[NumberOfPoints - i - 2][n + 1] - newtonsCoef[NumberOfPoints - i - 2][n])
					/ (PointsArray[NumberOfPoints - i + n][0] - PointsArray[n][0]);
			}
			cout << newtonsCoef[NumberOfPoints - i - 1][n] << "     ";
		}
		cout << endl;

	}
	return 0;
}

double interpolation::newtonsInterp(double alpha) {
	double sum;
	sum = PointsArray[0][1];
	double insideProduct;
	int n;
	for (int i = 1; i < NumberOfPoints; i++) {
		n = 0;
		insideProduct = newtonsCoef[i - 1][0];
		while (n < i) {
			insideProduct = insideProduct*(alpha - PointsArray[n][0]);
			n++;
			
		}
		cout << insideProduct << "+";
		sum += insideProduct;
	}
	cout << endl;
	return sum;
}

double interpolation::clampedCubicSpline(double FPO, double FPN) {
	double * b = new double[NumberOfPoints - 1];
	double * c = new double[NumberOfPoints];
	double * d = new double[NumberOfPoints - 1];
	double * l = new double[NumberOfPoints];
	double * h = new double[NumberOfPoints - 1];
	double * u = new double[NumberOfPoints - 1];
	double * z = new double[NumberOfPoints];

	double * alpha = new double[NumberOfPoints];

	for (int i = 0; i < NumberOfPoints - 1; i++) {
		h[i] = PointsArray[i + 1][0] - PointsArray[i][0];
	}

	alpha[0] = ((3 * (PointsArray[1][1] - PointsArray[0][1])) / h[0]) - 3 * FPO;
	alpha[NumberOfPoints - 1] = (3 * FPN) - (3 * (PointsArray[NumberOfPoints - 1][1] - PointsArray[NumberOfPoints - 2][1])) / h[NumberOfPoints - 2];

	for (int i = 1; i < NumberOfPoints - 1; i++) {
		alpha[i] = ((3 / h[i])*(PointsArray[i + 1][1] - PointsArray[i][1]))
			- ((3 / h[i - 1])*(PointsArray[i][1] - PointsArray[i - 1][1]));
	}
	l[0] = 2 * h[0];
	u[0] = .5;
	z[0] = alpha[0] / l[0];
	for (int i = 1; i < NumberOfPoints - 1; i++) {
		l[i] = (2 * (PointsArray[i + 1][0] - PointsArray[i - 1][0])) - h[i - 1]*u[i - 1];
		u[i] = h[i] / l[i];
		z[i] = (alpha[i] - (h[i - 1] * z[i - 1])) / l[i];
	}

	l[NumberOfPoints - 1] = h[NumberOfPoints - 2] * (2 - u[NumberOfPoints - 2]);
	z[NumberOfPoints - 1] = (alpha[NumberOfPoints - 1] - (h[NumberOfPoints - 2] * z[NumberOfPoints - 2])) / l[NumberOfPoints - 1];
	c[NumberOfPoints - 1] = z[NumberOfPoints - 1];

	for (int j = NumberOfPoints - 2; j >= 0; j--) {
		c[j] = z[j] - u[j] * c[j + 1];
		b[j] = ((PointsArray[j + 1][1] - PointsArray[j][1]) / h[j]) - (h[j] * (c[j + 1] + (2 * c[j]))) / 3;
		d[j] = (c[j + 1] - c[j]) / (3 * h[j]);

	}

	for (int i = 0; i < NumberOfPoints-1; i++) {

		cout << "x_" << i << " = " << PointsArray[i][0] 
			<< " y_" << i << " = " << PointsArray[i][1]
			<< " b_" << i << " = " << b[i]
			<< " c_" << i << " = " << c[i]
			<< " d_" << i << " = " << d[i]
			<< endl;
	}
	cout << "a_" << NumberOfPoints-1 << " = " << PointsArray[NumberOfPoints-1][1] << endl;
/*
	for (int i = 0; i < NumberOfPoints - 1; i++) {

		cout << PointsArray[i][1] << " + "
			<< b[i] << "*x" << " + "
			 << c[i] << "*(x^2)" << " + "
			 << d[i] << "*(x^3)" << " \t\t\t if " << PointsArray[i][0]<<" <= x <= "<< PointsArray[i+1][0]
			<< endl;
	}*/

	for (int i = 0; i < NumberOfPoints - 1; i++) {

		cout << PointsArray[i][1] << " + "
			<< b[i] << "*(x-" << PointsArray[i][0] << ") + "
			<< c[i] << "*(x-" << PointsArray[i][0] << " )^2 + "
			<< d[i] << "*(x-" << PointsArray[i][0] << ")^3 " << "\t\t\t if " << PointsArray[i][0] << " <= x <= " << PointsArray[i + 1][0]
			<< endl;
	}
	delete b;
	delete c;
	delete d;
	delete l;
	delete h;
	delete u;
	delete z;
	return 1;
}

double interpolation::naturalCubicSpline() {
	double * b = new double[NumberOfPoints - 1];
	double * c = new double[NumberOfPoints];
	double * d = new double[NumberOfPoints - 1];
	double * l = new double[NumberOfPoints];
	double * h = new double[NumberOfPoints - 1];
	double * u = new double[NumberOfPoints - 1];
	double * z = new double[NumberOfPoints];

	double * alpha = new double[NumberOfPoints];

	for (int i = 0; i < NumberOfPoints - 1; i++) {
		h[i] = PointsArray[i + 1][0] - PointsArray[i][0];
	}

	//alpha[0] = ((3 * (PointsArray[1][1] - PointsArray[0][1])) / h[0]) - 3 * FPO;
	//alpha[NumberOfPoints - 1] = (3 * FPN) - (3 * (PointsArray[NumberOfPoints - 1][1] - PointsArray[NumberOfPoints - 2][1])) / h[NumberOfPoints - 2];

	for (int i = 1; i < NumberOfPoints - 1; i++) {
		alpha[i] = ((3 / h[i])*(PointsArray[i + 1][1] - PointsArray[i][1]))
			- ((3 / h[i - 1])*(PointsArray[i][1] - PointsArray[i - 1][1]));
	}
	l[0] = 1;
	u[0] = 0;
	z[0] = 0;
	for (int i = 1; i < NumberOfPoints - 1; i++) {
		l[i] = (2 * (PointsArray[i + 1][0] - PointsArray[i - 1][0])) - h[i - 1] * u[i - 1];
		u[i] = h[i] / l[i];
		z[i] = (alpha[i] - (h[i - 1] * z[i - 1])) / l[i];
	}

	l[NumberOfPoints - 1] = 1;
	z[NumberOfPoints - 1] = 0;
	c[NumberOfPoints - 1] = 0;

	for (int j = NumberOfPoints - 2; j >= 0; j--) {
		c[j] = z[j] - u[j] * c[j + 1];
		b[j] = ((PointsArray[j + 1][1] - PointsArray[j][1]) / h[j]) - (h[j] * (c[j + 1] + (2 * c[j]))) / 3;
		d[j] = (c[j + 1] - c[j]) / (3 * h[j]);

	}

	for (int i = 0; i < NumberOfPoints - 1; i++) {
		cout << "a_" << i << " = " << PointsArray[i][1]
			<< " b_" << i << " = " << b[i]
			<< " c_" << i << " = " << c[i]
			<< " d_" << i << " = " << d[i]
			<< endl;
	}
	cout << "a_" << NumberOfPoints - 1 << " = " << PointsArray[NumberOfPoints - 1][1] << endl;
	cout << endl;
	for (int i = 0; i < NumberOfPoints - 1; i++) {

		cout << PointsArray[i][1] << " + "
			<< b[i] << "*(x-" <<PointsArray[i][0] << ") + "
			<< c[i] << "*(x-" <<PointsArray[i][0] << " )^2 + "
			<< d[i] << "*(x-" <<PointsArray[i][0] << ")^3 " << "\t\t\t if " << PointsArray[i][0] << " <= x <= " << PointsArray[i + 1][0]
			<< endl;
	}
	delete b;
	delete c;
	delete d;
	delete l;
	delete h;
	delete u;
	delete z;
	return 1;
}
/*
int interpolation::lagrange(int alpha) {
int NumberOfPoints=getNumberOfPoints();
int i = 0;
int** inBetweenPoly=new int*[NumberOfPoints-1];
while (i < NumberOfPoints) {




for (int n = 0; n < NumberOfPoints - 1; ++n) {
inBetweenPoly[n] = new int[2];//right now only excepts 2 dem arrays
inBetweenPoly[n][1] = 1;
inBetweenPoly[n][2] = 2;
}
for () {

}
}
}*/

