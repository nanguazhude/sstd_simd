#pragma once

/* 通用常量 */
#define sstd_simd_force_align 16

#if defined(SSTD_HAS_SIMD)

#include <cassert>
#include <cstddef>
#include <cstdint>

inline bool _sstd_simd_check_align(const void * arg){
    return 0==(reinterpret_cast< const std::uintptr_t >(arg) &
               static_cast<std::uintptr_t>(sstd_simd_force_align-1) );
}

#ifndef NDEBUG
#define sstd_simd_check_align(arg) _sstd_simd_check_align(arg)
#else
#define sstd_simd_check_align(arg) true
#endif

/*头文件及类型*/
#if defined(SSTD_SIMD_MSVC) || defined(SSTD_SIMD_WINDOWS_GCC)

#include <xmmintrin.h>
#define sstd_simd_m128 __m128 /*float[4]*/

#endif

/*方法*/

inline sstd_simd_m128 sstd_simd_load_m128(const float * arg){
    assert(arg);
    assert(sstd_simd_check_align(arg));
#if defined(SSTD_SIMD_MSVC) || defined(SSTD_SIMD_WINDOWS_GCC)
    return _mm_load_ps(arg);
#endif
}

inline void sstd_simd_store_m128(const sstd_simd_m128 & argSimd,float * arg){
    assert(arg);
    assert(sstd_simd_check_align(arg));
#if defined(SSTD_SIMD_MSVC) || defined(SSTD_SIMD_WINDOWS_GCC)
    return _mm_store_ps(arg,argSimd);
#endif
}

inline sstd_simd_m128 sstd_simd_mul_m128(const sstd_simd_m128 & argL,const sstd_simd_m128 & argR){
#if defined(SSTD_SIMD_MSVC) || defined(SSTD_SIMD_WINDOWS_GCC)
    return _mm_mul_ps(argL,argR);
#endif
}

#endif

