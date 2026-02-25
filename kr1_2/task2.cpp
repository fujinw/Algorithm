#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* next;
};

Node* newNode(int key = -1){
    Node* node = new Node;
    node->value = key;
    node->next = nullptr;
    return node;
}

Node* createLinkedList(int size){ // создание и заполнение списка случайными элементами
    if(size == 0) return nullptr;
    
    Node* head = newNode(rand()%100);
    Node* last = newNode(rand()%100);
    head->next = last;
    for(int i = 0; i < size - 2;i++){
        Node* node = newNode(rand()%100);
        last->next = node;
        last = node;
    }
    return head;
}

void printList(Node* head){
    Node* cur = head;
    while(cur != nullptr){
        cout << cur->value << " ";
        cur = cur->next;
    }
    cout << endl;
}

void partition(Node* head, Node* &headUpx, Node* &headDnx, int x){
    Node* cur = head;
    Node* lastUpx = nullptr;
    Node* lastDnx = nullptr;

    while(cur != nullptr){
        Node* next = cur->next;
        cur->next = nullptr;

        if(cur->value >= x){
            if(headUpx == nullptr){ // первый найденный елемент >= x
                headUpx = lastUpx = cur;
            }else{                          // все остальные
                lastUpx->next = cur;
                lastUpx = cur;
            }
        }else{
            if(headDnx == nullptr){ // первый найденный елемент < x
                headDnx = lastDnx = cur;
            }else{                          // все остальные
                lastDnx->next = cur;
                lastDnx = cur;
            }
        }
        cur = next;
    }
}

int main(){
    int n;
    cin >> n;
    Node* head = createLinkedList(n);
    int x;
    cin >> x;
    Node* upX = nullptr;
    Node* dnX = nullptr;
    cout << "Исходный список: " << endl;
    printList(head);
    partition(head, upX, dnX, x);
    cout << "Больше x: " << endl;
    printList(upX);
    cout << "Меньше x: " << endl;
    printList(dnX);
    return 0;
}