#include "proj1.h"

/*
 *  Return a string containing the disassembled version of the given
 *  instruction.  You absolutely MUST follow the formatting instructions
 *  given in the assignment.  Note that the string your return should
 *  not include a tab at the beginning or a newline at the end since
 *  those are added in computer.c where this function is called.
 *
 *  Finally you are responsible for managing the memory associated with
 *  any string you return.  If you use malloc, you will somehow need to
 *  free the memory later (note that you cannot modify computer.c).
 *  Hint: static or global variables.
 */
char * disassembled (unsigned int instr, unsigned int pc) {
    /* You replace this code by the right stuff. */
    int two = 0;//����ת������32λ��������
	if ((pc & 0x3) != 0) exit(0); // Your program must exit when an unsupported instruction is detected
	if ((instr & 0xfc000000) == 0) {
		if ((instr & 0x3f) == 0x20) { //addָ��
			printf("add\t");
			DS1(0, instr);
		}
		else if ((instr & 0x3f) == 0x21) {  //adduָ��
			printf("addu\t");
			DS1(0, instr);
		}
		else if ((instr & 0x3f) == 0x23) {  //subuָ��
			printf("subu\t");
			DS1(0, instr);
		}
		else if ((instr & 0x3f) == 0x24) {  //andָ��
			printf("and\t");
			DS1(0, instr);
		}
		else if ((instr & 0x3f) == 0x25) {  //orָ��
			printf("or\t");
			DS1(0, instr);
		}
		else if ((instr & 0x3f) == 0x2A) {  //sltָ��
			printf("slt\t");
			DS1(0, instr);
		}
		else if ((instr & 0x3f) == 0x0) {  //sllָ��
			printf("sll\t");
			DS1(3, instr);
		}
		else if ((instr & 0x3f) == 0x2) {
			// srlָ��
			printf("srl\t");
			DS1(3, instr);
		}
		else if ((instr & 0x3f) == 0x8) {  //jrָ��
			printf("jr\t");
			DS1(2, instr);
		}
	}
	else if ((instr & 0xfc000000) > 0x0C000000) {  //I��ʽָ��
		int opcode = instr >> 26;
		if (opcode == 0x9) {  //addiuָ��
			printf("addiu\t");
			DS3(0, instr);
		}
		else if (opcode == 0xC) {  //andiָ��
			printf("andi\t");
			DS3(3, instr);
		}
		else if (opcode == 0xD) {  //oriָ��
			printf("ori\t");
			DS3(3, instr);
		}
		else if (opcode == 0xF) {  //luiָ��
			printf("lui\t");
			DS3(1, instr);
		}
		else if (opcode == 0x23) {//lw ָ��
			printf("lw\t");
			DS3(2, instr);
		}
		else if (opcode == 0x2B) {  //swָ��
			printf("sw\t");
			DS3(2, instr);
		}
		else if (opcode == 0x4) {  //beqָ��
			printf("beq\t");
			DS2(instr, pc);
		}
		else if (opcode == 0x5) {  //bneָ��
			printf("bne\t");
			DS2(instr, pc);
		}
	}
	else if ((instr & 0xfc000000) == 0x08000000) {  //jָ��
		printf("j\t");
		DS4(instr, pc);
	}
	else if ((instr & 0xfc000000) == 0x0C000000) {  //jalָ��
		printf("jal\t");
		DS4(instr, pc);
	}

	return " ";

    return "addu $2,$0,$0";
}

/*
 *  Simulate the execution of the given instruction, updating the
 *  pc appropriately.
 *
 *  If the instruction modified a register--i.e. if it was lw,
 *  addu, addiu, subu, sll, srl, and, andi, or, ori, lui, or slt
 *  to list a few examples-- return the index of the modified
 *  register in *changedReg, otherwise return -1 in *changedReg.
 *  Note that you should never return 0 in *changedReg, since
 *  $0 cannot be changed!  Note that even if the instruction
 *  changes the register back to it's old value
 *  (e.g. addu $3, $3, $0) the destination register ($3 in the
 *  example) should be marked changed!
 *
 *  If the instruction was sw, return the address of the
 *  updated memory location in *changedMem, otherwise return -1
 *  in *changedMem.
 */
void simulateInstr (Computer mips, unsigned int instr, int *changedReg, int *changedMem) {
    /* You replace this code by the right stuff. */
    mips->pc = mips->pc + 4;
    *changedReg = -1;
    *changedMem = -1;
}
