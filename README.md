# MIPS-project

MIPS simulator written to conform to the following spec https://github.com/m8pple/arch2-2018-cw

Simulator written in `C++` and testbench written in `bash`

Open source parser, used to convert assembly files to binary files for the testbench, was made by Olly Larkin.

USAGE:
`make simulator` to build the simulator

`make testbench` to build the testbench and convert the assembly files to binary files

`make run_tests` to build the simulator and then run the testbench on the simulator

`make clean` to remove the testbench, simulator, and parser executables.
