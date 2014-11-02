#include <iostream>
#include<string>
#include<vector>
#include "Instruction.h"
using namespace std;

Instruction::Instruction(int n) : instWord(n) // initializer list
{
	opcode = instWord >> 26;
	//func = instWord & 0x3F;
	//shamt = (instWord >> 6) & 0x1f;
	//rd = (instWord >> 11) & 0x1f;
	//rt = (instWord >> 16) & 0x1f;
	//rs = (instWord >> 21) & 0x1f;

	// list of registers
	registers.push_back("$0");
	registers.push_back("$at");
	registers.push_back("$v0");
	registers.push_back("$v1");
	registers.push_back("$a0");
	registers.push_back("$a1");
	registers.push_back("$a2");
	registers.push_back("$a3");
	registers.push_back("$t0");
	registers.push_back("$t1");
	registers.push_back("$t2");
	registers.push_back("$t3");
	registers.push_back("$t4");
	registers.push_back("$t5");
	registers.push_back("$t6");
	registers.push_back("$t7");
	registers.push_back("$s0");
	registers.push_back("$s1");
	registers.push_back("$s2");
	registers.push_back("$s3");
	registers.push_back("$s4");
	registers.push_back("$s5");
	registers.push_back("$s6");
	registers.push_back("$s7");
	registers.push_back("$t8");
	registers.push_back("$t9");
	registers.push_back("$k0");
	registers.push_back("$k1");
	registers.push_back("$gp");
	registers.push_back("$sp");
	registers.push_back("$fp");
	registers.push_back("$ra");
}








