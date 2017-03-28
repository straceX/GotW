#include <iostream>
#include <complex>
using namespace std;

class Base {
	public:
        virtual void f( int ) {
            cout << "Base::f(int)" << endl;
        }

        virtual void f( double ) {
            cout << "Base::f(double)" << endl;
        }

        virtual void g( int i = 10 ) {
            cout << i << endl;
        }
};

class Derived: public Base {
    public:
        void f( complex<double> ) {
            cout << "Derived::f(complex)" << endl;
        }

        void g( int i = 20 ) {
            cout << "Derived::g() " << i << endl;
        }
    };

void main() {
	
    Base    b;
    Derived d;
    Base*   pb = new Derived;

	b.f(1.0);
    d.f(1.0);
    pb->f(1.0);

	b.g();
	d.g();
	pb->g();

	delete pb;
}
/* In your travels through the dusty corners of your company's code archives, you come across the following program fragment written by an unknown programmer. The programmer seems to have been experimenting to see how some C++ features worked. What did the programmer probably expect the program to print, but what is the actual result? */

#include <iostream>
#include <complex>

using namespace std;

class Base {
public:
    virtual void f( int ) {
        cout << "Base::f(int)" << endl;
    }

    virtual void f( double ) {
        cout << "Base::f(double)" << endl;
    }

    virtual void g( int i = 10 ) {
        cout << i << endl;
    }
    virtual ~Base() = default; //Make base class destructors virtual
};

class Derived: public Base {
public:
    using Base::f; //When providing a function with the same name as an inherited function, 
                   //be sure to bring the inherited functions into scope with a "using" declaration 
                   //if you don't want to hide them.
    
    void f( complex<double> ) {
        cout << "Derived::f(complex)" << endl;
    }

    void g( int i = 10 ) { //Never change the default parameters of overridden inherited functions.
        cout << "Derived::g() " << i << endl;
    }
};

int main(void)
{
    Base    b;
    Derived d;
    Base*   pb = new Derived;

    b.f(1.0);
    d.f(1.0);
    pb->f(1.0);

    b.g();
    d.g();
    pb->g();

    delete pb;

    return 0;
}