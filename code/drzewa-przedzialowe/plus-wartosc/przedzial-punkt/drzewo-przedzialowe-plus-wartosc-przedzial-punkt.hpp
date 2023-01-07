#ifndef DRZEWO_PRZEDZIALOWE_PLUS_WARTOSC_PRZEDZIAL_PUNKT
#define DRZEWO_PRZEDZIALOWE_PLUS_WARTOSC_PRZEDZIAL_PUNKT
#include <vector>
#include <cmath>
template<typename T>
class DrzewoPrzedzialowePlusWartoscPrzedzialPunkt {
	public:
		DrzewoPrzedzialowePlusWartoscPrzedzialPunkt(size_t n)
			: tree(1<<((size_t)std::log2l(n+2)+2), 0)
		{}
		void update(size_t first, size_t last, T value) {
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
		T query(size_t index) {
			index += (this->tree.size()>>1)+1;
			T result = 0;
			while(index > 0) {
				result += this->tree[index];
				index >>= 1;
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
