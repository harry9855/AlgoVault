#include <iostream>
#include <conio.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// INSERTION AT HEAD
void insertion_head(Node* &head, int data) {
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

// INSERTION AT TAIL
void insertion_tail(Node* &head, int data) {
    Node* temp = new Node(data);
    if (head == nullptr) {   // Handle empty list
        head = temp;
        return;
    }
    Node* ptr = head;
    while (ptr->next != nullptr) {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

// INSERTION ANYWHERE
void insertion_middle(Node* &head, int data, int position) {
    if (position == 1) {
        insertion_head(head, data);
        return;
    }
    Node* new_node = new Node(data);
    Node* temp = head;
    int cnt = 1;
    while (cnt < position - 1 && temp != nullptr) {
        temp = temp->next;
        cnt++;
    }
    if (temp == nullptr) {
        cout << "Position out of range\n";
        delete new_node;
        return;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

// INSERTION OF 1ST NODE
void insertion(Node* &head, int data) {
    Node* temp = new Node(data);
    if (head == NULL) {
        head = temp;
    }
}

// DELETION AT HEAD
void deletion_first(Node* &head) {
    Node* temp = head;
    head = head->next;
    delete temp;
}

// DELETION AT TAIL
void deletion_last(Node* &head) {
    if (head == NULL || head->next == NULL) {
        delete head;
        head = NULL;
    } else {
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
}

// DELETION ANYWHERE
void deletion(Node* &head, int position) {
    if (head == nullptr) {
        cout << "EMPTY LINKED LIST !!!!! CANNOT DELETE." << endl;
        return;
    }
    int cnt = 1;
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
        cnt++;
    }
    if (position == 1) {
        deletion_first(head);
    } else if (cnt > 1 && cnt == position) {
        deletion_last(head);
    } else if (position > cnt) {
        cout << "Node " << position << " not found" << endl;
    } else {
        Node* curr = head;
        Node* prev = NULL;
        int ct = 1;
        while (curr != NULL && ct < position) {
            prev = curr;
            curr = curr->next;
            ct++;
        }
        prev->next = curr->next;
        delete curr;
    }
}

// DISPLAY
void display(Node* &head) {
    if (head != NULL) {
        Node* temp = head;
        cout << "LINKED LIST IS ---->  ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    } else {
        cout << "EMPTY LINKED LIST !!!!! CANNOT DISPLAY." << endl;
    }
}

// SIZE OF LINKED LIST
int Size(Node* head) {
    int cnt = 0;
    Node* temp = head;
    while (temp != NULL) {
        temp = temp->next;
        cnt++;
    }
    cout << endl << "SIZE OF LINKED LIST IS :- " << cnt << endl << endl;
    return cnt;
}

// EXECUTION FIRST NODE
void first_node(Node* &head) {
    int data;
    cout << "CREATING FIRST NODE" << endl;
    cout << "ENTER THE ELEMENT YOU WANT TO INSERT:- ";
    cin >> data;
    system("cls");
    insertion(head, data);
    cout << "NODE CREATED SUCCESSFULLY" << endl << endl;
    cout << "PRESS ANY KEY TO CONTINUE";
    getch();
    system("cls");
}

// EXECUTION INSERTION AT HEAD
void IAH(Node* &head) {
    if (head == nullptr) {
        first_node(head);
    } else {
        int data;
        cout << "----------INSERTION----------" << endl << endl;
        cout << "ENTER THE ELEMENT YOU WANT TO INSERT :- ";
        cin >> data;
        insertion_head(head, data);
        system("cls");
        cout << endl << "NODE INSERTED AT HEAD" << endl << endl;
        cout << "PRESS ANY KEY TO CONTINUE";
        getch();
        system("cls");
    }
}

// EXECUTION INSERTION AT TAIL
void IAT(Node* &head) {
    if (head == nullptr) {
        first_node(head);
    } else {
        int data;
        cout << "----------INSERTION----------" << endl << endl;
        cout << "ENTER THE ELEMENT YOU WANT TO INSERT:- ";
        cin >> data;
        insertion_tail(head, data);
        system("cls");
        cout << "NODE INSERTED AT TAIL SUCCESSFULLY" << endl << endl;
        cout << "PRESS ANY KEY TO CONTINUE";
        getch();
        system("cls");
    }
}

// EXECUTION INSERTION ANYWHERE WITH VALID POSITION MESSAGE
int IAL(Node* &head) {
    while (1) {
        int a = Size(head);  // get current size
        if (head == nullptr) {
            first_node(head);
            return 0;
        } else {
            int data;
            int position;
            cout << "----------INSERTION----------" << endl << endl;
            cout << "ENTER THE ELEMENT YOU WANT TO INSERT :- ";
            cin >> data;

            // Show valid positions message here
            cout << "You can insert at positions from 1 to " << a + 1 << "." << endl;

            cout << "ENTER THE POSITION WHERE YOU WANT TO INSERT :- ";
            cin >> position;

            if (position >= 1 && position <= a + 1) {
                insertion_middle(head, data, position);
                system("cls");
                cout << endl << "NODE INSERTED AT POSITION " << position << endl << endl;
                cout << "PRESS ANY KEY TO CONTINUE";
                getch();
                system("cls");
                return 0;
            } else {
                cout << "POSITION EXCEEDS THE LINKED LIST" << endl << endl;
                cout << "PRESS ANY KEY TO CONTINUE";
                getch();
                system("cls");
            }
        }
    }
}

// DELETION OF 1ST LINKED LIST AND ERROR OF NO LINKED LIST
void DELETE(Node* &head) {
    if (head == nullptr) {
        cout << "EMPTY LINKED LIST !!!!! CANNOT DELETE." << endl << endl;
        cout << "PRESS ANY KEY TO CONTINUE";
        getch();
        system("cls");
    } else if (head->next == nullptr) {
        delete head;
        head = nullptr;
        cout << "LINKED LIST DELETED SUCCESSFULLY" << endl << endl;
        cout << "PRESS ANY KEY TO CONTINUE";
        getch();
        system("cls");
    }
}

// DELETION AT HEAD
void DAH(Node* &head) {
    if (head == nullptr || head->next == nullptr) {
        DELETE(head);
    } else {
        deletion_first(head);
        cout << "FIRST NODE DELETED" << endl << endl;
        cout << "PRESS ANY KEY TO CONTINUE";
        getch();
        system("cls");
    }
}

// DELETION AT TAIL
void DAT(Node* &head) {
    if (head != NULL) {
        deletion_last(head);
        cout << "LAST NODE DELETED" << endl << endl;
        cout << "PRESS ANY KEY TO CONTINUE";
        getch();
        system("cls");
    } else {
        DELETE(head);
    }
}

// DELETION ANYWHERE
void DAL(Node* &head) {
    if (head != NULL) {
        int position;
        cout << "ENTER THE POSITION WHERE YOU WANT TO DELETE THE ELEMENT :- ";
        cin >> position;
        deletion(head, position);
        system("cls");
        cout << "NODE AT POSITION " << position << " IS DELETED SUCCESSFULLY" << endl << endl;
        cout << "PRESS ANY KEY TO CONTINUE";
        getch();
        system("cls");
    } else {
        DELETE(head);
    }
}

// SEARCHING FOR ELEMENT VIA DATA
void searching(Node* &head) {
    if (head != NULL) {
        int num;
        int ct = 0;
        Node* temp = head;
        int flag = 0;
        cout << "ENTER THE NUMBER YOU WANT TO SEARCH :- ";
        cin >> num;
        system("cls");
        while (temp != NULL) {
            ct++;
            if (temp->data == num) {
                cout << "ELEMENT FOUND AT POSITION " << ct << endl;
                flag++;
            }
            temp = temp->next;
        }
        if (flag == 0) {
            cout << "ELEMENT NOT IN LINKED LIST";
        }
        cout << endl << endl << "PRESS ANY KEY TO CONTINUE";
        getch();
        system("cls");
    } else {
        cout << "NO LINKED LIST FOUND";
        cout << endl << endl << "PRESS ANY KEY TO CONTINUE";
        getch();
        system("cls");
    }
}

// SEARCHING FOR ELEMENT VIA POSITION
void Search(Node* &head) {
    if (head != NULL) {
        int ct = 0;
        int position;
        bool flag = false;
        cout << "ENTER THE POSITION WHERE YOU WANT TO FIND THE ELEMENT :- ";
        cin >> position;
        Node* temp = head;
        while (temp != NULL) {
            ct++;
            if (ct == position) {
                cout << temp->data << " FOUND AT POSITION " << ct << endl << endl;
                flag = true;
                break;
            }
            temp = temp->next;
        }
        if (flag == false) {
            cout << "POSITION EXCEEDS THE LINKED LIST SIZE" << endl << endl;
        }
    } else {
        cout << "EMPTY LINKED LIST!!!!! CANNOT SEARCH." << endl << endl;
        cout << "PRESS ANY KEY TO CONTINUE";
        getch();
        system("cls");
    }
}

// REVERSING LINKED LIST
Node* reversing(Node* &head) {
    if (head != NULL) {
        Node* temp = head;
        Node* prev = NULL;
        while (temp != NULL) {
            Node* Front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = Front;
        }
        return prev;
    }
    return NULL;
}

// MENU FUNCTIONS
void Show() {
    cout << "----------------------------WELCOME----------------------------" << endl;
    cout << endl << "1) INSERTION" << endl << "2) DELETION" << endl << "3) DISPLAY" << endl << "4) SEARCHING" << endl << "5) SIZE" << endl << "6) REVERSING" << endl << "7) EXIT" << endl << endl;
    cout << "SELECT YOUR OPTION :- ";
}

void Show1() {
    cout << "**********************INSERTION*********************" << endl;
    cout << endl << "1) INSERT AT TAIL" << endl << "2) OTHER OPTION" << endl << endl;
    cout << "SELECT YOUR OPTION :- ";
}

void other_options() {
    cout << "======================= OTHER OPTIONS =======================" << endl;
    cout << "1) INSERT AT HEAD" << endl << "2) INSERT AT TAIL" << endl << "3) INSERT AT ANY LOCATION" << endl;
    cout << endl << "ENTER YOUR OPTION :- ";
}

void show2() {
    cout << "******************DELETE******************" << endl << endl;
    cout << "1) DELETE AT TAIL" << endl << "2) OTHER OPTIONS" << endl;
    cout << "ENTER THE OPTION :- ";
}

void del_option() {
    cout << "======================= OTHER OPTIONS =======================" << endl;
    cout << "1) DELETE AT HEAD" << endl << "2) DELETE AT TAIL" << endl << "3) DELETE AT ANY LOCATION" << endl;
    cout << endl << "ENTER YOUR OPTION :- ";
}

void wrong() {
    cout << "ENTER A VALID OPTION !!!!" << endl << endl;
    cout << "PRESS ANY KEY TO CONTINUE" << endl << endl;
    getch();
    system("cls");
}

void cs(Node* &head) {
    cout << "1) SEARCHING VIA DATA" << endl << "2) SEARCHING VIA POSITION" << endl << endl;
    cout << "ENTER YOUR OPTION :- ";
}

int main() {
    Node* head = NULL;
    while (1) {
        int num;
        Show();
        cin >> num;
        system("cls");
        switch (num) {
        case 1:
        {
            int num1;
            Show1();
            cin >> num1;
            system("cls");
            if (num1 == 1) {
                IAT(head);
            }
            else if (num1 == 2) {
                int num2;
                other_options();
                cin >> num2;
                system("cls");
                if (num2 == 1) {
                    IAH(head);
                }
                else if (num2 == 2) {
                    IAT(head);
                }
                else if (num2 == 3) {
                    IAL(head);
                }
                else {
                    wrong();
                }
            }
            else {
                wrong();
            }
            break;
        }
        case 2:
        {
            int num3;
            Size(head);
            show2();
            cin >> num3;
            system("cls");
            if (num3 == 1) {
                DAT(head);
            }
            else if (num3 == 2) {
                int num4;
                Size(head);
                del_option();
                cin >> num4;
                system("cls");
                if (num4 == 1) {
                    DAH(head);
                }
                else if (num4 == 2) {
                    DAT(head);
                }
                else if (num4 == 3) {
                    DAL(head);
                }
                else {
                    wrong();
                }
            }
            else {
                wrong();
            }
            break;
        }
        case 3:
            display(head);
            cout << endl << "PRESS ANY KEY TO CONTINUE";
            getch();
            system("cls");
            break;
        case 4:
        {
            int num5;
            cs(head);
            cin >> num5;
            system("cls");
            if (num5 == 1) {
                searching(head);
            }
            else if (num5 == 2) {
                Search(head);
            }
            break;
        }
        case 5:
            Size(head);
            cout << endl << "PRESS ANY KEY TO CONTINUE";
            getch();
            system("cls");
            break;
        case 6:
            head = reversing(head);
            display(head);
            cout << endl << endl << "PRESS ANY KEY TO CONTINUE";
            getch();
            system("cls");
            break;
        case 7:
            system("cls");
            cout << "PROGRAM ENDED SUCCESSFULLY" << endl << endl;
            return 0;
        default:
            wrong();
            break;
        }
    }
    return 0;
}
