
output: assignment3.o
	g++ assignment3.o -o assignment3 && ./assignment3

assignment3.o: assignment3.cpp
	g++ -c assignment3.cpp

clean:
	rm *.o

run:
	./assignment3
