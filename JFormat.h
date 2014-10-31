
#ifndef JFormat_h
#define JFormat_h
#include <iostream>
#include<string>
#include<vector>
#include"Instruction.h"
using namespace std;


class JFormat :public Instruction
{
private:
	int add;
	int opCode;

public:
	JFormat(int n) :Instruction(n)
	{
		int first4digits,x;
		string a, b;
		first4digits = PC && 15;
		x = instWord && 268435455;
		add = x << 2;
		a = to_string(first4digits);
		b = to_string(add);
		a = a + b;

		add = atoi(a.c_str());

	}

	void jFx()
	{
		string lName = to_string(labels.size()-1);
		lName= "label" + lName;
		labels.push_back(add);
		lName = "j "+lName;
		funcList.push_back(lName);

	}

	void jalFx()
	{
		string lName = to_string(labels.size() - 1);
		lName = "label" + lName;
		labels.push_back(add);
		lName = "jal " + lName;
		funcList.push_back(lName);
	}

	void decodeInstruction()
	{
		opCode = instWord >> 26;
		if (opCode == 2)
			jFx();
		if (opcode == 3)
			jalFx();
		else
			cout << "unknown instruction" << endl;


		
	}


};





#endif