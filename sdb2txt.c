/*sdb2txt
	A tool to dump SDB files from Digimon World DS.

	Originally coded by @AlexPowerUp, modified
	by @Areidz.

	Version: 1.0.2

	Link: http://sourceforge.net/projects/sdb2txtdwds/
*/
#include <stdio.h>
#include <stdlib.h>

	//To replace original pause_system();
#ifdef WIN32
    #include <conio.h>
#elif LINUX
    #include <ncurses.h>
#else
	#error You need another OS
#endif
 
void pause_system(void);
long int get_ptr_number(FILE *filein);
long int get_ptr_string(FILE *filein, int number);

int main(int argc, char *argv[])
{
	//Variables
	unsigned int i, final = 0;
    int pointers, charBuffer;
    FILE *fileInput, *fileOutput;

    /*To check if we can read and write
    the correct files.			     
    */
    if(argc == 3)
    {
        fileInput = fopen(argv[1], "rb");
        if(!fileInput)
        {
            printf("Couldn't read the file.\n");
            pause_system();
            return 0;
        }
        fileOutput = fopen(argv[2], "wb");
        if(!fileOutput)
        {
            printf("Couldn't create the output.\n");
            pause_system();
            return 0;
        }
    }
    else
    {
	    printf("Error in the syntax.\nUsage: sdb2txt.exe <SDB file(input)> <TXT file(output)>\n");
	    pause_system();
	    return 0;
    }

    pointers = get_ptr_number(fileInput);

    printf("The SDB file has %d strings.\n", pointers);
    printf("Transforming...\n");

    for(i=0;i<pointers;i++)
    {
        fseek(fileInput, get_ptr_string(fileInput, i), SEEK_SET);
        while(final == 0)
        {
            charBuffer = fgetc(fileInput);
            switch(charBuffer)
            {
                case 0x50:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'A', fileOutput);
                    break;
                case 0x51:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'B', fileOutput);
                    break;
                case 0x52:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'C', fileOutput);
                    break;
                case 0x53:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'D', fileOutput);
                    break;
                case 0x54:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'E', fileOutput);
                    break;
                case 0x55:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'F', fileOutput);
                    break;
                case 0x56:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'G', fileOutput);
                    break;
                case 0x57:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'H', fileOutput);
                    break;
                case 0x58:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'I', fileOutput);
                    break;
                case 0x59:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'J', fileOutput);
                    break;
                case 0x5A:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'K', fileOutput);
                    break;
                case 0x5B:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'L', fileOutput);
                    break;
                case 0x5C:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'M', fileOutput);
                    break;
                case 0x5D:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'N', fileOutput);
                    break;
                case 0x5E:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'O', fileOutput);
                    break;
                case 0x5F:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'P', fileOutput);
                    break;
                case 0x60:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'Q', fileOutput);
                    break;
                case 0x61:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'R', fileOutput);
                    break;
                case 0x62:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'S', fileOutput);
                    break;
                case 0x63:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'T', fileOutput);
                    break;
                case 0x64:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'U', fileOutput);
                    break;
                case 0x65:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'V', fileOutput);
                    break;
                case 0x66:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'W', fileOutput);
                    break;
                case 0x67:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'X', fileOutput);
                    break;
                case 0x68:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'Y', fileOutput);
                    break;
                case 0x69:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'Z', fileOutput);
                    break;
                case 0x6A:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'a', fileOutput);
                    break;
                case 0x6B:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'b', fileOutput);
                    break;
                case 0x6C:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'c', fileOutput);
                    break;
                case 0x6D:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'd', fileOutput);
                    break;
                case 0x6E:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'e', fileOutput);
                    break;
                case 0x6F:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'f', fileOutput);
                    break;
                case 0x70:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'g', fileOutput);
                    break;
                case 0x71:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'h', fileOutput);
                    break;
                case 0x72:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'i', fileOutput);
                    break;
                case 0x73:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'j', fileOutput);
                    break;
                case 0x74:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'k', fileOutput);
                    break;
                case 0x75:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'l', fileOutput);
                    break;
                case 0x76:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'm', fileOutput);
                    break;
                case 0x77:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'n', fileOutput);
                    break;
                case 0x78:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'o', fileOutput);
                    break;
                case 0x79:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'p', fileOutput);
                    break;
                case 0x7A:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'q', fileOutput);
                    break;
                case 0x7B:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'r', fileOutput);
                    break;
                case 0x7C:
                    if(fgetc(fileInput) == 0x00) fputc((int) 's', fileOutput);
                    break;
                case 0x7D:
                    if(fgetc(fileInput) == 0x00) fputc((int) 't', fileOutput);
                    break;
                case 0x7E:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'u', fileOutput);
                    break;
                case 0x7F:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'v', fileOutput);
                    break;
                case 0x80:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'w', fileOutput);
                    break;
                case 0x81:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'x', fileOutput);
                    break;
                case 0x82:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'y', fileOutput);
                    break;
                case 0x83:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'z', fileOutput);
                    break;
                case 0x00:
                    if(fgetc(fileInput) == 0x00) fputc((int) ' ', fileOutput);
                    break;
                case 0x19:
                    if(fgetc(fileInput) == 0x00) fputc((int) '=', fileOutput);
                    break;
                case 0x18:
                    if(fgetc(fileInput) == 0x00) fputc((int) '-', fileOutput);
                    break;
                case 0x12:
                    if(fgetc(fileInput) == 0x00) fputc((int) '.', fileOutput);
                    break;
                case 0x14:
                    if(fgetc(fileInput) == 0x00) fputc((int) '?', fileOutput);
                    break;
                case 0x01:
                    if(fgetc(fileInput) == 0x00) fputc((int) '0', fileOutput);
                    break;
                case 0x02:
                    if(fgetc(fileInput) == 0x00) fputc((int) '1', fileOutput);
                    break;
                case 0x03:
                    if(fgetc(fileInput) == 0x00) fputc((int) '2', fileOutput);
                    break;
                case 0x04:
                    if(fgetc(fileInput) == 0x00) fputc((int) '3', fileOutput);
                    break;
                case 0x05:
                    if(fgetc(fileInput) == 0x00) fputc((int) '4', fileOutput);
                    break;
                case 0x06:
                    if(fgetc(fileInput) == 0x00) fputc((int) '5', fileOutput);
                    break;
                case 0x07:
                    if(fgetc(fileInput) == 0x00) fputc((int) '6', fileOutput);
                    break;
                case 0x08:
                    if(fgetc(fileInput) == 0x00) fputc((int) '7', fileOutput);
                    break;
                case 0x09:
                    if(fgetc(fileInput) == 0x00) fputc((int) '8', fileOutput);
                    break;
                case 0x0A:
                    if(fgetc(fileInput) == 0x00) fputc((int) '9', fileOutput);
                    break;
                case 0x11:
                    if(fgetc(fileInput) == 0x00) fputc((int) ',', fileOutput);
                    break;
                case 0x13:
                    if(fgetc(fileInput) == 0x00) fputc((int) '!', fileOutput);
                    break;
                case 0x15:
                    if(fgetc(fileInput) == 0x00) fputc((int) '(', fileOutput);
                    break;
                case 0x16:
                    if(fgetc(fileInput) == 0x00) fputc((int) ')', fileOutput);
                    break;
                case 0x17:
                    if(fgetc(fileInput) == 0x00) fputc((int) '+', fileOutput);
                    break;
                case 0x20:
                    if(fgetc(fileInput) == 0x00) fputc((int) '¿', fileOutput);
                    break;
                case 0x32:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'á', fileOutput);
                    break;
                case 0x30:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'ñ', fileOutput);
                    break;
                case 0x31:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'é', fileOutput);
                    break;
                case 0x21:
                    if(fgetc(fileInput) == 0x00) fputc((int) '¡', fileOutput);
                    break;
                case 0x0E:
                    if(fgetc(fileInput) == 0x00) fputc(0x27, fileOutput);
                    break;
                case 0x40:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'í', fileOutput);
                    break;
                case 0x41:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'ó', fileOutput);
                    break;
                case 0x42:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'ú', fileOutput);
                    break;
                case 0x43:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'ü', fileOutput);
                    break;
                case 0x44:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'Á', fileOutput);
                    break;
                case 0x45:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'É', fileOutput);
                    break;
                case 0x46:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'Í', fileOutput);
                    break;
                case 0x47:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'Ú', fileOutput);
                    break;
                case 0x48:
                    if(fgetc(fileInput) == 0x00) fputc((int) 'Ó', fileOutput);
                    break;
                case 0x4A: //gamma
                    if(fgetc(fileInput) == 0x00) fputc(0x03, fileOutput);
                    break;
                case 0x4B: //epsilon
                    if(fgetc(fileInput) == 0x00) fputc(0x05, fileOutput);
                    break;
                case 0x4C: //delta
                    if(fgetc(fileInput) == 0x00) fputc(0x04, fileOutput);
                    break;
                case 0x0F:
                    if(fgetc(fileInput) == 0x00) fputc((int) '"', fileOutput);
                    break;
                case 0xFF: //end of string
                    if(fgetc(fileInput) == 0xFF) {
                    	fputc(0x10, fileOutput);
                    	/* fputc(0x0D, fileOutput); fputc(0x0A, fileOutput);*/ 
                    	final = 1;
                    }
                    break;
                case 0xFD: //go one text line down
                    if(fgetc(fileInput) == 0xFF) fputc(0xAC, fileOutput);
                    break;
                case 0x22: //star
                    if(fgetc(fileInput) == 0x00) fputc(0x06, fileOutput);
                    break;
                case 0xEE: //color red text (inits and ends with the same code)
                    if(fgetc(fileInput) == 0xFF) fputc(0x0F, fileOutput);
                    break;
                case 0x0D:
                    if(fgetc(fileInput) == 0x00) fputc((int) ':', fileOutput);
                    break;
                case 0x1C: //"..."
                    if(fgetc(fileInput) == 0x00) fputc(0x0E, fileOutput);
                    break;
                case 0xFE: //alternative end of string (only works with the others msg folders)
                    if(fgetc(fileInput) == 0xFF) {
                    	fputc(0x15, fileOutput);
                     	/*fputc(0x0D, fileOutput); fputc(0x0A, fileOutput);*/ 
                     	final = 1;
                     }
                    break;
                case 0x0B:
                    if(fgetc(fileInput) == 0x00) fputc((int) '/', fileOutput);
                    break;
                case 0x1B:
                    if(fgetc(fileInput) == 0x00) fputc((int) '~', fileOutput);
                    break;
                case 0x23:
                    if(fgetc(fileInput) == 0x00) fputc((int) '&', fileOutput);
                    break;
                case 0x0C:
                    if(fgetc(fileInput) == 0x00) fputc((int) '%', fileOutput);
                    break;
                case 0x2F: //beta
                    if(fgetc(fileInput) == 0x00) fputc(0x02, fileOutput);
                    break;
                case 0x2E: //alpha
                    if(fgetc(fileInput) == 0x00) fputc(0x01, fileOutput);
                    break;
                case 0xED: //character name
                    if(fgetc(fileInput) == 0xFF) fputc(0x00, fileOutput);
                    break;
                case 0xF0: //identifier 0
                    if(fgetc(fileInput) == 0xFF) fputc(0x0A, fileOutput);
                    break;
                case 0xF1: //identifier 1
                    if(fgetc(fileInput) == 0xFF) fputc(0x0B, fileOutput);
                    break;
                case 0xF2: //identifier 2
                    if(fgetc(fileInput) == 0x00) fputc(0x0C, fileOutput);
                    break;
                case 0x24: //symbol 24
                    if(fgetc(fileInput) == 0x00) fputc(0x07, fileOutput);
                    break;
                case 0x25: //symbol 25
                    if(fgetc(fileInput) == 0x00) fputc(0x08, fileOutput);
                    break;
                case 0x33: //symbol 33
                    if(fgetc(fileInput) == 0x00) fputc(0x09, fileOutput);
                    break;
                case 0xEC: //"Mote"
                    if(fgetc(fileInput) == 0xFF) fputc(0x0D, fileOutput);
                    break;
                case 0xE9: //?? maybe color
                    if(fgetc(fileInput) == 0xFF) fputc(0x11, fileOutput);
                    break;
                case 0xEF: //used in credits... maybe color?
                    if(fgetc(fileInput) == 0xFF) fputc(0x12, fileOutput);
                    break;
                case 0x10: //unknown
                    if(fgetc(fileInput) == 0x00) fputc(0x13, fileOutput);
                    break;
                default:
                    printf("New char found: 0x%X%X\n", charBuffer, fgetc(fileOutput));
                    pause_system(); 
                    break;
            }
        }
    }
    fclose(fileInput);
    fclose(fileOutput);
    return 0;
}

long int get_ptr_number(FILE *filein)
{
    long int pointerCache[3];
    //int currentposition = ftell(filein);
    fseek(filein, 0, SEEK_SET);

    unsigned int i;
    for(i=0;i<4;i++) 
    	pointerCache[i] = fgetc(filein);

    long int pointerFinal = pointerCache[0] + (pointerCache[1]*0x100) + (pointerCache[2]*0x10000) + (pointerCache[3]*0x1000000);

    //fseek(filein, currentposition, SEEK_SET);
    return (pointerFinal/4);
}

long int get_ptr_string(FILE *filein, int number)
{
    /*if(number > get_ptr_number(filein))
    {
        printf("Error: This file has %d strings, but you are trying to access to the %d string. May cause an overflow, so leaving...\n", get_ptr_number(filein), number);
        pause_system();
        return -1;
    }*/
    long int pointerCache[3];
    //int currentposition = ftell(filein);
    fseek(filein, (4*number), SEEK_SET);

    unsigned int i;
    for(i=0;i<4;i++) 
    	pointerCache[i] = fgetc(filein);

    long int pointerFinal = pointerCache[0] + (pointerCache[1]*0x100) + (pointerCache[2]*0x10000) + (pointerCache[3]*0x1000000);

    //fseek(filein, currentposition, SEEK_SET);
    return pointerFinal;
}

void pause_system(void)
{
     char ch;
      
     /* flush the input buffer, just in case */
     while ((ch = getchar()) != '\n' && ch != EOF);
      
     //printf("Press any key to continue.. ");
     //getch();
}