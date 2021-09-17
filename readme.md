
# HeteroFuzz
Fuzz Testing to Detect Platform Dependent Divergence for Heterogeneous Application (FSE 2021)

## Summary of HeteroFuzz 
As specialized hardware accelerators like FPGAs become a prominent part of the current computing landscape, software applications are increasingly constructed to leverage heterogeneous architectures. Such a trend is already happening in the domain of machine learning and Internet-of-Things (IoT) systems built on edge devices. Yet, debugging and testing methods for heterogeneous applications are currently lacking. These applications may look similar to regular C/C++ code but include hardware synthesis details in terms of preprocessor directives. Therefore, their behavior under heterogeneous architectures may diverge significantly from CPU due to hardware synthesis details. Further, the compilation and hardware simulation cycle takes an enormous amount of time, prohibiting frequent invocations required for fuzz testing. We propose a novel fuzz testing technique, called HeteroFuzz, designed to specifically target heterogeneous applications and to detect platform-dependent divergence. The key essence of HeteroFuzz is that it uses a three-pronged approach to reduce the long latency of repetitively invoking a hardware simulator on a heterogeneous application. First, in addition to monitoring code coverage as a fuzzing guidance mechanism, we analyze synthesis pragmas in kernel code and monitor accelerator-relevant value spectra. Second, we design dynamic probabilistic mutations to increase the chance of hitting divergent behavior under different platforms. Third, we memorize the boundaries of seen kernel inputs and skip HLS simulator invocation if it can expose only redundant divergent behavior. We evaluate HeteroFuzz on seven real-world heterogeneous applications with FPGA kernels. HeteroFuzz is 754X faster in exposing the same set of distinct divergence symptoms than naive fuzzing. Probabilistic mutations contribute to 17.5X speed up than the one without. Selective invocation of HLS simulation contributes to 8.8X speed up than the one without. 
## Team 
This project is developed by Professor [Miryung Kim](http://web.cs.ucla.edu/~miryung/)'s Software Engineering and Analysis Laboratory at UCLA. 
If you encounter any problems, please open an issue or feel free to contact us:

[Qian Zhang](http://web.cs.ucla.edu/~zhangqian/): Postdoctoral researcher, zhangqian@cs.ucla.edu;

[Jiyuan Wang](http://web.cs.ucla.edu/~wangjiyuan): PhD student, wangjiyuan@cs.ucla.edu;

## How to cite 
Please refer to our FSE'21 paper, [Fuzz Testing to Detect Platform Dependent Divergence for Heterogeneous Applications](http://web.cs.ucla.edu/~miryung/Publications/fse2021-heterofuzz.pdf) for more details. 
### Bibtex  
@inproceedings{10.1145/3468264.3468610, author = {Zhang, Qian and Wang, Jiyuan and Kim, Miryung}, title = {HeteroFuzz: Fuzz Testing to Detect Platform Dependent Divergence for Heterogeneous Applications}, year = {2021}, isbn = {9781450385626}, publisher = {Association for Computing Machinery}, address = {New York, NY, USA}, url = {https://doi.org/10.1145/3468264.3468610}, doi = {10.1145/3468264.3468610}, booktitle = {Proceedings of the 29th ACM Joint Meeting on European Software Engineering Conference and Symposium on the Foundations of Software Engineering}, pages = {242–254}, numpages = {13}, keywords = {Fuzz testing, platform-dependent divergence, heterogeneous applications}, location = {Athens, Greece}, series = {ESEC/FSE 2021} }

[DOI Link](https://dl.acm.org/doi/10.1145/3468264.3468610)


## Prerequisites

HeteroFuzz has been tested on Ubuntu 18.04. The following packages are required to be installed. If you are using another operating system, please check those package names accordingly.

```bash
sudo apt-get install gawk git wget tar bzip2 gcc automake autoconf \
    libhpdf-dev libc6-dev autotools-dev bison flex libtool libbz2-dev \
    libpython2.7-dev ghostscript libhpdf-dev libmpfrc++-dev libltdl-dev
```
This tool is built on top of `afl` (https://lcamtuf.coredump.cx/afl/) and `heterorefactor`(https://github.com/heterorefactor/heterorefactor).


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

## Video
You can watch an FSE'21 presentation video [here](https://youtu.be/5lKTFfgdQlM)
## Alternative Package
You can also find our research replication package at [Zenodo](https://zenodo.org/record/5146681#.YTEnzS2ZNaY).
## FAQ 





