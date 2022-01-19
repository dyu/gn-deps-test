// endian detection via the compilers: clang and gcc.
// assume little endian on windows
// https://github.com/abseil/abseil-cpp/blob/c59e7e59f5d29619ddc07fcb59be3dcba9585814/absl/base/config.h#L511-L521

// clang defines __LITTLE_ENDIAN__ on little endian systems.
// gcc 4.6+ and clang 3.2+ both define __BYTE_ORDER__
#if defined(_WIN32) || (defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__)
#define IS_LITTLE_ENDIAN true
#endif

static const bool kLittleEndian = IS_LITTLE_ENDIAN;

#include <stdio.h>

int main() {
    printf("little endian: %d\n", kLittleEndian);
    return 0;
}