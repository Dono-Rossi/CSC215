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


std::string render_list_backward(Node* list) {
    if (list == nullptr) return "";
    std::string rest = render_list_backward(list->next);
    if (rest.empty())
        return list->to_str();
    else
        return rest + ", " + list->to_str();
}

string render_pretty(Node* list, string (*list_renderer)(Node*)) {
    return "(" + list_renderer(list) + ")";
}

std::string render_pretty(Node* list, std::string (*list_renderer)(Node*)) {
    return "(" + list_renderer(list) + ")";
}

// Remove the second node from the list and return it.
// If there is no second node, return nullptr.
Node* remove_second(Node* list) {
    if (list == nullptr) return nullptr;
    Node* first = list;
    Node* second = list->next;
    if (second == nullptr) return nullptr;

    // link first -> third (may be nullptr)
    first->next = second->next;

    // detach second and return it
    second->next = nullptr;
    return second;
}

class LinkedList
{
    int num_nodes;
    Node* head;

public:
    LinkedList() : num_nodes(0), head(nullptr) {}

    void insert_at_front(int cargo);
    // other non-templated list operations could go here
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
