#include <p18f452.h>
#define RW PORTDbits.RD6
#define  RS PORTDbits.RD5
#define  E PORTDbits.RD4
#define lcd PORTC

unsigned char x,binbyte, d1,d2,d3;
unsigned char temp; unsigned int freq = 0;

#pragma config WDT = OFF

void delay(unsigned int i);

unsigned char msg[] = "frequency";
unsigned char msg2[5];
unsigned int freq;

void LCD_CMD(unsigned char i);
void LCD_DATA(unsigned char i );
void display(unsigned char * );
void Sendchar(unsigned char );


void main()
{
	LCD_CMD(0x38); // 8 bit mode 2 lines
  LCD_CMD(0x0C); // display ON, cursor OFF

 TRISAbits.TRISA4 = 1; // give square wave from A0
TRISB = 0x00; TRISD = 0x00; TRISC=0x00;
//T0CON = 0x68; //set up TMR0 as an 8 bit counter
T0CON = 0x28; // set up TMR0 as a 16 bit counter

	TMR0H = 0;
	TMR0L = 0;
	INTCONbits.TMR0IF = 0;
	T0CONbits.TMR0ON = 1;
	delay(490);
	T0CONbits.TMR0ON = 0;

//if(TMR0H==0)
//{
	binbyte = TMR0L;
	x=binbyte/10;
	d1 = binbyte%10; //LSD
	d2 = x%10; //middle digit
	d3 = x/10; // MSD

	d2 =d2 << 4;
	PORTB = d1|d2;
	PORTD = d3;
//}

	
	temp = TMR0L;
	freq = TMR0H;
	freq <<= 8;
	freq|= temp;
	
	LCD_CMD(0x80);
	itoa(freq,msg2);
	display(msg2);

if (freq >= 1000)
{
	PORTB = freq/1000;	PORTD = 0;
}

}

void delay(unsigned int time )
{ unsigned int d;unsigned char j;
  for( d=0;d<time;d++)
    for(j=0;j<135;j++);
}

//********************** LCD FUNCTIONS ****************************
void display(unsigned char *StringOfChars)
{
  while (*StringOfChars > 0)
  {
    Sendchar(*StringOfChars++);
  }
}

void Sendchar(unsigned char character)
{
  LCD_DATA(character);
}


  void  LCD_CMD(unsigned char i)
  { lcd=i;
    RS=0;
    
    RW=0;
    E=1;
    delay(1);
    E=0;
    
    }
    void LCD_DATA(unsigned char i )
    { 
      RS=1;
      lcd=i;
      RW=0;
      E=1;
      delay(1);
      E=0;      
    }

