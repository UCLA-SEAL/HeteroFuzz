
# HeteroFuzz Artifacts
Artifact submission for FSE2021

## Prerequisites

HeteroFuzz has been tested on Ubuntu 18.04. The following packages are required to be installed. If you are using another operating system, please check those package names accordingly.

```bash
sudo apt-get install gawk git wget tar bzip2 gcc automake autoconf \
    libhpdf-dev libc6-dev autotools-dev bison flex libtool libbz2-dev \
    libpython2.7-dev ghostscript libhpdf-dev libmpfrc++-dev libltdl-dev
```

To compile, instrument, and run the subjects, a *valid* Xilinx Vivado license is required to do FPGA synthesis and simulation. Please ensure Xilinx toolchain is in your `PATH` environment variable, and you can run `vivado` and `vivado_hls` in your terminal.

Alternatively, we provide a running example with a downgraded version of HeteroFuzz without FPGA simulation. This can be used to verify the major functionalities of HeteroFuzz without Xilinx environments. Please follow the instructions in *prototype* folder.

## How to build the HeteroFuzz tool 
```
cd prototype; make
```

## How to use this tool
We basically follow the usage of AFL here: https://lcamtuf.coredump.cx/afl/README.txt. Aftering running *afl-gcc* to instrument the program under test, type the following command in terminal:

```bash
./fuzz path-seeds/ path-outputs/ max_trials test-program
```

## Project Folder Structure
- *Prototype*: this is the anonymized prototype of our tool. We made some modifications on the libs (to monitor the value spectra during simulation) that shipped with Vivado installation. Due to copyright issues, for now, we cannot release the modified code in public. We provide our core-function related code in this folder.
- *applications*: this folder has a list of our subjects. Compiling these subjects requires a valid Xilinx Vivado HLS installed.
- *log-samples*: this folder contains: (1) summarized reuslts when running our tool on the subject programs; and (2) sample outputs/logs/detected divergence behavior.


To verify the functionality:
1. Kernel-related input identification
2. coverage feedback and accelerator feedback
3. probabilistic mutations
4. selective invocation



