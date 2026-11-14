# Nome do executável final
TARGET = programa

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

# Encontra todos os arquivos .c na pasta src
SRC = main.c $(wildcard src/*.c)

# Gera os arquivos objeto (.o) temporários
OBJ = $(SRC:.c=.o)

# Regra principal (o que roda quando você digita "make")
all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Regra para compilar cada arquivo .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para limpar os arquivos temporários
clean:
	rm -f $(OBJ) $(TARGET)