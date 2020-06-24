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
