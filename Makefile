# Thanks to Job Vranish (https://spin.atomicobject.com/2016/08/26/makefile-c-projects/)
TARGET_EXEC := cipher
OBJECT_DIRECTORY := ob
CXX := gcc

O_FLAGS := -c

SRCS := $(wildcard src/*.c)
# https://www.gnu.org/software/make/manual/html_node/Wildcard-Function.html

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
