# eradsp-2018 - Hands-on

On your desktop/workstation, open a terminal or command line console and use the command ssh to login on the Skylake server and KNL Server as user traineeN (N = 01 … 20; please check with the teaching assistant which number has been assigned to you): 
 
```
ssh -X traineeN@SKYLAKE-SERVER 
ssh -X traineeN@KNL-SERVER 
```

After login on each server execute the following line to setup the environment to use Intel Parallel Studio:
```
source /opt/intel/parallel_studio_xe_2018/psxevars.sh intel64
```

# 1. Parallel Architecure 

Execute the following activities on each server (KNL and Skylake):

## 1.1. The utility lscpu shows information about the CPU architecture. Use this utility to obtain the number of cores and threads available on each node of Heterogeneous cluster. 
 
```
lscpu 
```

**How many cores/threads are available?**

## 1.2. The utility numactl maps processes to specific NUMA nodes. Use this utility with the parameter -H to obtain information about the NUMA nodes in the system. 
 
```
numactl -H 
```
**How many numa nodes are available**
 
## 1.3. The utility shows a hierarchical map of key computing elements, such as: NUMA memory nodes, shared caches, processor sockets and processor cores.

```
lstopo
```

**How many levels contains the memory systems? What is the size of each level?**


# 1. Parallel Offload

Execute the following activities on Skylake:
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
