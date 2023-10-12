#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node * next;
};

void traversal(struct Node *ptr)
{
	while(ptr!=NULL)
	{
		printf("\n%d",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}

struct Node * insertatfirst(struct Node * head,int data){
struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
ptr->data=data;
ptr->next=head;
return ptr;
}
struct Node * insertatindex(struct Node * head,int index,int data){
	struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
	struct Node * p = head;
	int i = 0;
	while(i!=index-1)
	{
		p = p->next;
		i++;
	}
	ptr->data=data;
	ptr->next=p->next;
	p->next=ptr;
	return head;
}
struct Node * insertatend(struct Node * head,int data){
	struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
	ptr->data=data;
	struct Node * p = head;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=ptr;
	ptr->next=NULL;
	return head;
}
struct Node * insertafternode(struct Node * head,struct Node *prevnode,int data){
	struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
	ptr->data=data;
	ptr->next=prevnode->next;
	prevnode->next=ptr;
	return head;
}
struct Node * deletefirst(struct Node * head){
	struct Node * ptr = head;
	head = head -> next;
	free(ptr);
	return head;
}
struct Node * deleteatindex(struct Node * head,int index){
	struct Node *p = head;
	struct Node *q = head->next;
	int i;
	for(i=0;i<=index-1;i++)
	{
		p=p->next;
		q=q->next;
	}
	p->next=q->next;
	free(q);
	return head;
	
}
struct Node * deletelast(struct Node * head){
	struct Node *p = head;
	struct Node *q = head->next;
	while(q->next!=NULL)
	{
		p=p->next;
		q=q->next;
	}
	p->next=NULL;
	free(q);
	return head;
}
struct Node * deletevalue(struct Node * head,int data)
{
    struct Node *p = head;
	struct Node *q = head->next;
	while(q->data!=data && q->next!=NULL )
	{
		p=p->next;
		q=q->next;
	 } 
	 printf("%d %d",q->data,data);
	 if(q->data == data)
	 {
	 	p->next=q->next;
	 	free(q);
	 }
	 return head;
	
	
}
int main(){
	int ko,oper,ind;
	char iord;
	struct Node * head;
    struct Node * second;
	struct Node * third;
	struct Node * forth;
	struct Node * fiveth;
	struct Node * sixth;
	head = (struct Node *)malloc(sizeof(struct Node));
	second = (struct Node *)malloc(sizeof(struct Node));
	third = (struct Node *)malloc(sizeof(struct Node));
	forth = (struct Node *)malloc(sizeof(struct Node));
	fiveth = (struct Node *)malloc(sizeof(struct Node));
	sixth = (struct Node *)malloc(sizeof(struct Node));
	head->data=2;
	head->next=second;
    second->data=8;
	second->next=third;
	third->data=890;
	third->next=forth;
	forth->data=8200;
	forth->next=fiveth;
	fiveth->data=8999;
	fiveth->next=sixth;
	sixth->data=890;
	sixth->next=NULL;
	yi:
	printf("Linked List Traversal\n");
	traversal(head);
	printf("Press I For Insertion And Press D For Deletion\n");
	iord=getch();
	if((iord=='I')||(iord=='i'))
	{
	
	printf("Press 1 For Insert At First Position \n Press 2 for Insert At Particular index \n Press 3 for insert at the End \n Press 4 For insert after Any Node\n");
	scanf("%d",&oper);
	if(oper==1)
	  {
	   printf("Type Data");
	   scanf("%d",&ko);
	   head=insertatfirst(head,ko);
	   traversal(head);
       }
       else if(oper==2)
       {
    	printf("Type Data");
    	scanf("%d",&ko);
    	printf("Type index Where it insert");
    	scanf("%d",&ind);
    	head=insertatindex(head,ind,ko);
    	traversal(head);
		}
		else if (oper == 3)
		{
			printf("Type Data");
			scanf("%d",&ko);
			head=insertatend(head,ko);
			traversal(head);
		}
		else if(oper == 4)
		{
			printf("Enter Previous Node");
			scanf("%d",&ko);
			
			head=insertafternode(head,head,ko);
			traversal(head);
		}
	}
	else if((iord=='D')||(iord=='d'))
	{
		printf("Press 1 for Delete First Data \n Press 2 for Delete Particular Index \n Press 3 for Delete Last Element \n Press 4 For Delete Any Particular Value");
		scanf("%d",&oper);
		if(oper==1)
		{
			head = deletefirst(head);
			traversal(head);	
		}
		 else if(oper==2)
		{
			printf("\t Type Index Which You Want To delete");
			scanf("%d",&ko);
			head= deleteatindex(head,ko);
			traversal(head);	
		}
		else if(oper==3)
		{
			head=deletelast(head);
			traversal(head);	
		}
		else if(oper==4)
		{
			printf("\t Type Which Data You Want Delete");
			scanf("%d",&ko);
			head = deletevalue(head,ko);
			traversal(head);
		}
	}
	printf("If you Want to Do any Operation Again, Then Press O\n Press Any Key For Exit Program");
	iord=getch();
	if((iord=='o')||(iord=='O'))
	{
		goto yi;
	}
	printf("Thank You :]");
	return 0;	
}
