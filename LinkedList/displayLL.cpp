#include<iostream> //input/output operations 
#include<stdlib.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first=NULL;


void create(int A[], int n){
   int i;
   struct Node *t, *last;
   first = (struct Node *)malloc(sizeof(struct Node));
   first->data = A[0];
   first->next = NULL;
   last = first;

   for(int i=1; i<n; i++){
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=A[i];
    t->next=NULL;
    last->next=t;
    last=t;
   }
}

void display(struct Node *p){
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}

void Rdisplay(struct Node *p){
    if(p!=NULL){
        Rdisplay(p->next);
        printf("%d", p->data);

    }
}

int main(){
   
   int A[] = {3, 5, 7, 10, 15};

   create(A, 5);
   cout<<endl;
   display(first);

  return 0;
}