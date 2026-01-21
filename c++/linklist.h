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
