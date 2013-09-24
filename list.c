#include <stdio.h>
#include "list.h"

int whileTrue()
{
	while(getchar()!='\n')
		continue;
	return 0;
}

int inputInt(int * n)
{
	int temp;
	while((temp=scanf("%d",n))!=1)
	{
		puts("please input a integer");
		while(getchar()!='\n')
			continue;
	}
	return temp;	
}

int inputFloat(float * n)
{
	int temp;
	while((temp=scanf("%f",n))!=1)
	{
		puts("please input a integer");
		while(getchar()!='\n')
			continue;
	}
	return temp;
}

int initList(List list)
{
	puts("input your id:");
	inputInt(&list->id);
	whileTrue();
	puts("input your age:");
	inputInt(&list->age);
	whileTrue();
	puts("input your score:");
	inputFloat(&list->score);
	whileTrue();
	list->next=NULL;
	return 0;
}

int selectMenu()
{
	puts("select what you want to do:");
	puts("1.add item");
	puts("2.delete item");
	puts("3.display all the node");
	puts("4.select a node to display");
	puts("5.exit");
	puts("your choice:");
	return 0;
}

List select(List head)
{
	int i,n,sn,num,temp;
	List ilist,slist,hlist;
	hlist=head;
	selectMenu();
	int no[5]={1,2,3,4,5};
	
	while(1)
	{
		while(1)
		{
			inputInt(&n);
			if(no[0]==n||no[1]==n||no[2]==n||no[3]==n||no[4]==n)
				break;
			puts("please input a intege number 1-5:");
		}
		while(getchar()!='\n')
			continue;
		if(1==n)
		{
			puts("where do you want to insert:");
			scanf("%d",&num);
			whileTrue();
			puts("please set your node your want to add");
			ilist=(List)malloc(sizeof(STU));
			initList(ilist);
			printf("\n");
			if(position(head,num)==NULL)
				puts("Node is beyond the end.");
			else
				head=addItem(head,num,ilist);
		}
		else if(2==n)
		{
			puts("where do you want to delete:");
			scanf("%d",&num);
			whileTrue();
			if(num>0)
			{
				if(head->next==NULL)
				{
					puts("there is only one Node");
					
				}
				else if(position(head,num)==NULL)
				{
					puts("Node is beyond the end.");
				}
				else
				{
					head=delItem(head,num);	
				}
			}
			else
				puts("please input a number which is more than 0.");
		}
		else if(3==n)
		{
			display(head);
		}
		else if(4==n)
		{
			puts("which node do you want to display:");
			scanf("%d",&sn);
			whileTrue();
			slist=position(head,sn);
			printf("your id is %5d,your age is %5d,your score is %5.2f\n",slist->id,slist->age,slist->score);
		}
		else if(5==n)
		{
			return head;
		}
		selectMenu();
	}
	return head;
}

List addItem(List head,int n,List ilist)
{
	List temp,list;
	if(0==n)
	{
		temp=head;
		head=ilist;
		head->next=temp;
	}
	else if(list->next!=NULL)
	{
		list=position(head,n);
		temp=list->next;
		list->next=ilist;
		ilist->next=temp;
	}
	else
	{
		list=position(head,n);
		list->next=ilist;
		ilist->next=NULL;
	}
	return head;
}

List delItem(List head,int n)
{
	List temp,list;
	if(1==n)
	{
		list=head;
		head=head->next;
		free(list);
		
	}
	else if(position(head,n)==NULL)
	{
		list=position(head,n-1);
		temp=list->next;
		list->next=NULL;
		free(temp);
	}
	else
	{
		list=position(head,n-1);
		temp=list->next;
		list->next=list->next->next;
		free(temp);
	}
	return head;
}

List position(List list,int n)
{
	int i=1;
	List temp;
	if(1==n)
		return list;
		
	temp=list;

	while(i<n && temp->next!=NULL)
	{
		temp=temp->next;
		i++;
	}
	if(i<n)
		return NULL;
	
	return temp;
}

int destroy(List head)
{
	List temp=head;
	do
	{
		head=temp;
		temp=temp->next;
		free(head);
	}while(temp!=NULL);
	return 0;	
}

int display(List head)
{	
	while(head!=NULL)
	{
		printf("your id is %3d\t,your age is %3d\t,your score is %5.2f\n",head->id,head->age,head->score);
		head=head->next;
	}
	return 0;
}
