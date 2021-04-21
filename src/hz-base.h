#ifndef HZ_BASE_H
#define HZ_BASE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <inttypes.h>
#include <wchar.h>

#define CMAS_IMPL
#include "cmas.h"

#ifdef HZ_ENABLE_LOGGING
#define HZ_LOG(...) fprintf(stdout, __VA_ARGS__)
#define HZ_DBGLOG(...) fprintf(stdout, __VA_ARGS__)
#define HZ_ERROR(...) fprintf(stderr, __VA_ARGS__)
#else
#define HZ_LOG(...)
#define HZ_DBGLOG(...)
#define HZ_ERROR(...)
#endif
#define HZ_MALLOC(size) malloc(size)
#define HZ_FREE(p) free(p)
#define HZ_REALLOC(p, size) realloc(p, size)
#define HZ_ARRAY_SIZE(x) (sizeof(x)/sizeof((x)[0]))


#define HZ_PACKED __attribute__((__packed__))

/*
 * Define base sized integer and float types
 * */
typedef unsigned char hz_uint8;
typedef unsigned short hz_uint16;
typedef unsigned long hz_uint32;
typedef unsigned long long hz_uint64;
typedef char hz_int8;
typedef short hz_int16;
typedef long hz_int32;
typedef long long hz_int64;
typedef float hz_float32;
typedef double hz_float64;
typedef void hz_void;

typedef int32_t hz_position;

/* signed 16-bit */
typedef int16_t FWORD;

/* unsigned 16-bit */
typedef uint16_t UFWORD;

/* unsigned 16-bit */
typedef uint16_t F2DOT14;

typedef uint8_t hz_byte_t, hz_bool_t, hz_char;
typedef uint16_t hz_offset16_t;
typedef uint32_t hz_tag_t;
typedef uint32_t hz_offset32_t;
typedef uint32_t hz_unicode_t; /* 32 bit unicode type */
typedef uint16_t hz_index_t;
typedef uint16_t hz_fixed_t;

#define HZ_F2DOT14 uint16_t
#define HZ_FWORD uint16_t
#define HZ_UFWORD uint16_t
typedef uint32_t HZ_Version16Dot16;

typedef uint64_t hz_uintptr;
typedef size_t hz_size_t;

static hz_float32
hz_cast_f32_f2d14(const HZ_F2DOT14 x)
{
    hz_float32 dec = (x & 0x3FFFU) / (hz_float32) 0x3FFFU;
    hz_float32 unit = (x & 0xC000U) >> 14U;
    return unit + dec;
}

static uint16_t bswap16(uint16_t val)
{
    uint16_t res = 0;
    res |= (val & 0x00FFU) << 8;
    res |= (val & 0xFF00U) >> 8;
    return res;
}

static uint32_t bswap32(uint32_t val)
{
    uint32_t res = 0;
    res |= (val & 0x0000FFFFU) << 16;
    res |= (val & 0xFFFF0000U) >> 16;
    return res;
}

#define HZ_TRUE 1
#define HZ_FALSE 0

#define HZ_ASSERT(cond) assert(cond)
#define HZ_TAG(c1, c2, c3, c4) ((hz_tag_t)c4 | ((hz_tag_t)c3 << 8U) | ((hz_tag_t)c2 << 16U) | ((hz_tag_t)c1 << 24U))
#define HZ_UNTAG(tag) (tag >> 24) & 0xFF, (tag >> 16) & 0xFF, (tag >> 8) & 0xFF, tag & 0xFF
#define HZ_ALLOC(T) (T *) HZ_MALLOC(sizeof(T))

/* V is the variable name, while T is the type/structure */
#define HZ_HEAPVAR(V, T) T *V = HZ_ALLOC(T)

#define HZ_HEAPARR(V, N, T) T *V = HZ_MALLOC(sizeof(T) * (N))

typedef enum hz_status_t {
    HZ_SUCCESS = 0,
    HZ_FAILURE = 1
} hz_status_t;

#define HZ_STREAM_BOUND_FLAG 0x01
#define HZ_STREAM_FLIP_ENDIANNESS_FLAG 0x02

#define HZ_STREAM_OVERFLOW 0

typedef struct hz_stream_t {
    hz_byte_t *data;
    size_t length;
    size_t offset;
    uint8_t flags;
} hz_stream_t;

static hz_stream_t *
hz_stream_create(hz_byte_t *data, size_t length, uint8_t flags)
{
    hz_stream_t *stream = (hz_stream_t *) HZ_MALLOC(sizeof(hz_stream_t));
    stream->offset = 0;
    stream->data = data;
    stream->length = length;
    stream->flags = flags;
    return stream;
}

static void
hz_stream_destroy(hz_stream_t *stream) {
    HZ_FREE(stream);
}

static unsigned int
hz_stream_read8(hz_stream_t *stream, uint8_t *val) {
    const uint8_t *valptr = stream->data + stream->offset;

    if (stream->flags & HZ_STREAM_BOUND_FLAG && stream->offset + 1 >= stream->length)
        return HZ_STREAM_OVERFLOW;

    (*val) = valptr[0];
    stream->offset += 1;
    return 1;
}

static unsigned int
hz_stream_read16(hz_stream_t *stream, uint16_t *val) {
    uint16_t tmpval = 0;
    const uint8_t *valptr = stream->data + stream->offset;

    if (stream->flags & HZ_STREAM_BOUND_FLAG && stream->offset + 2 >= stream->length)
        return HZ_STREAM_OVERFLOW;

    tmpval |= (uint16_t) valptr[0] << 8;
    tmpval |= valptr[1];

    if (stream->flags & HZ_STREAM_FLIP_ENDIANNESS_FLAG)
        tmpval = bswap16( tmpval );

    *val = tmpval;
    stream->offset += 2;
    return 2;
}

static unsigned int
hz_stream_read32(hz_stream_t *stream, uint32_t *val) {
    uint32_t tmpval = 0;
    const uint8_t *valptr = stream->data + stream->offset;

    if (stream->flags & HZ_STREAM_BOUND_FLAG && stream->offset + 4 >= stream->length)
        return HZ_STREAM_OVERFLOW;

    tmpval |= (uint32_t) valptr[0] << 24;
    tmpval |= (uint32_t) valptr[1] << 16;
    tmpval |= (uint32_t) valptr[2] << 8;
    tmpval |= valptr[3];

    if (stream->flags & HZ_STREAM_FLIP_ENDIANNESS_FLAG)
        tmpval = bswap32( tmpval );

    *val = tmpval;
    stream->offset += 4;
    return 4;
}

static void
hz_stream_seek(hz_stream_t *stream, int offset) {
    stream->offset += offset;
}

static void
hz_stream_read16_n(hz_stream_t *stream, size_t count, uint16_t *A)
{
    if (A != NULL) {
        size_t i = 0;

        while (i < count) {
            uint16_t *val = A + i;

            hz_stream_read16(stream, val);

            ++i;
        }
    }
}

typedef struct hz_metrics_t {
    int32_t x_advance;
    int32_t y_advance;
    int32_t x_bearing;
    int32_t y_bearing;

    int32_t x_min;
    int32_t x_max;
    int32_t y_min;
    int32_t y_max;
    int32_t width;
    int32_t height;
} hz_metrics_t;

#endif /* HZ_BASE_H */