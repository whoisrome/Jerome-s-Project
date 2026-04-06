output: character.o wizard.o engineer.o Warlock.o main.o
	c++ character.o wizard.o engineer.o Warlock.o main.o -o output

main.o: main.cpp
	c++ -c main.cpp

character.o: character.cpp character.h
	c++ -c character.cpp

wizard.o: wizard.cpp wizard.h
	c++ -c wizard.cpp

engineer.o: engineer.cpp engineer.h
	c++ -c engineer.cpp

warlock.o: Warlock.cpp warlock.h
	c++ -c warlock.cpp

clean:
	rm *.o



