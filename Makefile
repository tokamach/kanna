all:
	cc main.c core.c terminal.c gap_buffer.c vector.c -I. -lncurses -o kanna

debug:
	cc main.c core.c terminal.c gap_buffer.c vector.c -I. -lncurses -o kanna -g

clean:
	rm kanna
