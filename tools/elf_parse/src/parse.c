/*************************************************************************
    > File Name: src/main.c
    > Author:		
    > Mail:		
    > Created Time: 2020年11月14日 星期六 14时33分37秒
 ************************************************************************/

#include <stdio.h>
#include <elf.h>


void usage(char *execute_file_name)
{
	printf("Usage: %s <elf file>\n", execute_file_name);
	printf("elf file: the ELF format file!\n");
}


int main(int argc, char *argv[])
{
	int a;
	if (argc < 2) {
		usage(argv[0]);
		goto usage_err;
	}

	return 0;

usage_err:
	return -1;
}
