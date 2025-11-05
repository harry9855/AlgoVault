#include<iostream>
#include<conio.h>
using namespace std;

template<typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template<typename T>
class Stack {
private:
    Node<T>* head;
public:
    Stack(){
        head=nullptr;
    }
    void Push(T data) {
        Node<T>* temp = new Node<T>(data);
        if (head == NULL) {
            head = temp;
        } else {
            Node<T>* ptr = head;
            while (ptr->next != nullptr) {
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
    }

    void Pop() {
        if (head == NULL) {
            cout << "STACK IS EMPTY!!! ELEMENT CANNOT BE POPPED\n";
        } else if (head->next == NULL) {
            delete head;
            head = NULL;
            cout << "ELEMENT IS DELETED SUCCESSFULLY...... ";
        } else {
            Node<T>* temp = head;
            while (temp->next->next != NULL) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
            cout << "ELEMENT IS DELETED SUCCESSFULLY...... ";
        }
    }

    void Show() {
        if (head != NULL) {
            Node<T>* temp = head;
            cout << "STACK IS: ";
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        } else {
            cout << "EMPTY STACK !!!!! CANNOT DISPLAY." << endl;
        }
    }

    int Size() {
        int cnt = 0;
        Node<T>* temp = head;
        while (temp != NULL) {
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }

    void isEmpty() {
        if (head == NULL) {
            cout << "STACK IS EMPTY !!! ";
        } else {
            cout << "STACK IS NOT EMPTY....";
        }
    }

    T top() {

            Node<T>* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            return temp->data;
    }
};



