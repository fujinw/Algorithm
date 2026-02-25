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

void pushBack(Node*& head, Node*& last, int num){
    if(head == nullptr){
        head = newNode(num);
        last = head;
        return;
    }

    Node* node = newNode(num);
    last->next = node;
    node->prev = last;
    last = node;
}

Node* matching(Node*head1, Node* head2){
    Node* cur1 = head1;
    Node* cur2 = head2;

    Node* resultHead = nullptr;
    Node* resultLast = nullptr;

    while(cur1 != nullptr && cur2 != nullptr){
        if(cur1->value == cur2->value){
            pushBack(resultHead, resultLast, cur1->value);
            cur1 = cur1->next;
            cur2 = cur2->next;
        }else if(cur1->value > cur2->value){
            while(cur2 != nullptr && cur2->value < cur1->value){
                cur2 = cur2->next;
            }
        }else{
            while(cur2 != nullptr && cur1->value < cur2->value){
                cur1 = cur1->next;
            }
        }
    }

    return resultHead;
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

int main(){
    Node* head1 = nullptr;
    Node* last1 = nullptr;
    Node* head2 = nullptr;
    Node* last2 = nullptr;

    int n, m;
    cout << "Введите n: ";
    cin >> n; 
    cout << endl << "Введите m: ";
    cin >> m;

    cout << endl << "Введите n чисел: " << endl;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        pushBack(head1, last1, temp);
    }
    cout << "Введите m чисел: " << endl;
    for(int i = 0; i < m; i++){
        int temp;
        cin >> temp;
        pushBack(head2, last2, temp);
    }

    Node* result = matching(head1, head2);
    cout << "Результат сопоставления: " << endl;
    printList(result);

    return 0;
}

