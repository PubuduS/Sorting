#
# In order to execute this "Makefile" just type "make"
#

OBJS	 = main.o Sorting.o SimpleVisualizer.o UserUI.o
SOURCE	 = main.cpp Sorting.cpp SimpleVisualizer.cpp UserUI.cpp
HEADER	 = Sorting.h CoutColor.h SimpleVisualizer.h UserUI.h
OUT	 = sorting
CC	 = g++
FLAGS	 = -g -c -Wall -Iinclude/
LFLAGS	 = 
YFLAGS   =
# LFLAGS - Extra flags for lex
# YFLAGS - Extra flags for yacc
# -g option enables debugging mode 
# -c flag generates object code for separate files


all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)


# create/compile the individual files >>separately<<
main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c++11

Sorting.o: Sorting.cpp
	$(CC) $(FLAGS) Sorting.cpp -std=c++11

SimpleVisualizer.o: SimpleVisualizer.cpp
	$(CC) $(FLAGS) SimpleVisualizer.cpp -std=c++11

UserUI.o: UserUI.cpp
	$(CC) $(FLAGS) UserUI.cpp -std=c++11

# clean up
clean:
	rm -f $(OBJS) $(OUT)
	rm -rf Docs/
