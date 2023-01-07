#ifndef DRZEWO_PRZEDZIALOWE_PUNKT_PRZEDZIAL
#define DRZEWO_PRZEDZIALOWE_PUNKT_PRZEDZIAL
#include <functional>
#include <vector>
#include <cmath>
#include <cstddef>
template<typename T>
class DrzewoPrzedzialowePunktPrzedzial {
	public:
		DrzewoPrzedzialowePunktPrzedzial(std::size_t n, function<T(T a, T b)> changer, function<T(T a, T b)> combiner)
			: tree(1<<((std::size_t)std::log2l(n+2)+2))
			, initialized(1<<((std::size_t)std::log2l(n+2)+2))
			, change(changer)
			, combine(combiner)
		{}
		void update(std::size_t index, T value) {
			index += (this->tree.size()>>1)+1;
			if(this->initialized[index])
				this->tree[index] = this->change(this->tree[index], value);
			else
				this->tree[index] = value;
			while(index > 1) {
				if(!this->initialized[index^1])
					this->tree[index>>1] = this->tree[index];
				else
					this->tree[index>>1] = this->combine(this->tree[index], this->tree[index^1]);
				index >>= 1;
			}
		}
		T query(std::size_t first, std::size_t last) {
			first += (this->tree.size()>>1);
			last += (this->tree.size()>>1)+2;
			T result;
			bool init = false;
			while(first>>1 != last>>1) {
				if((first&1)==0) {
					if(!init) {
						result = this->tree[first+1];
						init = true;
					} else
						result = this->combine(result, this->tree[first+1]);
				}
				if((last&1)==1) {
					if(!init) {
						result = this->tree[last-1];
						init = true;
					} else
						result = this->combine(result, this->tree[last-1]);
				}
				first >>= 1;
				last >>= 1;
			}
			return result;
		}
	private:
		std::vector<T> tree;
		std::vector<bool> initialized;
		function<T(T a, T b)> change;
		function<T(T a, T b)> combine;
};
#endif
