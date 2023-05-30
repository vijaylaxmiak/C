//Program to perform basic push,pop operations

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100
struct stack
{
    int data[SIZE];
    int top;
};
void push(struct stack *sptr, int num);
void pop(struct stack *sptr);
int main()

{
    struct stack * sptr;
    FILE *fp,*temp,*temp1;
    struct stack s;
    sptr=&s;
    sptr->top=-1;
    int num,ch;
    fp=fopen("solve.txt","r");
    while(1)
    {
        printf("1.push\n2.pop\n3.Exit\n\n");
        printf("Enter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the data\n");
            scanf("%d",&num);
            temp=fopen("stacks.txt","w");
            fprintf(temp,"%d\n",num);
            push(sptr,num);
            break;
            case 2:pop(sptr);
            temp1=fopen("pop.txt","w");
            fprintf(temp1,"%d\n",num);
            break;
            case 3:exit(0);
            break;

        }
    }
    return 0;
}
void push(struct stack *sptr, int num)
{
    if(sptr->top==SIZE-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        sptr->top++;
        sptr->data[sptr->top]=num;
    }
}
void pop(struct stack *sptr)
{
    int num;
    if(sptr->top==-1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        num=sptr->data[sptr->top];
        sptr->top--;
    }
    printf("%d\n",num);
}
