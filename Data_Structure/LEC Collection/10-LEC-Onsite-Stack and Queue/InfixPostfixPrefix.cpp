#include <stdio.h>
#include <stdlib.h> //system malloc free
#include <string.h> //strlen strcpy
#include <ctype.h> //isdigit //ispunct
#include <math.h> //pow

// example : 

/*
infix	: 4+6*(5-2)/3
result = 10

postfix : 4652-*3/+
prefix	: +4/*6-523

infix	: 5*7+(8/2-3)^9
result = 36

postfix : 57*82/3-9^+
prefix	: +*57^-/8239
*/

struct Data
{
	char k; // operator
	float f; // operand
	struct Data *next;
	struct Data *prev;
}*head, *tail, *curr; // pointer struct Data as global variable. Global variable' default value is 0

void menu(); // display menu
void pushChar (char k); // push char to stack (operator)
void pushFloat (float f); // push float to stack (operand)

int numofnodes(); // return num of nodes in stack
void displayChar(); // display all nodes'char in stack (for simulation)
void displayFloat(); // display all nodes'float in stack (for simulation)

void pop(); // pop top node in stack
char peekChar(); // retrieve top nodes' character in stack
char peekFloat(); // retrieve top nodes' operand in stack
void popAll(); // pop all nodes in stack
void insertInfix(char infix[]); // insert arr of char as infix
void displayNotation(char not[]); // display infix/postfix/prefix notation
void displayResult(float val); // display infix/postfix/prefix result
int getPriority(char op); // get operator precedence level

void infixtoPostfix(char infix[], char postfix[]); // conversion from infix to postfix
float evaluatePostfix(char postfix[]); // evaluate postfix to result

void infixtoPrefix(char infix[], char prefix[]); // conversion from infix to prefix
float evaluatePrefix(char prefix[]); // evaluate prefix to result

void main()
{
	char input, infix[100]={""}, postfix[100]={""}, prefix[100]={""};
	float val=-1;
		
	do
	{
		system("cls");

		printf("\n--- Infix ---\n");
		displayNotation(infix);
		printf("--- Postfix ---\n");
		displayNotation(postfix);
		printf("--- Prefix ---\n");
		displayNotation(prefix);
		printf("--- Result ---\n");
		displayResult(val);
		
		menu();
		scanf("%c", &input); getchar();
		
		switch(input)
		{
			case '1' : { insertInfix(infix); }break;
			case '2' : { infixtoPostfix(infix, postfix); infixtoPrefix(infix, prefix); } break;
			case '3' : { val = evaluatePostfix(postfix); } break;
			case '4' : { val = evaluatePrefix(prefix); } break;			
			default	 : break;
		}

	}while (input != '0');
	popAll();
}


float evaluatePrefix(char prefix[])
{
	/*
	Evaluate Prefix

	Step : 
	Scan the string from right to left, for each character in the string:
	1. If it is an operand, push it into stack.
	2. If it is an operator, pop twice (store in variable A and B respectively) and push(A operator B).
	Pay attention here! It is (A operator B), not (B operator A).
	3. The result will be stored in the only element in stack.
	*/

	int i, n; // i to traverse for prefix, n is length of prefix
	float a, b, val;
	n = strlen(prefix);
	for(i=n-1; i>=0; i--)  // right to left
	{
		//1. If it is an operand, push it into stack.
		if(isdigit(prefix[i]))
		{
			pushFloat((float) prefix[i]-'0');
		}
		//2. If it is an operator, pop twice (store in variable A and B respectively) 
		// and push(A operator B).
		// Pay attention here! It is (A operator B), not (B operator A).
		else
		{
			a = peekFloat();
			pop();
			b = peekFloat();
			pop();

			switch(prefix[i])
			{
				case '^' : pushFloat(pow(a,b)); break;
				case '/' : pushFloat(a / b); break;
				case '*' : pushFloat(a * b); break;
				case '%' : pushFloat((int) a % (int) b); break;
				case '+' : pushFloat(a + b); break;
				case '-' : pushFloat(a - b); break;				
			}
		}

		// uncomment here to see simulation
		//printf("\n"); 
		//printf("'%c'\n", prefix[i]); 
		//printf("a : %.2f\t b : %.2f\n", a, b);
		//displayFloat();
		//getchar();
	}
	//3. The result will be stored in the only element in stack.
	val = peekFloat();
	pop();
	return val;
}

void infixtoPrefix(char infix[], char prefix[])
{	
	/*
	Convert to Prefix

	Step : 
	Scan the string from right to left, for each character in the string:
	1. If it is an operand, add it to the prefix string.
	2. If it is an close bracket, push it into stack.
	3. If it is a open bracket, pop the stack until you found an close bracket. Add each popped element to the prefix string (without the bracket).
	4. If it is an operator, pop while the stack’s top element has *higher precedence* than the scanned character. Add each popped element to the prefix string. Push the scanned character into stack.
	5. After you have scanned all character, pop all elements in stack and add them to prefix string.

	6. reverse prefix string.
	*/
	
	int i, j, n; // i to traverse infix, j for prefix, n is length of infix
	n = strlen(infix);
	for(i=n-1, j=0; i>=0; i--) // right to left
	{
		//1. If it is an operand, add it to the postfix string.
		if( isdigit(infix[i]) ) //non-zero is true
		{
			// isdigit is defined in ctype.h and help checks whether a character is decimal digit.
			// it return non-zero value if indeed the character is a decimal digit. zero otherwise
			// If we don't want to use ctype.h, we can use the following ascii symbol checking logic
			// if(infix[i] >= '0' && infix[i] <= '9') 
			prefix[j] = infix[i];
			j++;
		}
		//2. If it is an close bracket, push it into stack.
		else if (infix[i]==')')
		{
			pushChar(')');
		}
		// 3. If it is a open bracket, pop the stack until you found an close bracket. 
		// Add each popped element to the postfix string (without the bracket).
		else if (infix[i]=='(')
		{
			while(peekChar()!=-1 && peekChar()!=')')
			{	
				prefix[j] = peekChar();
				pop();
				j++;
			}

			// (without the bracket)
			// remove '('
			pop();			
		}
		// 4. If it is an operator, pop while the stack’s top element has higher precedence than the scanned character.
		// Add each popped element to the prefix string. 
		// Push the scanned character into stack.
		else if (ispunct(infix[i]))
		{
			// ispunct is defined in ctype.h and help checks whether a character is punctuation char.
			// 	!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
			// it return non-zero value if indeed the character is a punct. char. zero otherwise
			// If we don't want to use ctype.h, we can use the following ascii symbol checking logic
			// if(infix[i] == '+' || infix[i] == '-' .. and so on) 

			// Add each popped element to the postfix string. 
			while( peekChar()!=-1 && peekChar()!=')' && getPriority(peekChar()) > getPriority(infix[i]) )
			{	
				prefix[j] = peekChar();
				pop();
				j++;
			}

			// Push the scanned character into stack.
			pushChar(infix[i]);
		}
		else
		{
			strcpy(prefix, "Incorrect element in expression");
			return;
		}		
		
		// uncomment here to see simulation
		/*
		printf("\n");
		displayNotation(prefix);
		printf("\n");
		displayChar();
		getchar();
		*/
	}
	//5. After you have scanned all character, 
	//pop all elements in stack and add them to postfix string.
	while (peekChar()!=-1 && peekChar()!=')')
	{
		prefix[j] = peekChar();
		pop();
		j++;
	}
	prefix[j] = 0;

	//6. reverse prefix string.
	strrev(prefix);
}

float evaluatePostfix(char postfix[])
{
	/*
	Evaluate Postfix

	Step : 
	Scan the string from left to right, for each character in the string:
	1. If it is an operand, push it into stack.
	2. If it is an operator, pop twice (store in variable A and B respectively) and push(B operator A).
	Pay attention here! It is (B operator A), not (A operator B).
	3. The result will be stored in the only element in stack.
	*/

	int i; // i to traverse for postfix
	float a, b, val;
	for(i=0; i<strlen(postfix); i++) 
	{
		//1. If it is an operand, push it into stack.
		if(isdigit(postfix[i]))
		{
			pushFloat((float) postfix[i]-'0');
		}
		//2. If it is an operator, pop twice (store in variable A and B respectively) 
		// and push(B operator A).
		// Pay attention here! It is (B operator A), not (A operator B).
		else
		{
			a = peekFloat();
			pop();
			b = peekFloat();
			pop();

			switch(postfix[i])
			{
				case '^' : pushFloat(pow(b,a)); break;
				case '/' : pushFloat(b / a); break;
				case '*' : pushFloat(b * a); break;
				case '%' : pushFloat((int) b % (int) a); break;
				case '+' : pushFloat(b + a); break;
				case '-' : pushFloat(b - a); break;
			}			
		}
		// uncomment here to see simulation
		//printf("\n"); 
		//printf("'%c'\n", postfix[i]); 
		//printf("a : %.2f\t b : %.2f\n", a, b);
		//displayFloat();
		//getchar();
	}
	//3. The result will be stored in the only element in stack.
	val = peekFloat();
	pop();
	return val;
}

void infixtoPostfix(char infix[], char postfix[])
{
	
	/*
	Convert to Postfix

	Step : 
	Scan the string from left to right, for each character in the string:
	1. If it is an operand, add it to the postfix string.
	2. If it is an open bracket, push it into stack.
	3. If it is a close bracket, pop the stack until you found an open bracket. Add each popped element to the postfix string (without the bracket).
	4. If it is an operator, pop while the stack’s top element has *higher or equal* precedence than the scanned character. Add each popped element to the postfix string. Push the scanned character into stack.
	5. After you have scanned all character, pop all elements in stack and add them to postfix string.
	*/
	
	int i, j; // i to traverse infix, j for postfix
	
	for(i=0, j=0; i<strlen(infix); i++) 
	{
		//1. If it is an operand, add it to the postfix string.
		if( isdigit(infix[i]) ) //non-zero is true
		{
			// isdigit is defined in ctype.h and help checks whether a character is decimal digit.
			// it return non-zero value if indeed the character is a decimal digit. zero otherwise
			// If we don't want to use ctype.h, we can use the following ascii symbol checking logic
			// if(infix[i] >= '0' && infix[i] <= '9') 
			postfix[j] = infix[i];
			j++;
		}
		//2. If it is an open bracket, push it into stack.
		else if (infix[i]=='(')
		{
			pushChar('(');
		}
		// 3. If it is a close bracket, pop the stack until you found an open bracket. 
		// Add each popped element to the postfix string.
		else if (infix[i]==')')
		{
			while(peekChar()!=-1 && peekChar()!='(')
			{	
				postfix[j] = peekChar();
				pop();
				j++;
			}
			// remove '('
			pop();			
		}
		// 4. If it is an operator, pop while the stack’s top element has higher or equal precedence than the scanned character. 
		// Add each popped element to the postfix string. 
		// Push the scanned character into stack.
		else if (ispunct(infix[i]))
		{
			// ispunct is defined in ctype.h and help checks whether a character is punctuation char.
			// 	!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
			// it return non-zero value if indeed the character is a punct. char. zero otherwise
			// If we don't want to use ctype.h, we can use the following ascii symbol checking logic
			// if(infix[i] == '+' || infix[i] == '-' .. and so on) 

			// Add each popped element to the postfix string. 
			while( peekChar()!=-1 && peekChar()!='(' && getPriority(peekChar()) >= getPriority(infix[i]) )
			{	
				postfix[j] = peekChar();
				pop();
				j++;
			}
			// Push the scanned character into stack.
			pushChar(infix[i]);
		}
		else
		{
			strcpy(postfix, "Incorrect element in expression");
			return;
		}		
		
		// uncomment here to see simulation
		/*
		printf("\n");
		displayNotation(postfix);
		printf("\n");
		displayChar();
		getchar();
		*/
	}
	//5. After you have scanned all character, 
	//pop all elements in stack and add them to postfix string.
	while (peekChar()!=-1 && peekChar()!='(')
	{
		postfix[j] = peekChar();
		pop();
		j++;
	}
	postfix[j] = 0;
}

int getPriority(char op)
{
	if(op == '^' ) return 2;
	else if(op == '/' || op == '*' || op == '%') return 1;
	else if(op == '+' || op =='-') return 0;
}


void displayResult(float val)
{
	if(val>0)
	{
		printf("%.2f\n\n", val);		
	}
	else printf("[EMPTY]\n\n");
}

void displayNotation(char not[])
{
	if(strlen(not)>0)
	{
		printf("%s\n\n", not);		
	}
	else printf("[EMPTY]\n\n");
}

void insertInfix(char infix[])
{
	printf("\nInput Infix : ");
	gets(infix);
}


void popAll()
{
	struct Data *curr;
	
	while (tail)	
	{
		curr = tail;

		tail = tail->prev;
		if(tail) tail->next = NULL;
		else head = NULL;
		
		free(curr);
	}
}

char peekFloat()
{
	if(tail)	
	{
		return tail->f;
	}
	else
	{
		return -1;
	}
}

char peekChar()
{
	if(tail)	
	{
		return tail->k;
	}
	else
	{
		return -1;
	}
}

void pop()
{
	struct Data *curr;

	if(tail)	
	{
		curr = tail;

		if(head == tail) // data terakhir
		{
			head = tail = NULL;
		}
		else //bkn data terakhir
		{
			tail = tail->prev;
			tail->next = NULL;
		}		
		free(curr);
	}
}

void displayFloat()
{
	struct Data *curr;
	int n = numofnodes();

	if(n)
	{
		curr = head;
		while (curr)
		{
			printf("%.2f ", curr->f);
			curr = curr->next;
		}
	}
	else
	{
		printf("[EMPTY]\n\n");
	}

}

void displayChar()
{
	struct Data *curr;
	int n = numofnodes();

	if(n)
	{
		curr = head;
		while (curr)
		{
			printf("%c ", curr->k);
			curr = curr->next;
		}
	}
	else
	{
		printf("[EMPTY]\n\n");
	}

}

int numofnodes()
{
	struct Data *curr;
	int i=0;
	curr = tail; 
	while (curr)
	{
		curr = curr->prev;
		i++;
	}
	return i;
}

void pushFloat (float f)
{
	curr = (struct Data *) malloc(sizeof(struct Data));

	curr->f = f;
	curr->next = curr->prev = NULL;
	
	if(head == NULL)
	{
		head = tail = curr;
	}
	else
	{
		tail->next = curr;
		curr->prev = tail;
		
		tail = curr;
	}
}

void pushChar (char k)
{
	curr = (struct Data *) malloc(sizeof(struct Data));

	curr->k = k;
	curr->next = curr->prev = NULL;

	if(head == NULL)
	{
		head = tail = curr;
	}
	else
	{
		tail->next = curr;
		curr->prev = tail;
		
		tail = curr;
	}
}

void menu()
{
	printf("STACK Linked List :INFIX - POSTFIX\n");
	printf("++++++++++++++++++++++++++++++++++\n");
	printf("1. Insert INFIX \n");
	printf("2. Conversion to POSTFIX & PREFIX\n");
	printf("3. POSTFIX Evaluation\n");
	printf("4. PREFIX Evaluation\n");
	printf("0. Exit\n");
	printf(">> Input your choice : ");
}
