#include <iostream>
#include <list>
using namespace std;

template<typename T>
class Stack {
public:
    list<T> stk;

    void push(T a) {
        stk.push_back(a);
    }

    T top() {
        if (stk.empty()) {
            throw runtime_error("Stack is empty");
            }
        return stk.back();
    }

    bool isEmpty() {
        return stk.empty();
    }

    void pop() {
        if (!stk.empty()) {
            stk.pop_back();
        }
        else {
            cout << "Stack is empty, nothing to pop." << endl;
        }
    }

    void display() {
        if (stk.empty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        for (const auto& it : stk) {
            cout << it << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack<int> st;
    bool running = true;

    while (running) {
        int num;
        cout << "---------------STACK---------------" << endl << endl;
        cout << "1) PUSH \n2) POP \n3) IS EMPTY \n4) TOP \n5) DISPLAY \n6) EXIT \n";
        cout << "ENTER YOUR OPTION : -";
        cin >> num;

        switch (num) {
            case 1: {
                int nums;
                cout << "ENTER THE ELEMENT TO PUSH :- ";
                cin >> nums;
                st.push(nums);
                cout << "\nELEMENT INSERTED SUCCESSFULLY" << endl;
                break;
            }
            case 2: {
                st.pop();
                cout << "\nELEMENT POPPED SUCCESSFULLY" << endl;
                break;
            }
            case 3: {
                if (st.isEmpty()) {
                    cout << "Stack is empty" << endl;
                } else {
                    cout << "Stack is not empty" << endl;
                }
                break;
            }
            case 4: {
                try {
                    int a = st.top();
                    cout << "ELEMENT AT TOP IS " << a << endl;
                } catch (const runtime_error& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 5: {
                cout << "ELEMENTS IN STACK ARE :- " << endl;
                st.display();
                break;
            }
            case 6: {
                cout << "PROGRAM TERMINATED" << endl;
                running = false;
                break;
            }
            default: {
                cout << "Invalid option, please try again." << endl;
                break;
            }
        }
    }

    return 0;
}
