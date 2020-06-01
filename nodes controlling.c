#include <stdio.h>
#include <stdlib.h>
#define add_node push
#define del_top pop
//define node structure
typedef struct node
{
   int value;           // node htae hmr pr mae data
   struct node *next;   // head node tway ko connect lote pho linking
}NODE_TYPE;
//first ko lote chin tak process ko delcare lote
void init_list(NODE_TYPE *head);
void add_node(NODE_TYPE *head, int data);
int del_top(NODE_TYPE *head);
void show_list(NODE_TYPE *head);

//first time header ko create lote
void init_list(NODE_TYPE *head)
{
    head->next=NULL;       //null ko pya p tot head ko sa
}
//aku ka sa p tot node athit taku ko create
void add_node(NODE_TYPE *head, int data)
{
    NODE_TYPE *new_nodes;                   //declear node
    new_nodes = malloc(sizeof(NODE_TYPE));  //memory allocating
    new_nodes->value=data;                  //value htae ko data htae
    new_nodes->next=head->next;             //point to 2nd node
    head->next=new_nodes;                   //
    printf("push %3d\n",new_nodes->value);
}
int del_top(NODE_TYPE *head)
{
    NODE_TYPE *top;         //pop stack ka lo apaul sone data ko nyunn
    int data;               //temp file
    if(head->next== NULL)         //check top is avaviable or not
    {
        printf("List is empty.");
        return -1;
    }
    else
    {
        top=head->next;
        data=top->value;
        head->next=top->next;
        free(top);
        return data;
    }
}
void show_list(NODE_TYPE *head)
{
    printf("\nmylist [");
    head=head ->next;
    while(head!=NULL)
    {
        printf("%3d",head->value);
        head=head->next;
    }
    printf("]\n");
}

NODE_TYPE mylist;

int main(void)
{
    init_list(&mylist);
    push(&mylist, 10);
    push(&mylist, 20);
    push(&mylist, 30);
    push(&mylist, 40);
    push(&mylist, 50);
    push(&mylist, 60);
    show_list(&mylist);

    printf("pop %3d\n",pop(&mylist));
    printf("pop %3d\n",pop(&mylist));
    printf("pop %3d\n",pop(&mylist));
    printf("19TE486 Min Khant Sithu");
return 0;

}
