CC=gcc
PROC_FAN_OBJECTS=proc_fan.o function_library.o
TESTSIM_OBJECTS=testsim.o

default: proc_fan testsim

%.o: %.c
	$(CC) -c $< -o $@

proc_fan: $(PROC_FAN_OBJECTS) 
	$(CC) -o proc_fan proc_fan.o function_library.o

testsim: $(TESTSIM_OBJECTS)
	$(CC) testsim.o -o testsim

clean:
	-rm -f $(PROC_FAN_OBJECTS)
	-rm -f $(TESTSIM_OBJECTS)
	-rm -f proc_fan
	-rm -f testsim
