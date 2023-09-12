#
#	 Class: ECET 4640-002
#    Assignment: Lab Assignment 3
#    Authors: Christian Messmer, Karl Miller, Paul Shriner
#
#	 Makefile: Used to facilite "make" and related commands.
#
#	 Acknowledgements/Credits:
#	 	1. Job Vranish - https://spin.atomicobject.com/2016/08/26/makefile-c-projects/
#		2. https://www.gnu.org/software/make/manual/html_node/Wildcard-Function.html
#

# See 1 in Acknowledgements/Credits
TARGET_EXEC := cipher
OBJECT_DIRECTORY := ob
CXX := gcc

O_FLAGS := -c

# See 2 in Acknowledgements/Credits
SRCS := $(wildcard src/*.c)

OBJS := $(SRCS:%=$(OBJECT_DIRECTORY)/%.o)

INC_FLAGS := -Isrc

run: $(TARGET_EXEC)
	./$(TARGET_EXEC)

clean:
	$(RM) $(TARGET_EXEC) $(OBJS)

$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@

$(OBJECT_DIRECTORY)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CXX) $(INC_FLAGS) $(O_FLAGS) $< -o $@
