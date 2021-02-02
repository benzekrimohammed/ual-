#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
	bool F0,F1,INV_A,EN_A,EN_B,A,B,C_IN,S;
	//LOGIC UNIT ENTRIES
	bool LIN0,LIN1;
	//RESULTS OF ACTIVATION UNIT
	bool RF0,RF1,RF2,RF3;
	//RESULTS OF LOGIC UNITS
	bool L0,L1,L2;
	//RESILTS OF ADDING UNIT
	bool C_OUT,SOMME;
	//*****************
	F0=0;
	F1=0;
	INV_A=0;
	A=1;
	EN_A=1;
	B=0;
	EN_B=1;





	//ENCODER
	RF0=!F0&!F1;
	RF1=!F0&F1;
	RF2=F0&!F1;
	RF3=F0&F1;

	//PERLOGIC UNIT
	LIN0=A&EN_A;
	LIN1=INV_A^LIN0;
	//LOGIC UNIT
	L0=RF0&(LIN0&LIN1);
	L1=RF1&(LIN0|LIN1);
	L2=RF3&!LIN1;
	//ADDING UNIT
	SOMME=(C_IN^(LIN1^LIN0))&RF3;
	C_OUT=RF3&C_IN&(LIN1^LIN0)|RF3&LIN0&LIN1;
	//FINAL RESULT
	S=L0|L1|L2|SOMME;

	printf("S=%d c out=%d\n",S,C_OUT);









	return 0;
}