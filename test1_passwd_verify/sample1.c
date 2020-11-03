/*************************************************************************
    > File Name: sample1.c
    > Author:		
    > Mail:		
    > Created Time: Wed 02 Sep 2020 02:01:50 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWD "10938457473892939848"

enum {
	false,
	true,
};

void usage()
{

	printf("Usage: ./a.out passwd \n");

}

int verify_passwd(const char *pwd_str)
{
	int ret = false;

	if (!strcmp(PASSWD, pwd_str)) {
		ret = true;
	}

	return ret;
}

int main(int argc, char *argv[])
{

	if (argc != 2) {
		usage();
		exit(-1);
	}

	if (verify_passwd(argv[1])) {
		printf("Get correct passwd!\n");
	} else {
		printf("Get wrong passwd, try again...\n");
	}

}
