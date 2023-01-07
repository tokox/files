#ifndef DRZEWO_PRZEDZIALOWE_PLUS_SUMA_PUNKT_PRZEDZIAL
#define DRZEWO_PRZEDZIALOWE_PLUS_SUMA_PUNKT_PRZEDZIAL
#include <vector>
#include <cmath>
template<typename T>
class DrzewoPrzedzialowePlusSumaPunktPrzedzial {
	public:
		DrzewoPrzedzialowePlusSumaPunktPrzedzial(size_t n)
			: tree(1<<((size_t)std::log2l(n+2)+2), 0)
		{}
		void update(size_t index, T value) {
			index += (this->tree.size()>>1)+1;
			while(index > 0) {
				this->tree[index] += value;
				index >>= 1;
			}
		}
		T query(size_t first, size_t last) {
			first += (this->tree.size()>>1);
			last += (this->tree.size()>>1)+2;
			T result = 0;
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
		size_t size() {
			return (tree.size()>>1)-2;
		}
		T get(size_t index) {
			return tree[index];
		}
		T at(size_t index) {
			return tree[(tree.size()>>1)+index+1];
		}
	private:
		std::vector<T> tree;
};
#endif
