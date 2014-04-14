CC = gcc
CFLAGS = \
		 -g \
		 -Iinclude \
		 -std=gnu99

SRC = \
	  src/alarm_buffer.c \
	  src/alarm_list.c \
	  src/alarm_queue.c \
	  src/alarm.c

default:
	$(CC) $(CFLAGS) $(SRC)
