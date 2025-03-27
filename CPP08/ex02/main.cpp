#include "MutantStack.hpp"

std::stack<int> subjectTest()
{
	std::cout << "------- MutantStack test ------\n";

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	int size = 0;
	std::cout << "mutant stack elements: \n";
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
		size++;
	}
	std::cout << "size: " << size << std::endl;
	std::stack<int> s(mstack);
	return (s);
}

void additionalTest(std::stack<int> s)
{
	std::cout << "------- additional test ------\n";
	s.push(1);
	s.push(2);
	s.push(3);
	std::cout << s.top() << std::endl;
	s.pop();
	std::cout << s.top() << std::endl;
	s.pop();
	std::cout << s.top() << std::endl;
	s.pop();
	std::cout << s.top() << std::endl;
	s.pop();
	std::cout << s.top() << std::endl;
	s.pop();
	std::cout << s.top() << std::endl;
	s.pop();
	std::cout << s.top() << std::endl;
	s.pop();
	std::cout << s.top() << std::endl;
}

void listTest()
{
	std::cout << "------- List test ------\n";
	
    std::list<int> mlist;
    mlist.push_back(5);
    mlist.push_back(17);
    std::cout << mlist.back() << std::endl;
    mlist.pop_back();
    std::cout << mlist.size() << std::endl;

    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    //[...]
    mlist.push_back(0);

    std::list<int>::iterator it = mlist.begin();
    std::list<int>::iterator ite = mlist.end();
    ++it;
    --it;

    int size = 0;
    std::cout << "list elements: \n";
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
        size++;
    }
    std::cout << "size: " << size << std::endl;

    std::stack<int, std::list<int> > s(mlist);
    std::cout << "top element of stack: " << s.top() << std::endl;
}

void myTest() 
{
	std::cout << "------- MY test ------\n";
    MutantStack<int> s;

    // Test 1: Check if the stack is empty
    if (s.empty() != true)
        return;
    std::cout << "Stack is empty." << std::endl;

    // Test 2: Push an element onto the stack
    s.push(10);
    if (s.empty() == true || s.size() != 1 || s.top() != 10)
        return;
    std::cout << "Stack has one element, top is 10." << std::endl;

    // Test 3: Push another element onto the stack
    s.push(20);
    if (s.size() != 2 || s.top() != 20)
        return;
    std::cout << "Stack has two elements, top is 20." << std::endl;

    // Test 4: Pop an element from the stack
    s.pop();
    if (s.size() != 1 || s.top() != 10)
        return;
    std::cout << "After pop, stack size is 1, top is 10." << std::endl;

    // Test 5: Pop the last element and check if the stack is empty
    s.pop();
    if (s.empty() != true || s.size() != 0)
        return;
    std::cout << "Stack is empty after popping all elements." << std::endl;
}

int main()
{
	std::stack<int> stack = subjectTest();
	// additionalTest(stack);
	// listTest();
	// myTest();
}