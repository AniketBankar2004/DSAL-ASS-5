#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
  int data;
  node*right;
  node*left;
public :
  node(int num)
  {

    data=num;
    right=NULL;
    left=NULL;
  }
};
class BST
{
  node* root=NULL;
public:
  void insert(int value,node *&n1)
  {

    if(n1==NULL)
    {
      n1=new node(value);
      root=n1;
    }
    else
    {
      if(n1->data < value)
      {
        insert(value,n1->right);
      }
      else if(n1->data >= value)
      {
        insert(value,n1->left);
      }
    }
  }
node * findmin(node* x)
{
  while(x->left!=NULL)
    {
      x = x->left;
    }
  return x;
}

void display(node* n) {
if (n != NULL) {
    display(n->left);
    cout << n->data << " ";
    display(n->right);
}
}

void remove(node*& n, int x) {
    if (n == NULL) {
        return;
    }

    if (x > n->data) {
        remove(n->right, x);
    } else if (x < n->data) {
        remove(n->left, x);
    } else {
        if (n->right == NULL && n->left == NULL) {
            n = NULL; 
        } else if (n->right == NULL) {
            
            node* temp = n->left;
            n = temp;
        } else if (n->left == NULL) {
            node* temp = n->right;
            n = temp;
        } else {
            
            node* temp = findmin(n->right);
            n->data = temp->data;
            remove(n->right, temp->data);
        }
    }
}
  bool search(node* n, int x)
  {
      bool a = false;

      while (n != NULL && !a)
      {
          if (n->data == x)
          {
              a = true;
          }
          else if (x > n->data)
          {
              n = n->right;
          }
          else if (x < n->data)
          {
              n = n->left;
          }
      }

      return a;
  }
void displayParentsWithChildren(node* n) {
    if (n != NULL) {
        cout << "Parent: " << n->data;

        if (n->left != NULL || n->right != NULL) {
            cout << " : Children: ";
            if (n->left != NULL) {
                cout << n->left->data << " ";
            }
            if (n->right != NULL) {
                cout << n->right->data;
            }
        }

        cout << endl;

        displayParentsWithChildren(n->left);
        displayParentsWithChildren(n->right);
    }
}
void displayLevelOrder() {
        if (root == nullptr) {
            return;
        }

        queue<node*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; ++i) {
                node* current = q.front();
                q.pop();

                cout << current->data << " ";

                if (current->left != nullptr) {
                    q.push(current->left);
                }
                if (current->right != nullptr) {
                    q.push(current->right);
                }
            }

            cout << endl; 
        }
    }
};
void displayLeaf(node*n)
{
  if(n!=NULL)
  {
    if(n->right==NULL and n->left==NULL)
    {
      cout<<n->data<<" ";
    }
    displayLeaf(n->right);
    displayLeaf(n->left);
  }
 
}

void leveldisplay(node* n)
{
  if(n==NULL)
  {
    return;
  }
  queue<node*>q;
  q.push(n);
  while(!q.empty())
    {
      node * current = q.front();
      q.pop();
      cout<< current->data<<" ";
      if(current->left!=NULL)
      {
        q.push(current->left);
      }
      if(current->right!=NULL)
      {
        q.push(current->right);
      }
    }
  
}
int main()
{
  BST b;
  node* n1=NULL;
  b.insert(5,n1);
  b.insert(5,n1);
  b.insert(6,n1);
  b.insert(3,n1);
  b.insert(9,n1);
  b.insert(7,n1);
  b.insert(8,n1);
  // b.display(n1);
  b.remove(n1,6);
  cout<<endl;
  // cout<<"after removing 6"<<endl;
  // b.display(n1);
  // cout<<endl;
  // cout<<"searching for 6"<<endl;
  // cout<<b.search(n1,6)<<endl;
  // cout<<"searching for 7"<<endl;
  // cout<<b.search(n1,7)<<endl;
  // b.displayParentsWithChildren(n1);
  // cout<<endl;
  // displayLeaf(n1);
  leveldisplay(n1);
  
  }
