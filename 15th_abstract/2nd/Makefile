Human: main.o Englishman.o Chinese.o
	g++ -o $@ $^

%.o: %.cpp
	g++ -c -o $@ $<

clean:
	rm -f *.o Human *.cpp~ *.h~ Makefile~
