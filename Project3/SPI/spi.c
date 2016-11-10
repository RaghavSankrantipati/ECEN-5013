#include "MKL25Z4.h"
#include "spi.h"
#include "nrf24.h"

void main(void)
{
	uint8_t rx_data[6]={0};
	uint8_t write_data[32] = {0x03, 0xe6, 0xe7, 0xe4, 0xe8};
	uint8_t read_data[5], address_read = 0;
	uint8_t *write_ptr = write_data;
	uint8_t *read_ptr = address_read;
	uint8_t length = 1;

	spi_init();


	NRF_CS_DISABLE();

	nrf_write(W_REGISTER|CONFIG, write_ptr, 1);
	nrf_read(R_REGISTER|CONFIG, read_ptr, 1);

//	nRF_write_tx_payload(write_ptr);
//
//	nrf_read(R_REGISTER|FIFO_STATUS, read_ptr, length);
//
//	nrf_flush_tx();
//
//	nrf_read(R_REGISTER|FIFO_STATUS, read_ptr, length);

	NRF_CS_ENABLE();
	uint8_t a = nrf_dummy();
	NRF_CS_DISABLE();

}

