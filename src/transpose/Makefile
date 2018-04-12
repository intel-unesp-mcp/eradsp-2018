CXX = icpc
#CXXFLAGS = -g -O3 -fopenmp -DMETHOD=2 -opt-report5 -lmemkind -xhost
CXXFLAGS = -g -O3 -fopenmp -DMETHOD=2 -qopt-report5 -lmemkind -xhost -qopt-prefetch=5
#CXXFLAGS = -g -O3 -fopenmp -DMETHOD=2 -qopt-report5 -lmemkind -xAVX2 -qopt-prefetch=5
#icc -xCORE-AVX512 -O3 -qopt-prefetch=5 -vec-threshold0 -S -qopt-report-embed indirect.c 

MICFLAGS  = 
HOSTFLAGS = 

CPUOBJECTS = \
	Transpose-CPU.o\
	Main-CPU.o

MICOBJECTS = \
	Transpose-MIC.o\
	Main-MIC.o

TARGETS = runme-CPU runme-MIC

%-CPU.o: %.cc
	$(CXX) $(CXXFLAGS) $(HOSTFLAGS) -DDOUBLE -c -o $@ $^

%-MIC.o: %.cc
	$(CXX) $(CXXFLAGS) $(MICFLAGS) -DDOUBLE -c -o $@ $^

%-CPU: $(CPUOBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ *-CPU.o

%-MIC: $(MICOBJECTS)
	$(CXX) $(CXXFLAGS)  -o $@ *-MIC.o

all: $(TARGETS)

clean: 
	rm -f $(TARGETS) $(CPUOBJECTS) $(MICOBJECTS)
