//----------------------------------------------------------------------------
// C main line
//----------------------------------------------------------------------------

#include <m8c.h>        // part specific constants and macros
#include "PSoCAPI.h"    // PSoC API definitions for all User Modules
//#include "BPF2_1.h" 
#include <Timer16_2.h> 
#include <stdlib.h>  
#include <string.h> 
#include <stdio.h> 

//#ints
void My_gpio_p2_6(void);
void MyGpioISR_pwm(void);
void My_16_pwm_isr(void);
void My_t16_1_isr(void);
void My_t16_2(void);


#pragma interrupt_handler My_gpio_p2_6
#pragma interrupt_handler MyGpioISR_pwm
#pragma interrupt_handler My_t16_1_isr
#pragma interrupt_handler My_16_pwm_isr
#pragma interrupt_handler My_t16_2
//________________


int q;
BYTE pwm2,x,i,r,d,Channel,m_started;
char a[10],b[10];
char i=0,j=0;


//#f()
unsigned int ReadADCChannel(BYTE Channel);


//void TxZeroTerminatedRamString( BYTE *pbStrPtr );


void send_results(void);
void m_test (void);
void cur_read(void);
void adc_read(void);
void my_tx(void);

void dir_l(void);
void dir_r(void);
void crlf(void);
void led_t(void);
void led_on(void);
void led_off(void);
void led2_t(void);
void left(void);
void right(void);
void stop(void);
void p0_3_on(void);
void p0_3_off(void);
void p0_5_on(void);
void p0_5_off(void);

//_________________
float tempf;
unsigned long temp_l,tempf1,temp2;
unsigned int rot_time[10],rot_time1[10];
unsigned int temp0,temp1,temp3,vdi,vdiff;

unsigned char rc,cr,flag1,flag,r,vout,vset,vsetv,tx_tim;
BYTE Port1Shadow; 
unsigned int vstart,rot_count,iData;
unsigned char results,pwm_val,* p_i;
unsigned int vdiff_t[20];


unsigned int ADCResult;
unsigned int ADCResult0;
unsigned int ADCResult1;
unsigned int ADCResult2;
unsigned int ADCResult3;
BYTE test,vlf,x,s,cur_tx,vd;
char AsciiString[7];




void main(void)
{	
	m_started=0;
	test=0;
	vset=0;
	
	pwm2=0;
	
	temp_l=1920000;   //60sec 
	
	//vset=0x4d;	//1,5
	//vset=0xb5;	//3,5
	//vset=0xcf;	//4
	
	DigBuf_1_EnableInt();
	DigBuf_1_Start();

	
	PGA_1_Start(PGA_1_HIGHPOWER);
	
	M8C_EnableIntMask(INT_MSK0, INT_MSK0_GPIO);
	//BPF2_1_Start(BPF2_1_HIGHPOWER);
	////BPF2_2_Start(BPF2_2_HIGHPOWER);
	//PGA_1_SetGain(PGA_G8_00);
    ////PGA_1_Start(PGA_1_MEDPOWER);
	////PGA_2_Start(PGA_2_MEDPOWER);
	//PGA_3_Start(PGA_3_MEDPOWER);
	
	
	Timer16_1_EnableInt();
	Timer16_1_Start(); 
	Timer16_2_Start(); 
	//Timer16_2_EnableInt();
	//Timer16_2_Start(); 
	
	PWM16_1_EnableInt(); 
	PWM16_1_Start();
	
	//PWM8_1_EnableInt(); 
	PWM8_1_Start();
	PWM8_2_Start();
	PWM8_2_WritePulseWidth(pwm2); 
	
	
	M8C_EnableGInt ;
	while(1)
	{
				
					
		m_test();			
					
					
		
		//###########################
		//   Vset reg
		//##########################
		
		if((flag&0x80)==0)  //@200hz
			{
			//led_t();
			//tx_tim++;
			cur_tx++;
			flag |= 0x80;
			//led_t();	// 
			ADCResult3 = ReadADCChannel(3);
			//temp3=ADCResult3;
			ADCResult3 >>=3; //11bit to 8 bit
			vout=ADCResult3;
			ADCResult2 = ReadADCChannel(2);
			ADCResult2 >>=3;
			//vset=ADCResult2;
			
			if(vset>0)
			{
			if(vout>(vset+3))
				{
				if(pwm2>0)
				pwm2--;
				}
			if(vout<(vset-3))
				{
				if(pwm2<255)
				pwm2++;
				}	
				
			PWM8_2_WritePulseWidth(pwm2); 
			}
			if(vset==0)
			PWM8_2_WritePulseWidth(0); 
		//_________________________________
		
		
		
		if(cur_tx>20)	//curr read 
			{
			tx_tim++;
			cur_tx=0;
			cur_read();
			}	
		
		if(tx_tim>19)
			{
			tx_tim=0;
			my_tx();	// p2.3 tx
			}
				
		}
		
		if((flag&0x40)==0)
			{
			flag |= 0x40;
			//led_t();
			}
		
		
		if((flag&0x20)==0) // hall sens int
			{
			if(hall_in_Data_ADDR & hall_in_MASK){}
			
			if(m_started>2)
							{			
							m_started=3;
							}
					m_started++;
			
			
			//led_t();		
			
			flag |= 0x20;
			
			
			if((flag1&0x20)==0x20)
				{
				flag1&=~0x20; //clr data ready flag
				}
				
			rot_time[r]=Timer16_2_wReadTimer();
			Timer16_2_Stop(); 
			Timer16_2_WritePeriod(0xfa00);
			Timer16_2_Start();
			
			r++;
			if(r>1)
				{
				r=0;
				flag1|=0x20; //flag for data ready
				//rpm calc
				temp0=0xfa00 - rot_time[0];//64k-elapsed time
				temp1=0xfa00 - rot_time[1];//64k-elapsed time
				temp2=temp0+temp1;//sum
						}
			
			
			
			
			
			
			
			//flag1^=0x20;
			//if((flag1&0x20)==0) 
			//{
			//}
			}
			
			
			
			
		
		if((flag1&0x01)==0x00)		//p2.6 int routine
			{
			
			
			
			/*flag1 ^= 0x10;
			if((flag1&0x10) == 0x10)
				{
				Timer16_2_Start();
				Timer16_2_WritePeriod(3200);
				led_t();
				}
			else{
				rot_count = Timer16_2_wReadTimerSaveCV();  
				Timer16_2_Stop();
				}
			
			//flag1^=0x02;
			/*	/*
				if(flag1&0x02)
					{
					Timer16_2_Start();
					}
				else
					{
					rot_count = Timer16_2_wReadTimerSaveCV();  
					
					}
			*/
			//Timer16_2_Stop();
		//	rot_count = Timer16_2_wReadTimerSaveCV();  
			flag1 |= 0x01;
			}
		
	
	}
	// M8C_EnableGInt ; // Uncomment this line to enable Global Interrupts
	// Insert your main routine code here.
}



void m_test(void)
{
	switch (test)
				{
				case 0:		//start test
						if(m_started==3)
							{
							test=2;
							vstart=vout;
							//vset=0;
							//vfl=1;
							}
						if(vlf>16)
						{
						vset++;
						vlf=0;
						}
						
						vlf++;
						
						break;
				
						
				case 3:
						vset=0x3a;		//1V
						break;
						
				case 6:
						results=1; //send 1v results
						break;
				case 7:
						vset=0x53;	//1,5V
						break;
				case 10:
						results=15; //send 1,5v results
						break;
				
				case 11:
						vset=0x69;	//2V
						break;
				case 14:
						results=2; //send 2v results
						break;				
				case 15:
						vset=0x7e;	//2,5V
						break;
				case 18:
						results=25; //send 2,5v results
						break;		
				case 19:
						vset=0x97;	//3V
						break;
				case 22:
						results=3; //send 3v results
						break;				
				case 23:
						vset=0xad;	//3.5V
						break;
				case 26:
						results=35; //send 3,5v results
						break;		
				case 27:
						vset=0; //stop
						break;
				case 28:
						break;		
				case 29:
						break;	
						
				case 30:
						//vset=0;
						vstart=0;
						m_started=0;
						test=0;
						led_t();
						//Port1Shadow = PRT1DR ;
						//Port1Shadow ^= 0x04;     //p1.2
						//Port1Shadow &= ~0x04;	//p0.7
						//Port1Shadow |= 0x28;	//p0.5,p0.3
						//Port1Shadow |= 0xa8;	//p0.7,p0.5,p0.3
						//PRT1DR = Port1Shadow;
						break;
				
				
				default:
						break;
				}
			

}







//####################################
//###       IRQ
//####################################

void My_gpio_p2_6(void)
{

flag1 &= ~0x01;
}

void My_t16_1_isr(void)
{
#pragma nomac
//led_t();
//led2_t();
flag &= ~0x80;
return;
}

void My_16_pwm_isr(void)
{
//#pragma nomac
//led_t();
//led2_t();
flag &= ~0x40;
return;
}


void My_t16_2(void)
{
//#pragma nomac
//led_t();
//led2_t();
//flag &= ~0x80;
return;
}

void MyGpioISR_pwm(void)
{	
//led_t();
flag &= ~0x20;

}
//____________________________________



//####################################
//####        f()
//###################################

void adc_read(void)
{
		ADCINC_1_Start(ADCINC_1_HIGHPOWER);       // Apply power to the SC Block 
		ADCINC_1_GetSamples(5);                 // Have ADC run continuously 
		
				while(ADCINC_1_fIsDataAvailable() == 0);   // Loop until value ready 
				ADCINC_1_iClearFlagGetData();              // Clear ADC flag and get data 
				// Add user code here to use or display result 
				iData = ADCINC_1_wGetData();
				iData >>= 2;
				
				vout = iData;
				
				
			//iData = ADCINC_1_wGetData();
			ADCINC_1_Stop();
			
			}

void left (void)
	{
	flag1 |= 0x40;
	flag1 &= ~0x80;
	return;
	}

void right (void)
	{
	flag1 |= 0x80;
	flag1 &= ~0x40;
	return;
	}

void stop (void)
	{
	PWM8_1_WritePulseWidth(0);
	}

void cur_read(void)
{
//curr meas
		ADCResult1 = ReadADCChannel(1);
		temp3 = ReadADCChannel(3);
		vdi=ADCResult1-temp3; 
		vdi*=5;	////12bit@5v scale--->>vdiffx5/4=(u(mV)) 
		vdi/=2;
		vdiff_t[vd] = vdi/10; //current in mA
		if(vd<20)
		vd++;
		if(vd==19)
			{
			vd=0;
			for ( s = 0; s < 20; ++s )
				{
    			 vdiff = vdiff + vdiff_t[s];
				 }
			vdiff =vdiff/20;
				 
			}
		
		
}
void my_tx(void)
{		
		
		
		if(d>5)
		{
		d=0;
		//dir_l();
		}
		//if(d==3){ dir_r();}
		if(test>=2)
		{test++;}
		
		if(test==28)
		{test=30;}
		
		cr++;
	
			
		 TX8_1_Start(TX8_1_PARITY_NONE);
		
			
			//crlf();
				
			
			//csprintf(b,"t = %d xx ",temp0);
			//TX8_1_PutString(b);
			//crlf();
			
			send_results();
			
			
			/*
			csprintf(b,"started@ %d V ",vstart);
			TX8_1_PutString(b);
			crlf();
			
			
			temp0=temp_l/temp2;
			csprintf(b,"R = %d U/min ",temp0);
			TX8_1_PutString(b);
			crlf();
			
			
			vsetv=vout*1.95;  //11bit voltage value (*2 )
			csprintf(b,"U = %d V ",vsetv);
			TX8_1_PutString(b);
			crlf();
			
			csprintf(b,"I = %d mA ",vdiff);
			TX8_1_PutString(b);
			crlf();
			
			
			itoa(a,cr,10);
			TX8_1_PutString(a);
			crlf();
			/*
			
			/*
			TX8_1_PutSHexInt(temp0);
			while( !( TX8_1_bReadTxStatus() & TX8_TX_COMPLETE ) );
			crlf();	
			
			//TX8_1_PutString("start_volt");
			while( !( TX8_1_bReadTxStatus() & TX8_TX_COMPLETE ) );
			TX8_1_PutCRLF();							//Do a Line and Carriage Return
				//Wait until TX operation Complete
			while( !( TX8_1_bReadTxStatus() & TX8_TX_COMPLETE ) );
			while( !( TX8_1_bReadTxStatus() & TX8_TX_COMPLETE ) );
			*/
			
		TX8_1_Stop();
		
}


void TxZeroTerminatedRamString( BYTE *pbStrPtr )
{
    TX8_1_PutString(pbStrPtr);

}


void led_t(void)
{
Port1Shadow = PRT0DR ;
		//Port1Shadow |= 0x80;
		Port1Shadow ^= 0x80;  //toggle p0.7
		PRT0DR = Port1Shadow;
		return;
}

void led2_t(void)
{
Port1Shadow = PRT0DR ;
		//Port1Shadow |= 0x80;
		Port1Shadow ^= 0x40; //toggle p0.6
		PRT0DR = Port1Shadow;
		return;
}

void led_on(void)
{
Port1Shadow = PRT0DR ;
		//Port1Shadow |= 0x80;
		//Port1Shadow |= 0x80;	//p0.7
		Port1Shadow |= 0x28;	//p0.5,p0.3
		//Port1Shadow |= 0xa8;	//p0.7,p0.5,p0.3
		PRT0DR = Port1Shadow;
}

void led_off(void)
{
Port1Shadow = PRT0DR ;
		//Port1Shadow |= 0x80;
		//Port1Shadow &= ~0x80;
		Port1Shadow &= ~0x28;	//p0.5,p0.3
		//Port1Shadow &= ~0xa8;	//p0.7,p0.5,p0.3
		PRT0DR = Port1Shadow;
}

void p0_3_on(void)
{
Port1Shadow = PRT0DR ;
		Port1Shadow |= 0x08;     //p03
		//Port1Shadow |= 0x80;	//p0.7
		//Port1Shadow |= 0x28;	//p0.5,p0.3
		//Port1Shadow |= 0xa8;	//p0.7,p0.5,p0.3
		PRT0DR = Port1Shadow;
}

void p0_3_off(void)
{
Port1Shadow = PRT0DR ;
		//Port1Shadow |= 0x08;
		//Port1Shadow &= ~0x80;
		Port1Shadow &= ~0x08;	//p0.5,p0.3
		//Port1Shadow &= ~0xa8;	//p0.7,p0.5,p0.3
		PRT0DR = Port1Shadow;
}


void p0_5_on(void)
{
Port1Shadow = PRT0DR ;
		Port1Shadow |= 0x20;     //p03
		//Port1Shadow |= 0x80;	//p0.7
		//Port1Shadow |= 0x28;	//p0.5,p0.3
		//Port1Shadow |= 0xa8;	//p0.7,p0.5,p0.3
		PRT0DR = Port1Shadow;
}

void p0_5_off(void)
{
Port1Shadow = PRT0DR ;
		//Port1Shadow |= 0x08;
		//Port1Shadow &= ~0x80;
		Port1Shadow &= ~0x20;	//p0.5,p0.3
		//Port1Shadow &= ~0xa8;	//p0.7,p0.5,p0.3
		PRT0DR = Port1Shadow;
}


//	0 - P0[7]
//	1 - P0[5]
//	2 - P0[3]
//	3 - P0[1]
unsigned int ReadADCChannel(BYTE Channel)
{	


	ADCINC_1_Start(ADCINC_1_HIGHPOWER);
	
	AMUX4_1_Start();
	//int ADCResult;
	//BYTE x;
	
	switch (Channel)
	{
		case 0:
			// Connect P0[7] to Mux Bus
			//MUX_CR0 |= 0x80;
			AMUX4_1_InputSelect(AMUX4_1_PORT0_7);
			
			break;
			
		case 1:
			// Connect P0[5] to Mux Bus
			AMUX4_1_InputSelect(AMUX4_1_PORT0_5);
			break;
			
		case 2:
			// Connect P0[3] to Mux Bus
			AMUX4_1_InputSelect(AMUX4_1_PORT0_3);
			break;
			
		case 3:
			// Connect P0[1] to Mux Bus
			AMUX4_1_InputSelect(AMUX4_1_PORT0_1);
			break;
			
			
			
	}
		
	// Give a small delay for the signal to settle at the PGA output. With the PGA
	// operating at Highpower this takes less than a microsecond.  For low power operation
	// this should be 6uS.  Refer the AC op amp electrical characteristics in the
	// device data sheet
	for (x = 0; x < 25; x++) {};
	
	// Start conversion of ADC
	ADCINC_1_GetSamples(3);
	
	
		while(!(ADCINC_1_fIsDataAvailable()));
			
			// Read the ADC result and clear the data ready flag
			ADCResult=ADCINC_1_iClearFlagGetData();
			
	/*
	for(i=0; i<3; i++)
		{
		// Wait till ADC conversion is over
			while(!(ADCINC_1_fIsDataAvailable()));
			
			// Read the ADC result and clear the data ready flag
			ADCResult=ADCINC_1_iClearFlagGetData();
			
			//ADCResult0=ADCResult;
		} 
	*/
	// Disconnect all the pins from Mux Bus
	//MUX_CR0 &= ~0xaa;	// Disconnect P0[7],P0[5],P0[3],P0[1]
	//MUX_CR0 &= ~0x28;	// Disconnect P0[5] and P0[3]
	//MUX_CR3 &= ~0x42;	// Disconnect P3[6] and P3[1]

	// Return the result
	
	ADCINC_1_Stop();
	AMUX4_1_Stop();
	//ADCResult>>=2;
	return ADCResult;
}

void send_results(void)
{
if(results>0)
			{
			temp0=temp_l/temp2;
			csprintf(b,"@%dV,R= %d U/min ",results,temp0);
			TX8_1_PutString(b);
			crlf();
			
			csprintf(b,"I = %d mA ",vdiff);
			TX8_1_PutString(b);
			crlf();
			
			csprintf(b,"started@ %d V ",vstart);
			TX8_1_PutString(b);
			crlf();
			crlf();
			results=0;
			}
			
}



void crlf(void)
{
TX8_1_PutCRLF();							//Do a Line and Carriage Return
				//Wait until TX operation Complete
			while( !( TX8_1_bReadTxStatus() & TX8_TX_COMPLETE ) );
			while( !( TX8_1_bReadTxStatus() & TX8_TX_COMPLETE ) );
}

void dir_l(void)
{
Port1Shadow = PRT1DR ;
		Port1Shadow |= 0x04;     //p1.2
		Port1Shadow &= ~0x10;	//p0.7
		//Port1Shadow |= 0x28;	//p0.5,p0.3
		//Port1Shadow |= 0xa8;	//p0.7,p0.5,p0.3
		PRT1DR = Port1Shadow;
}


void dir_r(void)
{
Port1Shadow = PRT1DR ;
		Port1Shadow |= 0x10;     //p1.2
		Port1Shadow &= ~0x04;	//p0.7
		//Port1Shadow |= 0x28;	//p0.5,p0.3
		//Port1Shadow |= 0xa8;	//p0.7,p0.5,p0.3
		PRT1DR = Port1Shadow;
}

/*
for ( s = 0; s < 5; ++s )
				{
				 temp0=0xfa00 - rot_time[s];//64k-elapsed time
				 temp1=0xfa00 - rot_time[s+1];//64k-elapsed time
				 temp_s[s]=temp0+temp1;//sum
				 }
			for ( s = 0; s < 5; ++s )
				{
    			 temp2 = temp2+ temp_s[s];
				 }
			temp2 =temp2/4;
*/