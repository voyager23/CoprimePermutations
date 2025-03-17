/*
 * table.cpp
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

#include<numeric>
#include<iostream>
#include<utility>
#include "./table.hpp"

using namespace std;

Table::Table(){
	// construct coprimes 2 <= N < 35;
	//coprimes maps "8" to vector<"3","5","7","9"...> etc
	for(int n = 2; n < 35; ++n){
		vector<string> temp;
		for(int m = 2; m < 35; ++m){
			if((n==m) or (gcd(n,m)!=1)) continue;
			temp.push_back(to_string(m));
		}
		coprimes.emplace(to_string(n),temp);
	}
}


void Table::prt_table(int limit){
	string s_lim = to_string(limit);
	cout << "Read across for each value of N" << endl;
	for(int n = 2; n<= limit; ++n){
		auto i = coprimes.find(to_string(n));
		if(i == coprimes.end()){
			cout << "Key " << n << " not found in prt_table\n";
			return;
		}
		cout << i->first<< ")\t";
		// i.second is vector of strings
		for(auto j : i->second){
			if(stoi(j) > limit) break;
			cout << j << " ";
		}
		cout << endl;
	}	
}

