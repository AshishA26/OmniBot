EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 1 1
Title "OmniBot Joystick"
Date "2022-01-15"
Rev "1"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 "By: Ashish Agrahari"
$EndDescr
$Comp
L myelin-kicad:nRF24L01+ U?
U 1 1 61D4F1B6
P 6800 6050
F 0 "U?" H 6800 6565 50  0000 C CNN
F 1 "nRF24L01+_Receiver" H 6800 6474 50  0000 C CNN
F 2 "MODULE" H 6800 6150 50  0001 C CNN
F 3 "DOCUMENTATION" H 6800 6000 50  0001 C CNN
	1    6800 6050
	1    0    0    -1  
$EndComp
Text Notes 850  1250 0    276  Italic 55
OmniBot Joystick
$Comp
L power:+9V #PWR?
U 1 1 61D82457
P 2550 3000
F 0 "#PWR?" H 2550 2850 50  0001 C CNN
F 1 "+9V" H 2565 3173 50  0000 C CNN
F 2 "" H 2550 3000 50  0001 C CNN
F 3 "" H 2550 3000 50  0001 C CNN
	1    2550 3000
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 61D8AD90
P 2850 3000
F 0 "#PWR?" H 2850 2850 50  0001 C CNN
F 1 "+5V" H 2865 3173 50  0000 C CNN
F 2 "" H 2850 3000 50  0001 C CNN
F 3 "" H 2850 3000 50  0001 C CNN
	1    2850 3000
	1    0    0    -1  
$EndComp
$Comp
L SparkFun-PowerSymbols:GND2 #GND?
U 1 1 61DA884B
P 5750 5400
F 0 "#GND?" H 5800 5350 45  0001 L BNN
F 1 "GND2" H 5750 5170 45  0000 C CNN
F 2 "" H 5750 5075 60  0001 C CNN
F 3 "" H 5750 5300 60  0001 C CNN
	1    5750 5400
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 61DB9F8E
P 5750 6000
F 0 "#PWR?" H 5750 5850 50  0001 C CNN
F 1 "+5V" H 5765 6173 50  0000 C CNN
F 2 "" H 5750 6000 50  0001 C CNN
F 3 "" H 5750 6000 50  0001 C CNN
	1    5750 6000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 6000 6050 6000
$Comp
L SparkFun-PowerSymbols:GND2 #GND?
U 1 1 61EA1A16
P 3200 5250
F 0 "#GND?" H 3250 5200 45  0001 L BNN
F 1 "GND2" H 3200 5020 45  0000 C CNN
F 2 "" H 3200 4925 60  0001 C CNN
F 3 "" H 3200 5150 60  0001 C CNN
	1    3200 5250
	1    0    0    -1  
$EndComp
Text GLabel 6050 6150 0    50   Input ~ 0
CE
Text GLabel 6050 6300 0    50   Input ~ 0
CSN
Wire Wire Line
	6050 5850 6050 5400
Wire Wire Line
	6050 5400 5750 5400
Text GLabel 2000 4250 0    50   Output ~ 0
CSN
Text GLabel 2000 4150 0    50   Output ~ 0
CE
Text GLabel 7550 5850 2    50   Output ~ 0
SCK
Text GLabel 2000 4850 0    50   Input ~ 0
SCK
Text GLabel 7550 6000 2    50   Output ~ 0
MOSI
Text GLabel 7550 6150 2    50   Input ~ 0
MISO
Text GLabel 2000 4750 0    50   Output ~ 0
MISO
Text GLabel 2000 4650 0    50   Input ~ 0
MOSI
Wire Wire Line
	2000 4650 2150 4650
Wire Wire Line
	2000 4750 2150 4750
Wire Wire Line
	2000 4850 2150 4850
Wire Wire Line
	2000 4250 2150 4250
Wire Wire Line
	2000 4150 2150 4150
Wire Notes Line
	8150 5100 8150 6600
Wire Notes Line
	8150 6600 4550 6600
Wire Notes Line
	4550 6600 4550 5100
Wire Notes Line
	4550 5100 8150 5100
Text Notes 2150 2850 2    118  ~ 0
ARDUINO
Text Notes 7050 5350 2    118  ~ 0
NRF24 RADIO TRANSMITTER
$Comp
L MCU_Module:Arduino_Nano_Every A?
U 1 1 61DBEABC
P 2650 4150
F 0 "A?" H 2650 3061 50  0001 C CNN
F 1 "Arduino_Nano" H 2650 2970 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 2650 4150 50  0001 C CIN
F 3 "https://content.arduino.cc/assets/NANOEveryV3.0_sch.pdf" H 2650 4150 50  0001 C CNN
	1    2650 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 5150 3200 5150
Wire Wire Line
	3200 5150 3200 5250
Wire Wire Line
	2850 3150 2850 3000
Wire Wire Line
	2550 3150 2550 3000
$Comp
L AA_Custom_Components:JOYSTICK_BREAKOUT f
U 1 1 61DD2AAD
P 5350 2700
F 0 "f" H 6178 2842 45  0001 L CNN
F 1 "JOYSTICK_BREAKOUT_LEFT" H 5003 2374 45  0000 L CNN
F 2 "" H 5500 3000 20  0001 C CNN
F 3 "" H 5500 2550 50  0001 C CNN
	1    5350 2700
	1    0    0    -1  
$EndComp
$Comp
L SparkFun-PowerSymbols:GND2 #GND?
U 1 1 61DD9126
P 4800 2100
F 0 "#GND?" H 4850 2050 45  0001 L BNN
F 1 "GND2" H 4800 1870 45  0000 C CNN
F 2 "" H 4800 1775 60  0001 C CNN
F 3 "" H 4800 2000 60  0001 C CNN
	1    4800 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 2100 5150 2100
Wire Wire Line
	5150 2100 5150 2450
$Comp
L power:+5V #PWR?
U 1 1 61DD9F09
P 5000 2400
F 0 "#PWR?" H 5000 2250 50  0001 C CNN
F 1 "+5V" H 5015 2573 50  0000 C CNN
F 2 "" H 5000 2400 50  0001 C CNN
F 3 "" H 5000 2400 50  0001 C CNN
	1    5000 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 2550 5000 2400
Wire Wire Line
	5000 2550 5150 2550
Text GLabel 5000 2650 0    50   Output ~ 0
VRX_L
Text GLabel 5000 2750 0    50   Output ~ 0
VRY_L
Text GLabel 5000 2850 0    50   Output ~ 0
SW_L
$Comp
L AA_Custom_Components:JOYSTICK_BREAKOUT f?
U 1 1 61DDCDA7
P 5350 3650
F 0 "f?" H 6178 3792 45  0001 L CNN
F 1 "JOYSTICK_BREAKOUT_LEFT" H 5003 3324 45  0000 L CNN
F 2 "" H 5500 3950 20  0001 C CNN
F 3 "" H 5500 3500 50  0001 C CNN
	1    5350 3650
	1    0    0    -1  
$EndComp
$Comp
L SparkFun-PowerSymbols:GND2 #GND?
U 1 1 61DDCDAD
P 4800 3050
F 0 "#GND?" H 4850 3000 45  0001 L BNN
F 1 "GND2" H 4800 2820 45  0000 C CNN
F 2 "" H 4800 2725 60  0001 C CNN
F 3 "" H 4800 2950 60  0001 C CNN
	1    4800 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 3050 5150 3050
Wire Wire Line
	5150 3050 5150 3400
$Comp
L power:+5V #PWR?
U 1 1 61DDCDB5
P 5000 3350
F 0 "#PWR?" H 5000 3200 50  0001 C CNN
F 1 "+5V" H 5015 3523 50  0000 C CNN
F 2 "" H 5000 3350 50  0001 C CNN
F 3 "" H 5000 3350 50  0001 C CNN
	1    5000 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 3500 5000 3350
Wire Wire Line
	5000 3500 5150 3500
Text GLabel 5000 3600 0    50   Output ~ 0
VRX_R
Text GLabel 5000 3700 0    50   Output ~ 0
VRY_R
Text GLabel 5000 3800 0    50   Output ~ 0
SW_R
Wire Wire Line
	5000 2650 5150 2650
Wire Wire Line
	5000 2750 5150 2750
Wire Wire Line
	5000 2850 5150 2850
Wire Wire Line
	5000 3600 5150 3600
Wire Wire Line
	5000 3700 5150 3700
Wire Wire Line
	5000 3800 5150 3800
Text GLabel 3300 4350 2    50   Input ~ 0
VRX_L
Text GLabel 3300 4450 2    50   Input ~ 0
VRY_L
Text GLabel 2000 3650 0    50   Input ~ 0
SW_R
Wire Wire Line
	3300 4350 3150 4350
Wire Wire Line
	3150 4450 3300 4450
Text GLabel 3300 4150 2    50   Input ~ 0
VRX_R
Text GLabel 3300 4250 2    50   Input ~ 0
VRY_R
Wire Wire Line
	3300 4150 3150 4150
Wire Wire Line
	3150 4250 3300 4250
Text GLabel 2000 3750 0    50   Input ~ 0
SW_L
Text GLabel 2000 3850 0    50   Input ~ 0
BUTTON_1
Text GLabel 2000 3950 0    50   Input ~ 0
BUTTON_2
Text GLabel 2000 4050 0    50   Input ~ 0
BUTTON_3
Text GLabel 2000 4350 0    50   Input ~ 0
BUTTON_4
Wire Wire Line
	2000 3650 2150 3650
Wire Wire Line
	2000 3750 2150 3750
Wire Wire Line
	2000 3850 2150 3850
Wire Wire Line
	2000 3950 2150 3950
Wire Wire Line
	2000 4050 2150 4050
Wire Wire Line
	2000 4350 2150 4350
$Comp
L AA_Custom_Components:BUTTON_BREAKOUT j
U 1 1 61DC9678
P 8550 1950
F 0 "j" H 8425 2317 50  0001 C CNN
F 1 "BUTTON_BREAKOUT_1" H 8425 2225 50  0000 C CNN
F 2 "" H 8600 1700 50  0001 L CIN
F 3 "http://www.ti.com/lit/ds/symlink/lm2596.pdf" H 8550 1950 50  0001 C CNN
	1    8550 1950
	1    0    0    -1  
$EndComp
Text GLabel 7900 1850 0    50   Output ~ 0
BUTTON_1
$Comp
L AA_Custom_Components:BUTTON_BREAKOUT j?
U 1 1 61DDDFFF
P 8550 2600
F 0 "j?" H 8425 2967 50  0001 C CNN
F 1 "BUTTON_BREAKOUT_2" H 8425 2875 50  0000 C CNN
F 2 "" H 8600 2350 50  0001 L CIN
F 3 "http://www.ti.com/lit/ds/symlink/lm2596.pdf" H 8550 2600 50  0001 C CNN
	1    8550 2600
	1    0    0    -1  
$EndComp
Text GLabel 7900 2500 0    50   Output ~ 0
BUTTON_2
$Comp
L AA_Custom_Components:BUTTON_BREAKOUT j?
U 1 1 61DDF914
P 8550 3300
F 0 "j?" H 8425 3667 50  0001 C CNN
F 1 "BUTTON_BREAKOUT_3" H 8425 3575 50  0000 C CNN
F 2 "" H 8600 3050 50  0001 L CIN
F 3 "http://www.ti.com/lit/ds/symlink/lm2596.pdf" H 8550 3300 50  0001 C CNN
	1    8550 3300
	1    0    0    -1  
$EndComp
Text GLabel 7900 3200 0    50   Output ~ 0
BUTTON_3
$Comp
L AA_Custom_Components:BUTTON_BREAKOUT j?
U 1 1 61DE507E
P 8550 4000
F 0 "j?" H 8425 4367 50  0001 C CNN
F 1 "BUTTON_BREAKOUT_4" H 8425 4275 50  0000 C CNN
F 2 "" H 8600 3750 50  0001 L CIN
F 3 "http://www.ti.com/lit/ds/symlink/lm2596.pdf" H 8550 4000 50  0001 C CNN
	1    8550 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	7750 4100 8050 4100
Wire Notes Line
	4400 4200 6100 4200
Wire Notes Line
	6100 1600 4400 1600
Text Notes 5400 1850 2    118  ~ 0
JOYSTICKS
Wire Notes Line
	6750 4950 9650 4950
Wire Notes Line
	9650 1300 6750 1300
Text Notes 7700 1600 2    118  ~ 0
BUTTONS
Wire Notes Line
	6100 1600 6100 4200
Wire Notes Line
	4400 1600 4400 4200
Wire Notes Line
	1250 6050 3750 6050
Wire Notes Line
	3750 6050 3750 2600
Wire Notes Line
	3750 2600 1250 2600
Wire Notes Line
	1250 2600 1250 6050
Text Notes 1600 5900 0    59   ~ 0
Note: On the Arduino Nano, SCK = D13, \nMOSI = D12, and MISO = D11.
$Comp
L SparkFun-PowerSymbols:GND2 #GND?
U 1 1 61E33A90
P 7750 4100
F 0 "#GND?" H 7800 4050 45  0001 L BNN
F 1 "GND2" H 7750 3870 45  0000 C CNN
F 2 "" H 7750 3775 60  0001 C CNN
F 3 "" H 7750 4000 60  0001 C CNN
	1    7750 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	7750 3400 8050 3400
$Comp
L SparkFun-PowerSymbols:GND2 #GND?
U 1 1 61E3A52D
P 7750 3400
F 0 "#GND?" H 7800 3350 45  0001 L BNN
F 1 "GND2" H 7750 3170 45  0000 C CNN
F 2 "" H 7750 3075 60  0001 C CNN
F 3 "" H 7750 3300 60  0001 C CNN
	1    7750 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	7750 2700 8050 2700
$Comp
L SparkFun-PowerSymbols:GND2 #GND?
U 1 1 61E3B3F1
P 7750 2700
F 0 "#GND?" H 7800 2650 45  0001 L BNN
F 1 "GND2" H 7750 2470 45  0000 C CNN
F 2 "" H 7750 2375 60  0001 C CNN
F 3 "" H 7750 2600 60  0001 C CNN
	1    7750 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	7750 2050 8050 2050
$Comp
L SparkFun-PowerSymbols:GND2 #GND?
U 1 1 61E3C2CD
P 7750 2050
F 0 "#GND?" H 7800 2000 45  0001 L BNN
F 1 "GND2" H 7750 1820 45  0000 C CNN
F 2 "" H 7750 1725 60  0001 C CNN
F 3 "" H 7750 1950 60  0001 C CNN
	1    7750 2050
	1    0    0    -1  
$EndComp
Text GLabel 7900 3900 0    50   Output ~ 0
BUTTON_4
Wire Wire Line
	7900 1850 8050 1850
Wire Wire Line
	7900 2500 8050 2500
Wire Wire Line
	7900 3200 8050 3200
Wire Wire Line
	7900 3900 8050 3900
Text Notes 7100 4900 0    59   ~ 0
Note: Resistors not needed as Arduino has internal \npullup resistors. Also, it does not matter which set \nof pins used, only matters the pins are beside \neachother.
Wire Notes Line
	9650 1300 9650 4950
Wire Notes Line
	6750 1300 6750 4950
$EndSCHEMATC
