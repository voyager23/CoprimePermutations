#include<numeric>
#include<cstdint>
#include<iostream>
#include<utility>
#include<deque>

using namespace std;

#include "./table.hpp"

int main(int argc, char const *argv[])
{
	/*
	 * Only considering even values for P(n)
	 * For 2..n we have (n-1) values e.g P(8) 2,3,4,5,6,7,8,9,10
	 * pivot value is n//2 + 1	pivot parity can be odd/even	 P(8) odd P(10) even
	 * 
	 */
	 
	const int limit = 10;
	Table table(35);
	table.prt_table(10);
	/*
	 * Consider numbers 2..10 as 'pivot' numbers and construct possible triples
	 */
	 vector<int> suffix;
	 
	for(int pivot = 8; pivot < 9; ++pivot){
		// make list/vector of totients for pivot. These form the prefix and suffix numbers
		for(auto t : table.check[pivot]) {
			if(t > limit) break;
			suffix.push_back(t);
		}
		cout << endl;		
	}
	
	for(auto s : suffix) cout << " " << s;
	cout << endl;
	
	// select permutations of prefix and suffix
	for(auto m : suffix){
		for(auto n : suffix){
			if(m==n) continue;
			cout << m << " " << 8 << " " << n << endl;
		}
	}
	
	return 0;
}
