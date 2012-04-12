#include <iostream>
#include <stdio.h>
using namespace std;

struct node
{
    int data;
    bool color;
    node *left, *right, *par;
};

node *nil;
node *root;

void Tree_Ins_Fix(node *z)
{
    node *y;
    while(z!=root && z->par->color==1)
    {
        if(z->par->par->left == z->par)
        {
            cout<<1<<endl;
            y = z->par->par->right;
            if(y->color == 1)   // case 1: uncle is red
            {
                y->par->color = 1;
                y->color = 0;
                z->par->color = 0;
                z = y->par;
            }
            else
            {
                if(z == z->par->right)
                {
                    z = z->par;
                    z->right->par = z->par;
                    if(z->par->right == z)
                        z->par->right = z->right;
                    else
                        z->par->left = z->right;
                    z->right->left->par = z;
                    node *c = z->right;
                    z->right = c->left;
                    c->left = z;
                    z->par = c;
                }
                z->par->color = 0;
                z->par->par->color = 1;
                node *a = z->par->par;
                node *b = z->par;
                node *p = a->par;
                node *u = b->right;
                if(p!=NULL)
                {
                if(p->left == a)
                    p->left = b;
                else
                    p->right = b;
                }
                b->par = p;
                b->right = a;
                a->par = b;
                u->par = a;
                a->left = u;
                if(root==a)
                    root=b;
            }
        }
        else
        {
            cout<<2<<endl;
                        y = z->par->par->left;
            if(y->color == 1)   // case 1: uncle is red
            {
                y->par->color = 1;
                y->color = 0;
                z->par->color = 0;
                z = y->par;
            }
            else
            {
                if(z == z->par->left)
                {
                    z = z->par;
                    z->left->par = z->par;
                    if(z->par->left == z)
                        z->par->left = z->left;
                    else
                        z->par->right = z->left;
                    z->left->right->par = z;
                    node *c = z->left;
                    z->left = c->right;
                    c->right = z;
                    z->par = c;
                }
                z->par->color = 0;
                z->par->par->color = 1;
                node *a = z->par->par;
                node *b = z->par;
                node *p = a->par;
                node *u = b->left;
                if(p!=NULL)
                {
                if(p->right == a)
                    p->right = b;
                else
                    p->left = b;
                }
                b->par = p;
                b->left = a;
                a->par = b;
                u->par = a;
                a->right = u;
                if(root==a)
                    root=b;
            }
        }
    }
    root->color = 0;
}

void Tree_Insert(int v)
{
    node *temp = new node();
    temp->data = v;
    temp->left = nil;
    temp->right = nil;
    temp->par = NULL;
    node *p=NULL, *x=root;
    while(x!=nil)
    {
        p = x;
        if(p->data > temp->data)
            x = x->left;
        else
            x = x->right;
    }
    if(p==NULL)
    {
        root = temp;
        root->color = 0;
        cout<<v<<" root Insetred"<<endl;
        return;
    }
    else
    {
        if(temp->data < p->data)
            p->left = temp;
        else    
            p->right = temp;
        temp->par = p;
    }
    temp->color = 1;
    Tree_Ins_Fix(temp);
    cout<<v<<" Insetred"<<endl;
}

void print(node *root)
{
    if(root!=nil)
    {
        print(root->left);
        printf("(%d,%d) ",root->data,root->color);
        print(root->right);
    }
}

int main()
{
    int choice;
    nil = new node();
    nil->left = NULL;
    nil->right = NULL;
    nil->data = -1;
    nil->color = 0;
    root = nil;
    do
    {
        cin>>choice;
        switch(choice)
        {
            case 1:int val;
                   cin>>val;
                   Tree_Insert(val);
                   break;
            case 2:break;
            case 3:print(root);break;
        }
    }while(choice!=4);
}
