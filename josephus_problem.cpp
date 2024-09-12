#include <iostream>
#include <string>
using namespace std;
class Node {
public:
    Node* next;
    Node* prev;
    int data;
    Node(){
    	data=-1;
	next=NULL;
	prev=NULL;
	}
};
class Jos{
private:
    Node* head;
    Node* tail;
    int size;

public:
    Jos(){
	head=NULL;
	tail=NULL;
	size=0;
	}
    void addPerson(int data){
        Node* newNode = new Node();
        newNode->data=data;
        
        if (!head){
            head=tail = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
        } else {
            newNode->prev = tail;
            newNode->next = head;
            tail->next = newNode;
            head->prev = newNode;
            tail = newNode;
        }
        size++;
    }

    void elimination(int k) {
        if (!head || size <= 1) {
            cout << "No person left." <<endl;
            return;
        }
        Node* current = head;
        int count = 0;
        while (size > 1){
            for (int i=0; i < k && current !=NULL;++i){
                current = current->next;
            }
            if (current==NULL){
                current = head;
            }

            Node* nodeToDelete = current;
            current = current->next;

            nodeToDelete->prev->next = nodeToDelete->next;
            nodeToDelete->next->prev = nodeToDelete->prev;

            delete nodeToDelete;

            size--;
        }

        cout << "Last person standing: " << head->data <<endl;
    }
    void display() {
        if (!head) {
            cout << "No persons in the circle." <<endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout <<endl;
    }
};
int main(){
    Jos j;
    int choice, k;
    while (true){
        cout << "\n1. Add Person\n";
        cout << "2. Start Simulation\n";
        cout << "3. Exit\n";

        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data of person: ";
                int data;
                cin >> data;
                j.addPerson(data);
                break;
            case 2:
                cout << "Enter k value: ";
                cin >> k;
                j.elimination(k);
                break;
            case 3:
                return 0;
            default:
                cout << "Invalid choice." <<endl;
        }

        j.display();
    }

    return 0;
}

