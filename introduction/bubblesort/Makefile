CC = g++
CXXFLAGS = -Wall

targets = main
objects = main.o

$(targets) : $(objects)
	$(CC) -o $(targets) $(objects)

main.o : bubble.h

.PHONY : clean

clean:
	rm $(targets) $(objects)
