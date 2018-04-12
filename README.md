# eradsp-2018 - Hands-on

On your desktop/workstation, open a terminal or command line console and use the command ssh to login on the host as user traineeN (N = 01 … 20; please check with the teaching assistant which number has been assigned to you): 
 
$ ssh -X traineeN@SERVER 
 
The utility lscpu shows information about the CPU architecture. Use this utility to obtain the number of cores and threads available on each node of Heterogeneous cluster: 
 
$ lscpu 
 
the utility numactl maps processes to specific NUMA nodes. Use this utility with the parameter -H to obtain information about the NUMA nodes in the system. 
 
[KNL-SERVER]$ numactl -H 
 
The cluster mode of the KNL server we are using has been configured as SNC-4, so cores appear grouped into four nodes with exactly a quarter of the on-platform memory in each node. In addition, our system uses the on-package high bandwidth memory (HBM) configured as ﬂat mode, which adds four more NUMA nodes with a quarter of the HBM assigned for each node. 

lstopo

Offload

icc -qopenmp testHW.c -o testHW
export OFFLOAD_NODES=10.0.0.5

./testHW 
Running on host: phi01.ncc.unesp.br
Running on target: phi05
export OFFLOAD_NODES=10.0.0.6

./testHW 
Running on host: phi01.ncc.unesp.br
Running on target: phi06

option price

transposition

compiling openmp

execute program

put target pragma on simple application




