all: t p

t:
	gcc threadsched.c -o threadSched
	number=1 ; while [[ $$number -le 1 ]] ; do \
		./threadSched ; \
		((number = number + 1)) ; \
	done
	cat threadRuntimeCFS.txt
	cat threadRuntimeFIFO.txt
	cat threadRuntimeRR.txt

p:
	gcc processSched.c -o processSched
