all: t p

t:
	gcc threadsched.c -o threadSched
	./threadSched
	cat threadRuntimeCFS.txt

p:
	gcc processSched.c -o processSched
