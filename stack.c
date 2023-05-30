#include<stdio.h>
#include<stdlib.h>
#define max 100
typedef struct
{
    int top;
    int ele[max];
}stack;
void initstack(stack*s)
{
   s->top=-1;
}
int isFull(stack *s)
{
  return (s->top==max-1);
}
void push(stack *s, int e)
{
    s->top++;
    s->ele[s->top]=e;

}
int isEmpty(stack *s)
{

  return  (s->top==-1);

}
int pop(stack *s)

{
    int e=s->ele[s->top];

      s->top--;

     return e;

}
int peek(stack *s)

{
    int e=s->ele[s->top];

     return e;

}

void display(stack *s,FILE * optr)
{
    FILE * fp4 = fopen("stack1.txt","w");
    if((s->top )==-1)
    {
         printf("Stack is empty. \n");
    }
    else
    {
            printf("Stack elements are\n");
            fprintf(optr,"stack elements are : ");
            for(int i=s->top;i>=0;i--)
            {
                printf("%d\n",s->ele[i]);
                fprintf(fp4,"%d ",s->ele[i]);
                 fprintf(optr,"%d ",s->ele[i]);
            }
    }
}
int main()

{

    stack s;
    FILE * fp1;FILE* fp2; FILE * fp3;FILE * optr ;
    int p,t,q,i,num,cnt1=0,cnt2=0;
    fp1=fopen("generate.txt","w+");
    optr = fopen("opertaion.txt","w");
    printf("Enter the value of a  and  b  \n");

    scanf("%d %d",&p,&q);

    printf("Enter the value of t  ");

    scanf("%d",&t);
    fprintf(optr,"Generated elements: ");

    for(i=0;i<t;i++)

    {

    num = (rand() % (p - q +1))+ p;

    printf("%d\n ",num);

    fprintf(fp1,"%d ",num);
    fprintf(optr,"%d ",num);

    }
    fprintf(optr,"\n");
    fclose(fp1);
        fp1=fopen("generate.txt","r");

    fp2=fopen("push.txt","w");
    fp3 = fopen("pop.txt","w");


    initstack(&s);

    int e,ch;

    while(1)

    {

      printf("\n1.push\n 2.pop\n 3.STACK \n4.exit\n");

        printf("enter the choice\n");

        scanf("%d",&ch);



        switch(ch)

        {

              case 1:
                      if(isFull(&s))

                      printf("stack is overflow\n");

                      else

                      {

                        printf("enter the element:");

                        fscanf(fp1,"%d",&e);
                       printf("%d",e);

                        fprintf(fp2,"%d  ",e);
                         fprintf(optr,"pushed element is : %d \n",e);
                          cnt1++;
                        push(&s,e);

                      }

                      break;

              case 2: if(isEmpty(&s))

                      printf("stack is underflow\n");

                      else

                      {

                         e=pop(&s);
                          cnt2++;
                         fprintf(fp3," popped element is : %d \n",e);
                         fprintf(optr,"popped element is : %d \n",e);

                      }

                      break;

              case 3:  display(&s,optr);
                           fprintf(optr," \n number of pushed elements are :%d ",cnt1);
                                fprintf(optr," \n number of popped elements are :%d ",cnt2);
                                  fprintf(optr," \n number of popped elements are :%d ",cnt1-cnt2);
                      break;

              case 4: exit(0);

        }

    }
}
