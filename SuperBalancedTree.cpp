/* Check if a tree is super balanced. A tree is super balanced if the difference in
   depth of any two nodes is no greater than one.
*/

#include <iostream>
#include <limits>
using namespace std;

int max_height = 0;
int min_height = numeric_limits<int>::max();

  class BinaryTreeNode
{
public:
    int value_;
    BinaryTreeNode* left_;
    BinaryTreeNode* right_;

    BinaryTreeNode(int value) :
        value_(value),
        left_(nullptr),
        right_(nullptr)
    {
    }

    ~BinaryTreeNode()
    {
        delete left_;
        delete right_;
    }

    BinaryTreeNode * insertLeft(int value)
    {
        this->left_ = new BinaryTreeNode(value);
        return this->left_;
    }

    BinaryTreeNode * insertRight(int value)
    {
        this->right_ = new BinaryTreeNode(value);
        return this->right_;
    }
      
    void print(BinaryTreeNode *root, int spaces){
        if(root == NULL) return;
        
        for(int i=0; i < spaces; i++){
            cout << " ";
        }
        
        
        print(root->left_, spaces+2);
        cout << root->value_ << endl;
        print(root->right_, spaces+2);
    }
};


void isSuperBalancedHelper(BinaryTreeNode *n, int height){
    if(n == NULL) return;
    
    if(n->left_ == NULL && n->right_ == NULL){
        if(height > max_height){
            max_height = height;
        }
        if(height < min_height){
            min_height = height;
        }
    }
    else{
        isSuperBalancedHelper(n->left_, height+1);
        isSuperBalancedHelper(n->right_, height+1);
    } 
}


bool isSuperBalanced(BinaryTreeNode *root){
    isSuperBalancedHelper(root, 0);
    if(max_height - min_height > 1)
        return false;
    return true;
}



int main() {
    
    BinaryTreeNode n1(1);
    BinaryTreeNode *rightof = n1.insertRight(5);
    n1.insertLeft(7);
    rightof->insertLeft(2);
    rightof = rightof->insertRight(9);
    rightof->insertRight(3);
    
    n1.print(&n1, 0);
    
    cout << "\n\n" << (isSuperBalanced(&n1)? "true" : "false") << endl;
    cout << "min:" << min_height << " max:" << max_height << endl;
    
    return 0;
}
