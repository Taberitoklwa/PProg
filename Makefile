CC=gcc
CFLAGS=-Wall -pedantic -ansi -g -DDEBUG
CLIB= -lscreen -L.

.PHONY: clean_objects clean_program clean all

all: anthill

##############################################
anthill: game_reader.o character.o command.o game.o game_actions.o game_loop.o graphic_engine.o space.o object.o set.o player.o
	$(CC) -o $@ $^ $(CLIB)

##############################################
game_loop.o: game_loop.c command.h game.h space.h types.h game_actions.h graphic_engine.h
	$(CC) $(CFLAGS) -c $<

command.o: command.c command.h
	$(CC) $(CFLAGS) -c $<

game_reader.o: game_reader.c game_reader.h
	$(CC) $(CFLAGS) -c $<

game.o: game.c game.h game_reader.h command.h space.h types.h object.h types.h
	$(CC) $(CFLAGS) -c $<

game_actions.o: game_actions.c game_actions.h command.h game.h space.h types.h
	$(CC) $(CFLAGS) -c $<

graphic_engine.o: graphic_engine.c graphic_engine.h game.h command.h space.h types.h libscreen.h
	$(CC) $(CFLAGS) -c $<

space.o: space.c space.h types.h set.h
	$(CC) $(CFLAGS) -c $<

object.o: object.c object.h types.h
	$(CC) $(CFLAGS) -c $<

player.o: player.c player.h types.h
	$(CC) $(CFLAGS) -c $<

set.o: set.c set.h types.h
	$(CC) $(CFLAGS) -c $<

character.o: character.c types.h character.h
	$(CC) $(CFLAGS) -c $<


##############################################
clean_objects:
	@echo "Cleaning objects..."
	@rm -f *.o

clean_program:
	@echo "Cleaning program..."
	@rm -f anthill

clean: clean_objects clean_program