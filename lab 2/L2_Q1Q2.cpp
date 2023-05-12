#include<bits/stdc++.h>
using namespace std;
class Node{
public:
  int data;
  Node *left;
  Node *right;
  Node(int data){
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
  }
};
class bst{
public:
  Node *root=NULL;
  void insert(int key){
    Node *newNode = new Node(key);
    Node *temp = this->root;
    Node *parent = this->root;
    if(root==nullptr){
      root = newNode;
      return;
    }
    while(temp!=nullptr){
      parent = temp;
      if(temp->data>key) temp = temp->left;
      else temp = temp->right;
    }
    if(parent->data>key) parent->left = newNode;
    if(parent->data<key) parent->right = newNode; 
  }
  void inorder(Node *node){
    if(node==nullptr) return;
    inorder(node->left);
    cout<<node->data<<endl;
    inorder(node->right);
  }
  Node *successor(int key){
    Node *node = searchBst(key);
    if(node==nullptr) return node;
    node = node->right;
    while(node->right!=nullptr and node!=nullptr) node = node->left;
    return node;
  }
  Node *deleteNode(Node *&root, int key){
    if (root == NULL)
      return root;
    if (key < root->data)
      root->left = deleteNode(root->left, key);
    else if (key > root->data)
      root->right = deleteNode(root->right, key);
    else{
      if (root->left == NULL and root->right == NULL)     //0 child
        return NULL;
      else if (root->left == NULL){                 //1 child
        Node *temp = root->right;
        free(root);
        return temp;
      }
      else if (root->right == NULL)
      {
        Node *temp = root->left;
        free(root);
        return temp;
      }
      Node *temp = successor(root->right->data);      //2 child
      root->data = temp->data;
      root->right = deleteNode(root->right, temp->data);
    }
    return root;
  }
};
int main(){
  bst obj;
  int n,value,key;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>value;
    obj.insert(value);
  }
  cout<<"Enter the node to be deleted: ";
  cin>>key;
  obj.root=obj.deleteNode(obj.root,key);
  obj.inorder(obj.root);
}