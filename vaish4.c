#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff,exp;
    struct node *next;
};
struct node *create(struct node *head, int coe, int ex)
{
    struct node *c;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->coeff=coe;
    new->exp=ex;
    new->next=NULL;
            if(head == NULL)
            {
                head=new;
               
            }
            else
            {
                c=head;
                while(c->next != NULL)
                    c=c->next;
                c->next=new;       
            }
return head;
}
void display(struct node *head)
{
    struct node *c;
    if(head == NULL)
        printf("list is empty");
    else
    {
        for(c=head;c!=NULL;c=c->next)
                printf("%dx%d+ ",c->coeff,c->exp);
    }
}       
   
struct node *addpoly(struct node *p1, struct node *p2, struct node *head3)
{
    int x;
    while(p1 !=NULL && p2 !=NULL)
    {
        if(p1->exp == p2->exp)
        {
            x=p1->coeff+p2->coeff;
            if(x!=0)
            {
                head3=create(head3,x,p1->exp);
                p1=p1->next;
                p2=p2->next;
            }
        }
        else if(p1->exp>p2->exp)
        {
            head3=create(head3,p1->coeff,p1->exp);
            p1=p1->next;
        }
        else
        {
            head3=create(head3,p2->coeff,p2->exp);
            p2=p2->next;               
        }
    }
    while(p1 != NULL)
    {
        head3=create(head3,p1->coeff,p1->exp);
        p1=p1->next;
    }
    while(p2 != NULL)
    {
        head3=create(head3,p2->coeff,p2->exp);
        p2=p2->next;
    }   
    return head3;
}
void main()
{
    struct node *head1=NULL,*head2=NULL,*head3=NULL;
    int coe,ex;
    printf("\nenter first polynomial");
    while(1)
    {
        printf("\n Enter -999 for coeff and -999 for exponent to exit\n");
        scanf("%d%d",&coe,&ex);
        if(coe != -999 || ex != -999)
            head1=create(head1,coe,ex);
        else
            break;
    }
    printf("\n Display first polynomial\n");
    display(head1);

    printf("\nenter second polynomial");
    while(1)
    {
        printf("\n Enter -999 for coeff and -999 for exponent to exit\n");
        scanf("%d%d",&coe,&ex);
        if(coe != -999 || ex != -999)
            head2=create(head2,coe,ex);
        else
            break;
    }
    printf("\n Display second polynomial\n");
    display(head2);
    head3=addpoly(head1,head2,head3);
   
    printf("\n Display resultant polynomial\n");
    display(head3);   
}
