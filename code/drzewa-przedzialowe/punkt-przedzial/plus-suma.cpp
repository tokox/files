#include "../punkt-przedzial.hpp"
#include <iostream>
using namespace std;
struct Plus { int operator()(int a = 0, int b = 0) {
	return a+b;
}};
int main()
{
	size_t size;
	cin >> size;
	DrzewoPrzedzialowePunktPrzedzial<int, Plus, Plus> tree(size);
	char op;
	while(cin >> op) {
		if(op == 'u' || op == 'U') {
			size_t index;
			cin >> index;
			int value;
			cin >> value;
			tree.update(index, value);
		} else if(op == 'Q' || op == 'q') {
			size_t first, last;
			cin >> first >> last;
			cout << tree.query(first, last) << endl;
		}
	}
}
