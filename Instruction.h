#ifndef Instruction_H
#define Instruction_H

#include <iostream>
#include <vector>



class Instruction
{
public:
	Instruction(int); //constructor that takes 32 bit binary
	string toString() const;
	friend ostream& operator<<(ostream&, const Instruction&);
	void (*myFunctionPointer)();
	
protected:
	const int instWord;
	int opcode;
	int PC;
	vector<int> labels; // label0 is in index 0 ..etc
	//vector <string> funcList;
	string instString;
	vector<string> registers;
	vector<int> registerNames;


};

#endif




