#ifndef DRZEWO_PRZEDZIALOWE_PLUS_SUMA_PUNKT_PRZEDZIAL
#define DRZEWO_PRZEDZIALOWE_PLUS_SUMA_PUNKT_PRZEDZIAL
#include <vector>
#include <cmath>
class DrzewoPrzedzialowePlusSumaPunktPrzedzial {
	public:
		DrzewoPrzedzialowePlusSumaPunktPrzedzial(long long n)
			: tree(1<<((long long)std::log2l(n+2)+2), 0)
		{}
		void update(long long index, long long value) {
			index += this->tree.size()>>1;
			while(index > 0) {
				this->tree[index] += value;
				index >>= 1;
			}
		}
		long long query(long long first, long long last) {
			first += (this->tree.size()>>1)-1;
			last += (this->tree.size()>>1)+1;
			long long result = 0;
			while(first>>1 != last>>1) {
				if((first&1)==0)
					result += this->tree[first+1];
				if((last&1)==1)
					result += this->tree[last-1];
				first >>= 1;
				last >>= 1;
			}
			return result;
		}
	private:
		std::vector<long long> tree;
};
#endif
