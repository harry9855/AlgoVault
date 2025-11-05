#include <iostream>
#include <cstdlib>  
#include <limits>   
using namespace std;

class Queue {
    int* arr;
    int Front;
    int Rear;
    int Size;

public:
    Queue() {
        Front = 0;
        Rear = -1;
        Size = 100;
        arr = new int[Size];
    }

    bool isFull() {
        return (Rear == Size - 1);
    }

    bool isEmpty() {
        return (Rear == -1 || Front > Rear);
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "\nQUEUE IS FULL! CANNOT INSERT MORE ELEMENTS.\n";
        } else {
            Rear++;
            arr[Rear] = data;
            cout << "\n" << data << " INSERTED INTO QUEUE.\n";
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "\nQUEUE IS EMPTY! CANNOT DEQUEUE ELEMENT.\n";
        } else {
            cout << "\n" << arr[Front] << " IS REMOVED FROM QUEUE.\n";
            Front++;
            if (Front > Rear) {
                Front = 0;
                Rear = -1;
            }
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "\nQUEUE IS EMPTY. NOTHING TO DISPLAY.\n";
        } else {
            cout << "\nQUEUE IS -----> ";
            for (int i = Front; i <= Rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    ~Queue() {
        delete[] arr;
    }
};


void pressAnyKey() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 
}

int main() {
    Queue q1;
    int choice;

    while (true) {
        system("cls");  
        cout << "==============================\n";
        cout << "        QUEUE OPERATIONS      \n";
        cout << "==============================\n";
        cout << "1) ENQUEUE\n";
        cout << "2) DEQUEUE\n";
        cout << "3) DISPLAY\n";
        cout << "4) EXIT\n";
        cout << "==============================\n";
        cout << "ENTER YOUR CHOICE :- ";
        cin >> choice;

        system("cls");

        switch (choice) {
            case 1: {
                int data;
                cout << "ENTER THE NUMBER :- ";
                cin >> data;
                q1.enqueue(data);
                break;
            }
            case 2:
                q1.dequeue();
                break;
            case 3:
                q1.display();
                break;
            case 4:
                cout << "\nExiting program...\n";
                return 0;
            default:
                cout << "\nINVALID CHOICE! TRY AGAIN.\n";
        }

        pressAnyKey();
    }
}
