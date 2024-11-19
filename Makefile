# Makefile para carrera.cpp en macOS M1 Pro

# Compilador y banderas
CXX = clang++
CXXFLAGS = -std=c++17 -pthread -Wall

# Archivos fuente y ejecutable
SRC = carrera.cpp
EXE = carrera

# Regla por defecto: compilar
all: $(EXE)

$(EXE): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(EXE) $(SRC)

# Regla para ejecutar
run: $(EXE)
	./$(EXE)

# Limpiar archivos generados
clean:
	rm -f $(EXE)

