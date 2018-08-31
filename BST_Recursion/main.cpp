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

bool BSTSearch(BSTNode* node,int key)
{
    if(!node) return false;
    if(node->data==key) return true;
    else if(key<=node->data) BSTSearch(node->left,key);
    else BSTSearch(node->right,key);
}
BSTNode* MinBST(BSTNode* root)
{
    if(root->left==NULL) return root;
    else
        return MinBST(root->left);
}
BSTNode* NodeDelete(BSTNode* root,int key)
{
    if(root==NULL)return root;
    else if(root->data>key)
        root->left=NodeDelete(root->left,key);
    else if(root->data<key)
        root->right=NodeDelete(root->right,key);
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            delete(root);
            root=NULL;
        }
        else if(root->left==NULL)
        {
            BSTNode* t=root;
            root=root->right;
            root->parent=t->parent;
            delete(t);
        }
        else if(root->right==NULL)
        {
            BSTNode* t=root;
            root=root->left;
            root->parent=t->parent;
            delete(t);
        }
        else
        {
            BSTNode* t =MinBST(root->right);
            root->data=t->data;
            root->right=NodeDelete(root->right,t->data);
        }
    }
    return root;
}
int main() {
    BSTNode* root=NULL;
    root = InsertData(root, 12);
    InsertData(root, 5);
    InsertData(root, 3);
    InsertData(root, 4);
    InsertData(root, 7);
    InsertData(root, 9);
    InsertData(root, 15);
    InsertData(root, 13);
    InsertData(root, 17);
    InsertData(root, 19);
    Inorder(root);
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"Smallest Element is = "<<MinBST(root)->data<<endl;
    cout<<"Smallest Element in Right Subtree is = "<<MinBST(root->right)->data<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    NodeDelete(root,3);
    Inorder(root);
    cout<<"-----------------------------------------------------------"<<endl;
    NodeDelete(root,19);
    Inorder(root);
    cout<<"-----------------------------------------------------------"<<endl;
    NodeDelete(root,12);
    Inorder(root);
    return 0;
}