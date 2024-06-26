#include "../../libs/cSpec/export/cSpec.h"
#include "../../src/write_handler_base/write_handler_base.h"

EmeraldsWriteHandler *T_write_handler_object;
void setup_write_handler_object(void) {
  T_write_handler_object = write_handler_new();
}

module(T_WriteHandler, {
  before_each(&setup_write_handler_object);

  describe("#writer open", {
    context("on filename is new", {
      it("opens the file and returns true", {
        bool actual =
          write_handler_open(T_write_handler_object, "new_file.txt");
        assert_that(actual is true);
      });
    });

    context("on filename already existsing", {
      FILE *fd = fopen("new_file.txt", "w");
      fprintf(fd, "%s", "data in there");

      it("deletes the previous file, creates a new one and returns true", {
        /* For ease of use we assume the previous test has passed */
        bool actual =
          write_handler_open(T_write_handler_object, "new_file.txt");
        assert_that(actual is true);
        /* We expect that the file is now empty */
      });
    });
  });

  describe("#write", {
    it("writes `test data` to input file named `test_write.txt`", {
      write_handler_open(T_write_handler_object, "test_write.txt");

      bool actual = write_handler_write(T_write_handler_object, "test data");
      assert_that(actual is true);
    });
  });

  describe("#write line", {
    it(
      "writes `test data` to input file named `test_write_line.txt` with a "
      "newline",
      {
        write_handler_open(T_write_handler_object, "test_write_line.txt");

        bool actual =
          write_handler_write_line(T_write_handler_object, "test data");
        assert_that(actual is true);
      }
    );
  });

  describe("#writer close", {
    it("opens a file and successfully closes the buffer", {
      write_handler_open(T_write_handler_object, "new_file.txt");

      bool actual = write_handler_close(T_write_handler_object);
      assert_that(actual is true);
    });
  });

  after({
    remove("new_file.txt");
    remove("test_write.txt");
    remove("test_write_line.txt");
  });
})
