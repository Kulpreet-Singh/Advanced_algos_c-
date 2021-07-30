#include <iostream>
#include <fstream>
#include <cmath>

void getCofactor(int A[100][100], int temp[100][100], int p, int q, int n)
{
	int i = 0, j = 0;

	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
		{
			if (row != p && col != q)
			{
				temp[i][j++] = A[row][col];

				if (j == n - 1)
				{
					j = 0;
					i++;
				}
			}
		}
	}
}

int Determinant(int A[100][100], int n)
{
	int D = 0;
	if (n == 1)
		return A[0][0];

	int temp[100][100] = {0};
	int sign = 1;

	for (int f = 0; f < n; f++)
	{ 
		getCofactor(A, temp, 0, f, n);
		D += sign * A[0][f] * Determinant(temp, n - 1);

		sign = -sign;
	}

	return D;
}

void adjoint(int A[100][100], int adj[100][100], int N)
{
	if (N == 1)
	{
		adj[0][0] = 1;
		return;
	}
	int sign = 1, temp[100][100] = {0};

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{ 
			getCofactor(A, temp, i, j, N);

			sign = ((i + j) % 2 == 0) ? 1 : -1;

			adj[j][i] = (sign) * (Determinant(temp, N - 1));
		}
	}
}

int main()
{
	std::ifstream temp;
	temp.open("Database.txt");

	int matrixA[100][100] = { 0 }, matrixB[100][100]{ 0 }, Answer[100][100] = { 0 };
	int a, r1 = 0, c1 = 0, r2 = 0, c2 = 0, determinant=0;


	std::cout << "What operation would you like to perform?\n1.Addition of Matrices\n2.Subtraction of Matrices\n3.Multipication of Matices\n4.Inverse of a Matrix\n5.Multiplication of a Vector and Matrix" << std::endl;
	std::cin >> a;

	switch (a)
	{
		case 1: std::cout << "Enter no. of rows followed by columns(upto 100):" << std::endl;
			std::cin >> r1 >> c1;
			r2 = r1;
			c2 = c1;

			for (int i = 0; i < r1; ++i)
			{
				for (int j = 0; j < c1; ++j)
				{
					temp >> matrixA[i][j];
					std::cout << matrixA[i][j] << " ";
				}
				std::cout << "\n";
			}
			std::cout << "\n";
			for (int i = 0; i < r2; ++i)
			{
				for (int j = 0; j < c2; ++j)
				{
					temp >> matrixB[i][j];
					std::cout << matrixB[i][j] << " ";
				}
				std::cout << "\n";
			}
			std::cout << "\n";
			for (int i = 0; i < r1; ++i)
			{
				for (int j = 0; j < c1; ++j)
				{
					Answer[i][j] = matrixA[i][j]+matrixB[i][j];
					std::cout << Answer[i][j] << " ";
				}
				std::cout << "\n";
			}
			break;

		case 2: std::cout << "Enter no. of rows followed by columns(upto 100):" << std::endl;
			std::cin >> r1 >> c1;
			r2 = r1;
			c2 = c1;

			for (int i = 0; i < r1; ++i)
			{
				for (int j = 0; j < c1; ++j)
				{
					temp >> matrixA[i][j];
					std::cout << matrixA[i][j] << " ";
				}
				std::cout << "\n";
			}
			std::cout << "\n";
			for (int i = 0; i < r2; ++i)
			{
				for (int j = 0; j < c2; ++j)
				{
					temp >> matrixB[i][j];
					std::cout << matrixB[i][j] << " ";
				}
				std::cout << "\n";
			}
			std::cout << "\n";
			for (int i = 0; i < r1; ++i)
			{
				for (int j = 0; j < c1; ++j)
				{
					Answer[i][j] = matrixA[i][j] - matrixB[i][j];
					std::cout << Answer[i][j] << " ";
				}
				std::cout << "\n";
			}
			break;

		case 3: std::cout << "Enter no. of rows(Matrix A)(upto 100) followed by columns(Matrix A)(upto 100) followed by columns(Matrix B)(upto 100):" << std::endl;
			std::cin >> r1 >> c1 >> c2;
			r2 = c1;

			for (int i = 0; i < r1; ++i)
			{
				for (int j = 0; j < c1; ++j)
				{
					temp >> matrixA[i][j];
					std::cout << matrixA[i][j] << " ";
				}
				std::cout << "\n";
			}
			std::cout << "\n";
			for (int i = 0; i < r2; ++i)
			{
				for (int j = 0; j < c2; ++j)
				{
					temp >> matrixB[i][j];
					std::cout << matrixB[i][j] << " ";
				}
				std::cout << "\n";
			}
			std::cout << "\n";

			for (int i = 0; i < r1; ++i)
			{
				for (int j = 0; j < c2; ++j)
				{
					for (int k = 0; k < r2; ++k)
					{
						Answer[i][j] += matrixA[i][k] * matrixB[k][j];
					}
					std::cout << Answer[i][j] << " ";
				}
				std::cout << "\n";
			}
			break;

		case 4: std::cout << "Enter the Row = Column size of square matrix:" << std::endl;
			std::cin >> r1;
			c1 = r1;

			for (int i = 0; i < r1; ++i)
			{
				for (int j = 0; j < c1; ++j)
				{
					temp >> matrixA[i][j];
					std::cout << matrixA[i][j] << " ";
				}
				std::cout << "\n";
			}
			std::cout << "\n";

			determinant = Determinant(matrixA, r1);
			std::cout << determinant << std::endl;

			if (determinant == 0)
			{
				std::cout << "Inverse does not exist!" << std::endl;
				break;
			}
			float InverseMat[100][100] = { 0 };
			adjoint(matrixA, matrixB, r1);

			for (int i = 0; i < r1; ++i)
			{
				for (int j = 0; j < r1; ++j)
				{
					InverseMat[i][j] = matrixB[i][j] / (float)determinant;
					std::cout<< InverseMat[i][j] <<" ";
				}
				std::cout<<std::endl;
			}
			break;
	}
	/*int arr[100][100];
	for (int i = 0; i < 100; ++i)
	{	
		for (int j = 0; j < 100; ++j)
		{
			temp >> arr[i][j];
			std::cout << arr[i][j] << std::endl;
		}
	}*/
	temp.close();

	return 0;
}
