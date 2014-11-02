#include<iostream>
#include<fstream>
#include<vector>
#include"Instruction.h"
#include"Globals.h"
#include<string>
using namespace std;

void main()
{

	
}

void openFile(string name)
{
	ifstream x;
	x.open(name.c_str());
	string binarycode = NULL;
	char chara;
	while (!x.eof())
	{
		for (int i = 0; i < 32; i++)
		{
			x.get(chara);
			binarycode += chara;
		}

		binaryList.push_back(atoi(binarycode.c_str()));
	}
}