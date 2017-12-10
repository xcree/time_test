//*****************************************************************************
//*****************************************************************************
//  FILENAME: Timer16_2.h
//   Version: 2.6, Updated on 2012/3/2 at 9:15:25
//  Generated by PSoC Designer 5.2.2551
//
//  DESCRIPTION: Timer16 User Module C Language interface file
//-----------------------------------------------------------------------------
//  Copyright (c) Cypress Semiconductor 2012. All Rights Reserved.
//*****************************************************************************
//*****************************************************************************
#ifndef Timer16_2_INCLUDE
#define Timer16_2_INCLUDE

#include <m8c.h>

#pragma fastcall16 Timer16_2_EnableInt
#pragma fastcall16 Timer16_2_DisableInt
#pragma fastcall16 Timer16_2_Start
#pragma fastcall16 Timer16_2_Stop
#pragma fastcall16 Timer16_2_wReadTimer                // Read  DR0
#pragma fastcall16 Timer16_2_wReadTimerSaveCV          // Read  DR0      
#pragma fastcall16 Timer16_2_WritePeriod               // Write DR1
#pragma fastcall16 Timer16_2_wReadCompareValue         // Read  DR2
#pragma fastcall16 Timer16_2_WriteCompareValue         // Write DR2

// The following symbols are deprecated.
// They may be omitted in future releases
//
#pragma fastcall16 wTimer16_2_ReadCounter              // Read  DR0 "Obsolete"
#pragma fastcall16 wTimer16_2_CaptureCounter           // Read  DR0 "Obsolete"
#pragma fastcall16 wTimer16_2_ReadTimer                // Read  DR0 (Deprecated)
#pragma fastcall16 wTimer16_2_ReadTimerSaveCV          // Read  DR0 (Deprecated)
#pragma fastcall16 wTimer16_2_ReadCompareValue         // Read  DR2 (Deprecated)


//-------------------------------------------------
// Prototypes of the Timer16_2 API.
//-------------------------------------------------

extern void Timer16_2_EnableInt(void);                           // Proxy 1
extern void Timer16_2_DisableInt(void);                          // Proxy 1
extern void Timer16_2_Start(void);                               // Proxy 1
extern void Timer16_2_Stop(void);                                // Proxy 1
extern WORD Timer16_2_wReadTimer(void);                          // Proxy 1
extern WORD Timer16_2_wReadTimerSaveCV(void);                    // Proxy 2
extern void Timer16_2_WritePeriod(WORD wPeriod);                 // Proxy 1
extern WORD Timer16_2_wReadCompareValue(void);                   // Proxy 1
extern void Timer16_2_WriteCompareValue(WORD wCompareValue);     // Proxy 1

// The following functions are deprecated.
// They may be omitted in future releases
//
extern WORD wTimer16_2_ReadCompareValue(void);       // Deprecated
extern WORD wTimer16_2_ReadTimerSaveCV(void);        // Deprecated
extern WORD wTimer16_2_ReadCounter(void);            // Obsolete
extern WORD wTimer16_2_ReadTimer(void);              // Deprecated
extern WORD wTimer16_2_CaptureCounter(void);         // Obsolete


//--------------------------------------------------
// Constants for Timer16_2 API's.
//--------------------------------------------------

#define Timer16_2_CONTROL_REG_START_BIT        ( 0x01 )
#define Timer16_2_INT_REG_ADDR                 ( 0x0e1 )
#define Timer16_2_INT_MASK                     ( 0x40 )


//--------------------------------------------------
// Constants for Timer16_2 user defined values
//--------------------------------------------------

#define Timer16_2_PERIOD                       ( 0xfa00 )
#define Timer16_2_COMPARE_VALUE                ( 0x0 )


//-------------------------------------------------
// Register Addresses for Timer16_2
//-------------------------------------------------

#pragma ioport  Timer16_2_COUNTER_LSB_REG:  0x034          //Count register LSB
BYTE            Timer16_2_COUNTER_LSB_REG;
#pragma ioport  Timer16_2_COUNTER_MSB_REG:  0x038          //Count register MSB
BYTE            Timer16_2_COUNTER_MSB_REG;
#pragma ioport  Timer16_2_PERIOD_LSB_REG:   0x035          //Period register LSB
BYTE            Timer16_2_PERIOD_LSB_REG;
#pragma ioport  Timer16_2_PERIOD_MSB_REG:   0x039          //Period register MSB
BYTE            Timer16_2_PERIOD_MSB_REG;
#pragma ioport  Timer16_2_COMPARE_LSB_REG:  0x036          //Compare register LSB
BYTE            Timer16_2_COMPARE_LSB_REG;
#pragma ioport  Timer16_2_COMPARE_MSB_REG:  0x03a          //Compare register MSB
BYTE            Timer16_2_COMPARE_MSB_REG;
#pragma ioport  Timer16_2_CONTROL_LSB_REG:  0x037          //Control register LSB
BYTE            Timer16_2_CONTROL_LSB_REG;
#pragma ioport  Timer16_2_CONTROL_MSB_REG:  0x03b          //Control register MSB
BYTE            Timer16_2_CONTROL_MSB_REG;
#pragma ioport  Timer16_2_FUNC_LSB_REG: 0x134              //Function register LSB
BYTE            Timer16_2_FUNC_LSB_REG;
#pragma ioport  Timer16_2_FUNC_MSB_REG: 0x138              //Function register MSB
BYTE            Timer16_2_FUNC_MSB_REG;
#pragma ioport  Timer16_2_INPUT_LSB_REG:    0x135          //Input register LSB
BYTE            Timer16_2_INPUT_LSB_REG;
#pragma ioport  Timer16_2_INPUT_MSB_REG:    0x139          //Input register MSB
BYTE            Timer16_2_INPUT_MSB_REG;
#pragma ioport  Timer16_2_OUTPUT_LSB_REG:   0x136          //Output register LSB
BYTE            Timer16_2_OUTPUT_LSB_REG;
#pragma ioport  Timer16_2_OUTPUT_MSB_REG:   0x13a          //Output register MSB
BYTE            Timer16_2_OUTPUT_MSB_REG;
#pragma ioport  Timer16_2_INT_REG:       0x0e1             //Interrupt Mask Register
BYTE            Timer16_2_INT_REG;


//-------------------------------------------------
// Timer16_2 Macro 'Functions'
//-------------------------------------------------

#define Timer16_2_Start_M \
   ( Timer16_2_CONTROL_LSB_REG |=  Timer16_2_CONTROL_REG_START_BIT )

#define Timer16_2_Stop_M  \
   ( Timer16_2_CONTROL_LSB_REG &= ~Timer16_2_CONTROL_REG_START_BIT )

#define Timer16_2_EnableInt_M   \
   M8C_EnableIntMask(  Timer16_2_INT_REG, Timer16_2_INT_MASK )

#define Timer16_2_DisableInt_M  \
   M8C_DisableIntMask( Timer16_2_INT_REG, Timer16_2_INT_MASK )

#endif
// end of file Timer16_2.h
