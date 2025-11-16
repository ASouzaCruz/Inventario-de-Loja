# ===== CONFIGURAÇÕES =====
CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude

# Pastas
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

# Nome do executável
TARGET = $(BIN_DIR)/inventario.exe

# Arquivos fonte realmente existentes
SRC = $(SRC_DIR)/main.cpp \
      $(SRC_DIR)/Inventario.cpp

# Converte cada arquivo para um .o dentro de build/
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC))

# ===== REGRAS =====

all: $(TARGET)

$(TARGET): $(OBJ) | $(BIN_DIR)
	@echo Compilando o executável...
	$(CXX) $(OBJ) -o $(TARGET)
	@echo Compilação concluída! Executável em $(TARGET)

# Regra para compilar cada .cpp
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Criar pasta build
$(BUILD_DIR):
	@if not exist "$(BUILD_DIR)" mkdir "$(BUILD_DIR)"

# Criar pasta bin
$(BIN_DIR):
	@if not exist "$(BIN_DIR)" mkdir "$(BIN_DIR)"

# Limpar arquivos
clean:
	@echo Limpando arquivos compilados...
	@if exist "$(BUILD_DIR)" rmdir /s /q "$(BUILD_DIR)"
	@if exist "$(BIN_DIR)" rmdir /s /q "$(BIN_DIR)"
	@echo Limpeza concluída.

# Rodar
run: all
	@$(TARGET)
