/*
 * menu.c
 *
 *  Created on: 30 sie 2021
 *      Author: Programista
 */

#include "menu.h"
#include "rc_ssd1309.h"
#include "rc_graphic.h"
#include <stdio.h>
#include "i2c.h"


void measure_and_display_CO2_concentration(void);
void measure_and_display_PM_concentration(void);
void measure_and_dispaly_voltage_and_current(void);

extern uint8_t btn_state;
extern uint8_t CO2_irq_event;
extern uint8_t btn_counter;

MENU_NEXTSTATE menu_nextstate[4] = {
//  STATE                               INPUT          NEXT STATE
    {ST_MAIN_SCREEN,                  ENC_SW_ON,   ST_SECOND_SCREEN},
	{ST_SECOND_SCREEN,             	  ENC_SW_ON,   ST_MAIN_SCREEN},

};


MENU_STATE menu_state[3] = {
//       STATE                     STATE_FUNC
    {ST_MAIN_SCREEN,             DrawMainScreen},
    {ST_SECOND_SCREEN,           DrawSecondScreen},
};


/*****************************************************************************
*
*   Function name : StateMachine
*
*   Returns :       nextstate
*
*   Parameters :    state, stimuli
*
*   Purpose :       Shifts between the different states
*
*****************************************************************************/
uint8_t StateMachine(uint8_t state, uint8_t stimuli)
{
    uint8_t nextstate;
    unsigned char i;

    btn_state = KEY_NULL;

    nextstate = state;    // Default stay in same state
    for (i=0; menu_nextstate[i].state; i++)
    {
        if (menu_nextstate[i].state == state && menu_nextstate[i].input == stimuli)
        {
            // This is the one!
            nextstate = menu_nextstate[i].nextstate;
            break;
        }
    }

    return nextstate;
}

uint8_t DrawSecondScreen(uint8_t input)
{

	char buffer5[25];
	static uint8_t dane = 0;
	rc_ssd1309_display_clear();
    dane = dane+1;

	sprintf(buffer5,"second = %d",dane);
	rc_ssd1309_puts(0,0,buffer5,1,0);
	sprintf(buffer5,"input = %d",input);
	rc_ssd1309_puts(0,10,buffer5,1,0);


	rc_ssd1309_display();
	HAL_Delay(100);

	return ST_SECOND_SCREEN;
}


uint8_t DrawMainScreen(uint8_t input)
{

	if(CO2_irq_event>0)
	  {
  		measure_and_display_CO2_concentration();
  		measure_and_display_PM_concentration();
  		measure_and_dispaly_voltage_and_current();

  		rc_ssd1309_display();  // send display frame buffer to OLED

  		HAL_GPIO_WritePin(LED_1_GPIO_Port,LED_1_Pin,GPIO_PIN_RESET);  //turn off RED led

  		CO2_irq_event=0;
	}

	return ST_MAIN_SCREEN;
}


void measure_and_display_CO2_concentration(void)
{
	uint8_t CO2_wr_adr=0xC2;
	uint8_t CO2_rd_adr=0xC3;
	uint8_t CO2_meas_prep[2]={0x03,0x00};
	uint8_t CO2_meas_read_buff[20];

	float co2Concentration;
	float humidity;
	float temperature;
	unsigned int tempU32;
	char buffer5[25];


	/* Measure CO2 concentration */
	HAL_I2C_Master_Transmit(&hi2c2,CO2_wr_adr,CO2_meas_prep,2,500);         // co2 measure request
	HAL_Delay(5);
	HAL_I2C_Master_Receive(&hi2c2,CO2_rd_adr,CO2_meas_read_buff,18,100);    // co2 read sensor data


	/*    Calculation of temperature, humidity and CO2 concentration    */
	tempU32=	(CO2_meas_read_buff[0] << 24 |	CO2_meas_read_buff[1] << 16 |	CO2_meas_read_buff[3] << 8 |	CO2_meas_read_buff[4])	;
	co2Concentration = *(float*)&tempU32;

	tempU32=	(CO2_meas_read_buff[6] << 24 |	CO2_meas_read_buff[7] << 16 |	CO2_meas_read_buff[9] << 8 |	CO2_meas_read_buff[10])	;
	temperature = *(float*)&tempU32;

	tempU32=	(CO2_meas_read_buff[12] << 24 |	CO2_meas_read_buff[13] << 16 |	CO2_meas_read_buff[15] << 8 |	CO2_meas_read_buff[16])	;
	humidity = *(float*)&tempU32;

	/*    Put results on display frame buffer    */
	rc_ssd1309_display_clear();
	sprintf(buffer5,"CO2 = %3.0f",co2Concentration);
	rc_ssd1309_puts(0,0,buffer5,1,0);
	sprintf(buffer5,"Temperature= %2.0f",temperature);
	rc_ssd1309_puts(0,9,buffer5,1,0);
	sprintf(buffer5,"Humidity= %2.0f",humidity);
	rc_ssd1309_puts(0,20,buffer5,1,0);
}

void prepare_PM_sensor(void)
{
	uint8_t PM_sensor_wr_adr=0xD2;
	uint8_t PM_sensor_start_measure[5]={0x00,0x10,0x03,0x00,0xAC};

	HAL_GPIO_WritePin(PWR_ON_SPS30_GPIO_Port,PWR_ON_SPS30_Pin,GPIO_PIN_SET);
	HAL_Delay(1000);   //wait till sensor powers on

	HAL_I2C_Master_Transmit(&hi2c1,PM_sensor_wr_adr,PM_sensor_start_measure,5,500);
}




void measure_and_display_PM_concentration(void)
{
	uint8_t PM_sensor_wr_adr=0xD2;
	uint8_t PM_sensor_rd_adr=0xD3;
	uint8_t PM_sensor_read_measurement[2]={0x03,0x00};
	uint8_t PM_sensor_measurement_data[60];
	float PM_2_5_concentration;
	float PM_10_concentration;
	char buffer5[25];
	unsigned int tempU32;

	HAL_I2C_Master_Transmit(&hi2c1,PM_sensor_wr_adr,PM_sensor_read_measurement,2,500);   // PM sensor, measure request
	HAL_I2C_Master_Receive(&hi2c1,PM_sensor_rd_adr,PM_sensor_measurement_data,60,1000);  //	P


	tempU32=(PM_sensor_measurement_data[6] << 24 |	PM_sensor_measurement_data[7] << 16 |	PM_sensor_measurement_data[9] << 8 |	PM_sensor_measurement_data[10])	;
	PM_2_5_concentration = *(float*)&tempU32;

	tempU32=(PM_sensor_measurement_data[18] << 24 |	PM_sensor_measurement_data[19] << 16 |	PM_sensor_measurement_data[21] << 8 |	PM_sensor_measurement_data[22])	;
	PM_10_concentration = *(float*)&tempU32;

	sprintf(buffer5,"PM 2.5 = %3.2f",PM_2_5_concentration);
	rc_ssd1309_puts(0,30,buffer5,1,0);
	sprintf(buffer5,"PM 10 = %3.2f",PM_10_concentration);
	rc_ssd1309_puts(0,40,buffer5,1,0);
}



void prepare_INA_sensor(void)
{
	uint8_t INA_wr_adr_in=0x80;
	uint8_t INA_rd_adr_in=0x81;
	uint8_t INA_read_val[5];
	uint8_t INA_man_id[1]={0xfe};
	uint8_t INA_calib_value_in[3]={0x05,0x01,0xd6};
	uint8_t INA_conf_value[3]={0x00,0x47,0x27};


	HAL_I2C_Master_Transmit(&hi2c1,INA_wr_adr_in,INA_man_id,1,500);
	HAL_Delay(5);
	HAL_I2C_Master_Receive(&hi2c1,INA_rd_adr_in,INA_read_val,2,100);
	HAL_Delay(5);
	HAL_I2C_Master_Transmit(&hi2c1,INA_wr_adr_in,INA_conf_value,3,500);
	HAL_Delay(5);
	HAL_I2C_Master_Transmit(&hi2c1,INA_wr_adr_in,INA_calib_value_in,3,500);
	HAL_Delay(5);

}


void measure_and_dispaly_voltage_and_current(void)
{
	uint8_t INA_wr_adr_in=0x80;
	uint8_t INA_rd_adr_in=0x81;

	uint8_t INA_read_val[5];
	uint8_t INA_bus_vol_reg[1]={0x02};
	uint8_t INA_curr_reg[1]={0x04};
	uint32_t current_value;
	uint32_t voltage_value;
	float current_in;
	float voltage_in;
	char buffer5[25];

	//current measurements
	HAL_I2C_Master_Transmit(&hi2c1,INA_wr_adr_in,INA_curr_reg,1,500);
	HAL_Delay(5);
	HAL_I2C_Master_Receive(&hi2c1,INA_rd_adr_in,INA_read_val,2,100);
	current_value= (0 << 24 |	0 << 16 | INA_read_val[0]<<8 | INA_read_val[1]);
	current_in=(float)current_value;
	current_in=current_in/1000;
	sprintf(buffer5,"%3.3fA",current_in);
	rc_ssd1309_puts(0,50,buffer5,1,0);

	//Voltage measurements
	HAL_I2C_Master_Transmit(&hi2c1,INA_wr_adr_in,INA_bus_vol_reg,1,500);
	HAL_Delay(5);
	HAL_I2C_Master_Receive(&hi2c1,INA_rd_adr_in,INA_read_val,2,100);
	voltage_value= (0 << 24 |	0 << 16 | INA_read_val[0]<<8 | INA_read_val[1]);
	voltage_in=(float)voltage_value;
	voltage_in=voltage_in*1.251f;
	voltage_in=voltage_in/1000;
	sprintf(buffer5,"%3.3fV",voltage_in);
	rc_ssd1309_puts(64,50,buffer5,1,0);

}


