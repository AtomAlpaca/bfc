OBJS = main.o preprocessor.o lexer.o codegen.o fileio.o

main: $(OBJS)
	g++ $(OBJS) -o bfc

main.o: main.cpp
	g++ -c main.cpp -o main.o
preprocessor.o: preprocessor.h preprocessor.cpp
	g++ -c preprocessor.cpp -o preprocessor.o
lexer.o: lexer.h lexer.cpp
	g++ -c lexer.cpp -o lexer.o
codegen.o: codegen.h codegen.cpp
	g++ -c codegen.cpp -o codegen.o
fileio.o: fileio.h fileio.cpp
	g++ -c fileio.cpp -o fileio.o


clean:
	rm -rf *.o bfc
