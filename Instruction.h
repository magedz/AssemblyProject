#include <iostream>
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
	int PC;
	vector<int> labels; // label0 is in index 0 ..etc
	//vector <string> funcList;
	string lName;
	vector<string> registers;


};

#endif

#endif


