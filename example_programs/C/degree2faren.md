# Degree2faren
---

A program that converts in steps of 5 degrees, the conversion from celsius to farenheit degrees.

## Source Code

```c
#include <stdio.h>

int main()
{
  float fahr, celsius;
  int lower = 0, upper = 100, step = 5;

  celsius = lower;
  printf("%3s\t%6s\n", "Deg", "Fahr");
  while (celsius <= upper) {
    fahr = (celsius * 9.0 / 5.0) + 32.0;
    printf("%3.0f\t%6.1f\n", celsius, fahr);
    celsius = celsius + step;
  }
  return 0;
}
```
--- 
Here, floating point numbers are added which will complicate the assembly.
Disassembled function are as follow ...

## Disassembly

```bash
; Attributes: bp-based frame

; int __cdecl main(int argc, const char **argv, const char **envp)
public main
main proc near

var_28= qword ptr -28h
var_14= dword ptr -14h
var_10= dword ptr -10h
var_C= dword ptr -0Ch
var_8= dword ptr -8
var_4= dword ptr -4

push    rbp
mov     rbp, rsp
sub     rsp, 50h
call    __main
mov     [rbp+var_8], 0
mov     [rbp+var_C], 64h
mov     [rbp+var_10], 5
pxor    xmm0, xmm0
cvtsi2ss xmm0, [rbp+var_8]
movss   [rbp+var_4], xmm0
lea     r8, aFahr       ; "Fahr"
lea     rdx, aDeg       ; "Deg"
lea     rcx, Format     ; "%3s\t%6s\n"
call    printf
jmp     loc_401695


loc_401695:
pxor    xmm0, xmm0
cvtsi2ss xmm0, [rbp+var_C]
ucomiss xmm0, [rbp+var_4]
jnb     loc_4015FF

loc_4015FF:
cvtss2sd xmm0, [rbp+var_4]
movsd   xmm1, cs:qword_404050
mulsd   xmm0, xmm1
movsd   xmm1, cs:qword_404058
divsd   xmm0, xmm1
movsd   xmm1, cs:qword_404060
addsd   xmm0, xmm1
cvtsd2ss xmm3, xmm0
movss   [rbp+var_14], xmm3
cvtss2sd xmm1, [rbp+var_14]
cvtss2sd xmm0, [rbp+var_4]
movq    rax, xmm1
mov     rdx, rax
mov     [rbp+var_28], rdx
movsd   xmm2, [rbp+var_28]
mov     [rbp+var_28], rax
movsd   xmm1, [rbp+var_28]
movq    rax, xmm0
mov     rdx, rax
mov     [rbp+var_28], rdx
movsd   xmm0, [rbp+var_28]
movq    r8, xmm1
movapd  xmm1, xmm0
mov     rdx, rax
lea     rcx, a30f61f    ; "%3.0f\t%6.1f\n"
call    printf
pxor    xmm0, xmm0
cvtsi2ss xmm0, [rbp+var_10]
movss   xmm1, [rbp+var_4]
addss   xmm0, xmm1
movss   [rbp+var_4], xmm0

mov     eax, 0
add     rsp, 50h
pop     rbp
retn
main endp

```

---
# Pseudocode

```c
int __cdecl main(int argc, const char **argv, const char **envp)
{
  float v3; // xmm3_4
  float v5; // [rsp+4Ch] [rbp-4h]

  _main(*(_QWORD *)&argc, argv, envp);
  v5 = (float)0;
  printf("%3s\t%6s\n", "Deg", "Fahr");
  while ( (float)100 >= v5 )
  {
    v3 = v5 * 9.0 / 5.0 + 32.0;
    printf("%3.0f\t%6.1f\n", v5, v3);
    v5 = (float)5 + v5;
  }
  return 0;
}
```

Compared to the source code

```c
#include <stdio.h>

int main()
{
  float fahr, celsius;
  int lower = 0, upper = 100, step = 5;

  celsius = lower;
  printf("%3s\t%6s\n", "Deg", "Fahr");
  while (celsius <= upper) {
    fahr = (celsius * 9.0 / 5.0) + 32.0;
    printf("%3.0f\t%6.1f\n", celsius, fahr);
    celsius = celsius + step;
  }
  return 0;
}
```
