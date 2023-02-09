#include "../punkt-przedzial.hpp"
#include <iostream>
#include <limits>
using namespace std;
struct Assign { int operator()(int a = 0, int b = 0) {
	return b;
}};
struct Min { int operator()(int a = std::numeric_limits<int>::max(), int b = std::numeric_limits<int>::max()) {
	return (a < b ? a : b);
}};
int main()
{
	size_t size;
	cin >> size;
	DrzewoPrzedzialowePunktPrzedzial<int, Assign, Min> tree(size);
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
