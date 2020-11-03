/*************************************************************************
    > File Name: overflow1.c
    > Author:		
    > Mail:		
    > Created Time: Wed 02 Sep 2020 07:04:12 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void why_here(void)
{

	printf("Why are you here!...\n");
	exit(0);
}

void f()
{
	int buf; int *p = &buf;
	*(p + 2) = (int)why_here;

}

int main(int argc, char *argv[])
{
	f();

	return 0;
}
