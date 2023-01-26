/* Debounce Chip by Dlloydev */

#include "wokwi-api.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  pin_t pin_in;
  pin_t pin_out;
  uint32_t duration_attr;
  uint32_t duration;
  uint8_t count;
  uint8_t val;
} chip_state_t;

static void chip_timer_event(void *user_data);

void chip_init(void) {
  chip_state_t *chip = malloc(sizeof(chip_state_t));
  chip->pin_in = pin_init("IN", INPUT);
  chip->pin_out = pin_init("OUT", OUTPUT);
  chip->duration_attr = attr_init("duration", 100);

  const timer_config_t timer_config = {
    .callback = chip_timer_event,
    .user_data = chip,
  };
  timer_t timer_id = timer_init(&timer_config);
  timer_start(timer_id, 100, true);
}

static void chip_timer_event(void *user_data) {
  chip_state_t *chip = (chip_state_t*)user_data;
  if (attr_read(chip->duration_attr) != chip->duration) {
    timer_start((timer_t)0, attr_read(chip->duration_attr) / 3, true);
  }
  chip->val <<= 1;
  chip->val |= pin_read(chip->pin_in) & 1;
  if ((chip->val & 7) == 7) pin_write(chip->pin_out, HIGH);
  else if ((chip->val & 7) == 0) pin_write(chip->pin_out, LOW);
}
