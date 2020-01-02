#pragma once

#include "deque.h"
#include <iostream>

#define MAX_SIZE 10'001

void Test_CreateEmptyDeque()
{
	std::cout << "Create empty deque...";

	Deque<int> deque;

	if (deque.getCap() == MAX_SIZE && deque.getSize() == 0)
		std::cout << "OK\n";
	else
		std::cout << "Failed\n";

}


void Test_CreateDeque()
{
	std::cout << "Create deque...";

	Deque<int> deque(50);
	if (deque.getSize() == 0 && deque.getCap() == 50)
		std::cout << "OK\n";
	else
		std::cout << "Failed\n";

}


void Test_GetFirstElement()
{
	std::cout << "Get first element...";

	Deque<int> deque(10);
	deque.pushFront(1);
	deque.pushFront(2);
	if (deque.getFront() == 2)
		std::cout << "OK\n";

	else
		std::cout << "Failed\n";

}

void Test_GetLastElement()
{
	std::cout << "Get last element...";

	Deque<int> deque(10);
	deque.pushBack(1);
	deque.pushBack(2);
	if (deque.getBack() == 2)
		std::cout << "OK\n";

	else
		std::cout << "Failed\n";

}

void Test_FrontEqualsBack()
{
	std::cout << "Get last element...";

	Deque<int> deque(10);
	deque.pushBack(1);
	if (deque.getBack() == deque.getFront() == 1)
		std::cout << "OK\n";

	else
		std::cout << "Failed\n";

}

void Test_PopFront()
{
	std::cout << "Pop front element...";

	Deque<int> deque(10);
	deque.pushFront(1);
	deque.pushFront(3);
	deque.popFront();
	if (deque.getFront() == 1 && deque.getSize() == 1)
		std::cout << "OK\n";
	else
		std::cout << "Failed\n";

}

void Test_isEmpty()
{
	std::cout << "Is empty...";

	Deque<int> deque;
	deque.pushBack(5);
	deque.popBack();
	if (deque.isEmpty())
		std::cout << "OK\n";
	else
		std::cout << "Failed\n";
}

void Test_isFull()
{
	std::cout << "Is full...";

	Deque<int> deque(2);
	deque.pushFront(2);
	deque.pushFront(5);
	if (deque.isFull())
		std::cout << "OK\n";
	else
		std::cout << "Failed\n";
}


void Test_GetFrontOnEmptyDeque()
{
	std::cout << "Get front on empty deque...";

	Deque<int> deque;

	try
	{
		deque.getFront();
		std::cout << "Failed (does not throw)\n";
	}
	catch (std::logic_error &)
	{
		std::cout << "OK\n";
	}
	catch (...)
	{
		std::cout << "Failed (wrong exception type)\n";
	}
}

void Test_PushInFullDeque()
{
	std::cout << "Push in full deque...";

	Deque<int> deque(3);
	deque.pushFront(1);
	deque.pushBack(3);
	deque.pushFront(6);

	try
	{
		deque.pushBack(10);
		std::cout << "Failed (does not throw)\n";
	}
	catch (std::logic_error &)
	{
		std::cout << "OK\n";
	}
	catch (...)
	{
		std::cout << "Failed (wrong exception type)\n";
	}
}

void Test_PopFromEmptyDeque()
{
	std::cout << "Pop from empty deque...";

	Deque<int> deque(3);

	try
	{
		deque.popFront();
		std::cout << "Failed (does not throw)\n";
	}
	catch (std::logic_error &)
	{
		std::cout << "OK\n";
	}
	catch (...)
	{
		std::cout << "Failed (wrong exception type)\n";
	}
}



void Test_GetBackOnEmptyDeque()
{
	std::cout << "Get back on empty deque...";

	Deque<int> deque;

	try
	{
		deque.getBack();
		std::cout << "Failed (does not throw)\n";
	}
	catch (std::logic_error &)
	{
		std::cout << "OK\n";
	}
	catch (...)
	{
		std::cout << "Failed (wrong exception type)\n";
	}
}

void Test_PrintDeque()
{	
	Deque<int> deque;
	for (int i = 0; i < 5; i++)
	{
		deque.pushBack(i);
	}
	for (int i = 6; i < 10; i++)
	{
		deque.pushFront(i);
	}
	deque.printDeque();
	std::cout << "Printing deque... OK\n";
}

int main()
{
	std::cout << "Testing class Deque:\n";

	Test_CreateEmptyDeque();
	Test_CreateDeque();
	Test_FrontEqualsBack();
	Test_GetBackOnEmptyDeque();
	Test_GetFirstElement();
	Test_GetFrontOnEmptyDeque();
	Test_GetLastElement();
	Test_isEmpty();
	Test_isFull();
	Test_PopFromEmptyDeque();
	Test_PopFront();
	Test_PushInFullDeque();
	Test_PrintDeque();
	system("pause");
	return 0;
}

