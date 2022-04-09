SOURCES = $(shell find $(SOURCEDIR) -name '*.c')
OBJS = $(SOURCES:.c=.o)
CC = gcc
CC_FLAGS = -pedantic -Wall -W -std=c11 -Werror
INCLUDES = -Itest -Iinc

SRCS = $(wildcard *.c)

all:
	echo $(SOURCES)

cb_test: $(OBJS)
	$(CC) -o $@ $(OBJS)
	./cb_test

%.o: %.c
	$(CC) -o $@ $< -c $(CC_FLAGS) $(INCLUDES)

