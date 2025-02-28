// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    
};

struct node * newnode(int a){
    struct node * nnode=(struct node *)malloc(sizeof(struct node));
    nnode->data=a;
    nnode->next=NULL;
    return nnode;
}




void addele(struct node**top,int a){
    struct node * snode=newnode(a);
    if(*top==NULL){
        *top=snode;
    }
    else{
        snode->next=*top;
        *top=snode;
    }
}

void display(struct node * top){
    if(top==NULL){
        printf("\nstack empty");
        
    }
    else{
        struct node * i=top;
        while(i!=NULL){
            printf("%d ->",i->data);
            i=i->next;
        }
    }
}

void del(struct node ** top){
    if(*top==NULL){
        printf("stack empty \n");
    }
    else{
        struct node *i=*top;
        *top=(*top)->next;
        free(i);

    }
    }
int main() {
    struct node * top=NULL;
    printf("Stack using array\n");
    
    
    while(1){
    printf("\n\n1->add ; 2->display : 3-> pop : ");
    int d;
    scanf("%d",&d);
   
        switch (d){
        case 1:
            printf("\nadding items\n");
            int b;
            printf("Enter the element you want to add : ");
            scanf("%d",&b);
            addele(&top,b);
            break;
            
        case 2:
            printf("\ndisplaying elements : ");
            display(top);
            break;
            
        case 3:
            printf("\npoping elements : ");
            del(&top);
            break;
        default:
            printf("\ninvalid input \n");
            break;
    }

    }
    return 0;
}
