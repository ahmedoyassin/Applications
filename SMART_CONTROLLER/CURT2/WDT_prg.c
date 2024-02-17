
#include <avr/delay.h>
#include "STD_TYPES.h"
#include "bit_math.h"
#include "DIO_interface.h"
#include "WDT_private.h"


void WDT_VidEnable(){
	/*16.3 ms*/
	CLR_BIT(WDTCR_REG,0);
	CLR_BIT(WDTCR_REG,1);
	CLR_BIT(WDTCR_REG,2);

/*

	// 1.0 s
	SET_BIT(WDTCR_REG,1);
	SET_BIT(WDTCR_REG,2);
*/

	SET_BIT(WDTCR_REG,4);
	SET_BIT(WDTCR_REG,3);

}


void WDT_VidDisable(){
	WDTCR_REG= (1<<4) | (1<<3);
	WDTCR_REG=0;
}

