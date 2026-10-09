#include<iostream.h>
#include<conio.h>

class stack{
		int s[10];
		int top;
	public:
		stack(){
			top = -1;
		}
		void push(int);
		int pop();
		void display();
};

void stack::push(int val)
{
	if(top == 9)
	{
		cout<<"\n Stack Overflow";
		return;
	}

	top = top + 1;
	s[top] = val;
}

int stack::pop()
{
	int temp = 0;

	if(top == -1)
	{
		cout<<"\n Stack Underflow";
		return -1;
	}

	temp = s[top];
	top = top - 1;

	return temp;
}

void stack::display()
{
	int i=0;

	if(top == -1)
	{
		cout<<"\n Stack Is Empty";
		return;
	}

	for(i=0;i<=top;i++)
	{
		cout<<"\n Stack["<<i+1<<"] : "<<s[i];
	}
}

void main()
{
	stack s;
	int del;

	clrscr();


	s.push(10);
	s.push(20);
	s.push(30);

	cout<<"\n Insert : ";

	s.display();

	del = s.pop();
	cout<<"\n Deleted Value : "<<del;

	cout<<"\n Display : ";

	s.display();

	getch();
}