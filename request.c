//Sophia Hostetler
//U27264415
//All functions related to operations on the list of requests

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include"request.h"

struct request *append_to_list(struct request *list){

	struct request *new_request=malloc(sizeof(struct request));
	struct request *p;
	int age;

//if statement if to ensure allocation is done correctly

if(new_request==NULL)
	{
		printf("Malloc failed.");
		return list;
	}
	
//prompt user to enter last name, first name, and email

printf("Enter the following information for the camper: \n");
	printf("Last name: ");
        read_line(new_request->last,NAME_LEN);
	printf("First name: ");
        read_line(new_request->first,NAME_LEN);
	printf("Email: ");
	read_line(new_request->email, EMAIL_LEN);

//for loop iterating through the linked list

for(p=list;p!=NULL;p=p->next)
	{

//if statement to see if struct request is already in list

if(!strcmp(p->first, new_request->first)&&!strcmp(p->last, new_request->last)&&!strcmp(p->email, new_request->email))
		{
			printf("This request is already in the list, please use update code.");
			return list;
		}	
	}
	
//prompt user to enter student's age and make status pending due to being a new request

printf("Enter student age: ");
		scanf("%d", &age);
	new_request->age=age;
	strcpy(new_request->status,"pending");

//adding node to end of list

new_request->next=NULL;
	
//if statement to see if list is empty

if(list==NULL)
		return new_request;

//adding node to end if list is not empty

p=list;
	while(p->next !=NULL)
		p=p->next;
	p->next=new_request;
	return list;
}

void update(struct request *list)
{
	char first[NAME_LEN+1];
	char last[NAME_LEN+1];
	char email[EMAIL_LEN+1];
	char status[STATUS_LEN+1];
	struct request *p=list;

//if statement if to ensure list is not empty

	 if(list==NULL)
        {
                printf("List is empty.");
                return;
        }

//prompt user to enter last name, first name, email, and status update



        printf("Enter the following information for the camper: \n");
        printf("Last name: ");
        read_line(last,NAME_LEN);
        printf("First name: ");
        read_line(first,NAME_LEN);
        printf("Email: ");
        read_line(email, EMAIL_LEN);
	printf("Status update: ");
	read_line(status,STATUS_LEN);

//while loop iterating through nodes  and updating the status if information matches

while(p)
	{
		if(!strcmp(p->first,first)&&!strcmp(p->last,last)&&!strcmp(p->email,email))
		{
			(strcpy(p->status,status));
			return;
		}

	p=p->next;
	}

//If request is not found

printf("Request not found.");

}


void print_list(struct request *list){

	struct request *p;

//for loop iterating through list and printing the complete information of all requests

for(p=list;p!=NULL;p=p->next)
		printf("%-15s %15s %15s %15s\n",p->last,p->first,p->email,p->status);
}
void clear_list(struct request *list)
{
	struct request *p;

//while loop deallocating the memory and freeing the nodes

while(list!=NULL)
	{	
		p=list;
		list=list->next;
		if(p!=NULL)
			free(p);
	}
}


