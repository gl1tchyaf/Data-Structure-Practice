#include<stdio.h>
#include<stdlib.h>

struct BstNode {
	int data;
	struct BstNode* left;
	struct BstNode* right;
};

struct BstNode* NewNode(int data){
    struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
}

struct BstNode* Insert(struct BstNode* root , int data){
    if(root == NULL){
        root = NewNode(data);
    }else if(data <= root->data){
        root->left = Insert(root->left,data);
    }else{
        root->right = Insert(root->right,data);
    }
    return root;
}

void PreOrder(struct BstNode* root){
    if(root == NULL){
        return;
    }
    printf("%d ",root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(struct BstNode* root){
    if(root == NULL){
        return;
    }
    InOrder(root->left);
    printf("%d ",root->data);
    InOrder(root->right);
}

void PostOrder(struct BstNode* root){
    if(root == NULL){
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ",root->data);
}

int main(){

    struct BstNode* root = NULL;
    root = Insert(root,5);
    root = Insert(root,9);
    root = Insert(root,4);
    root = Insert(root,1);
    root = Insert(root,3);
    root = Insert(root,2);
    root = Insert(root,0);
    root = Insert(root,8);
    root = Insert(root,7);
    root = Insert(root,10);

    int op;
    printf("1.Pre order\n2.In order\n3.Post order");
    printf("\nChoose operation: ");
    scanf("%d",&op);

    if(op == 1){
        PreOrder(root);
    }
    else if(op == 2){
        InOrder(root);
    }else if(op == 3){
        PostOrder(root);
    }else{
        printf("Invalid input");
    }

    return 0;

}
