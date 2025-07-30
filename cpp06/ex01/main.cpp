#include "Serializer.hpp"

int main()
{
	Data obj;

	obj.internal_data = "hello";
	Data *ptr = &obj;
	Data *sptr = Serializer::deserialize( Serializer::serialize(ptr) );
	std::cout << "object pointer\t\t\t\t" <<  ptr << std::endl 
			<< "serialized and deserialized pointer\t" << sptr << std::endl;	
}