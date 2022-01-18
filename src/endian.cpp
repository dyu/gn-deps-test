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
#else

#if defined(BSD)
#include <sys/endian.h>
#else // BSD
#include <endian.h>
#endif // BSD

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
    printf("little endian: %d\n", OS_BYTE_ORDER == OS_LITTLE_ENDIAN);
}