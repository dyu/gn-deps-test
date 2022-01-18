// __LITTLE_ENDIAN__ is provided by the clang compiler on little endian systems.
#if defined(__LITTLE_ENDIAN__) || (!defined(_ppc_) && !defined(_ppc64_) && !defined(__ppc__) && !defined(__ppc64__) && !defined(__POWERPC__) && !defined(_M_PPC))
static const bool kLittleEndian = true;
#else
static const bool kLittleEndian = false;
#endif

#include <stdio.h>

int main() {
    printf("little endian: %d\n", kLittleEndian);
    #if defined(__LITTLE_ENDIAN__)
    printf("__LITTLE_ENDIAN__: 1\n");
    #endif
    return 0;
}