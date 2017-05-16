cc = g++
CXXFLAGS = -Wall

headers = ./header/*
targets = main
objects = main.o

$(targets) : $(objects)
	$(cc) -o $(targets) $(objects)

main.o : singlelist.h singlelist_impl.h $(headers) 

.PHONY : clean

clean:
	rm $(targets) $(objects)



