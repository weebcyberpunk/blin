blin : main.c
	cc main.c -o blin

.PHONY : test clean
# uses the lorem.txt file to test blin
test : blin
	./blin 10 lorem.txt
	cat lorem.txt | ./blin 10
	./blin 20 lorem.txt
	cat lorem.txt | ./blin 20

clean :
	-rm blin
