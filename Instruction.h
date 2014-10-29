#include <iostream>
#include <vector>
#include <string>
#ifndef Instruction_H
#define Instruction_H



class Instruction
{
public:
	Instruction(int); //constructor that takes 32 bit binary

protected:
	const int instWord;
	int opcode;
	vector <string> registers;


};

#endif

