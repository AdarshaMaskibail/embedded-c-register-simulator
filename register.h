#ifndef REGISTER_H
#define REGISTER_H

#include <stdint.h>

typedef struct {
    uint32_t control;
    uint32_t status;
} RegisterBank;

#define CONTROL_LASER_ENABLE  0
#define CONTROL_APC_ENABLE    1
#define CONTROL_POWER_MASK    0x000000F0u

#define STATUS_READY           0
#define STATUS_TX_OK           1

void register_set_bit(uint32_t *reg, uint8_t bit);
void register_clear_bit(uint32_t *reg, uint8_t bit);
int register_test_bit(uint32_t reg, uint8_t bit);
void register_set_field(uint32_t *reg, uint32_t mask, uint32_t value);
uint32_t register_get_field(uint32_t reg, uint32_t mask, uint8_t shift);

#endif
