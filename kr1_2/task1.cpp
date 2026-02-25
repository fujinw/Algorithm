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

Node* lastFromList(Node* head){
    Node* last = head;
    while(last->next != nullptr){
        last = last->next;
    }
    return last;
}

bool hasCicle(Node* head){
    if(head == nullptr) return false;
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    Node* head = createLinkedList(n);
    Node* head1 = createLinkedList(n);
    //зацикливаю созданный список
    Node* second = head->next;
    Node* last = lastFromList(head);
    last->next = head;

    if(hasCicle(head)){
        cout << "Перескок найден" << endl;
    }else{
        cout << "Перескок не найден" << endl;
    }

    // организую проскок
    Node* third = head->next->next;
    third->next = third->next->next;
    int l = 0;
    Node* cur = head1;
    while(cur->next != nullptr){
        l++;
        cur = cur->next;
    }
    if(l != n){
        cout << "Проскок найден";
    }else{
        cout << "Проскок не найден";
    }
    
    return 0;
}