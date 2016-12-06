#include "MKL25Z4.h"



// Initiate a touch scan on the given channel
inline static void TSI_Start(int channel)
{
    TSI0_DATA = TSI_DATA_TSICH(channel) | TSI_DATA_SWTS_MASK;
}

// Return scan data for most recent scan
inline static uint16_t TSI_Stop(void)
{
    TSI0_GENCS |= TSI_GENCS_EOSF_MASK;
    return TSI0_DATA & TSI_DATA_TSICNT_MASK;
}

// Initialize touch input
void TSI_Init(void)
{

    SIM_SCGC5 |= SIM_SCGC5_TSI_MASK | SIM_SCGC5_PORTB_MASK;
    TSI0_GENCS |= (//TSI_GENCS_ESOR_MASK          // Enable end of scan interrupt
                   TSI_GENCS_MODE(0)          // Capactive sensing
                   | TSI_GENCS_REFCHRG(4)       // Reference charge 4 uA
                   | TSI_GENCS_DVOLT(0)         // Voltage rails
                   | TSI_GENCS_EXTCHRG(7)       // External osc charge
                   | TSI_GENCS_PS(4)            // Prescalar divide by 4
                   | TSI_GENCS_NSCN(11)         // Scans per electrode
                  // | TSI_GENCS_TSIIEN_MASK      // Input interrupt enable
                   | TSI_GENCS_STPE_MASK        // Enable in STOP mode
                   );

    TSI0_GENCS |= TSI_GENCS_TSIEN_MASK;


    PORTB_PCR16 = PORT_PCR_MUX(0);      // PTB16 as touch channel 9
    PORTB_PCR17 = PORT_PCR_MUX(0);      // PTB17 as touch channel 10

}

void main(void)
{
	TSI_Init();
    while(1)
	{
    	uint16_t count;
    	int k;
    	TSI_Start(9);
        while(!(TSI0_GENCS & TSI_GENCS_EOSF_MASK));
        count = TSI_Stop();
        count=count;
        if(count>2000)
        {
           k=20;
        }


	}

}
