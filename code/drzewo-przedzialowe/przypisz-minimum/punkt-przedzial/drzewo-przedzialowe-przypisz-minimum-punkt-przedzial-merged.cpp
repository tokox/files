#include <vector>
#include <cmath>
#include <climits>
class DrzewoPrzedzialowePrzypiszMinimumPunktPrzedzial {
	public:
		DrzewoPrzedzialowePrzypiszMinimumPunktPrzedzial(long long n)
			: tree(1<<((long long)std::log2l(n+2)+2), LLONG_MAX)
		{}
		void update(long long index, long long value) {
			index += this->tree.size()>>1+1;
			this->tree[index] = value;
			index >>= 1;
			while(index > 0) {
				this->tree[index] = std::min(this->tree[index*2], this->tree[index*2+1]);
				index >>= 1;
			}
		}
		long long query(long long first, long long last) {
			first += (this->tree.size()>>1);
			last += (this->tree.size()>>1)+2;
			long long result = LLONG_MAX;
			while(first>>1 != last>>1) {
				if((first&1)==0)
					result = std::min(result, this->tree[first+1]);
				if((last&1)==1)
					result = std::min(result, this->tree[last-1]);
				first >>= 1;
				last >>= 1;
			}
			return result;
		}
	private:
		std::vector<long long> tree;
};
#include <iostream>
using namespace std;
int main()
{
	long long n;
	cin >> n;
	DrzewoPrzedzialowePrzypiszMinimumPunktPrzedzial tree(n);
	char p;
	int a, b;
	while(cin >> p >> a >> b) {
		if(p == 'u' || p == 'U')
			tree.update(a, b);
		else if(p == 'q' || p == 'Q')
			cout << tree.query(a, b) << endl;
	}
}
