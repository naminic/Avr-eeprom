/*****************************************************
Chip type               : ATmega32
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 512
*****************************************************/

#include <mega32.h>
#include <delay.h>

eeprom unsigned char led_state;

void main(void)
{
int i=0;

DDRC=0x0D; 
PORTC=0x7C;       //pins(0,2) defined out with zero value and pins(4,5,6) defined in with pull up.

PORTC &=led_state;
delay_ms(10);     

while (1)
      {
       if(PINC.4==0)    //mark pin(4) when pushed.
       {
          i=1;
       }
       if(PINC.4==1 && i==1)     //detect pin(4) as a user selected pin when released.  
       {
          i=0;
          led_state &=0xF7;
          delay_ms(10);
          PORTC &=0xF7;
       }
       
       if(PINC.5==0)
       {
          i=2;
       }
       if(PINC.5==1 && i==2)
       {
          i=0;
          led_state &=0xFB;
          delay_ms(10);
          PORTC &=0xFB;
       }
       
       if(PINC.6==0)
       {
          i=3;
       }
       if(PINC.6==1 && i==3)
       {
          i=0;
          led_state =0xFF;
          delay_ms(10);
          PORTC |=0x0C;
       }
      }//end of while(1).
}
