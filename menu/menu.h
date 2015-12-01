#ifndef MENU_H_
#define MENU_H_

#define MAX_SECTIONS 20
#define MAX_SECTION_STR 5
#define MAX_FILES 30
#define MAX_FILE_STR 20

int menu_setup(char path[]);
int menu(char path[]);
int read_sections(char sec[][MAX_SECTION_STR]);
void sort_sections_strings(char sec[][MAX_SECTION_STR], int n);
void draw_sections(char sec[][MAX_SECTION_STR], int n, int sel);
int run_sections_menu(char sec[][MAX_SECTION_STR], int n);

int read_files(char sec[][MAX_FILE_STR], char directory[]);
void sort_files_strings(char sec[][MAX_FILE_STR], int n);
void draw_files(char sec[][MAX_FILE_STR], int n, int sel);
int run_files_menu(char sec[][MAX_FILE_STR], int n, int *compile_only);

#endif

