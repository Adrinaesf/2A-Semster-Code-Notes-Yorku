/***************************************
* Lab03 *
* Author: Last name, first name *
* EECS/Prism username: Your eecs login username *
* Yorku Student #: Your student number *
* Email: Your email address *
****************************************/

#include <stdio.h>

#define AlphaV 100
void printBinary(int n); 

int main() {

  int r, g,b;
  unsigned int rgb_pack = 0;
  int r_unpack, g_unpack,b_unpack;
  int alpha = AlphaV;

  printf("enter R value (0~255): ");
  scanf("%d",&r);
  printf("enter G value (0~255): ");
  scanf("%d",&g);
  printf("enter B value (0~255): ");
  scanf("%d",&b);

  while(! (r<0 || g<0 || b <0) )
  {		
     rgb_pack = 0; // setting it up for the next use
     printf("A: %d\t", alpha);  printBinary(alpha); printf("\n");
     printf("R: %d\t", r);  printBinary(r); printf("\n");
     printf("G: %d\t", g);  printBinary(g); printf("\n"); 
     printf("B: %d\t", b);  printBinary(b); printf("\n"); 

    /* now do packing for Alpha,Red,Green,Blue, */

    // in order to pack them we can define a 32 bit int = 0
    // then we do rgb_pack = 0 | Alpha and then we shift it all the way to the left most digits. 
    // then we can do it with the rest of them. 

    rgb_pack = rgb_pack | alpha; 
    rgb_pack <<= 8; 

    rgb_pack = rgb_pack | r; 
    rgb_pack <<= 8; 

    rgb_pack = rgb_pack | g; 
    rgb_pack <<= 8; 

    rgb_pack = rgb_pack | b; 

     // printf("\nPacked: value %d\t", rgb_pack); printBinary(rgb_pack);printf("\n");
     printf("\nPacked:\t"); 
     printBinary(rgb_pack);
     printf(" (%d)\n", rgb_pack);

     printf("\nUnpacking  ......\n");  
     r=g=b=-1;

    /* now do unpacking */
    // since we need rgb_pack for the other unpacking stages, we first save the important values we 
    // want in the r_unpack, then we shift it to its correct place. 
    // Since the integers are all unsigned in here, we can shift them to right. 
    // I will use hex in order to get the information I want: 

    r_unpack = rgb_pack & 0x00FF0000; 
    // now we shift it 16 bits to right
    r_unpack >>= 16; 

    g_unpack = rgb_pack & 0x0000FF00; 
    // now we shift it 8 bits to right
    g_unpack >>= 8; 


    b_unpack = rgb_pack & 0x000000FF; 
    // No need for shifting. 

     printf("R: "); printBinary(r_unpack); printf(" (%d, %#o, %#X)\n", r_unpack, r_unpack, r_unpack);
     printf("G: "); printBinary(g_unpack); printf(" (%d, %#o, %#X)\n", g_unpack, g_unpack, g_unpack);
     printf("B: "); printBinary(b_unpack); printf(" (%d, %#o, %#X)\n", b_unpack, b_unpack, b_unpack);
     printf("------------------------------------\n\n"); 
	 
    printf("enter R value (0~255): ");
    scanf("%d",&r);
    printf("enter G value (0~255): ");
    scanf("%d",&g);
    printf("enter B value (0~255): ");
    scanf("%d",&b);
  }
}

