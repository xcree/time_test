;;*****************************************************************************
;;*****************************************************************************
;;  FILENAME: Timer16_1.asm
;;   Version: 2.6, Updated on 2012/3/2 at 9:15:25
;;  Generated by PSoC Designer 5.2.2551
;;
;;  DESCRIPTION: Timer16 User Module software implementation file
;;
;;  NOTE: User Module APIs conform to the fastcall16 convention for marshalling
;;        arguments and observe the associated "Registers are volatile" policy.
;;        This means it is the caller's responsibility to preserve any values
;;        in the X and A registers that are still needed after the API functions
;;        returns. For Large Memory Model devices it is also the caller's 
;;        responsibility to perserve any value in the CUR_PP, IDX_PP, MVR_PP and 
;;        MVW_PP registers. Even though some of these registers may not be modified
;;        now, there is no guarantee that will remain the case in future releases.
;;-----------------------------------------------------------------------------
;;  Copyright (c) Cypress Semiconductor 2012. All Rights Reserved.
;;*****************************************************************************
;;*****************************************************************************

include "m8c.inc"
include "memory.inc"
include "Timer16_1.inc"

;-----------------------------------------------
;  Global Symbols
;-----------------------------------------------
export  Timer16_1_EnableInt
export _Timer16_1_EnableInt
export  Timer16_1_DisableInt
export _Timer16_1_DisableInt
export  Timer16_1_Start
export _Timer16_1_Start
export  Timer16_1_Stop
export _Timer16_1_Stop
export  Timer16_1_WritePeriod
export _Timer16_1_WritePeriod
export  Timer16_1_WriteCompareValue
export _Timer16_1_WriteCompareValue
export  Timer16_1_wReadCompareValue
export _Timer16_1_wReadCompareValue
export  Timer16_1_wReadTimer
export _Timer16_1_wReadTimer
export  Timer16_1_wReadTimerSaveCV
export _Timer16_1_wReadTimerSaveCV

; The following functions are deprecated and subject to omission in future releases
;
export  wTimer16_1_ReadCompareValue  ; deprecated
export _wTimer16_1_ReadCompareValue  ; deprecated
export  wTimer16_1_ReadTimer         ; deprecated
export _wTimer16_1_ReadTimer         ; deprecated
export  wTimer16_1_ReadTimerSaveCV   ; deprecated
export _wTimer16_1_ReadTimerSaveCV   ; deprecated

export  wTimer16_1_ReadCounter       ; obsolete
export _wTimer16_1_ReadCounter       ; obsolete
export  wTimer16_1_CaptureCounter    ; obsolete
export _wTimer16_1_CaptureCounter    ; obsolete


AREA time_test_RAM (RAM,REL)

;-----------------------------------------------
;  Constant Definitions
;-----------------------------------------------


;-----------------------------------------------
; Variable Allocation
;-----------------------------------------------


AREA UserModules (ROM, REL)

.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: Timer16_1_EnableInt
;
;  DESCRIPTION:
;     Enables this timer's interrupt by setting the interrupt enable mask bit
;     associated with this User Module. This function has no effect until and
;     unless the global interrupts are enabled (for example by using the
;     macro M8C_EnableGInt).
;-----------------------------------------------------------------------------
;
;  ARGUMENTS:    None.
;  RETURNS:      Nothing.
;  SIDE EFFECTS: 
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to perserve their values across calls to fastcall16 
;    functions.
;
 Timer16_1_EnableInt:
_Timer16_1_EnableInt:
   RAM_PROLOGUE RAM_USE_CLASS_1
   Timer16_1_EnableInt_M
   RAM_EPILOGUE RAM_USE_CLASS_1
   ret

.ENDSECTION


.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: Timer16_1_DisableInt
;
;  DESCRIPTION:
;     Disables this timer's interrupt by clearing the interrupt enable
;     mask bit associated with this User Module.
;-----------------------------------------------------------------------------
;
;  ARGUMENTS:    None
;  RETURNS:      Nothing
;  SIDE EFFECTS: 
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to perserve their values across calls to fastcall16 
;    functions.
;
 Timer16_1_DisableInt:
_Timer16_1_DisableInt:
   RAM_PROLOGUE RAM_USE_CLASS_1
   Timer16_1_DisableInt_M
   RAM_EPILOGUE RAM_USE_CLASS_1
   ret

.ENDSECTION


.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: Timer16_1_Start
;
;  DESCRIPTION:
;     Sets the start bit in the Control register of this user module.  The
;     timer will begin counting on the next input clock.
;-----------------------------------------------------------------------------
;
;  ARGUMENTS:    None
;  RETURNS:      Nothing
;  SIDE EFFECTS: 
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to perserve their values across calls to fastcall16 
;    functions.
;
 Timer16_1_Start:
_Timer16_1_Start:
   RAM_PROLOGUE RAM_USE_CLASS_1
   Timer16_1_Start_M
   RAM_EPILOGUE RAM_USE_CLASS_1
   ret

.ENDSECTION


.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: Timer16_1_Stop
;
;  DESCRIPTION:
;     Disables timer operation by clearing the start bit in the Control
;     register of the LSB block.
;-----------------------------------------------------------------------------
;
;  ARGUMENTS:    None
;  RETURNS:      Nothing
;  SIDE EFFECTS: 
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to perserve their values across calls to fastcall16 
;    functions.
;
 Timer16_1_Stop:
_Timer16_1_Stop:
   RAM_PROLOGUE RAM_USE_CLASS_1
   Timer16_1_Stop_M
   RAM_EPILOGUE RAM_USE_CLASS_1
   ret

.ENDSECTION


.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: Timer16_1_WritePeriod
;
;  DESCRIPTION:
;     Write the 16-bit period value into the Period register (DR1). If the
;     Timer user module is stopped, then this value will also be latched
;     into the Count register (DR0).
;-----------------------------------------------------------------------------
;
;  ARGUMENTS: fastcall16 WORD wPeriodValue (LSB in A, MSB in X)
;  RETURNS:   Nothing
;  SIDE EFFECTS:
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to perserve their values across calls to fastcall16 
;    functions.
;
 Timer16_1_WritePeriod:
_Timer16_1_WritePeriod:
   RAM_PROLOGUE RAM_USE_CLASS_1
   mov   reg[Timer16_1_PERIOD_LSB_REG], A
   mov   A, X
   mov   reg[Timer16_1_PERIOD_MSB_REG], A
   RAM_EPILOGUE RAM_USE_CLASS_1
   ret

.ENDSECTION


.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: Timer16_1_WriteCompareValue
;
;  DESCRIPTION:
;     Writes compare value into the Compare register (DR2).
;
;     NOTE! The Timer user module must be STOPPED in order to write the
;           Compare register. (Call Timer16_1_Stop to disable).
;-----------------------------------------------------------------------------
;
;  ARGUMENTS:    fastcall16 WORD wCompareValue (LSB in A, MSB in X)
;  RETURNS:      Nothing
;  SIDE EFFECTS: 
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to perserve their values across calls to fastcall16 
;    functions.
;
 Timer16_1_WriteCompareValue:
_Timer16_1_WriteCompareValue:
   RAM_PROLOGUE RAM_USE_CLASS_1
   mov   reg[Timer16_1_COMPARE_LSB_REG], A
   mov   A, X
   mov   reg[Timer16_1_COMPARE_MSB_REG], A
   RAM_EPILOGUE RAM_USE_CLASS_1
   ret

.ENDSECTION


.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: Timer16_1_wReadCompareValue
;
;  DESCRIPTION:
;     Reads the Compare registers.
;-----------------------------------------------------------------------------
;
;  ARGUMENTS:    None
;  RETURNS:      fastcall16 WORD wCompareValue (value of DR2 in the X & A registers)
;  SIDE EFFECTS: 
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to perserve their values across calls to fastcall16 
;    functions.
;
 Timer16_1_wReadCompareValue:
_Timer16_1_wReadCompareValue:
 wTimer16_1_ReadCompareValue:                    ; this name deprecated
_wTimer16_1_ReadCompareValue:                    ; this name deprecated
   RAM_PROLOGUE RAM_USE_CLASS_1
   mov   A, reg[Timer16_1_COMPARE_MSB_REG]
   mov   X, A
   mov   A, reg[Timer16_1_COMPARE_LSB_REG]
   RAM_EPILOGUE RAM_USE_CLASS_1
   ret

.ENDSECTION


.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: Timer16_1_wReadTimerSaveCV
;
;  DESCRIPTION:
;     Returns the value in the Count register (DR0), preserving the
;     value in the compare register (DR2).
;-----------------------------------------------------------------------------
;
;  ARGUMENTS: None
;  RETURNS:   fastcall16 WORD wCount (value of DR0 in the X & A registers)
;  SIDE EFFECTS:
;     1) May cause an interrupt, if interrupt on Compare is enabled.
;     2) If enabled, Global interrupts are momentarily disabled.
;     3) The user module is stopped momentarily while the compare value is
;        restored.  This may cause the Count register to miss one or more
;        counts depending on the input clock speed.
;     4) The A and X registers may be modified by this or future implementations
;        of this function.  The same is true for all RAM page pointer registers in
;        the Large Memory Model.  When necessary, it is the calling function's
;        responsibility to perserve their values across calls to fastcall16 
;        functions.
;
;  THEORY of OPERATION:
;     1) Read and save the Compare register.
;     2) Read the Count register, causing its data to be latched into
;        the Compare register.
;     3) Read and save the Counter value, now in the Compare register,
;        to the buffer.
;     4) Disable global interrupts
;     5) Halt the timer
;     6) Restore the Compare register values
;     7) Start the Timer again
;     8) Restore global interrupt state
;
 Timer16_1_wReadTimerSaveCV:
_Timer16_1_wReadTimerSaveCV:
 wTimer16_1_ReadTimerSaveCV:                     ; this name deprecated
_wTimer16_1_ReadTimerSaveCV:                     ; this name deprecated
 wTimer16_1_ReadCounter:                         ; this name deprecated
_wTimer16_1_ReadCounter:                         ; this name deprecated

CpuFlags:      equ   0
wCount_MSB:    equ   1
wCount_LSB:    equ   2

   RAM_PROLOGUE RAM_USE_CLASS_2
   mov   X, SP                                   ; X <- stack frame pointer
   add   SP, 3                                   ; Reserve space for flags, count
   mov   A, reg[Timer16_1_CONTROL_LSB_REG]       ; save the Control register
   push  A
   mov   A, reg[Timer16_1_COMPARE_LSB_REG]       ; save the Compare register
   push  A
   mov   A, reg[Timer16_1_COMPARE_MSB_REG]
   push  A
   mov   A, reg[Timer16_1_COUNTER_LSB_REG]       ; synchronous copy DR2 <- DR0
                                                 ; This may cause an interrupt!
   mov   A, reg[Timer16_1_COMPARE_MSB_REG]       ; Now grab DR2 (DR0) and save
   mov   [X+wCount_MSB], A
   mov   A, reg[Timer16_1_COMPARE_LSB_REG]
   mov   [X+wCount_LSB], A
   mov   A, 0                                    ; Guess the global interrupt state
   tst   reg[CPU_F], FLAG_GLOBAL_IE              ; Currently Disabled?
   jz    .SetupStatusFlag                        ;   Yes, guess was correct
   mov   A, FLAG_GLOBAL_IE                       ;    No, modify our guess
.SetupStatusFlag:                                ; and ...
   mov   [X+CpuFlags], A                         ;   StackFrame[0] <- Flag Reg image
   M8C_DisableGInt                               ; Disable interrupts globally
   Timer16_1_Stop_M                              ; Disable (stop) the timer
   pop   A                                       ; Restore the Compare register
   mov   reg[Timer16_1_COMPARE_MSB_REG], A
   pop   A
   mov   reg[Timer16_1_COMPARE_LSB_REG], A
   pop   A                                       ; restore start state of the timer
   mov   reg[Timer16_1_CONTROL_LSB_REG], A
   pop   A                                       ; Return result stored in stack frame
   pop   X
   RAM_EPILOGUE RAM_USE_CLASS_2
   reti                                          ; Flag Reg <- StackFrame[0]

.ENDSECTION


.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: Timer16_1_wReadTimer
;
;  DESCRIPTION:
;     Performs a software capture of the Count register.  A synchronous
;     read of the Count register is performed.  The timer is NOT stopped.
;
;     WARNING - this will cause loss of data in the Compare register.
;-----------------------------------------------------------------------------
;
;  ARGUMENTS:    None
;  RETURNS:      fastcall16 WORD wCount, (value of DR0 in the X & A registers)
;  SIDE EFFECTS:
;    May cause an interrupt.
;
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to perserve their values across calls to fastcall16 
;    functions.
;
;  THEORY of OPERATION:
;     1) Read the Count register - this causes the count value to be
;        latched into the Compare registers.
;     2) Read and return the Count register values from the Compare
;        registers into the return buffer.
;
 Timer16_1_wReadTimer:
_Timer16_1_wReadTimer:
 wTimer16_1_ReadTimer:                           ; this name deprecated
_wTimer16_1_ReadTimer:                           ; this name deprecated
 wTimer16_1_CaptureCounter:                      ; this name deprecated
_wTimer16_1_CaptureCounter:                      ; this name deprecated

   RAM_PROLOGUE RAM_USE_CLASS_1
   mov   A, reg[Timer16_1_COUNTER_LSB_REG]       ; synchronous copy DR2 <- DR0
                                                 ; This may cause an interrupt!

   mov   A, reg[Timer16_1_COMPARE_MSB_REG]       ; Return DR2 (actually DR0)
   mov   X, A
   mov   A, reg[Timer16_1_COMPARE_LSB_REG]
   RAM_EPILOGUE RAM_USE_CLASS_1
   ret

.ENDSECTION

; End of File Timer16_1.asm
