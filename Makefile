CC := g++
FLAGS := -std=c++17 -Wall
SRC := main.cpp Game.cpp Tabuleiro.cpp login.cpp
SRCTST := teste.cpp Game.cpp Tabuleiro.cpp login.cpp
OBJ := $(SRC:.cpp=.o)
OBJTST := $(SRCTST:.cpp=.o)
JOGO := Xadrez.exe
TESTE := Casos_Teste.exe

build: $(OBJ) $(OBJTST)
	@echo "Building main game..."
	@$(CC) $(FLAGS) -o $(JOGO) $(OBJ)
	@echo "Building test cases..."
	@$(CC) $(FLAGS) -o $(TESTE) $(OBJTST)

test: $(TESTE)
	./$<

run: $(JOGO)
	./$<

clean:
	@echo "Cleaning..."
	@rf $(OBJ) $(OBJTST)

Game.o: Game.cpp
	@g++ -c $<

Tabuleiro.o: Tabuleiro.cpp
	@g++ -c $<

login.o: login.cpp
	@g++ -c $<