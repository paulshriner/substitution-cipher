# Thanks to Job Vranish (https://spin.atomicobject.com/2016/08/26/makefile-c-projects/)
TARGET_EXEC := cipher
OBJECT_DIRECTORY := ob
CXX := gcc

O_FLAGS := -c

SRCS := $(shell find src -name '*.c')

OBJS := $(SRCS:%=$(OBJECT_DIRECTORY)/%.o)

INC_FLAGS := -Isrc

run: $(TARGET_EXEC)
	./$(TARGET_EXEC)

$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@

$(OBJECT_DIRECTORY)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CXX) $(INC_FLAGS) $(O_FLAGS) $< -o $@




