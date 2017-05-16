cc = g++ 
CXXFLAGS = -Wall

targets = main
objects = main.o 
header = ./header/* 

$(targets) : $(objects)
	$(cc) -o $(targets) $(objects)

main.o : vector.h vector_impl.h $(header) 


.PHONY:clean
clean:
	rm $(targets) $(objects)
