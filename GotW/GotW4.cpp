class Complex 
{
    public:
        Complex( double real, double imaginary = 0 )
          : _real(real), _imaginary(imaginary) {};

        void operator+ ( Complex other ) {
            _real = _real + other._real;
            _imaginary = _imaginary + other._imaginary;
        }

        void operator<<( ostream os ) {
            os << "(" << _real << "," << _imaginary << ")";
        }

        Complex operator++() {
            ++_real;
            return *this;
        }

        Complex operator++( int ) {
            Complex temp = *this;
            ++_real;
            return temp;
        }

    private:
        double _real, _imaginary;
};

/*You are doing a code review. A programmer has written the following class, 
which shows some poor style and has some real errors. How many can you find, and how would you fix them?*/

/* 
    [1] :   This can be used as a single-parameter constructor, hence as an implicit conversion. This may not always be intended!
    
    [2] :   For efficiency, the parameter should be a const& and "a=a+b" should be rewritten "a+=b".
    
    [3] :   operator+ should not be a member function. If it's a member like this, you can write "a=b+1" but not "a=1+b". 
            For efficiency, you may want to provide an operator+(Complex,int) and operator+(int,Complex) too.)
    
    [4] :   ERROR: operator+ should not modify this object's value. It should return a temporary object containing the sum. 
            Note that this return type should be "const Complex" (not just "Complex") in order to prevent usage like "a+b=c".
    
    [5] :   You should normally define op= if you define op. Here, you should define operator+=, since you defined operator+. 
            In this case, the above function should be operator+= in any case (with a tweak for the proper return value, see below).
    
    [6] :   operator<< should not be a member function (see above), and the parameters should be "(ostream&, const Complex&)". 
            Note that, as James Kanze pointed out, it's preferable not to make it a friend either! Rather, it should call a "print" public member function that does the work.
    
    [7] :   The function should have return type "ostream&", and should end with "return os;" to permit chaining (so you can write "cout << a << b;").   
    
    [8] :   Preincrement should return Complex& to let client code operate more intuitively.

    [9] :   Postincrement should return "const Complex". This prevents things like "a++++", which doesn't do what a naive coder might think.     

    [10]:   It would be better to implement postincrement in terms of preincrement.

    [11]:   Try to avoid names with leading underscores. Yes, I've habitually used them, and yes, popular books like "Design Patterns" (Gamma et al) do use it... 
            but the standard reserves some leading-underscore identifiers for the implementation and the rules are hard enough 
            to remember (for you and for compiler writers!) that you might as well avoid this in new code. 

*/

class Complex 
{
    public:
        Complex( double real, double imaginary = 0 ) //[1]
          : real_(real), imaginary_(imaginary) { };

        Complex& operator+= (const Complex& other) { //[5]
            real_ += other.real_; //[2]
            imaginary_ += other.imaginary_; //[2]
            return *this;
        }

        Complex& operator++() {
            ++real_;
            return *this;  //[8]
        }

        const Complex operator++(int) {  //[9]
            Complex temp{*this};
            operator++()  //[10]
            return temp;
        }

        ostream& print( ostream& os ) const { //[6]
            return os << "(" << real_ //[7]
                      << "," << imaginary_ << ")";
        }

    private:

        double real_, imaginary_; //[11]
        
        friend ostream& operator<<(ostream& os,const Complex& c);

        const Complex operator+( const Complex& lhs,const Complex& rhs ) { //[3]
            Complex ret(lhs); //[4]
            ret += rhs;
            return ret; //[4]
        }

        ostream& operator<<(ostream& os,const Complex& c) { //[6]
            return c.print(os); //[7]
        }
};
