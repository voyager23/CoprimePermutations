#include<numeric>
#include<cstdint>
#include<iostream>
#include<tuple>
#include<vector>
using namespace std;

int main(int argc, char const *argv[])
{
	uint64_t n,m;
	const uint64_t N = 10;
	vector<tuple<uint64_t,uint64_t>> pairs;

	for(n = 2; n < N ; n++){
		for(m = n; m <= N; ++m){
			if (gcd(n,m)==1){
				//cout << "(" << n << "," << m << ")" << endl;
				pairs.push_back(tuple<uint64_t,uint64_t>{m,n});
			}
		}
	}
	for(auto r : pairs) cout << std::get<0>r << "," << std::get<1>r << endl;
	return 0;
}