#ifndef RFORMAT_H
#define RFORMAT_H
#include <iostream>
#include "Instruction.h"

class RFormat :public Instruction
{
public:
	RFormat(int); //constructor
	void decodeInst();
	void add();
	void addu();
	void and();
	void jr();
	void slt();
	void sltu();
	void sll();
	void srl();
	void sub();
	void subu();






private:
	int func, shamt, rd, rt, rs;
};





#endif
