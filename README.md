# EmeraldsWriteHandler

A safe file writer api.

# Installation

Install the library

`em list`
`em install`
`em build lib`

## Usage

```c
#include "EmeraldsWriteHandler.h"

int main(void) {
  char *line = "something random";
  EmeraldsWriteHandler *h = write_handler_new();

  if(write_handler_open(h, "file.txt")) {
    write_handler_write(h, line);
    write_handler_write(h, "\n");
  }

  write_handler_close(h);
}
```

## Contributing

1. Fork it (<https://github.com/Oblivious-Oblivious/EmeraldsWriteHandler/fork>)
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create a new Pull Request

## Contributors

- [oblivious](https://github.com/Oblivious-Oblivious) - creator and maintainer
