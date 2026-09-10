#include "register.h"

void register_set_bit(uint32_t *reg, uint8_t bit) {
    *reg |= (1u << bit);
}

void register_clear_bit(uint32_t *reg, uint8_t bit) {
    *reg &= ~(1u << bit);
}

int register_test_bit(uint32_t reg, uint8_t bit) {
    return (reg & (1u << bit)) != 0u;
}

void register_set_field(uint32_t *reg, uint32_t mask, uint32_t value) {
    uint8_t shift = 0;
    while (((mask >> shift) & 1u) == 0u && shift < 32u) {
        shift++;
    }
    *reg = (*reg & ~mask) | ((value << shift) & mask);
}

uint32_t register_get_field(uint32_t reg, uint32_t mask, uint8_t shift) {
    return (reg & mask) >> shift;
}
