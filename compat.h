/* -*- mode: C; mode: folding; fill-column: 70; -*- */
/* Copyright 2010-2011,  Georgia Institute of Technology, USA. */
/* See COPYING for license. */
#if !defined(COMPAT_HEADER_)
#define COMPAT_HEADER_

#define _FILE_OFFSET_BITS 64
#define _THREAD_SAFE
#define _XOPEN_SOURCE 600
#define _XOPEN_SOURCE_EXTENDED
#define _SVID_SOURCE

#include <cinttypes>

#if defined(_OPENMP)
#define OMP(x) _Pragma(x)
#include <omp.h>
#else
#define OMP(x)
#if defined(__GNUC__)
static int omp_get_thread_num (void) __attribute__((unused));
static int omp_get_num_threads (void) __attribute__((unused));
int omp_get_thread_num (void) { return 0; }
int omp_get_num_threads (void) { return 1; }
#else
static int omp_get_thread_num (void) { return 0; }
static int omp_get_num_threads (void) { return 1; }
#endif
#endif

#if defined(__MTA__)
#define MTA(x) _Pragma(x)
#else
#define MTA(x)
#endif

#endif /* COMPAT_HEADER_ */
