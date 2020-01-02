simulator:
	g++ src/simulator.cpp src/types.cpp src/memory.cpp src/R_type.cpp src/I_type.cpp src/J_type.cpp src/decode.cpp -o bin/mips_simulator 


run_tests: simulator 
	./bin/mips_testbench ./bin/mips_simulator 

testbench: parser
	chmod u+x mips_testbench
	cp mips_testbench ./bin/
	

clean:
	rm bin/mips_simulator 
	rm bin/mips_testbench
	rm -f -rf parser/src/*.o parser/bin

parser: main.o parser.o instructionList.o
	mkdir -p parser/bin
	g++ parser/src/main.o parser/src/parser.o parser/src/instructionList.o -o parser/bin/parser

main.o: parser/src/main.cpp
	g++ --std=c++11 -c parser/src/main.cpp -o parser/src/main.o

parser.o: parser/src/parser.cpp parser/src/parser.hpp
	g++ --std=c++11 -c parser/src/parser.cpp -o parser/src/parser.o

instructionList.o: parser/src/instructionList.cpp parser/src/instructionList.hpp
	g++ --std=c++11 -c parser/src/instructionList.cpp -o parser/src/instructionList.o

