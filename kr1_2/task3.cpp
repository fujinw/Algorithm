#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* next;
    Node* prev;
};

Node* newNode(int key = -1){
    Node* node = new Node;
    node->value = key;
    node->next = nullptr;
    node->prev = nullptr;
    return node;
}

Node* creationList(int size){
    if(size == 0) return nullptr;

    Node* head = newNode(rand()%100);
    Node* cur = head;
    for(int i = 0; i < size - 1; i++){
        Node* node = newNode(rand()%100);
        cur->next = node;
        node->prev = cur;
        cur = node;
    }
    cur->next = head;
    head->prev = cur;
    return head;
}

void printList(Node* head){
    if(head == nullptr) return;
    
    Node* cur = head;
    do{
        cout << cur->value << " " << cur << endl; // вывожу адресса, чтобы видеть, что все выводимые элементы уникальны
        cur = cur->next;
    }while(cur != head);
    cout << endl;
}

void del(Node* &head, int target){
    if(head == nullptr) return;

    Node* cur = head;
    do{
        if(cur->value == target){
            if(cur->next == cur){ // если всего один элемент в списке
                delete cur;
                head = nullptr;
                return;
            }

            if(cur == head) head = head->next; 

            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            delete cur;
            return;
        }
        cur = cur->next;
    }while(cur != head);
}

void add(Node* head, int value){
    Node* node = newNode(value);
    if(head == nullptr){ // если пустой список
        node->next = node;
        node->prev = node;
        head = node;
        return;
    }
    
    Node* prev = head->prev;
    prev->next = node;
    node->prev = prev;
    node->next = head;
    head->prev = node;
}

int main(){
    int n;
    cin >> n;
    Node* head = creationList(n);

    cout << "Исходный список: "<< endl;
    printList(head);

    int num;
    cin >> num;
    add(head, num);
    cout << "Список после добавления нового элемента: " << endl;
    printList(head);

    del(head, num);
    cout << "Список после удаления элемента: " << endl;
    printList(head);
}