// Penny Game
// Thane Durey
#include <iostream>
#include <fstream>
#include <string>
// Other include files?
using namespace std;

void main () {
	ifstream fin ("penny.in");
	if (fin) {
		ofstream fout ("penny.out");

		// Main part of program goes here.  Use fin and fout for input and output.
		// May also use cout statements for debugging purposes.

			int loop;
			string lineToRead;
			string compareLetters;

			getline(fin, lineToRead);
			loop = atoi(lineToRead.c_str());

		for(int i = 0; i < loop; i++)
		{
			getline(fin, lineToRead);
			
			int TTT = 0;
			int TTH = 0;
			int THT = 0;
			int THH = 0;
			int HTT = 0;
			int HTH = 0;
			int HHT = 0;
			int HHH = 0;

			for(int j = 0; j < 38; j++)
			{
				compareLetters = lineToRead.substr(j, 3);

				if(compareLetters == "TTT")
					TTT++;
				else if(compareLetters == "TTH")
					TTH++;
				else if(compareLetters == "THT")
					THT++;
				else if(compareLetters == "THH")
					THH++;
				else if(compareLetters == "HTT")
					HTT++;
				else if(compareLetters == "HTH")
					HTH++;
				else if(compareLetters == "HHT")
					HHT++;				
				else if(compareLetters == "HHH")
					HHH++;
			}

			fout << TTT << " " << TTH << " " << THT << " " << THH << " " << HTT << " " << HTH << " " << HHT << " " << HHH << endl;
		}

		fout.close();
		fin.close();
	}
	else {
		cout << "Input file not found." << endl;
	}
}