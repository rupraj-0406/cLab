#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define scan(type, var) scanf("%"#type, &var)

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

node* insert(node* root,int k){
    if(!root){
        node* tmp=(node*)malloc(sizeof(node));
        tmp->data=k;
        tmp->left=NULL;
        tmp->right=NULL;
        return tmp;
    }
    if(root->data > k){
        root->left=insert(root->left,k);
    }
    if(root->data<k)
        root->right=insert(root->right,k);
    return root;
}

void preorder(node* root){
    if(!root)return;
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(node* root){
    if(!root)return;
    
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
}
void inorder(node* root){
    if(!root)return;
    
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
    
}

int main(){
    node* root=(node *)malloc(sizeof(node));
    root=NULL;
    int n,k;
    scan(d,n);

    for(int i=0;i<n;i++){
        scan(d,k);
        root=insert(root,k);
    }
    printf("\n------------------\ninorder:");
    inorder(root);
    printf("\n------------------\npreorder:");
    preorder(root);
    printf("\n------------------\npostorder:");
    postorder(root);
    printf("\n------------------\n");
    return 0;
}