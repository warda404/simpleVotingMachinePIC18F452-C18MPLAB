#include <p18f452.h>
#define RW PORTDbits.RD6
#define  RS PORTDbits.RD5
#define  E PORTDbits.RD4
#define lcd PORTB

unsigned char  msg[]="helloo";
unsigned char msg2[] = "dfsdfsdf";

void delay1(unsigned int i);
void LCD_CMD(unsigned char i);
void LCD_DATA(unsigned char i );
void display(unsigned char * );
void Sendchar(unsigned char );

void main()
{
	//itoa(number, myStr);
	TRISDbits.TRISD4=0; // E of LCD
	TRISDbits.TRISD5=0; // RS of LCD
	TRISDbits.TRISD6=0; // RW of LCD

	TRISB=0X00;  // LCD data pins

	LCD_CMD(0x38); // 8 bit mode 2 lines
	LCD_CMD(0x0C); // display ON, cursor OFF

	LCD_CMD(0x80);  // cursor to beginning of first row
	display(msg);
	LCD_CMD(0xC0);  // cursor to beginning of second row
	display(msg2);

	while(1);
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

 void delay1(unsigned int i )
{ unsigned int d1; unsigned char ss;
	for( d1=0;d1<i;d1++)
		for(ss=0;ss<135;ss++);
}

	void  LCD_CMD(unsigned char i)
	{ lcd=i;
		RS=0;

		RW=0;
		E=1;
		delay1(1);
		E=0;

		}
		void LCD_DATA(unsigned char i )
		{
			RS=1;
			lcd=i;
			RW=0;
			E=1;
			delay1(1);
			E=0;
		}
