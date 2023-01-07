#include "drzewo-przedzialowe-plus-wartosc-przedzial-punkt.hpp"
#include <iostream>
using namespace std;
int main()
{
	long long n;
	cin >> n;
	DrzewoPrzedzialowePlusWartoscPrzedzialPunkt tree(n);
	char p;
	int a, b, c;
	while(cin >> p) {
		if(p == 'u' || p == 'U') {
			cin >> a >> b >> c;
			tree.update(a, b, c);
		} else if(p == 'q' || p == 'Q') {
			cin >> a;
			cout << tree.query(a) << endl;
		}
	}
}
