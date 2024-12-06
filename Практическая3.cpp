#include <iostream>


struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList{
    
    Node* head;
    Node* tail;

public:
    
    void push_front(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void push_back(int value) {
        Node* newNode = new Node(value); // получение значения
        if (head == nullptr) { // проверка на пустоту списка
            head = newNode; //приравнивание к 1 элементу списка полученного значения
            return;
        }
        Node* cur = head; // создание экземпляра Node равному 1 значение в списке
        while (cur->next != nullptr) { // проверка элемента
            cur = cur->next; // проходимся по списку проверяя СЛЕДУЮЩИЙ элемент
        }
        cur->next = newNode; // к найденному элементу nullptr присваиваем полученное значение
        newNode->prev = cur; // СОЗДАЁМ СВЯЗЬ МЕЖДУ ЭЛЕМЕНТАМИ   temp->   <-newNode
    }
    void pop_front() {
        if (head == nullptr) {
            std::cout << "Список пуст" << "\n";
            return;
        }
        Node* cur = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete cur;
    }
    void pop_back() {
        if (head == nullptr) {
            std::cout << "Список пуст" << "\n";
            return;
        }
        Node* cur = head;
        if (cur->next == nullptr) {
            head = nullptr;
            delete cur;
            return;
        }
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->prev->next = nullptr;
        delete cur;
    }
    void display() {
        Node* cur = head;
        while (cur != nullptr) {
            std::cout << cur->data << " ";
            cur = cur->next;
        }
        std::cout << "\n";
    }

    void sort() {
        if (head == nullptr) {
            return;
        }
        bool swapped;
        Node* cur;
        do {
            swapped = false;
            cur = head;
            while (cur->next != nullptr) {
                if (cur->data > cur->next->data) {
                    std::swap(cur->data, cur->next->data);
                    swapped = true;
                }
                cur = cur->next;
            }
        } while (swapped);
    }
    void remove_duplicates() {
        if (head == nullptr) {
            return;
        }
        Node* cur = head;
        while (cur != nullptr) {
            Node* runner = cur->next;
            while (runner != nullptr) {
                if (cur->data == runner->data) {
                    Node* duplicate = runner;
                    runner->prev->next = runner->next;
                    if (runner->next != nullptr) {
                        runner->next->prev = runner->prev;
                    }
                    runner = runner->next;
                    delete duplicate;
                }
                else {
                    runner = runner->next;
                }
            }
            cur = cur->next;
        }
    }
};

DoublyLinkedList list;



int main()
{
    setlocale(LC_ALL, "russian");
    srand(time(NULL));


    DoublyLinkedList a;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    list.push_front(5);
    list.push_front(5);
    list.push_back(5);
    list.display();
    list.sort();
    list.display();
    list.remove_duplicates();
    list.display();
    

    return 0;
}

