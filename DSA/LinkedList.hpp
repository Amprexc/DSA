#pragma once
#include <iostream>

using namespace std;
class Node {
public:
    int value;
    Node* next;

    Node(int value) {
        this->value = value;
        next = nullptr;
    }
};


class LinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    LinkedList(int value) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~LinkedList() {
        Node* temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printList() {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "empty";
        }
        else {
            while (temp != nullptr) {
                cout << temp->value;
                temp = temp->next;
                if (temp != nullptr) {
                    cout << " -> ";
                }
            }
        }
        cout << endl;
    }

    Node* getHead() {
        return head;
    }

    Node* getTail() {
        return tail;
    }

    int getLength() {
        return length;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }
    void prepend(int value) {
        Node* newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
            length++;
        }
        else {
            newNode->next = head;
            head = newNode;
            length++;
        }
    }

    void deleteFirst() {
        if (length == 0) return;
        Node* temp = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            head = head->next;
        }
        delete temp;
        length--;
    }

    void deleteLast() {
        if (length == 0) {
            return;
        }

        if (length == 1) {
            head = nullptr;
            tail = nullptr;
            length--;
            return;
        }
        Node* temp = head;
        Node* pre = head;
        while (temp->next) {
            pre = temp;
            temp = temp->next;
        }
        pre->next = nullptr;
        tail = pre;
        delete temp;
        length--;
    }

    Node* get(int index) {
        if (index < 0 || index >= length) {
            return nullptr;
        }
        else {
            Node* temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            return temp;
        }
    }

    bool set(int index, int value) {
        Node* temp = get(index);
        if (temp) {
            temp->value = value;
            return true;
        }
        return false;
    }

    bool insert(int index, int value) {
        if (index < 0 || index > length) return false;
        if (index == 0) {
            prepend(value);
            return true;
        }
        if (index == length) {
            append(value);
            return true;
        }
        Node* temp = get(index - 1);
        if (temp) {
            Node* newNode = new Node(value);
            newNode->next = temp->next;
            temp->next = newNode;
            length++;
            return true;
        }
        return false;
    }

    void deleteNode(int index) {
        if (index < 0 || index >= length) return;
        if (index == 0) {
            deleteFirst();
            return;
        }
        if (index == length) {
            deleteLast();
            return;
        }
        Node* prev = get(index - 1);
        if (prev) {
            Node* temp = prev->next;
            prev->next = temp->next;
            length--;
            delete temp;
        }
    }

    void reverse() {
        Node* temp = head;
        head = tail;
        tail = temp;
        Node* before = nullptr;

        Node* after = temp->next;
        while (temp) {
            after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;
        }
    }

    Node* findMiddleNode() {
        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    bool hasLoop() {
        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }

    Node* findKthFromEnd(int k) {
        Node* slow = head;
        Node* fast = head;
        for (int i = 0; i < k; i++) {
            if (fast == nullptr) {
                return nullptr;
            }
            fast = fast->next;
        }
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }


    void bubbleSort() {
        if (length < 2) {
            return;
        }
        Node* sortedUntil = nullptr;
        Node* current = nullptr;
        while (sortedUntil != head->next) {
            current = head;
            while (current->next != sortedUntil) {
                if (current->value > current->next->value) {
                    int temp = current->value;
                    current->value = current->next->value;
                    current->next->value = temp;
                }
                current = current->next;
            }
            sortedUntil = current;
        }
    }
};