#include<stdio.h>
#include<stdlib.h>
struct node{
int n;
struct node *next;
};
typedef struct node N;
N *head;


int cnt=0;
void insert(int item,int p)
{
    if(p<=cnt+1&&p>=1)
    {
    N *temp;
    temp=(N*)malloc(sizeof(N));
    temp->n=item;
    if(head==NULL){
       // head=temp;
       // tail=temp;
       // head->next=tail;
       head=temp;
       head->next=head;
       cnt++;
        return;
        }
    if(p==1)
    {
       N *tail;
       tail=head;
       while(tail->next!=head)
            tail=tail->next;
       temp->next=head;
       head=temp;
       tail->next=head;
       cnt++;
       return;
    }
    if(p==cnt+1)
    {
        N *c;
        c=head;
        while(c->next!=head)
            c=c->next;
        c->next=temp;
        temp->next=head;
        cnt++;
        return;
    }
    N *c;
    c=head;
    p=p-2;
    while(p--)
        c=c->next;
    temp->next=c->next;
    c->next=temp;
    cnt++;
    return;
    }
    else
    {
        printf("Enter valid position");
        return;
    }


}

void del(int p)
{
    if(p>cnt||p<1)
    printf("Enter valid position");
    else{

        if(p==1)
        {
            N *tail;
            tail=head;
            while(tail->next!=head)
                tail=tail->next;
            head=head->next;
            tail->next=head;
            cnt--;
            return;

        }
        if(p==cnt)
        {
            N *c;
            c=head;
            while(c->next->next!=head)
                c=c->next;
            c->next=head;
            cnt--;
            return;
        }
        p=p-2;
        N *c;
        c=head;
        while(p--)
            c=c->next;
        c->next=c->next->next;
        cnt--;
        return;

}
}
void display()
{
    N *c;
    c=head;
    if(cnt>0)
    {

    while(c->next!=head)
       {
           printf("%d ",c->n);
           c=c->next;
       }
    printf("%d",c->n);
    return;
    }
    else{
        printf("No element to display");
    }
}
int menu()
{
    int ch;
    printf("1.Insert\n");
    printf("2.Delete\n");
    printf("3.Display\n");
    printf("0.Exit\n\n");
    printf("Enter the choice");
    scanf("%d",&ch);
    return ch;
}
int main()
{
    head=NULL;
    int ch,p,item;
    while(1)
    {
        system("pause");
        system("cls");
        ch=menu();
        if(ch==0)
            break;
        switch(ch)
        {
        case 1:
            printf("Enter the item and position");
            scanf("%d %d",&item,&p);
            insert(item,p);
            break;
        case 2:
            printf("Enter the Position");
            scanf("%d",&p);
            del(p);
            break;
        case 3:
            display();
            break;
        default:
            break;
        }
    }



    return 0;
}





