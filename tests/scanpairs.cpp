#include <numeric>
#include <algorithm>
#include "./scanpairs.hpp"

ScanPairs::ScanPairs(int n){
	// Fill even and odd vectors with terms 2 .. n
	for(int m = 2; m < n; m += 2){
		even.push_back(m);
		odd.push_back(m+1);
	}
	even.push_back(n);	// final even value	
}

void ScanPairs::funct01(int n){
	
	do{
		do{
			// process even/odd
			pairwise_scan();	// set flag and possibly 
		} while (next_permutation(odd.begin(), odd.end()));
	} while (next_permutation(even.begin(), even.end()));
	
}

void ScanPairs::pairwise_scan(){
	// Scan pairs in even / odd vectors
	// set private scan_flag true on success
	// save fail indexes in private scan_pair
	scan_flag = false;
	scan_pair = pair(-1,-1);
	for(int e = 0; e != even.size(); ++e){
		for(int d = 0; d != odd.size(); ++d){
			if (gcd(even[e], odd[d]) != 0 ){
				scan_pair = pair(e,d);
				return;	// return fail data
			}
		}
	}
}
