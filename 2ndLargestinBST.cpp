#include <iostream>
using namespace std;

class Node
{
    public:
        Node();
        Node(int d) : data(d){
            left = NULL;
            right = NULL;
        };
    
        int data;
        Node *left;
        Node *right;
    
};


class Tree {
    private:
        Node *root;
    public:
        Tree() {root = NULL;};
    
        Node* getRoot() {return root;}
    
        void print(){
            if(root == NULL) return;
            printHelper(root, 0);

        };
    
        void printHelper(Node *n, int space){
            if(n == NULL) return;
            
            printHelper(n->right, space+1);

            for(int i=0; i < space; i++){
                cout << "    ";
            }
            cout << n->data << endl;

            printHelper(n->left, space+1);

            return;
        };
    
        
        void insert(int data){
            Node *n = new Node(data);
            
            if(root == NULL){
                root = n;
            }
            else{
                Node *curr = root;
                while(curr != NULL){
                    if(data < curr->data){
                        if(curr->left == NULL){
                            curr->left = n;
                            break;
                        }
                        else{
                            curr = curr->left;
                        }
                    }
                    else{
                        if(curr->right == NULL){
                            curr->right = n;
                            break;
                        }
                        else{
                            curr = curr->right;
                        }
                    }
                }
            }
        };
};


int secondLargest(Node *root){
    if(root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    
    Node *parent = NULL;
    Node *curr = root;
    
    while(curr->right != NULL){
        parent = curr;
        curr = curr->right;
    }
    
    if(curr->left != NULL){
        if(curr->left->right == NULL){
            return curr->left->data;
        }
        else{
            curr = curr->left;
            while(curr->right != NULL){
                curr = curr->right;
            }
            return curr->data;
        }
    }
    else{
        return parent->data;
    }
}





int main()
{
    Tree t;
    t.insert(50);
    t.insert(10);
    t.insert(100);
    t.insert(80);
    t.insert(40);
    t.insert(30);
    t.insert(90);
    t.insert(75);
    t.insert(15);
    
    cout << "Tree:" << endl;
    t.print();
    cout << "\n\n" << secondLargest(t.getRoot());
    
    
    
    return 0;
}
