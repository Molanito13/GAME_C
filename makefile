########################################################
CC=gcc
CFLAGS= -g -Wall -ansi -pedantic
EJS = main  
TEST = die_test set_test space_test inventory_test player_test link_test object_test command_test
#####################################################################
# $@ es el item que aparece a la izquierda de ':'
# $< es el primer item en la lista de dependencias
# $^ son todos los archivos que se encuentran a la derecha de ':'
########################################################################
########################################################
OBJECTSM = command.o game.o game_loop.o graphic_engine.o game_management.o screen.o space.o  player.o object.o set.o die.o inventory.o link.o
OBJECTST1 = die.o die_test.o
OBJECTST2 = set.o set_test.o
OBJECTST3 = space.o space_test.o set.o link.o
OBJECTST4 = inventory.o inventory_test.o set.o
OBJECTST5 = player.o player_test.o inventory.o set.o
OBJECTST6 = link.o link_test.o
OBJECTST7 = object.o object_test.o
OBJECTST8 = command.o command_test.o
########################################################

all: $(EJS) doxygen

test: $(TEST) doxygen

main: $(OBJECTSM)
	$(CC) $(CFLAGS) -o $@ ./obj/game_loop.o ./obj/command.o ./obj/game.o ./obj/graphic_engine.o ./obj/screen.o ./obj/space.o ./obj/object.o ./obj/player.o ./obj/game_management.o ./obj/die.o ./obj/set.o ./obj/inventory.o ./obj/link.o

die_test:  $(OBJECTST1)
	$(CC) $(CFLAGS) -o $@ ./obj/die_test.o ./obj/die.o

set_test: $(OBJECTST2)
	$(CC) $(CFLAGS) -o $@ ./obj/set_test.o ./obj/set.o

space_test: $(OBJECTST3)
	$(CC) $(CFLAGS) -o $@ ./obj/space_test.o ./obj/space.o ./obj/set.o ./obj/link.o

inventory_test: $(OBJECTST4)
	$(CC) $(CFLAGS) -o $@ ./obj/inventory_test.o ./obj/inventory.o ./obj/set.o

player_test: $(OBJECTST5)
	$(CC) $(CFLAGS) -o $@ ./obj/player_test.o ./obj/player.o ./obj/inventory.o ./obj/set.o

link_test: $(OBJECTST6)
	$(CC) $(CFLAGS) -o $@ ./obj/link_test.o ./obj/link.o

object_test: $(OBJECTST7)
		$(CC) $(CFLAGS) -o $@ ./obj/object_test.o ./obj/object.o

command_test: $(OBJECTST8)
		$(CC) $(CFLAGS) -o $@ ./obj/command_test.o ./obj/command.o

command.o: ./src/command.c ./include/command.h ./include/types.h
	$(CC) $(CFLAGS) -o ./obj/$@ -c $<

game.o: ./src/game.c ./include/game.h ./include/game_management.h ./include/player.h ./include/object.h ./include/die.h ./include/command.h ./include/types.h    
	$(CC) $(CFLAGS) -o ./obj/$@ -c $<

game_loop.o: ./src/game_loop.c ./include/graphic_engine.h ./include/game.h ./include/command.h   
	$(CC) $(CFLAGS) -o ./obj/$@ -c $<

graphic_engine.o: ./src/graphic_engine.c ./include/screen.h ./include/graphic_engine.h ./include/command.h ./include/die.h ./include/types.h ./include/set.h ./include/inventory.h       
	$(CC) $(CFLAGS) -o ./obj/$@ -c $<

screen.o: ./src/screen.c ./include/screen.h 
	$(CC) $(CFLAGS) -o ./obj/$@ -c $<

space.o: ./src/space.c ./include/types.h ./include/space.h ./include/link.h   
	$(CC) $(CFLAGS) -o ./obj/$@ -c $<

game_management.o: ./src/game_management.c ./include/game_management.h ./include/link.h ./include/game.h  
	$(CC) $(CFLAGS) -o ./obj/$@ -c $<

player.o: ./src/player.c ./include/types.h ./include/player.h ./include/inventory.h   
	$(CC) $(CFLAGS) -o ./obj/$@ -c $<

object.o: ./src/object.c ./include/types.h ./include/object.h 
	$(CC) $(CFLAGS) -o ./obj/$@ -c $<

die_test.o: ./src/die_test.c ./include/die.h ./include/die_test.h ./include/test.h   
	$(CC) $(CFLAGS) -o ./obj/$@ -c $<

die.o: ./src/die.c ./include/die.h 
	$(CC) $(CFLAGS) -o ./obj/$@ -c $<

set_test.o: ./src/set_test.c ./include/test.h ./include/set_test.h ./include/set.h  
	$(CC) $(CFLAGS) -o ./obj/$@ -c $<

space_test.o: ./src/space_test.c ./include/test.h ./include/set.h ./include/space.h ./include/space_test.h   
	$(CC) $(CFLAGS) -o ./obj/$@ -c $<

set.o: ./src/set.c ./include/set.h 
	$(CC) $(CFLAGS) -o ./obj/$@ -c $<

inventory_test.o: ./src/inventory_test.c ./include/test.h ./include/inventory.h ./include/inventory_test.h  
	$(CC) $(CFLAGS) -o ./obj/$@ -c $<

inventory.o: ./src/inventory.c ./include/set.h ./include/inventory.h 
	$(CC) $(CFLAGS) -o ./obj/$@ -c $<

player_test.o: ./src/player_test.c ./include/test.h ./include/player_test.h ./include/player.h ./include/set.h ./include/inventory.h    
	$(CC) $(CFLAGS) -o ./obj/$@ -c $<

link_test.o: ./src/link_test.c ./include/test.h ./include/link_test.h ./include/link.h ./include/types.h   
	$(CC) $(CFLAGS) -o ./obj/$@ -c $<

link.o: ./src/link.c ./include/link.h 
	$(CC) $(CFLAGS) -o ./obj/$@ -c $<

object_test.o: ./src/object_test.c ./include/test.h ./include/object_test.h ./include/object.h  
		$(CC) $(CFLAGS) -o ./obj/$@ -c $<

command_test.o: ./src/command_test.c ./include/test.h ./include/command.h ./include/command_test.h
		$(CC) $(CFLAGS) -o ./obj/$@ -c $<

########################################################
.PHONY: clean

clean:
	rm -f ./obj/*.o  $(EJS) $(TEST)

run:
	./main data.dat -l log.txt

runv:
	valgrind --leak-check=full ./main data.dat -l log.txt

runvf:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -v ./main data.dat -l log.txt

gdb:
	gdb --tui -tty /dev/pts/1 --args ./main data.dat -l

doxygen:
	doxygen Doxyfile

rung1:
	./main data.dat < partida1.oca

rung2:
	./main data.dat < partida2.oca