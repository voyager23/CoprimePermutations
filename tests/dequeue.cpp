#include<numeric>
#include<cstdint>
#include<iostream>
#include<vector>
#include<utility>
#include<deque>

using namespace std;

typedef std::deque<uint64_t> CoprimePerm;
typedef vector<vector<int>> table;

class Table{
	public:
		table check;
		Table(int n);
		void prt_table(int limit=10);
		
	private:
	
};

Table::Table(int x){
	// x is the highest index required
	for(auto c = 0; c < x+1; ++c)
	{
		check.push_back(vector<int>{});
	}
	
	// initialise lookup for range 2..x
	// use row,col indexes n,m
	for(auto n = 2; n <= x; ++n){
		for(auto m = 2; m <= x; ++m){
			if ((n==m) or (gcd(n,m) != 1)) continue;	// retain zero value;
			check[n].push_back(m);		
		}
	}
	
}

void Table::prt_table(int limit){
	// debug display
	cout << "Read across for each N value" << endl;
	for(auto n = 2; n <= 34; ++n){
		if(n > limit) break;
		cout << n << ") ";
		// table.check[i] is a vector
		for(auto i : check[n]) 
			if(i <= limit) cout << i << " ";
			else break;
		cout << endl;
	}	
}


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
	
	for(auto m : suffix){
		for(auto n : suffix){
			if(m==n) continue;
			cout << m << " " << 8 << " " << n << endl;
		}
	}
	
	return 0;
}
