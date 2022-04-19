blin : main.c
	cc main.c -o blin

.PHONY : test install uninstall clean 
# uses the lorem.txt file to test blin
test : blin
	./blin 10 lorem.txt
	cat lorem.txt | ./blin 10
	./blin 20 lorem.txt
	cat lorem.txt | ./blin 20

install : blin blin.1
	install -Dm755 blin /usr/bin/blin
	install -Dm644 blin.1 /usr/share/man/man1/blin.1

uninstall :
	rm -f /usr/bin/blin /usr/share/man/man1/blin.1

clean :
	-rm blin
