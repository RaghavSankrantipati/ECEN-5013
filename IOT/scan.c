#include <asf.h>
#include "platform.h"
#include "at_ble_api.h"
#include "console_serial.h"
#include "timer_hw.h"
#include "ble_manager.h"
#include "ble_utils.h"
#include "button.h"
#include "startup_template_app.h"
#define MAX_SCAN 1000
//at_ble_status_t _status;
at_ble_tx_power_level_t power;
volatile at_ble_status_t status;
volatile uint8_t scan_count = 0;
at_ble_scan_info_t scan_info[MAX_SCAN];
at_ble_status_t ble_scan_handler(void *params)
{
	at_ble_scan_info_t *scan_param;
	scan_param = (at_ble_scan_info_t *)params;
	memcpy((uint8_t *)&scan_info[scan_count], scan_param, sizeof(at_ble_scan_info_t));
	printf("RSSI is %d device address is 0x%02X%02X%02X%02X%02X%02X",scan_param->rssi,scan_param->dev_addr.addr[5],
	scan_param->dev_addr.addr[4],
	scan_param->dev_addr.addr[3],
	scan_param->dev_addr.addr[2],
	scan_param->dev_addr.addr[1],
	scan_param->dev_addr.addr[0]);
	return AT_BLE_SUCCESS;
}
static const ble_event_callback_t ble_gap_handle[] = {
	NULL,
	ble_scan_handler,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL
};

static void register_ble_callbacks (void)
{
	/* Register GAP Callbacks */
	printf("\nAssignment 3.2: Register bluetooth events callbacks");
	status = ble_mgr_events_callback_handler(REGISTER_CALL_BACK,
	BLE_GAP_EVENT_TYPE,ble_gap_handle);
	if (status != true) {
		printf("\n##Error when Registering SAMB11 gap callbacks");
	}
}
int main (void)
{
	platform_driver_init();
	acquire_sleep_lock();
	/* Initialize serial console */
	serial_console_init();
	/* Hardware timer */
	//hw_timer_init();
	printf("\n\rSAMB11 BLE Application");
	/* initialize the BLE chip and Set the Device Address */
	ble_device_init(NULL);
	register_ble_callbacks();
	/* set Beacon advertisement data */
	at_ble_scan_start(8000,1600,0x0000,AT_BLE_SCAN_ACTIVE,AT_BLE_SCAN_OBSERVER_MODE,false,false);
	printf("Assignment 3: BLE Beacon Scan Started\n");
	release_sleep_lock();
	while(true){
		ble_event_task(0xFFFFFFFF);
	}
}
