#include <iostream>
using namespace std;

struct BSTNode{
    int data;
    BSTNode* left;
    BSTNode* right;
    BSTNode* parent;
};

void Inorder(BSTNode* root)
{
    if(root)
    {
        Inorder(root->left);
        cout<<"Key = "<<root->data<<", ";
        if(!(root->parent))
            cout<<"Parent = NULL"<<", ";
        else
            cout<<"Parent = "<<root->parent->data<<", ";
        if(!(root->left))
            cout<<"Left = NULL"<<", ";
        else
            cout<<"Left = "<<root->left->data<<", ";
        if(!(root->right))
            cout<<"Right = NULL"<<endl;
        else
            cout<<"Right = "<<root->right->data<<endl;

    Inorder(root->right);
    }

}

BSTNode* getNodeData(int data)
{
    BSTNode* root=new(BSTNode);
    root->data=data;
    root->left=root->right=NULL;
    root->parent=NULL;
    return root;
}

BSTNode* InsertData(BSTNode* root,int data)
{

    if(root==NULL)
        return getNodeData(data);
    else if(data<=root->data)
    {
        BSTNode* lchild;
        lchild=InsertData(root->left,data);
        root->left=lchild;
        lchild->parent=root;
    }
    else
    {
        BSTNode* rchild;
        rchild=InsertData(root->right,data);
        root->right=rchild;
        rchild->parent=root;
    }
    return root;
}
bool BSTSearch(BSTNode* root,int key)
{
    if(!root) return false;
    if(root->data==key) return true;
    else if(key<=root->data) BSTSearch(root->left,key);
    else BSTSearch(root->right,key);
}
int main() {
    BSTNode* root=NULL;
    root = InsertData(root, 20);
    InsertData(root, 30);
    InsertData(root, 40);
    InsertData(root, 50);
    InsertData(root, 60);
    InsertData(root, 70);
    InsertData(root, 80);

    Inorder(root);
    cout<<BSTSearch(root,30);
    return 0;
}