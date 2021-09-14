# environmental-sensors


Environmental sensor board includes:

-SPS30 Particulate Matter Sensor module<br />
-SCD30 CO2, humidity, temperture sensor module<br />
-INA226 Bi-Directioal Current and Power Monitor<br />
-BLE module (NRF52840 dongle - can be assembled as an option)<br />
-2.4" OLED display with SSD1309 driver<br />
-PEC11R Series - 12 mm Incremental Encoder<br />
-USB MINI-B - for 5V power supply<br />


Project is in early stage of development process. Most hardware connections were verified for this moment and only 2 minor HW bugs found.
1. In INA226 circuit shunt resistor is connected directly to GND.
2. 3.3V voltage regulator IC1 is not capable to deliver enough peak current. As a temporary solution bigger capacitors on 3.3V line can be used. 

Schematic is available inside "environmental-sensors/workspace_stm32/smog_sensor_HW_files/" catalog. 




