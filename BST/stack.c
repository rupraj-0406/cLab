#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define scan(type, var) scanf("%"#type, &var)

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

typedef struct stack{
    node** arr;
    int top;
    int capacity;
}stack;

stack* createStack(int cap){
    stack* st=(stack *)malloc(sizeof(stack));
    st->capacity=cap;
    st->top=-1;
    st->arr=(node**)malloc(st->capacity*sizeof(int));
    return st;
}
int top(stack* st){
    return st->top;
}

bool isEmpty(stack* st){
    return st->top==-1;
}
void push(stack* st,int x){
    if(st->top==st->capacity){
        int cap=st->capacity;
        cap*=2;
        st->capacity=cap;
    }
    st->arr[++st->top]=x;
}
stack* pop(stack* st){
    if(st->top==st->capacity)return NULL;
    return st->arr[st->top--];
}

node* insert(node* root,int x){
    if(!root){
        node* tmp=(node*)malloc(sizeof(node));
        tmp->data=x;
        tmp->left=NULL;
        tmp->right=NULL;
        return tmp;
    }
    if(root->data < x){
        root->left=insert(root->left,x);
    }
    if(root->data > x) root->right=insert(root->right,x);

    return root;
}
void inorder(node* root, stack* st){
    if(!root)return;
    inorder(root->left,st);
    push(st,root->data);
    inorder(root->right,st);
}
int main(){

    stack* st;
    st=createStack(100);
    node* root;
    root=NULL;
    int n;
    scan(d,n);
    for(int i=0;i<n;i++){
        int k;
        scan(d,k);
        root=insert(root,k);
    }
    inorder(root,st);
    int *arr=(int *)malloc(sizeof(int));
    int i=0;
    while(!isEmpty(st)){
        int tmp=pop(st);
        arr[i++]=tmp;
    }
    // free(st);
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    free(st);
    free(arr);
    return 0;
}