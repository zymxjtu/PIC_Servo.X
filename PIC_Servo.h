// PIC18F2520 Configuration Bit Settings

// 'C' source line config statements
#include <xc.h>
//device is selected in project property
//#include <PIC18F2520.h> 

/*Hardware Board*/
#define xBREAD_BOARD_SETUP
#define NEW_PCB_BOARD
/*Feature Switch*/
#define ENABLE_PID_CONTROL
/*Testing Feature Switch*/
#define xPCB_BOARD_VERIFY_LED    // Blink LED for PCB Board verification

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// CONFIG1H
#ifdef BREAD_BOARD_SETUP
#pragma config OSC = HS
#else
#pragma config OSC = HSPLL      // Oscillator Selection bits (HS oscillator, PLL enabled (Clock Frequency = 4 x FOSC1))
#endif
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
//#pragma config FCMEN = ON
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)
//#pragma config IESO = ON

// CONFIG2L
#pragma config PWRT = ON        // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = SBORDIS  // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
//#pragma config BOREN = ON
#pragma config BORV = 3         // Brown Out Reset Voltage bits (Minimum setting)

// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)
//#pragma config WDTPS = 128

// CONFIG3H
#pragma config CCP2MX = PORTC   // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as analog input channels on Reset)
//#pragma config PBADEN = ON
#pragma config LPT1OSC = OFF    // Low-Power Timer1 Oscillator Enable bit (Timer1 configured for higher power operation)
//#pragma config LPT1OSC = ON
#ifdef BREAD_BOARD_SETUP
#pragma config MCLRE = OFF      // MCLR Pin Enable bit (RE3 input pin enabled; MCLR disabled)
#else
#pragma config MCLRE = OFF      // MCLR Pin Enable bit (RE3 input pin enabled; MCLR disabled)
#endif

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))
//#pragma config XINST = ON

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000800-001FFFh) not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) not code-protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (004000-005FFFh) not code-protected)
#pragma config CP3 = OFF        // Code Protection bit (Block 3 (006000-007FFFh) not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000800-001FFFh) not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) not write-protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (004000-005FFFh) not write-protected)
#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (006000-007FFFh) not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot block (000000-0007FFh) not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000800-001FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (004000-005FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (006000-007FFFh) not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot block (000000-0007FFh) not protected from table reads executed in other blocks)



#ifdef BREAD_BOARD_SETUP
#define _XTAL_FREQ 20000000
#else
#define _XTAL_FREQ 40000000
#endif



// Defining IOs
#ifndef NEW_PCB_BOARD
#define PWMA         PORTCbits.RC2
#define PWMB         PORTCbits.RC1
#define M_A1         PORTBbits.RB7
#define M_A2         PORTBbits.RB6
#define M_B1         PORTBbits.RB3
#define M_B2         PORTBbits.RB2

#define MA_Tacho0    PORTAbits.RA1
#define MA_Tacho1    PORTAbits.RA2
#define MA_TachoXOR  PORTAbits.RA4
#define MB_Tacho0    PORTAbits.RA3
#define MB_Tacho1    PORTAbits.RA5
#define MB_TachoXOR  PORTCbits.RC0

#define BOARD_ID     PORTEbits.RE3
#define RS485_DE     PORTBbits.RB5 //RS485 write_enable active high, DE and RE shorted.

#define LED_STATUS   PORTAbits.RA0
#else
//new board
#define PWMA         PORTCbits.RC2
#define PWMB         PORTCbits.RC1
#define M_A1         PORTBbits.RB7
#define M_A2         PORTBbits.RB6
#define M_B1         PORTBbits.RB5
#define M_B2         PORTBbits.RB4

#define MA_Tacho0    PORTAbits.RA1
#define MA_Tacho1    PORTAbits.RA2
#define MA_TachoXOR  PORTAbits.RA4
#define MB_Tacho0    PORTAbits.RA3
#define MB_Tacho1    PORTAbits.RA5
#define MB_TachoXOR  PORTCbits.RC0

#define BOARD_ID     PORTBbits.RB3
#define RS485_DE     PORTCbits.RC5 //RS485 write_enable active high, DE and RE shorted.
#ifdef PCB_BOARD_VERIFY_LED
#define LED_STATUS   RS485_DE
#endif

#define SPARE_IN     PORTEbits.RE3
#define EXT_INTIO    PORTBbits.RB2
#define EXT_INT1     PORTBbits.RB1
#define EXT_INT0     PORTBbits.RB0
#define VMOT_MON     PORTAbits.RA0
#define MA_Status    PORTCbits.RC3
#define MB_Status    PORTCbits.RC4
#endif


// Be careful about baudrate error. Depending on the Fosc some baudrates can not be generated
// Below you can find a list of avialable baudrates for 16MHz and 20MHz:
// 16MHz: 1200, 2400, 4800, 9600, 19200, 250000
// 20MHz:     , 2400, 4800,
// Note: Only Low baudrate mode (BRGH = 0) is considered.
// Rev2 set BRGH=1 & use baud 19200
#define RS485_BAUDRATE          19200
#define PACKET_LENGTH           9
#define GLOBAL_ADDRESS          0xFF
#define CRC_POLYNOMIAL          0x1021 // CRC-CCITT, can change to CRC-16
#define CRC_INITIALE_VALUE      0x0000


/*T3 to give 10ms every interrupt*/
#define T3_START_COUNT_LO 0x2C
#define T3_START_COUNT_HI 0xCF


/*DEFINE*/
#define ENABLE_ACTIVE_LOW       0
#define ENABLE_ACTIVE_HIGH      1
#define DISABLE_ACTIVE_LOW      1
#define DISABLE_ACTIVE_HIGH     0
#define ENABLE                  1
#define DISABLE                 0
#define SET                     1
#define CLEAR                   0
#define ON                      1
#define OFF                     0
#define LED_ON                  1
#define LED_OFF                 0


//CMD Structure
/*
 * SOH      BORAD_ADDR      CMD     DATA1       DATA2       DATA3       DATA4       CRC1       CRC2
 */
#define CMD_POS_SOH         0
#define CMD_POS_ADDR        1
#define CMD_POS_CMD         2
#define CMD_POS_DATA1       3
#define CMD_POS_DATA2       4
#define CMD_POS_DATA3       5
#define CMD_POS_DATA4       6
#define CMD_POS_CRC         7
/**/
#define OK      0
#define ERROR   0xFF
#define SOH     0x55
/*CMD ID*/
#define CMD_MOTOR_A_FW              0x01
#define CMD_MOTOR_A_BW              0x02
#define CMD_MOTOR_A_STOP            0x03
#define CMD_MOTOR_B_FW              0x04
#define CMD_MOTOR_B_BW              0x05
#define CMD_MOTOR_B_STOP            0x06
#define CMD_MOTOR_READ_COUNT        0x07
#define CMD_MOTOR_A_MOVE_TO         0x08
#define CMD_MOTOR_B_MOVE_TO         0x09
#define CMD_PID_OUTPUT_LIMIT        0x0A
#define CMD_MOTOR_AB_MOVE_TO        0x0B
#ifndef NEW_PCB_BOARD
#define CMD_CONTROL_LED             0x1E
#endif
#define CMD_RESET_MAIN_MCU          0x1F
/*
 * Command example
//LED OFF
0x55 0xFF 0x1E 0x00 0x00 0x25 0xA4
0x55 0x01 0x1E 0x00 0x00 0x18 0xB3

//LED ON
0x55 0xFF 0x1E 0x01 0x00 0x16 0x95
0x55 0x01 0x1E 0x01 0x00 0x2B 0x82

//RESET
0x55 0xFF 0x1F 0x00 0x00 0x12 0x94
0x55 0x01 0x1F 0x00 0x00 0x2F 0x83

//A FW
0x55 0xFF 0x01 0x00 0x00 0x4A 0xF6
//A BW
0x55 0xFF 0x02 0x00 0x00 0x13 0xA6
//A STOP
0x55 0xFF 0x03 0x00 0x00 0x24 0x96
//B FW
0x55 0xFF 0x04 0x00 0x00 0xA1 0x06
//B BW
0x55 0xFF 0x05 0x00 0x00 0x96 0x36
//B STOP
0x55 0xFF 0x06 0x00 0x00 0xCF 0x66
 */


//motor
enum
{
    MOTOR_A,
    MOTOR_B
};

enum
{
    MOTOR_CONTROL_FW,
    MOTOR_CONTROL_BW,
    MOTOR_CONTROL_STOP
};

#define MOTOR_MAX_SPEED         80
#define MOTOR_SLOW_SPEED        10
#define MOTOR_VERY_SLOW_SPEED   5
#define MOTOR_SUPER_SLOW_SPEED  2


//extern
extern long MotorA_Position;
extern long motorATargetPos;
extern long MotorB_Position;
extern long motorBTargetPos;
#ifdef ENABLE_PID_CONTROL
extern unsigned char PID_OUTPUT_LIMIT;
#endif

#ifndef ENABLE_PID_CONTROL
#define MOTOR_STOP_CHECK_THRESHOLD  2
#endif

//Functions
//PIC_init.c
void Initialize(void);
//PIC_crc.c
unsigned char CheckCRC(unsigned char *inputData, unsigned char inputDataLength);
unsigned int GenerateCRC (unsigned char *inputData, unsigned char inputDataLength);
//PIC_serialport.c
void serial_Putch(unsigned char byte);
void serial_Putstr(const char *str, unsigned char length);
//PIC_motor.c
void PIC_Motor_Control(unsigned char target_A_B, unsigned char control, unsigned long move_steps);
void PIC_Motor_Move_To_Position(unsigned char target_A_B, long position);
void PIC_Motor_Speed_Configure(unsigned char target_A_B, unsigned long steps_delta);
#ifdef ENABLE_PID_CONTROL
void PIC_Motor_PID_Loop();
#endif
void PIC_Motor_FW(unsigned char target_A_B);
void PIC_Motor_BW(unsigned char target_A_B);
void PIC_Motor_STOP(unsigned char target_A_B);
