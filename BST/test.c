#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
    
}node;

node* insert(node* root, int val){
    if(!root){
        node* temp=(node *)malloc(sizeof(node));
        temp->left=NULL;
        temp->right=NULL;
        temp->data=val;
        return temp;
    }
    if(root->data > val)
        root->left=insert(root->left,val);
    else
        root->right=insert(root->right,val);
    
    return root;
}
void inorder(node* root){
    if(!root)return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void kth_element(node* node,int* arr[]){

}
int main(){
    int n,k;
    scanf("%d",&n);
    scanf("%d",&k);
    int arr[]=(int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    node* root=NULL;
    for(int i=0;i<6;i++){
        root=insert(root,arr[i]);
    }
    inorder(root);
    kth_element(root,arr);
    printf("\n");
    return 0;
}