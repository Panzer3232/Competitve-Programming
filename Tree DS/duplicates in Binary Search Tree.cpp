/*
12(3)
       /        \
     10(2)      20(1)
    /    \       
 9(1)   11(1)   

Count of a key is shown in bracket
This approach has following advantages over above simple approach.

1) Height of tree is small irrespective of number of duplicates. Note that most of the BST operations (search, insert and delete) have time complexity as O(h) where h is height of BST. 
So if we are able to keep the height small,we get advantage of less number of key comparisons.

2) Search, Insert and Delete become easier to do. We can use same insert, search and delete algorithms with small modifications (see below code).

3) This approach is suited for self-balancing BSTs (AVL Tree, Red-Black Tree, etc) also. These trees involve rotations, and a rotation may violate BST property of simple 
solution as a same key can be in either left side or right side after rotation.

Below is implementation of normal Binary Search Tree with count with every key. This code basically is taken from code for insert and delete in BST. The changes made for 
handling duplicates are highlighted, rest of the code is same.

*/

#include<bits/stdc++.h> 

using namespace std;

struct node {
      int key;
      int count;
      struct node *left,*right;
  };
  struct node* newNode(int item){
      struct node* temp=(struct node* )malloc(sizeof(struct node));
      temp->key = item; 
      temp->left = temp->right = NULL; 
      temp->count = 1; 
      return temp;
  }
  struct node* insert(struct node* node,int key){
      if(node==NULL)
      return newNode(key);
      if(key== node->key){
          (node->count)++;
          return node;
      }
      if(node->key<key){
          node->right=insert(node->right,key);
      }
      else
      node->left=insert(node->left,key);
      return node ;
  }
  void Inorder(struct node* root){
      if(root != NULL){
           Inorder(root->left); 
            cout << root->key << "("
                 << root->count << ") "; 
           Inorder(root->right); 
      }
  }
  
  struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
    while (current->left != NULL) 
        current = current->left; 
  
    return current; 
} 

  struct node* deleteNode(struct node* root,int key){
      if(root==NULL)
      return root;
      if(root->key>key)
      root->left=deleteNode(root->left,key);
      
      else if(root->key<key)
       root->right=deleteNode(root->right,key);
      else{
          if(root->count>1){
          (root->count)--;
          return root;
          }
          
          if(root->left==NULL){
              struct node* temp=root->right;
              free(root);
              return temp;
          }
         else if(root->right==NULL){
              struct node* temp=root->left;
              free(root);
              return temp;
          }
           struct node* temp = minValueNode(root->right); 
           root->key = temp->key; 
        root->right = deleteNode(root->right, 
                                  temp->key); 
      }
      return root;
  }
int main()
{
 struct node *root=0;
 root = insert(root, 12); 
    root = insert(root, 10); 
    root = insert(root, 20); 
    root = insert(root, 9); 
    root = insert(root, 11); 
    root = insert(root, 10); 
    root = insert(root, 12); 
    root = insert(root, 12); 
     cout << "Inorder traversal of the given tree " 
         << endl; 
    Inorder(root); 
    
    cout << "\nDelete 20\n"; 
    root = deleteNode(root, 20); 
    cout << "Inorder traversal of the modified tree \n"; 
    Inorder(root); 
  
    cout << "\nDelete 12\n" ; 
    root = deleteNode(root, 12); 
    cout << "Inorder traversal of the modified tree \n"; 
    Inorder(root); 
  
    cout << "\nDelete 9\n"; 
    root = deleteNode(root, 9); 
    cout << "Inorder traversal of the modified tree \n"; 
    Inorder(root); 
  
  
    return 0;
}
