
#include <iostream>
#include <string_view>
using namespace std::string_view_literals;
#include <sstd_simd.hpp>

void test_mul_float_4(){

    alignas (sstd_simd_force_align) float var1 []{1,2,3,4};
    alignas (sstd_simd_force_align) float var2 []{5,6,7,8};
    alignas (sstd_simd_force_align) float var3 []{5,6,7,8};

    sstd_simd_store_m128(sstd_simd_mul_m128( sstd_simd_load_m128(var1),
                                             sstd_simd_load_m128(var2) ),var3);

    assert(var3[0]==5);
    assert(var3[1]==12);
    assert(var3[2]==21);
    assert(var3[3]==32);

    std::cout << " "sv << var3[0]
              << " "sv << var3[1]
              << " "sv << var3[2]
              << " "sv << var3[3]
              << std::endl ;

}

int main(){
    std::cout << "begin simple test : "sv << std::endl;
    test_mul_float_4();
    std::cout << "end simple test : "sv << std::endl;
}



