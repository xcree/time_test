//*****************************************************************************
//*****************************************************************************
//  FILENAME:  AMUX4_1.h
//  Version: 1.50, Updated on 2012/3/2 at 9:12:26
//  Generated by PSoC Designer 5.2.2551
//
//  DESCRIPTION:  AMux4 User Module C Language interface file.
//
//-----------------------------------------------------------------------------
//      Copyright (c) Cypress Semiconductor 2012. All Rights Reserved.
//*****************************************************************************
//*****************************************************************************
#ifndef AMUX4_1_INCLUDE
#define AMUX4_1_INCLUDE

#include <m8c.h>
//-------------------------------------------------
// Defines for AMUX4_1 API's.
//-------------------------------------------------
#define AMUX4_1_PORT0_0                0x00
#define AMUX4_1_PORT0_2                0x01
#define AMUX4_1_PORT0_4                0x02
#define AMUX4_1_PORT0_6                0x03

#define AMUX4_1_PORT0_1                0x00
#define AMUX4_1_PORT0_3                0x01
#define AMUX4_1_PORT0_5                0x02
#define AMUX4_1_PORT0_7                0x03


#pragma fastcall16 AMUX4_1_InputSelect
#pragma fastcall16 AMUX4_1_Start
#pragma fastcall16 AMUX4_1_Stop

//-------------------------------------------------
// Prototypes of the AMUX4_1 API.
//-------------------------------------------------

extern void AMUX4_1_InputSelect(BYTE bChannel);
extern void AMUX4_1_Start(void);
extern void AMUX4_1_Stop(void);

#endif
// end of file AMUX4_1.h