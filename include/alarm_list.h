#ifndef ALARM_LIST_H
#define ALARM_LIST_H
#include <alarm_buffer.h>
typedef struct alarm_list_item {
	Alarm *alarm;
	struct alarm_list_item *next;
} AlarmListItem;

typedef struct alarm_list {
	int (*add)(Alarm *);
	Alarm *(*pop)();
	void (*remove)(int);
	void (*print)();
	void (*delete)();
} AlarmList;

static int add_alarm_to_list(Alarm *);
static Alarm *pop_alarm_from_list();
static void delete_list_item(AlarmListItem *);
static void print_alarm_list();
static void delete_list();

AlarmList *get_alarm_list();

#endif //ALARM_LIST_H
