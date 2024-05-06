#ifndef __WRITE_HANDLER_BASE_H_
#define __WRITE_HANDLER_BASE_H_

#include "../../libs/EmeraldsBool/export/EmeraldsBool.h"

#include <stdio.h>  /* FILE, fopen, fprintf, fclose, printf */
#include <stdlib.h> /* malloc, realloc, free */

/**
 * @brief File handler for making write operations more intuitive
 * @param fd -> The current file descriptor
 * @param filepath -> The name of the file to write to
 */
typedef struct EmeraldsWriteHandler {
  FILE *fd;
  const char *filepath;
} EmeraldsWriteHandler;

/**
 * @brief Creates a new instance of a write handler
 * @return struct write_handler* -> The newly allocated handler
 */
struct EmeraldsWriteHandler *write_handler_new(void);

/**
 * @brief Open a file in write mode
 * @param filepath -> The path to open
 * @return a boolean signaling if the opening was successful
 */
bool write_handler_open(
  struct EmeraldsWriteHandler *self, const char *filepath
);

/**
 * @brief Write a string in the file
 * @param str -> The string to write
 * @return a boolean signaling if the opening was successful
 */
bool write_handler_write(struct EmeraldsWriteHandler *self, const char *str);

/**
 * @brief Writes a line in the file
 * @param line -> The line to write
 * @return a boolean signaling if the opening was successful
 */
bool write_handler_write_line(
  struct EmeraldsWriteHandler *self, const char *line
);

/**
 * @brief Attempts to close the buffers to avoid memory overflows
 * @return a boolean signaling if the opening was successful
 */
bool write_handler_close(struct EmeraldsWriteHandler *self);

#endif
