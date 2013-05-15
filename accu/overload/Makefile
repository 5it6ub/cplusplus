# Makefile template
# $(COMPILE) -> macro definition
# act as a rule for any .o file listed as a source in the "test" rule, and 
# makes each .o file dependent on a file of the same name with a .cpp extension.
# The predefined macro "$<" expands to the full filename of the .cpp file.

COMPILE = g++ -c

test: c++_streams.o
	g++ -o test c++_streams.o
.cpp.o:
	$(COMPILE) $<
clean:
	rm test c++_streams.o

