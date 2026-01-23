#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include "ToDos.h"
using namespace std;

TEST_CASE("Test can create and render a ToDo") {
    ToDo t1;
    CHECK(t1.to_string() == "I'm a ToDo");
}

