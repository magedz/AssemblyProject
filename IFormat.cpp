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
	case 0x8:			//addi
		signedImm = (imm & 0x8000) ? (0xFFFF0000 | imm) : imm;
		temp += "addi" + registers[rs] + "," + registers[rt] + "," + to_string(signedImm);
		funcList.push_back(temp);
		break;
	case 0x9:			//addiu
		temp += "addiu" + registers[rs] + "," + registers[rt] + "," + to_string(imm);
		funcList.push_back(temp);
		break;
	case 0xc:			//andi
		signedImm = (imm & 0x8000) ? (0xFFFF0000 | imm) : imm;
		temp += "andi" + registers[rs] + "," + registers[rt] + "," + to_string(signedImm);
		funcList.push_back(temp);
		break;
	case 0x4:			//beq
		signedImm = (imm & 0x8000) ? (0xFFFF0000 | imm) : imm;
		temp += "beq" + registers[rs] + "," + registers[rt] + "," + to_string(signedImm);
		funcList.push_back(temp);
		break;
	case 0x5:			//bne
		signedImm = (imm & 0x8000) ? (0xFFFF0000 | imm) : imm;
		temp += "bne" + registers[rs] + "," + registers[rt] + "," + to_string(signedImm);
		funcList.push_back(temp);
		break;
	case 0xf:			//lui
		signedImm = (imm & 0x8000) ? (0xFFFF0000 | imm) : imm;
		temp += "lui" + registers[rs] + "," + registers[rt] + "," + to_string(signedImm);
		funcList.push_back(temp);
		break;
	case 0x23:			//lw
		signedImm = (imm & 0x8000) ? (0xFFFF0000 | imm) : imm;
		temp += "lw" + registers[rt] + "," + to_string(signedImm)+ "(" + registers[rt] + ")";
		funcList.push_back(temp);
		break;
	case 0xd:			//ori
		signedImm = (imm & 0x8000) ? (0xFFFF0000 | imm) : imm;
		temp += "ori" + registers[rs] + "," + registers[rt] + "," + to_string(signedImm);
		funcList.push_back(temp);
		break;
	case 0xa:			//slti
		signedImm = (imm & 0x8000) ? (0xFFFF0000 | imm) : imm;
		temp += "slti" + registers[rs] + "," + registers[rt] + "," + to_string(signedImm);
		funcList.push_back(temp);
		break;
	case 0x28:			//sb
		signedImm = (imm & 0x8000) ? (0xFFFF0000 | imm) : imm;
		temp += "sb" + registers[rs] + "," + registers[rt] + "," + to_string(signedImm);
		funcList.push_back(temp);
		break;
	case 0x29:			//sh
		signedImm = (imm & 0x8000) ? (0xFFFF0000 | imm) : imm;
		temp += "sh" + registers[rs] + "," + registers[rt] + "," + to_string(signedImm);
		funcList.push_back(temp);
		break;
	case 0x2b:			//sw
		signedImm = (imm & 0x8000) ? (0xFFFF0000 | imm) : imm;
		temp += "sw" + registers[rs] + "," + registers[rt] + "," + to_string(signedImm);
		funcList.push_back(temp);
		break;
	default:
		temp = "Unknown Intruction";
	}
}