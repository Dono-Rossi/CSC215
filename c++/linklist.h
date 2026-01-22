#ifndef LINKLIST_H
#define LINKLIST_H

#include <string>
#include <stdexcept>

using std::string;

struct Node {
    int cargo;
    Node* next;

    Node() {
        cargo = 0;
        next = nullptr;
    }

    Node(int cargo) {
        this->cargo = cargo;
        next = nullptr;
    }

    Node(int cargo, Node* next) {
        this->cargo = cargo;
        this->next = next;
    }

    string to_str() const {
        return to_string(cargo);
    }
};

string render_list(Node* list) {
    Node* node = list;
    string s = "";
    while (node != nullptr) {
        s += node->to_string();
        node = node->next;
        if (node != nullptr)
           s += ", ";
    }
    return s;
}


string render_list_backward(Node*, string="");{
    if (list == nullptr) return "";
    Node* head = list;
    Node* tail = list->next;

    s = render_list_backward(tail, s) + s;
    if (head->next != nullptr)
        s += ", ";
    s += head->to_string();

    return s;
}

string render_pretty(Node* list, string (*list_renderer)(Node*)) {
    return "(" + list_renderer(list) + ")";
}

string render_list_backward(Node* list)
{
    return render_backward_worker(list, "");
}

Node* remove_second(Node* list) {
    Node* first = list;
    Node* second = list->next;

    // make the first node point to the third
    first->next = second->next;

    // remove the second node from the list and return a pointer to it
    second->next = nullptr;
    return second;
}

class LinkedList
{
    int num_nodes;
    Node* head;

public:
    LinkedList() {
        num_nodes = 0;
        head = nullptr;
    }
};

void LinkedList::insert_at_front(int cargo) {
    Node* front = new Node(cargo, head);
    head = front;
    num_nodes++;
}

template <class T>
struct Node
{
    T cargo;
    Node<T>* next;

    Node(T cargo, Node<T>* next)
    {
        this->cargo = cargo;
        this->next = next;
    }
};
