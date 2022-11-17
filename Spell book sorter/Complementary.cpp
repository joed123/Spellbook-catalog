/******************************************************
Author: Joseph Di Lullo
Date: 4/11/2021
Description: Sorts spellbooks/spells by 3 different forms and gives the option to print to screen or a file.
Input: file/screen, command line of file the information is gotten from, options to sort, option to go again.
Output: sorted spells/spellbooks to file or screen.
******************************************************/
#include <iostream> 
#include <fstream>
#include <cstdlib>
#include <string>
#include <string.h> 
#include "spellbooks.h"

using namespace std;

//Function: spellbook* create_spellbooks(int n)
//Description: creates spellbook in memory.
//Input: n (number of spellbooks)
//Output: none
spellbook* create_spellbooks(int n){
	spellbook* arr = new spellbook[n];
	return arr;
}

//Function: get_spell_data(spell* book, int n, ifstream & fin)
//Description: gets data from spells.
//Input: n (number of spellbooks), book, input file.
//Output: none
void get_spell_data(spell* book, int n, ifstream & fin){
        for (int i = 0; i < n; i++){
                fin >> book[i].name >> book[i].success_rate >> book[i].effect;
        }
}

//Function: create_spells(int n)
//Description: creates spells in memory.
//Input: n (number of spellbooks)
//Output: none
spell* create_spells(int n){
        spell* arr = new spell[n];
        return arr;
}

//Function: get_spellbook_data(spell* book, int n, ifstream & fin)
//Description: gets data from spellbooks.
//Input: n (number of spellbooks), book, input file.
//Output: none
void get_spellbook_data(spellbook* book, int n, ifstream & fin){ 
	for (int i = 0; i < n; i++){
		fin >> book[i].title >> book[i].author >> book[i].num_pages >> book[i].edition >> book[i].num_spells;
		book[i].s = create_spells(book[i].num_spells);
		get_spell_data(book[i].s, book[i].num_spells, fin);
	}
}

//Function: get_num_spellbooks(ifstream & fin)
//Description: converts the number of spellbooks from the top of the file into an int.
//Input: n (number of spellbooks)
//Output: int
int get_num_spellbooks(ifstream & fin){
	string num;
	fin >> num;
	return stoi(num);
}

//Function: sort_by_num_pages(spellbook* book, int n)
//Description: Sorts spellbooks by their number of pages.
//Input: n (number of spellbooks), book.
//Output: none
void sort_by_num_pages(spellbook* book, int n){
	int i, j;
	for (i = 0; i < n-1; i++){
		for (j = 0; j < n - i - 1; j++){
			if (book[j].num_pages > book[j + 1].num_pages){
				spellbook tmp;
				tmp = book[j];
				book[j] = book[j + 1];
				book[j + 1] = tmp;
			}
		} 
	}
}

//Function: print_num_pages(spellbook* book, int n, int file_or_screen, ofstream& fout)
//Description: Prints spellbooks by their number of pages.
//Input: n (number of spellbooks), book, file_or_screen, out file
//Output: spellbooks to screen or file.
void print_num_pages(spellbook* book, int n, int file_or_screen, ofstream& fout){
	for (int i = 0; i < n; i++){
		if (file_or_screen == 1){
			cout << book[i].title << ", " << book[i].num_pages << endl;
		}		
		else if (file_or_screen == 2){
			fout << book[i].title << ", " << book[i].num_pages << endl;
		}
	}	
}

//Function: print_avg_success_rate(spellbook* book, int n, int file_or_screen, ofstream& fout)
//Description: Prints spellbooks by their average success rate.
//Input: n (number of spellbooks), book, file_or_screen, out file
//Output: spellbooks to screen or file.
void print_avg_success_rate(spellbook* book, int n, int file_or_screen, ofstream& fout){
	for (int i = 0; i < n; i++){
        	if (file_or_screen == 1){        
			cout << book[i].title << ", " << book[i].avg_success_rate << endl;
		}
		else if (file_or_screen == 2){
                        fout << book[i].title << ", " << book[i].num_pages << endl;
                }
	}
}

//Function: sort_by_success_rate(spellbook* book, int n)
//Description: Sorts spellbooks by their success rate.
//Input: n (number of spellbooks), book.
//Output: none
void sort_by_success_rate(spellbook* book, int n){
	int i, j;
        for (i = 0; i < n-1; i++){
                for (j = 0; j < n - i - 1; j++){
                        if (book[j].avg_success_rate > book[j + 1].avg_success_rate){
                                spellbook tmp;
                                tmp = book[j];
                                book[j] = book[j + 1];
                                book[j + 1] = tmp;
                        }
                }
        }	
}

//Function: calculate_average_spell (spellbook* book, int n)
//Description: calculates spellbooks success rate by their average spell success rate.
//Input: n (number of spellbooks), book.
//Output: none
void calculate_average_spell (spellbook* book, int n){
	for (int i = 0; i < n; i++){
		float success_rate = 0;	
		for (int j = 0; j < book[i].num_spells; j++){
			success_rate = success_rate + book[i].s[j].success_rate;
		}
		book[i].avg_success_rate = success_rate / book[i].num_spells;
	}
}

//Function: sort_by_effect (spellbook* book, int n, int file_or_screen, ofstream& fout)
//Description: Sorts then prints spellbooks by effect.
//Input: n (number of spellbooks), book, file_or_screen, out file
//Output: spellbooks to screen or file.
void sort_by_effect (spellbook* book, int n, int file_or_screen, ofstream& fout){
int i, j, h, y, k, t, q;
        for (i = 0; i < n; i++){
                for (j = 0; j < book[i]. num_spells; j++){
			if (book[i].s[j].effect == "bubble"){
				if (file_or_screen == 1){
					cout << book[i].s[j].name << ", " << book[i].s[j].effect << endl;
				}
				else if (file_or_screen == 2){
                        		fout << book[i].s[j].name << ", " << book[i].s[j].effect << endl;
                		}
			}	
		}
	}
	for (i = 0; i < n; i++){
		for (j = 0; j < book[i]. num_spells; j++){
                        if (book[i].s[j].effect == "memory_loss"){
				if (file_or_screen == 1){
                                        cout << book[i].s[j].name << ", " << book[i].s[j].effect << endl;
                                }
                                else if (file_or_screen == 2){
                                        fout << book[i].s[j].name << ", " << book[i].s[j].effect << endl;
                                }
			}
		}
	}
	for (i = 0; i < n; i++){
		for (j = 0; j < book[i]. num_spells; j++){
                        if (book[i].s[j].effect == "fire"){
                                if (file_or_screen == 1){
                                        cout << book[i].s[j].name << ", " << book[i].s[j].effect << endl;
                                }
                                else if (file_or_screen == 2){
                                        fout << book[i].s[j].name << ", " << book[i].s[j].effect << endl;
                                }
			}
		}
	}
	for (i = 0; i < n; i++){
		for (j = 0; j < book[i]. num_spells; j++){
                        if (book[i].s[j].effect == "poison"){
                                if (file_or_screen == 1){
                                        cout << book[i].s[j].name << ", " << book[i].s[j].effect << endl;
                                }
                                else if (file_or_screen == 2){
                                        fout << book[i].s[j].name << ", " << book[i].s[j].effect << endl;
				}
			}
		}
	}
	for (i = 0; i < n; i++){
		 for (j = 0; j < book[i]. num_spells; j++){
                        if (book[i].s[j].effect == "death"){
                                if (file_or_screen == 1){
                                        cout << book[i].s[j].name << ", " << book[i].s[j].effect << endl;
                                }
                                else if (file_or_screen == 2){
                                        fout << book[i].s[j].name << ", " << book[i].s[j].effect << endl;
                                }
			}
		}
	}
}

//Function: delete_spellbook_data(spellbook* book, int n)
//Description: Deletes memory allocated for spellbooks and spells.
//Input: n (number of spellbooks), book
//Output: none
void delete_spellbook_data(spellbook* book, int n){
	for (int i = 0; i < n; i++){
	delete [] book[i].s;
	book[i].s = NULL;
}
	delete [] book;
	book = NULL;
}
