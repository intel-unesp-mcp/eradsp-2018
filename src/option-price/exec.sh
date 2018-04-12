#!/bin/bash
#time numactl -m 0,1,2,3 ./am_call_vp
#time numactl -m 0,1,2,3 ./matrix.icc
#time numactl -m 0,1,2,3 ./matrix.icc
#time numactl -m 0,1,2,3 ./matrix.icc
#time numactl -m 0,1,2,3 ./matrix.icc
time numactl -m 4,5,6,7 ./am_call_vp
#time numactl -m 4,5,6,7 ./matrix.icc
#time numactl -m 4,5,6,7 ./matrix.icc
#time numactl -m 4,5,6,7 ./matrix.icc
#time numactl -m 4,5,6,7 ./matrix.icc

