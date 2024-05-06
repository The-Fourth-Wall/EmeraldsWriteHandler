#include "../export/EmeraldsWriteHandler.h" /* IWYU pragma: keep */

int main(void) {
  char *line              = "something random";
  EmeraldsWriteHandler *h = write_handler_new();

  if(write_handler_open(h, "file.txt")) {
    write_handler_write(h, line);
    write_handler_write(h, "\n");
  }

  write_handler_close(h);
}
