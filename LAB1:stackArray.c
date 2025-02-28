
#include <stdio.h>
#define max 10

int stack[max];
int top =-1;


void addele(int a){
    if(top==max-1){
        printf("stack is full\n ");
    }
    else{
        top++;
        stack[top]=a;
        
    }
}

void display(){
    if(top==-1){
        printf("\nstack empty");
        
    }
    else{
        int i=top;
        while(i!=-1){
            printf("%d ->",stack[i]);
            i--;
        }
    }
}

void del(){
    if(top==-1){
        printf("stack empty \n");
    }
    else{
        top--;

    }
    }
int main() {
   
    printf("Stack using array\n");
     while(1){
    printf("\n1->add ; 2->display : 3-> delete : ");
    int d;
    scanf("%d",&d);
    printf("%d\n",d);
   
        switch (d){
        case 1:
            printf("adding items\n");
            int b;
            printf("Enter the element you want to add : \n");
            scanf("%d",&b);
            addele(b);
            break;
        case 2:
            printf("displaying elements : ");
            display();
            break;
        case 3:
            printf("deleting elements : ");
            del();
            break;
        default:
            printf("invalid input \n");
            break;
    }

    }
    return 0;
}
