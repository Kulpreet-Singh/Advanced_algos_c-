#include <iostream>
#include <fstream>
#include <cmath>
#include<omp.h>
using namespace std;

int main()
{
	ifstream temp;
	temp.open("Database.txt");

	const int m = 100;

	int** matrixA = new int* [m];
	int** matrixB = new int* [m];
	int** Answer = new int* [m];

	for (int i = 0; i < m; ++i)
	{
		matrixA[i] = new int[100];
		matrixB[i] = new int[100];
		Answer[i] = new int[100];
	}
	#pragma omp parallel for
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			matrixA[i][j] = 0;
			matrixB[i][j] = 0;
			Answer[i][j] = 0;
		}
	}
	int a, r1 = 0, c1 = 0, r2 = 0, c2 = 0;


	cout << "What operation would you like to perform?\n1.Addition of Matrices\n2.Multipication of Matices\n3.Multiplication of a Vector and Matrix" << endl;
	cin >> a;

	switch (a)
	{
		case 1: cout << "Enter no. of rows followed by columns(upto 100):" << endl;
			cin >> r1 >> c1;
			r2 = r1;
			c2 = c1;
			#pragma omp parallel for
			for (int i = 0; i < r1; ++i)
			{
				for (int j = 0; j < c1; ++j)
				{
					temp >> matrixA[i][j];
					cout << matrixA[i][j] << " ";
				}
				cout << "\n";
			}
			cout << "\n";
			#pragma omp parallel for
			for (int i = 0; i < r2; ++i)
			{
				for (int j = 0; j < c2; ++j)
				{
					temp >> matrixB[i][j];
					cout << matrixB[i][j] << " ";
				}
				cout << "\n";
			}
			cout << "\n";
			#pragma omp parallel for
			for (int i = 0; i < r1; ++i)
			{
				for (int j = 0; j < c1; ++j)
				{
					Answer[i][j] = matrixA[i][j]+matrixB[i][j];
					cout << Answer[i][j] << " ";
				}
				cout << "\n";
			}
			break; 

		case 2: cout << "Enter no. of rows(Matrix A)(upto 100) followed by columns(Matrix A)(upto 100) followed by columns(Matrix B)(upto 100):" << endl;
			cin >> r1 >> c1 >> c2;
			r2 = c1;

			#pragma omp parallel for
			for (int i = 0; i < r1; ++i)
			{
				for (int j = 0; j < c1; ++j)
				{
					temp >> matrixA[i][j];
					cout << matrixA[i][j] << " ";
				}
				cout << "\n";
			}
			cout << "\n";
			#pragma omp parallel for
			for (int i = 0; i < r2; ++i)
			{
				for (int j = 0; j < c2; ++j)
				{
					temp >> matrixB[i][j];
					cout << matrixB[i][j] << " ";
				}
				cout << "\n";
			}
			cout << "\n";

			#pragma omp parallel for
			for (int i = 0; i < r1; ++i)
			{
				for (int j = 0; j < c2; ++j)
				{
					for (int k = 0; k < r2; ++k)
					{
						Answer[i][j] += matrixA[i][k] * matrixB[k][j];
					}
					cout << Answer[i][j] << " ";
				}
				cout << "\n";
			}
			break;
			
		case 3: cout << "Vector into Matrix(enter 1) or Matrix into Vector(enter 2)?" << endl;
			int b;
			cin >> b;
			if (b == 1)
			{
				cout << "Enter dimensions of the matrix(rows followed by columns):" << endl;
				cin >> r2 >> c2;
				r1 = 1;
				c1 = r2;
			}
			else if (b == 2)
			{
				cout << "Enter dimensions of the matrix(rows followed by columns):" << endl;
				cin >> r1 >> c1;
				r2 = c1;
				c2 = 1;
			}
			else {
				cout << "Invalid input!" << endl;
				break;
			}

			#pragma omp parallel for
			for (int i = 0; i < r1; ++i)
			{
				for (int j = 0; j < c1; ++j)
				{
					temp >> matrixA[i][j];
					cout << matrixA[i][j] << " ";
				}
				cout << "\n";
			}
			cout << "\n";
			#pragma omp parallel for
			for (int i = 0; i < r2; ++i)
			{
				for (int j = 0; j < c2; ++j)
				{
					temp >> matrixB[i][j];
					cout << matrixB[i][j] << " ";
				}
				cout << "\n";
			}
			cout << "\n";

			#pragma omp parallel for
			for (int i = 0; i < r1; ++i)
			{
				for (int j = 0; j < c2; ++j)
				{
					for (int k = 0; k < r2; ++k)
					{
						Answer[i][j] += matrixA[i][k] * matrixB[k][j];
					}
					cout << Answer[i][j] << " ";
				}
				cout << "\n";
			}
			break;

		default: cout << "Invalid Input!" << endl;
			break;
	}

	temp.close();

	return 0;
}
