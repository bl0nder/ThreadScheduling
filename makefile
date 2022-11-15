all: threadSched
	
threadSched:
	gcc threadsched.c -o threadSched

processSched:
	gcc processSched.c -o processSched
