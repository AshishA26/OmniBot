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
P 3650 6950
F 0 "U?" H 3650 7465 50  0000 C CNN
F 1 "nRF24L01+_Receiver" H 3650 7374 50  0000 C CNN
F 2 "MODULE" H 3650 7050 50  0001 C CNN
F 3 "DOCUMENTATION" H 3650 6900 50  0001 C CNN
	1    3650 6950
	1    0    0    -1  
$EndComp
Text Notes 850  1250 0    276  Italic 55
OmniBot Joystick
$Comp
L power:+9V #PWR?
U 1 1 61D82457
P 2700 2400
F 0 "#PWR?" H 2700 2250 50  0001 C CNN
F 1 "+9V" H 2715 2573 50  0000 C CNN
F 2 "" H 2700 2400 50  0001 C CNN
F 3 "" H 2700 2400 50  0001 C CNN
	1    2700 2400
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 61D8AD90
P 3000 2400
F 0 "#PWR?" H 3000 2250 50  0001 C CNN
F 1 "+5V" H 3015 2573 50  0000 C CNN
F 2 "" H 3000 2400 50  0001 C CNN
F 3 "" H 3000 2400 50  0001 C CNN
	1    3000 2400
	1    0    0    -1  
$EndComp
$Comp
L SparkFun-PowerSymbols:GND2 #GND?
U 1 1 61DA884B
P 2600 6300
F 0 "#GND?" H 2650 6250 45  0001 L BNN
F 1 "GND2" H 2600 6070 45  0000 C CNN
F 2 "" H 2600 5975 60  0001 C CNN
F 3 "" H 2600 6200 60  0001 C CNN
	1    2600 6300
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 61DB9F8E
P 2600 6900
F 0 "#PWR?" H 2600 6750 50  0001 C CNN
F 1 "+5V" H 2615 7073 50  0000 C CNN
F 2 "" H 2600 6900 50  0001 C CNN
F 3 "" H 2600 6900 50  0001 C CNN
	1    2600 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 6900 2900 6900
$Comp
L SparkFun-PowerSymbols:GND2 #GND?
U 1 1 61EA1A16
P 3350 4650
F 0 "#GND?" H 3400 4600 45  0001 L BNN
F 1 "GND2" H 3350 4420 45  0000 C CNN
F 2 "" H 3350 4325 60  0001 C CNN
F 3 "" H 3350 4550 60  0001 C CNN
	1    3350 4650
	1    0    0    -1  
$EndComp
Text GLabel 2900 7050 0    50   Input ~ 0
CE
Text GLabel 2900 7200 0    50   Input ~ 0
CSN
Wire Wire Line
	2900 6750 2900 6300
Wire Wire Line
	2900 6300 2600 6300
Text GLabel 2150 3650 0    50   Output ~ 0
CSN
Text GLabel 2150 3550 0    50   Output ~ 0
CE
Text GLabel 4400 6750 2    50   Output ~ 0
SCK
Text GLabel 2150 4250 0    50   Input ~ 0
SCK
Text GLabel 4400 6900 2    50   Output ~ 0
MOSI
Text GLabel 4400 7050 2    50   Input ~ 0
MISO
Text GLabel 2150 4150 0    50   Output ~ 0
MISO
Text GLabel 2150 4050 0    50   Input ~ 0
MOSI
Wire Wire Line
	2150 4050 2300 4050
Wire Wire Line
	2150 4150 2300 4150
Wire Wire Line
	2150 4250 2300 4250
Wire Wire Line
	2150 3650 2300 3650
Wire Wire Line
	2150 3550 2300 3550
Wire Notes Line
	5000 6000 5000 7500
Wire Notes Line
	5000 7500 1400 7500
Wire Notes Line
	1400 7500 1400 6000
Wire Notes Line
	1400 6000 5000 6000
Text Notes 2300 2250 2    118  ~ 0
ARDUINO
Text Notes 3900 6250 2    118  ~ 0
NRF24 RADIO TRANSMITTER
$Comp
L MCU_Module:Arduino_Nano_Every A?
U 1 1 61DBEABC
P 2800 3550
F 0 "A?" H 2800 2461 50  0001 C CNN
F 1 "Arduino_Nano" H 2800 2370 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 2800 3550 50  0001 C CIN
F 3 "https://content.arduino.cc/assets/NANOEveryV3.0_sch.pdf" H 2800 3550 50  0001 C CNN
	1    2800 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 4550 3350 4550
Wire Wire Line
	3350 4550 3350 4650
Wire Wire Line
	3000 2550 3000 2400
Wire Wire Line
	2700 2550 2700 2400
$Comp
L AA_Custom_Components:JOYSTICK_BREAKOUT f
U 1 1 61DD2AAD
P 5450 3600
F 0 "f" H 6278 3742 45  0001 L CNN
F 1 "JOYSTICK_BREAKOUT_LEFT" H 5103 3274 45  0000 L CNN
F 2 "" H 5600 3900 20  0001 C CNN
F 3 "" H 5600 3450 50  0001 C CNN
	1    5450 3600
	1    0    0    -1  
$EndComp
$Comp
L SparkFun-PowerSymbols:GND2 #GND?
U 1 1 61DD9126
P 4900 3000
F 0 "#GND?" H 4950 2950 45  0001 L BNN
F 1 "GND2" H 4900 2770 45  0000 C CNN
F 2 "" H 4900 2675 60  0001 C CNN
F 3 "" H 4900 2900 60  0001 C CNN
	1    4900 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 3000 5250 3000
Wire Wire Line
	5250 3000 5250 3350
$Comp
L power:+5V #PWR?
U 1 1 61DD9F09
P 5100 3300
F 0 "#PWR?" H 5100 3150 50  0001 C CNN
F 1 "+5V" H 5115 3473 50  0000 C CNN
F 2 "" H 5100 3300 50  0001 C CNN
F 3 "" H 5100 3300 50  0001 C CNN
	1    5100 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 3450 5100 3300
Wire Wire Line
	5100 3450 5250 3450
Text GLabel 5100 3550 0    50   Output ~ 0
VRX_L
Text GLabel 5100 3650 0    50   Output ~ 0
VRY_L
Text GLabel 5100 3750 0    50   Output ~ 0
SW_L
$Comp
L AA_Custom_Components:JOYSTICK_BREAKOUT f?
U 1 1 61DDCDA7
P 5450 4550
F 0 "f?" H 6278 4692 45  0001 L CNN
F 1 "JOYSTICK_BREAKOUT_LEFT" H 5103 4224 45  0000 L CNN
F 2 "" H 5600 4850 20  0001 C CNN
F 3 "" H 5600 4400 50  0001 C CNN
	1    5450 4550
	1    0    0    -1  
$EndComp
$Comp
L SparkFun-PowerSymbols:GND2 #GND?
U 1 1 61DDCDAD
P 4900 3950
F 0 "#GND?" H 4950 3900 45  0001 L BNN
F 1 "GND2" H 4900 3720 45  0000 C CNN
F 2 "" H 4900 3625 60  0001 C CNN
F 3 "" H 4900 3850 60  0001 C CNN
	1    4900 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 3950 5250 3950
Wire Wire Line
	5250 3950 5250 4300
$Comp
L power:+5V #PWR?
U 1 1 61DDCDB5
P 5100 4250
F 0 "#PWR?" H 5100 4100 50  0001 C CNN
F 1 "+5V" H 5115 4423 50  0000 C CNN
F 2 "" H 5100 4250 50  0001 C CNN
F 3 "" H 5100 4250 50  0001 C CNN
	1    5100 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 4400 5100 4250
Wire Wire Line
	5100 4400 5250 4400
Text GLabel 5100 4500 0    50   Output ~ 0
VRX_R
Text GLabel 5100 4600 0    50   Output ~ 0
VRY_R
Text GLabel 5100 4700 0    50   Output ~ 0
SW_R
Wire Wire Line
	5100 3550 5250 3550
Wire Wire Line
	5100 3650 5250 3650
Wire Wire Line
	5100 3750 5250 3750
Wire Wire Line
	5100 4500 5250 4500
Wire Wire Line
	5100 4600 5250 4600
Wire Wire Line
	5100 4700 5250 4700
Text GLabel 3450 3750 2    50   Input ~ 0
VRX_L
Text GLabel 3450 3850 2    50   Input ~ 0
VRY_L
Text GLabel 2150 3050 0    50   Input ~ 0
SW_R
Wire Wire Line
	3450 3750 3300 3750
Wire Wire Line
	3300 3850 3450 3850
Text GLabel 3450 3550 2    50   Input ~ 0
VRX_R
Text GLabel 3450 3650 2    50   Input ~ 0
VRY_R
Wire Wire Line
	3450 3550 3300 3550
Wire Wire Line
	3300 3650 3450 3650
Text GLabel 2150 3150 0    50   Input ~ 0
SW_L
Text GLabel 2150 3250 0    50   Input ~ 0
BUTTON_1
Text GLabel 2150 3350 0    50   Input ~ 0
BUTTON_2
Text GLabel 2150 3450 0    50   Input ~ 0
BUTTON_3
Text GLabel 2150 3750 0    50   Input ~ 0
BUTTON_4
Wire Wire Line
	2150 3050 2300 3050
Wire Wire Line
	2150 3150 2300 3150
Wire Wire Line
	2150 3250 2300 3250
Wire Wire Line
	2150 3350 2300 3350
Wire Wire Line
	2150 3450 2300 3450
Wire Wire Line
	2150 3750 2300 3750
$Comp
L AA_Custom_Components:BUTTON_BREAKOUT j
U 1 1 61DC9678
P 8600 2600
F 0 "j" H 8475 2967 50  0001 C CNN
F 1 "BUTTON_BREAKOUT_1" H 8475 2875 50  0000 C CNN
F 2 "" H 8650 2350 50  0001 L CIN
F 3 "http://www.ti.com/lit/ds/symlink/lm2596.pdf" H 8600 2600 50  0001 C CNN
	1    8600 2600
	1    0    0    -1  
$EndComp
Text GLabel 7950 2500 0    50   Output ~ 0
BUTTON_1
$Comp
L AA_Custom_Components:BUTTON_BREAKOUT j?
U 1 1 61DDDFFF
P 8600 3250
F 0 "j?" H 8475 3617 50  0001 C CNN
F 1 "BUTTON_BREAKOUT_2" H 8475 3525 50  0000 C CNN
F 2 "" H 8650 3000 50  0001 L CIN
F 3 "http://www.ti.com/lit/ds/symlink/lm2596.pdf" H 8600 3250 50  0001 C CNN
	1    8600 3250
	1    0    0    -1  
$EndComp
Text GLabel 7950 3150 0    50   Output ~ 0
BUTTON_2
$Comp
L AA_Custom_Components:BUTTON_BREAKOUT j?
U 1 1 61DDF914
P 8600 3950
F 0 "j?" H 8475 4317 50  0001 C CNN
F 1 "BUTTON_BREAKOUT_3" H 8475 4225 50  0000 C CNN
F 2 "" H 8650 3700 50  0001 L CIN
F 3 "http://www.ti.com/lit/ds/symlink/lm2596.pdf" H 8600 3950 50  0001 C CNN
	1    8600 3950
	1    0    0    -1  
$EndComp
Text GLabel 7950 3850 0    50   Output ~ 0
BUTTON_3
$Comp
L AA_Custom_Components:BUTTON_BREAKOUT j?
U 1 1 61DE507E
P 8600 4650
F 0 "j?" H 8475 5017 50  0001 C CNN
F 1 "BUTTON_BREAKOUT_4" H 8475 4925 50  0000 C CNN
F 2 "" H 8650 4400 50  0001 L CIN
F 3 "http://www.ti.com/lit/ds/symlink/lm2596.pdf" H 8600 4650 50  0001 C CNN
	1    8600 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	7800 4750 8100 4750
Wire Notes Line
	4500 5100 6200 5100
Wire Notes Line
	6200 2500 4500 2500
Text Notes 5500 2750 2    118  ~ 0
JOYSTICKS
Wire Notes Line
	6800 5600 9700 5600
Wire Notes Line
	9700 1950 6800 1950
Text Notes 7750 2250 2    118  ~ 0
BUTTONS
Wire Notes Line
	6200 2500 6200 5100
Wire Notes Line
	4500 2500 4500 5100
Wire Notes Line
	1400 5450 3900 5450
Wire Notes Line
	3900 5450 3900 2000
Wire Notes Line
	3900 2000 1400 2000
Wire Notes Line
	1400 2000 1400 5450
Text Notes 1750 5300 0    59   ~ 0
Note: On the Arduino Nano, SCK = D13, \nMOSI = D12, and MISO = D11.
$Comp
L SparkFun-PowerSymbols:GND2 #GND?
U 1 1 61E33A90
P 7800 4750
F 0 "#GND?" H 7850 4700 45  0001 L BNN
F 1 "GND2" H 7800 4520 45  0000 C CNN
F 2 "" H 7800 4425 60  0001 C CNN
F 3 "" H 7800 4650 60  0001 C CNN
	1    7800 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7800 4050 8100 4050
$Comp
L SparkFun-PowerSymbols:GND2 #GND?
U 1 1 61E3A52D
P 7800 4050
F 0 "#GND?" H 7850 4000 45  0001 L BNN
F 1 "GND2" H 7800 3820 45  0000 C CNN
F 2 "" H 7800 3725 60  0001 C CNN
F 3 "" H 7800 3950 60  0001 C CNN
	1    7800 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	7800 3350 8100 3350
$Comp
L SparkFun-PowerSymbols:GND2 #GND?
U 1 1 61E3B3F1
P 7800 3350
F 0 "#GND?" H 7850 3300 45  0001 L BNN
F 1 "GND2" H 7800 3120 45  0000 C CNN
F 2 "" H 7800 3025 60  0001 C CNN
F 3 "" H 7800 3250 60  0001 C CNN
	1    7800 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	7800 2700 8100 2700
$Comp
L SparkFun-PowerSymbols:GND2 #GND?
U 1 1 61E3C2CD
P 7800 2700
F 0 "#GND?" H 7850 2650 45  0001 L BNN
F 1 "GND2" H 7800 2470 45  0000 C CNN
F 2 "" H 7800 2375 60  0001 C CNN
F 3 "" H 7800 2600 60  0001 C CNN
	1    7800 2700
	1    0    0    -1  
$EndComp
Text GLabel 7950 4550 0    50   Output ~ 0
BUTTON_4
Wire Wire Line
	7950 2500 8100 2500
Wire Wire Line
	7950 3150 8100 3150
Wire Wire Line
	7950 3850 8100 3850
Wire Wire Line
	7950 4550 8100 4550
Text Notes 7150 5550 0    59   ~ 0
Note: Resistors not needed as Arduino has internal \npullup resistors. Also, it does not matter which set \nof pins used, only matters the pins are beside \neachother.
Wire Notes Line
	9700 1950 9700 5600
Wire Notes Line
	6800 1950 6800 5600
$EndSCHEMATC
