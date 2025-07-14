#include "hardware.h"
#include "ti_msp_dl_config.h"

void BEEP()
{
             DL_GPIO_setPins(BUUZER_PORT,  BUUZER_PIN_1_PIN);
           DL_GPIO_setPins(LED_PORT,  LED_PIN_0_PIN);
           delay_ms(600);
           DL_GPIO_clearPins(BUUZER_PORT, BUUZER_PIN_1_PIN);
           DL_GPIO_clearPins(LED_PORT, LED_PIN_0_PIN);
}