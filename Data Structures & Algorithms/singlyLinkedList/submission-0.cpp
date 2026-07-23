#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int value) {
        val = value;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    int size;

    LinkedList() {
        head = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size)
            return -1;

        Node* temp = head;

        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }

        return temp->val;
    }

    void insertHead(int val) {
        Node* newNode = new Node(val);

        newNode->next = head;
        head = newNode;

        size++;
    }

    void insertTail(int val) {
        Node* newNode = new Node(val);

        // Empty list
        if (head == nullptr) {
            head = newNode;
            size++;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;

        size++;
    }

    bool remove(int index) {
        if (index < 0 || index >= size)
            return false;

        // Remove head
        if (index == 0) {
            Node* del = head;
            head = head->next;
            delete del;

            size--;
            return true;
        }

        Node* temp = head;

        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }

        Node* del = temp->next;
        temp->next = temp->next->next;

        delete del;

        size--;
        return true;
    }

    vector<int> getValues() {
        vector<int> arr;

        Node* temp = head;

        while (temp != nullptr) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        return arr;
    }
};