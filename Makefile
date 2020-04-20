main: main.o linked.o stack.o search.o time.o shortway.o timetable.o
	gcc -o main main.o linked.o stack.o search.o time.o shortway.o timetable.o
main.o: main.c
	gcc -c main.c
linked.o : linked.c
	gcc -c linked.c
stack.o : stack.c
	gcc -c stack.c
search.o : search.c
	gcc -c search.c
time.o : time.c
	gcc -c time.c
shortway.o : shortway.c
	gcc -c shortway.c
timetable.o : timetable.c
	gcc -c timetable.c
clean :
	rm -f main main.o linked.o stack.o time.o shortway.o timetable.o
