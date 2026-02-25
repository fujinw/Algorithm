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


void transforming(Node*& head){
    Node* cur = head;
    Node* evenHead = nullptr;
    Node* evenTail = nullptr;
    Node* oddHead = nullptr;
    Node* oddTail = nullptr;
    while(cur != nullptr){ 
        if(cur->value%2==0){
            if(evenHead == nullptr){
                evenHead = evenTail = cur;
            }else{
                evenTail->next = cur;
                evenTail = cur;
            }
        }else{
            if(oddHead == nullptr){
                oddHead = oddTail = cur;
            }else{
                oddTail->next = cur;
                oddTail = cur;
            }
        }
        cur = cur->next;
    }

    oddTail->next = nullptr;
    if(evenHead != nullptr){
        evenTail->next = oddHead;
        head = evenHead; 
    }else{
        head = oddHead;
    }
}

void printList(Node* head){
    Node* cur = head;
    while(cur != nullptr){
        cout << cur->value << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main(){
    int size;
    cin >> size;
    Node* head = createLinkedList(size);
    cout << "Список до трансформации: " << endl;
    printList(head);

    transforming(head);
    cout << "Список после трансформации: " << endl;
    printList(head);

    return 0;
}