/*************************************************************************
    > File Name: overflow.c
    > Author:		
    > Mail:		
    > Created Time: Wed 02 Sep 2020 06:49:13 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void why_here(void)
{
	printf("why are you here!\n");
	exit(0);
}

void f()
{
	int buff[1];

	buff[2] = (int)why_here;
}

int main(int argc, char *argv[])
{

	f();

	return 0;
}
