#ifndef ALARM_BUFFER_H
#define ALARM_BUFFER_H
typedef struct {
	int index;
} Alarm;

#define BUF_SZ 3
typedef struct alarm_buf {
	void (*reset)();
	Alarm *(*put)(Alarm *);
	void (*get)();
	void (*delete)();
} AlarmBuf;

static void reset_alarm_buffer();
static Alarm *put_alarm(Alarm *);
static void get_alarm();
static void delete_alarm(Alarm *);

AlarmBuf *get_alarm_buf();

#endif //ALARM_BUFFER_H
