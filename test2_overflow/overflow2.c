/*************************************************************************
    > File Name: overflow2.c
    > Author:		
    > Mail:		
    > Created Time: Wed 02 Sep 2020 11:28:28 PM CST
 ************************************************************************/

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

	char auther = true;
	char buff[8];
	auther = strcmp(PASSWD, passwd_str);
	strcpy(buff, passwd_str);
	return auther;
}

int main(int argc, char *argv[])
{

	int ret = false;

	if (argc != 2) {
		usage();
		exit(0);
	}

	ret = verify_passwd(argv[1]);
	if (ret) {
		printf("Wrong passwd, try again...\n");
	} else {
		printf("Got the right passwd!\n");
	}
	return 0;
}
