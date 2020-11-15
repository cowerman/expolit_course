/*************************************************************************
 * MIT LICENSE
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <elf_parse.h>
#include <getopt.h>

#define N_SIZE 4096
extern char *elf_type[];
extern char *machine_type[];
char buf[N_SIZE];
Elf64_Ehdr elf;


void usage(char *execute_file_name)
{
	printf("Usage: %s <elf file>\n", execute_file_name);
	printf("elf file: the ELF format file!\n");
	printf("   -h   : header of the ELF format file\n");
	printf("   -v   : usage of this information\n");
}

void elf2str(int fd)
{
	int err;
	do {
		err = read(fd, buf, N_SIZE);
		if (err == -1) {
			perror(strerror(errno));
			break;
		}
		puts(buf);
	} while (err != 0);

	return;
}

char *itoa(unsigned int num, int nbytes)
{
	int type_bit_leng = nbytes * 8;
	int shift = (type_bit_leng - 4)/4, i = shift, j, low;

	for (j = 2; i >= 0; i --, j ++) {
		low = (num >> (i * 4)) & 0xf;
		if (low >= 10) {
			buf[j] = low + 0x37;
		} else {
			buf[j] = low + 0x30;
		}
	}

	buf[1] = 'x';
	buf[0] = '0';
	buf[shift + 3] = '\0';

	return buf;
}

void show_elf_header(int fd)
{
	int err;
	memset(&elf, 0, sizeof(Elf64_Ehdr));
	lseek(fd, 0, SEEK_SET);
	err = read(fd, &elf, sizeof(Elf64_Ehdr));
	if (err == -1) {
		perror(strerror(errno));
		return;
	}
#if 0
	/* Convert type of Elf64_Word/Off/Addr to string */
	printf("Magic:    %45s\n", elf.e_ident);
	printf("Type:     %45s\n", elf_type[elf.e_type]);
	printf("Machine:  %45s\n", machine_type[elf.e_machine]);
	printf("Version:  %45s\n", itoa(elf.e_version, sizeof(Elf64_Word)));
	printf("Entry:    %45s\n", itoa(elf.e_entry, sizeof(Elf64_Addr)));
	printf("Phoff:    %45s\n", itoa(elf.e_phoff, sizeof(Elf64_Off)));
	printf("Shoff:    %45s\n", itoa(elf.e_shoff, sizeof(Elf64_Off)));
	printf("Flags:    %45s\n", itoa(elf.e_flags, sizeof(Elf64_Word)));
	printf("Ehsize:   %45s\n", itoa(elf.e_ehsize, sizeof(Elf64_Half)));
	printf("Phentsize:%45s\n", itoa(elf.e_phentsize, sizeof(Elf64_Half)));
	printf("Phnum:    %45s\n", itoa(elf.e_phnum, sizeof(Elf64_Half)));
	printf("Shentsize:%45s\n", itoa(elf.e_shentsize, sizeof(Elf64_Half)));
	printf("Shnum:    %45s\n", itoa(elf.e_shnum, sizeof(Elf64_Half)));
	printf("Shstrndx: %45s\n", itoa(elf.e_shstrndx, sizeof(Elf64_Half)));
#else
	printf("Magic:    %36s\n", elf.e_ident);
	printf("Type:     %36s\n", elf_type[elf.e_type]);
	printf("Machine:  %36s\n", machine_type[elf.e_machine]);
	printf("Version:  %36d\n", elf.e_version);
	printf("Entry:    %#36lx\n", elf.e_entry);
	printf("Phoff:    %36ld (bytes into file)\n", elf.e_phoff);
	printf("Shoff:    %36ld (bytes into file)\n", elf.e_shoff);
	printf("Flags:    %#36x\n", elf.e_flags);
	printf("Ehsize:   %36d (bytes)\n", elf.e_ehsize);
	printf("Phentsize:%36d (bytes)\n", elf.e_phentsize);
	printf("Phnum:    %36d\n", elf.e_phnum);
	printf("Shentsize:%36d (bytes)\n", elf.e_shentsize);
	printf("Shnum:    %36d\n", elf.e_shnum);
	printf("Shstrndx: %36d\n", elf.e_shstrndx);

#endif
	perror(strerror(errno));
	return;

}

static char optstr[] = "hv";
static struct option long_options[] = {
	{"ELF Header", no_argument, 0,  'h'},
	{"Help",       no_argument, 0,  'v'},

};

int main(int argc, char *argv[])
{
	int fd;
	char c;
	if (argc < 2) {
		usage(argv[0]);
		goto usage_err;
	}

	fd = open(argv[1], O_RDONLY);
	if (fd < 0) {
		goto open_failed;
	}

	int option_idx = 0;
	while ((c = getopt_long(argc, argv, optstr, long_options, &option_idx)) != -1) {
		switch (c) {
		case 'h':
			show_elf_header(fd);
			break;
		case 'v':
		default:
			usage(argv[0]);
		}
	}
	//elf2str(fd);

	close(fd);
	return 0;
usage_err:
open_failed:
	return -1;
}
