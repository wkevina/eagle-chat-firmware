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
#include "asf.h"
#include "board.h"
#include "sram.h"
#include <avr/io.h>
#include "user_board.h"


int main (void)
{
	// Insert system clock initialization code here (sysclk_init()).
	uint8_t arrayt[12] = {"obrigadotudo"};
	uint8_t fillthis[13];
	fillthis[12]=0;//cdc_write_string funciton looking for zero 
	long int i,j;
	board_init();

	sram_init();

	cpu_irq_enable();

	irq_initialize_vectors();

	sysclk_init();

	cdc_start();
       
	//spi_init_pins();
	
        spi_init_module();
	
	while(!cdc_opened());
	while (1) {
		for (i=1 ; i<15000000 ; i++) ;
		{
			j=i;
		}
		
		write_mode(1);// 0 byte, 1 sequential, 2 page
		write_data(3,12,arrayt);//address, bytes of data, data array
		read_data(3,12,fillthis);
		cdc_write_string(fillthis);
		cdc_newline();
	//      display_read_results();
	//	uint8_t read = udi_cdc_getc();
		//if (read != 0)
			//cdc_write_string("Hello. This is quite a long string.\n");
	//	cdc_write_hex(read);
	//	cdc_write_string(" ");
	}


	// Insert application code here, after the board has been initialized.
}
