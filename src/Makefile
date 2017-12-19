gradeSystem: grade.o main.o inquire.o sort.o
	gcc grade.o main.o inquire.o sort.o -o gradeSystem
grade.o: grade.cpp
	gcc -c grade.cpp
main.o: main.cpp
	gcc -c main.cpp
sort.o: sort.cpp
	gcc -c sort.cpp
inquire.o: inquire.cpp
	gcc -c inquire.cpp
clean:
	rm -r *.o