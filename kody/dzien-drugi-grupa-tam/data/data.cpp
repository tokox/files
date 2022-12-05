#include <iostream>
#include <regex>
namespace time {
	using date = long long int;
	long long datetotime(string date) {
			
	}
}
int main()
{
	std::string d1, d2;
	std::getline(std::cin, d1);
	std::getline(std::cin, d2);
	long long t1 = time::datetotime(d1);
	long long t2 = time::datetotime(d2);
	long long r = t2-t1;
	std::cout << time::timetoduration(r) << std::endl;
}
YYYY-MM-SS HH:mm:ss
x lat x miesiecy x dni x godzin x minut x sekund
