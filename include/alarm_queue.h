#ifndef ALARM_QUEUE_H
#define ALARM_QUEUE_H
#include <alarm_buffer.h>
#include <alarm_list.h>

typedef struct alarm_queue{
	AlarmBuf *alarm_buf;
	AlarmList *alarm_list;
	void (*init)();
	int (*add)(Alarm *);
	int (*schedule_next)();
	void (*drop_item)(int);
	void (*print)();
	void (*delete)();
} AlarmQueue;

static void init_alarm_queue();
static int add_alarm_to_queue(Alarm *);
static int schedule_next_alarm();
static void drop_alarm_from_queue(int);
static void print_alarm_queue();
static void delete_alarm_queue();

AlarmQueue *get_alarm_queue();

#endif //ALARM_QUEUE_H
