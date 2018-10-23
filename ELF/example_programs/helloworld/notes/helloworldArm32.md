# Hello World - 32 bits
---

## Source Code
Typical hello world application


```c
#include<stdio.h>

int main(){

	printf("Hello World!\n");

	return 0;
}
```


```
$ file hello

hello: ELF 32-bit LSB pie executable ARM, EABI5 version 1 
(SYSV), 
dynamically linked, interpreter /system/bin/linker, not stripped
```

---

##Disassembly

```
(gdb) disassemble main
Dump of assembler code for function main:
   0x00000408 <+0>:     push    {r11, lr}
   0x0000040c <+4>:     mov     r11, sp
   0x00000410 <+8>:     sub     sp, sp, #16
   0x00000414 <+12>:    mov     r0, #0
   0x00000418 <+16>:    str     r0, [r11, #-4]
   0x0000041c <+20>:    ldr     r1, [pc, #36]   ; 0x448 <main+64>
   0x00000420 <+24>:    add     r1, pc, r1
   0x00000424 <+28>:    str     r0, [sp, #8]
   0x00000428 <+32>:    mov     r0, r1
   0x0000042c <+36>:    bl      0x354 <printf@plt>
   0x00000430 <+40>:    ldr     r1, [sp, #8]
   0x00000434 <+44>:    str     r0, [sp, #4]
   0x00000438 <+48>:    mov     r0, r1
   0x0000043c <+52>:    mov     sp, r11
   0x00000440 <+56>:    pop     {r11, lr}
   0x00000444 <+60>:    bx      lr
   0x00000448 <+64>:    andeq   r0, r0, r4, lsr #32
End of assembler dump.
```
---

## Pseudocode

```c
int __cdecl main(int argc, const char **argv, const char **envp)
{
  printf("Hello World!\n");
  return 0;
}
```

---
