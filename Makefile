CXXFLAGS = -fopenmp -g -Wall -Drestrict=__restrict__ -O3 -DNDEBUG -ffast-math -DGRAPH_GENERATOR_MPI # -g -pg
LDFLAGS = -fopenmp -g # -g -pg
MPICXX = /Users/ghos167/builds/mpich/bin/mpicxx

all: graph500_mpi_simple 

GENERATOR_SOURCES = graph_generator.cc make_graph.cc splittable_mrg.cc prng.cc utils.cc
SOURCES = main.cc oned_csr.cc mpi_utils.cc validate.cc onesided.cc
HEADERS = common.h oned_csr.h redistribute.h mpi_workarounds.h onesided.h

graph500_mpi_simple: bfs_simple.cc $(SOURCES) $(HEADERS) $(GENERATOR_SOURCES)
	$(MPICXX) $(CXXFLAGS) $(LDFLAGS) -o graph500_mpi_simple bfs_simple.cc $(SOURCES) $(GENERATOR_SOURCES) -lm

clean:
	-rm -f graph500_mpi_* *.o *.a 
