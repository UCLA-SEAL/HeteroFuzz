

This folder contains anonymized code and evaluation for double blind review.
-> applications: this folder has a list of our subjects. Compiling these subjects requires a valid Xilinx Vivado HLS installed.
-> evaluation: this folder contains: (1) summarized reuslts when running our tool on the benchmark programs; and (2) sample outputs/logs/detected divergence behavior.
-> prototype: this is the anonymized prototype of our tool. We made some modifications on the libs (to monitor the value spectra during simulation) that shipped with Vivado installation. Due to copyright issues, for now, we cannot release the modified code in public. We provide our core-function related code in this folder.


To verify the functionality:
1. Kernel-related input identification
2. coverage feedback and accelerator feedback
3. probabilistic mutations
4. selective invocation



