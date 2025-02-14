/*******************************************************************************
  SYS PORTS Static Functions for PORTS System Service

  Company:
    Microchip Technology Inc.

  File Name:
    sys_ports_static.c

  Summary:
    SYS PORTS static function implementations for the Ports System Service.

  Description:
    The Ports System Service provides a simple interface to manage the ports
    on Microchip microcontrollers. This file defines the static implementation for the 
    Ports System Service.
    
  Remarks:
    Static functions incorporate all system ports configuration settings as
    determined by the user via the Microchip Harmony Configurator GUI.  It provides 
    static version of the routines, eliminating the need for an object ID or 
    object handle.

*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/
//DOM-IGNORE-END

#include "system_config.h"
#include "peripheral/ports/plib_ports.h"


void SYS_PORTS_Initialize(void)
{
    /* AN and CN Pins Initialization */
    PLIB_PORTS_AnPinsModeSelect(PORTS_ID_0, SYS_PORT_AD1PCFG, PORTS_PIN_MODE_DIGITAL);
    PLIB_PORTS_CnPinsPullUpEnable(PORTS_ID_0, SYS_PORT_CNPUE);
    PLIB_PORTS_CnPinsEnable(PORTS_ID_0, SYS_PORT_CNEN);
    PLIB_PORTS_ChangeNoticeEnable(PORTS_ID_0);
    
    /* PORT A Initialization */
    PLIB_PORTS_DirectionOutputSet( PORTS_ID_0, PORT_CHANNEL_A,  SYS_PORT_A_TRIS ^ 0xFFFF);
    PLIB_PORTS_OpenDrainEnable(PORTS_ID_0, PORT_CHANNEL_A, SYS_PORT_A_ODC);


//     PLIB_PORTS_DirectionOutputSet( PORTS_ID_0, PORT_CHANNEL_B,  SYS_PORT_B_TRIS ^ 0x80); //or 0b10 0000 00  for B7
//    PLIB_PORTS_DirectionOutputSet( PORTS_ID_0, PORT_CHANNEL_B,  SYS_PORT_B_TRIS ^ 0x2000); //or 0b10 0000 0000 0000 for B13
//    PLIB_PORTS_DirectionOutputSet( PORTS_ID_0, PORT_CHANNEL_B,  SYS_PORT_B_TRIS ^ 0x8000); //or 0b10 0000 00  for B15 --LED2
//
//    TRISBbits.TRISB7=0; //output
//     TRISBbits.TRISB15=0; //output
//    TRISBbits.TRISB13=1;
//    ANSELBbits.ANSB13 = 0; // 0 for digital, 1 for analog
//    PLIB_PORTS_OpenDrainEnable(PORTS_ID_0, PORT_CHANNEL_B, SYS_PORT_B_ODC);
    
}


/*******************************************************************************
 End of File
*/
