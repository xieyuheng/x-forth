#pragma once

struct frame_t {
    size_t address;
};

frame_t *frame_new(size_t address);
void frame_destroy(frame_t **self_pointer);

value_t frame_fetch_value(frame_t *self);
uint8_t frame_fetch_byte(frame_t *self);
