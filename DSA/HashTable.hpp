#pragma once
#include <iostream>
#include <string>

using namespace std;
namespace HT {
    class Node {
    public:
        int value;
        string key;
        Node* next;
        Node(string key, int value) {
            this->key = key;
            this->value = value;
            next = nullptr;
        }
    };
}


class HashTable {
private:
    static const int SIZE = 7;
    HT::Node* dataMap[SIZE];

public:

    int hash(string key) {
        int hash = 0;
        for (int i = 0; i < key.length(); i++) {
            int asciiValue = int(key[i]);
            hash = (hash + asciiValue * 23) % SIZE;

        }
        return hash;
    }

    void set(string key, int value) {
        int index = hash(key);
        HT::Node* newNode = new HT::Node(key, value);
        if (dataMap[index] == nullptr) {
            dataMap[index] = newNode;
        }
        else {
            HT::Node* temp = dataMap[index];
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    int get(string key) {
        int index = hash(key);
        HT::Node* temp = dataMap[index];
        while (temp) {
            if (temp->key == key) return temp->value;

            temp = temp->next;
        }
        return 999;
    }

    void printTable() {
        for (int i = 0; i < SIZE; i++) {
            cout << i << ": " << endl;
            if (dataMap[i]) {
                HT::Node* temp = dataMap[i];
                while (temp) {
                    cout << "  {" << temp->key << ", " << temp->value << "}" << endl;
                    temp = temp->next;
                }
            }
        }
    }

};