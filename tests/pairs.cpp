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

int main(int argc, char **argv)
{
	//~ ScanPairs scanpairs(34);
	//~ do{
		//~ scanpairs.pairwise_scan();
	//~ }while (scanpairs.scan_flag == true);
	
	ScanPairs sp;
	sp.triples(12);
	
	sp.make_fwd_set();
	sp.make_bak_set();
	
	cout << endl;
	sp.prt_fwd_set();
	cout << endl;
	sp.prt_bak_set();
	
	// list any triple for which center satisfies N//2 + 1. N=10 center=6, N=12 center=7.
	
	
	return 0;
}

