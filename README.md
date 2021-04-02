# WriteHandler

A safe file writer api.

# Installation

Install the library

`em list`
`em install`
`em build lib`

## Usage

```c
#include "WriteHandler.h"

int main(void) {
    char *line = "something random";
    struct write_handler *h = write_handler_new();

    if(write_handler_open(h, "file.txt")) {
        write_handler_write(h, line);
        write_handler_write(h, "\n");
    }

    write_handler_close(h);
}
```

## Development

## Contributing

1. Fork it (<https://github.com/EmeraldsFramework/WriteHandler/fork>)
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create a new Pull Request

## Contributors

- [Oblivious](https://github.com/Oblivious-Oblivious) - creator and maintainer
