

CONFIG(debug,debug|release){
    TARGET = sstd_simd_test_debug
}else{
    TARGET = sstd_simd_test
}

SOURCES += $$PWD/main.cpp

CONFIG += c++17
include($$PWD/../sstd_simd.pri)




