all: threadSched
	
threadSched:
	gcc threadsched.c -o threadSched
	./threadSched

processSched:
	gcc processSched.c -o processSched
