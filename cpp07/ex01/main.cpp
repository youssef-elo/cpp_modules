#include "iter.hpp"

int main()
{
	int arr[3] = {1, 2, 3};

	iter(arr, 3, increment<int>);
	iter(arr, 3, print_element<int>);
}
