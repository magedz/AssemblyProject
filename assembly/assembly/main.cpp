#include<iostream>
#include<fstream>
#include<vector>
#include"Globals.h"
#include<string>
#include"RFormat.h"
#include <sstream>
#include"IFormat.h"
#include<cstring>
#include"JFormat.h"
using namespace std;
//PSINST PSINT //PSINT // PSINT !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11111
void openFile(string name);
void callingInst();

void main()
{
	string s;
	for (int i = 0; i < Instructions.size(); i++);
	{
		string temp;
		int index;
		s = Instructions(i); // ass huh, ffd, jj
		index = s.find(' ');
		string fxName = s.substr(0, index);
		temp = s;
		temp.erase(0, index);
		index = temp.find(',');
		string reg1 = temp.substr(0,index);
		temp.erase(0, index);
		index = temp.find(',');
		string reg2 = temp.substr(0, index);
		temp.erase(0, index);
		if (fxName == "addi")
		{
		
			int mostsig = atoi(temp.c_str()) >> 15;
			if ( mostsig== 1)
			{
				index = s.find(' ');
				temp = s.erase(0, index);
				psInst.push_back("subi" +' '+ temp);

			}
			if (reg2 == "$0")
			{
				psInst.push_back("li " +','+ reg1 +','+ temp);
			}

		}

		if ((fxName == "add") || (fxName == "addu"))
		{

			if ((reg2 == "0") && (temp == "0"))
			
				psInst.push_back("clear " + reg1);
			
			if (reg2 == "$0")
				psInst.push_back("move" +',' + reg1 + ',' +temp);
			

		}

		if (fxName == "nor")
		{
			if (temp == "$0")
				psInst.push_back("not " + reg1 +reg2);           /// CHECK LATER ! !!!!! WRONG SYNTAX
		}

		if (fxName == "lui")
		{
			if (s.substr(0, Instructions(i + 1).find(' ')) == "or")
			{
				i += 1;
				//psInst("Li " +)            CHECK LATER !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

			}

		}
		if (fxName == "srl")
		{
			if ((s.substr(0, Instructions(i + 1).find(' ')) == "sll") && (s.substr(0, Instructions(i + 2).find(' ')) == "or"))
			{
				i += 2;
				//psInst("ror " +)            CHECK LATER !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

			}
		}

		if (fxName == "slt")
		{
			i += 1;
			string temps = Instructions(i + 1).erase(0, (Instructions(i + 1).find(",")));
			temps = Instructions(i + 1).erase(0, (Instructions(i + 1).find(",")));
			if ((s.substr(0, Instructions(i + 1).find(' ')) == "beq"))
			{
				psInst("bge " + reg2 + "," + temp + "," + temps);

			}
			else
			{
				psInst("blt " + reg2 + "," + temp + "," + temps);
			}
		}
	}
}


void callingInst()
{
	int OPC;
	for (int i = 0; i < binaryList.size(); i++)
	{
		OPC= binaryList[0];
		OPC = OPC >> 26;
		switch (OPC)
		{
		case 0:
			IsntructionPlist= new RFormat(binaryList(i));

			break;
		case 2:
		case 3:
			InstructionPlist = new JFormat(binaryList(i));
			break;
		default:
			InstructionPlist = new IFormat(binaryList(i));

		}
		
	}

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