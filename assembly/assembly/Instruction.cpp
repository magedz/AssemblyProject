#include <iostream>
#include<string>
#include<vector>
#include"Instruction.h"
using namespace std;

Instruction::Instruction(int n) : instWord(n) // initializer list
{

	opcode = instWord >> 26;

}
