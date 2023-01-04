#include "intervaltree.hpp"
#include <iostream>
using namespace std;
int main()
{
	long long n;
	cin >> n;
	IntervalTree tree(n);
	char p;
	int a, b;
	while(cin >> p >> a >> b) {
		if(p == 'u' || p == 'U')
			tree.update(a, b);
		else if(p == 'q' || p == 'Q')
			cout << tree.query(a, b) << endl;
	}
}
