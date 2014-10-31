#include <iostream>
#include"RFormat.h"
#include <string>
using namespace std;

RFormat::RFormat(int n) : Instruction(n)
{
	func = instWord & 0x3F;
	shamt = (instWord >> 6) & 0x1f;
	rd = (instWord >> 11) & 0x1f;
	rt = (instWord >> 16) & 0x1f;
	rs = (instWord >> 21) & 0x1f;
}


void RFormat::add()
{
	lName = "add" + string(" ") + to_string(rd) + string(",") + to_string(rs) + string(",") + to_string(rt); // vector of rd
}
void RFormat::addu()
{
	lName = "addu" + string(" ") + to_string(rd) + string(",") + to_string(rs) + string(",") + to_string(rt);
}
void RFormat::and()
{
	lName = "and" + string(" ") + to_string(rd) + string(",") + to_string(rs) + string(",") + to_string(rt);
}
void RFormat::jr()
{
	lName = "jr" + string(" ") + to_string(rs);
}
void RFormat::slt()
{
	lName = "slt" + string(" ") + to_string(rd) + string(",") + to_string(rs) + string(",") + to_string(rt);
}
void RFormat::sltu()
{
	lName = "sltu" + string(" ") + to_string(rd) + string(",") + to_string(rs) + string(",") + to_string(rt);
}
void RFormat::sll()
{
	lName = "sll" + string(" ") + to_string(rd) + string(",") + to_string(rt) + string(",") + to_string(shamt);
}
void RFormat::srl()
{
	lName = "sll" + string(" ") + to_string(rd) + string(",") + to_string(rt) + string(",") + to_string(shamt);
}
void RFormat::sub()
{
	lName = "sll" + string(" ") + to_string(rd) + string(",") + to_string(rs) + string(",") + to_string(rt);
}
void RFormat::subu()
{
	lName = "sll" + string(" ") + to_string(rd) + string(",") + to_string(rs) + string(",") + to_string(rt);
}