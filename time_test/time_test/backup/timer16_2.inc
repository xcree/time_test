;;*****************************************************************************
;;*****************************************************************************
;;  FILENAME: Timer16_2.inc
;;   Version: 2.6, Updated on 2012/3/2 at 9:15:25
;;  Generated by PSoC Designer 5.2.2551
;;
;;  DESCRIPTION: Assembler declarations for the Timer16 user module interface
;;-----------------------------------------------------------------------------
;;  Copyright (c) Cypress Semiconductor 2012. All Rights Reserved.
;;*****************************************************************************
;;*****************************************************************************

include "m8c.inc"


;--------------------------------------------------
; Constants for Timer16_2 API's.
;--------------------------------------------------

Timer16_2_CONTROL_REG_START_BIT:           equ 0x01    ; Control register start bit
Timer16_2_INT_REG:                         equ 0x0e1
Timer16_2_INT_MASK:                        equ 0x40


;--------------------------------------------------
; Constants for Timer16_2 user defined values
;--------------------------------------------------

Timer16_2_PERIOD:                          equ 0xfa00
Timer16_2_COMPARE_VALUE:                   equ 0x0


;--------------------------------------------------
; Register Address Constants for Timer16_2
;--------------------------------------------------

Timer16_2_COUNTER_LSB_REG:             equ 0x34   ; DR0 Counter register
Timer16_2_COUNTER_MSB_REG:             equ 0x38
Timer16_2_PERIOD_LSB_REG:              equ 0x35   ; DR1 Period register
Timer16_2_PERIOD_MSB_REG:              equ 0x39
Timer16_2_COMPARE_LSB_REG:             equ 0x36   ; DR2 CompareValue register
Timer16_2_COMPARE_MSB_REG:             equ 0x3a
Timer16_2_CONTROL_LSB_REG:             equ 0x37   ; Control register
Timer16_2_CONTROL_MSB_REG:             equ 0x3b
Timer16_2_FUNC_LSB_REG:                equ 0x34   ; Function register
Timer16_2_FUNC_MSB_REG:                equ 0x38
Timer16_2_INPUT_LSB_REG:               equ 0x35   ; Input register
Timer16_2_INPUT_MSB_REG:               equ 0x39
Timer16_2_OUTPUT_LSB_REG:              equ 0x36   ; Output register
Timer16_2_OUTPUT_MSB_REG:              equ 0x3a


;--------------------------------------------------
; Timer16_2 Macro 'Functions'
;--------------------------------------------------

   macro Timer16_2_Start_M
   or    reg[Timer16_2_CONTROL_LSB_REG],  Timer16_2_CONTROL_REG_START_BIT
   endm

   macro Timer16_2_Stop_M
   and   reg[Timer16_2_CONTROL_LSB_REG], ~Timer16_2_CONTROL_REG_START_BIT
   endm

   macro Timer16_2_EnableInt_M
   M8C_EnableIntMask Timer16_2_INT_REG, Timer16_2_INT_MASK
   endm

   macro Timer16_2_DisableInt_M
   M8C_DisableIntMask Timer16_2_INT_REG, Timer16_2_INT_MASK
   endm


; end of file Timer16_2.inc