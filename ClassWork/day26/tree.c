#include <stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *l;
    struct node *r;
}NODE;
NODE *createNode(int);
NODE *insertNode(NODE *,int);
void inorderTrav(NODE *);
void preOrder(NODE *);
void postOrder(NODE *);
NODE *createNode(int val)
{
    NODE *nn =(NODE *)malloc(sizeof(NODE));
    nn->data=val;
    nn->l=NULL;
    nn->r=NULL;
    return nn;
}
NODE *insertNode(NODE *root,int val)
{
    if(root==NULL)
    {
        //if tree is empty
        //return nn
        return createNode(val);
    }
    if(root->data < val)
    {
        //right sub tree
        root->r=insertNode(root->r,val);
    }
    else if(root->data > val)
    {
        //left sub tree
        root->l=insertNode(root->l,val);
    }
    else
    {
        printf("\n%d duplicate value found,Hence ingore",val);
    }
    return root;
}
void inorderTrav(NODE *root)
{
    if(root==NULL)
    {
        return;
    }
    inorderTrav(root->l);
    printf("%d ",root->data);
    inorderTrav(root->r);
    
}
void preOrder(NODE *root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d ",root->data);
    preOrder(root->l);
    preOrder(root->r);
    
}
void postOrder(NODE *root)
{
    if(root==NULL)
    {
        return;
    }
    postOrder(root->l);
    postOrder(root->r);
    printf("%d ",root->data);
    
}
int main(){
    NODE *root=NULL;
    root=insertNode(root,5);
    insertNode(root,10);
    insertNode(root,3);
    insertNode(root,4);
    insertNode(root,8);
    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,13);
    printf("\nIn Order Traversal\n");
    inorderTrav(root);
    printf("\n\n");
    preOrder(root);
    printf("\n\n");
    postOrder(root);
    printf("\n\n");
    return 0;
}
