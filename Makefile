CC=gcc
CFLAGS=-Wall -pedantic -ansi -g -DDEBUG
CLIB= -lscreen -L.
TEST= space_test set_test 
IFLAGS=-I.

.PHONY: clean_objects clean_program clean all

all: anthill

##############################################
anthill: game_reader.o character.o command.o game.o game_actions.o game_loop.o graphic_engine.o space.o object.o set.o player.o
	$(CC) -o $@ $^ $(CLIB)

##############################################
game_loop.o: game_loop.c command.h game.h space.h types.h game_actions.h graphic_engine.h
	$(CC) $(CFLAGS) -c $< $(IFLAGS)

command.o: command.c command.h
	$(CC) $(CFLAGS) -c $< $(IFLAGS)

game_reader.o: game_reader.c game_reader.h
	$(CC) $(CFLAGS) -c $< $(IFLAGS)

game.o: game.c game.h game_reader.h command.h space.h types.h object.h types.h
	$(CC) $(CFLAGS) -c $< $(IFLAGS)
 
game_actions.o: game_actions.c game_actions.h command.h game.h space.h types.h
	$(CC) $(CFLAGS) -c $< $(IFLAGS)

graphic_engine.o: graphic_engine.c graphic_engine.h game.h command.h space.h types.h libscreen.h
	$(CC) $(CFLAGS) -c $< $(IFLAGS)

space.o: space.c space.h types.h set.h
	$(CC) $(CFLAGS) -c $< $(IFLAGS)

object.o: object.c object.h types.h
	$(CC) $(CFLAGS) -c $< $(IFLAGS)

player.o: player.c player.h types.h
	$(CC) $(CFLAGS) -c $< $(IFLAGS)
 
set.o: set.c set.h types.h
	$(CC) $(CFLAGS) -c $< $(IFLAGS)

character.o: character.c types.h character.h
	$(CC) $(CFLAGS) -c $< $(IFLAGS)

space_test.o: space_test.c space.h types.h set.h test.h
	$(CC) $(CFLAGS) -c $< $(IFLAGS)

set_test.o: set_test.c set.h types.h test.h
	$(CC) $(CFLAGS) -c $< $(IFLAGS)

character_test.o: character_test.c character.h types.h test.h
	$(CC) $(CFLAGS) -c $< $(IFLAGS)


#############################################

test: space_test set_test

space_test: space_test.o space.o set.o 
	$(CC) $(CFLAGS) -o $@ $^ -L.

set_test: set_test.o set.o 
	$(CC) $(CFLAGS) -o $@ $^ -L.

character_test: character_test.o character.o
	$(CC) $(CFLAGS) -o $@ $^ -L.


############################################
clean_objects:
	@echo "Cleaning objects..."
	@rm -f *.o

clean_program:
	@echo "Cleaning program..."
	@rm -f anthill

clean_test:
	@echo "Cleaning tests..."
	@rm -f $(TEST)

clean: clean_objects clean_program clean_test

#############################################

run:
	@echo "Anthill being runned"
	@./anthill anthill.dat

runtest: 
	@echo "Running tests"
	@./space_test; ./set_test ./character_test

valgrind:
	@echo "Running valgrind to detect memory leaks"
	@valgrind --leak-check=full -s ./anthill anthill.dat


run_space_test: space_test
	./space_test

run_set_test:
	./set_test

run_character_test:
	./character_test

