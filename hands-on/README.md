# ERAD-SP 2018 - Hands-on

On your desktop/workstation, open a terminal or command line console and use the command ssh to login on the Skylake server and KNL Server as user traineeN (N = 01 … 20; please check with the teaching assistant which number has been assigned to you): 
 
```
$ ssh -X traineeN@SKYLAKE-SERVER 
$ ssh -X traineeN@KNL-SERVER 
```

After login on each server execute the following line to setup the environment to use Intel Parallel Studio:
```
$ source /opt/intel/parallel_studio_xe_2018/psxevars.sh intel64
```
**Clone** Hands-on repository:
```
$ git clone https://github.com/intel-unesp-mcp/eradsp-2018.git && cd eradsp-2018
```

# 1. Parallel Architecure 

Execute the following activities on each server (KNL and Skylake):

## 1.1. lscpu

The utility lscpu shows information about the CPU architecture. Use this utility to obtain the number of cores and threads available on each node of Heterogeneous cluster. 
 
```
$ lscpu 
```

**How many cores/threads are available?**

## 1.2. numactl 

The utility numactl maps processes to specific NUMA nodes. Use this utility with the parameter -H to obtain information about the NUMA nodes in the system. 
 
```
$ numactl -H 
```
**How many numa nodes are available ?**
 
## 1.3. lstopo 

The utility lstopo shows a hierarchical map of key computing elements, such as: NUMA memory nodes, shared caches, processor sockets and processor cores.

```
$ lstopo
```

**How many levels contains the memory systems? What is the size of each level?**

## 1.4 Option Price

**Change** to Option Price dir:
```
$ cd src/option-price
```

**Compile** Option Price:
```
$ make am_call_vp
```

**Run** application on **KNL** and on **Skylake**:
```
$ time ./am_call_vp 
```

**What execution presents the best execution time?**


## 1.5 Transposition

**Change** to Transposition dir:
```
$ cd ../transpose
```

**Compile** application:
```
$ make runme-CPU
```

Run transposition using **MCDRAM** on **KNL**:

```
$ numactl -m 0,1,2,3 ./runme-CPU 30000 50
```

**Run** transposition using **DRAM** on **KNL**
```
$ numactl -m 4,5,6,7 ./runme-CPU 30000 50
```

**Run** transposition on Skylake:
```
$ ./runme-CPU 30000 50
```

**What execution presents the best execution time?**

# 2. Offload

Execute the following activities on Skylake:

## 2.1 Test with Offload:

**Change** to src dir:
```
$ cd ..
```

**Compile** application using **OpenMP**:

```
$ icc -qopenmp testHW.c -o testHW
```

**Setup** the list of nodes to receive offloaded code:

```
$ export OFFLOAD_NODES=10.0.0.6
```

**Run** the application:

```
$ ./testHW 
```

**Change** the list of nodes to receive offloaded code and **run** the application again:

```
$ export OFFLOAD_NODES=10.0.0.7
$ ./testHW 
```

## 2.2 Test with Offload Data Transfer

**Execute** program without offload:

```
$ unset OFFLOAD_NODES
$ cd matrix/linux
$ make clean ; make icc
$ ./matrix.icc 
```

**Put** entire code of function **multiply5** inside the following block:
```
  #pragma omp target device(0) map(a[0:NUM][0:NUM]) map(b[0:NUM][0:NUM]) map(c[0:NUM][0:NUM])
  {
      function void multiply5 (line 323)
  } 
```

**Execute** program with offload:

```
$ export OFFLOAD_NODES=10.0.0.5,10.0.0.6,10.0.0.7,10.0.0.4
$ make clean ; make icc
$ export OFFLOAD_REPORT=2
$ ./matrix.icc 
```

**How many bytes was transfered from host do device?**
