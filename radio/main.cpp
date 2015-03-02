/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
 /**
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

extern "C" {
	#include "asf.h"
	#include <avr/io.h>
	#include "cdc.h"
}

#include "RFM69.h"

// void spi_init_pins(void);
// void spi_init_pins(void)
// {
//     ioport_configure_port_pin(&PORTE, PIN4_bm, IOPORT_INIT_HIGH | IOPORT_DIR_OUTPUT); 	//Set the pin used for slave select as output high
// 	//Pin is set, though not needed to change
//     ioport_configure_port_pin(&PORTE, PIN1_bm, IOPORT_PULL_UP | IOPORT_DIR_INPUT);	//Enable pull-up on own chip select (SS):
//     ioport_configure_port_pin(&PORTE, PIN5_bm, IOPORT_INIT_HIGH | IOPORT_DIR_OUTPUT);	//Set MOSI as output high
//     ioport_configure_port_pin(&PORTE, PIN6_bm, IOPORT_DIR_INPUT);						//Set MISO as input
//     ioport_configure_port_pin(&PORTE, PIN7_bm, IOPORT_INIT_HIGH | IOPORT_DIR_OUTPUT);	//Set SCL as output high
// }

// void spi_init_module(void);
// void spi_init_module(void)
// {
//    struct spi_device spi_device_conf = {
//        .id = IOPORT_CREATE_PIN(PORTE, 4)
//    };
//    spi_master_init(&SPIE);
//    spi_master_setup_device(&SPIE, &spi_device_conf, SPI_MODE_0, 1000000, 0);
//    spi_enable(&SPID);
// }

RFM69 module;

int main (void)
{
	// Insert system clock initialization code here (sysclk_init()).

	cpu_irq_enable();

	irq_initialize_vectors();

	sysclk_init();

	cdc_start();

	// spi_init_module();
	// spi_init_pins();

	// uint8_t data_buffer[1] = {0xAA};

	// struct spi_device spi_device_conf = {
	// 	.id = IOPORT_CREATE_PIN(PORTE, 4)
	// };

	// spi_select_device(&SPIE, &spi_device_conf);

	// spi_write_packet(&SPIE, data_buffer, 1);
	// spi_read_packet(&SPIE, data_buffer, 1);

	// spi_deselect_device(&SPIE, &spi_device_conf);

	module = RFM69();


}
