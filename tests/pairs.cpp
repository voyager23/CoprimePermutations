/*
 * pairs.cpp
 * 
 * Copyright 2025 mike <mike@xps14>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
#include <algorithm>
#include "../inc/scanpairs.hpp"
#include "../inc/copmpr.hpp"

using namespace std;

int main(int argc, char **argv)
{
	//~ ScanPairs scanpairs(34);
	//~ do{
		//~ scanpairs.pairwise_scan();
	//~ }while (scanpairs.scan_flag == true);
	
	ScanPairs sp;
	sp.triples(12);
	sp.make_fwd_set();
	
	vector<Triple> fwd_set = sp.get_fwd_set();
	for(Triple t : fwd_set) cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
	
	const int MSD = 8;
	vector<Triple> subset;
	for(Triple t : fwd_set) 
		if (get<2>(t) == MSD) subset.push_back(t);
	cout << endl;
	
	//for(Triple t : subset) cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
	
	// for each triple in subset find/print 1 or more possible continuations
	for(Triple &x : subset){
		vector<Triple> results = {x};
		for(Triple &y : subset){
			if ((x == y) or (get<0>(x) == get<0>(y)) or (get<1>(x) == get<1>(y))) continue;
			results.push_back(y);
		}
		for(Triple &z : results) {
			sp.prt_triple(z);
			cout << "   ";
		}
		cout << endl;
	}

	return 0;
}

