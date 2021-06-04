
# Function Verification
Please note that this tool and all the subjects have dependent on `vivado_hls` envrionment. Here we provide a running example with regular C/C++ code to verify the major functionalities of HeteroFuzz. The usage is the same with Xilinx compiler and C/C++ compiler. The only difference is that without a Xilinx compiler, tool cannot read feedback from FPGA simulation.

## Example Program
To compile and run the example program `hello.c`, type the following commands

```bash
gcc -o hello hello.c
./hello good-seeds/anyseed
```

## Use the tool
To build the tool, type the following commands:
- make: this will make all afl executables
- ./afl-gcc -o hello hello.c: this will instrument the program under test
- ./fuzz good-seeds/ good-outputs/ 10000 hello: this will run this tool on `hello` for 10000 trials.

The generated tests will be saved in the folder `good-outputs`.

## Major Functionality:
- Coverage feedback and accelerator feedback: coverage information will be printed out in terms of a hash value of coverage bitmap; while the accelerator feedback is from FPGA simulation.
3. Probabilistic mutations: In the fuzzing trials, we select the mutations based on their activation probabilities
4. Selective invocation: We selectively invokes the hardware simulation based on the boundaries of input values.


