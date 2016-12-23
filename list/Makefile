cc = g++
CXXFLAGS = -Wall

targets = main
objects = main.o 
headers = ./header/*.h 
$(targets) : $(objects)
	$(cc) -o $(targets) $(objects)

main.o : list.h list_impl.h $(headers)

.PHONY : clean

clean:
	rm $(targets) $(objects)

