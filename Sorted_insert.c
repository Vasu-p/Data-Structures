
#include<stdio.h>
#include<stdlib.h>
struct node{
int n;
struct node *next;
};
typedef struct node N;
N *head;


int cnt=0;
void insert(int item)
{
    N *temp;
    temp=(N*)malloc(sizeof(N));
    temp->n=item;
    temp->next=NULL;
    if(head==NULL)
        {head=temp;cnt++;return;}
    if(head->next==NULL||temp->n<head->n)
    {
        if(temp->n<head->n)
        {
            temp->next=head;
            head=temp;
            cnt++;
            return;
        }
        else
        {
            head->next=temp;
            cnt++;
            return;
        }
    }
    else
    {
        N *c;
        c=head;
        while(c->next!=NULL)
        {

            if(c->n<=temp->n&&temp->n<c->next->n)
            {
                temp->next=c->next;
                c->next=temp;
                cnt++;
                return;
            }
            else
                c=c->next;
        }
        c->next=temp;
        cnt++;
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
            head=head->next;
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

    while(c!=NULL)
       {
           printf("%d ",c->n);
           c=c->next;
       }

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
            printf("Enter the item");
            scanf("%d",&item);
            insert(item);
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





