# ERAD-SP 2018 - Introdução à Programação Paralela em Clusters Heterogêneos

## Nbody ##

```
$ cd src
$ make nbody-v3d
$ export OFFLOAD_NODES=10.0.0.4,10.0.0.5,10.0.0.6,10.0.0.7
$ ./nbody-v3d 
```
## Transposition A B ##

```
$ cd src/transpose-ab
```
**Compile** and **run** with **malloc**:
```
$ icc -g -O3 -qopenmp transpose-ab-malloc.c -o transpose-ab-malloc.o
$ ./transpose-ab-malloc.o 45000
```
**Compile** and **run** with **hbw_malloc**:
```
$ icc -g -O3 -qopenmp -lmemkind transpose-ab-hbwmalloc.c -o transpose-ab-hbwmalloc.o
$ ./transpose-ab-hbwmalloc.o 45000
```
