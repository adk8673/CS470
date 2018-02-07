CC=gcc

proc_fan : proc_fan.o function_library.o;
	$(CC) -o proc_fan proc_fan.o function_library.o

%.o : %.c;
	$(CC) -c  $<  -o $@

testsim : testsim.o;
	$(CC) testsim.o -o testsim
