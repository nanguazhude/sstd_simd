

CONFIG(debug,debug|release){
    TARGET = sstd_simd_test_debug
}else{
    TARGET = sstd_simd_test
}

SOURCES += $$PWD/main.cpp

include($$PWD/../sstd_simd.pri)
include($$PWD/../../sstd_library/sstd_library.pri)
DESTDIR = $${SSTD_LIBRARY_OUTPUT_PATH}

