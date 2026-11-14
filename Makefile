# Nomes dos executáveis
TARGET = programa
TARGET_ESTRESSE = teste_estresse

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

# Encontra os arquivos fonte
SRC = main.c $(wildcard src/*.c)
SRC_ESTRESSE = main_estresse.c $(wildcard src/*.c)

# Arquivos objeto
OBJ = $(SRC:.c=.o)
OBJ_ESTRESSE = $(SRC_ESTRESSE:.c=.o)

# Regra principal (compila o projeto e o teste de estresse)
all: $(TARGET) $(TARGET_ESTRESSE)

# Compila o executável principal
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Compila o executável de teste de estresse
$(TARGET_ESTRESSE): $(OBJ_ESTRESSE)
	$(CC) $(CFLAGS) -o $(TARGET_ESTRESSE) $(OBJ_ESTRESSE)

# Regra para compilar cada arquivo .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza inteligente (funciona no Windows e no Linux)
clean:
	@echo "Limpando arquivos temporarios..."
ifeq ($(OS),Windows_NT)
	@del /Q /S *.o 2>nul || exit 0
	@del /Q $(TARGET).exe 2>nul || exit 0
	@del /Q $(TARGET) 2>nul || exit 0
	@del /Q $(TARGET_ESTRESSE).exe 2>nul || exit 0
	@del /Q $(TARGET_ESTRESSE) 2>nul || exit 0
else
	@rm -f $(OBJ) $(OBJ_ESTRESSE) $(TARGET) $(TARGET_ESTRESSE)
endif
	@echo "Pronto."