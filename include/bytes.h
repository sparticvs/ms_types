/* @copyright
 * Copyright (c) 2016 - Charles `sparticvs` Timko
 *
 * Author(s):
 *  Charles Timko <sparticvs@popebp.com>
 *
 * Description:
 *  Byte Array implementation with supporting magic
 */

#ifndef __MST_BYTES_H__
#define __MST_BYTES_H__

#include <stdint.h>

#define BF_STACK    0x00000000
#define BF_HEAP     0x00000001

/*
 * Byte array structure.
 *
 * @note Recommended to not manipulate directly.
 */
typedef struct {
    uint8_t *_bytes; ///< Bytes
    size_t _len; ///< Length of array
    size_t _pos; ///< Position of the tail
    uint32_t _flags; ///< Flags describing this type
} bytes_t;

#ifndef NO_HEAP
/*
 * Allocate a bytes_t on the heap
 *
 * @note Can be disabled when compiled with "NO_HEAP" defined.
 *
 * @return Returns a pointer to the structure that was allocated, or NULL if no
 * memory remains.
 */
bytes_t *bytes_alloc();

/*
 * Frees the bytes_t on the heap
 *
 * @note Can be disabled when compiled with "NO_HEAP" defined.
 *
 * @args this   The bytes_t to free
 */
void bytes_free(bytes_t *this);
#endif

// Management Functions
/*
 * Initialize a bytes_t to be used
 *
 * @note Intended for stack only operations.
 *
 * @args this   The bytes_t to initialize
 * @args buf    Buffer to use for the byte array
 * @args len    Length of the allocated byte array
 *
 * @return Returns 0 on success or an error code
 */
uint8_t bytes_init(bytes_t *this, uint8_t *buf, size_t len);

/*
 * Appends data to the byte array
 *
 * @args this   The bytes_t to push data into
 * @args buf    Buffer of bytes to append
 * @args len    Lenght of the buffer
 *
 * @return Returns 0 on success or an error code
 */
uint8_t bytes_append(bytes_t *this, uint8_t *buf, size_t len);

// Access Functions
/* @brief
 * Gets the length of the array
 *
 * @detail
 * Returns the length of the array. If this was allocated on the stack then it
 * returns the numbef of bytes inserted.
 *
 * @args this   The bytes_t of which you want the length
 *
 * @return Returns the size as a size_t
 */
size_t bytes_len(bytes_t *this);

/* @brief
 * Copies the bytes of the array into the buffer supplied upto the length.
 *
 * @args this   The bytes_t instance to get data from
 * @args out    Pointer to the buffer to store the bytes
 * @args len    Length of the array that the pointer points to
 *
 * @return Returns the number of bytes copied into the buffer.
 */
size_t bytes_array(bytes_t *this, uint8_t *out, size_t len);

// Operational Functions
/*
 * Checks if both bytes_t are equal in value
 *
 * @note Ignores all other information in the bytes_t datastruct
 *
 * @args this   Left bytes_t instance
 * @args that   Right bytes_t instance
 *
 * @return Returns 1 if equal or 0 if not equal.
 */
uint8_t bytes_eq(bytes_t *this, bytes_t *that);

/*
 * Copies bytes from src to dest
 *
 * @note Does not copy everything.
 *
 * @args dest   Destination bytes_t
 * @args src    Source bytes_t
 *
 * @return Returns 0 on success or an error code
 */
uint8_t bytes_cpy(bytes_t *dest, bytes_t *src);

/* @brief
 * Concatenates two byte arrays together
 *
 * @detail
 * Effectively does:
 *  dest = dest + src
 *
 * It will try some different tactics to get the data in the buffer if there is
 * room or if room can be made (by reallocating).
 *
 * @args dest   Destination bytes_t
 * @args src    Source bytes_t
 *
 * @return Returns 0 on success or an error code
 */
uint8_t bytes_cat(bytes_t *dest, bytes_t *src);

#endif //__MST_BYTES_H__
