cc = g++
CXXFLAGS = -Wall

targets = main
objects = main.o 

$(targets) : $(objects)
	$(cc) -o $(targets) $(objects)

main.o : array.h

.PHONY : clean

clean: 
	rm $(targets) $(objects)
