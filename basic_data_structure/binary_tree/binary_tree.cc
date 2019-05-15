#include <iostream>
#include <queue>
using namespace std;
template<typename T>
class BTNode{
    public:
        T val;
        BTNode<T> *right;
        BTNode<T> *left;
        BTNode():val(T()),right(nullptr),left(nullptr)
        {

        };
        BTNode(T v,BTNode<T> *pRight = nullptr,BTNode<T> *pLeft = nullptr):val(v),right(pRight),left(pLeft)
        {

        };
};
template<typename T>
class BinaryTree{
    public:
        BTNode<T> *root;

        BinaryTree():root(nullptr){};
        ~BinaryTree(){};
        //Construct binary tree from preOrder and MidOrder
        void ConstructTree(BTNode<T> * &root,T *PreOrder,T *MidOrder,int Len);
        //Construct binary search tree from array
        void ConstructBST(BTNode<T> * &root,T *arr);
        void PreTraversing(BTNode<T> * &root);
        void InTraversing(BTNode<T> * &root) ;
        void PostTraversing(BTNode<T> * &root);
        void LevelTraversing(BTNode<T> * &root);
        int GetTreeDepth(BTNode<T> * &root);
};
template<typename T>
void BinaryTree<T>::ConstructTree(BTNode<T> * &root,T *PreOrder,T *MidOrder,int Len){
    T rootVal = PreOrder[0];
    root = new BTNode<T>(rootVal);
    if(Len == 1 && PreOrder[0] == MidOrder[0])
        return;
    //find root position in MidOrder
    T *rootInMid = MidOrder;
    int leftLen = 0;
    while(rootInMid < MidOrder + Len && *rootInMid != rootVal){
        ++rootInMid;
        ++leftLen;
    }
    if(*rootInMid != rootVal)
        return ;
    if(leftLen > 0)
        ConstructTree(root->left,PreOrder + 1,MidOrder,leftLen);
    if(Len - leftLen - 1 > 0)
        ConstructTree(root->right,PreOrder + leftLen + 1,rootInMid + 1,Len - leftLen - 1);
}
template<typename T>
void BinaryTree<T>::PreTraversing(BTNode<T> * &root){
    if(root){
        cout<<root->val<<" ";
        PreTraversing(root->left);
        PreTraversing(root->right);
    }
}
template<typename T>
void BinaryTree<T>::InTraversing(BTNode<T> * &root){
    if(root){
        InTraversing(root->left);
        cout<<" "<<root->val<<" ";
        InTraversing(root->right);
    }
}
template<typename T>
void BinaryTree<T>::PostTraversing(BTNode<T> * &root){
    if(root){
        PostTraversing(root->left);
        PostTraversing(root->right);
        cout<<" "<<root->val<<" ";
    }
}
template<typename T>
void BinaryTree<T>::LevelTraversing(BTNode<T> * &root){
    if(!root)
        return;
    queue< BTNode<T>* > nodeQ;
    nodeQ.push(root);
    int parentSz = 1,childSz = 0;
    do
    {
        BTNode<T> *cur = nodeQ.front();
        cout<<" "<<cur->val<<" ";
        nodeQ.pop();
        if(cur->left){
            nodeQ.push(cur->left);
            ++ childSz;
        }
        if(cur->right){
            nodeQ.push(cur->right);
            ++ childSz;
        }
        --parentSz;
        if(parentSz == 0){
            parentSz = childSz;
            childSz = 0;
            cout<<endl;
        }
    }while(!nodeQ.empty());
}
template<typename T>
int BinaryTree<T>::GetTreeDepth(BTNode<T> * &root){
    if(!root)
        return 0;
    int leftDepth = GetTreeDepth(root->left);
    int rightDepth = GetTreeDepth(root->right);
    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}
int main()
{
    BinaryTree<int> tree;
    int preOrder[] = {1,2,4,6,7,8,3,5};
    int midOrder[] = {4,7,6,8,2,1,3,5};
    tree.ConstructTree(tree.root,preOrder,midOrder,8);
    tree.PreTraversing(tree.root);
    cout<<endl;
    tree.InTraversing(tree.root);
    cout<<endl;
    tree.PostTraversing(tree.root);     ;
    cout<<endl;
    tree.LevelTraversing(tree.root);
    cout<<endl;
    cout<<"Depth :"<<tree.GetTreeDepth(tree.root)<<endl;
    return 0;
}
