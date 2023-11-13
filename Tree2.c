
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root=NULL;

void insert(){
    struct node *temp,*parent,*curr;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&temp->data);
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL){
        root=temp;
    }
    else{
        curr=root;
        while(curr){
            parent=curr;
            if(temp->data>curr->data){
                curr=curr->right;
            }
            else{
                curr=curr->left;
            }
        }
        if(temp->data>parent->data){
            parent->right=temp;
        }
        else{
            parent->left=temp;
        }
    }
}

void largest(){
    struct node *curr;
    curr=root;
    while(curr->right!=NULL){
        curr=curr->right;
    }
    printf("Largest element is %d\n",curr->data);
}

void smallest(){
    struct node *curr;
    curr=root;
    while(curr->left!=NULL){
        curr=curr->left;
    }
    printf("Smallest element is %d\n",curr->data);
}

int height(struct node *temp){
    int lh,rh;
    if(temp==NULL){
        return 0;
    }
    else{
        lh=height(temp->left);
        rh=height(temp->right);
        if(lh>rh){
            return lh+1;
        }
        else{
            return rh+1;
        }
    }
}

void node_height(){
    int key,h;
    struct node *curr;
    curr=root;
    printf("Enter the node data: ");
    scanf("%d",&key);
    while(curr!=NULL){
        if(curr->data==key){
            h=height(curr);
            printf("Height of the node is %d\n",h);
            return;
        }
        else if(curr->data<key){
            curr=curr->right;
        }
        else{
            curr=curr->left;
        }
    }
    printf("Node not found\n");
}

int count_leaf(struct node *temp){
    if(temp==NULL){
        return 0;
    }
    else if(temp->left==NULL && temp->right==NULL){
        return 1;
    }
    else{
        return count_leaf(temp->left)+count_leaf(temp->right);
    }
}

void leaf_count(){
    int count;
    count=count_leaf(root);
    printf("Number of leaf nodes are %d\n",count);
}

int main(){
    int ch;
    while(1){
        printf("1. Insert\n");
        printf("2. Largest element\n");
        printf("3. Smallest element\n");
        printf("4. Height of a node\n");
        printf("5. Count number of leaf nodes\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: insert();
                    break;
            case 2: largest();
                    break;
            case 3: smallest();
                    break;
            case 4: node_height();
                    break;
            case 5: leaf_count();
                    break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
