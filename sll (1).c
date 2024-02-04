#include <stdio.h>
#include <stdlib.h>

//DEFINING A NODE
struct node
{
    int data;
    struct node *next;
};
struct node *newNode,*temp,*head,*temp1,*tail;


//FUNCTION TO INSERT BEFORE A GIVEN ELEMENT
void insert_after()
{
    int i,target,item;
    struct node *newNode,*temp;
    //ALLOCATING MEMORY FOR A NODE
    newNode=(struct node*)malloc(sizeof(struct node*));

    if(newNode==NULL)
    {
        printf("\nmemory overflow");
    }
    else
    {
        printf("enter element value:\n");
        scanf("%d",&item);
        newNode->data=item;
        printf("enter the element after which you want to insert\n");
        scanf("%d",&target);
        temp=head;
      while(temp->data != target)
      {
          temp=temp->next;
      }
      newNode->next=temp->next;
      temp->next=newNode;
      printf("node inserted");
    }


}

void insert_before()
{
   int i,target,item;
    struct node *newNode,*temp;
    newNode=(struct node*)malloc(sizeof(struct node*));
    if(newNode==NULL)
    {
        printf("\nmemory overflow");
    }
    else
    {
        printf("enter element value:\n");
        scanf("%d",&item);
        newNode->data=item;//ASSIGN ENTERED ITEM TO NODE
        printf("enter the element before which you want to insert\n");
        scanf("%d",&target);
        temp=head;
      while(temp->next->data != target)
      {
          temp=temp->next;//WHILE THE DESIRED VALUE ISNT REACHED, KEEP INCREMENTING TEMP
      }
      newNode->next=temp->next;
      temp->next=newNode;
      printf("node inserted");
    }


}
void addNode(int data) {
    //Create a new node
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    //Checks if the list is empty
    if(head == NULL) {
        //If list is empty, both head and tail will point to new node
        head = newNode;
        tail = newNode;
    }
    else {
        //newNode will be added after tail such that tail's next will point to newNode
        tail->next = newNode;
        //newNode will become new tail of the list
        tail = newNode;
    }
}
void deleteNode() {
    printf("enter element to be deleted:");
    int key;
    scanf("%d",&key);
    // Handle the case where the head node contains the key
    if (head != NULL && (head)->data == key) {
        struct node* temp = head;
        head = (head)->next;
        free(temp);
        return;
    }

    // Search for the key in the rest of the list
    struct node* current = head;
    struct node* prev = NULL;

    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    // If the key was not found in the list
    if (current == NULL) {
        printf("Element %d not found in the list\n", key);
        return;
    }

    // Remove the node containing the key
    prev->next = current->next;
    free(current);
}


void traverse()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}
void reverse()
{
    struct node *prev,*curr,*next;
    prev=NULL;
    curr=head;
    next=NULL;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
}
int sort()
{
    struct node *temp1=head,*temp2;
    while(temp1!=NULL)
    {
        temp2=head;
        while(temp2->next!=NULL)
        {
            if(temp2->data>temp2->next->data)
            {
                int tmp=temp2->data;
                temp2->data=temp2->next->data;
                temp2->next->data=tmp;
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    return head;

}
void deleteAlternateNodes() {
    if (head == NULL) {
        return;
    }

    struct node* current = head;
    while (current != NULL && current->next != NULL) {
        struct node* temp = current->next;
        current->next = temp->next;
        free(temp);
        current = current->next;
    }
}
void display()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}



void insertSorted() {
    int data;
    printf("enter element to be inserted:");
    scanf("%d",&data);
    //printf("data taken");
    // Special case: if the list is empty or the data is smaller than the head node
    if (head == NULL || data < head->data) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Traverse the list to find the correct position to insert the element
    struct node* current = head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }
//printf("data taken");
    // Insert the new node after the current node
    newNode->next = current->next;
    current->next = newNode;

    printf("data taken");
}
int main()
{
struct node* head = NULL;
 int choice, data;
 while (1) {
 printf("\n1. Create a list\n");
 printf("2. insert before an element\n");
 printf("3. insert after an element\n");
 printf("4. delete\n");
 printf("5. traverse\n");
 printf("6. reverse\n");
 printf("7. sort\n");
 printf("8. delete alt node\n");
 printf("9. insert in sorted list\n");
 printf("10. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter the element to insert: ");
 scanf("%d", &data);
 addNode(data);
 break;
 case 2:
insert_before();
 break;
 case 3:
insert_after();
 break;
  case 4:
deleteNode();
 break;
  case 5:
traverse();
 break;
  case 6:
reverse();
 break;
  case 7:
sort();
 break;
  case 8:
deleteAlternateNodes();
 break;
  case 9:
insertSorted();
 break;
 case 10:
 printf("Exiting the program.\n");
 return 0;
 default:
 printf("Invalid choice! Please try again.\n");
 }
 }
 return 0;
}