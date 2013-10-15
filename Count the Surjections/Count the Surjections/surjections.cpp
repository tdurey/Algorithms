// Count the Surjections
// Thane Durey
#include <iostream>
#include <fstream>
#include <string>
// Other include files?
using namespace std;

//Function for n^m
unsigned long long PowerOfn(int m, int n)
{
	unsigned long long temp = n;
	for(int i = 1; i < m; i++)
	{
		temp = n*temp;
	}
	return temp;
}

//Function for Combination (n over i)
unsigned long long Combination (unsigned long long n, unsigned long long i)
{
	if(i == 0 || n == 0 || i == n)
		return 1;
	return Combination(n-1, i-1) + Combination(n-1, i);
}

//Function for S(m,n)
unsigned long long Surjection(unsigned long long m, unsigned long long n)
{
	if(m == 0 && n == 0)
	{
		//nothing, end of file
	}
	else if(n == 1)
	{
		return 1;
	}
	else if(m < n)
	{
		return 0;
	}
	else if(m == n)
	{
		unsigned long long answer = 1;
		//Factorial of 'm'
		for(int x = 1; x <= m; x++)
		{
			answer = answer * x;
		}

		return answer;
	}
	else
	{
		//n^m
		unsigned long long r = PowerOfn(m, n);
	
		//what we will return
		unsigned long long summation = 0;

		for(int i = 1; i <= (n-1); i++)
		{
			unsigned long long combination = Combination(n,i);
			summation = summation + (combination * Surjection(m,i));
		}

		return r - summation;
	}
}

void main () {
	ifstream fin ("surjections.in");
	if (fin) {
		ofstream fout ("surjections.out");

		// Main part of program goes here.  Use fin and fout for input and output.
		// May also use cout statements for debugging purposes.
		bool notLastLine = true;

		while(fin)
		{
			string line;
			string stringM;
			string stringN;
			bool firstNumber;
			string str;
			unsigned long long m;
			unsigned long long n;
			unsigned long long answer = 1;

			getline(fin, line);
			firstNumber = true;
		
			for(int i = 0; i < line.length(); i++)
			{
				if(line.at(i) != 32 && firstNumber)
				{
					//append to m
					str = line.at(i);
					stringM.append(str); 
				}
				else if(line.at(i) == 32)
				{
					firstNumber = false;
				}
				else
				{
					//append to n
					str = line.at(i);
					stringN.append(str);
				}
			}

			m = atoi(stringM.c_str());
			n = atoi(stringN.c_str());

			answer = Surjection(m,n);

			if(notLastLine)
				notLastLine = false;
			else
				fout << endl;
			if(m != 0 || n != 0)
				fout << "S(" << m << "," << n << ") = " << answer;
		}

		fout.close();
		fin.close();
	}
	else {
		cout << "Input file not found." << endl;
	}
}