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
    
    Node* head = newNode(rand()%10);
    Node* last = newNode(rand()%10);
    head->next = last;
    for(int i = 0; i < size - 2;i++){
        Node* node = newNode(rand()%9+1);
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

void pushBack(Node*& head, int num){
    if(head == nullptr){
        head = newNode(num);
        return;
    }

    Node* last = head;
    while(last->next != nullptr){
        last = last->next;
    }

    Node* node = newNode(num);
    last->next = node;
}

Node* addition(Node* head1, Node* head2){
    Node* cur1 = head1;
    Node* cur2 = head2;
    Node* ans = nullptr;
    int transfer = 0, bit;
    while(cur1 != nullptr && cur2 != nullptr){
        int result = cur1->value + cur2->value + transfer;
        transfer = result/10;
        bit = result%10;
        pushBack(ans, bit);

        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    Node* cur = nullptr;
    if(cur1 == nullptr){
        cur = cur2;
    }else{
        cur = cur1;
    }

    while(cur != nullptr){
        int result = cur->value + transfer;
        transfer = result/10;
        bit = result%10;
        pushBack(ans, bit);

        cur = cur->next;
    }
    return ans;
}

int main(){
    int size1, size2;
    cout << "Введите размер первого числа: ";
    cin >> size1;
    cout << endl << "Введите размер второго числа: ";
    cin >> size2;

    Node* num1 = createLinkedList(size1);
    Node* num2 = createLinkedList(size2);

    cout << "Первое число в обратном порядке: " << endl;
    printList(num1);
    cout << "Второе число в обратном порядке: " << endl;
    printList(num2);

    Node* result = addition(num1, num2);
    cout << "Результат сложения: " << endl;
    printList(result);

    return 0;
}