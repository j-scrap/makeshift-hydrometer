#ifndef PER_MILLISECONDS_H
#define PER_MILLISECONDS_H

typedef struct Per_Time_Data {
  unsigned long last_time;
  unsigned long interval;
} Per_Time_Data;

bool per_milliseconds(void *lt);

#endif /* PER_MILLISECONDS_H */
