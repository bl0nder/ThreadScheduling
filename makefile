all: t p

t:
	gcc threadsched.c -o threadSched
	./threadSched

p:
	gcc processSched.c -o processSched
