#include <iostream>
#include"globals.h"
#ifndef Instruction_H
#define Instruction_H

class Instruction
{
public:
	Instruction(int); //constructor that takes 32 bit binary
	string toString() const;
	friend ostream& operator<<(ostream&, const Instruction&);
protected:
	const int instWord;
	int opcode;
	//int PC;
	string instString;

};

#endif




