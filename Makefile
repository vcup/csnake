.c.o:
	gcc -c $<

snake:main.o snake.o food.o painter.o operate.o
	gcc -lcurses -o $@ $?
	mv snake bin/
	rm -f $?
