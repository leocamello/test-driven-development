# Compiler
CC=gcc
# Flags
LDFLAGS =
CFLAGS =  
#define the name of the output file
APP=leddrivertests.out
# includes directories
DIR_INC=./include/
DIR_UNITY_SRC=./unity/src/
DIR_UNITY_EXTRAS=./unity/extras/fixture/src/
DIR_TESTS=./tests/
DIR_SRC=./src/
# Output directory
DIR_BIN=./bin

INC=$(DIR_INC) $(DIR_UNITY_SRC) $(DIR_UNITY_EXTRAS)
INC_PARAMS=$(foreach d, $(INC), -I$d)

SRC = $(wildcard $(DIR_TESTS)*.c)
SRC += $(wildcard $(DIR_UNITY_SRC)*.c)
SRC += $(wildcard $(DIR_UNITY_EXTRAS)*.c)
SRC += $(wildcard $(DIR_SRC)*.c)

OBJ = $(SRC:.c=.o)

$(DIR_BIN)/$(APP):
	$(info   Generating $@)
	@$(CC) -o $@ $(SRC) $(LDFLAGS) $(CFLAGS) $(INC_PARAMS)
	$(info   Done.)

.PHONY: clean
clean:
	$(info   Cleaning files)
	@rm -f $(OBJ) $(DIR_BIN)/$(APP)
	$(info   Done.)