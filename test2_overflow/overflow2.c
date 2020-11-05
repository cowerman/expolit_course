/*************************************************************************
    > File Name: overflow2.c
    > Author:		
    > Mail:		
    > Created Time: Wed 02 Sep 2020 11:28:28 PM CST
 ************************************************************************/

/* Stack overflow the internel flag variable */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWD "1234567"

enum {
	false,
	true,
};

void usage()
{
	printf("Usage: ./a.out passwd\n");
}

int verify_passwd(char *passwd_str)
{

	char auther = false;
	char buff[8];
	if(!strcmp(PASSWD, passwd_str)) {
		auther = true;
	}
	strcpy(buff, passwd_str);
	return auther;
}

int main(int argc, char *argv[])
{

	int pass = false;

	if (argc != 2) {
		usage();
		exit(0);
	}

	pass = verify_passwd(argv[1]);
	if (pass) {
		printf("Got the right passwd!\n");
	} else {
		printf("Wrong passwd, try again...\n");
	}
	return 0;
}
