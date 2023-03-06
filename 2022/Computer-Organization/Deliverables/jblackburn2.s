

 // Section .crt0 is always placed from address 0
	.section .crt0, "ax"

_start:
.global _start

 /*
 	Assembly Abstraction assignment

 	Start here
 */
    //WORK DONE BY STRCHR(JACK BLACKBURN)
    //LOAD VARIABLES INTO REGISTERS

addi  x10, x0, 0x2   //0x200513
slli  x10, x10, 12  //x10 is 0x2000 //0xc51513
addi x11, x10, 0x4  //x11 is 0x2004 //0x450593
addi x12, x11, 0x4  //x12 0x2008    //0x458613
addi x13, x0, 0x0 //x13 is RESULT which is initialized as 0 //0x693
addi x14, x0, 0x0 //x14 is I which is also init to 0  //0x713
addi x15, x0, 0x6a //x15 is LETTER init to 106 which is 'j' repped as an unsigned int //0x6a00793


//LOOP
LOOP: 
    add  x13, x13, x15 //result = result + letter //0xf686b3
    add  x13, x13, x14 //result = result + i   //0xe686b3
    addi  x14, x14, 1  //i = i + 1  //0x170713
    blt  x14, x15, LOOP // if i<letter go back to top of loop //0xf74063

//RETURN RESULT
sw  x13, 0x4(x10) //store result in memory //0xd52223
halt //finish
/*
Add your assembly code above this line
*/
nop
nop
nop
halt
nop
nop
nop
