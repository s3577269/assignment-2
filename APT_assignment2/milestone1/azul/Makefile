.default: all

all: azul

clean:
	rm -f azul *.o

azul: Wall.o Pattern.o Mosaic.o Player.o TileBag.o GameEngine.o azul.o Factory.o Type.o BoxLid.o AI.o
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^
