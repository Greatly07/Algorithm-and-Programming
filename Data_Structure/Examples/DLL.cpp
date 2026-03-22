#include <stdio.h>
#include <stdlib.h> //malloc free

struct Data
{
	int val;
	struct Data *next, *prev;
}*head, *tail, *curr, *temp; 
//head = first node
//tail = last node
//curr = processed node
//temp = before processed node

struct Data *newNode(int val)
{
	curr = (struct Data *) malloc(sizeof(struct Data));
	curr->val = val;
	curr->next = curr->prev = NULL;
	return curr;
}

void pushTail(int val)
{
	curr = newNode(val);
	
	if(head == NULL) // first node
	{
		head = tail = curr;
	}
	else // not the first node
	{
		tail->next = curr;	
		curr->prev = tail;
		tail = curr;
	}
}

void displayAll()
{
	curr = head;
	while(curr)
	{
		printf("%d", curr->val);
		if(curr->next) printf(" ");
		curr = curr->next;
	}
}

void pushHead(int val)
{
	curr = newNode(val);
	
	if(head == NULL) // first node
	{
		head = tail = curr;
	}
	else // not the first node
	{
		curr->next = head;
		head->prev = curr;	
		head = curr;
	}
}

void popHead()
{
	curr = head;
	if( head == tail ) //last node
	{
		head = tail = NULL;
	}
	else
	{
		head = head->next;
		head->prev = NULL;		
	}
	free (curr);
}

void popAll()
{
	while (head)
	{
		popHead();
	}
}

void pushSorted(int val)
{
	curr = newNode(val);
	
	if(head == NULL) // first node 
	{
		head = tail = curr;
	}
	else // not the first node
	{
		if(val < head->val) // smaller than head->val
		{
			curr->next = head;
			head->prev = curr;
			head = curr;
		}
		else if (val >= tail->val) //greater or equal than tail->val
		{
			tail->next = curr;
			curr->prev = tail;
			tail = curr;	
		}
		else //1 2 3 [4] 5 6 7
		{	 //    t  c
			temp = head;
			while (temp)
			{
				if(temp->next)
				{
					if(temp->next->val > val) // 5 > [4]
						break;
				}
				temp = temp->next;
			}
			curr->next = temp->next;
			temp->next->prev = curr;
				
			temp->next = curr;
			curr->prev = temp;
		}
	}
}

void popTail()
{
	curr = tail;
	
	if(head == tail) //last node 
	{
		head = tail = NULL;
	}
	else  //not the last node
	{
		tail = tail->prev;
		tail->next = NULL;
	}
	free(curr);
}

int popSearch(int key)
{
	curr = head;
	while(curr)
	{
		if(curr->val == key) break;
		curr = curr->next;
	}
	
	if (curr == head && curr == tail) //last node
	{
		head = tail = NULL;
	}
	else // not the last node
	{
		if (curr == head)
		{
			head = head->next;
			head->prev = NULL;
		}
		else if(curr == tail)
		{
			tail = tail->prev;
			tail->next = NULL;			
		}
		else
		{
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
		}
		
	}
	free(curr);
}

int main ()
{
	//printf("%d", head->val); 
	//Runtime Error because acces memory 0 which has no val attribute available
	
	
	pushTail(3);
	pushTail(5);
	// 3 5
	
	pushHead(2);
	pushTail(6);
	//[2] 3 5 [6] 
	
	pushSorted(1);
	pushSorted(7);
	pushSorted(4);
	//[1] 2 3 [4] 5 6 [7]
	
	displayAll();
	puts("");
	
	popHead();
	popTail();
	// 2 3 4 5 6 
	
	popSearch(2);
	popSearch(6);
	popSearch(4);
	// 3 5 
	
	displayAll();
	
	popAll();
	return 0;
}


