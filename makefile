program:
	g++ -I "./include" -c ./src/ogrenci.cpp -o ./lib/ogrenci.o
	g++ -I "./include" -c ./src/dugum.cpp -o ./lib/dugum.o
	g++ -I "./include" -c ./src/sinif.cpp -o ./lib/sinif.o
	g++ -I "./include" -c ./src/okul.cpp -o ./lib/okul.o
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o
	g++ ./lib/main.o ./lib/ogrenci.o ./lib/dugum.o ./lib/sinif.o ./lib/okul.o -o./bin/program
	./bin/program.exe
