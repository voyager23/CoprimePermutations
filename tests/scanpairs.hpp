#include <algorithm>
#include <utility>
#include <vector>
#include <array>
#include <set>

using namespace std;

typedef array<int,3> Triple;

class ScanPairs{
	
	public:
		ScanPairs(int n);
		void funct01(int n);
		void pairwise_scan(); // Query - private?
		bool scan_flag;
		//-------------------------
		void triples();	//Test Code
		
		void make_fwd_set();	// sorted by first value
		void make_bak_set();	// sorted by last value
		
		void prt_fwd_set();
		void prt_bak_set();
						
	private:
		pair<int,int> scan_pair;	// contains the indices which failed gcd check
		bool odd_flag;
		vector<int> even;
		vector<int>	odd;	
		vector<Triple> results;
		
		struct FwdCmp
		{
			bool operator()(const Triple& lhs, const Triple& rhs) const
			// return true if lhs < rhs
			{
				if (get<0>(lhs) < get<0>(rhs)) return true;
				if ((get<0>(lhs) == get<0>(rhs))and(get<1>(lhs) < get<1>(rhs))) return true;
				return (get<2>(lhs) < get<2>(rhs));
			}
		};
		
		struct BakCmp
		{
			bool operator()(const Triple& lhs, const Triple& rhs) const
			// reverse comparison order
			{
				if (get<2>(lhs) < get<2>(rhs)) return true;
				if ((get<2>(lhs) == get<2>(rhs))and(get<1>(lhs) < get<1>(rhs))) return true;
				return (get<0>(lhs) < get<0>(rhs));
			}
		};
		
		set<Triple, FwdCmp> fwdset;
		set<Triple, BakCmp> bakset;	
};
