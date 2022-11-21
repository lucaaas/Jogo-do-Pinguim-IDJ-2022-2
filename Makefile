CC = g++
RMDIR = rm -rf
RM = rm -f
RUN = ./

HEADER_PATH = include
SRC_PATH = .
BIN_PATH = bin
DEP_PATH = dep

DEP_FLAGS = -MT $@ -MMD -MP -MF $(DEP_PATH)/$*.d
DIRECTIVES = -std=c++11 -Wall -Wextra -c -I $(HEADER_PATH)
LIBS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lm

CPP_FILES := $(shell find $(SRC_PATH) -type f -name "*.cpp")
OBJ_FILES = $(CPP_FILES:.cpp=.o)
DEP_FILES = $(wildcard $(DEP_PATH)/*.d)

EXEC = GAME


ifeq ($(OS),Windows_NT)

RMDIR = rd /s /q
RM = del

RUN =

SDL_PATH = C:\SDL2\SDL2-2.0.5\x86_64-w64-mingw32

DIRECTIVES += -I $(SDL_PATH)\include\SDL2

LIBS = -L $(SDL_PATH)\lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lm

EXEC := $(EXEC).exe

else
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Darwin)
LIBS = -lm -framework SDL2 -framework SDL2_image -framework SDL2_mixer -framework SDL2_ttf
endif
endif


all: $(EXEC)

$(EXEC): $(OBJ_FILES)
	$(CC) -o $@ $^ $(LIBS)

$(BIN_PATH)/%.o: $(shell find $(SRC_PATH) -type f -name "*.cpp")

ifeq ($(OS), Windows_NT)
	@if not exist $(DEP_PATH) @mkdir $(DEP_PATH)
	@if not exist $(BIN_PATH) @mkdir $(BIN_PATH)
else
	@mkdir -p $(DEP_PATH) $(BIN_PATH)
endif

	$(CC) $(DEP_FLAGS) -c -o $@ $< $(DIRECTIVES)

print-% : ; @echo $* = $($*)

debug: DIRECTIVES += -ggdb -O0 -DDEBUG
debug: all

dev: debug run

gdb: RUN := gdb $(RUN)
gdb: dev

release: DIRECTIVES += -Ofast -mtune=native
release: all

run:
	$(RUN)$(EXEC)

clean:
	$(RMDIR) $(BIN_PATH) $(DEP_PATH)
	$(RM) $(EXEC)
	$(RM) *.o

.PRECIOUS: $(DEP_PATH)/%.D

.PHONY: debug clean release

-include $(DEP_FILES)