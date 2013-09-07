/*
 *  Copyright (C) 2011, 2012, 2013 Michael Hofmann
 *  
 *  This file is part of ScaFaCoS.
 *  
 *  ScaFaCoS is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  
 *  ScaFaCoS is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser Public License for more details.
 *  
 *  You should have received a copy of the GNU Lesser Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *  

 *  
 *  SL - Sorting Library, michael <dot> hofmann <at> informatik <dot> tu-chemnitz <dot> de
 */


#ifndef __SL_FRONT_XQ_A0_H__
#define __SL_FRONT_XQ_A0_H__

#ifdef SL_USE_MPI
 #include <mpi.h>
#endif /* SL_USE_MPI */

#define SL_PROTO(_f_)  _f_

#include "config_fmm_sort.h"


/* standard (SL) integer data type */
#define front_xq_a0_sl_int_type_c             SL_INTEGER_C
#define front_xq_a0_sl_int_type_mpi           SL_INTEGER_MPI
#define front_xq_a0_sl_int_size_mpi           1
#define front_xq_a0_sl_int_type_fmt           SL_INTEGER_FMT


/* key section */
#define front_xq_a0_sl_key_type_c             INTEGER_C
#define front_xq_a0_sl_key_type_mpi           INTEGER_MPI
#define front_xq_a0_sl_key_size_mpi           1

#define front_xq_a0_sl_key_integer
#define front_xq_a0_sl_key_type_fmt           INTEGER_FMT

extern INTEGER_C key_mask;

#define front_xq_a0_sl_key_purify(_k_)        (_k_ & key_mask)


/* data section */
#define front_xq_a0_SL_DATA0                  /* xyz */
#define front_xq_a0_sl_data0_type_c           REAL_C
#define front_xq_a0_sl_data0_size_c           3
#define front_xq_a0_sl_data0_type_mpi         REAL_MPI
#define front_xq_a0_sl_data0_size_mpi         3

#define front_xq_a0_SL_DATA1                  /* q */
#define front_xq_a0_sl_data1_type_c           REAL_C
#define front_xq_a0_sl_data1_size_c           1
#define front_xq_a0_sl_data1_type_mpi         REAL_MPI
#define front_xq_a0_sl_data1_size_mpi         1

#undef front_xq_a0_SL_DATA2                   /* scr */
#define front_xq_a0_sl_data2_type_c           INTEGER_C
#define front_xq_a0_sl_data2_size_c           1
#define front_xq_a0_sl_data2_type_mpi         INTEGER_MPI
#define front_xq_a0_sl_data2_size_mpi         1

#undef front_xq_a0_SL_DATA3                   /* addr */
#define front_xq_a0_sl_data3_type_c           INTEGER_C
#define front_xq_a0_sl_data3_size_c           1
#define front_xq_a0_sl_data3_type_mpi         INTEGER_MPI
#define front_xq_a0_sl_data3_size_mpi         1

#define front_xq_a0_MC_ALLTOALL_INT_2STEP_THRESHOLD  1024




#if defined(MSEG_ROOT) && !defined(front_xq_a0_MSEG_ROOT)
# define front_xq_a0_MSEG_ROOT  MSEG_ROOT
#endif

#if defined(MSEG_BORDER_UPDATE_REDUCTION) && !defined(front_xq_a0_MSEG_BORDER_UPDATE_REDUCTION)
# define front_xq_a0_MSEG_BORDER_UPDATE_REDUCTION  MSEG_BORDER_UPDATE_REDUCTION
#endif

#if defined(MSEG_DISABLE_BEST_CHOICE) && !defined(front_xq_a0_MSEG_DISABLE_BEST_CHOICE)
# define front_xq_a0_MSEG_DISABLE_BEST_CHOICE  MSEG_DISABLE_BEST_CHOICE
#endif

#if defined(MSEG_DISABLE_MINMAX) && !defined(front_xq_a0_MSEG_DISABLE_MINMAX)
# define front_xq_a0_MSEG_DISABLE_MINMAX  MSEG_DISABLE_MINMAX
#endif

#if defined(MSEG_ENABLE_OPTIMZED_LOWHIGH) && !defined(front_xq_a0_MSEG_ENABLE_OPTIMZED_LOWHIGH)
# define front_xq_a0_MSEG_ENABLE_OPTIMZED_LOWHIGH  MSEG_ENABLE_OPTIMZED_LOWHIGH
#endif

#if defined(MSEG_FORWARD_ONLY) && !defined(front_xq_a0_MSEG_FORWARD_ONLY)
# define front_xq_a0_MSEG_FORWARD_ONLY  MSEG_FORWARD_ONLY
#endif

#if defined(MSEG_INFO) && !defined(front_xq_a0_MSEG_INFO)
# define front_xq_a0_MSEG_INFO  MSEG_INFO
#endif

#if defined(MSEG_TRACE_IF) && !defined(front_xq_a0_MSEG_TRACE_IF)
# define front_xq_a0_MSEG_TRACE_IF  MSEG_TRACE_IF
#endif






/* override SL_USE_MPI from sl_config.h */
#ifdef SL_USE_MPI_IGNORE
# undef SL_USE_MPI
#endif

#ifdef SL_USE_MPI_FORCE
# ifndef SL_USE_MPI
#  define SL_USE_MPI
# endif
#endif

/* override SL_USE_OMP from sl_config.h */
#ifdef SL_USE_OMP_IGNORE
# undef SL_USE_OMP
#endif

#ifdef SL_USE_OMP_FORCE
# ifndef SL_USE_OMP
#  define SL_USE_OMP
# endif
#endif


#ifndef front_xq_a0_SL_INDEX
# undef front_xq_a0_SL_PACKED_INDEX
#endif


/* if no special datatype for (sl default) integer ... */
#ifndef front_xq_a0_sl_int_type_c
  /* ... use a default one */
# define front_xq_a0_sl_int_type_c               long      /* sl_macro */
# undef front_xq_a0_sl_int_type_mpi
# define front_xq_a0_sl_int_type_mpi             MPI_LONG  /* sl_macro */
# undef front_xq_a0_sl_int_size_mpi
# define front_xq_a0_sl_int_size_mpi             1         /* sl_macro */
# undef front_xq_a0_sl_int_type_fmt
# define front_xq_a0_sl_int_type_fmt             "ld"      /* sl_macro */
#else
  /* ... use the given one and check whether an mpi-type is present and required */
# ifdef SL_USE_MPI
#  if !defined(front_xq_a0_sl_int_type_mpi) || !defined(front_xq_a0_sl_int_size_mpi)
#   error "front_xq_a0_sl_int_type_mpi and/or front_xq_a0_sl_int_size_mpi missing"
#  endif
# endif
# ifndef front_xq_a0_sl_int_type_fmt
#  error "front_xq_a0_sl_int_type_fmt macro is missing, using d as default"
#  define front_xq_a0_sl_int_type_fmt  "d"
# endif
#endif


/* if no special datatype for (intern) weight ... */
#ifndef front_xq_a0_sl_weight_type_c
 /* ... use (sl default) integer */
# define front_xq_a0_sl_weight_type_c             front_xq_a0_sl_int_type_c    /* sl_macro */
# undef front_xq_a0_sl_weight_type_mpi
# define front_xq_a0_sl_weight_type_mpi           front_xq_a0_sl_int_type_mpi  /* sl_macro */
# undef front_xq_a0_sl_weight_size_mpi
# define front_xq_a0_sl_weight_size_mpi           front_xq_a0_sl_int_size_mpi  /* sl_macro */
# undef front_xq_a0_sl_weight_type_fmt
# define front_xq_a0_sl_weight_type_fmt           front_xq_a0_sl_int_type_fmt  /* sl_macro */
# undef front_xq_a0_sl_weight_intequiv
# define front_xq_a0_sl_weight_intequiv                            /* sl_macro */
#else
  /* ... use the given one and check whether an mpi-type is present and required */
# ifdef SL_USE_MPI
#  if !defined(front_xq_a0_sl_weight_type_mpi) || !defined(front_xq_a0_sl_weight_size_mpi)
#   error "front_xq_a0_sl_weight_type_mpi and/or front_xq_a0_sl_weight_size_mpi missing"
#  endif
# endif
# ifndef front_xq_a0_sl_weight_type_fmt
#  error "front_xq_a0_sl_weight_type_fmt macro is missing, using f as default"
#  define front_xq_a0_sl_weight_type_fmt  "f"
# endif
#endif


/* if no special datatype for indexes ... */
#ifndef front_xq_a0_sl_index_type_c
 /* ... use the primary integer type */
# define front_xq_a0_sl_index_type_c             front_xq_a0_sl_int_type_c
# undef front_xq_a0_sl_index_type_mpi
# define front_xq_a0_sl_index_type_mpi           front_xq_a0_sl_int_type_mpi
# undef front_xq_a0_sl_index_size_mpi
# define front_xq_a0_sl_index_size_mpi           front_xq_a0_sl_int_size_mpi
# undef front_xq_a0_sl_index_type_fmt
# define front_xq_a0_sl_index_type_fmt           front_xq_a0_sl_int_type_fmt
#else
  /* ... use the given one and check whether an mpi-type is present and required */
# ifdef SL_USE_MPI
#  if !defined(front_xq_a0_sl_index_type_mpi) || !defined(front_xq_a0_sl_index_size_mpi)
#   error "front_xq_a0_sl_index_type_mpi and/or front_xq_a0_sl_index_size_mpi missing"
#  endif
# endif
# ifndef front_xq_a0_sl_index_type_fmt
#  error "front_xq_a0_sl_index_type_fmt macro is missing, using d as default"
#  define front_xq_a0_sl_index_type_fmt  "d"
# endif
#endif


/* default pure keys */
#ifndef front_xq_a0_sl_key_pure_type_c
# define front_xq_a0_sl_key_pure_type_c          front_xq_a0_sl_key_type_c  /* sl_macro */
#endif
#ifndef front_xq_a0_sl_key_pure_type_mpi
# define front_xq_a0_sl_key_pure_type_mpi        front_xq_a0_sl_key_type_mpi  /* sl_macro */
#endif
#ifndef front_xq_a0_sl_key_pure_size_mpi
# define front_xq_a0_sl_key_pure_size_mpi        front_xq_a0_sl_key_size_mpi  /* sl_macro */
#endif
#ifndef front_xq_a0_sl_key_pure_type_fmt
# ifdef front_xq_a0_sl_key_type_fmt
#  define front_xq_a0_sl_key_pure_type_fmt       front_xq_a0_sl_key_type_fmt  /* sl_macro */
# endif
#endif

#ifndef front_xq_a0_sl_key_purify
 /* key val -> key val */
 #define front_xq_a0_sl_key_purify(k)            (k)  /* sl_macro */
#endif
#ifndef front_xq_a0_sl_key_get_pure
 /* key component pointer -> key val pointer */
 #define front_xq_a0_sl_key_get_pure(k)          (k)  /* sl_macro */
#endif
#ifndef front_xq_a0_sl_key_set_pure
 /* key component pointer and key val */
 #define front_xq_a0_sl_key_set_pure(k, p)       (*(k) = p)  /* sl_macro */
#endif


/* default pure key comparisons */
#ifndef front_xq_a0_sl_key_pure_cmp_eq
 #define front_xq_a0_sl_key_pure_cmp_eq(k0, k1)  ((k0) == (k1))  /* sl_macro */
#endif
#ifndef front_xq_a0_sl_key_pure_cmp_ne
 #define front_xq_a0_sl_key_pure_cmp_ne(k0, k1)  ((k0) != (k1))  /* sl_macro */
#endif
#ifndef front_xq_a0_sl_key_pure_cmp_lt
 #define front_xq_a0_sl_key_pure_cmp_lt(k0, k1)  ((k0) < (k1))  /* sl_macro */
#endif
#ifndef front_xq_a0_sl_key_pure_cmp_le
 #define front_xq_a0_sl_key_pure_cmp_le(k0, k1)  ((k0) <= (k1))  /* sl_macro */
#endif
#ifndef front_xq_a0_sl_key_pure_cmp_gt
 #define front_xq_a0_sl_key_pure_cmp_gt(k0, k1)  ((k0) > (k1))  /* sl_macro */
#endif
#ifndef front_xq_a0_sl_key_pure_cmp_ge
 #define front_xq_a0_sl_key_pure_cmp_ge(k0, k1)  ((k0) >= (k1))  /* sl_macro */
#endif


/* default key comparisons */
#ifndef front_xq_a0_sl_key_cmp_eq
 #define front_xq_a0_sl_key_cmp_eq(k0, k1)       (front_xq_a0_sl_key_pure_cmp_eq(front_xq_a0_sl_key_purify(k0), front_xq_a0_sl_key_purify(k1)))  /* sl_macro */
#endif
#ifndef front_xq_a0_sl_key_cmp_ne
 #define front_xq_a0_sl_key_cmp_ne(k0, k1)       (front_xq_a0_sl_key_pure_cmp_ne(front_xq_a0_sl_key_purify(k0), front_xq_a0_sl_key_purify(k1)))  /* sl_macro */
#endif
#ifndef front_xq_a0_sl_key_cmp_lt
 #define front_xq_a0_sl_key_cmp_lt(k0, k1)       (front_xq_a0_sl_key_pure_cmp_lt(front_xq_a0_sl_key_purify(k0), front_xq_a0_sl_key_purify(k1)))  /* sl_macro */
#endif
#ifndef front_xq_a0_sl_key_cmp_le
 #define front_xq_a0_sl_key_cmp_le(k0, k1)       (front_xq_a0_sl_key_pure_cmp_le(front_xq_a0_sl_key_purify(k0), front_xq_a0_sl_key_purify(k1)))  /* sl_macro */
#endif
#ifndef front_xq_a0_sl_key_cmp_gt
 #define front_xq_a0_sl_key_cmp_gt(k0, k1)       (front_xq_a0_sl_key_pure_cmp_gt(front_xq_a0_sl_key_purify(k0), front_xq_a0_sl_key_purify(k1)))  /* sl_macro */
#endif
#ifndef front_xq_a0_sl_key_cmp_ge
 #define front_xq_a0_sl_key_cmp_ge(k0, k1)       (front_xq_a0_sl_key_pure_cmp_ge(front_xq_a0_sl_key_purify(k0), front_xq_a0_sl_key_purify(k1)))  /* sl_macro */
#endif


/* default random key */
#ifdef front_xq_a0_sl_key_integer
# if !defined(front_xq_a0_sl_key_val_srand) || !defined(front_xq_a0_sl_key_val_rand) || !defined(front_xq_a0_sl_key_val_rand_minmax)
#  undef front_xq_a0_sl_key_val_srand
#  undef front_xq_a0_sl_key_val_rand
#  undef front_xq_a0_sl_key_val_rand_minmax
#  define front_xq_a0_sl_key_val_srand(_s_)                 z_srand(_s_)                                        /* sl_macro */
#  define front_xq_a0_sl_key_val_rand()                     ((front_xq_a0_sl_key_pure_type_c) z_rand())                     /* sl_macro */
#  define front_xq_a0_sl_key_val_rand_minmax(_min_, _max_)  ((front_xq_a0_sl_key_pure_type_c) z_rand_minmax(_min_, _max_))  /* sl_macro */
# endif
#endif


/* disable data components on request */
/* DATAX_TEMPLATE_BEGIN */
#ifdef front_xq_a0_SL_DATA0_IGNORE
# undef front_xq_a0_SL_DATA0
#endif
#ifdef front_xq_a0_SL_DATA1_IGNORE
# undef front_xq_a0_SL_DATA1
#endif
#ifdef front_xq_a0_SL_DATA2_IGNORE
# undef front_xq_a0_SL_DATA2
#endif
#ifdef front_xq_a0_SL_DATA3_IGNORE
# undef front_xq_a0_SL_DATA3
#endif
#ifdef front_xq_a0_SL_DATA4_IGNORE
# undef front_xq_a0_SL_DATA4
#endif
#ifdef front_xq_a0_SL_DATA5_IGNORE
# undef front_xq_a0_SL_DATA5
#endif
#ifdef front_xq_a0_SL_DATA6_IGNORE
# undef front_xq_a0_SL_DATA6
#endif
#ifdef front_xq_a0_SL_DATA7_IGNORE
# undef front_xq_a0_SL_DATA7
#endif
#ifdef front_xq_a0_SL_DATA8_IGNORE
# undef front_xq_a0_SL_DATA8
#endif
#ifdef front_xq_a0_SL_DATA9_IGNORE
# undef front_xq_a0_SL_DATA9
#endif
#ifdef front_xq_a0_SL_DATA10_IGNORE
# undef front_xq_a0_SL_DATA10
#endif
#ifdef front_xq_a0_SL_DATA11_IGNORE
# undef front_xq_a0_SL_DATA11
#endif
#ifdef front_xq_a0_SL_DATA12_IGNORE
# undef front_xq_a0_SL_DATA12
#endif
#ifdef front_xq_a0_SL_DATA13_IGNORE
# undef front_xq_a0_SL_DATA13
#endif
#ifdef front_xq_a0_SL_DATA14_IGNORE
# undef front_xq_a0_SL_DATA14
#endif
#ifdef front_xq_a0_SL_DATA15_IGNORE
# undef front_xq_a0_SL_DATA15
#endif
#ifdef front_xq_a0_SL_DATA16_IGNORE
# undef front_xq_a0_SL_DATA16
#endif
#ifdef front_xq_a0_SL_DATA17_IGNORE
# undef front_xq_a0_SL_DATA17
#endif
#ifdef front_xq_a0_SL_DATA18_IGNORE
# undef front_xq_a0_SL_DATA18
#endif
#ifdef front_xq_a0_SL_DATA19_IGNORE
# undef front_xq_a0_SL_DATA19
#endif
/* DATAX_TEMPLATE_END */


/* sl_macro front_xq_a0_sl_elem_weight */


/* disable sl_dataX_weight if there is not weight */
#ifndef front_xq_a0_sl_elem_weight
/* DATAX_TEMPLATE_BEGIN */
# undef front_xq_a0_sl_data0_weight
# undef front_xq_a0_sl_data1_weight
# undef front_xq_a0_sl_data2_weight
# undef front_xq_a0_sl_data3_weight
# undef front_xq_a0_sl_data4_weight
# undef front_xq_a0_sl_data5_weight
# undef front_xq_a0_sl_data6_weight
# undef front_xq_a0_sl_data7_weight
# undef front_xq_a0_sl_data8_weight
# undef front_xq_a0_sl_data9_weight
# undef front_xq_a0_sl_data10_weight
# undef front_xq_a0_sl_data11_weight
# undef front_xq_a0_sl_data12_weight
# undef front_xq_a0_sl_data13_weight
# undef front_xq_a0_sl_data14_weight
# undef front_xq_a0_sl_data15_weight
# undef front_xq_a0_sl_data16_weight
# undef front_xq_a0_sl_data17_weight
# undef front_xq_a0_sl_data18_weight
# undef front_xq_a0_sl_data19_weight
/* DATAX_TEMPLATE_END */
#endif


/* disable front_xq_a0_sl_elem_weight if the weight component is missing */
/* DATAX_TEMPLATE_BEGIN */
#if defined(front_xq_a0_sl_data0_weight) && !defined(front_xq_a0_SL_DATA0)
# undef front_xq_a0_sl_elem_weight
#endif
#if defined(front_xq_a0_sl_data1_weight) && !defined(front_xq_a0_SL_DATA1)
# undef front_xq_a0_sl_elem_weight
#endif
#if defined(front_xq_a0_sl_data2_weight) && !defined(front_xq_a0_SL_DATA2)
# undef front_xq_a0_sl_elem_weight
#endif
#if defined(front_xq_a0_sl_data3_weight) && !defined(front_xq_a0_SL_DATA3)
# undef front_xq_a0_sl_elem_weight
#endif
#if defined(front_xq_a0_sl_data4_weight) && !defined(front_xq_a0_SL_DATA4)
# undef front_xq_a0_sl_elem_weight
#endif
#if defined(front_xq_a0_sl_data5_weight) && !defined(front_xq_a0_SL_DATA5)
# undef front_xq_a0_sl_elem_weight
#endif
#if defined(front_xq_a0_sl_data6_weight) && !defined(front_xq_a0_SL_DATA6)
# undef front_xq_a0_sl_elem_weight
#endif
#if defined(front_xq_a0_sl_data7_weight) && !defined(front_xq_a0_SL_DATA7)
# undef front_xq_a0_sl_elem_weight
#endif
#if defined(front_xq_a0_sl_data8_weight) && !defined(front_xq_a0_SL_DATA8)
# undef front_xq_a0_sl_elem_weight
#endif
#if defined(front_xq_a0_sl_data9_weight) && !defined(front_xq_a0_SL_DATA9)
# undef front_xq_a0_sl_elem_weight
#endif
#if defined(front_xq_a0_sl_data10_weight) && !defined(front_xq_a0_SL_DATA10)
# undef front_xq_a0_sl_elem_weight
#endif
#if defined(front_xq_a0_sl_data11_weight) && !defined(front_xq_a0_SL_DATA11)
# undef front_xq_a0_sl_elem_weight
#endif
#if defined(front_xq_a0_sl_data12_weight) && !defined(front_xq_a0_SL_DATA12)
# undef front_xq_a0_sl_elem_weight
#endif
#if defined(front_xq_a0_sl_data13_weight) && !defined(front_xq_a0_SL_DATA13)
# undef front_xq_a0_sl_elem_weight
#endif
#if defined(front_xq_a0_sl_data14_weight) && !defined(front_xq_a0_SL_DATA14)
# undef front_xq_a0_sl_elem_weight
#endif
#if defined(front_xq_a0_sl_data15_weight) && !defined(front_xq_a0_SL_DATA15)
# undef front_xq_a0_sl_elem_weight
#endif
#if defined(front_xq_a0_sl_data16_weight) && !defined(front_xq_a0_SL_DATA16)
# undef front_xq_a0_sl_elem_weight
#endif
#if defined(front_xq_a0_sl_data17_weight) && !defined(front_xq_a0_SL_DATA17)
# undef front_xq_a0_sl_elem_weight
#endif
#if defined(front_xq_a0_sl_data18_weight) && !defined(front_xq_a0_SL_DATA18)
# undef front_xq_a0_sl_elem_weight
#endif
#if defined(front_xq_a0_sl_data19_weight) && !defined(front_xq_a0_SL_DATA19)
# undef front_xq_a0_sl_elem_weight
#endif
/* DATAX_TEMPLATE_END */


/* verify that the flex component is the last (FIXME: only if packed is on?) */
/* sl_macro front_xq_a0_FLECKS_GUARD */
/* DATAX_TEMPLATE_BEGIN */
#ifdef front_xq_a0_SL_DATA0
# ifdef front_xq_a0_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef front_xq_a0_sl_data0_flex
#   define front_xq_a0_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef front_xq_a0_SL_DATA1
# ifdef front_xq_a0_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef front_xq_a0_sl_data1_flex
#   define front_xq_a0_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef front_xq_a0_SL_DATA2
# ifdef front_xq_a0_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef front_xq_a0_sl_data2_flex
#   define front_xq_a0_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef front_xq_a0_SL_DATA3
# ifdef front_xq_a0_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef front_xq_a0_sl_data3_flex
#   define front_xq_a0_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef front_xq_a0_SL_DATA4
# ifdef front_xq_a0_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef front_xq_a0_sl_data4_flex
#   define front_xq_a0_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef front_xq_a0_SL_DATA5
# ifdef front_xq_a0_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef front_xq_a0_sl_data5_flex
#   define front_xq_a0_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef front_xq_a0_SL_DATA6
# ifdef front_xq_a0_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef front_xq_a0_sl_data6_flex
#   define front_xq_a0_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef front_xq_a0_SL_DATA7
# ifdef front_xq_a0_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef front_xq_a0_sl_data7_flex
#   define front_xq_a0_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef front_xq_a0_SL_DATA8
# ifdef front_xq_a0_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef front_xq_a0_sl_data8_flex
#   define front_xq_a0_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef front_xq_a0_SL_DATA9
# ifdef front_xq_a0_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef front_xq_a0_sl_data9_flex
#   define front_xq_a0_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef front_xq_a0_SL_DATA10
# ifdef front_xq_a0_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef front_xq_a0_sl_data10_flex
#   define front_xq_a0_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef front_xq_a0_SL_DATA11
# ifdef front_xq_a0_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef front_xq_a0_sl_data11_flex
#   define front_xq_a0_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef front_xq_a0_SL_DATA12
# ifdef front_xq_a0_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef front_xq_a0_sl_data12_flex
#   define front_xq_a0_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef front_xq_a0_SL_DATA13
# ifdef front_xq_a0_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef front_xq_a0_sl_data13_flex
#   define front_xq_a0_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef front_xq_a0_SL_DATA14
# ifdef front_xq_a0_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef front_xq_a0_sl_data14_flex
#   define front_xq_a0_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef front_xq_a0_SL_DATA15
# ifdef front_xq_a0_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef front_xq_a0_sl_data15_flex
#   define front_xq_a0_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef front_xq_a0_SL_DATA16
# ifdef front_xq_a0_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef front_xq_a0_sl_data16_flex
#   define front_xq_a0_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef front_xq_a0_SL_DATA17
# ifdef front_xq_a0_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef front_xq_a0_sl_data17_flex
#   define front_xq_a0_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef front_xq_a0_SL_DATA18
# ifdef front_xq_a0_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef front_xq_a0_sl_data18_flex
#   define front_xq_a0_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef front_xq_a0_SL_DATA19
# ifdef front_xq_a0_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef front_xq_a0_sl_data19_flex
#   define front_xq_a0_FLECKS_GUARD
#  endif
# endif
#endif
/* DATAX_TEMPLATE_END */






#ifdef sort_radix_width_default

 #ifndef sort_radix_width_max
  #define sort_radix_width_max       sort_radix_width_default
 #endif

#else /* sort_radix_width_default */

  #ifndef sort_radix_width_max
   #define sort_radix_width_max      12
  #endif

  #define sort_radix_width_default   sort_radix_width_max

#endif /* sort_radix_width_default */

#ifndef sort_radix_db_width_default
# define sort_radix_db_width_default  sort_radix_width_default
#endif

#ifndef sort_radix_ip_width_default
# define sort_radix_ip_width_default  sort_radix_width_default
#endif

#ifndef sort_radix_iter_width_default
# define sort_radix_iter_width_default  sort_radix_width_default
#endif

/* radix-sort thresholds */
#ifndef sort_radix_threshold
# define sort_radix_threshold  256
#endif

#ifndef sort_radix_ip_threshold
# define sort_radix_ip_threshold  sort_radix_threshold
#endif

#ifndef sort_radix_db_threshold
# define sort_radix_db_threshold  sort_radix_threshold
#endif

#ifndef sort_radix_iter_threshold
# define sort_radix_iter_threshold  sort_radix_threshold
#endif


#ifndef ncopy_auto_loop_border_o4o
 #define ncopy_auto_loop_border_o4o  2
#endif

#ifndef ncopy_auto_loop_border_a4o
 #define ncopy_auto_loop_border_a4o  2
#endif

#ifndef nmove_auto_loop_border_o4o
 #define nmove_auto_loop_border_o4o  2
#endif

#ifndef nmove_auto_loop_border_a4o
 #define nmove_auto_loop_border_a4o  2
#endif


/* configure tuneable */
#ifdef SL_TUNEABLE

#if 0
 /* sort_radix_threshold_rec */
 extern int tuneable_sort_radix_threshold_rec;

 /* sort_radix_threshold_iter */
 extern int tuneable_sort_radix_threshold_iter;

#endif
#endif






#ifndef SL_RTI_TID_DECLARED
# define SL_RTI_TID_DECLARED

enum rti_tid
{
  /* src/base_mpi/base_mpi.c */
  rti_tid_mpi_merge2,
  rti_tid_mpi_merge2_find,
  rti_tid_mpi_merge2_moveright,
  rti_tid_mpi_merge2_exchange,
  rti_tid_mpi_merge2_moveleft,
  rti_tid_mpi_merge2_local,
  rti_tid_mpi_mergek_equal,
  rti_tid_mpi_mergek_equal_while,
  rti_tid_mpi_mergek_equal_while_merge2,
  rti_tid_mpi_mergek_sorted,
  rti_tid_mpi_mergek_sorted_while,
  rti_tid_mpi_mergek_sorted_while_check,
  rti_tid_mpi_mergek_sorted_while_oddeven,
  rti_tid_mpi_mergek_sorted2,
  rti_tid_mpi_mergek_sorted2_while,
  rti_tid_mpi_mergek_sorted2_while_check,
  rti_tid_mpi_mergek_sorted2_while_oddeven,
  rti_tid_mpi_mergek,
  rti_tid_mpi_mergek_equalike,
  rti_tid_mpi_mergek_while,
  rti_tid_mpi_mergek_while_check,
  rti_tid_mpi_mergek_while_oddeven,
  rti_tid_mpi_partition_exact_generic,
  rti_tid_mpi_partition_exact_generic_select,
  rti_tid_mpi_partition_exact_generic_rcounts,
  rti_tid_mpi_partition_exact_radix_ngroups,
  rti_tid_mpi_partition_exact_radix_ngroups_pconds,
  rti_tid_mpi_partition_exact_radix_ngroups_idxin,
  rti_tid_mpi_partition_exact_radix_ngroups_up,
  rti_tid_mpi_partition_exact_radix_ngroups_down,
  rti_tid_mpi_partition_exact_radix_ngroups_down_select,
  rti_tid_mpi_partition_exact_radix_ngroups_down_alltoall,
  rti_tid_mpi_partition_exact_radix_ngroups_down_x2suby,
  rti_tid_mpi_partition_exact_radix_ngroups_down_merge,
  rti_tid_mpi_partition_exact_radix_ngroups_idxout,
  rti_tid_mpi_partition_exact_radix_ngroups_idxout_loop,
  rti_tid_mpi_partition_exact_radix_ngroups_idxout_alltoall,
  rti_tid_mpi_partition_exact_radix_2groups,
  rti_tid_mpi_partition_exact_radix_2groups_pconds,
  rti_tid_mpi_partition_exact_radix_2groups_select1st,
  rti_tid_mpi_partition_exact_radix_2groups_x2suby,
  rti_tid_mpi_partition_exact_radix_2groups_alltoall,
  rti_tid_mpi_partition_exact_radix_2groups_select2nd,
  rti_tid_mpi_partition_exact_radix_2groups_subx2y,
  rti_tid_mpi_partition_sample,
  rti_tid_mpi_partition_sample_select,
  rti_tid_mpi_partition_sample_rcounts,
  rti_tid_mpi_select_exact_generic,
  rti_tid_mpi_select_exact_generic_sync_init,
  rti_tid_mpi_select_exact_generic_sync_exit,
  rti_tid_mpi_select_exact_generic_while,
  rti_tid_mpi_select_exact_generic_while_check,
  rti_tid_mpi_select_exact_generic_while_check_bins,
  rti_tid_mpi_select_exact_generic_while_check_bins_local,
  rti_tid_mpi_select_exact_generic_while_check_bins_global,
  rti_tid_mpi_select_exact_generic_while_check_round1,
  rti_tid_mpi_select_exact_generic_while_check_pre,
  rti_tid_mpi_select_exact_generic_while_check_part,
  rti_tid_mpi_select_exact_generic_while_check_part_root,
  rti_tid_mpi_select_exact_generic_while_check_final,
  rti_tid_mpi_select_exact_generic_while_check_final_root,
  rti_tid_mpi_select_exact_generic_while_check_post,


  rti_tid_all,
  rti_tid_sort_insert,
  rti_tid_sort_quick,
  rti_tid_sort_radix,
  rti_tid_sort_radix_iter,
  rti_tid_sort_permute_forward,
  rti_tid_sort_permute_backward,

  rti_tid_mpi_all,

  rti_tid_mpi_merge2_fe,
  rti_tid_mpi_merge2_xchg,

  rti_tid_mpi_mergek_merge2,

  rti_tid_mpi_splitk_exact,
  rti_tid_mpi_splitk_exact_init,
  rti_tid_mpi_splitk_exact_loop,
  rti_tid_mpi_splitk_exact_loop_walk,
  rti_tid_mpi_splitk_exact_loop_flow,
  rti_tid_mpi_splitk_exact_loop_flow_gather,
  rti_tid_mpi_splitk_exact_loop_flow_create,
  rti_tid_mpi_splitk_exact_loop_flow_reduce,
  rti_tid_mpi_splitk_exact_loop_flow_unbalance,
  rti_tid_mpi_splitk_exact_loop_dist,
  rti_tid_mpi_splitk_exact_loop_dist_pre,
  rti_tid_mpi_splitk_exact_loop_dist_a2av,

  rti_tid_mpi_splitk_dummy,
  rti_tid_mpi_splitk_dummy_init,
  rti_tid_mpi_splitk_dummy_loop,

  rti_tid_mpi_partition_joink,
  rti_tid_mpi_partition_joink_init,
  rti_tid_mpi_partition_joink_loop,
  rti_tid_mpi_partition_joink_loop_flow,
  rti_tid_mpi_partition_joink_loop_dist,

  rti_tid_mpi_select_radix_final,

  rti_tid_mpi_partition_radix2,
  rti_tid_mpi_partition_radix2_sync,
  rti_tid_mpi_partition_radix2_sync_init,
  rti_tid_mpi_partition_radix2_sync_exit,
/*  rti_tid_mpi_partition_radix2_while,
  rti_tid_mpi_partition_radix2_while_count,
  rti_tid_mpi_partition_radix2_while_allreduce,
  rti_tid_mpi_partition_radix2_while_round1,
  rti_tid_mpi_partition_radix2_while_round1_allgather,
  rti_tid_mpi_partition_radix2_while_exscan,
  rti_tid_mpi_partition_radix2_while_check,
  rti_tid_mpi_partition_radix2_while_check_pre,
  rti_tid_mpi_partition_radix2_while_check_classes,
  rti_tid_mpi_partition_radix2_while_check_final,
  rti_tid_mpi_partition_radix2_while_check_post,*/
  rti_tid_mpi_partition_radix2_final,

  rti_tid_mpi_sample_complete,
  rti_tid_mpi_sample_complete_gather,
  rti_tid_mpi_sample_complete_detect,
  rti_tid_mpi_sample_complete_bcast,

  rti_tid_mpi_select_qs,
  rti_tid_mpi_select_qs_pre,
  rti_tid_mpi_select_qs_loop,
  rti_tid_mpi_select_qs_part,
  rti_tid_mpi_select_qs_reduce_sizes,
  rti_tid_mpi_select_qs_area,
  rti_tid_mpi_select_qs_pivot_new,
  rti_tid_mpi_select_qs_pivot_gather,
  rti_tid_mpi_select_qs_pivot_detect,

  rti_tid_mpi_sample_select_qs,
  rti_tid_mpi_sample_select_qs_pre,
  rti_tid_mpi_sample_select_qs_select,

  rti_tid_mpi_sample_precise,
  rti_tid_mpi_sample_precise_llec,
  rti_tid_mpi_sample_precise_gather,
  rti_tid_mpi_sample_precise_detect,

  rti_tid_mpi_sample_permutation,

  rti_tid_mpi_sm_simple,
  rti_tid_mpi_sm_simple_sort,
  rti_tid_mpi_sm_simple_merge,

  rti_tids
};

#endif /* SL_RTI_TID_DECLARED */






#define front_xq_a0_SPEC_TLOC

typedef front_xq_a0_sl_int_type_c front_xq_a0_spec_int_t;

typedef int front_xq_a0_spec_proc_t;

#define front_xq_a0_SPEC_LOC_NONE   -1
#ifdef SL_USE_MPI
# define front_xq_a0_SPEC_PROC_NONE  MPI_PROC_NULL
#else
# define front_xq_a0_SPEC_PROC_NONE  -1
#endif

typedef void *front_xq_a0_spec_tloc_data_t;
typedef void *front_xq_a0_spec_tproc_data_t;

struct front_xq_a0__elements_t;

typedef struct front_xq_a0__elements_t *front_xq_a0_spec_elem_buf_t;

typedef struct front_xq_a0__elements_t front_xq_a0_spec_elem_t;

typedef front_xq_a0_sl_int_type_c front_xq_a0_spec_elem_index_t;

#define front_xq_a0_spec_elem_set_n(_e_, _n_)     front_xq_a0_elem_set_size((_e_), (_n_))
#define front_xq_a0_spec_elem_get_n(_e_)          front_xq_a0_elem_get_size((_e_))
#define front_xq_a0_spec_elem_set_nmax(_e_, _n_)  front_xq_a0_elem_set_max_size((_e_), (_n_))
#define front_xq_a0_spec_elem_get_nmax(_e_)       front_xq_a0_elem_get_max_size((_e_))

#define front_xq_a0_spec_elem_set_buf(_e_, _b_)   *(_e_) = *(_b_)
#define front_xq_a0_spec_elem_get_buf(_e_)        (_e_)

#define front_xq_a0_spec_elem_copy_at(_se_, _sat_, _de_, _dat_) \
  elem_copy_at((_se_), (_sat_), (_de_), (_dat_))

#define front_xq_a0_spec_elem_exchange_at(_s0_, _s0at_, _s1_, _s1at_, _t_) \
  elem_xchange_at((_s0_), (_s0at_), (_s1_), (_s1at_), (_t_))






/* tproc count */

/* sp_macro front_xq_a0_SPEC_DECLARE_TPROC_COUNT_DB */
#define front_xq_a0_SPEC_DECLARE_TPROC_COUNT_DB \
  struct { front_xq_a0_spec_elem_index_t i; front_xq_a0_spec_proc_t p; } spec0cd;

/* sp_macro front_xq_a0_SPEC_DO_TPROC_COUNT_DB */
#define front_xq_a0_SPEC_DO_TPROC_COUNT_DB(_tp_, _tpd_, _b_, _cs_)  do { \
  for (spec0cd.i = 0; spec0cd.i < front_xq_a0_spec_elem_get_n(_b_); ++spec0cd.i) { \
    spec0cd.p = (_tp_)(front_xq_a0_spec_elem_get_buf(_b_), spec0cd.i, _tpd_); \
    if (spec0cd.p == front_xq_a0_SPEC_PROC_NONE) continue; \
    ++(_cs_)[spec0cd.p]; \
  } } while (0)

/* sp_macro front_xq_a0_SPEC_FUNC_TPROC_COUNT_DB */
#define front_xq_a0_SPEC_FUNC_TPROC_COUNT_DB(_name_, _tp_, _s_...) \
_s_ void _name_##_tproc_count_db(front_xq_a0_spec_elem_t *s, front_xq_a0_spec_tproc_data_t tproc_data, int *counts) \
{ \
  front_xq_a0_SPEC_DECLARE_TPROC_COUNT_DB \
  front_xq_a0_SPEC_DO_TPROC_COUNT_DB(_tp_, tproc_data, s, counts); \
}

/* sp_macro front_xq_a0_SPEC_DECLARE_TPROC_COUNT_IP */
#define front_xq_a0_SPEC_DECLARE_TPROC_COUNT_IP \
  struct { front_xq_a0_spec_elem_index_t i, t; front_xq_a0_spec_proc_t p; } spec0ci;

/* sp_macro front_xq_a0_SPEC_DO_TPROC_COUNT_IP */
#define front_xq_a0_SPEC_DO_TPROC_COUNT_IP(_tp_, _tpd_, _b_, _cs_)  do { \
  spec0ci.t = 0; \
  for (spec0ci.i = 0; spec0ci.i < front_xq_a0_spec_elem_get_n(_b_); ++spec0ci.i) { \
    spec0ci.p = (_tp_)(front_xq_a0_spec_elem_get_buf(_b_), spec0ci.i, _tpd_); \
    if (spec0ci.p == front_xq_a0_SPEC_PROC_NONE) continue; \
    ++(_cs_)[spec0ci.p]; \
    if (spec0ci.t < spec0ci.i) front_xq_a0_spec_elem_copy_at((_b_), spec0ci.i, (_b_), spec0ci.t); \
    ++spec0ci.t; \
  } \
  front_xq_a0_spec_elem_set_n(_b_, spec0ci.t); \
} while (0)

/* sp_macro front_xq_a0_SPEC_FUNC_TPROC_COUNT_IP */
#define front_xq_a0_SPEC_FUNC_TPROC_COUNT_IP(_name_, _tp_, _s_...) \
_s_ void _name_##_tproc_count_ip(front_xq_a0_spec_elem_t *s, front_xq_a0_spec_tproc_data_t tproc_data, int *counts) \
{ \
  front_xq_a0_SPEC_DECLARE_TPROC_COUNT_IP \
  front_xq_a0_SPEC_DO_TPROC_COUNT_IP(_tp_, tproc_data, s, counts); \
}


/* tproc_mod count */

/* sp_macro front_xq_a0_SPEC_DECLARE_TPROC_MOD_COUNT_DB */
#define front_xq_a0_SPEC_DECLARE_TPROC_MOD_COUNT_DB \
  struct { front_xq_a0_spec_elem_index_t i; front_xq_a0_spec_proc_t p; } spec1cd;

/* sp_macro front_xq_a0_SPEC_DO_TPROC_MOD_COUNT_DB */
#define front_xq_a0_SPEC_DO_TPROC_MOD_COUNT_DB(_tp_, _tpd_, _b_, _cs_)  do { \
  for (spec1cd.i = 0; spec1cd.i < front_xq_a0_spec_elem_get_n(_b_); ++spec1cd.i) { \
    spec1cd.p = (_tp_)(front_xq_a0_spec_elem_get_buf(_b_), spec1cd.i, _tpd_, NULL); \
    if (spec1cd.p == front_xq_a0_SPEC_PROC_NONE) continue; \
    ++(_cs_)[spec1cd.p]; \
  } } while (0)

/* sp_macro front_xq_a0_SPEC_FUNC_TPROC_MOD_COUNT_DB */
#define front_xq_a0_SPEC_FUNC_TPROC_MOD_COUNT_DB(_name_, _tp_, _s_...) \
_s_ void _name_##_tproc_mod_count_db(front_xq_a0_spec_elem_t *s, front_xq_a0_spec_tproc_data_t tproc_data, int *counts) \
{ \
  front_xq_a0_SPEC_DECLARE_TPROC_MOD_COUNT_DB \
  front_xq_a0_SPEC_DO_TPROC_MOD_COUNT_DB(_tp_, tproc_data, s, counts); \
}

/* sp_macro front_xq_a0_SPEC_DECLARE_TPROC_MOD_COUNT_IP */
#define front_xq_a0_SPEC_DECLARE_TPROC_MOD_COUNT_IP \
  struct { front_xq_a0_spec_elem_index_t i, t; front_xq_a0_spec_proc_t p; } spec1ci;

/* sp_macro front_xq_a0_SPEC_DO_TPROC_MOD_COUNT_IP */
#define front_xq_a0_SPEC_DO_TPROC_MOD_COUNT_IP(_tp_, _tpd_, _b_, _cs_)  do { \
  spec1ci.t = 0; \
  for (spec1ci.i = 0; spec1ci.i < front_xq_a0_spec_elem_get_n(_b_); ++spec1ci.i) { \
    spec1ci.p = (_tp_)(front_xq_a0_spec_elem_get_buf(_b_), spec1ci.i, _tpd_, NULL); \
    if (spec1ci.p == front_xq_a0_SPEC_PROC_NONE) continue; \
    ++(_cs_)[spec1ci.p]; \
    if (spec1ci.t < spec1ci.i) front_xq_a0_spec_elem_copy_at((_b_), spec1ci.i, (_b_), spec1ci.t); \
    ++spec1ci.t; \
  } \
  front_xq_a0_spec_elem_set_n(_b_, spec1ci.t); \
} while (0)

/* sp_macro front_xq_a0_SPEC_FUNC_TPROC_MOD_COUNT_IP */
#define front_xq_a0_SPEC_FUNC_TPROC_MOD_COUNT_IP(_name_, _tp_, _s_...) \
_s_ void _name_##_tproc_mod_count_ip(front_xq_a0_spec_elem_t *s, front_xq_a0_spec_tproc_data_t tproc_data, int *counts) \
{ \
  front_xq_a0_SPEC_DECLARE_TPROC_MOD_COUNT_IP \
  front_xq_a0_SPEC_DO_TPROC_MOD_COUNT_IP(_tp_, tproc_data, s, counts); \
}


/* tprocs count */

/* sp_macro front_xq_a0_SPEC_DECLARE_TPROCS_COUNT_DB */
#define front_xq_a0_SPEC_DECLARE_TPROCS_COUNT_DB \
  struct { front_xq_a0_spec_elem_index_t i; front_xq_a0_spec_int_t j, n; } spec2cd;

/* sp_macro front_xq_a0_SPEC_DO_TPROCS_COUNT_DB */
#define front_xq_a0_SPEC_DO_TPROCS_COUNT_DB(_tp_, _tpd_, _b_, _cs_, _ps_)  do { \
  for (spec2cd.i = 0; spec2cd.i < front_xq_a0_spec_elem_get_n(_b_); ++spec2cd.i) { \
    spec2cd.n = (_tp_)(front_xq_a0_spec_elem_get_buf(_b_), spec2cd.i, (_tpd_), (_ps_)); \
    for (spec2cd.j = 0; spec2cd.j < spec2cd.n; ++spec2cd.j) ++(_cs_)[(_ps_)[spec2cd.j]]; \
  } } while (0)

/* sp_macro front_xq_a0_SPEC_FUNC_TPROCS_COUNT_DB */
#define front_xq_a0_SPEC_FUNC_TPROCS_COUNT_DB(_name_, _tp_, _s_...) \
_s_ void _name_##_tprocs_count_db(front_xq_a0_spec_elem_t *s, front_xq_a0_spec_tproc_data_t tproc_data, int *counts, front_xq_a0_spec_proc_t *procs) \
{ \
  front_xq_a0_SPEC_DECLARE_TPROCS_COUNT_DB \
  front_xq_a0_SPEC_DO_TPROCS_COUNT_DB(_tp_, tproc_data, s, counts, procs); \
}

/* sp_macro front_xq_a0_SPEC_DECLARE_TPROCS_COUNT_IP */
#define front_xq_a0_SPEC_DECLARE_TPROCS_COUNT_IP \
  struct { front_xq_a0_spec_elem_index_t i, t; front_xq_a0_spec_int_t j, n; } spec2ci;

/* sp_macro front_xq_a0_SPEC_DO_TPROCS_COUNT_IP */
#define front_xq_a0_SPEC_DO_TPROCS_COUNT_IP(_tp_, _tpd_, _b_, _cs_, _ps_)  do { \
  spec2ci.t = 0; \
  for (spec2ci.i = 0; spec2ci.i < front_xq_a0_spec_elem_get_n(_b_); ++spec2ci.i) { \
    spec2ci.n = (_tp_)(front_xq_a0_spec_elem_get_buf(_b_), spec2ci.i, (_tpd_), (_ps_)); \
    if (spec2ci.n <= 0) continue; \
    for (spec2ci.j = 0; spec2ci.j < spec2ci.n; ++spec2ci.j) ++(_cs_)[(_ps_)[spec2ci.j]]; \
    if (spec2ci.t < spec2ci.i) front_xq_a0_spec_elem_copy_at((_b_), spec2ci.i, (_b_), spec2ci.t); \
    ++spec2ci.t; \
  } \
  front_xq_a0_spec_elem_set_n(_b_, spec2ci.t); \
} while (0)

/* sp_macro front_xq_a0_SPEC_FUNC_TPROCS_COUNT_IP */
#define front_xq_a0_SPEC_FUNC_TPROCS_COUNT_IP(_name_, _tp_, _s_...) \
_s_ void _name_##_tprocs_count_ip(front_xq_a0_spec_elem_t *s, front_xq_a0_spec_tproc_data_t tproc_data, int *counts, front_xq_a0_spec_proc_t *procs) \
{ \
  front_xq_a0_SPEC_DECLARE_TPROCS_COUNT_IP \
  front_xq_a0_SPEC_DO_TPROCS_COUNT_IP(_tp_, tproc_data, s, counts, procs); \
}


/* tprocs_mod count */

/* sp_macro front_xq_a0_SPEC_DECLARE_TPROCS_MOD_COUNT_DB */
#define front_xq_a0_SPEC_DECLARE_TPROCS_MOD_COUNT_DB \
  struct { front_xq_a0_spec_elem_index_t i; front_xq_a0_spec_int_t j, n; } spec3cd;

/* sp_macro front_xq_a0_SPEC_DO_TPROCS_MOD_COUNT_DB */
#define front_xq_a0_SPEC_DO_TPROCS_MOD_COUNT_DB(_tp_, _tpd_, _b_, _cs_, _ps_)  do { \
  for (spec3cd.i = 0; spec3cd.i < front_xq_a0_spec_elem_get_n(_b_); ++spec3cd.i) \
  { \
    spec3cd.n = (_tp_)(front_xq_a0_spec_elem_get_buf(_b_), spec3cd.i, (_tpd_), (_ps_), NULL); \
    for (spec3cd.j = 0; spec3cd.j < spec3cd.n; ++spec3cd.j) ++(_cs_)[(_ps_)[spec3cd.j]]; \
  } } while (0)

/* sp_macro front_xq_a0_SPEC_FUNC_TPROCS_MOD_COUNT_DB */
#define front_xq_a0_SPEC_FUNC_TPROCS_MOD_COUNT_DB(_name_, _tp_, _s_...) \
_s_ void _name_##_tprocs_mod_count_db(front_xq_a0_spec_elem_t *s, front_xq_a0_spec_tproc_data_t tproc_data, int *counts, front_xq_a0_spec_proc_t *procs) \
{ \
  front_xq_a0_SPEC_DECLARE_TPROCS_MOD_COUNT_DB \
  front_xq_a0_SPEC_DO_TPROCS_MOD_COUNT_DB(_tp_, tproc_data, s, counts, procs); \
}

/* sp_macro front_xq_a0_SPEC_DECLARE_TPROCS_MOD_COUNT_IP */
#define front_xq_a0_SPEC_DECLARE_TPROCS_MOD_COUNT_IP \
  struct { front_xq_a0_spec_elem_index_t i, t; front_xq_a0_spec_int_t j, n; } spec3ci;

/* sp_macro front_xq_a0_SPEC_DO_TPROCS_MOD_COUNT_IP */
#define front_xq_a0_SPEC_DO_TPROCS_MOD_COUNT_IP(_tp_, _tpd_, _b_, _cs_, _ps_)  do { \
  spec3ci.t = 0; \
  for (spec3ci.i = 0; spec3ci.i < front_xq_a0_spec_elem_get_n(_b_); ++spec3ci.i) { \
    spec3ci.n = (_tp_)(front_xq_a0_spec_elem_get_buf(_b_), spec3ci.i, (_tpd_), (_ps_), NULL); \
    if (spec3ci.n <= 0) continue; \
    for (spec3ci.j = 0; spec3ci.j < spec3ci.n; ++spec3ci.j) ++(_cs_)[(_ps_)[spec3ci.j]]; \
    if (spec3ci.t < spec3ci.i) front_xq_a0_spec_elem_copy_at((_b_), spec3ci.i, (_b_), spec3ci.t); \
    ++spec3ci.t; \
  } \
  front_xq_a0_spec_elem_set_n(_b_, spec3ci.t); \
} while (0)

/* sp_macro front_xq_a0_SPEC_FUNC_TPROCS_MOD_COUNT_IP */
#define front_xq_a0_SPEC_FUNC_TPROCS_MOD_COUNT_IP(_name_, _tp_, _s_...) \
_s_ void _name_##_tprocs_mod_count_ip(front_xq_a0_spec_elem_t *s, front_xq_a0_spec_tproc_data_t tproc_data, int *counts, front_xq_a0_spec_proc_t *procs) \
{ \
  front_xq_a0_SPEC_DECLARE_TPROCS_MOD_COUNT_IP \
  front_xq_a0_SPEC_DO_TPROCS_MOD_COUNT_IP(_tp_, tproc_data, s, counts, procs); \
}


/* tproc rearrange */

/* sp_macro front_xq_a0_SPEC_DECLARE_TPROC_REARRANGE_DB */
#define front_xq_a0_SPEC_DECLARE_TPROC_REARRANGE_DB \
  struct { front_xq_a0_spec_elem_index_t i; front_xq_a0_spec_proc_t p; } spec0d;

/* sp_macro front_xq_a0_SPEC_DO_TPROC_REARRANGE_DB */
#define front_xq_a0_SPEC_DO_TPROC_REARRANGE_DB(_tp_, _tpd_, _sb_, _db_, _ds_)  do { \
  for (spec0d.i = 0; spec0d.i < front_xq_a0_spec_elem_get_n(_sb_); ++spec0d.i) { \
    spec0d.p = (_tp_)(front_xq_a0_spec_elem_get_buf(_sb_), spec0d.i, _tpd_); \
    if (spec0d.p == front_xq_a0_SPEC_PROC_NONE) continue; \
    front_xq_a0_spec_elem_copy_at((_sb_), spec0d.i, (_db_), (_ds_)[spec0d.p]); \
    ++(_ds_)[spec0d.p]; \
  } } while (0)

/* sp_macro front_xq_a0_SPEC_FUNC_TPROC_REARRANGE_DB */
#define front_xq_a0_SPEC_FUNC_TPROC_REARRANGE_DB(_name_, _tp_, _s_...) \
_s_ void _name_##_tproc_rearrange_db(front_xq_a0_spec_elem_t *s, front_xq_a0_spec_elem_t *d, front_xq_a0_spec_tproc_data_t tproc_data, int *displs) \
{ \
  front_xq_a0_SPEC_DECLARE_TPROC_REARRANGE_DB \
  front_xq_a0_SPEC_DO_TPROC_REARRANGE_DB(_tp_, tproc_data, s, d, displs); \
}

/* sp_macro front_xq_a0_SPEC_DECLARE_TPROC_REARRANGE_IP */
#define front_xq_a0_SPEC_DECLARE_TPROC_REARRANGE_IP \
  struct { front_xq_a0_spec_elem_index_t e, i, j; front_xq_a0_spec_proc_t p, np; } spec0i;

/* sp_macro front_xq_a0_SPEC_DO_TPROC_REARRANGE_IP */
#define front_xq_a0_SPEC_DO_TPROC_REARRANGE_IP(_tp_, _tpd_, _b_, _xb_, _ds_, _cs_, _n_)  do { \
  for (spec0i.e = 0, spec0i.i = 0; spec0i.i < (_n_); ++spec0i.i) { \
    spec0i.e += (_cs_)[spec0i.i]; \
    spec0i.j = (_ds_)[spec0i.i]; \
    while (spec0i.j < spec0i.e) { \
      spec0i.p = (_tp_)(front_xq_a0_spec_elem_get_buf(_b_), spec0i.j, _tpd_); \
      while (spec0i.p != spec0i.i) { \
        spec0i.np = (_tp_)(front_xq_a0_spec_elem_get_buf(_b_), (_ds_)[spec0i.p], _tpd_); \
        if (spec0i.np != spec0i.p) front_xq_a0_spec_elem_exchange_at((_b_), (_ds_)[spec0i.p], (_b_), spec0i.j, (_xb_)); \
        ++(_ds_)[spec0i.p]; \
        spec0i.p = spec0i.np; \
      } \
      ++spec0i.j; \
    } \
  } } while (0)

/* sp_macro front_xq_a0_SPEC_FUNC_TPROC_REARRANGE_IP */
#define front_xq_a0_SPEC_FUNC_TPROC_REARRANGE_IP(_name_, _tp_, _s_) \
_s_ void _name_##_tproc_rearrange_ip(front_xq_a0_spec_elem_t *s, front_xq_a0_spec_elem_t *x, front_xq_a0_spec_tproc_data_t tproc_data, int *displs, int *counts, front_xq_a0_spec_int_t n) \
{ \
  front_xq_a0_SPEC_DECLARE_TPROC_REARRANGE_IP \
  front_xq_a0_SPEC_DO_TPROC_REARRANGE_IP(_tp_, tproc_data, s, x, displs, counts, n); \
}


/* tproc_mod rearrange */

/* sp_macro front_xq_a0_SPEC_DECLARE_TPROC_MOD_REARRANGE_DB */
#define front_xq_a0_SPEC_DECLARE_TPROC_MOD_REARRANGE_DB \
  struct { front_xq_a0_spec_elem_index_t i; front_xq_a0_spec_proc_t p; } spec1d;

/* sp_macro front_xq_a0_SPEC_DO_TPROC_MOD_REARRANGE_DB */
#define front_xq_a0_SPEC_DO_TPROC_MOD_REARRANGE_DB(_tp_, _tpd_, _sb_, _db_, _ds_, _ib_)  do { \
  if (_ib_) { \
    for (spec1d.i = 0; spec1d.i < front_xq_a0_spec_elem_get_n(_sb_); ++spec1d.i) { \
      spec1d.p = (_tp_)(front_xq_a0_spec_elem_get_buf(_sb_), spec1d.i, _tpd_, front_xq_a0_spec_elem_get_buf(_ib_)); \
      if (spec1d.p == front_xq_a0_SPEC_PROC_NONE) continue; \
      front_xq_a0_spec_elem_copy_at((_ib_), 0, (_db_), (_ds_)[spec1d.p]); \
      ++(_ds_)[spec1d.p]; \
    } \
  } else { \
    for (spec1d.i = 0; spec1d.i < front_xq_a0_spec_elem_get_n(_sb_); ++spec1d.i) { \
      spec1d.p = (_tp_)(front_xq_a0_spec_elem_get_buf(_sb_), spec1d.i, _tpd_, NULL); \
      if (spec1d.p == front_xq_a0_SPEC_PROC_NONE) continue; \
      front_xq_a0_spec_elem_copy_at((_sb_), spec1d.i, (_db_), (_ds_)[spec1d.p]); \
      ++(_ds_)[spec1d.p]; \
    } \
  } } while (0)

/* sp_macro front_xq_a0_SPEC_FUNC_TPROC_MOD_REARRANGE_DB */
#define front_xq_a0_SPEC_FUNC_TPROC_MOD_REARRANGE_DB(_name_, _tp_, _s_...) \
_s_ void _name_##_tproc_mod_rearrange_db(front_xq_a0_spec_elem_t *s, front_xq_a0_spec_elem_t *d, front_xq_a0_spec_tproc_data_t tproc_data, int *displs, front_xq_a0_spec_elem_t *mod) \
{ \
  front_xq_a0_SPEC_DECLARE_TPROC_MOD_REARRANGE_DB \
  front_xq_a0_SPEC_DO_TPROC_MOD_REARRANGE_DB(_tp_, tproc_data, s, d, displs, mod); \
}

/* sp_macro front_xq_a0_SPEC_DECLARE_TPROC_MOD_REARRANGE_IP */
#define front_xq_a0_SPEC_DECLARE_TPROC_MOD_REARRANGE_IP \
  struct { front_xq_a0_spec_elem_index_t e, i, j; front_xq_a0_spec_proc_t p, np; } spec1i;

/* sp_macro front_xq_a0_SPEC_DO_TPROC_MOD_REARRANGE_IP */
#define front_xq_a0_SPEC_DO_TPROC_MOD_REARRANGE_IP(_tp_, _tpd_, _b_, _xb_, _ds_, _cs_, _n_, _ib_)  do { \
  if (_ib_) { \
    for (spec1i.e = 0, spec1i.i = 0; spec1i.i < (_n_); ++spec1i.i) { \
      spec1i.e += (_cs_)[spec1i.i]; \
      spec1i.j = (_ds_)[spec1i.i]; \
      while (spec1i.j < spec1i.e) { \
        spec1i.p = (_tp_)(front_xq_a0_spec_elem_get_buf(_b_), spec1i.j, _tpd_, front_xq_a0_spec_elem_get_buf(_ib_)); \
        front_xq_a0_spec_elem_copy_at((_ib_), 0, (_b_), spec1i.j); \
        while (spec1i.p != spec1i.i) { \
          spec1i.np = (_tp_)(front_xq_a0_spec_elem_get_buf(_b_), (_ds_)[spec1i.p], _tpd_, front_xq_a0_spec_elem_get_buf(_ib_)); \
          if (spec1i.np != spec1i.p) { \
            front_xq_a0_spec_elem_copy_at((_b_), spec1i.j, (_b_), (_ds_)[spec1i.p]); \
            front_xq_a0_spec_elem_copy_at((_ib_), 0, (_b_), spec1i.j); \
          } else front_xq_a0_spec_elem_copy_at((_ib_), 0, (_b_), (_ds_)[spec1i.p]); \
          ++(_ds_)[spec1i.p]; \
          spec1i.p = spec1i.np; \
        } \
        ++spec1i.j; \
      } \
    } \
  } else { \
    for (spec1i.e = 0, spec1i.i = 0; spec1i.i < (_n_); ++spec1i.i) { \
      spec1i.e += (_cs_)[spec1i.i]; \
      spec1i.j = (_ds_)[spec1i.i]; \
      while (spec1i.j < spec1i.e) { \
        spec1i.p = (_tp_)(front_xq_a0_spec_elem_get_buf(_b_), spec1i.j, _tpd_, NULL); \
        while (spec1i.p != spec1i.i) { \
          spec1i.np = (_tp_)(front_xq_a0_spec_elem_get_buf(_b_), (_ds_)[spec1i.p], _tpd_, NULL); \
          if (spec1i.np != spec1i.p) front_xq_a0_spec_elem_exchange_at((_b_), (_ds_)[spec1i.p], (_b_), spec1i.j, (_xb_)); \
          ++(_ds_)[spec1i.p]; \
          spec1i.p = spec1i.np; \
        } \
        ++spec1i.j; \
      } \
    } \
  } } while (0)

/* sp_macro front_xq_a0_SPEC_FUNC_TPROC_MOD_REARRANGE_IP */
#define front_xq_a0_SPEC_FUNC_TPROC_MOD_REARRANGE_IP(_name_, _tp_, _s_) \
_s_ void _name_##_tproc_mod_rearrange_ip(front_xq_a0_spec_elem_t *s, front_xq_a0_spec_elem_t *x, front_xq_a0_spec_tproc_data_t tproc_data, int *displs, int *counts, front_xq_a0_spec_int_t n, front_xq_a0_spec_elem_t *mod) \
{ \
  front_xq_a0_SPEC_DECLARE_TPROC_MOD_REARRANGE_IP \
  front_xq_a0_SPEC_DO_TPROC_MOD_REARRANGE_IP(_tp_, tproc_data, s, x, displs, counts, n, mod); \
}


/* tprocs rearrange */

/* sp_macro front_xq_a0_SPEC_DECLARE_TPROCS_REARRANGE_DB */
#define front_xq_a0_SPEC_DECLARE_TPROCS_REARRANGE_DB \
  struct { front_xq_a0_spec_elem_index_t i; front_xq_a0_spec_int_t j, n; } spec2d;

/* sp_macro front_xq_a0_SPEC_DO_TPROCS_REARRANGE_DB */
#define front_xq_a0_SPEC_DO_TPROCS_REARRANGE_DB(_tp_, _tpd_, _sb_, _db_, _ds_, _ps_)  do { \
  for (spec2d.i = 0; spec2d.i < front_xq_a0_spec_elem_get_n(_sb_); ++spec2d.i) { \
    spec2d.n = (_tp_)(front_xq_a0_spec_elem_get_buf(_sb_), spec2d.i, (_tpd_), (_ps_)); \
    for (spec2d.j = 0; spec2d.j < spec2d.n; ++spec2d.j) { \
      front_xq_a0_spec_elem_copy_at((_sb_), spec2d.i, (_db_), (_ds_)[(_ps_)[spec2d.j]]); \
      ++(_ds_)[(_ps_)[spec2d.j]]; \
    } \
  } } while (0)

/* sp_macro front_xq_a0_SPEC_FUNC_TPROCS_REARRANGE_DB */
#define front_xq_a0_SPEC_FUNC_TPROCS_REARRANGE_DB(_name_, _tp_, _s_...) \
_s_ void _name_##_tprocs_rearrange_db(front_xq_a0_spec_elem_t *s, front_xq_a0_spec_elem_t *d, front_xq_a0_spec_tproc_data_t tproc_data, int *displs, front_xq_a0_spec_proc_t *procs) \
{ \
  front_xq_a0_SPEC_DECLARE_TPROCS_REARRANGE_DB \
  front_xq_a0_SPEC_DO_TPROCS_REARRANGE_DB(_tp_, tproc_data, s, d, displs, procs); \
}

/* sp_macro front_xq_a0_SPEC_DECLARE_TPROCS_REARRANGE_IP */
#define front_xq_a0_SPEC_DECLARE_TPROCS_REARRANGE_IP \
  struct { front_xq_a0_spec_elem_index_t e, j, fe, fc, le, lc; front_xq_a0_spec_int_t i, n, f, l, o; } spec2i;

/* sp_macro front_xq_a0_SPEC_DO_TPROCS_REARRANGE_IP */
#define front_xq_a0_SPEC_DO_TPROCS_REARRANGE_IP(_tp_, _tpd_, _b_, _xb_, _ds_, _cs_, _n_, _ps_)  do { \
  spec2i.f = 0; spec2i.fe = (_cs_)[0]; spec2i.fc = front_xq_a0_spec_elem_get_n(_b_); \
  while (spec2i.f + 1 < (_n_) && spec2i.fc >= spec2i.fe) { ++spec2i.f; spec2i.fe += (_cs_)[spec2i.f]; } \
  spec2i.l = 0; spec2i.le = (_cs_)[0]; spec2i.lc = front_xq_a0_spec_elem_get_n(_b_) - 1; \
  while (spec2i.lc >= spec2i.le) { ++spec2i.l; spec2i.le += (_cs_)[spec2i.l]; } \
  for (spec2i.e = 0, spec2i.i = 0; spec2i.i < (_n_); ++spec2i.i) { \
    spec2i.e += (_cs_)[spec2i.i]; \
    spec2i.j = (_ds_)[spec2i.i]; \
    while (spec2i.j < spec2i.e) { \
      spec2i.n = (_tp_)(front_xq_a0_spec_elem_get_buf(_b_), spec2i.j, (_tpd_), (_ps_)); \
      spec2i.o = -1; \
      while (spec2i.n > 0) { \
        --spec2i.n; \
        if ((_ps_)[spec2i.n] == spec2i.i && spec2i.o < 0) spec2i.o = spec2i.n; \
        else if ((_ds_)[(_ps_)[spec2i.n]] < spec2i.fc) { \
          spec2i.l = spec2i.f; spec2i.le = spec2i.fe; spec2i.lc = spec2i.fc; \
          if (spec2i.fc < spec2i.fe) { \
            front_xq_a0_spec_elem_copy_at((_b_), (_ds_)[(_ps_)[spec2i.n]], (_b_), spec2i.fc); \
            ++spec2i.fc; \
          } else front_xq_a0_spec_elem_copy_at((_b_), (_ds_)[(_ps_)[spec2i.n]], (_xb_), 0); \
        } else if ((_ds_)[(_ps_)[spec2i.n]] == spec2i.fc) ++spec2i.fc; \
        if (spec2i.j != (_ds_)[(_ps_)[spec2i.n]]) front_xq_a0_spec_elem_copy_at((_b_), spec2i.j, (_b_), (_ds_)[(_ps_)[spec2i.n]]); \
        ++(_ds_)[(_ps_)[spec2i.n]]; \
        while (spec2i.f + 1 < (_n_) && spec2i.fc >= spec2i.fe) { ++spec2i.f; spec2i.fe += (_cs_)[spec2i.f]; spec2i.fc = (_ds_)[spec2i.f]; } \
      } \
      if (spec2i.o < 0) { \
        if (spec2i.lc < spec2i.le) {  \
          front_xq_a0_spec_elem_copy_at((_b_), spec2i.lc, (_b_), spec2i.j); \
          spec2i.f = spec2i.l; spec2i.fe = spec2i.le; spec2i.fc = spec2i.lc; \
          --spec2i.lc; \
          while (spec2i.l > 0 && spec2i.lc < (_ds_)[spec2i.l]) { spec2i.le -= (_cs_)[spec2i.l]; spec2i.lc = spec2i.le - 1; --spec2i.l; } \
        } else front_xq_a0_spec_elem_copy_at((_xb_), 0, (_b_), spec2i.j); \
      } \
      spec2i.j = (_ds_)[spec2i.i]; \
    } \
  } } while (0)

/* sp_macro front_xq_a0_SPEC_FUNC_TPROCS_REARRANGE_IP */
#define front_xq_a0_SPEC_FUNC_TPROCS_REARRANGE_IP(_name_, _tp_, _s_...) \
_s_ void _name_##_tprocs_rearrange_ip(front_xq_a0_spec_elem_t *s, front_xq_a0_spec_elem_t *d, front_xq_a0_spec_tproc_data_t tproc_data, int *displs, int *counts, front_xq_a0_spec_int_t n, front_xq_a0_spec_proc_t *procs) \
{ \
  front_xq_a0_SPEC_DECLARE_TPROCS_REARRANGE_IP \
  front_xq_a0_SPEC_DO_TPROCS_REARRANGE_IP(_tp_, tproc_data, s, d, displs, counts, n, procs); \
}


/* tprocs_mod rearrange */

/* sp_macro front_xq_a0_SPEC_DECLARE_TPROCS_MOD_REARRANGE_DB */
#define front_xq_a0_SPEC_DECLARE_TPROCS_MOD_REARRANGE_DB \
  struct { front_xq_a0_spec_elem_index_t i; front_xq_a0_spec_int_t j, n; } spec3d;

/* sp_macro front_xq_a0_SPEC_DO_TPROCS_MOD_REARRANGE_DB */
#define front_xq_a0_SPEC_DO_TPROCS_MOD_REARRANGE_DB(_tp_, _tpd_, _sb_, _db_, _ds_, _ps_, _ib_)  do { \
  if (_ib_) { \
    for (spec3d.i = 0; spec3d.i < front_xq_a0_spec_elem_get_n(_sb_); ++spec3d.i) { \
      spec3d.n = (_tp_)(front_xq_a0_spec_elem_get_buf(_sb_), spec3d.i, (_tpd_), (_ps_), front_xq_a0_spec_elem_get_buf(_ib_)); \
      for (spec3d.j = 0; spec3d.j < spec3d.n; ++spec3d.j) { \
        front_xq_a0_spec_elem_copy_at((_ib_), spec3d.j, (_db_), (_ds_)[(_ps_)[spec3d.j]]); \
        ++(_ds_)[(_ps_)[spec3d.j]]; \
      } \
    } \
  } else { \
    for (spec3d.i = 0; spec3d.i < front_xq_a0_spec_elem_get_n(_sb_); ++spec3d.i) { \
      spec3d.n = (_tp_)(front_xq_a0_spec_elem_get_buf(_sb_), spec3d.i, (_tpd_), (_ps_), NULL); \
      for (spec3d.j = 0; spec3d.j < spec3d.n; ++spec3d.j) { \
        front_xq_a0_spec_elem_copy_at((_sb_), spec3d.i, (_db_), (_ds_)[(_ps_)[spec3d.j]]); \
        ++(_ds_)[(_ps_)[spec3d.j]]; \
      } \
    } \
  } } while (0)

/* sp_macro front_xq_a0_SPEC_FUNC_TPROCS_MOD_REARRANGE_DB */
#define front_xq_a0_SPEC_FUNC_TPROCS_MOD_REARRANGE_DB(_name_, _tp_, _s_...) \
_s_ void _name_##_tprocs_mod_rearrange_db(front_xq_a0_spec_elem_t *s, front_xq_a0_spec_elem_t *d, front_xq_a0_spec_tproc_data_t tproc_data, int *displs, front_xq_a0_spec_proc_t *procs, front_xq_a0_spec_elem_t *mod) \
{ \
  front_xq_a0_SPEC_DECLARE_TPROCS_MOD_REARRANGE_DB \
  front_xq_a0_SPEC_DO_TPROCS_MOD_REARRANGE_DB(_tp_, tproc_data, s, d, displs, procs, mod); \
}

/* sp_macro front_xq_a0_SPEC_DECLARE_TPROCS_MOD_REARRANGE_IP */
#define front_xq_a0_SPEC_DECLARE_TPROCS_MOD_REARRANGE_IP \
  struct { front_xq_a0_spec_elem_index_t e, j, fe, fc, le, lc; front_xq_a0_spec_int_t i, n, f, l, o; } spec3i;

/* sp_macro front_xq_a0_SPEC_DO_TPROCS_MOD_REARRANGE_IP */
#define front_xq_a0_SPEC_DO_TPROCS_MOD_REARRANGE_IP(_tp_, _tpd_, _b_, _xb_, _ds_, _cs_, _n_, _ps_, _ib_)  do { \
  if (_ib_) { \
    spec3i.f = 0; spec3i.fe = (_cs_)[0]; spec3i.fc = front_xq_a0_spec_elem_get_n(_b_); \
    while (spec3i.f + 1 < (_n_) && spec3i.fc >= spec3i.fe) { ++spec3i.f; spec3i.fe += (_cs_)[spec3i.f]; } \
    spec3i.l = 0; spec3i.le = (_cs_)[0]; spec3i.lc = front_xq_a0_spec_elem_get_n(_b_) - 1; \
    while (spec3i.lc >= spec3i.le) { ++spec3i.l; spec3i.le += (_cs_)[spec3i.l]; } \
    for (spec3i.e = 0, spec3i.i = 0; spec3i.i < (_n_); ++spec3i.i) { \
      spec3i.e += (_cs_)[spec3i.i]; \
      spec3i.j = (_ds_)[spec3i.i]; \
      while (spec3i.j < spec3i.e) { \
        spec3i.n = (_tp_)(front_xq_a0_spec_elem_get_buf(_b_), spec3i.j, (_tpd_), (_ps_), front_xq_a0_spec_elem_get_buf(_ib_)); \
        spec3i.o = -1; \
        while (spec3i.n > 0) { \
          --spec3i.n; \
          if ((_ps_)[spec3i.n] == spec3i.i && spec3i.o < 0) spec3i.o = spec3i.n; \
          else if ((_ds_)[(_ps_)[spec3i.n]] < spec3i.fc) { \
            spec3i.l = spec3i.f; spec3i.le = spec3i.fe; spec3i.lc = spec3i.fc; \
            if (spec3i.fc < spec3i.fe) { \
              front_xq_a0_spec_elem_copy_at((_b_), (_ds_)[(_ps_)[spec3i.n]], (_b_), spec3i.fc); \
              ++spec3i.fc; \
            } else front_xq_a0_spec_elem_copy_at((_b_), (_ds_)[(_ps_)[spec3i.n]], (_xb_), 0); \
          } else if ((_ds_)[(_ps_)[spec3i.n]] == spec3i.fc) ++spec3i.fc; \
          front_xq_a0_spec_elem_copy_at((_ib_), spec3i.n, (_b_), (_ds_)[(_ps_)[spec3i.n]]); \
          ++(_ds_)[(_ps_)[spec3i.n]]; \
          while (spec3i.f + 1 < (_n_) && spec3i.fc >= spec3i.fe) { ++spec3i.f; spec3i.fe += (_cs_)[spec3i.f]; spec3i.fc = (_ds_)[spec3i.f]; } \
        } \
        if (spec3i.o < 0) { \
          if (spec3i.lc < spec3i.le) {  \
            front_xq_a0_spec_elem_copy_at((_b_), spec3i.lc, (_b_), spec3i.j); \
            spec3i.f = spec3i.l; spec3i.fe = spec3i.le; spec3i.fc = spec3i.lc; \
            --spec3i.lc; \
            while (spec3i.l > 0 && spec3i.lc < (_ds_)[spec3i.l]) { spec3i.le -= (_cs_)[spec3i.l]; spec3i.lc = spec3i.le - 1; --spec3i.l; } \
          } else front_xq_a0_spec_elem_copy_at((_xb_), 0, (_b_), spec3i.j); \
        } \
        spec3i.j = (_ds_)[spec3i.i]; \
      } \
    } \
  } else { \
    spec3i.f = 0; spec3i.fe = (_cs_)[0]; spec3i.fc = front_xq_a0_spec_elem_get_n(_b_); \
    while (spec3i.f + 1 < (_n_) && spec3i.fc >= spec3i.fe) { ++spec3i.f; spec3i.fe += (_cs_)[spec3i.f]; } \
    spec3i.l = 0; spec3i.le = (_cs_)[0]; spec3i.lc = front_xq_a0_spec_elem_get_n(_b_) - 1; \
    while (spec3i.lc >= spec3i.le) { ++spec3i.l; spec3i.le += (_cs_)[spec3i.l]; } \
    for (spec3i.e = 0, spec3i.i = 0; spec3i.i < (_n_); ++spec3i.i) { \
      spec3i.e += (_cs_)[spec3i.i]; \
      spec3i.j = (_ds_)[spec3i.i]; \
      while (spec3i.j < spec3i.e) { \
        spec3i.n = (_tp_)(front_xq_a0_spec_elem_get_buf(_b_), spec3i.j, (_tpd_), (_ps_), NULL); \
        spec3i.o = -1; \
        while (spec3i.n > 0) { \
          --spec3i.n; \
          if ((_ps_)[spec3i.n] == spec3i.i && spec3i.o < 0) spec3i.o = spec3i.n; \
          else if ((_ds_)[(_ps_)[spec3i.n]] < spec3i.fc) { \
            spec3i.l = spec3i.f; spec3i.le = spec3i.fe; spec3i.lc = spec3i.fc; \
            if (spec3i.fc < spec3i.fe) { \
              front_xq_a0_spec_elem_copy_at((_b_), (_ds_)[(_ps_)[spec3i.n]], (_b_), spec3i.fc); \
              ++spec3i.fc; \
            } else front_xq_a0_spec_elem_copy_at((_b_), (_ds_)[(_ps_)[spec3i.n]], (_xb_), 0); \
          } else if ((_ds_)[(_ps_)[spec3i.n]] == spec3i.fc) ++spec3i.fc; \
          if (spec3i.j != (_ds_)[(_ps_)[spec3i.n]]) front_xq_a0_spec_elem_copy_at((_b_), spec3i.j, (_b_), (_ds_)[(_ps_)[spec3i.n]]); \
          ++(_ds_)[(_ps_)[spec3i.n]]; \
          while (spec3i.f + 1 < (_n_) && spec3i.fc >= spec3i.fe) { ++spec3i.f; spec3i.fe += (_cs_)[spec3i.f]; spec3i.fc = (_ds_)[spec3i.f]; } \
        } \
        if (spec3i.o < 0) { \
          if (spec3i.lc < spec3i.le) {  \
            front_xq_a0_spec_elem_copy_at((_b_), spec3i.lc, (_b_), spec3i.j); \
            spec3i.f = spec3i.l; spec3i.fe = spec3i.le; spec3i.fc = spec3i.lc; \
            --spec3i.lc; \
            while (spec3i.l > 0 && spec3i.lc < (_ds_)[spec3i.l]) { spec3i.le -= (_cs_)[spec3i.l]; spec3i.lc = spec3i.le - 1; --spec3i.l; } \
          } else front_xq_a0_spec_elem_copy_at((_xb_), 0, (_b_), spec3i.j); \
        } \
        spec3i.j = (_ds_)[spec3i.i]; \
      } \
    } \
  } } while (0)

/* sp_macro front_xq_a0_SPEC_FUNC_TPROCS_MOD_REARRANGE_IP */
#define front_xq_a0_SPEC_FUNC_TPROCS_MOD_REARRANGE_IP(_name_, _tp_, _s_...) \
_s_ void _name_##_tprocs_mod_rearrange_ip(front_xq_a0_spec_elem_t *s, front_xq_a0_spec_elem_t *x, front_xq_a0_spec_tproc_data_t tproc_data, int *displs, int *counts, front_xq_a0_spec_int_t n, front_xq_a0_spec_proc_t *procs, front_xq_a0_spec_elem_t *mod) \
{ \
  front_xq_a0_SPEC_DECLARE_TPROCS_MOD_REARRANGE_IP \
  front_xq_a0_SPEC_DO_TPROCS_MOD_REARRANGE_IP(_tp_, tproc_data, s, x, displs, counts, n, procs, mod); \
}

/* sp_macro front_xq_a0_SPEC_DEFINE_TPROC */
#define front_xq_a0_SPEC_DEFINE_TPROC(_name_, _tp_, _s_...) \
  front_xq_a0_SPEC_FUNC_TPROC_COUNT_DB(_name_, _tp_, _s_) \
  front_xq_a0_SPEC_FUNC_TPROC_COUNT_IP(_name_, _tp_, _s_) \
  front_xq_a0_SPEC_FUNC_TPROC_REARRANGE_DB(_name_, _tp_, _s_) \
  front_xq_a0_SPEC_FUNC_TPROC_REARRANGE_IP(_name_, _tp_, _s_)

/* sp_macro front_xq_a0_SPEC_DEFINE_TPROC_MOD */
#define front_xq_a0_SPEC_DEFINE_TPROC_MOD(_name_, _tp_, _s_...) \
  front_xq_a0_SPEC_FUNC_TPROC_MOD_COUNT_DB(_name_, _tp_, _s_) \
  front_xq_a0_SPEC_FUNC_TPROC_MOD_COUNT_IP(_name_, _tp_, _s_) \
  front_xq_a0_SPEC_FUNC_TPROC_MOD_REARRANGE_DB(_name_, _tp_, _s_) \
  front_xq_a0_SPEC_FUNC_TPROC_MOD_REARRANGE_IP(_name_, _tp_, _s_)

/* sp_macro front_xq_a0_SPEC_DEFINE_TPROCS */
#define front_xq_a0_SPEC_DEFINE_TPROCS(_name_, _tp_, _s_...) \
  front_xq_a0_SPEC_FUNC_TPROCS_COUNT_DB(_name_, _tp_, _s_) \
  front_xq_a0_SPEC_FUNC_TPROCS_COUNT_IP(_name_, _tp_, _s_) \
  front_xq_a0_SPEC_FUNC_TPROCS_REARRANGE_DB(_name_, _tp_, _s_) \
  front_xq_a0_SPEC_FUNC_TPROCS_REARRANGE_IP(_name_, _tp_, _s_)

/* sp_macro front_xq_a0_SPEC_DEFINE_TPROCS_MOD */
#define front_xq_a0_SPEC_DEFINE_TPROCS_MOD(_name_, _tp_, _s_...) \
  front_xq_a0_SPEC_FUNC_TPROCS_MOD_COUNT_DB(_name_, _tp_, _s_) \
  front_xq_a0_SPEC_FUNC_TPROCS_MOD_COUNT_IP(_name_, _tp_, _s_) \
  front_xq_a0_SPEC_FUNC_TPROCS_MOD_REARRANGE_DB(_name_, _tp_, _s_) \
  front_xq_a0_SPEC_FUNC_TPROCS_MOD_REARRANGE_IP(_name_, _tp_, _s_)

/* sp_macro front_xq_a0_SPEC_EXT_PARAM_TPROC front_xq_a0_SPEC_EXT_PARAM_TPROC_NULL front_xq_a0_SPEC_EXT_PARAM_TPROC_MOD front_xq_a0_SPEC_EXT_PARAM_TPROC_MOD_NULL front_xq_a0_SPEC_EXT_PARAM_TPROCS front_xq_a0_SPEC_EXT_PARAM_TPROCS_NULL front_xq_a0_SPEC_EXT_PARAM_TPROCS_MOD front_xq_a0_SPEC_EXT_PARAM_TPROCS_MOD_NULL */
#define front_xq_a0_SPEC_EXT_PARAM_TPROC(_name_)       _name_##_tproc_count_db, _name_##_tproc_count_ip, _name_##_tproc_rearrange_db, _name_##_tproc_rearrange_ip
#define front_xq_a0_SPEC_EXT_PARAM_TPROC_NULL          NULL, NULL, NULL, NULL
#define front_xq_a0_SPEC_EXT_PARAM_TPROC_MOD(_name_)   _name_##_tproc_mod_count_db, _name_##_tproc_mod_count_ip, _name_##_tproc_mod_rearrange_db, _name_##_tproc_mod_rearrange_ip
#define front_xq_a0_SPEC_EXT_PARAM_TPROC_MOD_NULL      NULL, NULL, NULL, NULL
#define front_xq_a0_SPEC_EXT_PARAM_TPROCS(_name_)      _name_##_tprocs_count_db, _name_##_tprocs_count_ip, _name_##_tprocs_rearrange_db, _name_##_tprocs_rearrange_ip
#define front_xq_a0_SPEC_EXT_PARAM_TPROCS_NULL         NULL, NULL, NULL, NULL
#define front_xq_a0_SPEC_EXT_PARAM_TPROCS_MOD(_name_)  _name_##_tprocs_mod_count_db, _name_##_tprocs_mod_count_ip, _name_##_tprocs_mod_rearrange_db, _name_##_tprocs_mod_rearrange_ip
#define front_xq_a0_SPEC_EXT_PARAM_TPROCS_MOD_NULL     NULL, NULL, NULL, NULL


/* sp_type front_xq_a0_spec_tproc_f front_xq_a0_spec_tproc_count_f front_xq_a0_spec_tproc_rearrange_db_f front_xq_a0_spec_tproc_rearrange_ip_f */
typedef front_xq_a0_spec_proc_t front_xq_a0_spec_tproc_f(front_xq_a0_spec_elem_buf_t b, front_xq_a0_spec_elem_index_t x, front_xq_a0_spec_tproc_data_t tproc_data);
typedef void front_xq_a0_spec_tproc_count_f(front_xq_a0_spec_elem_t *s, front_xq_a0_spec_tproc_data_t tproc_data, int *counts);
typedef void front_xq_a0_spec_tproc_rearrange_db_f(front_xq_a0_spec_elem_t *s, front_xq_a0_spec_elem_t *d, front_xq_a0_spec_tproc_data_t tproc_data, int *displs);
typedef void front_xq_a0_spec_tproc_rearrange_ip_f(front_xq_a0_spec_elem_t *s, front_xq_a0_spec_elem_t *x, front_xq_a0_spec_tproc_data_t tproc_data, int *displs, int *counts, front_xq_a0_spec_int_t n);

/* sp_type front_xq_a0_spec_tproc_mod_f front_xq_a0_spec_tproc_mod_count_f front_xq_a0_spec_tproc_mod_rearrange_db_f front_xq_a0_spec_tproc_mod_rearrange_ip_f */
typedef front_xq_a0_spec_proc_t front_xq_a0_spec_tproc_mod_f(front_xq_a0_spec_elem_buf_t b, front_xq_a0_spec_elem_index_t x, front_xq_a0_spec_tproc_data_t tproc_data, front_xq_a0_spec_elem_buf_t mod);
typedef void front_xq_a0_spec_tproc_mod_count_f(front_xq_a0_spec_elem_t *s, front_xq_a0_spec_tproc_data_t tproc_data, int *counts);
typedef void front_xq_a0_spec_tproc_mod_rearrange_db_f(front_xq_a0_spec_elem_t *s, front_xq_a0_spec_elem_t *d, front_xq_a0_spec_tproc_data_t tproc_data, int *displs, front_xq_a0_spec_elem_t *mod);
typedef void front_xq_a0_spec_tproc_mod_rearrange_ip_f(front_xq_a0_spec_elem_t *s, front_xq_a0_spec_elem_t *x, front_xq_a0_spec_tproc_data_t tproc_data, int *displs, int *counts, front_xq_a0_spec_int_t n, front_xq_a0_spec_elem_t *mod);

/* sp_type front_xq_a0_spec_tprocs_f front_xq_a0_spec_tprocs_count_f front_xq_a0_spec_tprocs_rearrange_db_f front_xq_a0_spec_tprocs_rearrange_ip_f */
typedef front_xq_a0_spec_int_t front_xq_a0_spec_tprocs_f(front_xq_a0_spec_elem_buf_t b, front_xq_a0_spec_elem_index_t x, front_xq_a0_spec_tproc_data_t tproc_data, front_xq_a0_spec_proc_t *procs);
typedef void front_xq_a0_spec_tprocs_count_f(front_xq_a0_spec_elem_t *s, front_xq_a0_spec_tproc_data_t tproc_data, int *counts, front_xq_a0_spec_proc_t *procs);
typedef void front_xq_a0_spec_tprocs_rearrange_db_f(front_xq_a0_spec_elem_t *s, front_xq_a0_spec_elem_t *d, front_xq_a0_spec_tproc_data_t tproc_data, int *displs, front_xq_a0_spec_proc_t *procs);
typedef void front_xq_a0_spec_tprocs_rearrange_ip_f(front_xq_a0_spec_elem_t *s, front_xq_a0_spec_elem_t *x, front_xq_a0_spec_tproc_data_t tproc_data, int *displs, int *counts, front_xq_a0_spec_int_t n, front_xq_a0_spec_proc_t *procs);

/* sp_type front_xq_a0_spec_tprocs_mod_f front_xq_a0_spec_tprocs_mod_count_f front_xq_a0_spec_tprocs_mod_rearrange_db_f front_xq_a0_spec_tprocs_mod_rearrange_ip_f */
typedef front_xq_a0_spec_int_t front_xq_a0_spec_tprocs_mod_f(front_xq_a0_spec_elem_buf_t b, front_xq_a0_spec_elem_index_t x, front_xq_a0_spec_tproc_data_t tproc_data, front_xq_a0_spec_proc_t *procs, front_xq_a0_spec_elem_buf_t mod);
typedef void front_xq_a0_spec_tprocs_mod_count_f(front_xq_a0_spec_elem_t *s, front_xq_a0_spec_tproc_data_t tproc_data, int *counts, front_xq_a0_spec_proc_t *procs);
typedef void front_xq_a0_spec_tprocs_mod_rearrange_db_f(front_xq_a0_spec_elem_t *s, front_xq_a0_spec_elem_t *d, front_xq_a0_spec_tproc_data_t tproc_data, int *displs, front_xq_a0_spec_proc_t *procs, front_xq_a0_spec_elem_t *mod);
typedef void front_xq_a0_spec_tprocs_mod_rearrange_ip_f(front_xq_a0_spec_elem_t *s, front_xq_a0_spec_elem_t *x, front_xq_a0_spec_tproc_data_t tproc_data, int *displs, int *counts, front_xq_a0_spec_int_t n, front_xq_a0_spec_proc_t *procs, front_xq_a0_spec_elem_t *mod);

/* sp_type front_xq_a0_spec_tproc_reset_f */
typedef void front_xq_a0_spec_tproc_reset_f(front_xq_a0_spec_tproc_data_t tproc_data);


/* enable tloc features */
#ifdef front_xq_a0_SPEC_TLOC

/* sp_macro front_xq_a0_SPEC_TLOC front_xq_a0_SPEC_LOC_NONE */


/* tloc rearrange */

/* sp_macro front_xq_a0_SPEC_DECLARE_TLOC_REARRANGE_DB */
#define front_xq_a0_SPEC_DECLARE_TLOC_REARRANGE_DB \
  struct { front_xq_a0_spec_int_t i, p; } spec0d;

/* sp_macro front_xq_a0_SPEC_DO_TLOC_REARRANGE_DB */
#define front_xq_a0_SPEC_DO_TLOC_REARRANGE_DB(_tl_, _tld_, _sb_, _db_)  do { \
  for (spec0d.i = 0; spec0d.i < front_xq_a0_spec_elem_get_n(_sb_); ++spec0d.i) { \
    spec0d.p = (_tl_)(front_xq_a0_spec_elem_get_buf(_sb_), spec0d.i, _tld_); \
    if (spec0d.p == front_xq_a0_SPEC_LOC_NONE) continue; \
    front_xq_a0_spec_elem_copy_at((_sb_), spec0d.i, (_db_), spec0d.p); \
  } } while (0)

/* sp_macro front_xq_a0_SPEC_FUNC_TLOC_REARRANGE_DB */
#define front_xq_a0_SPEC_FUNC_TLOC_REARRANGE_DB(_name_, _tl_, _s_...) \
_s_ void _name_##_tloc_rearrange_db(front_xq_a0_spec_elem_t *s, front_xq_a0_spec_elem_t *d, front_xq_a0_spec_tloc_data_t tloc_data) \
{ \
  front_xq_a0_SPEC_DECLARE_TLOC_REARRANGE_DB \
  front_xq_a0_SPEC_DO_TLOC_REARRANGE_DB(_tl_, tloc_data, s, d); \
}

/* sp_macro front_xq_a0_SPEC_DECLARE_TLOC_REARRANGE_IP */
#define front_xq_a0_SPEC_DECLARE_TLOC_REARRANGE_IP \
  struct { front_xq_a0_spec_int_t i, p, np; } spec0i;

/* sp_macro front_xq_a0_SPEC_DO_TLOC_REARRANGE_IP */
#define front_xq_a0_SPEC_DO_TLOC_REARRANGE_IP(_tl_, _tld_, _b_, _xb_)  do { \
  for (spec0i.i = 0; spec0i.i < front_xq_a0_spec_elem_get_n(_b_); ++spec0i.i) { \
    spec0i.p = (_tl_)(front_xq_a0_spec_elem_get_buf(_b_), spec0i.i, _tld_); \
    if (spec0i.p == front_xq_a0_SPEC_LOC_NONE) continue; \
    while (spec0i.i != spec0i.p) { \
      spec0i.np = (_tl_)(front_xq_a0_spec_elem_get_buf(_b_), spec0i.p, _tld_); \
      if (spec0i.np == front_xq_a0_SPEC_LOC_NONE) { front_xq_a0_spec_elem_copy_at((_b_), spec0i.i, (_b_), spec0i.p); break; } \
      front_xq_a0_spec_elem_exchange_at((_b_), spec0i.i, (_b_), spec0i.p, (_xb_)); \
      spec0i.p = spec0i.np; \
    } \
  } } while (0)

/* sp_macro front_xq_a0_SPEC_FUNC_TLOC_REARRANGE_IP */
#define front_xq_a0_SPEC_FUNC_TLOC_REARRANGE_IP(_name_, _tl_, _s_) \
_s_ void _name_##_tloc_rearrange_ip(front_xq_a0_spec_elem_t *s, front_xq_a0_spec_elem_t *x, front_xq_a0_spec_tloc_data_t tloc_data) \
{ \
  front_xq_a0_SPEC_DECLARE_TLOC_REARRANGE_IP \
  front_xq_a0_SPEC_DO_TLOC_REARRANGE_IP(_tl_, tloc_data, s, x); \
}


/* tloc_mod_mod rearrange */

/* sp_macro front_xq_a0_SPEC_DECLARE_TLOC_MOD_REARRANGE_DB */
#define front_xq_a0_SPEC_DECLARE_TLOC_MOD_REARRANGE_DB \
  struct { front_xq_a0_spec_int_t i, p; } spec1d;

/* sp_macro front_xq_a0_SPEC_DO_TLOC_MOD_REARRANGE_DB */
#define front_xq_a0_SPEC_DO_TLOC_MOD_REARRANGE_DB(_tl_, _tld_, _sb_, _db_, _ib_)  do { \
  if (_ib_) { \
    for (spec1d.i = 0; spec1d.i < front_xq_a0_spec_elem_get_n(_sb_); ++spec1d.i) { \
      spec1d.p = (_tl_)(front_xq_a0_spec_elem_get_buf(_sb_), spec1d.i, _tld_, front_xq_a0_spec_elem_get_buf(_ib_)); \
      if (spec1d.p == front_xq_a0_SPEC_LOC_NONE) continue; \
      front_xq_a0_spec_elem_copy_at((_ib_), 0, (_db_), spec1d.p); \
    } \
  } else { \
    for (spec1d.i = 0; spec1d.i < front_xq_a0_spec_elem_get_n(_sb_); ++spec1d.i) { \
      spec1d.p = (_tl_)(front_xq_a0_spec_elem_get_buf(_sb_), spec1d.i, _tld_, NULL); \
      if (spec1d.p == front_xq_a0_SPEC_LOC_NONE) continue; \
      front_xq_a0_spec_elem_copy_at((_sb_), spec1d.i, (_db_), spec1d.p); \
    } \
  } } while (0) 

/* sp_macro front_xq_a0_SPEC_FUNC_TLOC_MOD_REARRANGE_DB */
#define front_xq_a0_SPEC_FUNC_TLOC_MOD_REARRANGE_DB(_name_, _tl_, _s_...) \
_s_ void _name_##_tloc_mod_rearrange_db(front_xq_a0_spec_elem_t *s, front_xq_a0_spec_elem_t *d, front_xq_a0_spec_tloc_data_t tloc_data, front_xq_a0_spec_elem_t *mod) \
{ \
  front_xq_a0_SPEC_DECLARE_TLOC_MOD_REARRANGE_DB \
  front_xq_a0_SPEC_DO_TLOC_MOD_REARRANGE_DB(_tl_, tloc_data, s, d, mod); \
}

/* sp_macro front_xq_a0_SPEC_DECLARE_TLOC_MOD_REARRANGE_IP */
#define front_xq_a0_SPEC_DECLARE_TLOC_MOD_REARRANGE_IP \
  struct { front_xq_a0_spec_int_t i, p, np; } spec1i;

/* sp_macro front_xq_a0_SPEC_DO_TLOC_MOD_REARRANGE_IP */
#define front_xq_a0_SPEC_DO_TLOC_MOD_REARRANGE_IP(_tl_, _tld_, _b_, _xb_, _ib_)  do { \
  if (_ib_) { \
    for (spec1i.i = 0; spec1i.i < front_xq_a0_spec_elem_get_n(_b_); ++spec1i.i) { \
      spec1i.p = (_tl_)(front_xq_a0_spec_elem_get_buf(_b_), spec1i.i, _tld_, front_xq_a0_spec_elem_get_buf(_ib_)); \
      if (spec1i.p == front_xq_a0_SPEC_LOC_NONE) continue; \
      while (spec1i.i != spec1i.p) { \
        spec1i.np = (_tl_)(front_xq_a0_spec_elem_get_buf(_b_), spec1i.p, _tld_, front_xq_a0_spec_elem_get_buf(_xb_)); \
        if (spec1i.np == front_xq_a0_SPEC_LOC_NONE) break; \
        front_xq_a0_spec_elem_copy_at((_ib_), 0, (_b_), spec1i.p); \
        front_xq_a0_spec_elem_copy_at((_xb_), 0, (_ib_), 0); \
        spec1i.p = spec1i.np; \
      } \
      front_xq_a0_spec_elem_copy_at((_ib_), 0, (_b_), spec1i.i); \
    } \
  } else { \
    for (spec1i.i = 0; spec1i.i < front_xq_a0_spec_elem_get_n(_b_); ++spec1i.i) { \
      spec1i.p = (_tl_)(front_xq_a0_spec_elem_get_buf(_b_), spec1i.i, _tld_, NULL); \
      if (spec1i.p == front_xq_a0_SPEC_LOC_NONE) continue; \
      while (spec1i.i != spec1i.p) { \
        spec1i.np = (_tl_)(front_xq_a0_spec_elem_get_buf(_b_), spec1i.p, _tld_, NULL); \
        if (spec1i.np == front_xq_a0_SPEC_LOC_NONE) { front_xq_a0_spec_elem_copy_at((_b_), spec1i.i, (_b_), spec1i.p); break; } \
        front_xq_a0_spec_elem_exchange_at((_b_), spec1i.i, (_b_), spec1i.p, (_xb_)); \
        spec1i.p = spec1i.np; \
      } \
    } \
 } } while (0) 

/* sp_macro front_xq_a0_SPEC_FUNC_TLOC_MOD_REARRANGE_IP */
#define front_xq_a0_SPEC_FUNC_TLOC_MOD_REARRANGE_IP(_name_, _tl_, _s_) \
_s_ void _name_##_tloc_mod_rearrange_ip(front_xq_a0_spec_elem_t *s, front_xq_a0_spec_elem_t *x, front_xq_a0_spec_tloc_data_t tloc_data, front_xq_a0_spec_elem_t *mod) \
{ \
  front_xq_a0_SPEC_DECLARE_TLOC_MOD_REARRANGE_IP \
  front_xq_a0_SPEC_DO_TLOC_MOD_REARRANGE_IP(_tl_, tloc_data, s, x, mod); \
}

/* sp_macro front_xq_a0_SPEC_DEFINE_TLOC */
#define front_xq_a0_SPEC_DEFINE_TLOC(_name_, _tl_, _s_...) \
  front_xq_a0_SPEC_FUNC_TLOC_REARRANGE_DB(_name_, _tl_, _s_) \
  front_xq_a0_SPEC_FUNC_TLOC_REARRANGE_IP(_name_, _tl_, _s_)

/* sp_macro front_xq_a0_SPEC_DEFINE_TLOC_MOD */
#define front_xq_a0_SPEC_DEFINE_TLOC_MOD(_name_, _tl_, _s_...) \
  front_xq_a0_SPEC_FUNC_TLOC_MOD_REARRANGE_DB(_name_, _tl_, _s_) \
  front_xq_a0_SPEC_FUNC_TLOC_MOD_REARRANGE_IP(_name_, _tl_, _s_)

/* sp_macro front_xq_a0_SPEC_EXT_PARAM_TLOC front_xq_a0_SPEC_EXT_PARAM_TLOC_NULL front_xq_a0_SPEC_EXT_PARAM_TLOC_MOD front_xq_a0_SPEC_EXT_PARAM_TLOC_MOD_NULL */
#define front_xq_a0_SPEC_EXT_PARAM_TLOC(_name_)      _name_##_tloc_rearrange_db, _name_##_tloc_rearrange_ip
#define front_xq_a0_SPEC_EXT_PARAM_TLOC_NULL         NULL, NULL
#define front_xq_a0_SPEC_EXT_PARAM_TLOC_MOD(_name_)  _name_##_tloc_mod_rearrange_db, _name_##_tloc_mod_rearrange_ip
#define front_xq_a0_SPEC_EXT_PARAM_TLOC_MOD_NULL     NULL, NULL


/* sp_type front_xq_a0_spec_tloc_f front_xq_a0_spec_tloc_rearrange_db_f front_xq_a0_spec_tloc_rearrange_ip_f */
typedef front_xq_a0_spec_elem_index_t front_xq_a0_spec_tloc_f(front_xq_a0_spec_elem_buf_t b, front_xq_a0_spec_elem_index_t x, front_xq_a0_spec_tloc_data_t tloc_data);
typedef void front_xq_a0_spec_tloc_rearrange_db_f(front_xq_a0_spec_elem_t *s, front_xq_a0_spec_elem_t *d, front_xq_a0_spec_tloc_data_t tloc_data);
typedef void front_xq_a0_spec_tloc_rearrange_ip_f(front_xq_a0_spec_elem_t *s, front_xq_a0_spec_elem_t *x, front_xq_a0_spec_tloc_data_t tloc_data);

/* sp_type front_xq_a0_spec_tloc_mod_f front_xq_a0_spec_tloc_mod_rearrange_db_f front_xq_a0_spec_tloc_mod_rearrange_ip_f */
typedef front_xq_a0_spec_elem_index_t front_xq_a0_spec_tloc_mod_f(front_xq_a0_spec_elem_buf_t b, front_xq_a0_spec_elem_index_t x, front_xq_a0_spec_tloc_data_t tloc_data, front_xq_a0_spec_elem_buf_t mod);
typedef void front_xq_a0_spec_tloc_mod_rearrange_db_f(front_xq_a0_spec_elem_t *s, front_xq_a0_spec_elem_t *d, front_xq_a0_spec_tloc_data_t tloc_data, front_xq_a0_spec_elem_t *mod);
typedef void front_xq_a0_spec_tloc_mod_rearrange_ip_f(front_xq_a0_spec_elem_t *s, front_xq_a0_spec_elem_t *x, front_xq_a0_spec_tloc_data_t tloc_data, front_xq_a0_spec_elem_t *mod);


#endif /* front_xq_a0_SPEC_TLOC */






#ifdef SL_USE_MPI
# include <mpi.h>
#endif


/* sl_type front_xq_a0_slint_t front_xq_a0_slint */
typedef front_xq_a0_sl_int_type_c front_xq_a0_slint_t, front_xq_a0_slint;  /* deprecated 'front_xq_a0_slint' */

#define front_xq_a0_slint_fmt   front_xq_a0_sl_int_type_fmt    /* sl_macro */

/* sl_type front_xq_a0_slindex_t */
typedef front_xq_a0_sl_index_type_c front_xq_a0_slindex_t;

#define front_xq_a0_sindex_fmt  front_xq_a0_sl_index_type_fmt  /* sl_macro */

/* sl_type front_xq_a0_slkey_t */
typedef front_xq_a0_sl_key_type_c front_xq_a0_slkey_t;

/* sl_type front_xq_a0_slkey_pure_t front_xq_a0_slpkey_t */
typedef front_xq_a0_sl_key_pure_type_c front_xq_a0_slkey_pure_t, front_xq_a0_slpkey_t;

/* DATAX_TEMPLATE_BEGIN */
/* sl_type front_xq_a0_sldata0_t */
#ifdef front_xq_a0_sl_data0_type_c
typedef front_xq_a0_sl_data0_type_c front_xq_a0_sldata0_t;
#endif
/* sl_type front_xq_a0_sldata1_t */
#ifdef front_xq_a0_sl_data1_type_c
typedef front_xq_a0_sl_data1_type_c front_xq_a0_sldata1_t;
#endif
/* sl_type front_xq_a0_sldata2_t */
#ifdef front_xq_a0_sl_data2_type_c
typedef front_xq_a0_sl_data2_type_c front_xq_a0_sldata2_t;
#endif
/* sl_type front_xq_a0_sldata3_t */
#ifdef front_xq_a0_sl_data3_type_c
typedef front_xq_a0_sl_data3_type_c front_xq_a0_sldata3_t;
#endif
/* sl_type front_xq_a0_sldata4_t */
#ifdef front_xq_a0_sl_data4_type_c
typedef front_xq_a0_sl_data4_type_c front_xq_a0_sldata4_t;
#endif
/* sl_type front_xq_a0_sldata5_t */
#ifdef front_xq_a0_sl_data5_type_c
typedef front_xq_a0_sl_data5_type_c front_xq_a0_sldata5_t;
#endif
/* sl_type front_xq_a0_sldata6_t */
#ifdef front_xq_a0_sl_data6_type_c
typedef front_xq_a0_sl_data6_type_c front_xq_a0_sldata6_t;
#endif
/* sl_type front_xq_a0_sldata7_t */
#ifdef front_xq_a0_sl_data7_type_c
typedef front_xq_a0_sl_data7_type_c front_xq_a0_sldata7_t;
#endif
/* sl_type front_xq_a0_sldata8_t */
#ifdef front_xq_a0_sl_data8_type_c
typedef front_xq_a0_sl_data8_type_c front_xq_a0_sldata8_t;
#endif
/* sl_type front_xq_a0_sldata9_t */
#ifdef front_xq_a0_sl_data9_type_c
typedef front_xq_a0_sl_data9_type_c front_xq_a0_sldata9_t;
#endif
/* sl_type front_xq_a0_sldata10_t */
#ifdef front_xq_a0_sl_data10_type_c
typedef front_xq_a0_sl_data10_type_c front_xq_a0_sldata10_t;
#endif
/* sl_type front_xq_a0_sldata11_t */
#ifdef front_xq_a0_sl_data11_type_c
typedef front_xq_a0_sl_data11_type_c front_xq_a0_sldata11_t;
#endif
/* sl_type front_xq_a0_sldata12_t */
#ifdef front_xq_a0_sl_data12_type_c
typedef front_xq_a0_sl_data12_type_c front_xq_a0_sldata12_t;
#endif
/* sl_type front_xq_a0_sldata13_t */
#ifdef front_xq_a0_sl_data13_type_c
typedef front_xq_a0_sl_data13_type_c front_xq_a0_sldata13_t;
#endif
/* sl_type front_xq_a0_sldata14_t */
#ifdef front_xq_a0_sl_data14_type_c
typedef front_xq_a0_sl_data14_type_c front_xq_a0_sldata14_t;
#endif
/* sl_type front_xq_a0_sldata15_t */
#ifdef front_xq_a0_sl_data15_type_c
typedef front_xq_a0_sl_data15_type_c front_xq_a0_sldata15_t;
#endif
/* sl_type front_xq_a0_sldata16_t */
#ifdef front_xq_a0_sl_data16_type_c
typedef front_xq_a0_sl_data16_type_c front_xq_a0_sldata16_t;
#endif
/* sl_type front_xq_a0_sldata17_t */
#ifdef front_xq_a0_sl_data17_type_c
typedef front_xq_a0_sl_data17_type_c front_xq_a0_sldata17_t;
#endif
/* sl_type front_xq_a0_sldata18_t */
#ifdef front_xq_a0_sl_data18_type_c
typedef front_xq_a0_sl_data18_type_c front_xq_a0_sldata18_t;
#endif
/* sl_type front_xq_a0_sldata19_t */
#ifdef front_xq_a0_sl_data19_type_c
typedef front_xq_a0_sl_data19_type_c front_xq_a0_sldata19_t;
#endif
/* DATAX_TEMPLATE_END */

#define SL_DATA_NMAX (0 \
 + 1 \
 + 1 \
 + 1 \
 + 1 \
 + 1 \
 + 1 \
 + 1 \
 + 1 \
 + 1 \
 + 1 \
 + 1 \
 + 1 \
 + 1 \
 + 1 \
 + 1 \
 + 1 \
 + 1 \
 + 1 \
 + 1 \
 + 1 \
)

/* sl_type front_xq_a0_slweight_t */
typedef front_xq_a0_sl_weight_type_c front_xq_a0_slweight_t;

#define front_xq_a0_slweight_fmt  front_xq_a0_sl_weight_type_fmt  /* sl_macro */

#if defined(front_xq_a0_sl_elem_weight) && defined(front_xq_a0_sl_weight_intequiv)
typedef front_xq_a0_sl_weight_type_c front_xq_a0_slcount_t;       /* sl_type front_xq_a0_slcount_t */
# define front_xq_a0_slcount_fmt  front_xq_a0_sl_weight_type_fmt  /* sl_macro */
#else
typedef front_xq_a0_sl_int_type_c front_xq_a0_slcount_t;
# define front_xq_a0_slcount_fmt  front_xq_a0_sl_int_type_fmt
#endif


/* sl_type front_xq_a0__slpwkey_t front_xq_a0_slpwkey_t */
typedef struct front_xq_a0__slpwkey_t
{
  front_xq_a0_slpkey_t pkey;
  front_xq_a0_slweight_t weight;

} front_xq_a0_slpwkey_t;


/* sl_type front_xq_a0__elements_t front_xq_a0_elements_t */
typedef struct front_xq_a0__elements_t
{
  front_xq_a0_slint_t size, max_size;
  front_xq_a0_slkey_t *keys;

#ifdef front_xq_a0_SL_INDEX
  front_xq_a0_slindex_t *indices;
#endif

/* DATAX_TEMPLATE_BEGIN */
#ifdef front_xq_a0_SL_DATA0
  front_xq_a0_sldata0_t *data0;
#endif
#ifdef front_xq_a0_SL_DATA1
  front_xq_a0_sldata1_t *data1;
#endif
#ifdef front_xq_a0_SL_DATA2
  front_xq_a0_sldata2_t *data2;
#endif
#ifdef front_xq_a0_SL_DATA3
  front_xq_a0_sldata3_t *data3;
#endif
#ifdef front_xq_a0_SL_DATA4
  front_xq_a0_sldata4_t *data4;
#endif
#ifdef front_xq_a0_SL_DATA5
  front_xq_a0_sldata5_t *data5;
#endif
#ifdef front_xq_a0_SL_DATA6
  front_xq_a0_sldata6_t *data6;
#endif
#ifdef front_xq_a0_SL_DATA7
  front_xq_a0_sldata7_t *data7;
#endif
#ifdef front_xq_a0_SL_DATA8
  front_xq_a0_sldata8_t *data8;
#endif
#ifdef front_xq_a0_SL_DATA9
  front_xq_a0_sldata9_t *data9;
#endif
#ifdef front_xq_a0_SL_DATA10
  front_xq_a0_sldata10_t *data10;
#endif
#ifdef front_xq_a0_SL_DATA11
  front_xq_a0_sldata11_t *data11;
#endif
#ifdef front_xq_a0_SL_DATA12
  front_xq_a0_sldata12_t *data12;
#endif
#ifdef front_xq_a0_SL_DATA13
  front_xq_a0_sldata13_t *data13;
#endif
#ifdef front_xq_a0_SL_DATA14
  front_xq_a0_sldata14_t *data14;
#endif
#ifdef front_xq_a0_SL_DATA15
  front_xq_a0_sldata15_t *data15;
#endif
#ifdef front_xq_a0_SL_DATA16
  front_xq_a0_sldata16_t *data16;
#endif
#ifdef front_xq_a0_SL_DATA17
  front_xq_a0_sldata17_t *data17;
#endif
#ifdef front_xq_a0_SL_DATA18
  front_xq_a0_sldata18_t *data18;
#endif
#ifdef front_xq_a0_SL_DATA19
  front_xq_a0_sldata19_t *data19;
#endif
/* DATAX_TEMPLATE_END */

} front_xq_a0_elements_t;


/* sl_type front_xq_a0__packed_element_t front_xq_a0_packed_element_t */
typedef struct front_xq_a0__packed_element_t
{
  front_xq_a0_slkey_t key;

#ifdef front_xq_a0_SL_PACKED_INDEX
  front_xq_a0_slindex_t index;
#endif

/* DATAX_TEMPLATE_BEGIN */
#ifdef front_xq_a0_SL_DATA0
# ifdef front_xq_a0_sl_data0_flex
  front_xq_a0_sldata0_t data0[];
# else
  front_xq_a0_sldata0_t data0[front_xq_a0_sl_data0_size_c];
# endif
#endif
#ifdef front_xq_a0_SL_DATA1
# ifdef front_xq_a0_sl_data1_flex
  front_xq_a0_sldata1_t data1[];
# else
  front_xq_a0_sldata1_t data1[front_xq_a0_sl_data1_size_c];
# endif
#endif
#ifdef front_xq_a0_SL_DATA2
# ifdef front_xq_a0_sl_data2_flex
  front_xq_a0_sldata2_t data2[];
# else
  front_xq_a0_sldata2_t data2[front_xq_a0_sl_data2_size_c];
# endif
#endif
#ifdef front_xq_a0_SL_DATA3
# ifdef front_xq_a0_sl_data3_flex
  front_xq_a0_sldata3_t data3[];
# else
  front_xq_a0_sldata3_t data3[front_xq_a0_sl_data3_size_c];
# endif
#endif
#ifdef front_xq_a0_SL_DATA4
# ifdef front_xq_a0_sl_data4_flex
  front_xq_a0_sldata4_t data4[];
# else
  front_xq_a0_sldata4_t data4[front_xq_a0_sl_data4_size_c];
# endif
#endif
#ifdef front_xq_a0_SL_DATA5
# ifdef front_xq_a0_sl_data5_flex
  front_xq_a0_sldata5_t data5[];
# else
  front_xq_a0_sldata5_t data5[front_xq_a0_sl_data5_size_c];
# endif
#endif
#ifdef front_xq_a0_SL_DATA6
# ifdef front_xq_a0_sl_data6_flex
  front_xq_a0_sldata6_t data6[];
# else
  front_xq_a0_sldata6_t data6[front_xq_a0_sl_data6_size_c];
# endif
#endif
#ifdef front_xq_a0_SL_DATA7
# ifdef front_xq_a0_sl_data7_flex
  front_xq_a0_sldata7_t data7[];
# else
  front_xq_a0_sldata7_t data7[front_xq_a0_sl_data7_size_c];
# endif
#endif
#ifdef front_xq_a0_SL_DATA8
# ifdef front_xq_a0_sl_data8_flex
  front_xq_a0_sldata8_t data8[];
# else
  front_xq_a0_sldata8_t data8[front_xq_a0_sl_data8_size_c];
# endif
#endif
#ifdef front_xq_a0_SL_DATA9
# ifdef front_xq_a0_sl_data9_flex
  front_xq_a0_sldata9_t data9[];
# else
  front_xq_a0_sldata9_t data9[front_xq_a0_sl_data9_size_c];
# endif
#endif
#ifdef front_xq_a0_SL_DATA10
# ifdef front_xq_a0_sl_data10_flex
  front_xq_a0_sldata10_t data10[];
# else
  front_xq_a0_sldata10_t data10[front_xq_a0_sl_data10_size_c];
# endif
#endif
#ifdef front_xq_a0_SL_DATA11
# ifdef front_xq_a0_sl_data11_flex
  front_xq_a0_sldata11_t data11[];
# else
  front_xq_a0_sldata11_t data11[front_xq_a0_sl_data11_size_c];
# endif
#endif
#ifdef front_xq_a0_SL_DATA12
# ifdef front_xq_a0_sl_data12_flex
  front_xq_a0_sldata12_t data12[];
# else
  front_xq_a0_sldata12_t data12[front_xq_a0_sl_data12_size_c];
# endif
#endif
#ifdef front_xq_a0_SL_DATA13
# ifdef front_xq_a0_sl_data13_flex
  front_xq_a0_sldata13_t data13[];
# else
  front_xq_a0_sldata13_t data13[front_xq_a0_sl_data13_size_c];
# endif
#endif
#ifdef front_xq_a0_SL_DATA14
# ifdef front_xq_a0_sl_data14_flex
  front_xq_a0_sldata14_t data14[];
# else
  front_xq_a0_sldata14_t data14[front_xq_a0_sl_data14_size_c];
# endif
#endif
#ifdef front_xq_a0_SL_DATA15
# ifdef front_xq_a0_sl_data15_flex
  front_xq_a0_sldata15_t data15[];
# else
  front_xq_a0_sldata15_t data15[front_xq_a0_sl_data15_size_c];
# endif
#endif
#ifdef front_xq_a0_SL_DATA16
# ifdef front_xq_a0_sl_data16_flex
  front_xq_a0_sldata16_t data16[];
# else
  front_xq_a0_sldata16_t data16[front_xq_a0_sl_data16_size_c];
# endif
#endif
#ifdef front_xq_a0_SL_DATA17
# ifdef front_xq_a0_sl_data17_flex
  front_xq_a0_sldata17_t data17[];
# else
  front_xq_a0_sldata17_t data17[front_xq_a0_sl_data17_size_c];
# endif
#endif
#ifdef front_xq_a0_SL_DATA18
# ifdef front_xq_a0_sl_data18_flex
  front_xq_a0_sldata18_t data18[];
# else
  front_xq_a0_sldata18_t data18[front_xq_a0_sl_data18_size_c];
# endif
#endif
#ifdef front_xq_a0_SL_DATA19
# ifdef front_xq_a0_sl_data19_flex
  front_xq_a0_sldata19_t data19[];
# else
  front_xq_a0_sldata19_t data19[front_xq_a0_sl_data19_size_c];
# endif
#endif
/* DATAX_TEMPLATE_END */

} front_xq_a0_packed_element_t;


/* sl_type front_xq_a0__packed_elements_t front_xq_a0_packed_elements_t */
typedef struct front_xq_a0__packed_elements_t
{
  front_xq_a0_slint_t size, max_size;
  
  front_xq_a0_packed_element_t *elements;
  
} front_xq_a0_packed_elements_t;


#ifndef SLCINT_T
#define SLCINT_T
typedef long long int slcint_t;
#define slcint_fmt  "ll"
/*#define slcint_sfx  LL*/
#endif


#define SLCM_KEYS     (((slcint_t) 1) << 0)
#define SLCM_INDICES  (((slcint_t) 1) << 1)
#define SLCM_WEIGHTS  (((slcint_t) 1) << 2)

/* DATAX_TEMPLATE_BEGIN */
#define SLCM_DATA0    (((slcint_t) 1) << (3+0))
#define SLCM_DATA1    (((slcint_t) 1) << (3+1))
#define SLCM_DATA2    (((slcint_t) 1) << (3+2))
#define SLCM_DATA3    (((slcint_t) 1) << (3+3))
#define SLCM_DATA4    (((slcint_t) 1) << (3+4))
#define SLCM_DATA5    (((slcint_t) 1) << (3+5))
#define SLCM_DATA6    (((slcint_t) 1) << (3+6))
#define SLCM_DATA7    (((slcint_t) 1) << (3+7))
#define SLCM_DATA8    (((slcint_t) 1) << (3+8))
#define SLCM_DATA9    (((slcint_t) 1) << (3+9))
#define SLCM_DATA10    (((slcint_t) 1) << (3+10))
#define SLCM_DATA11    (((slcint_t) 1) << (3+11))
#define SLCM_DATA12    (((slcint_t) 1) << (3+12))
#define SLCM_DATA13    (((slcint_t) 1) << (3+13))
#define SLCM_DATA14    (((slcint_t) 1) << (3+14))
#define SLCM_DATA15    (((slcint_t) 1) << (3+15))
#define SLCM_DATA16    (((slcint_t) 1) << (3+16))
#define SLCM_DATA17    (((slcint_t) 1) << (3+17))
#define SLCM_DATA18    (((slcint_t) 1) << (3+18))
#define SLCM_DATA19    (((slcint_t) 1) << (3+19))
/* DATAX_TEMPLATE_END */

#define SLCM_DATA     (((slcint_t) 0) \
  |SLCM_DATA0 \
  |SLCM_DATA1 \
  |SLCM_DATA2 \
  |SLCM_DATA3 \
  |SLCM_DATA4 \
  |SLCM_DATA5 \
  |SLCM_DATA6 \
  |SLCM_DATA7 \
  |SLCM_DATA8 \
  |SLCM_DATA9 \
  |SLCM_DATA10 \
  |SLCM_DATA11 \
  |SLCM_DATA12 \
  |SLCM_DATA13 \
  |SLCM_DATA14 \
  |SLCM_DATA15 \
  |SLCM_DATA16 \
  |SLCM_DATA17 \
  |SLCM_DATA18 \
  |SLCM_DATA19 \
  )

#define SLCM_ALL      (~((slcint_t) 0))


/* sl_type front_xq_a0__classification_info_t front_xq_a0_classification_info_t front_xq_a0_classification_info */
typedef struct front_xq_a0__classification_info_t
{
  front_xq_a0_slint_t nclasses;
  front_xq_a0_slkey_pure_t *keys;
  front_xq_a0_slint_t *counts;
  front_xq_a0_slint_t *masks;

  /* */
  front_xq_a0_slint_t *all_local_sizes;
  front_xq_a0_slint_t *local_lt_eq_counts;
  front_xq_a0_slint_t *all_local_lt_eq_counts;

} front_xq_a0_classification_info_t, front_xq_a0_classification_info;  /* deprecated 'front_xq_a0_classification_info' */


/* key2class, sl_type front_xq_a0_key2class_f */
typedef front_xq_a0_slint_t (*front_xq_a0_key2class_f)(front_xq_a0_slkey_t *, front_xq_a0_slint, void *);

/* pivot-element, sl_type front_xq_a0_pivot_f */
typedef front_xq_a0_slint_t (*front_xq_a0_pivot_f)(front_xq_a0_elements_t *);

/* sorting-network, sl_type front_xq_a0_sortnet_f front_xq_a0_sortnet_data_t */
typedef void *front_xq_a0_sortnet_data_t;
typedef front_xq_a0_slint_t (*front_xq_a0_sortnet_f)(front_xq_a0_slint_t size, front_xq_a0_slint_t rank, front_xq_a0_slint_t stage, front_xq_a0_sortnet_data_t snd, front_xq_a0_slint_t *up);

/* merge2, sl_type front_xq_a0_merge2x_f front_xq_a0_merge2X_f */
typedef front_xq_a0_slint_t (*front_xq_a0_merge2x_f)(front_xq_a0_elements_t *s0, front_xq_a0_elements_t *s1, front_xq_a0_elements_t *sx);
typedef front_xq_a0_slint_t (*front_xq_a0_merge2X_f)(front_xq_a0_elements_t *s0, front_xq_a0_elements_t *s1, front_xq_a0_elements_t *sx, front_xq_a0_elements_t *t);

/* sl_type front_xq_a0__permute_generic_t front_xq_a0_permute_generic_t */
typedef struct front_xq_a0__permute_generic_t
{
  int type;

  front_xq_a0_spec_tloc_f *tloc;
  front_xq_a0_spec_tloc_rearrange_db_f *tloc_rearrange_db;
  front_xq_a0_spec_tloc_rearrange_ip_f *tloc_rearrange_ip;

  front_xq_a0_spec_tloc_mod_f *tloc_mod;
  front_xq_a0_spec_tloc_mod_rearrange_db_f *tloc_mod_rearrange_db;
  front_xq_a0_spec_tloc_mod_rearrange_ip_f *tloc_mod_rearrange_ip;

} front_xq_a0_permute_generic_t;

/* sl_macro front_xq_a0_PERMUTE_GENERIC_DEFINE_TLOC front_xq_a0_PERMUTE_GENERIC_INIT_TLOC front_xq_a0_PERMUTE_GENERIC_INIT_EXT_TLOC */
#define front_xq_a0_PERMUTE_GENERIC_DEFINE_TLOC(_tl_, _s_...)      front_xq_a0_SPEC_DEFINE_TLOC(_tl_, _tl_, _s_)
#define front_xq_a0_PERMUTE_GENERIC_INIT_TLOC(_tl_)                { 1, _tl_, front_xq_a0_SPEC_EXT_PARAM_TLOC_NULL,  NULL, front_xq_a0_SPEC_EXT_PARAM_TLOC_MOD_NULL }
#define front_xq_a0_PERMUTE_GENERIC_INIT_EXT_TLOC(_tl_)            { 1, _tl_, front_xq_a0_SPEC_EXT_PARAM_TLOC(_tl_), NULL, front_xq_a0_SPEC_EXT_PARAM_TLOC_MOD_NULL }

/* sl_macro front_xq_a0_PERMUTE_GENERIC_DEFINE_TLOC_MOD front_xq_a0_PERMUTE_GENERIC_INIT_TLOC_MOD front_xq_a0_PERMUTE_GENERIC_INIT_EXT_TLOC_MOD */
#define front_xq_a0_PERMUTE_GENERIC_DEFINE_TLOC_MOD(_tl_, _s_...)  front_xq_a0_SPEC_DEFINE_TLOC_MOD(_tl_, _tl_, _s_)
#define front_xq_a0_PERMUTE_GENERIC_INIT_TLOC_MOD(_tl_)            { 2, NULL, front_xq_a0_SPEC_EXT_PARAM_TLOC_MOD_NULL, _tl_, front_xq_a0_SPEC_EXT_PARAM_TLOC_MOD_NULL }
#define front_xq_a0_PERMUTE_GENERIC_INIT_EXT_TLOC_MOD(_tl_)        { 2, NULL, front_xq_a0_SPEC_EXT_PARAM_TLOC_MOD_NULL, _tl_, front_xq_a0_SPEC_EXT_PARAM_TLOC_MOD(_tl_) }

/* sl_type front_xq_a0__split_generic_t front_xq_a0_split_generic_t */
typedef struct front_xq_a0__split_generic_t
{
  int type;

  front_xq_a0_spec_tproc_f *tproc;
  front_xq_a0_spec_tproc_count_f *tproc_count_db, *tproc_count_ip;
  front_xq_a0_spec_tproc_rearrange_db_f *tproc_rearrange_db;
  front_xq_a0_spec_tproc_rearrange_ip_f *tproc_rearrange_ip;

  front_xq_a0_spec_tproc_mod_f *tproc_mod;
  front_xq_a0_spec_tproc_mod_count_f *tproc_mod_count_db, *tproc_mod_count_ip;
  front_xq_a0_spec_tproc_mod_rearrange_db_f *tproc_mod_rearrange_db;
  front_xq_a0_spec_tproc_mod_rearrange_ip_f *tproc_mod_rearrange_ip;

  front_xq_a0_spec_tprocs_f *tprocs;
  front_xq_a0_spec_tprocs_count_f *tprocs_count_db, *tprocs_count_ip;
  front_xq_a0_spec_tprocs_rearrange_db_f *tprocs_rearrange_db;
  front_xq_a0_spec_tprocs_rearrange_ip_f *tprocs_rearrange_ip;

  front_xq_a0_spec_tprocs_mod_f *tprocs_mod;
  front_xq_a0_spec_tprocs_mod_count_f *tprocs_mod_count_db, *tprocs_mod_count_ip;
  front_xq_a0_spec_tprocs_mod_rearrange_db_f *tprocs_mod_rearrange_db;
  front_xq_a0_spec_tprocs_mod_rearrange_ip_f *tprocs_mod_rearrange_ip;

  front_xq_a0_spec_tproc_reset_f *reset;

} front_xq_a0_split_generic_t;

/* sl_macro front_xq_a0_SPLIT_GENERIC_DEFINE_TPROC front_xq_a0_SPLIT_GENERIC_INIT_TPROC front_xq_a0_SPLIT_GENERIC_INIT_EXT_TPROC */
#define front_xq_a0_SPLIT_GENERIC_DEFINE_TPROC(_tp_, _s_...)         front_xq_a0_SPEC_DEFINE_TPROC(_tp_, _tp_, _s_)
#define front_xq_a0_SPLIT_GENERIC_INIT_TPROC(_tp_, _r_...)           { 1, _tp_, front_xq_a0_SPEC_EXT_PARAM_TPROC_NULL,  NULL, front_xq_a0_SPEC_EXT_PARAM_TPROC_MOD_NULL, NULL, front_xq_a0_SPEC_EXT_PARAM_TPROCS_NULL, NULL, front_xq_a0_SPEC_EXT_PARAM_TPROCS_MOD_NULL,  _r_ }
#define front_xq_a0_SPLIT_GENERIC_INIT_EXT_TPROC(_tp_, _r_...)       { 1, _tp_, front_xq_a0_SPEC_EXT_PARAM_TPROC(_tp_), NULL, front_xq_a0_SPEC_EXT_PARAM_TPROC_MOD_NULL, NULL, front_xq_a0_SPEC_EXT_PARAM_TPROCS_NULL, NULL, front_xq_a0_SPEC_EXT_PARAM_TPROCS_MOD_NULL,  _r_ }

/* sl_macro front_xq_a0_SPLIT_GENERIC_DEFINE_TPROC_MOD front_xq_a0_SPLIT_GENERIC_INIT_TPROC_MOD front_xq_a0_SPLIT_GENERIC_INIT_EXT_TPROC_MOD */
#define front_xq_a0_SPLIT_GENERIC_DEFINE_TPROC_MOD(_tp_, _s_...)     front_xq_a0_SPEC_DEFINE_TPROC_MOD(_tp_, _tp_, _s_)
#define front_xq_a0_SPLIT_GENERIC_INIT_TPROC_MOD(_tp_, _r_...)       { 2, NULL, front_xq_a0_SPEC_EXT_PARAM_TPROC_NULL, _tp_, front_xq_a0_SPEC_EXT_PARAM_TPROC_MOD_NULL,  NULL, front_xq_a0_SPEC_EXT_PARAM_TPROCS_NULL, NULL, front_xq_a0_SPEC_EXT_PARAM_TPROCS_MOD_NULL,  _r_ }
#define front_xq_a0_SPLIT_GENERIC_INIT_EXT_TPROC_MOD(_tp_, _r_...)   { 2, NULL, front_xq_a0_SPEC_EXT_PARAM_TPROC_NULL, _tp_, front_xq_a0_SPEC_EXT_PARAM_TPROC_MOD(_tp_), NULL, front_xq_a0_SPEC_EXT_PARAM_TPROCS_NULL, NULL, front_xq_a0_SPEC_EXT_PARAM_TPROCS_MOD_NULL,  _r_ }

/* sl_macro front_xq_a0_SPLIT_GENERIC_DEFINE_TPROCS front_xq_a0_SPLIT_GENERIC_INIT_TPROCS front_xq_a0_SPLIT_GENERIC_INIT_EXT_TPROCS */
#define front_xq_a0_SPLIT_GENERIC_DEFINE_TPROCS(_tp_, _s_...)        front_xq_a0_SPEC_DEFINE_TPROCS(_tp_, _tp_, _s_)
#define front_xq_a0_SPLIT_GENERIC_INIT_TPROCS(_tp_, _r_...)          { 3, NULL, front_xq_a0_SPEC_EXT_PARAM_TPROC_NULL, NULL, front_xq_a0_SPEC_EXT_PARAM_TPROC_MOD_NULL, _tp_, front_xq_a0_SPEC_EXT_PARAM_TPROCS_NULL,  NULL, front_xq_a0_SPEC_EXT_PARAM_TPROCS_MOD_NULL,  _r_ }
#define front_xq_a0_SPLIT_GENERIC_INIT_EXT_TPROCS(_tp_, _r_...)      { 3, NULL, front_xq_a0_SPEC_EXT_PARAM_TPROC_NULL, NULL, front_xq_a0_SPEC_EXT_PARAM_TPROC_MOD_NULL, _tp_, front_xq_a0_SPEC_EXT_PARAM_TPROCS(_tp_), NULL, front_xq_a0_SPEC_EXT_PARAM_TPROCS_MOD_NULL,  _r_ }

/* sl_macro front_xq_a0_SPLIT_GENERIC_DEFINE_TPROCS_MOD front_xq_a0_SPLIT_GENERIC_INIT_TPROCS_MOD front_xq_a0_SPLIT_GENERIC_INIT_EXT_TPROCS_MOD */
#define front_xq_a0_SPLIT_GENERIC_DEFINE_TPROCS_MOD(_tp_, _s_...)    front_xq_a0_SPEC_DEFINE_TPROCS_MOD(_tp_, _tp_, _s_)
#define front_xq_a0_SPLIT_GENERIC_INIT_TPROCS_MOD(_tp_, _r_...)      { 4, NULL, front_xq_a0_SPEC_EXT_PARAM_TPROC_NULL, NULL, front_xq_a0_SPEC_EXT_PARAM_TPROC_MOD_NULL, NULL, front_xq_a0_SPEC_EXT_PARAM_TPROCS_NULL,  _tp_, front_xq_a0_SPEC_EXT_PARAM_TPROCS_MOD_NULL,  _r_ }
#define front_xq_a0_SPLIT_GENERIC_INIT_EXT_TPROCS_MOD(_tp_, _r_...)  { 4, NULL, front_xq_a0_SPEC_EXT_PARAM_TPROC_NULL, NULL, front_xq_a0_SPEC_EXT_PARAM_TPROC_MOD_NULL, NULL, front_xq_a0_SPEC_EXT_PARAM_TPROCS_NULL,  _tp_, front_xq_a0_SPEC_EXT_PARAM_TPROCS_MOD(_tp_), _r_ }

/* sl_type front_xq_a0_tloc_f front_xq_a0_tloc_mod_f */
typedef front_xq_a0_slint_t front_xq_a0_tloc_f(front_xq_a0_elements_t *b, front_xq_a0_slint_t x, void *tloc_data);
typedef front_xq_a0_slint_t front_xq_a0_tloc_mod_f(front_xq_a0_elements_t *b, front_xq_a0_slint_t x, void *tloc_data, front_xq_a0_elements_t *mod);

/* sl_type front_xq_a0_tproc_f front_xq_a0_tproc_mod_f front_xq_a0_tprocs_f front_xq_a0_tprocs_mod_f */
typedef int front_xq_a0_tproc_f(front_xq_a0_elements_t *b, front_xq_a0_slint_t x, void *tproc_data);
typedef int front_xq_a0_tproc_mod_f(front_xq_a0_elements_t *b, front_xq_a0_slint_t x, void *tproc_data, front_xq_a0_elements_t *mod);
typedef front_xq_a0_slint_t front_xq_a0_tprocs_f(front_xq_a0_elements_t *b, front_xq_a0_slint_t x, void *tproc_data, int *procs);
typedef front_xq_a0_slint_t front_xq_a0_tprocs_mod_f(front_xq_a0_elements_t *b, front_xq_a0_slint_t x, void *tproc_data, int *procs, front_xq_a0_elements_t *mod);

/* sl_type front_xq_a0_tproc_reset_f */
typedef void front_xq_a0_tproc_reset_f(void *tproc_data);

/* sl_macro front_xq_a0_TPROC_RESET_NULL */
#define front_xq_a0_TPROC_RESET_NULL  NULL

/* sl_type front_xq_a0__tproc_t front_xq_a0_tproc_t */
typedef struct front_xq_a0__tproc_t *front_xq_a0_tproc_t;

/* sl_type front_xq_a0__tproc_exdef front_xq_a0_tproc_exdef */
typedef struct front_xq_a0__tproc_exdef {
  int type;

  front_xq_a0_spec_tproc_count_f *tproc_count_db, *tproc_count_ip;
  front_xq_a0_spec_tproc_rearrange_db_f *tproc_rearrange_db;
  front_xq_a0_spec_tproc_rearrange_ip_f *tproc_rearrange_ip;

  front_xq_a0_spec_tproc_mod_count_f *tproc_mod_count_db, *tproc_mod_count_ip;
  front_xq_a0_spec_tproc_mod_rearrange_db_f *tproc_mod_rearrange_db;
  front_xq_a0_spec_tproc_mod_rearrange_ip_f *tproc_mod_rearrange_ip;

  front_xq_a0_spec_tprocs_count_f *tprocs_count_db, *tprocs_count_ip;
  front_xq_a0_spec_tprocs_rearrange_db_f *tprocs_rearrange_db;
  front_xq_a0_spec_tprocs_rearrange_ip_f *tprocs_rearrange_ip;

  front_xq_a0_spec_tprocs_mod_count_f *tprocs_mod_count_db, *tprocs_mod_count_ip;
  front_xq_a0_spec_tprocs_mod_rearrange_db_f *tprocs_mod_rearrange_db;
  front_xq_a0_spec_tprocs_mod_rearrange_ip_f *tprocs_mod_rearrange_ip;

} const *front_xq_a0_tproc_exdef;

/* sl_macro front_xq_a0_TPROC_EXDEF_NULL */
#define front_xq_a0_TPROC_EXDEF_NULL  NULL

/* sl_macro front_xq_a0_TPROC_EXDEF_DEFINE_TPROC front_xq_a0_TPROC_EXDEF_DEFINE_TPROC_MOD front_xq_a0_TPROC_EXDEF_DEFINE_TPROCS front_xq_a0_TPROC_EXDEF_DEFINE_TPROCS_MOD */
#define front_xq_a0_TPROC_EXDEF_DEFINE_TPROC(_name_, _tp_, _s_...) \
  front_xq_a0_SPEC_DEFINE_TPROC(_name_, _tp_, _s_) \
  _s_ const struct front_xq_a0__tproc_exdef _##_name_ = { 1, front_xq_a0_SPEC_EXT_PARAM_TPROC(_name_), front_xq_a0_SPEC_EXT_PARAM_TPROC_MOD_NULL, front_xq_a0_SPEC_EXT_PARAM_TPROCS_NULL, front_xq_a0_SPEC_EXT_PARAM_TPROCS_MOD_NULL }, *_name_ = &_##_name_;

#define front_xq_a0_TPROC_EXDEF_DEFINE_TPROC_MOD(_name_, _tp_, _s_...) \
  front_xq_a0_SPEC_DEFINE_TPROC_MOD(_name_, _tp_, _s_) \
  _s_ const struct front_xq_a0__tproc_exdef _##_name_ = { 2, front_xq_a0_SPEC_EXT_PARAM_TPROC_NULL, front_xq_a0_SPEC_EXT_PARAM_TPROC_MOD(_name_), front_xq_a0_SPEC_EXT_PARAM_TPROCS_NULL, front_xq_a0_SPEC_EXT_PARAM_TPROCS_MOD_NULL }, *_name_ = &_##_name_;

#define front_xq_a0_TPROC_EXDEF_DEFINE_TPROCS(_name_, _tp_, _s_...) \
  front_xq_a0_SPEC_DEFINE_TPROCS(_name_, _tp_, _s_) \
  _s_ const struct front_xq_a0__tproc_exdef _##_name_ = { 3, front_xq_a0_SPEC_EXT_PARAM_TPROC_NULL, front_xq_a0_SPEC_EXT_PARAM_TPROC_MOD_NULL, front_xq_a0_SPEC_EXT_PARAM_TPROCS(_name_), front_xq_a0_SPEC_EXT_PARAM_TPROCS_MOD_NULL }, *_name_ = &_##_name_;

#define front_xq_a0_TPROC_EXDEF_DEFINE_TPROCS_MOD(_name_, _tp_, _s_...) \
  front_xq_a0_SPEC_DEFINE_TPROCS_MOD(_name_, _tp_, _s_) \
  _s_ const struct front_xq_a0__tproc_exdef _##_name_ = { 4, front_xq_a0_SPEC_EXT_PARAM_TPROC_NULL, front_xq_a0_SPEC_EXT_PARAM_TPROC_MOD_NULL, front_xq_a0_SPEC_EXT_PARAM_TPROCS_NULL, front_xq_a0_SPEC_EXT_PARAM_TPROCS_MOD(_name_) }, *_name_ = &_##_name_;


/* deprecated, sl_type front_xq_a0_k2c_func front_xq_a0_pivot_func front_xq_a0_sn_func front_xq_a0_m2x_func front_xq_a0_m2X_func */
typedef front_xq_a0_key2class_f front_xq_a0_k2c_func;
typedef front_xq_a0_pivot_f front_xq_a0_pivot_func;
typedef front_xq_a0_sortnet_f front_xq_a0_sn_func;
typedef front_xq_a0_merge2x_f front_xq_a0_m2x_func;
typedef front_xq_a0_merge2X_f front_xq_a0_m2X_func;


/* sl_type front_xq_a0__mergek_t front_xq_a0_mergek_t */
typedef struct front_xq_a0__mergek_t
{
  front_xq_a0_sortnet_f sn;
  front_xq_a0_sortnet_data_t snd;

  front_xq_a0_merge2x_f m2x;
  front_xq_a0_elements_t *sx;

} front_xq_a0_mergek_t;


/* sl_type front_xq_a0_keys_init_type_t front_xq_a0_keys_init_data_t */
typedef front_xq_a0_slint_t front_xq_a0_keys_init_type_t;
typedef void *front_xq_a0_keys_init_data_t;

/* sl_type front_xq_a0_key_set_data_t front_xq_a0_key_set_f */
typedef void *front_xq_a0_key_set_data_t;
typedef void (*front_xq_a0_key_set_f)(front_xq_a0_slkey_pure_t *k, front_xq_a0_key_set_data_t d);


#undef SL_EKIT_SET
#define SL_EKIT_SET         1
#undef SL_EKIT_SET_FUNC
#define SL_EKIT_SET_FUNC    2
#undef SL_EKIT_RAND
#define SL_EKIT_RAND        3
#undef SL_EKIT_RAND_QUAD
#define SL_EKIT_RAND_QUAD   4
#undef SL_EKIT_RAND_AND
#define SL_EKIT_RAND_AND    5
#undef SL_EKIT_URAND
#define SL_EKIT_URAND       6
#undef SL_EKIT_NRAND
#define SL_EKIT_NRAND       7


#ifndef SL_EIK_OFFSET
# define SL_EIK_OFFSET     65536LL
#endif

#ifndef SL_EIK_SET
# define SL_EIK_SET        SL_EIK_OFFSET*1
#endif

#ifndef SL_EIK_RAND
# define SL_EIK_RAND       SL_EIK_OFFSET*2
#endif

#ifndef SL_EIK_RAND_QUAD
# define SL_EIK_RAND_QUAD  SL_EIK_OFFSET*3
#endif

#ifndef SL_EIK_RAND_AND
# define SL_EIK_RAND_AND   SL_EIK_OFFSET*4
#endif

#ifndef SL_EIK_RAND_NORM
# define SL_EIK_RAND_NORM  SL_EIK_OFFSET*5
#endif


/* front_xq_a0_elements_keys_stats */
#ifndef SL_EKS_MIN
# define SL_EKS_MIN   0
#endif

#ifndef SL_EKS_MAX
# define SL_EKS_MAX   1
#endif

#ifndef SL_EKS_SUM
# define SL_EKS_SUM   2
#endif

#ifndef SL_EKS_AVG
# define SL_EKS_AVG   3
#endif

#ifndef SL_EKS_STD
# define SL_EKS_STD   4
#endif

#ifndef SL_EKS_SIZE
# define SL_EKS_SIZE  5
#endif


#ifndef SL_SORTED_IN
# define SL_SORTED_IN   0x1LL
#endif

#ifndef SL_SORTED_OUT
# define SL_SORTED_OUT  0x2LL
#endif


#ifndef SL_MSEG_FM_EXACT
# define SL_MSEG_FM_EXACT         0
#endif
#ifndef SL_MSEG_FM_ALLORNOTHING
# define SL_MSEG_FM_ALLORNOTHING  1
#endif
#ifndef SL_MSEG_FM_MIDDLE
# define SL_MSEG_FM_MIDDLE        2
#endif


/* partition conditions, sl_type front_xq_a0__partcond2_t front_xq_a0_partcond2_t */
typedef struct front_xq_a0__partcond2_t
{
  int weighted;
  double min_count, max_count;
  double min_weight, max_weight;
  double min_cpart, max_cpart;
  double min_wpart, max_wpart;

} front_xq_a0_partcond2_t;


#ifndef SLPC_COUNTS_MM
# define SLPC_COUNTS_MM   0x1
#endif
#ifndef SLPC_COUNTS_LH
# define SLPC_COUNTS_LH   0x2
#endif
#ifndef SLPC_WEIGHTS_MM
# define SLPC_WEIGHTS_MM  0x4
#endif
#ifndef SLPC_WEIGHTS_LH
# define SLPC_WEIGHTS_LH  0x8
#endif

/* partition conditions, sl_type front_xq_a0__partcond_t front_xq_a0_partcond_t front_xq_a0_partcond_p */
typedef struct front_xq_a0__partcond_t
{
  front_xq_a0_slint_t pcm;
  double count_min, count_max;
  double count_low, count_high;
  double weight_min, weight_max;
  double weight_low, weight_high;

} front_xq_a0_partcond_t, *front_xq_a0_partcond_p;


/* internal partition conditions, sl_type front_xq_a0__partcond_intern_t front_xq_a0_partcond_intern_t front_xq_a0_partcond_intern_p */
typedef struct front_xq_a0__partcond_intern_t
{
  front_xq_a0_slint_t pcm;
  front_xq_a0_slint_t count_min, count_max;
  front_xq_a0_slint_t count_low, count_high;
#ifdef elem_weight
  front_xq_a0_slweight_t weight_min, weight_max;
  front_xq_a0_slweight_t weight_low, weight_high;
#endif

} front_xq_a0_partcond_intern_t, *front_xq_a0_partcond_intern_p;


/* sl_type front_xq_a0__parttype_t front_xq_a0_parttype_t front_xq_a0_parttype_p */
typedef struct front_xq_a0__parttype_t
{
  front_xq_a0_slint_t type;

} front_xq_a0_parttype_t, *front_xq_a0_parttype_p;


/* generic binning method */

/* sl_type front_xq_a0__bin_t front_xq_a0_bin_t */
typedef struct front_xq_a0__bin_t
{
  front_xq_a0_elements_t s;

#ifdef elem_weight
  front_xq_a0_slweight_t weight;
#endif

} front_xq_a0_bin_t;


/* sl_type front_xq_a0__splitter_t front_xq_a0_splitter_t */
typedef struct front_xq_a0__splitter_t
{
  front_xq_a0_slint_t n;

  int *displs;
  front_xq_a0_slkey_pure_t *s;
  front_xq_a0_slint_t *sn;

} front_xq_a0_splitter_t;


struct front_xq_a0__binning_t;

/* sl_type front_xq_a0_binning_pre_f front_xq_a0_binning_exec_f front_xq_a0_binning_refine_f front_xq_a0_binning_hit_f front_xq_a0_binning_finalize_f front_xq_a0_binning_post_f */
typedef front_xq_a0_slint_t (*front_xq_a0_binning_pre_f)(struct front_xq_a0__binning_t *bm);
typedef front_xq_a0_slint_t (*front_xq_a0_binning_exec_f)(struct front_xq_a0__binning_t *bm, front_xq_a0_bin_t *bin, front_xq_a0_slcount_t *counts, front_xq_a0_slweight_t *weights);
typedef front_xq_a0_slint_t (*front_xq_a0_binning_refine_f)(struct front_xq_a0__binning_t *bm, front_xq_a0_bin_t *bin, front_xq_a0_slint_t k, front_xq_a0_slcount_t *counts, front_xq_a0_slweight_t *weights, front_xq_a0_splitter_t *sp, front_xq_a0_slint_t s, front_xq_a0_bin_t *new_bin);
typedef front_xq_a0_slint_t (*front_xq_a0_binning_hit_f)(struct front_xq_a0__binning_t *bm, front_xq_a0_bin_t *bin, front_xq_a0_slint_t k, front_xq_a0_slcount_t *counts, front_xq_a0_splitter_t *sp, front_xq_a0_slint_t s);
typedef front_xq_a0_slint_t (*front_xq_a0_binning_finalize_f)(struct front_xq_a0__binning_t *bm, front_xq_a0_bin_t *bin, front_xq_a0_slint_t dc, front_xq_a0_slweight_t dw, front_xq_a0_slint_t lc_min, front_xq_a0_slint_t lc_max, front_xq_a0_slcount_t *lcs, front_xq_a0_slweight_t *lws, front_xq_a0_splitter_t *sp, front_xq_a0_slint_t s);
typedef front_xq_a0_slint_t (*front_xq_a0_binning_post_f)(struct front_xq_a0__binning_t *bm);


/* sl_type front_xq_a0__binning_data_t front_xq_a0_binning_data_t */
typedef union front_xq_a0__binning_data_t
{
  struct
  {
    front_xq_a0_slint_t rhigh, rlow, rwidth;
    front_xq_a0_slint_t rcurrent;
    front_xq_a0_slkey_pure_t bit_mask;

    front_xq_a0_elements_t sx;

  } radix;

} front_xq_a0_binning_data_t;


/* sl_type front_xq_a0__binning_t front_xq_a0_binning_t */
typedef struct front_xq_a0__binning_t
{
  front_xq_a0_slint_t nbins, max_nbins;
  
  front_xq_a0_binning_pre_f pre;
  front_xq_a0_binning_exec_f exec;
  front_xq_a0_binning_refine_f refine;
  front_xq_a0_binning_hit_f hit;
  front_xq_a0_binning_finalize_f finalize;
  front_xq_a0_binning_post_f post;

  front_xq_a0_slint_t sorted;

  front_xq_a0_slint_t docounts;
#ifdef elem_weight
  front_xq_a0_slint_t doweights;
#endif

  front_xq_a0_binning_data_t bd;

} front_xq_a0_binning_t;


/* sl_type front_xq_a0__local_bins_t front_xq_a0_local_bins_t */
typedef struct front_xq_a0__local_bins_t
{
  front_xq_a0_binning_t *bm;

  front_xq_a0_slint_t nbins, max_nbins;
  front_xq_a0_slint_t nelements;

  front_xq_a0_slint_t docounts;
#ifdef elem_weight
  front_xq_a0_slint_t doweights;
#endif

  front_xq_a0_slint_t nbinnings, max_nbinnings;

  front_xq_a0_slint_t nbins_new, last_new_b, last_new_k;
  front_xq_a0_bin_t *bins, *bins_new;
  front_xq_a0_bin_t *bins0, *bins1;

  front_xq_a0_slint_t *bcws;

#if defined(elem_weight) && defined(front_xq_a0_sl_weight_intequiv)
  front_xq_a0_slint_t cw_factor, w_index, bin_cw_factor;
  front_xq_a0_slweight_t *cws, *bin_cws;
  front_xq_a0_slweight_t *prefix_cws;
#else
  front_xq_a0_slint_t *cs, *bin_cs;
  front_xq_a0_slint_t *prefix_cs;
# ifdef elem_weight
  front_xq_a0_slweight_t *ws, *bin_ws;
  front_xq_a0_slweight_t *prefix_ws;
# endif
#endif

  front_xq_a0_slint_t last_exec_b;

} front_xq_a0_local_bins_t;


/* sl_type front_xq_a0__global_bins_t front_xq_a0_global_bins_t */
typedef struct front_xq_a0__global_bins_t
{
  front_xq_a0_binning_t *bm;
  
  front_xq_a0_local_bins_t lb;

  front_xq_a0_slint_t *bcws;

#if defined(elem_weight) && defined(front_xq_a0_sl_weight_intequiv)
  front_xq_a0_slweight_t *cws;
  front_xq_a0_slweight_t *prefix_cws;
#else
  front_xq_a0_slint_t *cs;
  front_xq_a0_slint_t *prefix_cs;
# ifdef elem_weight
  front_xq_a0_slweight_t *ws;
  front_xq_a0_slweight_t *prefix_ws;
# endif
#endif

} front_xq_a0_global_bins_t;


/* sl_type front_xq_a0_rti_cmc_t */
typedef struct
{
  front_xq_a0_slint_t cmp, movek, moved;

} front_xq_a0_rti_cmc_t;

#ifndef my_rti_ccmp
# define my_rti_ccmp(m)    m.cmc.cmp
# define my_rti_cmovek(m)  m.cmc.movek
# define my_rti_cmoved(m)  m.cmc.moved
#endif


/* sl_type front_xq_a0_rti_tim_t */
typedef struct
{
  double start, stop;
  double last, cumu;

  front_xq_a0_slint_t num;

} front_xq_a0_rti_tim_t[rti_tids];

#ifndef my_rti_tlast
# define my_rti_tlast(m, t)  m.tim[t].last
# define my_rti_tcumu(m, t)  m.tim[t].cumu
# define my_rti_tnum(m, t)   m.tim[t].num
#endif


/* sl_type front_xq_a0_rti_mem_t */
typedef struct
{
  front_xq_a0_slint_t nalloc, nfree;
  front_xq_a0_slint_t max, cur, cur_max;

} front_xq_a0_rti_mem_t;


/* sl_type front_xq_a0_rti_t */
typedef struct
{
  /* compare-move-counter */
  front_xq_a0_rti_cmc_t cmc;
  /* timer */
  front_xq_a0_rti_tim_t tim;
  /* memory */
  front_xq_a0_rti_mem_t mem;

} front_xq_a0_rti_t;

#ifndef my_rti_reset
# define my_rti_reset(m)  memset((void *) &m, 0, sizeof(m))
#endif


/* sl_type front_xq_a0__sl_context_t front_xq_a0_sl_context_t */
typedef struct front_xq_a0__sl_context_t
{

/* src/base/base.c */
  struct {
int dummy_rank;
  } sl;
#ifdef front_xq_a0_SL_USE_RTI
front_xq_a0_rti_t rti;
#endif
  struct {
front_xq_a0_slint_t ip_threshold;
front_xq_a0_slint_t db_threshold;
front_xq_a0_slint_t ma_threshold;
  } sr;
  struct {
front_xq_a0_slint_t threshold;
  } sri;
/* src/base_mpi/base_mpi.c */
#ifdef SL_USE_MPI
  struct {
MPI_Datatype int_datatype;
MPI_Datatype key_datatype;
MPI_Datatype pkey_datatype;
MPI_Datatype pwkey_datatype;
MPI_Datatype index_datatype;
MPI_Datatype weight_datatype;
MPI_Datatype data_datatype[SL_DATA_NMAX + 1];
int rank;
  } mpi;
#endif
#ifdef SL_USE_MPI
  struct {
void *sendrecv_replace_mem;
front_xq_a0_slint_t sendrecv_replace_memsize;
front_xq_a0_slint_t sendrecv_replace_mpi_maxsize;
  } me;
#endif
#ifdef SL_USE_MPI
  struct {
double t[2];
front_xq_a0_slint_t max_nprocs;
front_xq_a0_slint_t packed;
front_xq_a0_slint_t minalloc;
double overalloc;
  } meas;
#endif
#ifdef SL_USE_MPI
  struct {
front_xq_a0_slint_t packed;
front_xq_a0_slint_t db_packed;
front_xq_a0_slint_t ip_packed;
  } mea;
#endif
#ifdef SL_USE_MPI
  struct {
#ifdef front_xq_a0_MSEG_ROOT
int root;
#endif
#ifdef front_xq_a0_MSEG_BORDER_UPDATE_REDUCTION
double border_update_count_reduction;
double border_update_weight_reduction;
#endif
#ifdef front_xq_a0_MSEG_FORWARD_ONLY
front_xq_a0_slint_t forward_only;
#endif
#ifdef front_xq_a0_MSEG_INFO
front_xq_a0_slint_t info_rounds;
front_xq_a0_slint_t *info_finish_rounds;
double info_finish_rounds_avg;
front_xq_a0_slweight_t info_total_weights;
#endif
front_xq_a0_slint_t binnings;
front_xq_a0_slint_t finalize_mode;
  } mseg;
#endif
#ifdef SL_USE_MPI
  struct {
#ifdef front_xq_a0_MSS_ROOT
int root;
#endif
  } mss;
#endif
#ifdef SL_USE_MPI
  struct {
double t[4];
front_xq_a0_slint_t sync;
  } msm;
#endif
#ifdef SL_USE_MPI
  struct {
double t[4];
front_xq_a0_slint_t sync;
front_xq_a0_partcond_t *r_pc;
  } msp;
#endif
#ifdef SL_USE_MPI
  struct {
double i_t[3];
double p_t[3];
double b_t[3];
front_xq_a0_slint_t sync;
front_xq_a0_slint_t i_sync;
front_xq_a0_slint_t p_sync;
front_xq_a0_slint_t b_sync;
front_xq_a0_slint_t back_packed;
  } mssp;
#endif
} front_xq_a0_sl_context_t;






/* sl_macro front_xq_a0_elem_set_size front_xq_a0_elem_set_max_size front_xq_a0_elem_set_keys front_xq_a0_elem_set_indices */
#define front_xq_a0_elem_set_size(_e_, _s_)      ((_e_)->size = (_s_))
#define front_xq_a0_elem_set_max_size(_e_, _s_)  ((_e_)->max_size = (_s_))
#define front_xq_a0_elem_set_keys(_e_, _k_)      ((_e_)->keys = (_k_))
#define front_xq_a0_elem_set_indices(_e_, _i_)   ((_e_)->indices = (_i_))
/* DATAX_TEMPLATE_BEGIN */
#define front_xq_a0_elem_set_data0(_e_, _b_)     ((_e_)->data0 = (_b_))  /* sl_macro */
#define front_xq_a0_elem_set_data1(_e_, _b_)     ((_e_)->data1 = (_b_))  /* sl_macro */
#define front_xq_a0_elem_set_data2(_e_, _b_)     ((_e_)->data2 = (_b_))  /* sl_macro */
#define front_xq_a0_elem_set_data3(_e_, _b_)     ((_e_)->data3 = (_b_))  /* sl_macro */
#define front_xq_a0_elem_set_data4(_e_, _b_)     ((_e_)->data4 = (_b_))  /* sl_macro */
#define front_xq_a0_elem_set_data5(_e_, _b_)     ((_e_)->data5 = (_b_))  /* sl_macro */
#define front_xq_a0_elem_set_data6(_e_, _b_)     ((_e_)->data6 = (_b_))  /* sl_macro */
#define front_xq_a0_elem_set_data7(_e_, _b_)     ((_e_)->data7 = (_b_))  /* sl_macro */
#define front_xq_a0_elem_set_data8(_e_, _b_)     ((_e_)->data8 = (_b_))  /* sl_macro */
#define front_xq_a0_elem_set_data9(_e_, _b_)     ((_e_)->data9 = (_b_))  /* sl_macro */
#define front_xq_a0_elem_set_data10(_e_, _b_)     ((_e_)->data10 = (_b_))  /* sl_macro */
#define front_xq_a0_elem_set_data11(_e_, _b_)     ((_e_)->data11 = (_b_))  /* sl_macro */
#define front_xq_a0_elem_set_data12(_e_, _b_)     ((_e_)->data12 = (_b_))  /* sl_macro */
#define front_xq_a0_elem_set_data13(_e_, _b_)     ((_e_)->data13 = (_b_))  /* sl_macro */
#define front_xq_a0_elem_set_data14(_e_, _b_)     ((_e_)->data14 = (_b_))  /* sl_macro */
#define front_xq_a0_elem_set_data15(_e_, _b_)     ((_e_)->data15 = (_b_))  /* sl_macro */
#define front_xq_a0_elem_set_data16(_e_, _b_)     ((_e_)->data16 = (_b_))  /* sl_macro */
#define front_xq_a0_elem_set_data17(_e_, _b_)     ((_e_)->data17 = (_b_))  /* sl_macro */
#define front_xq_a0_elem_set_data18(_e_, _b_)     ((_e_)->data18 = (_b_))  /* sl_macro */
#define front_xq_a0_elem_set_data19(_e_, _b_)     ((_e_)->data19 = (_b_))  /* sl_macro */
/* DATAX_TEMPLATE_END */

/* sl_macro front_xq_a0_elem_get_size front_xq_a0_elem_get_max_size front_xq_a0_elem_get_keys front_xq_a0_elem_get_indices */
#define front_xq_a0_elem_get_size(_e_)           (_e_)->size
#define front_xq_a0_elem_get_max_size(_e_)       (_e_)->max_size
#define front_xq_a0_elem_get_keys(_e_)           (_e_)->keys
#define front_xq_a0_elem_get_indices(_e_)        (_e_)->indices
/* DATAX_TEMPLATE_BEGIN */
#define front_xq_a0_elem_get_data0(_e_)          (_e_)->data0  /* sl_macro */
#define front_xq_a0_elem_get_data1(_e_)          (_e_)->data1  /* sl_macro */
#define front_xq_a0_elem_get_data2(_e_)          (_e_)->data2  /* sl_macro */
#define front_xq_a0_elem_get_data3(_e_)          (_e_)->data3  /* sl_macro */
#define front_xq_a0_elem_get_data4(_e_)          (_e_)->data4  /* sl_macro */
#define front_xq_a0_elem_get_data5(_e_)          (_e_)->data5  /* sl_macro */
#define front_xq_a0_elem_get_data6(_e_)          (_e_)->data6  /* sl_macro */
#define front_xq_a0_elem_get_data7(_e_)          (_e_)->data7  /* sl_macro */
#define front_xq_a0_elem_get_data8(_e_)          (_e_)->data8  /* sl_macro */
#define front_xq_a0_elem_get_data9(_e_)          (_e_)->data9  /* sl_macro */
#define front_xq_a0_elem_get_data10(_e_)          (_e_)->data10  /* sl_macro */
#define front_xq_a0_elem_get_data11(_e_)          (_e_)->data11  /* sl_macro */
#define front_xq_a0_elem_get_data12(_e_)          (_e_)->data12  /* sl_macro */
#define front_xq_a0_elem_get_data13(_e_)          (_e_)->data13  /* sl_macro */
#define front_xq_a0_elem_get_data14(_e_)          (_e_)->data14  /* sl_macro */
#define front_xq_a0_elem_get_data15(_e_)          (_e_)->data15  /* sl_macro */
#define front_xq_a0_elem_get_data16(_e_)          (_e_)->data16  /* sl_macro */
#define front_xq_a0_elem_get_data17(_e_)          (_e_)->data17  /* sl_macro */
#define front_xq_a0_elem_get_data18(_e_)          (_e_)->data18  /* sl_macro */
#define front_xq_a0_elem_get_data19(_e_)          (_e_)->data19  /* sl_macro */
/* DATAX_TEMPLATE_END */

/* sl_macro front_xq_a0_elem_set_block front_xq_a0_elem_set_block_size front_xq_a0_elem_get_block front_xq_a0_elem_get_block_size */
#define front_xq_a0_elem_set_block(_e_, _b_)       ((_e_)->keys = (_b_), (_e_)->max_size = -1)
#define front_xq_a0_elem_set_block_size(_e_, _s_)  ((_e_)->size = (_s_))
#define front_xq_a0_elem_get_block(_e_)            ((void *) (((_e_)->max_size < 0)?(_e_)->keys:NULL))
#define front_xq_a0_elem_get_block_size(_e_)       (_e_)->size

/* sl_macro front_xq_a0_pelem_set_size front_xq_a0_pelem_set_max_size front_xq_a0_pelem_set_elements */
#define front_xq_a0_pelem_set_size(_e_, _s_)      ((_e_)->size = (_s_))
#define front_xq_a0_pelem_set_max_size(_e_, _s_)  ((_e_)->max_size = (_s_))
#define front_xq_a0_pelem_set_elements(_e_, _l_)  ((_e_)->elements = (_l_))

/* sl_macro front_xq_a0_pelem_get_size front_xq_a0_pelem_get_max_size front_xq_a0_pelem_get_elements */
#define front_xq_a0_pelem_get_size(_e_)           (_e_)->size
#define front_xq_a0_pelem_get_max_size(_e_)       (_e_)->max_size
#define front_xq_a0_pelem_get_elements(_e_)       (_e_)->elements

/* sl_macro front_xq_a0_SL_DEFCON */
#define front_xq_a0_SL_DEFCON(_v_)  (front_xq_a0_sl_default_context._v_)






/* src/base/base.c */
extern front_xq_a0_sl_context_t front_xq_a0_sl_default_context;
extern const int front_xq_a0_default_sl_dummy_rank;
#ifdef front_xq_a0_SL_USE_RTI
extern const front_xq_a0_rti_t front_xq_a0_default_rti;
#endif
extern const front_xq_a0_slint_t front_xq_a0_default_sr_ip_threshold;
extern const front_xq_a0_slint_t front_xq_a0_default_sr_db_threshold;
extern const front_xq_a0_slint_t front_xq_a0_default_sr_ma_threshold;
extern const front_xq_a0_slint_t front_xq_a0_default_sri_threshold;

/* src/base_mpi/base_mpi.c */
#ifdef SL_USE_MPI
extern const MPI_Datatype front_xq_a0_default_mpi_int_datatype;
extern const MPI_Datatype front_xq_a0_default_mpi_key_datatype;
extern const MPI_Datatype front_xq_a0_default_mpi_pkey_datatype;
extern const MPI_Datatype front_xq_a0_default_mpi_pwkey_datatype;
extern const MPI_Datatype front_xq_a0_default_mpi_index_datatype;
extern const MPI_Datatype front_xq_a0_default_mpi_weight_datatype;
extern const MPI_Datatype front_xq_a0_default_mpi_data_datatype[];
extern const int front_xq_a0_default_mpi_rank;
#endif
extern const void *front_xq_a0_default_me_sendrecv_replace_mem;
extern const front_xq_a0_slint_t front_xq_a0_default_me_sendrecv_replace_memsize;
extern const front_xq_a0_slint_t front_xq_a0_default_me_sendrecv_replace_mpi_maxsize;
extern const double front_xq_a0_default_meas_t[];
extern const front_xq_a0_slint_t front_xq_a0_default_meas_max_nprocs;
extern const front_xq_a0_slint_t front_xq_a0_default_meas_packed;
extern const front_xq_a0_slint_t front_xq_a0_default_meas_minalloc;
extern const double front_xq_a0_default_meas_overalloc;
extern const front_xq_a0_slint_t front_xq_a0_default_mea_packed;
extern const front_xq_a0_slint_t front_xq_a0_default_mea_db_packed;
extern const front_xq_a0_slint_t front_xq_a0_default_mea_ip_packed;
#ifdef front_xq_a0_MSEG_ROOT
extern const int front_xq_a0_default_mseg_root;
#endif
#ifdef front_xq_a0_MSEG_BORDER_UPDATE_REDUCTION
extern const double front_xq_a0_default_mseg_border_update_count_reduction;
extern const double front_xq_a0_default_mseg_border_update_weight_reduction;
#endif
#ifdef front_xq_a0_MSEG_FORWARD_ONLY
extern const front_xq_a0_slint_t front_xq_a0_default_mseg_forward_only;
#endif
#ifdef front_xq_a0_MSEG_INFO
extern const front_xq_a0_slint_t front_xq_a0_default_mseg_info_rounds;
extern const front_xq_a0_slint_t *front_xq_a0_default_mseg_info_finish_rounds;
extern const double front_xq_a0_default_mseg_info_finish_rounds_avg;
extern const front_xq_a0_slweight_t front_xq_a0_default_mseg_info_total_weights;
#endif
extern const front_xq_a0_slint_t front_xq_a0_default_mseg_binnings;
extern const front_xq_a0_slint_t front_xq_a0_default_mseg_finalize_mode;
#ifdef front_xq_a0_MSS_ROOT
extern const int front_xq_a0_default_mss_root;
#endif
extern const double front_xq_a0_default_msm_t[];
extern const front_xq_a0_slint_t front_xq_a0_default_msm_sync;
extern const double front_xq_a0_default_msp_t[];
extern const front_xq_a0_slint_t front_xq_a0_default_msp_sync;
extern const front_xq_a0_partcond_t *front_xq_a0_default_msp_r_pc;
extern const double front_xq_a0_default_mssp_i_t[];
extern const double front_xq_a0_default_mssp_p_t[];
extern const double front_xq_a0_default_mssp_b_t[];
extern const front_xq_a0_slint_t front_xq_a0_default_mssp_sync;
extern const front_xq_a0_slint_t front_xq_a0_default_mssp_i_sync;
extern const front_xq_a0_slint_t front_xq_a0_default_mssp_p_sync;
extern const front_xq_a0_slint_t front_xq_a0_default_mssp_b_sync;
extern const front_xq_a0_slint_t front_xq_a0_default_mssp_back_packed;






/* src/base/base.c */
front_xq_a0_slint_t SL_PROTO(front_xq_a0_binning_create)(front_xq_a0_local_bins_t *lb, front_xq_a0_slint_t max_nbins, front_xq_a0_slint_t max_nbinnings, front_xq_a0_elements_t *s, front_xq_a0_slint_t nelements, front_xq_a0_slint_t docounts, front_xq_a0_slint_t doweights, front_xq_a0_binning_t *bm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_binning_destroy)(front_xq_a0_local_bins_t *lb);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_binning_pre)(front_xq_a0_local_bins_t *lb);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_binning_exec_reset)(front_xq_a0_local_bins_t *lb, front_xq_a0_slint_t do_bins, front_xq_a0_slint_t do_prefixes);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_binning_exec)(front_xq_a0_local_bins_t *lb, front_xq_a0_slint_t b, front_xq_a0_slint_t do_bins, front_xq_a0_slint_t do_prefixes);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_binning_refine)(front_xq_a0_local_bins_t *lb, front_xq_a0_slint_t b, front_xq_a0_slint_t k, front_xq_a0_splitter_t *sp, front_xq_a0_slint_t s);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_binning_hit)(front_xq_a0_local_bins_t *lb, front_xq_a0_slint_t b, front_xq_a0_slint_t k, front_xq_a0_splitter_t *sp, front_xq_a0_slint_t s);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_binning_finalize)(front_xq_a0_local_bins_t *lb, front_xq_a0_slint_t b, front_xq_a0_slint_t dc, front_xq_a0_slweight_t dw, front_xq_a0_slint_t lc_min, front_xq_a0_slint_t lc_max, front_xq_a0_slcount_t *lcs, front_xq_a0_slweight_t *lws, front_xq_a0_splitter_t *sp, front_xq_a0_slint_t s);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_binning_post)(front_xq_a0_local_bins_t *lb);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_binning_radix_create)(front_xq_a0_binning_t *bm, front_xq_a0_slint_t rhigh, front_xq_a0_slint_t rlow, front_xq_a0_slint_t rwidth, front_xq_a0_slint_t sorted);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_binning_radix_destroy)(front_xq_a0_binning_t *bm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_binning_radix_pre)(front_xq_a0_binning_t *bm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_binning_radix_exec)(front_xq_a0_binning_t *bm, front_xq_a0_bin_t *bin, front_xq_a0_slcount_t *counts, front_xq_a0_slweight_t *weights);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_binning_radix_refine)(front_xq_a0_binning_t *bm, front_xq_a0_bin_t *bin, front_xq_a0_slint_t k, front_xq_a0_slcount_t *counts, front_xq_a0_slweight_t *weights, front_xq_a0_splitter_t *sp, front_xq_a0_slint_t s, front_xq_a0_bin_t *new_bin);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_binning_radix_hit)(front_xq_a0_binning_t *bm, front_xq_a0_bin_t *bin, front_xq_a0_slint_t k, front_xq_a0_slcount_t *counts, front_xq_a0_splitter_t *sp, front_xq_a0_slint_t s);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_binning_radix_finalize)(front_xq_a0_binning_t *bm, front_xq_a0_bin_t *bin, front_xq_a0_slint_t dc, front_xq_a0_slweight_t dw, front_xq_a0_slint_t lc_min, front_xq_a0_slint_t lc_max, front_xq_a0_slcount_t *lcs, front_xq_a0_slweight_t *lws, front_xq_a0_splitter_t *sp, front_xq_a0_slint_t s);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_binning_radix_post)(front_xq_a0_binning_t *bm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_alloc)(front_xq_a0_elements_t *s, front_xq_a0_slint_t nelements, slcint_t components);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_free)(front_xq_a0_elements_t *s);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_realloc)(front_xq_a0_elements_t *s, front_xq_a0_slint_t nelements, slcint_t components);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_alloca)(front_xq_a0_elements_t *s, front_xq_a0_slint_t nelements, slcint_t components);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_freea)(front_xq_a0_elements_t *s);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_alloc_from_blocks)(front_xq_a0_elements_t *s, front_xq_a0_slint_t nblocks, void **blocks, front_xq_a0_slint_t *blocksizes, front_xq_a0_slint_t alignment, front_xq_a0_slint_t nmax, slcint_t components);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_alloc_from_block)(front_xq_a0_elements_t *s, void *block, front_xq_a0_slint_t blocksize, front_xq_a0_slint_t alignment, front_xq_a0_slint_t nmax, slcint_t components);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_alloc_block)(front_xq_a0_elements_t *s, void **block, front_xq_a0_slint_t *blocksize, front_xq_a0_slint_t alignment, front_xq_a0_slint_t maxblocksize);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_copy)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *d);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_copy_at)(front_xq_a0_elements_t *s, front_xq_a0_slint_t sat, front_xq_a0_elements_t *d, front_xq_a0_slint_t dat);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_ncopy)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *d, front_xq_a0_slint_t n);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_nmove)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *d, front_xq_a0_slint_t n);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_printf)(front_xq_a0_elements_t *s, const char *prefix);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_extract)(front_xq_a0_elements_t *src, front_xq_a0_slint_t nelements, front_xq_a0_elements_t *dst0, front_xq_a0_elements_t *dst1);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_touch)(front_xq_a0_elements_t *s);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_digest_sum)(front_xq_a0_elements_t *s, front_xq_a0_slint_t nelements, slcint_t components, unsigned int *sum);
unsigned int SL_PROTO(front_xq_a0_elements_crc32)(front_xq_a0_elements_t *s, front_xq_a0_slint nelements, front_xq_a0_slint_t keys, front_xq_a0_slint_t data);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_digest_hash)(front_xq_a0_elements_t *s, front_xq_a0_slint_t nelements, slcint_t components, void *hash);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_random_exchange)(front_xq_a0_elements_t *s, front_xq_a0_slint_t rounds, front_xq_a0_elements_t *xs);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_keys_init_seed)(unsigned long s);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_keys_init)(front_xq_a0_elements_t *s, front_xq_a0_keys_init_type_t t, front_xq_a0_keys_init_data_t d);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_keys_init_randomized)(front_xq_a0_elements_t *s, front_xq_a0_slint_t nkeys, front_xq_a0_keys_init_type_t t, front_xq_a0_keys_init_data_t d);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_keys_init_from_file)(front_xq_a0_elements_t *s, front_xq_a0_slint_t data, char *filename, front_xq_a0_slint_t from, front_xq_a0_slint_t to, front_xq_a0_slint_t const_bytes_per_line);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_keys_save_to_file)(front_xq_a0_elements_t *s, char *filename);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_validate_order)(front_xq_a0_elements_t *s, front_xq_a0_slint_t n);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_validate_order_bmask)(front_xq_a0_elements_t *s, front_xq_a0_slint_t n, front_xq_a0_slkey_pure_t bmask);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_validate_order_weight)(front_xq_a0_elements_t *s, front_xq_a0_slint_t n, front_xq_a0_slkey_pure_t weight);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_keys_stats)(front_xq_a0_elements_t *s, front_xq_a0_slkey_pure_t *stats);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_keys_stats_print)(front_xq_a0_elements_t *s);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_print_keys)(front_xq_a0_elements_t *s);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_print_all)(front_xq_a0_elements_t *s);
front_xq_a0_slweight_t SL_PROTO(front_xq_a0_elements_get_weight)(front_xq_a0_elements_t *s);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_get_minmax_keys)(front_xq_a0_elements_t *s, front_xq_a0_slint_t nelements, front_xq_a0_slkey_pure_t *minmaxkeys);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_alloc_packed)(front_xq_a0_packed_elements_t *s, front_xq_a0_slint_t nelements);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_free_packed)(front_xq_a0_packed_elements_t *s);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_alloc_packed_from_block)(front_xq_a0_packed_elements_t *s, void *block, front_xq_a0_slint_t blocksize, front_xq_a0_slint_t alignment, front_xq_a0_slint_t nmax);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_pack_indexed)(front_xq_a0_elements_t *s, front_xq_a0_packed_elements_t *d, front_xq_a0_slindex_t *rindx, front_xq_a0_slindex_t *windx);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_pack)(front_xq_a0_elements_t *s, front_xq_a0_packed_elements_t *d);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_pack_at)(front_xq_a0_elements_t *s, front_xq_a0_slint_t sat, front_xq_a0_packed_elements_t *d, front_xq_a0_slint_t dat);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_unpack_indexed)(front_xq_a0_packed_elements_t *s, front_xq_a0_elements_t *d, front_xq_a0_slindex_t *rindx, front_xq_a0_slindex_t *windx);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_unpack)(front_xq_a0_packed_elements_t *s, front_xq_a0_elements_t *d);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_unpack_at)(front_xq_a0_packed_elements_t *s, front_xq_a0_slint_t sat, front_xq_a0_elements_t *d, front_xq_a0_slint_t dat);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elements_unpack_keys)(front_xq_a0_packed_elements_t *s, front_xq_a0_slkey_t *k);
front_xq_a0_slint SL_PROTO(front_xq_a0_merge2_basic_auto_01_x)(front_xq_a0_elements_t *s0, front_xq_a0_elements_t *s1, front_xq_a0_elements_t *sx);
front_xq_a0_slint SL_PROTO(front_xq_a0_merge2_basic_01_x)(front_xq_a0_elements_t *s0, front_xq_a0_elements_t *s1, front_xq_a0_elements_t *sx, front_xq_a0_m2x_func _x0_1, front_xq_a0_m2x_func _0x_1);
front_xq_a0_slint SL_PROTO(front_xq_a0_merge2_basic_01_X)(front_xq_a0_elements_t *s0, front_xq_a0_elements_t *s1, front_xq_a0_elements_t *sx, front_xq_a0_elements_t *t, front_xq_a0_m2X_func _X0_1, front_xq_a0_m2X_func _0X_1);
front_xq_a0_slint SL_PROTO(front_xq_a0_merge2_simplify_s1)(front_xq_a0_elements_t *s0, front_xq_a0_elements_t *s1, front_xq_a0_elements_t *sx, front_xq_a0_slint s1elements);
front_xq_a0_slint SL_PROTO(front_xq_a0_merge2_memory_adaptive)(front_xq_a0_elements_t *s0, front_xq_a0_elements_t *s1, front_xq_a0_elements_t *sx);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_merge2_compo_hula)(front_xq_a0_elements_t *s0, front_xq_a0_elements_t *s1, front_xq_a0_elements_t *xs);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_merge2_basic_sseq_x0_1)(front_xq_a0_elements_t *s0, front_xq_a0_elements_t *s1, front_xq_a0_elements_t *sx);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_merge2_basic_sseq_0x_1)(front_xq_a0_elements_t *s0, front_xq_a0_elements_t *s1, front_xq_a0_elements_t *sx);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_merge2_basic_sseq_01_x)(front_xq_a0_elements_t *s0, front_xq_a0_elements_t *s1, front_xq_a0_elements_t *sx);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_merge2_basic_sseq_01)(front_xq_a0_elements_t *s0, front_xq_a0_elements_t *s1, front_xq_a0_elements_t *t);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_merge2_basic_sbin_x0_1)(front_xq_a0_elements_t *s0, front_xq_a0_elements_t *s1, front_xq_a0_elements_t *sx);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_merge2_basic_sbin_0x_1)(front_xq_a0_elements_t *s0, front_xq_a0_elements_t *s1, front_xq_a0_elements_t *sx);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_merge2_basic_sbin_01_x)(front_xq_a0_elements_t *s0, front_xq_a0_elements_t *s1, front_xq_a0_elements_t *sx);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_merge2_basic_sbin_01)(front_xq_a0_elements_t *s0, front_xq_a0_elements_t *s1, front_xq_a0_elements_t *t);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_merge2_basic_shyb_x0_1)(front_xq_a0_elements_t *s0, front_xq_a0_elements_t *s1, front_xq_a0_elements_t *sx);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_merge2_basic_shyb_0x_1)(front_xq_a0_elements_t *s0, front_xq_a0_elements_t *s1, front_xq_a0_elements_t *sx);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_merge2_basic_shyb_01_x)(front_xq_a0_elements_t *s0, front_xq_a0_elements_t *s1, front_xq_a0_elements_t *sx);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_merge2_basic_shyb_01)(front_xq_a0_elements_t *s0, front_xq_a0_elements_t *s1, front_xq_a0_elements_t *t);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_merge2_basic_straight_x0_1)(front_xq_a0_elements_t *s0, front_xq_a0_elements_t *s1, front_xq_a0_elements_t *sx);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_merge2_basic_straight_0x_1)(front_xq_a0_elements_t *s0, front_xq_a0_elements_t *s1, front_xq_a0_elements_t *sx);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_merge2_basic_straight_01_x)(front_xq_a0_elements_t *s0, front_xq_a0_elements_t *s1, front_xq_a0_elements_t *sx);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_merge2_basic_straight_x_0_1)(front_xq_a0_elements_t *s0, front_xq_a0_elements_t *s1, front_xq_a0_elements_t *sx);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_merge2_basic_straight_X0_1)(front_xq_a0_elements_t *s0, front_xq_a0_elements_t *s1, front_xq_a0_elements_t *sx, front_xq_a0_elements_t *t);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_merge2_basic_straight_0X_1)(front_xq_a0_elements_t *s0, front_xq_a0_elements_t *s1, front_xq_a0_elements_t *sx, front_xq_a0_elements_t *t);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_merge2_basic_straight_01_X)(front_xq_a0_elements_t *s0, front_xq_a0_elements_t *s1, front_xq_a0_elements_t *sx, front_xq_a0_elements_t *t);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_merge2_basic_straight_X0_1u)(front_xq_a0_elements_t *s0, front_xq_a0_elements_t *s1, front_xq_a0_elements_t *sx, front_xq_a0_elements_t *t);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_merge2_compo_tridgell)(front_xq_a0_elements_t *s0, front_xq_a0_elements_t *s1, front_xq_a0_elements_t *sx);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mergep_2way_ip_int)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *sx, front_xq_a0_slint_t p, int *displs, front_xq_a0_merge2x_f m2x);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mergep_2way_ip_int_rec)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *sx, front_xq_a0_slint_t p, int *displs, front_xq_a0_merge2x_f m2x);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mergep_heap_int)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *d, front_xq_a0_slint_t p, int *displs, int *counts);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mergep_heap_int_idx)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *d, front_xq_a0_slint_t p, int *displs, int *counts);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mergep_heap_idx)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *d, front_xq_a0_slint_t p, front_xq_a0_slindex_t *displs, front_xq_a0_slindex_t *counts);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mergep_heap_unpack_idx)(front_xq_a0_packed_elements_t *s, front_xq_a0_elements_t *d, front_xq_a0_slint_t p, front_xq_a0_slindex_t *displs, front_xq_a0_slindex_t *counts);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mergep_heap_unpack_idxonly)(front_xq_a0_packed_elements_t *s, front_xq_a0_elements_t *d, front_xq_a0_slint_t p, front_xq_a0_slindex_t *displs, front_xq_a0_slindex_t *counts);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_permute_generic_db)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *d, front_xq_a0_permute_generic_t *pg, void *pg_data);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_permute_generic_ip)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *x, front_xq_a0_permute_generic_t *pg, void *pg_data);
front_xq_a0_slint SL_PROTO(front_xq_a0_sl_search_sequential_lt)(front_xq_a0_elements_t *s, front_xq_a0_slpkey_t k);
front_xq_a0_slint SL_PROTO(front_xq_a0_sl_search_sequential_le)(front_xq_a0_elements_t *s, front_xq_a0_slpkey_t k);
front_xq_a0_slint SL_PROTO(front_xq_a0_sl_search_sequential_gt)(front_xq_a0_elements_t *s, front_xq_a0_slpkey_t k);
front_xq_a0_slint SL_PROTO(front_xq_a0_sl_search_sequential_ge)(front_xq_a0_elements_t *s, front_xq_a0_slpkey_t k);
front_xq_a0_slint SL_PROTO(front_xq_a0_sl_search_p_sequential_lt)(front_xq_a0_elements_t *s, front_xq_a0_slpkey_t *k);
front_xq_a0_slint SL_PROTO(front_xq_a0_sl_search_p_sequential_le)(front_xq_a0_elements_t *s, front_xq_a0_slpkey_t *k);
front_xq_a0_slint SL_PROTO(front_xq_a0_sl_search_p_sequential_gt)(front_xq_a0_elements_t *s, front_xq_a0_slpkey_t *k);
front_xq_a0_slint SL_PROTO(front_xq_a0_sl_search_p_sequential_ge)(front_xq_a0_elements_t *s, front_xq_a0_slpkey_t *k);
front_xq_a0_slint SL_PROTO(front_xq_a0_sl_search_binary_lt)(front_xq_a0_elements_t *s, front_xq_a0_slpkey_t k);
front_xq_a0_slint SL_PROTO(front_xq_a0_sl_search_binary_le)(front_xq_a0_elements_t *s, front_xq_a0_slpkey_t k);
front_xq_a0_slint SL_PROTO(front_xq_a0_sl_search_binary_gt)(front_xq_a0_elements_t *s, front_xq_a0_slpkey_t k);
front_xq_a0_slint SL_PROTO(front_xq_a0_sl_search_binary_ge)(front_xq_a0_elements_t *s, front_xq_a0_slpkey_t k);
front_xq_a0_slint SL_PROTO(front_xq_a0_sl_search_p_binary_lt)(front_xq_a0_elements_t *s, front_xq_a0_slpkey_t *k);
front_xq_a0_slint SL_PROTO(front_xq_a0_sl_search_p_binary_le)(front_xq_a0_elements_t *s, front_xq_a0_slpkey_t *k);
front_xq_a0_slint SL_PROTO(front_xq_a0_sl_search_p_binary_gt)(front_xq_a0_elements_t *s, front_xq_a0_slpkey_t *k);
front_xq_a0_slint SL_PROTO(front_xq_a0_sl_search_p_binary_ge)(front_xq_a0_elements_t *s, front_xq_a0_slpkey_t *k);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_sl_search_binary_lt_bmask)(front_xq_a0_elements_t *s, front_xq_a0_slpkey_t k, front_xq_a0_slpkey_t bmask);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_sl_search_binary_le_bmask)(front_xq_a0_elements_t *s, front_xq_a0_slpkey_t k, front_xq_a0_slpkey_t bmask);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_sl_search_binary_sign_switch)(front_xq_a0_elements_t *s);
front_xq_a0_slint SL_PROTO(front_xq_a0_sl_search_hybrid_lt)(front_xq_a0_elements_t *s, front_xq_a0_slpkey_t k, front_xq_a0_slint t);
front_xq_a0_slint SL_PROTO(front_xq_a0_sl_search_hybrid_le)(front_xq_a0_elements_t *s, front_xq_a0_slpkey_t k, front_xq_a0_slint t);
front_xq_a0_slint SL_PROTO(front_xq_a0_sl_search_hybrid_gt)(front_xq_a0_elements_t *s, front_xq_a0_slpkey_t k, front_xq_a0_slint t);
front_xq_a0_slint SL_PROTO(front_xq_a0_sl_search_hybrid_ge)(front_xq_a0_elements_t *s, front_xq_a0_slpkey_t k, front_xq_a0_slint t);
front_xq_a0_slint SL_PROTO(front_xq_a0_sl_search_p_hybrid_lt)(front_xq_a0_elements_t *s, front_xq_a0_slpkey_t *k, front_xq_a0_slint t);
front_xq_a0_slint SL_PROTO(front_xq_a0_sl_search_p_hybrid_le)(front_xq_a0_elements_t *s, front_xq_a0_slpkey_t *k, front_xq_a0_slint t);
front_xq_a0_slint SL_PROTO(front_xq_a0_sl_search_p_hybrid_gt)(front_xq_a0_elements_t *s, front_xq_a0_slpkey_t *k, front_xq_a0_slint t);
front_xq_a0_slint SL_PROTO(front_xq_a0_sl_search_p_hybrid_ge)(front_xq_a0_elements_t *s, front_xq_a0_slpkey_t *k, front_xq_a0_slint t);
front_xq_a0_slint SL_PROTO(front_xq_a0_ilog2c)(front_xq_a0_slint x);
front_xq_a0_slint SL_PROTO(front_xq_a0_ilog2f)(front_xq_a0_slint x);
front_xq_a0_slint SL_PROTO(front_xq_a0_print_bits)(front_xq_a0_slint v);
front_xq_a0_slint SL_PROTO(front_xq_a0_pivot_random)(front_xq_a0_elements_t *s);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_counts2displs)(front_xq_a0_slint_t n, int *counts, int *displs);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_displs2counts)(front_xq_a0_slint_t n, int *displs, int *counts, front_xq_a0_slint_t total_counts);
void SL_PROTO(front_xq_a0_get_displcounts_extent)(front_xq_a0_slint_t n, int *displs, int *counts, front_xq_a0_slint_t *lb, front_xq_a0_slint_t *extent);
void SL_PROTO(front_xq_a0_elem_set_data)(front_xq_a0_elements_t *e, ...);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elem_get_max_byte)();
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elem_reverse)(front_xq_a0_elements_t *e, front_xq_a0_elements_t *t);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elem_nxchange_at)(front_xq_a0_elements_t *e0, front_xq_a0_slint_t at0, front_xq_a0_elements_t *e1, front_xq_a0_slint_t at1, front_xq_a0_slint_t n, front_xq_a0_elements_t *t);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elem_nxchange)(front_xq_a0_elements_t *e0, front_xq_a0_elements_t *e1, front_xq_a0_slint_t n, front_xq_a0_elements_t *t);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elem_nxchange_ro0)(front_xq_a0_elements_t *e0, front_xq_a0_elements_t *e1, front_xq_a0_slint_t n, front_xq_a0_elements_t *t);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elem_rotate)(front_xq_a0_elements_t *e, front_xq_a0_slint_t m, front_xq_a0_slint_t n, front_xq_a0_elements_t *t);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elem_rotate_ro0)(front_xq_a0_elements_t *e, front_xq_a0_slint_t m, front_xq_a0_slint_t n, front_xq_a0_elements_t *t);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_elem_rotate_ro1)(front_xq_a0_elements_t *e, front_xq_a0_slint_t m, front_xq_a0_slint_t n, front_xq_a0_elements_t *t);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_sort_counting_use_displs)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *d, front_xq_a0_slint_t ndispls, front_xq_a0_slint_t *displs);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_sort_counting_use_counts)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *d, front_xq_a0_slint_t ncounts, front_xq_a0_slint_t *counts);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_sort_counting_get_counts)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *d, front_xq_a0_slint_t ncounts, front_xq_a0_slint_t *counts);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_sort_counting)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *d, front_xq_a0_slint_t ncounts);
front_xq_a0_slint SL_PROTO(front_xq_a0_sort_heap)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *xs);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_sort_insert_bmask_kernel)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *sx, front_xq_a0_slkey_pure_t bmask);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_sort_insert)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *sx);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_sort_permute_forward)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *sx, front_xq_a0_slint_t *perm, front_xq_a0_slint_t offset, front_xq_a0_slint_t mask_bit);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_sort_permute_backward)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *sx, front_xq_a0_slint_t *perm, front_xq_a0_slint_t offset, front_xq_a0_slint_t mask_bit);
front_xq_a0_slint SL_PROTO(front_xq_a0_sort_quick)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *xs);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_sort_radix_ip)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *sx, front_xq_a0_slint_t rhigh, front_xq_a0_slint_t rlow, front_xq_a0_slint_t rwidth);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_sort_radix_db)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *sx, front_xq_a0_slint_t rhigh, front_xq_a0_slint_t rlow, front_xq_a0_slint_t rwidth);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_sort_radix_ma)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *sx, front_xq_a0_slint_t rhigh, front_xq_a0_slint_t rlow, front_xq_a0_slint_t rwidth);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_sort_radix)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *sx, front_xq_a0_slint_t rhigh, front_xq_a0_slint_t rlow, front_xq_a0_slint_t rwidth);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_sort_radix_1bit_kernel)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *sx, front_xq_a0_slint_t rhigh, front_xq_a0_slint_t rlow);
front_xq_a0_slint SL_PROTO(front_xq_a0_sort_radix_1bit)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *sx, front_xq_a0_slint_t rhigh, front_xq_a0_slint_t rlow);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_sort_radix_iter)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *sx, front_xq_a0_slint_t presorted, front_xq_a0_slint_t rhigh, front_xq_a0_slint_t rlow, front_xq_a0_slint_t rwidth);
front_xq_a0_slint SL_PROTO(front_xq_a0_sn_hypercube_lh)(front_xq_a0_slint size, front_xq_a0_slint rank, front_xq_a0_slint stage, void *snp, front_xq_a0_slint *up);
front_xq_a0_slint SL_PROTO(front_xq_a0_sn_hypercube_hl)(front_xq_a0_slint size, front_xq_a0_slint rank, front_xq_a0_slint stage, void *snp, front_xq_a0_slint *up);
front_xq_a0_slint SL_PROTO(front_xq_a0_sn_odd_even_trans)(front_xq_a0_slint size, front_xq_a0_slint rank, front_xq_a0_slint stage, void *snp, front_xq_a0_slint *up);
front_xq_a0_slint SL_PROTO(front_xq_a0_sn_odd)(front_xq_a0_slint size, front_xq_a0_slint rank, front_xq_a0_slint stage, void *snp, front_xq_a0_slint *up);
front_xq_a0_slint SL_PROTO(front_xq_a0_sn_even)(front_xq_a0_slint size, front_xq_a0_slint rank, front_xq_a0_slint stage, void *snp, front_xq_a0_slint *up);
front_xq_a0_slint SL_PROTO(front_xq_a0_sn_batcher)(front_xq_a0_slint size, front_xq_a0_slint rank, front_xq_a0_slint stage, void *snp, front_xq_a0_slint *up);
front_xq_a0_slint SL_PROTO(front_xq_a0_sn_bitonic)(front_xq_a0_slint size, front_xq_a0_slint rank, front_xq_a0_slint stage, void *snp, front_xq_a0_slint *up);
front_xq_a0_slint SL_PROTO(front_xq_a0_sn_connected)(front_xq_a0_slint size, front_xq_a0_slint rank, front_xq_a0_slint stage, void *snp, front_xq_a0_slint *up);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_split_generic_db)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *d, front_xq_a0_split_generic_t *sg, void *sg_data, front_xq_a0_slint_t n);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_split_generic_ip)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *d, front_xq_a0_split_generic_t *sg, void *sg_data, front_xq_a0_slint_t n);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_split_generic_count_db)(front_xq_a0_elements_t *s, front_xq_a0_split_generic_t *sg, void *sg_data, int *counts, front_xq_a0_slint_t n);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_split_generic_count_ip)(front_xq_a0_elements_t *s, front_xq_a0_split_generic_t *sg, void *sg_data, int *counts, front_xq_a0_slint_t n);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_split_generic_rearrange_db)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *d, front_xq_a0_split_generic_t *sg, void *sg_data, int *counts, front_xq_a0_slint_t n);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_split_generic_rearrange_ip)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *d, front_xq_a0_split_generic_t *sg, void *sg_data, int *counts, int *displs, front_xq_a0_slint_t n);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_splitter_reset)(front_xq_a0_splitter_t *sp);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_splitx_radix)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *sx, front_xq_a0_slint_t nclasses, front_xq_a0_slint_t shl, front_xq_a0_slint_t *counts);
front_xq_a0_slint SL_PROTO(front_xq_a0_split2_lt_ge)(front_xq_a0_elements_t *s, front_xq_a0_slkey_pure_t *k, front_xq_a0_elements_t *t);
front_xq_a0_slint SL_PROTO(front_xq_a0_split2_le_gt)(front_xq_a0_elements_t *s, front_xq_a0_slkey_pure_t *k, front_xq_a0_elements_t *t);
front_xq_a0_slint SL_PROTO(front_xq_a0_split3_lt_eq_gt)(front_xq_a0_elements_t *s, front_xq_a0_slkey_pure_t *k, front_xq_a0_elements_t *t, front_xq_a0_slint *nlt, front_xq_a0_slint *nle);
front_xq_a0_slint SL_PROTO(front_xq_a0_split3_lt_eq_gt_old)(front_xq_a0_elements_t *s, front_xq_a0_slkey_pure_t *k, front_xq_a0_elements_t *t, front_xq_a0_slint *nlt, front_xq_a0_slint *nle);
front_xq_a0_slint SL_PROTO(front_xq_a0_split2_b)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *sx, front_xq_a0_slkey_pure_t bmask);
front_xq_a0_slint SL_PROTO(front_xq_a0_splitk_k2c_af)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *sx, front_xq_a0_slint k, front_xq_a0_slint *c, front_xq_a0_k2c_func k2c, void *k2c_data);
front_xq_a0_slint SL_PROTO(front_xq_a0_splitk_k2c)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *sx, front_xq_a0_slint k, front_xq_a0_slint *c, front_xq_a0_k2c_func k2c, void *k2c_data);
front_xq_a0_slint SL_PROTO(front_xq_a0_splitk_k2c_count)(front_xq_a0_elements_t *s, front_xq_a0_slint k, front_xq_a0_slint *c, front_xq_a0_k2c_func k2c, void *k2c_data);


#ifdef SL_USE_MPI





/* src/base_mpi/base_mpi.c */
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_binning_create)(front_xq_a0_global_bins_t *gb, front_xq_a0_slint_t max_nbins, front_xq_a0_slint_t max_nbinnings, front_xq_a0_elements_t *s, front_xq_a0_slint_t nelements, front_xq_a0_slint_t docounts, front_xq_a0_slint_t doweights, front_xq_a0_binning_t *bm, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_binning_destroy)(front_xq_a0_global_bins_t *gb, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_binning_pre)(front_xq_a0_global_bins_t *gb, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_binning_exec_reset)(front_xq_a0_global_bins_t *gb, front_xq_a0_slint_t do_bins, front_xq_a0_slint_t do_prefixes, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_binning_exec_local)(front_xq_a0_global_bins_t *gb, front_xq_a0_slint_t b, front_xq_a0_slint_t do_bins, front_xq_a0_slint_t do_prefixes, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_binning_exec_global)(front_xq_a0_global_bins_t *gb, front_xq_a0_slint_t do_bins, front_xq_a0_slint_t do_prefixes, front_xq_a0_slint_t root, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_binning_refine)(front_xq_a0_global_bins_t *gb, front_xq_a0_slint_t b, front_xq_a0_slint_t k, front_xq_a0_splitter_t *sp, front_xq_a0_slint_t s, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_binning_hit)(front_xq_a0_global_bins_t *gb, front_xq_a0_slint_t b, front_xq_a0_slint_t k, front_xq_a0_splitter_t *sp, front_xq_a0_slint_t s, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_binning_finalize)(front_xq_a0_global_bins_t *gb, front_xq_a0_slint_t b, front_xq_a0_slint_t dc, front_xq_a0_slweight_t dw, front_xq_a0_slint_t lc_min, front_xq_a0_slint_t lc_max, front_xq_a0_slcount_t *lcs, front_xq_a0_slweight_t *lws, front_xq_a0_splitter_t *sp, front_xq_a0_slint_t s, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_binning_post)(front_xq_a0_global_bins_t *gb, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_datatypes_init)();
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_datatypes_release)();
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_get_grid_properties)(front_xq_a0_slint_t ndims, front_xq_a0_slint_t *dims, front_xq_a0_slint_t *pos, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_subgroups_create)(front_xq_a0_slint_t nsubgroups, MPI_Comm *sub_comms, int *sub_sizes, int *sub_ranks, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_subgroups_delete)(front_xq_a0_slint_t nsubgroups, MPI_Comm *sub_comms, int size, int rank, MPI_Comm comm);
int SL_PROTO(front_xq_a0_sl_MPI_Allreduce)(void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, int size, int rank);
int SL_PROTO(front_xq_a0_sl_MPI_Alltoall_int)(void *sendbuf, int sendcount, void *recvbuf, int recvcount, MPI_Comm comm, int size, int rank);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_elements_keys_init_from_file)(front_xq_a0_elements_t *s, char *filename, front_xq_a0_slint from, front_xq_a0_slint to, front_xq_a0_slint const_bytes_per_line, front_xq_a0_slint root, int size, int rank, MPI_Comm comm);
front_xq_a0_slint SL_PROTO(front_xq_a0_mpi_elements_validate_order)(front_xq_a0_elements_t *s, front_xq_a0_slint n, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_linear_exchange_pure_keys)(front_xq_a0_slkey_pure_t *in, front_xq_a0_slkey_pure_t *out, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_elements_check_order)(front_xq_a0_elements_t *s, front_xq_a0_slint_t nelements, front_xq_a0_slint_t *orders, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_check_global_order)(front_xq_a0_slkey_pure_t local_min, front_xq_a0_slkey_pure_t local_max, int root, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_elements_digest_sum)(front_xq_a0_elements_t *s, front_xq_a0_slint_t nelements, slcint_t components, unsigned int *sum, int size, int rank, MPI_Comm comm);
unsigned int SL_PROTO(front_xq_a0_mpi_elements_crc32)(front_xq_a0_elements_t *s, front_xq_a0_slint_t n, front_xq_a0_slint_t keys, front_xq_a0_slint_t data, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_elements_digest_hash)(front_xq_a0_elements_t *s, front_xq_a0_slint_t nelements, slcint_t components, void *hash, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_elements_get_counts)(front_xq_a0_elements_t *s, front_xq_a0_slint_t *clocal, front_xq_a0_slint_t *cglobal, int root, int size, int rank, MPI_Comm comm);
front_xq_a0_slweight_t SL_PROTO(front_xq_a0_mpi_elements_get_weights)(front_xq_a0_elements_t *s, front_xq_a0_slweight_t *wlocal, front_xq_a0_slweight_t *wglobal, int root, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_elements_get_counts_and_weights)(front_xq_a0_elements_t *s, front_xq_a0_slint_t nelements, front_xq_a0_slint_t *counts, front_xq_a0_slweight_t *weights, int root, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_elements_sendrecv_replace)(front_xq_a0_elements_t *s, int count, int dest, int sendtag, int source, int recvtag, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_tproc_create_tproc)(front_xq_a0_tproc_t *tproc, front_xq_a0_tproc_f *tfn, front_xq_a0_tproc_reset_f *rfn, front_xq_a0_tproc_exdef exdef);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_tproc_create_tproc_mod)(front_xq_a0_tproc_t *tproc, front_xq_a0_tproc_mod_f *tfn, front_xq_a0_tproc_reset_f *rfn, front_xq_a0_tproc_exdef exdef);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_tproc_create_tprocs)(front_xq_a0_tproc_t *tproc, front_xq_a0_tprocs_f *tfn, front_xq_a0_tproc_reset_f *rfn, front_xq_a0_tproc_exdef exdef);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_tproc_create_tprocs_mod)(front_xq_a0_tproc_t *tproc, front_xq_a0_tprocs_mod_f *tfn, front_xq_a0_tproc_reset_f *rfn, front_xq_a0_tproc_exdef exdef);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_tproc_free)(front_xq_a0_tproc_t *tproc);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_tproc_set_proclists)(front_xq_a0_tproc_t *tproc, front_xq_a0_slint_t nsend_procs, int *send_procs, front_xq_a0_slint_t nrecv_procs, int *recv_procs, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_tproc_verify)(front_xq_a0_tproc_t tproc, void *data, front_xq_a0_elements_t *s, int proc);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_elements_alltoall_specific)(front_xq_a0_elements_t *sin, front_xq_a0_elements_t *sout, front_xq_a0_elements_t *xs, front_xq_a0_tproc_t tproc, void *data, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_elements_alltoallv_db_packed)(front_xq_a0_elements_t *sbuf, int *scounts, int *sdispls, front_xq_a0_elements_t *rbuf, int *rcounts, int *rdispls, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_elements_alltoallv_db)(front_xq_a0_elements_t *sbuf, int *scounts, int *sdispls, front_xq_a0_elements_t *rbuf, int *rcounts, int *rdispls, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_elements_alltoallv_ip_packed)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *sx, int *scounts, int *sdispls, int *rcounts, int *rdispls, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_elements_alltoallv_ip_double)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *sx, int *scounts, int *sdispls, int *rcounts, int *rdispls, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_elements_alltoallv_ip_mpi)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *sx, int *scounts, int *sdispls, int *rcounts, int *rdispls, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_elements_alltoallv_ip_dash)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *sx, int *scounts, int *sdispls, int *rcounts, int *rdispls, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_elements_alltoallv_ip)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *sx, int *scounts, int *sdispls, int *rcounts, int *rdispls, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_elements_alltoallv_proclists_db)(front_xq_a0_elements_t *sbuf, int *scounts, int *sdispls, int nsendprocs, int *sendprocs, front_xq_a0_elements_t *rbuf, int *rcounts, int *rdispls, int nrecvprocs, int *recvprocs, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_elements_packed_datatype_create)(MPI_Datatype *pdt, front_xq_a0_slint_t structured);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_elements_packed_datatype_destroy)(MPI_Datatype *pdt);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_find_exact_equal)(front_xq_a0_elements_t *s, front_xq_a0_slint_t other_rank, front_xq_a0_slint_t high_rank, front_xq_a0_slint_t *ex_start, front_xq_a0_slint_t *ex_size, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_find_exact)(front_xq_a0_elements_t *s, front_xq_a0_slint_t other_rank, front_xq_a0_slint_t high_rank, front_xq_a0_slint_t *dst_size, front_xq_a0_slint_t *ex_start, front_xq_a0_slint_t *ex_sizes, front_xq_a0_slint_t *nx_move, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_merge2)(front_xq_a0_elements_t *s, front_xq_a0_slint_t other_rank, front_xq_a0_slint_t high_rank, front_xq_a0_slint_t *dst_size, front_xq_a0_merge2x_f m2, front_xq_a0_elements_t *xs, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_mergek_equal)(front_xq_a0_elements_t *s, front_xq_a0_sortnet_f sn, front_xq_a0_sortnet_data_t snd, front_xq_a0_merge2x_f m2x, front_xq_a0_elements_t *xs, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_mergek_sorted)(front_xq_a0_elements_t *s, front_xq_a0_merge2x_f m2x, front_xq_a0_elements_t *xs, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_mergek_sorted2)(front_xq_a0_elements_t *s, front_xq_a0_sortnet_f sn, front_xq_a0_sortnet_data_t snd, front_xq_a0_merge2x_f m2x, front_xq_a0_elements_t *xs, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_mergek)(front_xq_a0_elements_t *s, front_xq_a0_sortnet_f sn, front_xq_a0_sortnet_data_t snd, front_xq_a0_merge2x_f m2x, front_xq_a0_elements_t *xs, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_mergek_equal2)(front_xq_a0_elements_t *s, front_xq_a0_sortnet_f sn, front_xq_a0_sortnet_data_t snd, front_xq_a0_merge2x_f m2x, front_xq_a0_elements_t *xs, int *sizes, int *ranks, MPI_Comm *comms);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_partition_exact_generic)(front_xq_a0_elements_t *s, front_xq_a0_partcond_t *pcond, front_xq_a0_binning_t *bm, int *scounts, int *rcounts, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_partition_exact_radix)(front_xq_a0_elements_t *s, front_xq_a0_partcond_t *pcond, front_xq_a0_slint_t rhigh, front_xq_a0_slint_t rlow, front_xq_a0_slint_t rwidth, front_xq_a0_slint_t sorted, int *scounts, int *rcounts, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_partition_exact_radix_ngroups)(front_xq_a0_elements_t *s, front_xq_a0_partcond_t *pcond, front_xq_a0_slint_t ngroups, MPI_Comm *group_comms, front_xq_a0_elements_t *sx, front_xq_a0_slint_t rhigh, front_xq_a0_slint_t rlow, front_xq_a0_slint_t rwidth, int *scounts, int *rcounts, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_partition_exact_radix_2groups)(front_xq_a0_elements_t *s, front_xq_a0_partcond_t *pcond, MPI_Comm group_comm, front_xq_a0_elements_t *sx, front_xq_a0_slint_t rhigh, front_xq_a0_slint_t rlow, front_xq_a0_slint_t rwidth, int *scounts, int *rcounts, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_partition_sample_regular)(front_xq_a0_elements_t *s, front_xq_a0_partcond_t *pcond, int *scounts, int *rcounts, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_rebalance)(front_xq_a0_elements_t *s0, front_xq_a0_elements_t *s1, front_xq_a0_slint_t stable, front_xq_a0_slint_t *dst_size, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_rebalance_alltoallv)(front_xq_a0_elements_t *sbuf, int *scounts, int *sdispls, front_xq_a0_elements_t *rbuf, int *rcounts, int *rdispls, int size, int rank, MPI_Comm comm);
void SL_PROTO(front_xq_a0_mpi_partcond_set_even)(front_xq_a0_partcond_t *pcond, front_xq_a0_slint_t pcm, front_xq_a0_slint_t ntotal, double nimba, double wtotal, double wimba, int size, int rank);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_init_partconds)(front_xq_a0_slint_t npconds, front_xq_a0_partcond_t *pconds, front_xq_a0_slint_t nparts, front_xq_a0_slint_t total_count, front_xq_a0_slweight_t total_weight);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_init_partconds_intern)(front_xq_a0_slint_t npconds, front_xq_a0_partcond_intern_t *pci, front_xq_a0_partcond_t *pc, front_xq_a0_slint_t nparts, front_xq_a0_slint_t total_count, front_xq_a0_slweight_t total_weight);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_merge_partconds)(front_xq_a0_partcond_t *pconds_in, front_xq_a0_slint_t npconds_in, front_xq_a0_partcond_t *pcond_out);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_gather_partconds_grouped)(front_xq_a0_partcond_t *pcond_in, MPI_Comm pcond_in_comm, MPI_Comm pconds_out_comm, front_xq_a0_partcond_t *pconds_out, front_xq_a0_slint_t *npconds_out, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_gather_partconds)(front_xq_a0_partcond_t *pcond_in, front_xq_a0_partcond_t *pconds_out, int root, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_allgather_partconds)(front_xq_a0_partcond_t *pcond_in, front_xq_a0_partcond_t *pconds_out, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_bcast_partconds)(front_xq_a0_slint_t npconds, front_xq_a0_partcond_t *pconds, int root, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_post_check_partconds)(front_xq_a0_elements_t *s, front_xq_a0_slint_t nelements, front_xq_a0_slint_t nparts, front_xq_a0_partcond_t *pconds, int *sdispls, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_post_check_partconds_intern)(front_xq_a0_elements_t *s, front_xq_a0_slint_t nelements, front_xq_a0_slint_t nparts, front_xq_a0_partcond_intern_t *pci, int *sdispls, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_select_stats)(front_xq_a0_elements_t *s, front_xq_a0_slint_t nparts, int *sdispls, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_select_exact_generic_bulk)(front_xq_a0_elements_t *s, front_xq_a0_slint_t nelements, front_xq_a0_slint_t nparts, front_xq_a0_partcond_t *pconds, front_xq_a0_binning_t *bm, front_xq_a0_splitter_t *sp, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_select_exact_generic_grouped)(front_xq_a0_elements_t *s, front_xq_a0_slint_t nelements, front_xq_a0_partcond_t *pcond, MPI_Comm pcond_comm, MPI_Comm group_comm, front_xq_a0_binning_t *bm, front_xq_a0_splitter_t *sp, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_select_exact_generic)(front_xq_a0_elements_t *s, front_xq_a0_slint_t nelements, front_xq_a0_slint_t nparts, front_xq_a0_partcond_t *pconds, front_xq_a0_binning_t *bm, front_xq_a0_splitter_t *sp, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_select_exact_radix)(front_xq_a0_elements_t *s, front_xq_a0_slint_t nelements, front_xq_a0_slint_t nparts, front_xq_a0_partcond_t *pconds, front_xq_a0_slint_t rhigh, front_xq_a0_slint_t rlow, front_xq_a0_slint_t rwidth, front_xq_a0_slint_t sorted, int *sdispls, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_select_exact_radix_grouped)(front_xq_a0_elements_t *s, front_xq_a0_slint_t nelements, front_xq_a0_partcond_t *pcond, MPI_Comm pcond_comm, MPI_Comm group_comm, front_xq_a0_slint_t rhigh, front_xq_a0_slint_t rlow, front_xq_a0_slint_t rwidth, front_xq_a0_slint_t sorted, int *sdispls, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_select_sample_regular)(front_xq_a0_elements_t *s, front_xq_a0_slint_t nparts, front_xq_a0_partcond_t *pconds, front_xq_a0_slint_t nsamples, front_xq_a0_splitter_t *sp, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_sort_merge)(front_xq_a0_elements_t *s0, front_xq_a0_elements_t *s1, front_xq_a0_elements_t *xs, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_sort_merge2)(front_xq_a0_elements_t *s0, front_xq_a0_elements_t *s1, front_xq_a0_elements_t *xs, front_xq_a0_slint_t merge_type, front_xq_a0_slint_t sort_type, double *times, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_sort_merge_radix)(front_xq_a0_elements_t *s0, front_xq_a0_elements_t *s1, front_xq_a0_elements_t *xs, front_xq_a0_slint_t merge_type, front_xq_a0_slint_t sort_type, front_xq_a0_slint_t rhigh, front_xq_a0_slint_t rlow, front_xq_a0_slint_t rwidth, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_sort_partition)(front_xq_a0_elements_t *s0, front_xq_a0_elements_t *s1, front_xq_a0_elements_t *xs, front_xq_a0_slint_t part_type, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_sort_partition_radix)(front_xq_a0_elements_t *s0, front_xq_a0_elements_t *s1, front_xq_a0_elements_t *xs, front_xq_a0_slint_t part_type, front_xq_a0_slint_t rhigh, front_xq_a0_slint_t rlow, front_xq_a0_slint_t rwidth, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_sort_partition_exact_radix)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *sx, front_xq_a0_partcond_t *pcond, front_xq_a0_slint_t rhigh, front_xq_a0_slint_t rlow, front_xq_a0_slint_t rwidth, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_sort_partition_exact_radix_ngroups)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *sx, front_xq_a0_partcond_t *pcond, front_xq_a0_slint_t ngroups, MPI_Comm *group_comms, front_xq_a0_slint_t rhigh, front_xq_a0_slint_t rlow, front_xq_a0_slint_t rwidth, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_sort_partition_exact_radix_2groups)(front_xq_a0_elements_t *s, front_xq_a0_elements_t *sx, front_xq_a0_partcond_t *pcond, MPI_Comm group_comm, front_xq_a0_slint_t rhigh, front_xq_a0_slint_t rlow, front_xq_a0_slint_t rwidth, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_sort_insert_radix)(front_xq_a0_elements_t *s0, front_xq_a0_elements_t *s1, front_xq_a0_elements_t *xs, front_xq_a0_slpkey_t *mmkeys, front_xq_a0_slint_t rhigh, front_xq_a0_slint_t rlow, front_xq_a0_slint_t rwidth, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_sort_presorted_radix)(front_xq_a0_elements_t *s0, front_xq_a0_elements_t *s1, front_xq_a0_elements_t *xs, front_xq_a0_slint_t merge_type, front_xq_a0_slint_t rhigh, front_xq_a0_slint_t rlow, front_xq_a0_slint_t rwidth, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_sort_back)(front_xq_a0_elements_t *sin, front_xq_a0_elements_t *sout, front_xq_a0_elements_t *sx, front_xq_a0_slpkey_t *lh, front_xq_a0_slint_t ntotal, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_xcounts2ycounts_all2all)(int *xcounts, int *ycounts, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_xcounts2ycounts_sparse)(int *xcounts, int *ycounts, front_xq_a0_slint_t ytotal, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_xcounts2ycounts_grouped)(int *xcounts, front_xq_a0_slint_t nxcounts, int *ycounts, MPI_Comm group_comm, MPI_Comm master_comm, int size, int rank, MPI_Comm comm);
front_xq_a0_slint_t SL_PROTO(front_xq_a0_mpi_subxdispls2ycounts)(front_xq_a0_slint_t nsubs, int *sub_xdispls, front_xq_a0_slint_t *sub_sources, front_xq_a0_slint_t *sub_sizes, MPI_Comm sub_comm, int sub_size, int *ycounts, int size, int rank, MPI_Comm comm);


#endif /* SL_USE_MPI */


#undef SL_PROTO
#endif /* __SL_FRONT_XQ_A0_H__ */
