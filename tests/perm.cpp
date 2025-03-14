#include<numeric>
#include<cstdint>
#include<iostream>
#include<tuple>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	uint64_t n,m, count=0;;

	vector<uint64_t> group{2,3,4,5,6,7,8,9,10};

	do
    {
    	// test for coprime pairs {?reverse order?}
    	bool flag = true;
    	for(auto i = group.begin(); i != group.end()-1; ++i){
    		if (gcd(*i,*(i+1)) != 1){
    			flag = false;
    			break;
    		}
    	}
    	if(flag){
       		for(auto n : group) cout << n << " ";
       		cout << endl;
       		count++;
       	} 
    }
    while (std::next_permutation(group.begin(), group.end()));

    cout << "Count: " << count << endl;

	return 0;
}
