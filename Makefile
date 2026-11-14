TARGET = programa
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

SRC = main.c $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza inteligente que funciona no Windows e no Linux
clean:
	@echo "Limpando arquivos temporarios..."
ifeq ($(OS),Windows_NT)
	@del /Q /S *.o 2>nul || exit 0
	@del /Q $(TARGET).exe 2>nul || exit 0
	@del /Q $(TARGET) 2>nul || exit 0
else
	@rm -f $(OBJ) $(TARGET)
endif
	@echo "Pronto."