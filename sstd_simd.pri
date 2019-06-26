
INCLUDEPATH += $$PWD

# linux g++
linux-g++ {
    DEFINES *= SSTD_HAS_SIMD=1
    DEFINES *= SSTD_SIMD_GCC=1
}

# win32-g++
win32-g++ {
    DEFINES *= SSTD_HAS_SIMD=1
    DEFINES *= SSTD_SIMD_GCC=1
}

# win32-g++
win32-msvc {
    DEFINES *= SSTD_HAS_SIMD=1
    DEFINES *= SSTD_SIMD_MSVC=1
}

HEADERS += $$PWD/sstd_simd.hpp

