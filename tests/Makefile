# Makefile for CoprimePermutations test folder

CFLAGS = --std=c++20 
DEBUG = -g



dequeue : dequeue.cpp table.cpp
	@echo "Clearing"
	clear
	g++ $(CFLAGS) $(DEBUG) $@.cpp table.cpp -o ../bin/$@
	@ln -fs ../bin/$@ ../bin/bin_link
	@symlinks -v ../bin
	
map : map.cpp
	@echo "Clearing"
	clear
	g++ $(CFLAGS) $(DEBUG) $@.cpp -o ../bin/$@
	@ln -fs ../bin/$@ ../bin/bin_link
	@symlinks -v ../bin

perm : perm.cpp
	@echo "Clearing"
	clear
	g++ $(CFLAGS) $(DEBUG) $@.cpp -o ../bin/$@
	@ln -fs ../bin/$@ ../bin/bin_link
	@symlinks -v ../bin

phony: run gdb

run :
	../bin/bin_link

gdb :
	gdb ../bin/bin_link
