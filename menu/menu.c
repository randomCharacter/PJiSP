#include <string.h>
#include <ncurses.h>
#include <dirent.h>

#include "menu.h"

int menu_setup(char path[]) {
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(FALSE);
	clear();

	int compile_only=menu(path);
	
	endwin();
	return compile_only;
}

int menu(char path[]) {
	char sec[MAX_SECTIONS][MAX_SECTION_STR];
	char fil[MAX_FILES][MAX_FILE_STR];
	char sec_dir[MAX_FILE_STR];
	int n;
	int sel=0;
	int compile_only=0;

	do {
		clear();
		n=read_sections(sec);
		sort_sections_strings(sec, n);

		sel=run_sections_menu(sec, n);
		if(sel==-1) {
			endwin();
			return compile_only;
		}

		clear();
		strcpy(sec_dir, "");
		strcat(sec_dir,"../");
		strcat(sec_dir, sec[sel]);

		n=read_files(fil, sec_dir);
		sort_files_strings(fil, n);
		sel=run_files_menu(fil,n, &compile_only);
	} while(sel==-1);

	//char file[MAX_SECTION_STR+MAX_FILE_STR];
	strcpy(path, "");
	strcat(path, sec_dir);
	strcat(path, "/");
	strcat(path, fil[sel]);
	mvprintw(1,1, "Selected file: %s", path);
	refresh();
	//while(1);
	return compile_only;
}

int read_sections(char sec[][MAX_SECTION_STR]) {
	DIR *dir;
	struct dirent *ent;
	int n=0;
	if ((dir = opendir ("../")) != NULL) {
		while ((ent = readdir (dir)) != NULL) {
			if(strstr(ent->d_name,"v")==ent->d_name) {
				strcpy(sec[n++],ent->d_name);
			}
		}
		closedir (dir);
	} else
		return -1;
	return n;
}

void sort_sections_strings(char str[][MAX_SECTION_STR], int n) {
	int i,j;
	char tmp[MAX_SECTION_STR];
	for(i = 0; i < n; i++) {
		for(j = i+1; j < n; j++) {
			if(strcmp(str[i],str[j]) > 0) {
				strcpy(tmp, str[i]);
				strcpy(str[i], str[j]);
				strcpy(str[j], tmp);
			}
		}
	}
}

void draw_sections(char sec[][MAX_SECTION_STR], int n, int selected) {
	int x=2, y=2, i;
	mvprintw(y++, x, "Select a section:");
	for(i = 0; i < n; i++) {
		if(i==selected)
			attron(A_STANDOUT);
		mvprintw(y++, x, "%s", sec[i]);
		attroff(A_STANDOUT);
	}
	mvprintw(++y, x, "q za izlazak");
	refresh();
}

int run_sections_menu(char sec[][MAX_SECTION_STR], int max_sel) {
	int sel=0, back=0;

	do {
		draw_sections(sec, max_sel, sel);
		//refresh();
		int c=getch();

		if(c == KEY_UP && sel > 0) {
			sel--;
		} else if(c==KEY_DOWN && sel < max_sel-1) {
			sel++;
		} else if(c==10) {
			return sel;
		} else if(c=='q') {
			back=1;
		}
	} while(back == 0);
	return -1;
}

int read_files(char fil[][MAX_FILE_STR], char directory[]) {
	DIR *dir;
	struct dirent *ent;
	int n=0;
	if ((dir = opendir (directory)) != NULL) {
		while ((ent = readdir (dir)) != NULL) {
			if(strstr(ent->d_name,".c") != NULL) {
				strcpy(fil[n++],ent->d_name);
			}
		}
		closedir (dir);
	} else
		return -1;
	return n;
}

void sort_files_strings(char str[][MAX_FILE_STR], int n) {
	int i,j;
	char tmp[MAX_FILE_STR];
	for(i = 0; i < n; i++) {
		for(j = i+1; j < n; j++) {
			if(strcmp(str[i],str[j]) > 0) {
				strcpy(tmp, str[i]);
				strcpy(str[i], str[j]);
				strcpy(str[j], tmp);
			}
		}
	}
}

void draw_files(char fil[][MAX_FILE_STR], int n, int selected) {
	int x=2, y=2, i;
	mvprintw(y++, x, "Select a file:");
	for(i = 0; i < n; i++) {
		if(i==selected)
			attron(A_STANDOUT);
		mvprintw(y++, x, "%s", fil[i]);
		attroff(A_STANDOUT);
	}
	mvprintw(++y, x, "c za kompajliranje fajla, bez pokretanja");
	mvprintw(++y, x, "q za nazad");
	refresh();
}

int run_files_menu(char fil[][MAX_FILE_STR], int max_sel, int *compile_only) {
	int sel=0, back=0;

	do {
		draw_files(fil, max_sel, sel);
		//refresh();
		int c=getch();

		if(c == KEY_UP && sel > 0) {
			sel--;
		} else if(c == KEY_DOWN && sel < max_sel-1) {
			sel++;
		} else if(c == 10) {
			return sel;
		} else if(c == 'q') {
			back=1;
		} else if(c == 'c') {
			*compile_only=1;
			return sel;
		}
	} while(back == 0);
	return -1;
}

