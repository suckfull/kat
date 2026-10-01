CC = cc
CFLAGS = -std=c99 -Wall -Wextra -O2

kat: kat.c
	$(CC) $(CFLAGS) kat.c -o kat

install: kat
	install -Dm755 kat /usr/local/bin/kat

uninstall:
	rm -f /usr/local/bin/kat

clean:
	rm -f kat

.PHONY: install uninstall clean
