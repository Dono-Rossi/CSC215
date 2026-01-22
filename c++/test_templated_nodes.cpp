#include <iostream>
#include <string>
#include "linklist.h"

using namespace std;

int main()
{
    Node<string>* node1 = new Node<string>("I", NULL);
    Node<string>* node2 = new Node<string>("love", NULL);
    Node<string>* node3 = new Node<string>("templates!", NULL);

    node1->next = node2;
    node2->next = node3;

    Node<string>* node = node1;

    while (node != NULL) {
        cout << node->cargo << endl;
        node = node->next;
    }

    return 0;
}

template <class T>
class LinkedList
{
    int num_nodes;
    Node<T>* head;

public:
    // constructor
    LinkedList() {
        num_nodes = 0;
        head = nullptr;
    }

    // modifiers
    void insert_at_front(T cargo) {
        Node<T>* front = new Node<T>(cargo, head);
        head = front;
        num_nodes++;
    }

    T remove_from_front() {
        if (head == nullptr)
            throw runtime_error("Can't remove from empty list!");
        T cargo = head->cargo;
        Node<T>* front = head;
        head = head->next;
        delete front;
        num_nodes--;
        return cargo;
    }
};
