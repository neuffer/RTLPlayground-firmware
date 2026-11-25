/*
 * The RTL8238C driver's second PSE image, read from BANK4.
 *
 * The stock firmware carries two PSE images and sends the 21164-byte one
 * when the chip's register 0xe8 does not read 2 (see rtl8238c.c). It does not
 * fit into BANK3 next to the driver and the 8028-byte image, so
 * tools/poe_extract generates it as poe_firmware_b in BANK4, and the driver,
 * which runs in BANK3, reads it through these banked functions: a constant
 * can only be read while its own bank is mapped.
 */
#pragma codeseg BANK4
#pragma constseg BANK4

#include <stdint.h>
#include "rtl8238c.h"

extern __code const uint8_t poe_firmware_b[];
extern __code const uint16_t poe_firmware_b_len;

uint16_t poe_image_b_len(void) __banked
{
	return poe_firmware_b_len;
}

uint8_t poe_image_b_byte(uint16_t i) __banked
{
	return poe_firmware_b[i];
}
