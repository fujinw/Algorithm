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

pair<Node*, Node*> createList(int size){
    if(size == 0) return pair<Node*, Node*>{nullptr, nullptr};

    Node* head = newNode(rand()%100);
    Node* last = head;
    for(int i = 0; i < size-1; i++){
        Node* node = newNode(rand()%100);
        last->next = node;
        node->prev = last;
        last = node;
    }
    return pair<Node*, Node*>{head, last};
}

int len(Node* head){
    int count = 0;
    Node* cur = head;
    while(cur != nullptr){
        count++;
        cur = cur->next;
    }
    return count;
}

void printList(Node* start, bool reverse = false){
    if(start == nullptr) return;

    Node* cur = start;
    if(reverse){
        while(cur != nullptr){
            cout << cur->value << " ";
            cur = cur->prev;
        }
    }else{
        while(cur != nullptr){
            cout << cur->value << " ";
            cur = cur->next;
        }
    }
    cout << endl;
}

void del(Node* &head, int target){
    if(head == nullptr) return;

    Node* cur = head;
    while(cur != nullptr){
        Node* nextCur = cur->next;
        if(cur->value == target){
            Node* prev = cur->prev;
            Node* next = cur->next;

            if(prev == nullptr){
                head = next;
                if(head != nullptr) head->prev = nullptr;
            }else{
                prev->next = next;
                if(next != nullptr) next->prev = prev;
            }
            delete cur;
        }
        cur = nextCur;
    }
}

void add(Node*& head, int target, int before){
    if(head == nullptr) return;

    Node* node = newNode(target);
    if(head->value == before){
        head->prev = node;
        node->next = head;
        head = node;
    }else{
        Node* cur = head;
        while(cur != nullptr && cur->value != before ){
            cur = cur->next;
        }
        if(cur == nullptr){
            delete node;
            cout << "Нет такого значения в списке, перед которым можно вставить" << endl;
            return;
        }
        node->prev = cur->prev;
        node->next = cur;
        cur->prev->next = node;
        cur->prev = node;
    }
}

void pushBack(Node*& head, Node*& last, int target){
    Node* node = newNode(target);
    if(last == nullptr){ // если список пуст
        last = node;
        head = node;
    }else{
        last->next = node;
        node->prev = last;
        last = node;
    }
}

bool isPalindrome(Node* head, Node* last){
    if(head == nullptr) return true; // если мы считаем пустоту палиндромом

    while(head!= last && head->prev != last){
        if(head->value != last->value) return false;
        head = head->next;
        last = last->prev;
    }
    return true;
}

int main(){
    int n;
    cin >> n;

    pair<Node*, Node*> pointers = createList(n);
    Node* head = pointers.first;
    Node* last = pointers.second;
    cout << "Печать списка в прямом порядке: " << endl;
    printList(head);
    cout << "Печать списка в обратном порядке: " << endl;
    printList(last, true); // когда вывожу в обратном порядке, делаю это с конца, чтобы было быстрее
    
    add(head, 7, 72);
    cout << "Список после добавления элемента: " << endl;
    printList(head);

    pushBack(head, last, 1000);
    cout << "Список после добавления элемента в конец: " << endl;
    printList(head);

    del(head, 7);
    cout << "Список после удаления элемента: " << endl;
    printList(head);

    int length = len(head);
    cout << "Длина списка: " << length << endl;

    pair<Node*, Node*> palindromCheck = createList(0);
    pushBack(palindromCheck.first,palindromCheck.second, 1);
    pushBack(palindromCheck.first,palindromCheck.second, 2);
    pushBack(palindromCheck.first,palindromCheck.second, 3);
    pushBack(palindromCheck.first,palindromCheck.second, 2);
    pushBack(palindromCheck.first,palindromCheck.second, 1);
    cout << "Список для проверки на палиндром: " << endl;
    printList(palindromCheck.first);
    cout << "Является ли список палиндоромом: " << isPalindrome(palindromCheck.first, palindromCheck.second) << endl;

    return 0;
}