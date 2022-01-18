enum endian_t {
    OS_BIG_ENDIAN      = 0x00000001,
    OS_LITTLE_ENDIAN   = 0x01000000,
    OS_PDP_ENDIAN      = 0x00010000,
    OS_UNKNOWN_ENDIAN  = 0xFFFFFFFF
};

#if defined(__BIG_ENDIAN__)
enum { OS_BYTE_ORDER = OS_BIG_ENDIAN };
#elif defined(__LITTLE_ENDIAN__)
enum { OS_BYTE_ORDER = OS_LITTLE_ENDIAN };
#elif defined(_WIN32)

#if defined(_ppc_) || defined(_ppc64_) || defined(__ppc__) || defined(__ppc64__) || defined(__POWERPC__) || defined(_M_PPC)
enum { OS_BYTE_ORDER = OS_BIG_ENDIAN };
#else
enum { OS_BYTE_ORDER = OS_LITTLE_ENDIAN };
#endif

#else

#if defined(BSD)
#include <sys/endian.h>
#else
#include <endian.h>
#endif

#if __BYTE_ORDER == __BIG_ENDIAN
enum { OS_BYTE_ORDER = OS_BIG_ENDIAN };
#elif __BYTE_ORDER == __LITTLE_ENDIAN
enum { OS_BYTE_ORDER = OS_LITTLE_ENDIAN };
#else
#error "Unsupported Endianness!"
#endif

#endif

#include <stdio.h>

int main() {
    auto little = OS_BYTE_ORDER == OS_LITTLE_ENDIAN;
    printf("little endian: %d\n", little);
    #if defined(__LITTLE_ENDIAN__)
    printf("__LITTLE_ENDIAN__: 1\n");
    #endif
}
