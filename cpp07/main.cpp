#include <iostream>

class integ
{

	public:
		int a;
		integ(int arg): a(arg){}
		bool operator< ( const integ & other)
		{
			return a < other.a;
		}
};

std::ostream& operator<<(std::ostream& out, const integ& other)
{
	out << other.a;
	return out;
}

template < typename T>
T my_max(T first, T second)
{
	return ( first < second)? second : first;
}
@param
void testing ( int a , int b)
{

}


int main ()
{
	integ a(3), b(7);

	std::cout << my_max(8, 0) << std::endl;
}