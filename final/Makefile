OPT = -Wall
OXV = -std=c++98
REL = main.o Record.o ReportGenerator.o Control.o View.o

final: $(REL)
	g++ $(OPT) $(OXV) -o final $(REL)
main.o:	main.cc Control.h
	g++ $(OPT) $(OXV) -c main.cc
ReportGenerator.o: ReportGenerator.cc ReportGenerator.h Property.h
	g++ $(OPT) $(OXV) -c ReportGenerator.cc
Record.o: Record.cc Record.h
	g++ $(OPT) $(OXV) -c Record.cc
#
Control.o: Control.cc Control.h View.h
		g++ $(OPT) $(OXV) -c Control.cc
#
View.o: View.cc View.h ReportGenerator.h
		g++ $(OPT) $(OXV) -c View.cc

clean:
	rm -f *.o final
