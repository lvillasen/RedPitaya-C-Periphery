#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "mmio.h"
int main() {
        mmio_t *mmio;
    mmio = mmio_new();
    if (mmio_open(mmio, 0x40200000, 0x4) < 0) {
        fprintf(stderr, "mmio_open(): %s\n", mmio_errmsg(mmio));
        exit(1);
    }

    mmio_write32(mmio, 0, 0x80); // Stop DAC1
    mmio_close(mmio);
    mmio_free(mmio);
    return 0;
}
