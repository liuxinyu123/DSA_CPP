cc = g++ 
CXXFLAGS = -Wall

targets = main
objects = main.o 

$(targets) : $(objects)
	$(cc) -o $(targets) $(objects)

main.o : vector.h

.PHONY:clean
clean:
	rm $(targets) $(objects)
