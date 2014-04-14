#include <stdio.h>
#include <alarm_queue.h>

static AlarmQueue alarm_queue = {
	.alarm_buf = NULL,
	.alarm_list = NULL,
	.init = init_alarm_queue,
	.add = add_alarm_to_queue,
	.schedule_next = schedule_next_alarm,
	.drop_item = drop_alarm_from_queue,
	.print = print_alarm_queue,
	.delete = delete_alarm_queue
};

AlarmQueue *get_alarm_queue()
{
	return &alarm_queue;
}

static void init_alarm_queue()
{
	alarm_queue.alarm_buf = get_alarm_buf();
	alarm_queue.alarm_list = get_alarm_list();

	AlarmBuf *alarm_buf = alarm_queue.alarm_buf;

	alarm_buf->reset();
}

static int add_alarm_to_queue(Alarm *new_alarm)
{
	AlarmBuf *alarm_buf = alarm_queue.alarm_buf;
	AlarmList *alarm_list = alarm_queue.alarm_list;
	Alarm *pnew_alarm;
	if ((pnew_alarm = alarm_buf->put(new_alarm)) != NULL)
		return alarm_list->add(pnew_alarm);

	return 0;
}
static int schedule_next_alarm()
{
	AlarmList *alarm_list = alarm_queue.alarm_list;
	Alarm *alarm;

	if ((alarm = alarm_list->pop()) != NULL) {
		printf("%d ", alarm->index);
		return 1;
	}

	return 0;
}

static void drop_alarm_from_queue(int index) {}
static void print_alarm_queue()
{
	alarm_queue.alarm_list->print();
}

static void delete_alarm_queue()
{
}
