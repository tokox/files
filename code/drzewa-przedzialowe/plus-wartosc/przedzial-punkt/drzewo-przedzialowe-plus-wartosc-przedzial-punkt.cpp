#include "drzewo-przedzialowe-plus-wartosc-przedzial-punkt.hpp"
#include <iostream>
using namespace std;
int main()
{
	size_t n;
	cin >> n;
	DrzewoPrzedzialowePlusWartoscPrzedzialPunkt<int> tree(n);
	char p;
	while(cin >> p) {
		if(p == 'u' || p == 'U') {
			size_t a, b;
			int c;
			cin >> a >> b >> c;
			tree.update(a, b, c);
		} else if(p == 'q' || p == 'Q') {
			size_t a;
			cin >> a;
			cout << tree.query(a) << endl;
		}
	}
}
