#include "list_utils.h"
#include <stdexcept>

// Return the number of nodes in the linked list
int length(const LinkedList& list) {
    int count = 0;
    LinkedList::Node* current = list.getHead();
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// Return the sum of all values in the linked list
int sum(const LinkedList& list) {
    int total = 0;
    LinkedList::Node* current = list.getHead();
    while (current != nullptr) {
        total += current->data;
        current = current->next;
    }
    return total;
}

// Check if the list contains a value k
bool contains(const LinkedList& list, int k) {
    LinkedList::Node* current = list.getHead();
    while (current != nullptr) {
        if (current->data == k) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Reverse the linked list in-place
void reverse(LinkedList& list) {
    LinkedList::Node* prev = nullptr;
    LinkedList::Node* curr = list.getHead();
    while (curr != nullptr) {
        LinkedList::Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    list.setHead(prev);
}

// Return the nth node value from the end of the list
#include "list_utils.h"
#include <stdexcept>  // for std::out_of_range

int nthFromEnd(const LinkedList& list, int n) {
    if (n < 0) {
        throw std::out_of_range("Negative n is invalid");
    }

    LinkedList::Node* fast = list.getHead();
    LinkedList::Node* slow = list.getHead();

    // Move fast pointer n steps ahead
    for (int i = 0; i < n; ++i) {
        if (fast == nullptr) {
            throw std::out_of_range("n is too large for the list size");
        }
        fast = fast->next;
    }

    if (fast == nullptr) {
        throw std::out_of_range("n is too large for the list size");
    }

    while (fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow->data;
}
