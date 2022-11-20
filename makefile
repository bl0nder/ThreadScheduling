all: t p

t:
	gcc threadsched.c -o threadSched

p:
	gcc processSched.c -o processSched
	./processSched
