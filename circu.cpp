#include <stdio.h>

struct node
{
    int data;
    node *next;
};

void print(node *p)
{
    if(p!=NULL)
    {
        printf("%d ",p->data);
        node * t = p->next;
        while(t!=p)
        {
            printf("%d ",t->data);
            t = t->next;
        }
    }
}

node * Insert(node *p, int nd)
{
    node *temp = new node;  
    temp->data = nd;
    temp->next = NULL;
    
    if(p==NULL)
    {
        p = temp;
        temp->next = temp;
    }
    else if(p->next == p)
    {
        temp->next = p->next;
        p->next = temp;
    }
    else
    {
        int asc=0, i;
        for(i=0;i<3;i++)
        {
            asc += (p->next->data - p->data)>0?1:-1;
            p = p->next;
        }
        
        if(asc>0)
        {
            while(p!=NULL)
            {
                if((nd>p->data && nd<p->next->data) || ((nd<p->next->data || nd>p->data) && p->next->data<p->data))
                {
                    temp->next = p->next;
                    p->next = temp;
                    break;
                }
                p = p->next;
            }
        }
        else
        {
            //printf("Here..\n");
            while(p!=NULL)
            {
                if((nd<p->data && nd>p->next->data) || ((nd>p->next->data || nd<p->data) && p->next->data>p->data))
                {
                    temp->next = p->next;
                    p->next = temp;
                    break;
                }
                p = p->next;
            }
        }
    }
    return p;
}

int main()
{
    int c=1;
    node *p = NULL;
    do
    {
        scanf("%d",&c);
        switch(c)
        {
            case 1: int t; scanf("%d",&t); p = Insert(p,t); break;
            case 2: print(p);printf("\n");break;
        }
    }while(c!=3);
}
