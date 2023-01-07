#ifndef DRZEWO_PRZEDZIALOWE_PLUS_WARTOSC_PRZEDZIAL_PUNKT
#define DRZEWO_PRZEDZIALOWE_PLUS_WARTOSC_PRZEDZIAL_PUNKT
#include <vector>
#include <cmath>
class DrzewoPrzedzialowePlusWartoscPrzedzialPunkt {
	public:
		DrzewoPrzedzialowePlusWartoscPrzedzialPunkt(long long n)
			: tree(1<<((long long)std::log2l(n+2)+2), 0)
		{}
		void update(long long first, long long last, long long value) {
			first += (this->tree.size()>>1);
			last += (this->tree.size()>>1)+2;
			while(first>>1 != last>>1) {
				if((first&1)==0)
					this->tree[first+1] += value;
				if((last&1)==1)
					this->tree[last-1] += value;
				first >>= 1;
				last >>= 1;
			}
		}
		long long query(long long index) {
			index += (this->tree.size()>>1)+1;
			long long result = 0;
			while(index > 0) {
				result += this->tree[index];
				index >>= 1;
			}
			return result;
		}
	private:
		std::vector<long long> tree;
};
#endif
