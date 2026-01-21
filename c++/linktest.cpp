#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include "LinkedList.h"
using namespace std;

TEST_CASE("Test can create and render List Nodes") {
    Node* node1 = new Node;
    CHECK(node1->cargo == 0);
}


