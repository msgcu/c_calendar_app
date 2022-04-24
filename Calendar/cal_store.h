#pragma once
#include <stdbool.h>

typedef struct {
	int priority;
	bool isAllDay;
	char name[64];
} cal_metadata_t;

typedef union {
	cal_metadata_t meta;
	char notes[128];
} cal_notes_t;

typedef struct {
	int id;
	int day;
	int month;
	int year;
	bool isFreeNote;
	cal_notes_t notes;
	bool isSet;
} cal_entry_t;

void init_calendar_store(void);
bool add_calendar_entry_freenote(int day, int month, int year, char* notes);
bool add_calendar_entry_meta(int day, int month, int year, int priority, bool isAllDay, char *name);
void print_calendar_entries(void);
bool remove_calendar_entry(int id);