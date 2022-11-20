all: threadSched processSched

threadSched:
	gcc threadsched.c -o threadSched

processSched:
	gcc processSched.c -o processSched
	./processSched
