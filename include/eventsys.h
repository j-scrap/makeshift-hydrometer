#ifndef EVENTSYS_H
#define EVENTSYS_H

typedef struct Trigger {
  bool (*check)(void*);
  void *data;
} Trigger;

typedef struct Action {
  void (*do_action)(void*);
  void *data;
} Action;

typedef struct Event {
  Trigger trigger;
  Action action;
  struct Event *next_event;
} Event;

typedef struct Event_Sys {
  Event *head_event;
} Event_Sys;

void init_event_sys(Event_Sys *es);
void add_event(Event_Sys *es, Event *event);
void check_events(Event_Sys *es);

#endif /* EVENTSYS_H */
