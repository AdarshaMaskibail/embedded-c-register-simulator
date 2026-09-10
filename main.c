#include <stdio.h>
#include <stdint.h>
#include "register.h"

int main(void) {
    RegisterBank regs = {0};

    printf("=== Embedded C Register Simulator ===\n");

    register_set_bit(&regs.control, CONTROL_LASER_ENABLE);
    register_set_bit(&regs.control, CONTROL_APC_ENABLE);

    register_set_field(&regs.control, CONTROL_POWER_MASK, 0x05);

    register_set_bit(&regs.status, STATUS_READY);
    register_set_bit(&regs.status, STATUS_TX_OK);

    printf("CONTROL = 0x%08X\n", regs.control);
    printf("STATUS  = 0x%08X\n", regs.status);
    printf("Laser   : %s\n",
           register_test_bit(regs.control, CONTROL_LASER_ENABLE) ? "ON" : "OFF");
    printf("APC     : %s\n",
           register_test_bit(regs.control, CONTROL_APC_ENABLE) ? "ON" : "OFF");
    printf("Power level: %u\n",
           register_get_field(regs.control, CONTROL_POWER_MASK, 0));

    register_clear_bit(&regs.control, CONTROL_APC_ENABLE);
    printf("APC after clear: %s\n",
           register_test_bit(regs.control, CONTROL_APC_ENABLE) ? "ON" : "OFF");

    return 0;
}
