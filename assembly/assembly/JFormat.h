
#ifndef JFormat_h
#define JFormat_h
#include <iostream>
#include<string>
#include<vector>
#include"Instruction.h"
#include"Globals.h"
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

	void decodeInstruction()
	{
		opCode = instWord >> 26;
		if (opCode == 2)
		{
			jDisassemble();
			Instruction::myFunctionPointer = &this->jSimulate;
		}
			
		if (opcode == 3)
		{
			jalDisassemble();
			Instruction::myFunctionPointer = &this->jalSimulate;
		}
		
		else
			cout << "unknown instruction" << endl;


	}

	void jDisassemble()
	{
		string lName = to_string(labels.size()-1);
		lName= "label" + lName;
		labels.push_back(add);
		lName = "j "+lName;
		funcList.push_back(lName);

	}

	void jalDisassemble()
	{
		string lName = to_string(labels.size() - 1);
		lName = "label" + lName;
		labels.push_back(add);
		lName = "jal" + lName;
		funcList.push_back(lName);
	}
	
	void jSimulate()
	{
		PC = add;
	}

	void jalSimulate()
	{
		PC = add;
		R[31] = PC + 8;
	}


};





#endif