/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * MKS BASE – Arduino Mega2560 with RAMPS pin assignments
 * MKS BASE2 v1.2 with  stepper drivers and digital micro-stepping
 */

#if HOTENDS > 2 || E_STEPPERS > 2
  #error "MKS BASE2 1.2 supports up to 2 hotends / E steppers."
#endif

#define BOARD_INFO_NAME "MKS BASE_2 1.2"
#define MKS_BASE_VERSION                     12

#include "pins_MKS_BASE_common.h"

/*
  Available connectors on MAKERBASE MKS BASE2 v1.2

   +========+
   | 12-24V |
   |--------|   Power
   |  GND   |
   +========+

   +=====+
   | GND |
   |-----|   Heated Bed                    (8)  PH5 ** Pin17 ** PWM8
   |  8  |                
   +=====+

   +=====+
   | GND |
   |-----|   E0                            (10)  PB4 ** Pin23 ** PWM10
   |  10 |                
   |-----|
   | GND |
   |-----|   E1                            (7)  PH4 ** Pin16 ** PWM7
   |  7  |                
   |-----|
   | GND |
   |-----|   FAN                           (9)  PH6 ** Pin18 ** PWM9
   |  9  |                
   +=====+

   Temperature
   +================================+      (69)  PK7 ** Pin82 ** A15
   | GND | 67 | GND | 69 | GND | 68 |      (68)  PK6 ** Pin83 ** A14
   +================================+      (67)  PK5 ** Pin84 ** A13
  
   AUX-1 Connector
   +====================+                  (51)  PE4 ** Pin6  ** D2
   | 5V | GND | 51 | 20 |                  (52)  PF3 ** Pin94 ** A3
   |----+-----+----+----|                  (20)  PE1 ** Pin3  ** D1
   | 5V | GND | 52 | 21 |                  (21)  PF4 ** Pin93 ** A4
   +====================+ 

   ICSP
   +===============+
   | 5V | 51 | GND |                       (51)  PB2 ** Pin21 ** SPI_MOSI
   |----+----+-----|                       (50)  PB3 ** Pin22 ** SPI_MISO
   | 50 | 52 | RST |                       (52)  PB1 ** Pin20 ** SPI_SCK
   +===============+      

   XS1
   +==============+
   | 80 | 82 | 84 |                        (80)  PK3 ** Pin86 ** A11
   |----+----+----|                        (81)  PK4 ** Pin85 ** A12
   | 81 | 83 | 85 |                        (82,83) Pin11 ** GND
   +==============+                        (84,85) Pin10 ** +5V
   
   XS2
   +==============+
   | 90 | 92 | 94 |                        (90)  PB5 ** Pin24 ** D11
   |----+----+----|                        (91)  PB6 ** Pin25 ** D12
   | 91 | 93 | 95 |                        (92,93) Pin11 ** GND
   +==============+                        (94,95) Pin10 ** +5V

   Limit Switches
   +===============+
   |  3 | GND | VCC| X-                    (3)  PE5 ** Pin7  ** PWM3
   |----+-----+----|
   |  2 | GND | VCC| X+                    (2)  PE4 ** Pin6  ** PWM2       
   |----+-----+----|
   | 14 | GND | VCC| Y-                    (14) PJ1 ** Pin64 ** USART3_TX
   |----+-----+----|
   | 15 | GND | VCC| Y+                    (15) PJ0 ** Pin63 ** USART3_RX
   |----+-----+----|
   | 18 | GND | VCC| Z-                    (18) PD3 ** Pin46 ** USART1_TX
   |----+-----+----|
   | 19 | GND | VCC| Z+                    (19) PD2 ** Pin45 ** USART1_RX
   +===============+
   
   EXP1
   +=========+
   | 37 | 35 |                            (37)  PC0 ** Pin53 ** D37
   |----+----|                            (35)  PC2 ** Pin55 ** D35
   | 17 | 16 |                            (17)  PH0 ** Pin12 ** USART2_RX
   |----+----|                            (16)  PH1 ** Pin13 ** USART2_TX
   | 23 | 25 |                            (23)  PA1 ** Pin77 ** D23
   |----+----|                            (25)  PA3 ** Pin75 ** D25
   | 27 | 29 |                            (27)  PA5 ** Pin73 ** D27
   |----+----|                            (29)  PA7 ** Pin71 ** D29
   | GND| 5V |
   +=========+

   EXP2
   +=========+
   | 50 | 52 |           (50)  PB3 ** Pin22 ** SPI_MISO
   |----+----|           (52)  PB1 ** Pin20 ** SPI_SCK
   | 31 | 53 |           (31)  PC6 ** Pin59 ** D31/A14
   |----+----|           (53)  PB0 ** Pin19 ** SPI_SS
   | 33 | 51 |           (33)  PC4 ** Pin57 ** D33
   |----+----|           (51)  PB2 ** Pin21 ** SPI_MOSI
   | 49 | 30 |           (49)  PL0 ** Pin35 ** D49
   |----+----|           (30)  RST ** Pin30
   | GND| 41 |           (41 )  PG0 ** Pin51 ** D41
   +=========+
*/
