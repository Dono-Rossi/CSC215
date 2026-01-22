#include "linklist.h"

Node* node1 = new Node(1, nullptr);
cout << node1->to_str() << endl;

cout << render_list(node1);

cout << render_list_backward(node1);

render_pretty(node1, &render_list);

cout << render_list(node1) << endl;
Node* second_node = remove_second(node1);
cout << render_list(second_node) << endl;
cout << render_list(node1) << endl;


