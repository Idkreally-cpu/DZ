#include <iostream>

struct Node {
    int data;    
    Node* next;  

    Node(int value) : data(value), next(nullptr) {}
};

class SimpleList {
private:
    Node* head;

public:
    SimpleList() : head(nullptr) {}

    void addFront(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void addBack(int value) {
        Node* newNode = new Node(value);

        if (!head) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    void removeFront() {
        if (!head) return;

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    bool find(int value) {
        Node* current = head;
        while (current) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void print() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "NULL" << std::endl;
    }

    void clear() {
        while (head) {
            removeFront();
        }
    }

    ~SimpleList() {
        clear();
    }
};

int main() {
    SimpleList list;

    list.addBack(10);
    list.addBack(20);
    list.addBack(30);
    list.addFront(5);  

    std::cout << "Список: ";
    list.print();

    std::cout << "Найти 20: " << (list.find(20) ? "Да" : "Нет") << std::endl;
    std::cout << "Найти 99: " << (list.find(99) ? "Да" : "Нет") << std::endl;

    list.removeFront();
    std::cout << "После удаления первого: ";
    list.print();

    return 0;
}
