#include "eventsys.h"

void init_event_sys(Event_Sys *es) {
  es->head_event = nullptr;
}

void add_event(Event_Sys *es, Event *e) {
  e->next_event = es->head_event;
  es->head_event = e;
}

void check_events(Event_Sys *es) {
  Event *e = es->head_event;
  while (e != nullptr) {
    Trigger t = e->trigger;
    if (t.check(t.data)) {
      Action a = e->action;
      a.do_action(a.data);
    }
    e = e->next_event;
  }
}
