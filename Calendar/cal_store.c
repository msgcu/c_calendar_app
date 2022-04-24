#include <stdio.h>
#include <string.h>
#include "cal_store.h"

#define STORE_SIZE 10

cal_entry_t calendar_store[STORE_SIZE];

void init_calendar_store(void)
{
	// Default all calendar entries to not set
	for (int i = 0; i < STORE_SIZE; i++)
	{
		calendar_store[i].id = i;
		calendar_store[i].isSet = false;
	}
}

bool add_calendar_entry_freenote(int day, int month, int year, char* notes)
{
	bool didSet = false;

	for (int i = 0; i < STORE_SIZE; i++)
	{
		// Find an unset calendar entry in the store
		if (calendar_store[i].isSet == false)
		{
			// Save calendar entry details into the store and set isSet = true
			calendar_store[i].day = day;
			calendar_store[i].month = month;
			calendar_store[i].year = year;
			calendar_store[i].isFreeNote = true;
			memcpy((void*)calendar_store[i].notes.notes, (void*)notes, 128);
			calendar_store[i].isSet = true;
			
			// Exit the loop early since data was saved
			didSet = true;
			break;
		}
	}

	return didSet; // Return if entry was set or calendar store is full
}

bool add_calendar_entry_meta(int day, int month, int year, int priority, bool isAllDay, char* name)
{
	bool didSet = false;

	for (int i = 0; i < STORE_SIZE; i++)
	{
		// Find an unset calendar entry in the store
		if (calendar_store[i].isSet == false)
		{
			// Save calendar entry details into the store and set isSet = true
			calendar_store[i].isSet = true;
			calendar_store[i].day = day;
			calendar_store[i].month = month;
			calendar_store[i].year = year;

			calendar_store[i].isFreeNote = false;
			calendar_store[i].notes.meta.priority = priority;
			calendar_store[i].notes.meta.isAllDay = isAllDay;
			memcpy((void*)calendar_store[i].notes.meta.name, (void*)name, 64);

			// Exit the loop early since data was saved
			didSet = true;
			break;
		}
	}

	return didSet; // Return if entry was set or calendar store is full
}

void print_calendar_entries(void)
{
	bool didPrint = false;

	for (int i = 0; i < STORE_SIZE; i++)
	{
		// Only print set calendar entries
		if (calendar_store[i].isSet == true)
		{
			printf("Calendar Entry ID %d\n", calendar_store[i].id);
			printf("\tDate: %d/%d/%d\n", calendar_store[i].month, calendar_store[i].day, calendar_store[i].year);

			if (calendar_store[i].isFreeNote)
			{
				printf("\tNotes: %s\n\n", calendar_store[i].notes.notes);
			}
			else
			{
				printf("\tAppointment name: %s\n", calendar_store[i].notes.meta.name);
				printf("\tPriority: %d\n", calendar_store[i].notes.meta.priority);
				printf("\tIsAllDay: %s\n", calendar_store[i].notes.meta.isAllDay ? "yes" : "no");
			}

			didPrint = true;
		}
	}

	if (!didPrint)
	{
		printf("There are no saved calendar entries\n");
	}
}

bool remove_calendar_entry(int id)
{
	if (id >= 0 && id < STORE_SIZE)
	{
		calendar_store[id].isSet = false;
		return true;
	}

	return false;
}