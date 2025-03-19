#include <numeric>
#include <algorithm>
#include <vector>
#include <array>
#include <iostream>
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

//----------------------------------------------------------

void ScanPairs::triples(){
	// Places triples in instance results vector
	vector<int> even{2,4,6,8,10};
	vector<int> odd{3,5,7,9};
	Triple triple;
	int x,y,z; //indexes
	if(results.empty()==false) results.clear();
	for(x = 0; x < even.size()-1; ++x){
		for(y = x+1; y < even.size(); ++y){
			for(z = 0; z < odd.size(); ++z){
				if ((gcd(even[x], odd[z]) == 1) and (gcd(even[y], odd[z]) == 1)){
					triple = {even[x], odd[z], even[y]};
					results.push_back(triple);
					for(auto t : triple) cout << t << " ";
					cout << endl;
				}
			}
		}
	}
}

void ScanPairs::make_fwd_set(){
	if(fwdset.empty()== false) fwdset.clear();
	// filter results to fwd_set using FwdCmp comparison
	for(auto t : results)
		fwdset.emplace(t);		
	}


void ScanPairs::make_bak_set(){
	Triple reversed;
	if(bakset.empty()== false) bakset.clear();
	// filter results to fwd_set using bak comparison
	for(auto t : results){
		reversed = {get<0>(t), get<1>(t), get<2>(t)};
		bakset.emplace(reversed);		
	}
}

void ScanPairs::prt_fwd_set(){
	cout << "Sort on LSD Set" << endl;
	for(auto t : fwdset) cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
	}
	
void ScanPairs::prt_bak_set(){
	cout << "Sort on MSD Set" << endl;
	for(auto t : bakset) cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
	}

	
	
	
	
	
	
	
	
