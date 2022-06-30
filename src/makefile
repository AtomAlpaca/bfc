OBJS = main.o preprocessor.o lexer.o

main: $(OBJS)
	g++ $(OBJS) -o bfc

main.o: main.cpp
	g++ -c main.cpp -o main.o
preprocessor.o: preprocessor.h preprocessor.cpp
	g++ -c preprocessor.cpp -o preprocessor.o
lexer.o:
	g++ -c lexer.cpp -o lexer.o

clean:
	rm -rf *.o bfc
