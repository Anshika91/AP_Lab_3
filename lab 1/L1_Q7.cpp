#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};
Node* deleteNode(Node* start, int k){
    if (k < 1) return start;
    if (start == NULL) return NULL;
    if (k == 1){
        Node *res = start->next;
        delete(start);
        return res;  
    }
    start->next = deleteNode(start->next, k-1);
    return start;
}
void insert(struct Node **head_ref, int new_data) {
    struct Node *new_node = new Node;
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}  
void printList(struct Node *head){
    while (head!=NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout<<endl;
}
int main(){
    struct Node *head = NULL;
    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    insert(&head,4);
    insert(&head,5);
    insert(&head,6);
    head = deleteNode(head, 3);
    printList(head);
    return 0;
}
