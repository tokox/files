#ifndef DRZEWO_PRZEDZIALOWE_PRZEDZIAL_PUNKT
#define DRZEWO_PRZEDZIALOWE_PRZEDZIAL_PUNKT
#include <functional>
#include <vector>
#include <cmath>
#include <cstddef>
template<typename T, class Changer>
class DrzewoPrzedzialowePrzedzialPunkt {
	public:
		DrzewoPrzedzialowePrzedzialPunkt(std::size_t n)
			: tree(1<<((std::size_t)std::log2l(n+2)+2))
			, change(Changer{})
			, combine(Combiner{})
		{
			tree.assign(tree.size(), this->change());
		}
		void update(std::size_t first, std::size_t last, T value) {
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
		T query(std::size_t index) {
			index += (this->tree.size()>>1)+1;
			T result = 0;
			while(index > 0) {
				result += this->tree[index];
				index >>= 1;
			}
			return result;
		}
		std::size_t size() {
			return (tree.size()>>1)-2;
		}
	private:
		std::vector<T> tree;
		Changer change;
		Combiner combine;
};
#endif
