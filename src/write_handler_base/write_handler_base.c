#include "write_handler_base.h"

/**
 * @func: "delete previous file"
 * @brief Delete any previous instance of the file
 */
void write_handler_delete_previous_file(EmeraldsWriteHandler *self) {
  remove(self->filepath);
}

EmeraldsWriteHandler *write_handler_new(void) {
  EmeraldsWriteHandler *h =
    (EmeraldsWriteHandler *)malloc(sizeof(EmeraldsWriteHandler));
  h->filepath = NULL;
  h->fd       = NULL;
  return h;
}

bool write_handler_open(EmeraldsWriteHandler *self, const char *filepath) {
  self->filepath = filepath;
  write_handler_delete_previous_file(self);

  if(!(self->fd = fopen(self->filepath, "w"))) {
    printf("Error on openning file: `%s`\n", self->filepath);
    return false;
  }
  return true;
}

bool write_handler_write(EmeraldsWriteHandler *self, const char *str) {
  if(!(fprintf(self->fd, "%s", str))) {
    printf("Error on writting `%s` to file: `%s`\n", str, self->filepath);
    return false;
  }
  return true;
}

bool write_handler_write_line(EmeraldsWriteHandler *self, const char *line) {
  if(write_handler_write(self, line)) {
    return write_handler_write(self, "\n");
  }
  printf("Error on writting line `%s` on file: `%s`\n", line, self->filepath);
  return false;
}

bool write_handler_close(EmeraldsWriteHandler *self) {
  if((fclose(self->fd))) {
    printf("Error on closing file: `%s`\n", self->filepath);
    return false;
  }
  return true;
}
