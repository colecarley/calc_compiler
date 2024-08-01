compiler.o: main.o lexer.o token.o node.o parser.o interpreter.o
	gcc -o compiler main.o lexer.o token.o node.o parser.o interpreter.o

main.o: main.c ./lexer/lexer.h ./token/token.h ./node/node.h ./parser/parser.h
	gcc -c main.c 

token.o: ./token/token.c ./token/token.h
	gcc -c ./token/token.c

lexer.o: ./lexer/lexer.c ./lexer/lexer.h ./token/token.h
	gcc -c ./lexer/lexer.c

node.o: ./node/node.c ./node/node.h
	gcc -c ./node/node.c

parser.o: ./parser/parser.c ./parser/parser.h ./node/node.h
	gcc -c ./parser/parser.c

interpreter.o: ./interpreter/interpreter.c ./interpreter/interpreter.h ./node/node.h
	gcc -c ./interpreter/interpreter.c

clean:
	rm -rf *.o compiler