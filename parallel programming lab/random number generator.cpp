#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
	int MaxNumber = 1000, random;
	ofstream fout;
	fout.open("Database.txt");
	for (int i = 0; i < 16000000; ++i){
		random = rand() % MaxNumber;
		fout << random << " ";
	}
	fout.close();
	cout<<"Random Numbers Successfully generated and saved to file.\n";
	
	ifstream fin;
	fin.open("Database.txt");
	cout<<"A few random numbers inside the database file:\n";
	for(int i=0;i<1000;i++){
		fin>>random;
		cout<<random<<" ";
	}
	fin.close();
	return 0;
}
