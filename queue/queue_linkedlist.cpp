#include <iostream>
#include <conio.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }


    void enqueue(int data) {
        Node* temp = new Node(data);

        if (rear == nullptr) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }

        cout << data << " INSERTED SUCCESSFULLY\n";
    }


    void dequeue() {
        if (isEmpty()) {
            cout << "QUEUE IS EMPTY! NOTHING TO DELETE\n";
            return;
        }

        Node* temp = front;
        cout << temp->data << " IS DELETED SUCCESSFULLY\n";

        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        delete temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "QUEUE IS EMPTY! NOTHING TO DISPLAY\n";
            return;
        }

        cout << "QUEUE IS ----> ";
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~Queue() {
        while (!isEmpty())
            dequeue();
    }
};

void pressAnyKey() {
    cout << "\nPress any key to continue...";
    getch();
}

int main() {
    Queue q;
    int choice, data;

    while (true) {
        cout << "\n==============================\n";
        cout << "        QUEUE OPERATIONS      \n";
        cout << "==============================\n";
        cout << "1) ENQUEUE\n";
        cout << "2) DEQUEUE\n";
        cout << "3) DISPLAY\n";
        cout << "4) EXIT\n";
        cout << "==============================\n";
        cout << "ENTER YOUR CHOICE: ";
        cin >> choice;

        system("cls");
        cout << endl;

        switch (choice) {
            case 1:
                cout << "ENTER THE ELEMENT: ";
                cin >> data;
                q.enqueue(data);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "EXITING PROGRAM...\n";
                return 0;
            default:
                cout << "INVALID CHOICE! TRY AGAIN.\n";
        }

        pressAnyKey();
         system("cls");
    }
}
