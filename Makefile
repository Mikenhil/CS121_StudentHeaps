studentheap: date.o address.o main.o
	g++ date.o address.o student.o main.o -o studentheap

date.o: date.cpp date.h
	g++ -c date.cpp

address.o: address.cpp address.h
	g++ -c address.cpp

student.o: student.cpp student.h
	g++ -c student.cpp

main.o: main.cpp date.h address.h student.h
	g++ -c main.cpp

build:
	make date.o
	make address.o
	make student.o
	make main.o
	make studentheap

run: studentheap
	./studentheap

br: 
	make build
	make run

simpleclean:
	rm *.o

clean:
	rm studentheap
	rm *.o
