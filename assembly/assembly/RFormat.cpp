#include <iostream>
#include"RFormat.h"
#include"Globals.h"
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

void RFormat::decodeInst()
{
	switch (func)
	{
	case 0x20:			addDisassemble();
		Instruction::myFunctionPointer = &this->addSimulate;
		break;
	case 0x21:			adduDisassemble();
		Instruction::myFunctionPointer = &this->adduSimulate;

		break;
	case 0x24:			andDisassemble();
		Instruction::myFunctionPointer = &this->andSimulate;

		break;
	case 0x08:			jrDisassemble();
		Instruction::myFunctionPointer = &this->jrSimulate;
		break;

	case 0x2a:			sltDisassemble();
		Instruction::myFunctionPointer = &this->sltSimulate;
		break;
	case 0x2b:			sltuDisassemble();
		Instruction::myFunctionPointer = &this->sltuSimulate;
		break;

		break;
	case 0x00:			sllDisassemble();
		Instruction::myFunctionPointer = &this->sllSimulate;

		break;
	case 0x02:			srlDisassemble();
		Instruction::myFunctionPointer = &this->srlSimulate;
		break;


	case 0x22:			subDisassemble();
		Instruction::myFunctionPointer = &this->subSimulate;
		break;

	case 0x23:			subuDisassemble();
		Instruction::myFunctionPointer = &this->subuSimulate;
		break;



	default:
		instString = "Unknown Intruction";
		cout << instString;
	}
}

void RFormat::addDisassemble()
{
	instString = "add" + string(" ") + registers[rd].name + string(",") + registers[rs].name + string(",") + registers[rt].name; // vector of rd
	//cout << instString;
	instructions.push_back(instString);
}
void RFormat::adduDisassemble()
{
	instString = "addu" + string(" ") + registers[rd].name + string(",") + registers[rs].name + string(",") + registers[rt].name;
	//cout << instString;
	instructions.push_back(instString);
}
void RFormat::adduSimulate()
{
	registers[rd].name = registers[rs].value + registers[rt].value;
}
void RFormat::andDisassemble()
{
	instString = "and" + string(" ") + registers[rd].name + string(",") + registers[rs].name + string(",") + registers[rt].name;
	instructions.push_back(instString);
	//cout << instString;
}
void RFormat::andSimulate()
{
	registers[rd].name = registers[rs].value & registers[rt].value;
}
void RFormat::jrDisassemble()
{
	instString = "jr" + string(" ") + registers[rs].name;
	instructions.push_back(instString);
	//cout << instString;
}
void RFormat::jrSimulate()
{
	pc = registers[rs].value;
}
void RFormat::sltDisassemble()
{
	instString = "slt" + string(" ") + registers[rd].name + string(",") + registers[rs].name + string(",") + registers[rt].name;
	instructions.push_back(instString);
	//cout << instString;
}
void RFormat::sltSimulate()
{
	registers[rd].name = (registers[rs].value < registers[rt].value) ? 1 : 0;
	PC += 4;
}
void RFormat::sltuDisassemble()
{
	instString = "sltu" + string(" ") + registers[rd].name + string(",") + registers[rs].name + string(",") + registers[rt].name;
	instructions.push_back(instString);
	//cout << instString;
}
void RFormat::sllDisassemble()
{
	instString = "sll" + string(" ") + registers[rd].name + string(",") + registers[rt].name + string(",") + to_string(shamt);
	instructions.push_back(instString);
	//cout << instString;
}
void RFormat::sllSimulate()
{
	registers[rd].name = registers[rt].value << shamt;
	PC += 4;
}
void RFormat::srlDisassemble()
{
	instString = "sll" + string(" ") + registers[rd].name + string(",") + registers[rt].name + string(",") + to_string(shamt);
	instructions.push_back(instString);
	//cout << instString;
	PC += 4;
}
void RFormat::srlSimulate()
{
	registers[rd].name = registers[rt].value >> shamt;    // or pow(2,shamt) ??
	PC += 4;
}
void RFormat::subDisassemble()
{
	instString = "sll" + string(" ") + registers[rd].name + string(",") + registers[rs].name + string(",") + registers[rt].name;
	//cout << instString;
	instructions.push_back(instString);
	PC += 4;
}
void RFormat::subSimulate()
{
	registers[rd].name = registers[rs].value << registers[rt].value;
	PC += 4;
}
void RFormat::subuDisassemble()
{
	instString = "sll" + string(" ") + registers[rd].name + string(",") + registers[rs].name + string(",") + registers[rt].name;
	//cout << instString;
	instructions.push_back(instString);
	PC += 4;
}