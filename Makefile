OPCIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++11

program.exe: Jugador.o Cjt_jugadores.o Torneo.o Cjt_torneos.o Cjt_categorias.o program.o
	g++ $(OPCIONS) -o program.exe Jugador.o Cjt_jugadores.o Torneo.o Cjt_torneos.o Cjt_categorias.o program.o

program.o: program.cc
	g++ $(OPCIONS) -c program.cc

Jugador.o: Jugador.cc Jugador.hh
	g++ $(OPCIONS) -c Jugador.cc

Cjt_jugadores.o: Cjt_jugadores.cc Cjt_jugadores.hh
	g++ $(OPCIONS) -c Cjt_jugadores.cc

Torneo.o: Torneo.hh Torneo.cc
	g++ $(OPCIONS) -c Torneo.cc

Cjt_torneos.o: Cjt_torneos.hh Cjt_torneos.cc
	g++ $(OPCIONS) -c Cjt_torneos.cc

Cjt_categorias.o: Cjt_categorias.hh Cjt_categorias.cc
	g++ $(OPCIONS) -c Cjt_categorias.cc

practica.tar: Makefile Jugador.hh Jugador.cc Torneo.hh Torneo.cc Cjt_torneos.cc Cjt_torneos.hh Cjt_jugadores.hh Cjt_jugadores.cc Cjt_categorias.cc Cjt_categorias.hh program.cc html.zip jp_alba.lopez.zip  
	tar -cvf practica.tar *.cc *.hh Makefile html.zip jp_alba.lopez.zip
	
clean: 
	rm -f *.o *.gch *.exe *.tar