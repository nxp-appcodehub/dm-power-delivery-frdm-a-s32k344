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

#include "ptn5110.h"

uint8_t array_ADD_PTN5110_Tx[LIMIT_PTN5110] = {0x00, 0x00, 0x00, 0x00, 0x00};
uint8_t array_ADD_PTN5110_Rx[LIMIT_PTN5110] = {0x02, 0x00, 0x00, 0x00, 0x00};

pd_source_pdo_t array_source_pdos[MAX_OBJECTS_PTN5110];
uint8_t number_pdo_source;
info_PTN5110_t config_PTN5110;

#if (USE_BAREMETAL_I2C == 0U)
Lpi2c_Ip_StatusType status_I2C;
#endif

/**
*   This section corresponds the read of byte, word (2 bytes) or a block
*/
/* I2C, read byte */
static uint8_t Reg_BusReadByte(uint8_t reg){
#if (USE_BAREMETAL_I2C == 0U)
	PD_I2cReadBlocking(config_PTN5110.instance_i2c, config_PTN5110.address, reg, array_ADD_PTN5110_Rx, 1U);
#else
	i2cReadBlocking(config_PTN5110.instance_i2c, config_PTN5110.address, reg, array_ADD_PTN5110_Rx, 1U);
#endif
	return array_ADD_PTN5110_Rx[0];
}

/* I2C, read word */
static uint16_t Reg_BusReadWord(uint8_t reg){
#if (USE_BAREMETAL_I2C == 0U)
	PD_I2cReadBlocking(config_PTN5110.instance_i2c, config_PTN5110.address, reg, array_ADD_PTN5110_Rx, 2U);
#else
	i2cReadBlocking(config_PTN5110.instance_i2c, config_PTN5110.address, reg, array_ADD_PTN5110_Rx, 2U);
#endif
	uint16_t aux = (uint16_t) array_ADD_PTN5110_Rx[0];
	uint16_t data = (uint16_t) array_ADD_PTN5110_Rx[1];

	data = (data << SHIFT_8_BITS_PTN5110) | aux;
	return data;
}

/* I2C, read word */
static void Reg_BusReadBlock(uint8_t reg, uint8_t length, uint8_t* dst){

#if (USE_BAREMETAL_I2C == 0U)
	PD_I2cReadBlocking(config_PTN5110.instance_i2c, config_PTN5110.address, reg, dst, length);
#else
	i2cReadBlocking(config_PTN5110.instance_i2c, config_PTN5110.address, reg, dst, length);
#endif
}

/**
*   This section corresponds the write of byte, word (2 bytes) or a block
*/
/* I2C, write byte */
static void Reg_BusWriteByte(uint8_t reg, uint8_t byteData){
	array_ADD_PTN5110_Tx[0] = byteData;

#if (USE_BAREMETAL_I2C == 0U)
	PD_I2cWriteBlocking(config_PTN5110.instance_i2c, config_PTN5110.address, reg, array_ADD_PTN5110_Tx, 1U);
#else
	i2cWriteBlocking(config_PTN5110.instance_i2c, config_PTN5110.address, reg, array_ADD_PTN5110_Tx, 1U);
#endif
}

/* I2C, write word */
static void Reg_BusWriteWord(uint8_t reg, uint16_t byteData){
	array_ADD_PTN5110_Tx[0] = (uint8_t) (byteData & (0xFF));
	array_ADD_PTN5110_Tx[1] = (uint8_t) ((byteData >> SHIFT_8_BITS_PTN5110) & (0xFF));

#if (USE_BAREMETAL_I2C == 0U)
	PD_I2cWriteBlocking(config_PTN5110.instance_i2c, config_PTN5110.address, reg, array_ADD_PTN5110_Tx, 2U);
#else
	i2cWriteBlocking(config_PTN5110.instance_i2c, config_PTN5110.address, reg, array_ADD_PTN5110_Tx, 2U);
#endif
}

static void Reg_BusWriteBlock(uint8_t reg, uint8_t length, uint8_t *src){
#if (USE_BAREMETAL_I2C == 0U)
	PD_I2cWriteBlocking(config_PTN5110.instance_i2c, config_PTN5110.address, reg, src, length);
#else
	i2cWriteBlocking(config_PTN5110.instance_i2c, config_PTN5110.address, reg, src, length);
#endif
}




static void ptn5110_pdo_save_Fixed(uint8_t* array, uint8_t index_array){
	uint32_t auxiliar;
	uint32_t fixedSupplyPDO = 0;
	uint8_t index_save;

	for(index_save = 0; index_save < 4; index_save++){
		auxiliar = (uint32_t) array[index_save];
		fixedSupplyPDO |= (auxiliar << (8*index_save));
	}

	array_source_pdos[index_array]._pd_source_pdo_union.fixedPDO.fixedSupply = kPDO_Fixed;
	array_source_pdos[index_array]._pd_source_pdo_union.fixedPDO.dualRolePower = (fixedSupplyPDO >> 29) & 0x1;
	array_source_pdos[index_array]._pd_source_pdo_union.fixedPDO.usbSuspendSupported = (fixedSupplyPDO >> 28) & 0x1;
	array_source_pdos[index_array]._pd_source_pdo_union.fixedPDO.unconstrainedPower = (fixedSupplyPDO >> 27) & 0x1;
	array_source_pdos[index_array]._pd_source_pdo_union.fixedPDO.usbCommunicationsCapable = (fixedSupplyPDO >> 26) & 0x1;
	array_source_pdos[index_array]._pd_source_pdo_union.fixedPDO.dualRoleData = (fixedSupplyPDO >> 25) & 0x1;
	array_source_pdos[index_array]._pd_source_pdo_union.fixedPDO.peakCurrent = (fixedSupplyPDO >> 20) & 0x3;
	array_source_pdos[index_array]._pd_source_pdo_union.fixedPDO.voltage = (fixedSupplyPDO >> 10) & 0x3FF;
	array_source_pdos[index_array]._pd_source_pdo_union.fixedPDO.maxCurrent = (fixedSupplyPDO >> 0) & 0x3FF;

	/* TODO: Maximum Current */
	/* NOTE: For the laptops of NXP, the maximum current is 3 A */
	if(array_source_pdos[index_array]._pd_source_pdo_union.fixedPDO.maxCurrent == 300){
		IP_SIUL2->GPDO30 = 1;
	}
}

static void ptn5110_check_and_program_orientation(void){
	uint8_t auxiliar_for_registers = 0;
	uint8_t data_byte = 0;

	/* Check orientation */
	data_byte = Reg_BusReadByte(ADDR_cc_status);
	auxiliar_for_registers = data_byte & TCPC_CC_STATUS_CONNECT_RESULT_MASK;
    if(auxiliar_for_registers == 0x00){
    	for(;;);
    }

    auxiliar_for_registers = data_byte & (TCPC_CC_STATUS_CC1_STATE_MASK | TCPC_CC_STATUS_CC2_STATE_MASK);
    if((auxiliar_for_registers & TCPC_CC_STATUS_CC1_STATE_MASK) != CC_STATUS_CC1_STATE_SRC_OPEN){
    	config_PTN5110.pd_orientation = kPlug_Orientation_CC1;
    }else if(((auxiliar_for_registers & TCPC_CC_STATUS_CC2_STATE_MASK) >> TCPC_CC_STATUS_CC2_STATE_LSB) != CC_STATUS_CC2_STATE_SRC_OPEN){
    	config_PTN5110.pd_orientation = kPlug_Orientation_CC2;
    }else{
    	config_PTN5110.pd_orientation = kPlus_Orientation_Nothing;
    	for(;;);
    }

    /* Program Plug Orientation */
    if(config_PTN5110.pd_orientation == kPlug_Orientation_CC1){
    	Reg_BusWriteByte(ADDR_tcpc_control, 0x10);
    }else{
    	Reg_BusWriteByte(ADDR_tcpc_control, 0x11);
    }

    if(config_PTN5110.pd_orientation == kPlug_Orientation_CC1){
    	Reg_BusWriteByte(ADDR_role_control, 0x0E);
    }else{
    	Reg_BusWriteByte(ADDR_role_control, 0x0B);
    }

    if(config_PTN5110.pd_orientation == kPlug_Orientation_CC1){
    	Reg_BusWriteByte(ADDR_tcpc_control, 0x00);
    }else{
    	Reg_BusWriteByte(ADDR_tcpc_control, 0x01);
    }

    Reg_BusWriteByte(ADDR_power_control, TCPC_POWER_CONTROL_VBUS_VOLTAGE_MONITOR_MASK | TCPC_POWER_CONTROL_DISABLE_VOLTAGE_ALARMS_MASK | TCPC_POWER_CONTROL_AUTO_DISCHARGE_DISCONNECT_MASK);

    if(config_PTN5110.pd_orientation == kPlug_Orientation_CC1){
    	Reg_BusWriteByte(ADDR_tcpc_control, 0x10);
    }else{
    	Reg_BusWriteByte(ADDR_tcpc_control, 0x11);
    }
}

void ptn5110_init(info_PTN5110_t info){
	number_pdo_source = 0;
	config_PTN5110 = info;
	uint8_t index = 0;
	uint16_t data_word = 0;

	/* Check Product ID Vendor ID and Device ID */
	while(PD_VENDOR_ID_NXP != data_word){
		data_word = Reg_BusReadWord(ADDR_vendor_id);
	}

	/*-----------------------------------------------------------------------Primera Prueba--------------------------------------------------------------------------------------------------------------*/
	//PD_I2cReadBlocking_Test(config_PTN5110.instance_i2c, config_PTN5110.address, ADDR_vendor_id, array_ADD_PTN5110_Rx, 2U);

	while(PRODUCT_ID_PTN5110 != data_word){
	    data_word = Reg_BusReadWord(ADDR_product_id);
	}

	data_word = Reg_BusReadWord(ADDR_device_id);

	data_word = Reg_BusReadWord(ADDR_power_status);

    data_word = data_word & (TCPC_POWER_STATUS_SINKING_VBUS_MASK | TCPC_POWER_STATUS_VBUS_PRESENT_MASK | TCPC_POWER_STATUS_VBUS_PRESENT_DETECTION_ENABLED_MASK);
    if(data_word != (TCPC_POWER_STATUS_SINKING_VBUS_MASK | TCPC_POWER_STATUS_VBUS_PRESENT_MASK | TCPC_POWER_STATUS_VBUS_PRESENT_DETECTION_ENABLED_MASK)){
    	// TODO: It is necessary to put the error type error_init_power_status
    	for(;;);
    }

    /* Configure Default */
    /* Default TCPC Control */
    Reg_BusWriteByte(ADDR_tcpc_control, 0x00);

    Reg_BusWriteWord(ADDR_alert_mask, 0x7FFF);

    Reg_BusWriteWord(ADDR_alert, 0x7FFF);

    Reg_BusWriteByte(ADDR_power_status_mask, 0xFF);

    Reg_BusWriteByte(ADDR_fault_control, 0x00);

    data_word = Reg_BusReadWord(ADDR_alert);

    /* Default Reception */
    Reg_BusWriteByte(ADDR_receive_detect, 0x00);

    for(index = 0; index < 3; index++){
    	Reg_BusWriteWord(ADDR_alert, (TCPC_ALERT_BEGINNING_SOP_MESSAGE_STATUS_MASK | TCPC_ALERT_RECEIVE_SOP_MESSAGE_STATUS_MASK));
    }

    Reg_BusWriteByte(ADDR_fault_status, 0xFF);

    Reg_BusWriteWord(ADDR_alert, (TCPC_ALERT_FAULT_MASK | TCPC_ALERT_CC_STATUS_ALERT_MASK));

    ptn5110_check_and_program_orientation();

    /* Command SINK VBUS */
    Reg_BusWriteByte(ADDR_command, TCPC_SINKVBUS);

    Reg_BusWriteWord(ADDR_vbus_voltage_alarm_lo_cfg, 0x00AA);

    Reg_BusWriteWord(ADDR_vbus_voltage_alarm_hi_cfg, 0x00E6);

    Reg_BusWriteByte(ADDR_power_control, (TCPC_POWER_CONTROL_VBUS_VOLTAGE_MONITOR_MASK | TCPC_POWER_CONTROL_AUTO_DISCHARGE_DISCONNECT_MASK));

    Reg_BusWriteWord(ADDR_vbus_sink_disconnect_threshold, 0x008C);
}

message_type_t ptn5110_check_received_message(uint8_t* number_bytes_received){
	Reg_BusReadBlock(ADDR_receive_byte_count, 4, array_ADD_PTN5110_Rx);

	uint8_t number = array_ADD_PTN5110_Rx[0];
	message_type_t type;
	if(0 == number){
		type = kPD_MsgNotMessage;
	}else{
		number += 1;
		type = ptn5110_message_header(array_ADD_PTN5110_Rx + 2);
	}
	*number_bytes_received = number;

	return type;
}

// TODO: It is necessary put a timeout of intents to receive the information (source capabilities)
void ptn5110_receive_source_capabilities(void){
	uint8_t index = 0;
	uint8_t flag_exit = 0;
	message_type_t type = kPD_MsgNotMessage;
	uint8_t number_bytes_received = 0;
	uint8_t data_byte = 0;

	data_byte = Reg_BusReadByte(ADDR_cc_status);

    /* Command SINK VBUS */
    Reg_BusWriteByte(ADDR_command, TCPC_SINKVBUS);

    Reg_BusWriteWord(ADDR_vbus_voltage_alarm_lo_cfg, 0x00AA);

    Reg_BusWriteWord(ADDR_vbus_voltage_alarm_hi_cfg, 0x00E6);

    Reg_BusWriteByte(ADDR_power_control, (TCPC_POWER_CONTROL_VBUS_VOLTAGE_MONITOR_MASK | TCPC_POWER_CONTROL_AUTO_DISCHARGE_DISCONNECT_MASK));

    Reg_BusWriteByte(ADDR_receive_detect, 0x00);

    for(index = 0; index < 3; index++){
    	Reg_BusWriteWord(ADDR_alert, (TCPC_ALERT_BEGINNING_SOP_MESSAGE_STATUS_MASK | TCPC_ALERT_RECEIVE_SOP_MESSAGE_STATUS_MASK));
    }

    Reg_BusWriteByte(ADDR_receive_detect, (TCPC_RECEIVE_DETECT_ENABLE_HARD_RESET_MASK | TCPC_RECEIVE_DETECT_ENABLE_SOP_MESSAGE_MASK));

    Reg_BusWriteByte(ADDR_message_header_info, 0x02);

    flag_exit = 0;
    while(0 == flag_exit){
    	type = ptn5110_check_received_message(&number_bytes_received);

        /* Command RESETRECEIVEBUFFER */
    	Reg_BusWriteByte(ADDR_command, TCPC_RESETRECEIVEBUFFER);

        if((number_bytes_received != 0) && (kPD_MsgSourceCapabilities == type)){
        	Reg_BusReadBlock(ADDR_receive_byte_count, number_bytes_received, array_ADD_PTN5110_Rx);

            ptn5110_pdo_identification((array_ADD_PTN5110_Rx + 4), (number_bytes_received - 4)/4);
            flag_exit = 1;
        }
    }
}
/*
 * Examples of this 2 functions
 * Source Capabilities
Header 		0x2161		[3][2]
Objeto 1 	0x0801912C	[7][6][5][4]
Objeto 2	0x0002D0DE	[11][10][9][8]
 * */

/*
 * TODO: In this function the user needs to add the offset when call this function.
 * The offset is equal to 2.
 * */
message_type_t ptn5110_message_header(uint8_t* array){
	uint16_t auxiliar_register = (uint16_t) array[1];
	uint16_t header = (uint16_t) array[0];
	message_type_t type = kPD_MsgNotMessage;

	header = header | (auxiliar_register << PD_MSG_HEADER_PORT_POWER_ROLE_POS);

	auxiliar_register = (header & PD_MSG_HEADER_NUMBER_OF_DATA_OBJECTS_MASK) >> PD_MSG_HEADER_NUMBER_OF_DATA_OBJECTS_POS;

	if(0 == auxiliar_register){
		type = (header & PD_MSG_HEADER_MESSAGE_TYPE_MASK) >> PD_MSG_HEADER_MESSAGE_TYPE_POS;
		// Control Messages
		/* Not implemented */
	}else{
		// Data Messages
		type = (header & PD_MSG_HEADER_MESSAGE_TYPE_MASK) >> PD_MSG_HEADER_MESSAGE_TYPE_POS;
		type |= PD_MSG_DATA_TYPE_MASK;

		//TODO: Test objects (If receive 1 object in Source Capabilities, LED RED turn on)
		if(((header >> PD_MSG_HEADER_NUMBER_OF_DATA_OBJECTS_POS) & 0x7) == 1){
			IP_SIUL2->GPDO29 = 1;
		}
	}
	return type;
}

/*
 * TODO: In this function the user needs to add the offset when call this function.
 * The offset is equal to 4.
 * */
void ptn5110_pdo_identification(uint8_t* array, uint8_t number_objects){
	uint8_t index = 0;
	uint8_t aux_objects = number_objects;
	uint8_t aux_register = 0;

	if(MAX_OBJECTS_PTN5110 < number_objects){
		aux_objects = MAX_OBJECTS_PTN5110;
	}

	for(index = 0; index < aux_objects; index++){
		aux_register = array[4*index + 3] >> 6;

		if(kPDO_Fixed == aux_register){
			ptn5110_pdo_save_Fixed(&(array[4*index]), index);
		}else if(kPDO_Battery == aux_register){
			/* Not implemented */
		}else if(kPDO_Variable == aux_register){
			/* Not implemented */
		}else{
			/* Not implemented */
		}
	}

	number_pdo_source = aux_objects;
}

void ptn5110_request_data_object(pd_rdo_fixed_variable_t request){
	uint32_t data_object = 0;
	uint16_t voltage_request = request.voltage_request;
	uint16_t voltage_capability = 0;
	uint16_t max_current_capability = 0;
	uint32_t max_current_request = 0;
	uint32_t data_object_auxiliar = 0;
	uint8_t index = 0;

	uint8_t flag = 0;

	uint16_t data_word = 0;

	/* This is to obtain the best voltage to request depending the capabilities of source */
	if(0 < number_pdo_source){
		if(voltage_request < PD_MIN_VOLTAGE){
		} else{
			while(0 == flag){
				voltage_capability = array_source_pdos[index]._pd_source_pdo_union.fixedPDO.voltage * PD_PDO_VOLTAGE_UNIT;

				if(voltage_capability > voltage_request){
					flag = 1;
					index = index - 1;
				} else{
					index = index + 1;
				}

				if(number_pdo_source <= index){
					flag = 1;
					index = index - 1;
				}
			}
		}
	}else{
		for(;;);
	}

	index = index + 1;
	max_current_capability = array_source_pdos[index]._pd_source_pdo_union.fixedPDO.maxCurrent * PD_PDO_CURRENT_UNIT;

	if(max_current_capability < request.maximum_operating_current){
		max_current_request = (uint32_t) max_current_capability;
	}else{
		max_current_request = (uint32_t) request.maximum_operating_current;
	}
	max_current_request = max_current_request / PD_PDO_CURRENT_UNIT;

	data_object = (uint32_t) index;

	data_object = (data_object << 28U) | (max_current_request << 10U) | (max_current_request << 0U);

	Reg_BusWriteWord(ADDR_alert, TCPC_ALERT_RECEIVE_SOP_MESSAGE_STATUS_MASK);

	data_word = Reg_BusReadWord(ADDR_alert);

    Reg_BusWriteByte(ADDR_message_header_info, 0x02);

    Reg_BusWriteByte(ADDR_receive_detect, (TCPC_RECEIVE_DETECT_ENABLE_HARD_RESET_MASK | TCPC_RECEIVE_DETECT_ENABLE_SOP_MESSAGE_MASK));

    /* Command RESETTRASMITBUFFER */
    Reg_BusWriteByte(ADDR_command, TCPC_RESETTRASMITBUFFER);

    /* TRANSMIT BUFFER Request PD Power Negotiation */
    //array_ADD_PTN5110_Tx[0] = ADDR_transmit_byte_count;
    array_ADD_PTN5110_Tx[0] = 0x06;

    /* Ponerlo en mascaras, para saber que es cada cosa */
    array_ADD_PTN5110_Tx[1] = 0x42;
    array_ADD_PTN5110_Tx[2] = 0x10;

    for(index = 0; index < 4; index++){
        data_object_auxiliar = (data_object >> (8*index)) & (0xFF);
        array_ADD_PTN5110_Tx[3 + index] = (uint8_t) data_object_auxiliar;
    }

/*
    array_ADD_PTN5110_Tx[2] = 0x42;
    array_ADD_PTN5110_Tx[3] = 0x10;
    array_ADD_PTN5110_Tx[4] = 0x64;
    array_ADD_PTN5110_Tx[5] = 0x90;
    array_ADD_PTN5110_Tx[6] = 0x01;
    array_ADD_PTN5110_Tx[7] = 0x20; //Byte most significant
*/
    Reg_BusWriteBlock(ADDR_transmit_byte_count, 7, array_ADD_PTN5110_Tx);

    Reg_BusWriteByte(ADDR_transmit, AUTOMATICALLY_RETRY_MESSAGE_TRANSMISSION_THREE_TIMES);

    while(0 == flag){
    	data_word = Reg_BusReadWord(ADDR_alert);

    	data_word = data_word & TCPC_ALERT_TRANSMIT_SOP_MESSAGE_SUCCESSFUL_MASK;
        if(data_word != 0){
        	Reg_BusWriteWord(ADDR_alert, TCPC_ALERT_TRANSMIT_SOP_MESSAGE_SUCCESSFUL_MASK);
            flag = 1;
        }
    }
}

void ptn5110_accept_data_object(void){
    uint8_t flag_exit = 0;
    uint16_t data_word = 0;

    while(0 == flag_exit){
    	data_word = Reg_BusReadWord(ADDR_alert);

    	data_word = data_word & TCPC_ALERT_RECEIVE_SOP_MESSAGE_STATUS_MASK;
        if(data_word != 0){
            flag_exit = 1;
        }
    }

    /* Accept */
    Reg_BusReadBlock(ADDR_receive_byte_count, 4, array_ADD_PTN5110_Rx);

    Reg_BusWriteWord(ADDR_alert, TCPC_ALERT_RECEIVE_SOP_MESSAGE_STATUS_MASK);

    data_word = Reg_BusReadWord(ADDR_alert);

    Reg_BusWriteByte(ADDR_receive_detect, (TCPC_RECEIVE_DETECT_ENABLE_HARD_RESET_MASK | TCPC_RECEIVE_DETECT_ENABLE_SOP_MESSAGE_MASK));

    if(config_PTN5110.pd_orientation == kPlug_Orientation_CC1){
    	Reg_BusWriteByte(ADDR_tcpc_control, 0x00);
    }else{
    	Reg_BusWriteByte(ADDR_tcpc_control, 0x01);
    }

    Reg_BusWriteByte(ADDR_power_control, TCPC_POWER_CONTROL_VBUS_VOLTAGE_MONITOR_MASK);

    if(config_PTN5110.pd_orientation == kPlug_Orientation_CC1){
    	Reg_BusWriteByte(ADDR_tcpc_control, 0x10);
    }else{
    	Reg_BusWriteByte(ADDR_tcpc_control, 0x11);
    }

    Reg_BusWriteWord(ADDR_vbus_sink_disconnect_threshold, 0x0000);

    Reg_BusWriteByte(ADDR_power_control, (TCPC_POWER_CONTROL_VBUS_VOLTAGE_MONITOR_MASK | TCPC_POWER_CONTROL_DISABLE_VOLTAGE_ALARMS_MASK));
}

void ptn5110_ready_data_object(void){

    uint8_t flag_exit = 0;
    uint16_t data_word = 0;

    while(0 == flag_exit){
    	data_word = Reg_BusReadWord(ADDR_alert);

    	data_word = data_word & TCPC_ALERT_RECEIVE_SOP_MESSAGE_STATUS_MASK;
        if(data_word != 0){
            flag_exit = 1;
        }
    }

    /* PS_READY */
    Reg_BusReadBlock(ADDR_receive_byte_count, 4, array_ADD_PTN5110_Rx);

    Reg_BusWriteWord(ADDR_alert, TCPC_ALERT_RECEIVE_SOP_MESSAGE_STATUS_MASK);

    data_word = Reg_BusReadWord(ADDR_alert);

    Reg_BusWriteByte(ADDR_receive_detect, (TCPC_RECEIVE_DETECT_ENABLE_HARD_RESET_MASK | TCPC_RECEIVE_DETECT_ENABLE_SOP_MESSAGE_MASK));
}

void ptn5110_request_sink(pd_rdo_fixed_variable_t request){
    ptn5110_request_data_object(request);
    ptn5110_accept_data_object();
    ptn5110_ready_data_object();
}

uint16_t ptn5110_get_vbus_voltage(void){
	uint16_t vbus_scale_factor = 0;
	uint16_t data = 0;

	uint8_t data_control = Reg_BusReadByte(ADDR_power_control);
	data_control &= ~TCPC_POWER_CONTROL_VBUS_VOLTAGE_MONITOR_MASK;
	Reg_BusWriteByte(ADDR_power_control, data_control);

	data = Reg_BusReadWord(ADDR_vbus_voltage);

	data_control |= TCPC_POWER_CONTROL_VBUS_VOLTAGE_MONITOR_MASK;
	Reg_BusWriteByte(ADDR_power_control, data_control);

	vbus_scale_factor = data & TCPC_VBUS_VOLTAGE_VBUS_SCALE_FACTOR_MASK;
	vbus_scale_factor = vbus_scale_factor >> TCPC_VBUS_VOLTAGE_VBUS_SCALE_FACTOR_LSB;
	data &= TCPC_VBUS_VOLTAGE_VBUS_VOLTAGE_MEASUREMENT_MASK;

	data = data*25;

	if(1 == vbus_scale_factor){
		data = data << 1;
	}else if(2 == vbus_scale_factor){
		data = data << 2;
	}


	return data;
}
