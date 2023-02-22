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


/*
  Available connectors on MAKERBASE MKS BASE2 v1.2
Power
   +==============+
   | 12-24V | GND |                          Power Supply line
   +========+=====+
Heated Bed 
   +==========+
   | D8 |GND |                               (8)  D8 ** PH5 ** Pin17
   +==========+                      

Extruders E1          E2
   +=====+=====+=====+====+                  (10) D10 ** PB4 ** Pin2
   | GND | D10 | GND | D7 |                  (7)  D7  ** PH4 ** Pin1
   +=====+=====+=====+====+ 

Fan                   
   +=====+====+
   | GND | D9 |                              (9)  D9  ** PH6 ** Pin1
   +=====+====+

Temperature
           TH1         TH2         TB
   +===================================+     A15 ** PK7 ** Pin82
   | GND | A13 | GND | A15 | GND | A14 |     A14 ** PK6 ** Pin83
   +===================================+     A13 ** PK5 ** Pin84
  
AUX-1 Connector
   +====================+                  D2 ** PE4 ** Pin6
   | 5V | GND | D2 | D1 |                  A3 ** PF3 ** Pin94 ** D57
   |----+-----+----+----|                  D1 ** PE1 ** Pin3
   | 5V | GND | A3 | A4 |                  A4 ** PF4 ** Pin93 ** D58 
   +====================+ 

ICSP
   +=================+
   | 5V  | PB2 | GND |                       SPI_MOSI ** PB2 ** Pin21
   |-----+-----+-----|                       SPI_MISO ** PB3 ** Pin22
   | PB3 | PB1 | RST |                       SPI_SCK  ** PB1 ** Pin20
   +=================+                       RESET    ** Pin 30

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
   |  3 | GND | VCC| X-                    
   |----+-----+----|                       (3 ) D3 ** PE5 ** Pin7
   |  2 | GND | VCC| X+                    (2 ) D2 ** PE4 ** Pin6     
   |----+-----+----|                       (14) D14 ** PJ1 ** Pin64 ** USART3_TX
   | 14 | GND | VCC| Y-                    (15) D15 ** PJ0 ** Pin63 ** USART3_RX
   |----+-----+----|                       (18) D18 ** PD3 ** Pin46 ** USART1_TX
   | 15 | GND | VCC| Y+                    (19) D19 ** PD2 ** Pin45 ** USART1_RX
   |----+-----+----|
   | 18 | GND | VCC| Z-                    
   |----+-----+----|
   | 19 | GND | VCC| Z+                    
   +===============+
   
EXP1
   +=========+
   | 37 | 35 |                             (37) D37 ** PC0 ** Pin53
   |----+----|                             (35) D35 ** PC2 ** Pin55 
   | 17 | 16 |                             (17) D17 ** PH0 ** Pin12 ** USART2_RX
   |----+----|                             (16) D16 ** PH1 ** Pin13 ** USART2_TX
   | 23 | 25 |                             (23) D23 ** PA1 ** Pin77
   |----+----|                             (25) D25 ** PA3 ** Pin75
   | 27 | 29 |                             (27) D27 ** PA5 ** Pin73
   |----+----|                             (29) D29 ** PA7 ** Pin71
   | GND| 5V |
   +=========+

EXP2
   +=========+
   | 50 | 52 |                            (50)  D50 ** PB3 ** Pin22 ** SPI_MISO
   |----+----|                            (52)  D52 ** PB1 ** Pin20 ** SPI_SCK
   | 31 | 53 |                            (31)  D31 ** PC6 ** Pin59 ** A14
   |----+----|                            (53)  D53 ** PB0 ** Pin19 ** SPI_SS
   | 33 | 51 |                            (33)  D33 ** PC4 ** Pin57
   |----+----|                            (51)  D51 ** PB2 ** Pin21 ** SPI_MOSI
   | 49 | 30 |                            (49)  D49 ** PL0 ** Pin35
   |----+----|                            (30)  RST ** Pin30
   | GND| 41 |                            (41)  D41 ** PG0 ** Pin51
   +=========+

J1
   +==+
   |16|                                   Microstepper motor step selection
   |++|
   |32|
   +==+

Stepper motors
*/

#if HOTENDS > 2 || E_STEPPERS > 2
  #error "MKS BASE2 1.2 supports up to 2 hotends / E steppers."
#endif

#define BOARD_INFO_NAME "MKS BASE_2"
#define MKS_BASE_VERSION "1.2"

#include "env_validate.h"

// Power outputs EFBF or EFBE
#define FAN1_is_ENABLED
#define FAN1_PIN   7

#ifndef FIL_RUNOUT_PIN
  #define FIL_RUNOUT_PIN  2
#endif

//
// Servos
//
#ifndef SERVO0_PIN
  #ifdef IS_RAMPS_13
    #define SERVO0_PIN                         7
  #else
    #define SERVO0_PIN                        11
  #endif
#endif
#ifndef SERVO1_PIN
  #define SERVO1_PIN                           6
#endif
#ifndef SERVO2_PIN
  #define SERVO2_PIN                           5
#endif
#ifndef SERVO3_PIN
  #define SERVO3_PIN                           4
#endif

//
// Foam Cutter requirements
//

#if ENABLED(FOAMCUTTER_XYUV)
  #ifndef MOSFET_C_PIN
    #define MOSFET_C_PIN                      -1
  #endif
  #if HAS_CUTTER && !defined(SPINDLE_LASER_ENA_PIN) && NUM_SERVOS < 2
    #define SPINDLE_LASER_PWM_PIN              8  // Hardware PWM
  #endif
  #ifndef Z_MIN_PIN
    #define Z_MIN_PIN                         -1
  #endif
  #ifndef Z_MAX_PIN
    #define Z_MAX_PIN                         -1
  #endif
  #ifndef I_STOP_PIN
    #define I_STOP_PIN                        18
  #endif
  #ifndef J_STOP_PIN
    #define J_STOP_PIN                        19
  #endif
#endif

//
// Limit Switches
//
#ifndef X_STOP_PIN
  #ifndef X_MIN_PIN
    #define X_MIN_PIN                          3
  #endif
  #ifndef X_MAX_PIN
    #define X_MAX_PIN                          2
  #endif
#endif
#ifndef Y_STOP_PIN
  #ifndef Y_MIN_PIN
    #define Y_MIN_PIN                         14
  #endif
  #ifndef Y_MAX_PIN
    #define Y_MAX_PIN                         15
  #endif
#endif
#ifndef Z_STOP_PIN
  #ifndef Z_MIN_PIN
    #define Z_MIN_PIN                         18
  #endif
  #ifndef Z_MAX_PIN
    #define Z_MAX_PIN                         19
  #endif
#endif

//
// Z Probe (when not Z_MIN_PIN)
//
#ifndef Z_MIN_PROBE_PIN
  #define Z_MIN_PROBE_PIN                     32
#endif

//
// Steppers
//
#define X_STEP_PIN                            54
#define X_DIR_PIN                             55
#define X_ENABLE_PIN                          38
#ifndef X_CS_PIN
  #define X_CS_PIN                            53
#endif

#define Y_STEP_PIN                            60
#define Y_DIR_PIN                             61
#define Y_ENABLE_PIN                          56
#ifndef Y_CS_PIN
  #define Y_CS_PIN                            49
#endif

#ifndef Z_STEP_PIN
  #define Z_STEP_PIN                          46
#endif
#ifndef Z_DIR_PIN
  #define Z_DIR_PIN                           48
#endif
#ifndef Z_ENABLE_PIN
  #define Z_ENABLE_PIN                        62
#endif
#ifndef Z_CS_PIN
  #define Z_CS_PIN                            40
#endif

#ifndef E0_STEP_PIN
  #define E0_STEP_PIN                         26
#endif
#ifndef E0_DIR_PIN
  #define E0_DIR_PIN                          28
#endif
#ifndef E0_ENABLE_PIN
  #define E0_ENABLE_PIN                       24
#endif
#ifndef E0_CS_PIN
  #define E0_CS_PIN                           42
#endif

#ifndef E1_STEP_PIN
  #define E1_STEP_PIN                         36
#endif
#ifndef E1_DIR_PIN
  #define E1_DIR_PIN                          34
#endif
#ifndef E1_ENABLE_PIN
  #define E1_ENABLE_PIN                       30
#endif
#ifndef E1_CS_PIN
  #define E1_CS_PIN                           44
#endif

//
// Temperature Sensors
//
#ifndef TEMP_0_PIN
  #define TEMP_0_PIN                          13  // Analog Input
#endif
#ifndef TEMP_1_PIN
  #define TEMP_1_PIN                          15  // Analog Input
#endif
#ifndef TEMP_BED_PIN
  #define TEMP_BED_PIN                        14  // Analog Input
#endif

//
// SPI for MAX Thermocouple
//
#ifndef TEMP_0_CS_PIN
  #define TEMP_0_CS_PIN                       66  // Don't use 53 if using Display/SD card (SDSS) or 49 (SD_DETECT_PIN)
#endif

//
// Heaters / Fans
//
#ifndef MOSFET_A_PIN
  #define MOSFET_A_PIN                        10
#endif
#ifndef MOSFET_B_PIN
  #define MOSFET_B_PIN                         9
#endif
#ifndef MOSFET_C_PIN
  #define MOSFET_C_PIN                         8
#endif
#ifndef MOSFET_D_PIN
  #define MOSFET_D_PIN                        -1
#endif

#define HEATER_0_PIN                MOSFET_A_PIN

#if FET_ORDER_EFB                                 // Hotend, Fan, Bed
  #ifndef HEATER_BED_PIN
    #define HEATER_BED_PIN          MOSFET_C_PIN
  #endif
#elif FET_ORDER_EEF                               // Hotend, Hotend, Fan
  #define HEATER_1_PIN              MOSFET_B_PIN
#elif FET_ORDER_EEB                               // Hotend, Hotend, Bed
  #define HEATER_1_PIN              MOSFET_B_PIN
  #ifndef HEATER_BED_PIN
    #define HEATER_BED_PIN          MOSFET_C_PIN
  #endif
#elif FET_ORDER_EFF                               // Hotend, Fan, Fan
  #define FAN1_PIN                  MOSFET_C_PIN
#elif DISABLED(FET_ORDER_SF)                      // Not Spindle, Fan (i.e., "EFBF" or "EFBE")
  #ifndef HEATER_BED_PIN
    #define HEATER_BED_PIN          MOSFET_C_PIN
  #endif
  #if EITHER(HAS_MULTI_HOTEND, HEATERS_PARALLEL)
    #define HEATER_1_PIN            MOSFET_D_PIN
  #else
    #define FAN1_PIN                MOSFET_D_PIN
  #endif
#endif

#ifndef FAN_PIN
  #if EITHER(FET_ORDER_EFB, FET_ORDER_EFF)        // Hotend, Fan, Bed or Hotend, Fan, Fan
    #define FAN_PIN                 MOSFET_B_PIN
  #elif EITHER(FET_ORDER_EEF, FET_ORDER_SF)       // Hotend, Hotend, Fan or Spindle, Fan
    #define FAN_PIN                 MOSFET_C_PIN
  #elif FET_ORDER_EEB                             // Hotend, Hotend, Bed
    #define FAN_PIN                            4  // IO pin. Buffer needed
  #else                                           // Non-specific are "EFB" (i.e., "EFBF" or "EFBE")
    #define FAN_PIN                 MOSFET_B_PIN
  #endif
#endif

//
// Misc. Functions
//
#ifndef SDSS
  #define SDSS                       EXP2_04_PIN
#endif
#define LED_PIN                               13

#ifndef FILWIDTH_PIN
  #define FILWIDTH_PIN                         5  // Analog Input on AUX2
#endif

// RAMPS 1.4 DIO 4 on the servos connector
#ifndef FIL_RUNOUT_PIN
  #define FIL_RUNOUT_PIN                       4
#endif

#ifndef PS_ON_PIN
  #define PS_ON_PIN                           12
#endif

#if ENABLED(CASE_LIGHT_ENABLE) && !defined(CASE_LIGHT_PIN) && !defined(SPINDLE_LASER_ENA_PIN)
  #if NUM_SERVOS <= 1                             // Prefer the servo connector
    #define CASE_LIGHT_PIN                     6  // Hardware PWM
  #elif HAS_FREE_AUX2_PINS
    #define CASE_LIGHT_PIN                    44  // Hardware PWM
  #endif
#endif

//
// M3/M4/M5 - Spindle/Laser Control
//
#if HAS_CUTTER && !defined(SPINDLE_LASER_ENA_PIN)
  #if NUM_SERVOS < 2                              // Use servo connector if possible
    #define SPINDLE_LASER_ENA_PIN              4  // Pullup or pulldown!
    #ifndef SPINDLE_LASER_PWM_PIN
      #define SPINDLE_LASER_PWM_PIN            6  // Hardware PWM
    #endif
    #define SPINDLE_DIR_PIN                    5
  #elif HAS_FREE_AUX2_PINS
    #define SPINDLE_LASER_ENA_PIN             40  // Pullup or pulldown!
    #define SPINDLE_LASER_PWM_PIN             44  // Hardware PWM
    #define SPINDLE_DIR_PIN                   65
  #else
    #error "No auto-assignable Spindle/Laser pins available."
  #endif
#endif

//
// TMC software SPI
//
#if ENABLED(TMC_USE_SW_SPI)
  #ifndef TMC_SW_MOSI
    #define TMC_SW_MOSI                       66
  #endif
  #ifndef TMC_SW_MISO
    #define TMC_SW_MISO                       44
  #endif
  #ifndef TMC_SW_SCK
    #define TMC_SW_SCK                        64
  #endif
#endif

#if HAS_TMC_UART
  /**
   * TMC2208/TMC2209 stepper drivers
   *
   * Hardware serial communication ports.
   * If undefined software serial is used according to the pins below
   *
   * Serial2 -- AUX-4 Pin 18 (D16 TX2) and AUX-4 Pin 17 (D17 RX2)
   * Serial1 -- Pins D18 and D19 are used for Z-MIN and Z-MAX
   */
  //#define X_HARDWARE_SERIAL Serial1
  //#define X2_HARDWARE_SERIAL Serial1
  //#define Y_HARDWARE_SERIAL Serial1
  //#define Y2_HARDWARE_SERIAL Serial1
  //#define Z_HARDWARE_SERIAL Serial1
  //#define Z2_HARDWARE_SERIAL Serial1
  //#define E0_HARDWARE_SERIAL Serial1
  //#define E1_HARDWARE_SERIAL Serial1
  //#define E2_HARDWARE_SERIAL Serial1
  //#define E3_HARDWARE_SERIAL Serial1
  //#define E4_HARDWARE_SERIAL Serial1

  #ifndef X_SERIAL_TX_PIN
    #define X_SERIAL_TX_PIN                   40
  #endif
  #ifndef X_SERIAL_RX_PIN
    #define X_SERIAL_RX_PIN                   63
  #endif
  #ifndef X2_SERIAL_TX_PIN
    #define X2_SERIAL_TX_PIN                  -1
  #endif
  #ifndef X2_SERIAL_RX_PIN
    #define X2_SERIAL_RX_PIN                  -1
  #endif

  #ifndef Y_SERIAL_TX_PIN
    #define Y_SERIAL_TX_PIN                   59
  #endif
  #ifndef Y_SERIAL_RX_PIN
    #define Y_SERIAL_RX_PIN                   64
  #endif
  #ifndef Y2_SERIAL_TX_PIN
    #define Y2_SERIAL_TX_PIN                  -1
  #endif
  #ifndef Y2_SERIAL_RX_PIN
    #define Y2_SERIAL_RX_PIN                  -1
  #endif

  #ifndef Z_SERIAL_TX_PIN
    #define Z_SERIAL_TX_PIN                   42
  #endif
  #ifndef Z_SERIAL_RX_PIN
    #define Z_SERIAL_RX_PIN                   65
  #endif
  #ifndef Z2_SERIAL_TX_PIN
    #define Z2_SERIAL_TX_PIN                  -1
  #endif
  #ifndef Z2_SERIAL_RX_PIN
    #define Z2_SERIAL_RX_PIN                  -1
  #endif

  #ifndef E0_SERIAL_TX_PIN
    #define E0_SERIAL_TX_PIN                  44
  #endif
  #ifndef E0_SERIAL_RX_PIN
    #define E0_SERIAL_RX_PIN                  66
  #endif
  #ifndef E1_SERIAL_TX_PIN
    #define E1_SERIAL_TX_PIN                  -1
  #endif
  #ifndef E1_SERIAL_RX_PIN
    #define E1_SERIAL_RX_PIN                  -1
  #endif
  #ifndef E2_SERIAL_TX_PIN
    #define E2_SERIAL_TX_PIN                  -1
  #endif
  #ifndef E2_SERIAL_RX_PIN
    #define E2_SERIAL_RX_PIN                  -1
  #endif
  #ifndef E3_SERIAL_TX_PIN
    #define E3_SERIAL_TX_PIN                  -1
  #endif
  #ifndef E3_SERIAL_RX_PIN
    #define E3_SERIAL_RX_PIN                  -1
  #endif
  #ifndef E4_SERIAL_TX_PIN
    #define E4_SERIAL_TX_PIN                  -1
  #endif
  #ifndef E4_SERIAL_RX_PIN
    #define E4_SERIAL_RX_PIN                  -1
  #endif
  #ifndef E5_SERIAL_TX_PIN
    #define E5_SERIAL_TX_PIN                  -1
  #endif
  #ifndef E5_SERIAL_RX_PIN
    #define E5_SERIAL_RX_PIN                  -1
  #endif
  #ifndef E6_SERIAL_TX_PIN
    #define E6_SERIAL_TX_PIN                  -1
  #endif
  #ifndef E6_SERIAL_RX_PIN
    #define E6_SERIAL_RX_PIN                  -1
  #endif
  #ifndef E7_SERIAL_TX_PIN
    #define E7_SERIAL_TX_PIN                  -1
  #endif
  #ifndef E7_SERIAL_RX_PIN
    #define E7_SERIAL_RX_PIN                  -1
  #endif
#endif

// AUX1    5V  GND D2  D1
//          2   4   6   8
//          1   3   5   7
//         5V  GND A3  A4
//
#define AUX1_05_PIN                           57  // (A3)
#define AUX1_06_PIN                            2
#define AUX1_07_PIN                           58  // (A4)
#define AUX1_08_PIN                            1

/**
 * LCD adapters come in different variants. The socket keys can be
 * on either side, and may be backwards on some boards / displays.
 */
  #define EXP1_01_PIN                37
  #define EXP1_02_PIN                35
  #define EXP1_03_PIN                17 
  #define EXP1_04_PIN                16 
  #define EXP1_05_PIN                23 
  #define EXP1_06_PIN                25 
  #define EXP1_07_PIN                27 
  #define EXP1_08_PIN                29 

  #define EXP2_01_PIN                50 
  #define EXP2_02_PIN                52 
  #define EXP2_03_PIN                31
  #define EXP2_04_PIN                53 
  #define EXP2_05_PIN                33
  #define EXP2_06_PIN                51 
  #define EXP2_07_PIN                49 
  #define EXP2_10_PIN                41 

// LCDs and Controllers

#if HAS_WIRED_LCD && DISABLED(LCD_PINS_DEFINED)
  #define LCD_SCREEN_ROTATE                0  // 0, 90, 180, 270

  // LCD Display output pins
  #if EITHER(MKS_MINI_12864, FYSETC_MINI_12864)
      #define BEEPER_PIN             EXP1_01_PIN
      #define BTN_ENC                EXP1_02_PIN
      #ifndef SD_DETECT_PIN
        #define SD_DETECT_PIN        -1 //EXP2_07_PIN
      #endif
      #ifndef KILL_PIN
        #define KILL_PIN             -1 //EXP2_10_PIN
      #endif

      #if ENABLED(FYSETC_MINI_12864)  // From https://wiki.fysetc.com/Mini12864_Panel/
        #define DOGLCD_A0            EXP1_04_PIN
        #define DOGLCD_CS            EXP1_03_PIN
        #define BTN_EN2              EXP2_05_PIN
        #define BTN_EN1              EXP2_03_PIN
        #define FORCE_SOFT_SPI                  // Use this if default of hardware SPI causes display problems,results in LCD soft SPI mode 3, SD soft SPI mode 0
        #define LCD_RESET_PIN        EXP1_05_PIN  // Must be high or open for LCD to operate normally.
        #if ENABLED(FYSETC_MINI_12864_2_1)
          #define NEOPIXEL_PIN       EXP1_06_PIN
        #endif
      #endif  
  #endif
#endif // HAS_WIRED_LCD && !LCD_PINS_DEFINED