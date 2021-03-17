#include "WriteHandler.spec.h"

module(T_WriteHandler, {
    describe("#get_value", {
        it("returns `Hello, World!`", {
            assert_that_charptr("Hello, World!" equals to "Hello, World!");
        });
    });
});

spec_suite({
    T_WriteHandler();
});

spec({
    run_spec_suite("all");
});
