#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;

};

Node* create_node(int data)
{
    Node * node = new Node();
    node->data = data;
    node->next = NULL;
    return node;
}

void push(Node** head,int data)
{
    Node * new_node = create_node(data);
    if(*head == NULL)
      *head = new_node;

      else
      new_node->next = *head;
      *head = new_node;

}

Node* add_sum(Node* first ,Node* second)
{
  Node* res = NULL;
  Node* temp,*prev = NULL;
  int sum =0;
  int carry =0;

  while((first != NULL)|| (second != NULL)){ 
   sum = carry + (first ? first->data : 0)+(second?second->data :0);
   carry = (sum>=10) ? 1:0;
   sum = sum %10;

   temp = create_node(sum);
   if(res == NULL)
       res = temp;

       else
       {
           prev->next = temp;
       }


       prev = temp;

    


    first =  first->next;
    second = second->next;
  }

  if(carry >0)
  temp->next = create_node(carry);

  return res;
}
 

void print(Node* root)
{
    Node* temp = root;
    while(temp!= NULL)
    {
        cout <<temp->data;
        temp= temp->next;
    }
    cout<<endl;
}


int main()
{
  Node * result = NULL;
  Node * first = NULL;
  Node * second = NULL;

  push(&first,3);
  push(&first,4);
  push(&first,2);

  print(first);
   push(&second,4);
  push(&second,6);
  push(&second,5);
  print(second);

  result = add_sum(first,second);
print(result);

 // Node *result = add_sum (root1,root2);
 // void print(result);
    return 0;
}