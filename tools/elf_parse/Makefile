
CUR=$(shell pwd)
INC=-I$(CUR)/include
OUT_DIR=$(CUR)/build
TARGET=elf_parse

CC=gcc
CFLAGS= -g -Werror -std=c99
LD_FLAGS= -Wl,-Map=output.map
OBJCPY=objcopy

SRCS=src/parse.c
OBJS=$(patsubst %.c, $(OUT_DIR)/%.o, $(wildcard $(SRCS)))

.PHONY:
all: clean $(OUT_DIR)/$(TARGET)


.PHONY:
$(OUT_DIR)/$(TARGET): $(OBJS)
	$(CC) $(LD_FLAGS) $(OBJS) -o $@

.PHONY:
$(OUT_DIR)/%.o: %.c
	[ ! -e $@ ] && mkdir -p $(dir $@); \
	$(CC) -c $(CFLAGS) $(INC) $< -o $@

.PHONY:
clean:
	rm -rf $(OUT_DIR)
