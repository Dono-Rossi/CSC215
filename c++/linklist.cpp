#include <iostream>
#include "linklist.h"

int main() {
    using std::cout
    using std::endl;
    
    Node* node1 = new Node(1, nullptr);
    cout << node1->to_str() << endl;
    
    node1->next = new Node(2, new Node(3, nullptr));

        cout << render_list(node1) << endl;              // "1, 2, 3"
    cout << render_list_backward(node1) << endl;     // "3, 2, 1"

    cout << render_pretty(node1, &render_list) << endl; // "(1, 2, 3)"

    cout << render_list(node1) << endl;
    Node* second_node = remove_second(node1);
    if (second_node) {
        cout << "Removed second: " << second_node->to_str() << endl;
        delete second_node;
    } else {
        cout << "No second node to remove" << endl;
    }
    cout << "List now: " << render_list(node1) << endl;

    // cleanup remaining nodes
    Node* cur = node1;
    while (cur) {
        Node* next = cur->next;
        delete cur;
        cur = next;
    }

    return 0;

}
