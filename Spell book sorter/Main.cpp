/******************************************************
 * ** Author: Joseph Di Lullo
 * ** Date: 4/11/2021
 * ** Description: Sorts spellbooks/spells by 3 different forms and gives the option to print to screen or a file. 
 * ** Input: file/screen, command line of file the information is gotten from, options to sort, option to go again.
 * ** Output: sorted spells/spellbooks to file or screen.
 * ******************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstdlib>
#include "spellbooks.h"

using namespace std;

main(int argc, char *argv[]){
	string file = argv[1];
	if ((argc != 2) or (file != "spellbooks.txt")){
		cout << "Invlaid command line argument!" << endl;
		return 1; 	
	}
	ifstream fin;
	fin.open(file);
	if(!fin.is_open()){
		cout << "Error opening file!" << endl;
		return 1;
	}
	ofstream fout;
	int l = 0;
	int file_or_screen;
	string file_name;
	while (l == 0){
		cout << "would you like to write to a file or print to screen? (1 for screen, 2 for file)" << endl;
		cin >> file_or_screen;
		if (file_or_screen == 1){
			l = 1;
		}
		else if (file_or_screen == 2){	
			cout << "What would you like to name the file that the information will be added too? " << endl;
        		cin >> file_name;
			fout.open (file_name,ios::app);
			l = 1;
		}
	}
	int number_spellbooks;
	number_spellbooks = get_num_spellbooks(fin);
	spellbook* book = create_spellbooks(number_spellbooks);
	get_spellbook_data(book, number_spellbooks, fin);
	int k = 0;
	while (k != 4){
		cout << "Would you like to sort by number of pages, effect, success rate, or quit? (1 for pages, 2 for effect, 3 for average success rate, 4 to quit)" << endl;
		cin >> k;
		if (k == 1){
			sort_by_num_pages(book, number_spellbooks);
			print_num_pages(book, number_spellbooks, file_or_screen, fout);
		}
		else if (k == 2){
			sort_by_effect (book, number_spellbooks, file_or_screen, fout);
		}
		else if (k == 3){
			calculate_average_spell (book, number_spellbooks);
			sort_by_success_rate (book, number_spellbooks);
			print_avg_success_rate (book, number_spellbooks, file_or_screen, fout);
		}
		else if (k == 4) {
			return 1;
		}
		else {
			cout << "Invalid input try again!" << endl;
		}  
	}
	fin.close();
	fout.close();
	delete_spellbook_data(book, number_spellbooks);
	return 0;
}

