#include<numeric>
#include<cstdint>
#include<iostream>
#include<tuple>
#include<vector>
#include<algorithm>
#include<map>
#include<utility>
using namespace std;

int main(int argc, char const *argv[])
{
	uint64_t n,m;

	map<uint64_t, vector<uint64_t>> coprimes;
	for(n = 2; n < 35; ++n) {
		vector<uint64_t> t = {};
		for(m = 2; m < 35; ++m){
			if (gcd(m,n)==1) t.push_back(m);
		}
		coprimes.emplace(n, t);
	}

	const uint64_t N = 6;
	for(auto p : coprimes){
		if (p.first > N) break;
		cout << p.first << " -> ";
		for(auto q : p.second) {
			if (q > N) break;
			cout << q << " ";
		}
		cout << endl;
	}

	return 0;
}