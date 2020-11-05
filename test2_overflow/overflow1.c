/*************************************************************************
    > File Name: first_vol.c
    > Author:		
    > Mail:		
    > Created Time: 2020年11月03日 星期二 14时36分54秒
 ************************************************************************/

/* For 64Bit Operation machine */

#include <stdio.h>
#include <stdlib.h>

/* before stack frame					 |		after override stack frame
---0x7fffdd90--|   X                  | <----RBP0	 |	---0x7fffdd90--|   X                  | <----RBP0
---0x7fffdd88--|   return IP          | <----RSP0	 |	---0x7fffdd88--|   return where IP    | <----RSP0
---0x7fffdd80--|   RBP0(0x7fffdd90)   | <----RSP1,RBP1	 |	---0x7fffdd80--|   0x00030002         | <----RSP1,RBP1
---0x7fffdd7c--|   4Byte Local var    | <----RSP2	 |	---0x7fffdd7c--|   1                  | <----RSP2
 */
void where(void)
{
	printf("why are u here!\n");

	return;
	//exit(0);
}

void f()
{
	int repl[1];
	repl[0] = 1;
	repl[1] = 2;
	repl[2] = 3;
	repl[3] = (int)where;
}

int main(void)
{

	f();
	return 0;
}
