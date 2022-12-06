#include <iostream>
#include <iomanip>
#define FORMAT "%Y-%m-%d %H-%M-%S"
int main()
{
	std::tm t1, t2;
	cin >> get_time(t1, FORMAT) >> ws >> get_time(t2, FORMAT);
	long long t2 = time::datetotime(d2);
	long long r = t2-t1;
	std::cout << time::timetoduration(r) << std::endl;
}
YYYY-MM-SS HH:mm:ss
x lat x miesiecy x dni x godzin x minut x sekund
