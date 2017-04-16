all:
	cc main.c terminal.c vector.c -I. -lncurses -o kanna

debug:
	cc main.c terminal.c vector.c -I. -lncurses -o kanna -g
