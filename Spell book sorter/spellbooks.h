/*****************************************************
 * File: spellbooks.h
 * Author: Joseph Di Lullo
 * Date: 4/11/2021
 * Description: Sorts spellbooks/spells by 3 different forms and gives the option to print to screen or a file.
 * Input: file/screen, command line of file the information is gotten from, options to sort, option to go again.
 * Output: sorted spells/spellbooks to file or screen.
******************************************************/

#ifndef SPELLBOOKS_H
#define SPELLBOOKS_H
#include <fstream>
#include <string>
#include <cstdlib>
#include <string.h>
#include <iostream>

using namespace std;

struct spell {
        string name;
        float success_rate;
        string effect;
};

struct spellbook {
	string title;
	string author;
	int num_pages;
	int edition;
	int num_spells;
	float avg_success_rate;
	struct spell* s;
};

int get_num_spellbooks(ifstream &);
void get_spellbook_data(spellbook*, int, ifstream &);
void sort_by_num_pages(spellbook*, int);



spellbook* create_spellbooks(int);
int get_num_spellbooks(ifstream &);
void get_spellbook_data(spellbook*, int, ifstream &);
void sort_by_num_pages(spellbook*, int);
void print_num_pages(spellbook*, int, int, ofstream&); 
spell* create_spells(int);
void get_spell_data(spell*, int, ifstream &); 
void sort_by_success_rate(spellbook*, int);
void calculate_average_spell(spellbook*, int);
void print_avg_success_rate(spellbook*, int, int, ofstream&);
void sort_by_effect (spellbook*, int, int, ofstream&);
void delete_spellbook_data(spellbook*, int);

#endif
