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

