#include <bits/stdc++.h>
template <typename T>
class BST {
private:  
  class node {
  public:
    T data;
    node *parent;
    node *left;
    node *right;
  };
  node *root;
public:
  BST();
  node* insert(T &data);  
  node* search(T &data);
};
int
main() {
  
}
