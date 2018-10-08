# Disassembly Examples of PE files

These programs are compiled with mingw gcc from code block.

# Example 1 - [ Single Argument Function Call ]
## Example 1 Source Code
```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}

```

## Example 1 Disassembly
Opening on IDA Pro 7.0, we get the disassembled main function.

```bash
; Attributes: bp-based frame
; int __cdecl main(int argc, const char **argv, const char **envp)
public main
main proc near
push    rbp
mov     rbp, rsp
sub     rsp, 20h
call    __main
lea     rcx, Str        ; "Hello world!"
call    puts
mov     eax, 0
add     rsp, 20h
pop     rbp
retn
main endp
```

Here the calling convention is cdel.
String address is being stored in rcx as the first parameter which points to the Hello World! String.


## Example 1 Pseudocode

```c
int __cdecl main(int argc, const char **argv, const char **envp)
{
  _main();
  puts("Hello world!");
  return 0;
}
```
---


# Example 2 - [ Two Argument Function Call ]

## Example 2 Source Code
```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 0;
    printf("x is %d",x);
    return 0;
}
```

## Example 2 Disassembly
Opening on IDA Pro 7.0, we get the disassembled main function.

```bash
; Attributes: bp-based frame
; int __cdecl main(int argc, const char **argv, const char **envp)
public main
main proc near

x= dword ptr -4

push    rbp
mov     rbp, rsp
sub     rsp, 30h
call    __main
mov     [rbp+x], 0
mov     eax, [rbp+x]
mov     edx, eax
lea     rcx, Format     ; "x is %d"
call    printf
mov     eax, 0
add     rsp, 30h
pop     rbp
retn
main endp
```

Here the calling convention is cdel.
String address is being stored in rcx as the first parameter and value 0 is placed in a variable and placed in `ecx` which is in the second argument. printf is then called.


## Example 2 Pseudocode

```c
int __cdecl main(int argc, const char **argv, const char **envp)
{
  _main();
  printf("x is %d", 0i64);
  return 0;
```
---

# Example 3 - [ More Functions Calls ]

## Example 3 Source Code 

```c
#include <stdio.h>
#include <stdlib.h>

int add(int x, int y);

int main()
{
    int x = 15;
    int y = 42;
    int z = add(x,y);
    printf("%d + %d = %d" ,x ,y ,z );
    return 0;
}

int add (int x, int y){
    return x + y;
}
```


## Example 3 Disassembly
Opening on IDA Pro 7.0, we get the disassembled main function.

```
; Attributes: bp-based frame

; int __cdecl main(int argc, const char **argv, const char **envp)
public main
main proc near

z= dword ptr -0Ch
y= dword ptr -8
x= dword ptr -4
push    rbp
mov     rbp, rsp
sub     rsp, 30h
call    __main
mov     [rbp+x], 0Fh
mov     [rbp+y], 2Ah
mov     edx, [rbp+y]    ; y
mov     eax, [rbp+x]
mov     ecx, eax        ; x
call    add
mov     [rbp+z], eax
mov     ecx, [rbp+z]
mov     edx, [rbp+y]
mov     eax, [rbp+x]
mov     r9d, ecx
mov     r8d, edx
mov     edx, eax
lea     rcx, Format     ; "%d + %d = %d"
call    printf
mov     eax, 0
add     rsp, 30h
pop     rbp
retn
main endp


; int __cdecl add(int x, int y)
public add
add proc near

x= dword ptr  10h
y= dword ptr  18h

push    rbp
mov     rbp, rsp
mov     [rbp+x], ecx
mov     [rbp+y], edx
mov     edx, [rbp+x]
mov     eax, [rbp+y]
add     eax, edx
pop     rbp
retn
add endp
```


## Example 3 Pseudocode

Pseudocode from IDA 7.0

```c
int __cdecl main(int argc, const char **argv, const char **envp)
{
  unsigned int z; // ST24_4

  _main();
  z = add(15, 42);
  printf("%d + %d = %d", 15i64, 42i64, z);  // Here 15 integer 64 bits
                                            // and 42 integer 64 bits
  return 0;
}

int __cdecl add(int x, int y)
{
  return x + y;
}
```

---

# Example 4 - [ More Functions Calls ]

## Example 4 Source Code 

```c
#include <stdio.h>
#include <stdlib.h>


int addAll(int a, int b, int c, int d, int e, int f, int g, int h, int i){
    return a+b+c+d+e+f+g+h+i;
}
int main()
{
    int x = 0 ;
    int sum = addAll(1,2,3,4,5,6,7,8,9);
    printf("The total sum is %d", sum);
    return 0;
}

```


## Example 4 Disassembly
Opening on IDA Pro 7.0, we get the disassembled main function.
Seems like the first parameter is being stored in `rcx`, the second in `rdx`, third in `r8d`, fourth in `r9d` and the rest in the stack from closest to rsp towards the rbp.

```
; Attributes: bp-based frame

; int __cdecl main(int argc, const char **argv, const char **envp)
public main
main proc near

var_40= dword ptr -40h
var_38= dword ptr -38h
var_30= dword ptr -30h
var_28= dword ptr -28h
var_20= dword ptr -20h
var_8= dword ptr -8
var_4= dword ptr -4


push    rbp
mov     rbp, rsp
sub     rsp, 60h
call    __main
mov     [rbp+var_4], 0
mov     [rsp+60h+var_20], 9
mov     [rsp+60h+var_28], 8
mov     [rsp+60h+var_30], 7
mov     [rsp+60h+var_38], 6
mov     [rsp+60h+var_40], 5
mov     r9d, 4
mov     r8d, 3
mov     edx, 2
mov     ecx, 1
call    addAll
mov     [rbp+var_8], eax
mov     eax, [rbp+var_8]
mov     edx, eax
lea     rcx, Format     ; "The total sum is %d"
call    printf
mov     eax, 0
add     rsp, 60h
pop     rbp
retn
main endp





; Attributes: bp-based frame

public addAll
addAll proc near

arg_0= dword ptr  10h
arg_8= dword ptr  18h
arg_10= dword ptr  20h
arg_18= dword ptr  28h
arg_20= dword ptr  30h
arg_28= dword ptr  38h
arg_30= dword ptr  40h
arg_38= dword ptr  48h
arg_40= dword ptr  50h

push    rbp
mov     rbp, rsp
mov     [rbp+arg_0], ecx
mov     [rbp+arg_8], edx
mov     [rbp+arg_10], r8d
mov     [rbp+arg_18], r9d
mov     edx, [rbp+arg_0]
mov     eax, [rbp+arg_8]
add     edx, eax
mov     eax, [rbp+arg_10]
add     edx, eax
mov     eax, [rbp+arg_18]
add     edx, eax
mov     eax, [rbp+arg_20]
add     edx, eax
mov     eax, [rbp+arg_28]
add     edx, eax
mov     eax, [rbp+arg_30]
add     edx, eax
mov     eax, [rbp+arg_38]
add     edx, eax
mov     eax, [rbp+arg_40]
add     eax, edx
pop     rbp
retn
addAll endp
```


## Example 4 Pseudocode

Pseudocode from IDA 7.0

```c
__int64 __fastcall addAll(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  return (unsigned int)(a8 + a7 + a6 + a5 + a4 + a3 + a2 + a1 + a9);
}

// local variable allocation has failed, the output may be wrong!
int __cdecl main(int argc, const char **argv, const char **envp)
{
  unsigned int v3; // ST58_4

  _main(*(_QWORD *)&argc, argv, envp);
  v3 = addAll(1, 2, 3, 4, 5, 6, 7, 8, 9);
  printf("The total sum is %d", v3);
  return 0;
}
```
---