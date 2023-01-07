#include "drzewo-przedzialowe-plus-suma-punkt-przedzial.hpp"
#include <iostream>
using namespace std;
int main()
{
	size_t n;
	cin >> n;
	DrzewoPrzedzialowePlusSumaPunktPrzedzial<int> tree(n);
	char p;
	while(cin >> p) {
		if(p == 'u' || p == 'U') {
			size_t a;
			int b;
			cin >> a >> b;
			tree.update(a, b);
		} else if(p == 'q' || p == 'Q') {
			size_t a, b;
			cin >> a >> b;
			cout << tree.query(a, b) << endl;
		}
	}
}
