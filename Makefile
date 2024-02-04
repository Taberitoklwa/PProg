CC = gcc

BINARY = anthill

OBJS = game.o command.o game_actions.o game_loop.o game_reader.o graphic_engine.o space.o

all: $(BINARY)

antill: $(OBJS)
	$(CC) -o $(BINARY) $(OBJS)

game.o: game.c game.h game_reader.h
	$(CC) -c game.c

command.o: command.h
	$(CC) -c command.c

game_actions.o: game_actions.h game.h
	$(CC) -c game_actions.c

game_loop.o: game_actions.h game.h command.h graphic_engine.h
	$(CC) -c game_loop.c

game_reader.o: game.h game_reader.h
	$(CC) -c game_reader.c
 
graphic_engine.o: graphic_engine.h command.h libscreen.h space.h types.h
	$(CC) -c graphic_engine.c
	
space.o: space.h
	$(CC) -c space.c


clean: 
	rm -f $(BINARY) $(OBJS)
