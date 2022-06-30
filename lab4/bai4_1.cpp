#include <iostream> 
using namespace std;
struct Node { 
    int data; 
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

// push a new element to the beginning of the list
Node* prepend(Node* head, int data) {
    /*****************/
    if(head == NULL) return new Node(data);

    Node *tmp = new Node(data);
    tmp->next = head;
    return tmp;
    /*****************/
}

// print the list content on a line
void print(Node* head) {
    /*****************/
    while(head != NULL) {
        cout << head->data;
        head = head->next;
    }

    cout << '\n';
    /*****************/
}

// return the new head of the reversed list
Node* reverse(Node* head) {
    Node *result = NULL;
    Node *temp = NULL;
    while(head != NULL) {
        temp = head->next;
        head->next = result;
        result = head;
        head = temp;
    }
    return result;
    /*****************/
}
  
int main() {
    cout << "Ho Sy The - 20200614\n";

    int n, u;
    cin >> n;
    Node* head = NULL;
    for (int i = 0; i < n; ++i){
        cin >> u;
        head = prepend(head, u);
    } 
    
    cout << "Original list: ";
    print(head);

    head = reverse(head);
    
    cout << "Reversed list: ";
    print(head);

    return 0; 
}