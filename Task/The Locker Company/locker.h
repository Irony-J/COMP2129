#ifndef LOCKER_H
#define LOCKER_H
#include <stdint.h>

struct locker_t {
  uint16_t id;
  uint16_t user_id;
  uint8_t locked;
  uint8_t owned;
  int write_fd;
  int read_fd;
};

struct queue_t {
  struct locker_t* head;
  size_t size;
};

#endif
