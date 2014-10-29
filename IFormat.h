#ifndef IFormat_h
#define IFormat_h
#include "Instruction.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class IFormat : public Instruction
{
public:
	IFormat(int);			// constructor
	~IFormat();				// destructor
	void decodeInst();


private:
	int rt;    //target	
	int rs;		//source	
	int imm;	//immediate
	int signedImm;                  // signed Immediate
	vector<string> funcList;		//list of finished instructions
	vector<string> registers;		//list of register names (access by index)
	string temp = NULL;
}

#endif