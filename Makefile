blin : main.c
	cc main.c -o blin

.PHONY : test clean
# uses the lorem.txt file to test blin
test : blin
	echo 'TEST WITH FILE SPECIFYING - 10 chars'
	./blin 10 lorem.txt
	echo 'TEST WITH STDIN - 10 chars'
	cat lorem.txt | ./blin 10
	echo 'TEST WITH FILE SPECIFYING - 20 chars'
	./blin 20 lorem.txt
	echo 'TEST WITH STDIN - 20 chars'
	cat lorem.txt | ./blin 20

clean :
	-rm blin
