
#include <iostream>
#include "Header1.h"
#include"Source1.cpp"
#include <vector>
using namespace std;

int main()
{


	l_list list;
	int size, num;
	vector<int> V;


	list.insert_first(4);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(1);
	list.insert_end(5);
	list.print();

	list.insert_after(2, 10);
	list.insert_before(3, 5);
	cout << endl << endl;
	list.print();
	cout << "The sum of the values in the list: " << list.list_sum();

	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> num;
		V.push_back(num);
	}
	list.vec_list(V);

	return 0;
}

