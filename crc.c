#include <stdio.h>

struct node {
    int value;
    struct node * next;
};

typedef struct node mynode;

mynode *head = NULL;


void display(void)
{
    mynode *temp;
    
    if (head != NULL)
    {
        printf("\n%d ",head->value);
        temp = head->next;
        while (temp != head)
        {
            printf("%d ",temp->value);
            temp = temp->next;
        }
   }
}
void insert(int element)
{
    mynode *temp,*temp1;
    int asc = 0,i;
    
    temp = (mynode *)malloc(sizeof(struct node));
    temp->next = NULL;
    temp->value = element;
    
    if (head == NULL)
    {
        head = temp;
        temp->next = temp;
    }
    else if (head->next == head)
    {
        temp->next = head->next;
        head->next = temp;
    }
    else
    {
        temp1 = head;
        for (i=0;i<3;i++)
        {
            asc += (temp1->next->value > temp1->value)?1:-1;
            temp1 = temp1->next;
        }
        
        if (asc > 0)
        {
            temp1 = head;
            while (temp1 != NULL)
            {
            if (element > temp1->value && element < temp1->next->value || ((element > temp1->value||element < temp1->next->value) && temp1->next->value < temp1->value))
                {
                    temp->next = temp1->next;
                    temp1->next = temp;
                    break;
                }
                temp1 = temp1->next;
            }
        }
        else
        {
            temp1 = head;
            while (temp1 != NULL)
            {
                if (((element < temp1->value) && (element > temp1->next->value)) || (((element < temp1->value)||(element > temp1->next->value)) && temp1->next->value > temp1->value))
                {
                    temp->next = temp1->next;
                    temp1->next = temp;
                    break;
                }
                temp1 = temp1->next;
            }   
        }
            
    }
    
    display();
        
}

void del(int element)
{
    mynode *temp,*d;
    if (head == NULL)
    {
        return;
    }
    else if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;
        while(temp->value != element && temp->next != head)
            temp = temp->next;
      
        if (temp->value == element)
        {
            temp->value = temp->next->value;
            d = temp->next;
            temp->next = temp->next->next;
            free(d);
            d = NULL;
        }
        else
            printf("\n Desired element not in list \n");
    }
    display();
}

int main()
{
    int n,a;
    printf("\nEnter your choices.. 1 for insert, 2 for delete, 3 for exit \n");
    while (1)
    {
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                scanf("%d",&a);
                insert(a);
                break;
            case 2:
                scanf("%d",&a);
                del(a);
                break;
            case 3:
                exit(1);
         }
    }
    
}
