#ifndef DRZEWO_PRZEDZIALOWE_PUNKT_PRZEDZIAL
#define DRZEWO_PRZEDZIALOWE_PUNKT_PRZEDZIAL
#include <functional>
#include <vector>
#include <cmath>
#include <cstddef>
template<typename T, class Changer, class Combiner>
class DrzewoPrzedzialowePunktPrzedzial {
	public:
		DrzewoPrzedzialowePunktPrzedzial(std::size_t n)
			: tree(1<<((std::size_t)std::log2l(n+2)+2))
			, change(Changer{})
			, combine(Combiner{})
		{
			tree.assign(tree.size(), this->change());
		}
		void update(std::size_t index, T value)
		{
			index += (this->tree.size()>>1)+1;
			this->tree[index] = this->change(this->tree[index], value);
			while(index > 1) {
				this->tree[index>>1] = this->combine(this->tree[index], this->tree[index^1]);
				index >>= 1;
			}
		}
		T query(std::size_t first, std::size_t last)
		{
			first += (this->tree.size()>>1);
			last += (this->tree.size()>>1)+2;
			T result = this->combine();
			while(first>>1 != last>>1) {
				if((first&1) == 0)
					result = this->combine(result, this->tree[first+1]);
				if((last&1)==1)
					result = this->combine(result, this->tree[last-1]);
				first >>= 1;
				last >>= 1;
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
