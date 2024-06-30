/*
 *
 * kernel.c - version 0.0.1
 * 
 */


#define WHITE_TXT 0x07 /* light gray on black text */
#include "cpython/Include/Python.h"

void k_clear_screen();
unsigned int k_printf(char *message, unsigned int line);

/* simple kernel written in C */
void k_main() 
{
	k_clear_screen();
	k_printf("Loading from a Python Code.", 0);
	Py_SetProgramName("SCL OS");
	Py_Initialize();

	// Start loading SCL
	char * buffer = 0;
	long length;
	FILE * f = fopen ("./SCL/SCL.py", "rb");
	
	if (f)
	{
	  fseek (f, 0, SEEK_END);
	  length = ftell (f);
	  fseek (f, 0, SEEK_SET);
	  buffer = malloc (length);
	  if (buffer)
	  {
	    fread (buffer, 1, length, f);
	  }
	  fclose (f);
	}
	
	if (buffer)
	{
	  PyRun_SimpleString(buffer);
	}
};

/* k_clear_screen : to clear the entire text screen */
void k_clear_screen()
{
	char *vidmem = (char *) 0xb8000;
	unsigned int i=0;
	while(i < (80*25*2))
	{
		vidmem[i]=' ';
		i++;
		vidmem[i]=WHITE_TXT;
		i++;
	};
};

/* k_printf : the message and the line # */
unsigned int k_printf(char *message, unsigned int line)
{
	char *vidmem = (char *) 0xb8000;
	unsigned int i=0;

	i=(line*80*2);

	while(*message!=0)
	{
		if(*message=='\n') // check for a new line
		{
			line++;
			i=(line*80*2);
			*message++;
		} else {
			vidmem[i]=*message;
			*message++;
			i++;
			vidmem[i]=WHITE_TXT;
			i++;
		};
	};

	return(1);
}
