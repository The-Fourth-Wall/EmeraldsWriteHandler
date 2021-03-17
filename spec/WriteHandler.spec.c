#include "WriteHandler.spec.h"

module(T_WriteHandler, {
    describe("#get_value", {
        it("returns `Hello, World!`", {
            assert_that_charptr(get_value() equals to "Hello, World!");
        });
    });
});

spec_suite({
    T_WriteHandler();
});

spec({
    run_spec_suite("all");
});
