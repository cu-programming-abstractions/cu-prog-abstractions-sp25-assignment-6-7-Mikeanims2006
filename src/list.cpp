#include "list.h"
#include <iostream>
#include <utility>

using namespace std;

// Constructor
LinkedList::LinkedList() : head(nullptr) {}

// Copy constructor (deep copy)
LinkedList::LinkedList(const LinkedList& other) {
    head = deepCopy(other.head);
}

// Copy assignment using copy-and-swap idiom
LinkedList& LinkedList::operator=(LinkedList rhs) {
    swap(head, rhs.head);
    return *this;
}

// Destructor
LinkedList::~LinkedList() {
    freeChain(head);
}

// Prepend: insert at front
void LinkedList::prepend(int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
}

// Append: insert at end
void LinkedList::append(int value) {
    Node* newNode = new Node{value, nullptr};
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

// Remove front node
int LinkedList::removeFront() {
    if (isEmpty()) {
        throw std::runtime_error("List is empty");
    }
    Node* oldHead = head;
    int value = oldHead->data;
    head = head->next;
    delete oldHead;
    return value;
}

// Check if list is empty
bool LinkedList::isEmpty() const {
    return head == nullptr;
}

// Print the list
void LinkedList::print(ostream& out) const {
    Node* current = head;
    while (current != nullptr) {
        out << current->data;
        if (current->next != nullptr) {
            out << " -> ";
        }
        current = current->next;
    }
    out << endl;
}

// Deep copy utility
LinkedList::Node* LinkedList::deepCopy(Node* src) {
    if (src == nullptr) return nullptr;
    Node* newHead = new Node{src->data, nullptr};
    Node* currentNew = newHead;
    Node* currentSrc = src->next;
    while (currentSrc != nullptr) {
        currentNew->next = new Node{currentSrc->data, nullptr};
        currentNew = currentNew->next;
        currentSrc = currentSrc->next;
    }
    return newHead;
}

// Free memory utility
void LinkedList::freeChain(Node* n) {
    while (n != nullptr) {
        Node* next = n->next;
        delete n;
        n = next;
    }
}
