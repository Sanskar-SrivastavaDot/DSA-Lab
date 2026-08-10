#include <bits/stdc++.h> 
using namespace std; 

class Node{ 
public: 
    int val; 
    Node* next; 
    Node(int val){ 
        this->val = val; 
        this->next = NULL; 
    } 
}; 

class ll{ 
public: 
    Node* head; 
    Node* Tail; 
    ll(){ 
        head = NULL; 
        Tail = NULL; 
    } 
    void add(int val){ 
        if(head==NULL){ 
            head = new Node(val); 
            Tail = head; 
        }else{ 
            Node* n = new Node(val); 
            Tail->next = n; 
            Tail = n; 
        } 
    } 
    void del(int idx){ 
        if(head == NULL) {
            cout << "List is already Empty." << endl; 
            return;
        }
        if(idx == 0) {
            Node* toDelete = head;
            head = head->next;
            if(head == NULL) {
                Tail = NULL;
            }
            delete toDelete;
            return;
        }
        Node* Temp = head; 
        int i=0; 
        while(i<idx-1 && Temp!=NULL){ 
            Temp = Temp->next; 
            i++; 
        } 
        if(Temp == NULL || Temp->next == NULL) {
            return;
        }
        Node* toDelete = Temp->next;
        if(toDelete == Tail){ 
            Tail = Temp; 
        } 
        Temp->next = Temp->next->next; 
        delete toDelete;
    } 
    void Search(int val){ 
        Node* temp = head; 
        int i = 0; 
        while(temp!=NULL){ 
            if(temp->val==val){ 
                cout << "Found at Index " << i << endl; 
                return; 
            } 
            i++; 
            temp = temp->next;
        } 
        cout << "Not Found" << endl; 
    } 
    void show(){ 
        Node* temp = head; 
        while(temp!=NULL){ 
            cout << temp->val << " "; 
            temp = temp->next; 
        } 
        cout << endl; 
    } 
}; 

int main() { 
    ll list; 
    list.add(9); 
    list.add(2); 
    list.add(3); 
    list.add(1); 
    list.add(8); 
    list.show(); 
    list.del(2); 
    list.show(); 
    return 0; 
}
