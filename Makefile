#
# In order to execute this "Makefile" just type "make"
#

OBJS	 = main.o Sorting.o
SOURCE	 = main.cpp Sorting.cpp
HEADER	 = Sorting.h
OUT	 = sorting
CC	 = g++
FLAGS	 = -g -c -Wall
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


# clean up
clean:
	rm -f $(OBJS) $(OUT)
