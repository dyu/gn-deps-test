// endian detection via the compilers: Clang, Gcc and Msvc.

// clang defines __LITTLE_ENDIAN__ on little endian systems.
// gcc 4.x+ and msvc 2015+ (c++14) both define __BYTE_ORDER__
#if !defined(__LITTLE_ENDIAN__) && !defined(__clang__) && defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define __LITTLE_ENDIAN__ 1
#endif

#if defined(__LITTLE_ENDIAN__)
static const bool kLittleEndian = true;
#else
static const bool kLittleEndian = false;
#endif

#include <stdio.h>

int main() {
    printf("little endian: %d\n", kLittleEndian);
    return 0;
}