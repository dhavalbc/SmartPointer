// SmartPointer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <memory>
#include <iostream>

using namespace std;
#define ENABLE_UNIQUE 1

class A {
public:
	A(){
		cout << "inside A ctor" << "\n";
	}
	~A() {
		cout << "inside A dtor" << "\n";
	}
};

class B {
public:
	B(){
		cout << "inside B ctor" << "\n";
	}
	~B() {
		cout << "inside B dtor" << "\n";
	}
};

typedef struct _tmp {
#if ENABLE_UNIQUE
	unique_ptr<A>ptr1;
	unique_ptr<B>ptr2;
#else
	A* ptr1;
	B* ptr2;
#endif
}tmp;

int _tmain(int argc, _TCHAR* argv[])
{
	A *a = new A;
	B *b = new B;

	tmp *t = new tmp;
#if ENABLE_UNIQUE
	t->ptr1 = std::unique_ptr<A>(a);
	t->ptr2 = std::unique_ptr<B>(b);
	delete t;
#else
	t->ptr1 = a;
	t->ptr2 = b;

	delete t->ptr1;
	delete t->ptr2;
	delete t;
#endif
	cout << "after delete t" << "\n";
	return 0;
}

