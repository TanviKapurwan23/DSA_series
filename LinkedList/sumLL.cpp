// int Add(struct Node *p){
//     int sum = 0;
//     while(p){
//         sum = sum + p->data;
//         p=p->next;
//     }
//     return sum;
// }


// using recursion

// Add(struct Node *p){
//     if(p==0){
//         return 0;
//     } else{
//         return Add(p->next) + p->data;
//     }
// }   O(N)


#include<iostream>
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

int count(struct Node *p){
    int l=0;
    while(p){
        l++;
        p=p->next;
    } return l;
}


int main(){
  int A[] = {3,5,7,10,15};
  create(A,5);
  printf("Length is %d",count(first));

  return 0;
}