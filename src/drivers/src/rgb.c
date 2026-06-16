/*==================================================================================================
 * Project : RTD AUTOSAR 4.9
 * Platform : CORTEXM
 * Peripheral : S32K3XX
 * Dependencies : none
 *
 * Autosar Version : 4.9.0
 * Autosar Revision : ASR_REL_4_9_REV_0000
 * Autosar Conf.Variant :
 * SW Version : 7.0.0
 * Build Version : S32K3_RTD_7_0_0_QLP03_D2512_ASR_REL_4_9_REV_0000_20251210
 *
 * Copyright 2020 - 2026 NXP
 *
 *   NXP Proprietary. This software is owned or controlled by NXP and may only be
 *   used strictly in accordance with the applicable license terms. By expressly
 *   accepting such terms or by downloading, installing, activating and/or otherwise
 *   using the software, you are agreeing that you have read, and that you agree to
 *   comply with and are bound by, such license terms. If you do not agree to be
 *   bound by the applicable license terms, then you may not retain, install,
 *   activate or otherwise use the software.
==================================================================================================*/

#include "rgb.h"

void rgb_init_leds(void){
	/* Turn RED LED OFF */
	rgb_turn_off_led(LED_RED);

	/* Turn GREEN LED OFF */
	rgb_turn_off_led(LED_GREEN);

	/* Turn BLUE LED OFF */
	rgb_turn_off_led(LED_BLUE);
}

void rgb_turn_on_led(RGB_t color){
	switch(color)
	{
	case LED_RED :
		Siul2_Dio_Ip_WritePin(RGB_RED_LED_PORT, RGB_RED_LED_PIN, 1U);
		break;

	case LED_GREEN :
		Siul2_Dio_Ip_WritePin(RGB_GREEN_LED_PORT, RGB_GREEN_LED_PIN, 1U);
		break;

	case LED_BLUE :
		Siul2_Dio_Ip_WritePin(RGB_BLUE_LED_PORT, RGB_BLUE_LED_PIN, 1U);
		break;

	default:
		break;
	}
}

void rgb_turn_off_led(RGB_t color){
	switch(color)
	{
	case LED_RED :
		Siul2_Dio_Ip_WritePin(RGB_RED_LED_PORT, RGB_RED_LED_PIN, 0U);
		break;

	case LED_GREEN :
		Siul2_Dio_Ip_WritePin(RGB_GREEN_LED_PORT, RGB_GREEN_LED_PIN, 0U);
		break;

	case LED_BLUE :
		Siul2_Dio_Ip_WritePin(RGB_BLUE_LED_PORT, RGB_BLUE_LED_PIN, 0U);
		break;

	default:
		break;
	}
}

void rgb_set_color(color_t color){
	switch(color)
	{
	case COLOR_OFF :
		/* RED LED */
		Siul2_Dio_Ip_WritePin(RGB_RED_LED_PORT, RGB_RED_LED_PIN, 0U);
		/* GREEN LED */
		Siul2_Dio_Ip_WritePin(RGB_GREEN_LED_PORT, RGB_GREEN_LED_PIN, 0U);
		/* BLUE LED */
		Siul2_Dio_Ip_WritePin(RGB_BLUE_LED_PORT, RGB_BLUE_LED_PIN, 0U);
		break;

	case COLOR_RED :
		/* RED LED */
		Siul2_Dio_Ip_WritePin(RGB_RED_LED_PORT, RGB_RED_LED_PIN, 1U);
		/* GREEN LED */
		Siul2_Dio_Ip_WritePin(RGB_GREEN_LED_PORT, RGB_GREEN_LED_PIN, 0U);
		/* BLUE LED */
		Siul2_Dio_Ip_WritePin(RGB_BLUE_LED_PORT, RGB_BLUE_LED_PIN, 0U);
		break;

	case COLOR_GREEN :
		/* RED LED */
		Siul2_Dio_Ip_WritePin(RGB_RED_LED_PORT, RGB_RED_LED_PIN, 0U);
		/* GREEN LED */
		Siul2_Dio_Ip_WritePin(RGB_GREEN_LED_PORT, RGB_GREEN_LED_PIN, 1U);
		/* BLUE LED */
		Siul2_Dio_Ip_WritePin(RGB_BLUE_LED_PORT, RGB_BLUE_LED_PIN, 0U);
		break;

	case COLOR_YELLOW :
		/* RED LED */
		Siul2_Dio_Ip_WritePin(RGB_RED_LED_PORT, RGB_RED_LED_PIN, 1U);
		/* GREEN LED */
		Siul2_Dio_Ip_WritePin(RGB_GREEN_LED_PORT, RGB_GREEN_LED_PIN, 1U);
		/* BLUE LED */
		Siul2_Dio_Ip_WritePin(RGB_BLUE_LED_PORT, RGB_BLUE_LED_PIN, 0U);
		break;

	case COLOR_BLUE :
		/* RED LED */
		Siul2_Dio_Ip_WritePin(RGB_RED_LED_PORT, RGB_RED_LED_PIN, 0U);
		/* GREEN LED */
		Siul2_Dio_Ip_WritePin(RGB_GREEN_LED_PORT, RGB_GREEN_LED_PIN, 0U);
		/* BLUE LED */
		Siul2_Dio_Ip_WritePin(RGB_BLUE_LED_PORT, RGB_BLUE_LED_PIN, 1U);
		break;

	case COLOR_MAGENTA :
		/* RED LED */
		Siul2_Dio_Ip_WritePin(RGB_RED_LED_PORT, RGB_RED_LED_PIN, 1U);
		/* GREEN LED */
		Siul2_Dio_Ip_WritePin(RGB_GREEN_LED_PORT, RGB_GREEN_LED_PIN, 0U);
		/* BLUE LED */
		Siul2_Dio_Ip_WritePin(RGB_BLUE_LED_PORT, RGB_BLUE_LED_PIN, 1U);
		break;

	case COLOR_CYAN :
		/* RED LED */
		Siul2_Dio_Ip_WritePin(RGB_RED_LED_PORT, RGB_RED_LED_PIN, 0U);
		/* GREEN LED */
		Siul2_Dio_Ip_WritePin(RGB_GREEN_LED_PORT, RGB_GREEN_LED_PIN, 1U);
		/* BLUE LED */
		Siul2_Dio_Ip_WritePin(RGB_BLUE_LED_PORT, RGB_BLUE_LED_PIN, 1U);
		break;

	case COLOR_WHITE :
		/* RED LED */
		Siul2_Dio_Ip_WritePin(RGB_RED_LED_PORT, RGB_RED_LED_PIN, 1U);
		/* GREEN LED */
		Siul2_Dio_Ip_WritePin(RGB_GREEN_LED_PORT, RGB_GREEN_LED_PIN, 1U);
		/* BLUE LED */
		Siul2_Dio_Ip_WritePin(RGB_BLUE_LED_PORT, RGB_BLUE_LED_PIN, 1U);
		break;

	default:
		/* RED LED */
		Siul2_Dio_Ip_WritePin(RGB_RED_LED_PORT, RGB_RED_LED_PIN, 0U);
		/* GREEN LED */
		Siul2_Dio_Ip_WritePin(RGB_GREEN_LED_PORT, RGB_GREEN_LED_PIN, 0U);
		/* BLUE LED */
		Siul2_Dio_Ip_WritePin(RGB_BLUE_LED_PORT, RGB_BLUE_LED_PIN, 0U);
		break;
	}
}




