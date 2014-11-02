#include "IFormat.h"

IFormat::IFormat(int n) : Instruction(n)
{
	rt = (instWord >> 16) & 0x1f;
	rs = (instWord >> 21) & 0x1f;
	imm = (instWord & 0x0000FFFF);
}

void IFormat::decodeInst()
{
	switch (opcode)
	{
	case 0x8:			addiDisassemble();
		break;
	case 0x9:			addiuDisassemble();

		break;
	case 0xc:			andiDisassemble();

		break;
	case 0x4:			beqDisassemble();
		break;

	case 0x5:			bneDisassemble();

		break;
	case 0xf:			luiDisassemble();
		break;

		break;
	case 0x23:			lwDisassemble();

		break;
	case 0xd:			oriDisassemble();
		break;


	case 0xa:			sltiDisassemble();
		break;

	case 0x28:			sbDisassemble();
		break;


	case 0x29:			shDisassemble();
		break;


	case 0x2b:			swDisassemble();
		break;

	default:
		instString = "Unknown Intruction";
	}
}

void IFormat::addiDisassemble()
{
	signedImm = (imm & 0x8000) ? (0xFFFF0000 | imm) : imm;
	instString += "addi" + registers[rs].name + "," + registers[rt] + "," + to_string(signedImm);
	cout << instString << endl;
}

void IFormat::luiDisassemble()
{
	signedImm = (imm & 0x8000) ? (0xFFFF0000 | imm) : imm;
	instString += "lui" + registers[rs].name + "," + registers[rt] + "," + to_string(signedImm);
	cout << instString << endl;
}
void IFormat::addiuDisassemble()
{
	instString += "addiu" + registers[rs].name + "," + registers[rt] + "," + to_string(imm);
	cout << instString << endl;
}

void IFormat::andiDisassemble()
{
	signedImm = (imm & 0x8000) ? (0xFFFF0000 | imm) : imm;
	instString += "andi" + registers[rs].name + "," + registers[rt] + "," + to_string(signedImm);
	cout << instString << endl;
}

void IFormat::beqDisassemble()
{
	signedImm = (imm & 0x8000) ? (0xFFFF0000 | imm) : imm;
	instString += "beq" + registers[rs].name + "," + registers[rt] + "," + to_string(signedImm);
	cout << instString << endl;
}

void IFormat::bneDisassemble()
{
	signedImm = (imm & 0x8000) ? (0xFFFF0000 | imm) : imm;
	instString += "bne" + registers[rs].name + "," + registers[rt] + "," + to_string(signedImm);
	cout << instString << endl;
}

void IFormat::lwDisassemble()
{
	signedImm = (imm & 0x8000) ? (0xFFFF0000 | imm) : imm;
	instString += "lw" + registers[rt].name + "," + to_string(signedImm) + "(" + registers[rt].name + ")";
	cout << instString << endl;
}

void IFormat::oriDisassemble()
{
	signedImm = (imm & 0x8000) ? (0xFFFF0000 | imm) : imm;
	instString += "ori" + registers[rs].name + "," + registers[rt] + "," + to_string(signedImm);
	cout << instString << endl;
}

void IFormat::sltiDisassemble()
{
	signedImm = (imm & 0x8000) ? (0xFFFF0000 | imm) : imm;
	instString += "slti" + registers[rs].name + "," + registers[rt] + "," + to_string(signedImm);
	cout << instString << endl;
}

void IFormat::sbDisassemble()
{
	signedImm = (imm & 0x8000) ? (0xFFFF0000 | imm) : imm;
	instString += "sb" + registers[rt].name + "," + to_string(signedImm) + "(" + registers[rt].name + ")";
	cout << instString << endl;
}

void IFormat::shDisassemble()
{
	signedImm = (imm & 0x8000) ? (0xFFFF0000 | imm) : imm;
	instString += "sh" + registers[rt].name + "," + to_string(signedImm) + "(" + registers[rt].name + ")";
	cout << instString << endl;
}

void IFormat::swDisassemble()
{
	signedImm = (imm & 0x8000) ? (0xFFFF0000 | imm) : imm;
	instString += "lw" + registers[rt].name + "," + to_string(signedImm) + "(" + registers[rt].name + ")";
	cout << instString << endl;
}

void IFormat::sbSimulate()
{
	memory[ rs + signedImm] = rt;
	PC += 4;
}

void IFormat::sltiSimulate()
{
	rd = (rs < signedImm) ? 1 : 0;
	PC += 4;
}

void IFormat::lwSimulate ()
{
	rt = memory[ rs + signedImm];      // assuming we have a vector called memory
	PC += 4;
}

void IFormat::beqSimulate()
{
	if (rs == rt)
		PC = PC + 4 + signedImm; // actuall PC (pointer) or simulated PC? (signedImm here means address)
}