#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

class ScanPairs{
	public:
		ScanPairs(int n);
		void funct01(int n);
		void pairwise_scan(); // Query - private?
		bool scan_flag;
					
	private:
		pair<int,int> scan_pair;	// contains the indices which failed gcd check
		bool odd_flag;
		vector<int> even;
		vector<int>	odd;	
	
};
