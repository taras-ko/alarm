#include <stdio.h>
#include <stdlib.h>
#include <alarm_list.h>

static AlarmListItem *head = NULL;
static AlarmListItem *tail = NULL;

static AlarmList alarm_list = {
	.add = add_alarm_to_list,
	.pop = pop_alarm_from_list,
	.delete = delete_list_item,
	.print = print_alarm_list,
};

AlarmList *get_alarm_list()
{
	return &alarm_list;
}

static int add_alarm_to_list(Alarm *alarm)
{
	AlarmListItem *new = NULL;

	if ((new = malloc(sizeof(AlarmListItem))) == NULL)
		return 0;
	if ((new_alarm = malloc(sizeof(Alarm))) == NULL)
		return 0;
	else
		memcpy(new_alarm, alarm, sizeof(Alarm));

	new->alarm = new_alarm;

	if (!head) { // If there are no elements in list
		head = new;
		head->next = NULL;
		tail = head;
	} else {
		tail->next = new;
		new->next = NULL;
		tail = new;
	}

	return 1;
}

static Alarm *pop_alarm_from_list()
{
	AlarmListItem *item;
	Alarm *alarm;
	if (!head)
		return NULL;

	alarm = head->alarm;
	item = head;
	head = item->next;
	free(item->alarm);
	free(item);

	return alarm;
}

static void delete_list_item(AlarmListItem *item_to_delete)
{
	AlarmListItem *prev, *next;
	for (AlarmListItem *item = head; item && item->next; item = item->next) {
		if (item->next == item_to_delete) {
			prev = item;
			next = item_to_delete->next;
			prev->next = next;
			free(item_to_delete);
			break;
		}
	}
}

static void print_alarm_list()
{
	for (AlarmListItem *item = head; item != NULL; item = item->next)
		printf((item->next == NULL) ? "%d\n" : "%d ", item->alarm->index);
}

static void delete_list()
{
	for (AlarmListItem *item = head; item != NULL; item = item->next)
		;
}
