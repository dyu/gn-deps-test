// simplified endian detection for the 3 supported compilers: clang/gcc/msvc
// https://github.com/abseil/abseil-cpp/blob/c59e7e59f5d29619ddc07fcb59be3dcba9585814/absl/base/config.h#L511-L521
// gcc 4.6+ and clang 3.2+ both define __BYTE_ORDER__
#if defined(_WIN32) || __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
static const bool kLittleEndian = true;
#else
static const bool kLittleEndian = false;
#endif

#include <stdio.h>

int main() {
    printf("little endian: %d\n", kLittleEndian);
    return 0;
}