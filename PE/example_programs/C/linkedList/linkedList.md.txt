# LinkedList - 32bits PE
---
Linked list program that has basic data assignment and traversing only
May add on more later on

## Source Code

```c
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};



void traverse(struct Node *node)
{
    struct Node* cursor = node;

    while(cursor->next != NULL)
    {
        printf("%d,",cursor->data);
        cursor = cursor->next;
    }
    printf("%d",cursor->data);
}


// Program to create a simple linked
// list with 3 nodes
int main()
{
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

// allocate 3 nodes in the heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1; //assign data in first node
    head->next = second; // Link first node with the second node

// assign data to second node
    second->data = 2;

// Link second node with the third node
    second->next = third;

    third->data = 3; //assign data to third node
    third->next = NULL;



    traverse(head);
    return 0;
}
```



## Disassembly [ 32 bits ]
```
; int __cdecl main(int argc, const char **argv, const char **envp)
public _main
_main proc near


Size= dword ptr -20h
var_C= dword ptr -0Ch
var_8= dword ptr -8
var_4= dword ptr -4
argc= dword ptr  8
argv= dword ptr  0Ch
envp= dword ptr  10h


push    ebp
mov     ebp, esp
and     esp, 0FFFFFFF0h
sub     esp, 20h
call    ___main
mov     [esp+20h+var_4], 0
mov     [esp+20h+var_8], 0
mov     [esp+20h+var_C], 0
mov     [esp+20h+Size], 8 ; Size
call    _malloc
mov     [esp+20h+var_4], eax
mov     [esp+20h+Size], 8 ; Size
call    _malloc
mov     [esp+20h+var_8], eax
mov     [esp+20h+Size], 8 ; Size
call    _malloc
mov     [esp+20h+var_C], eax
mov     eax, [esp+20h+var_4]
mov     dword ptr [eax], 1
mov     eax, [esp+20h+var_4]
mov     edx, [esp+20h+var_8]
mov     [eax+4], edx
mov     eax, [esp+20h+var_8]
mov     dword ptr [eax], 2
mov     eax, [esp+20h+var_8]
mov     edx, [esp+20h+var_C]
mov     [eax+4], edx
mov     eax, [esp+20h+var_C]
mov     dword ptr [eax], 3
mov     eax, [esp+20h+var_C]
mov     dword ptr [eax+4], 0
mov     eax, [esp+20h+var_4]
mov     [esp+20h+Size], eax
call    _traverse
mov     eax, 0
leave
retn
_main endp




# FOR TRAVERSE FUNCTION

.text:00401570                 push    ebp
.text:00401571                 mov     ebp, esp
.text:00401573                 sub     esp, 28h
.text:00401576                 mov     eax, [ebp+arg_0]
.text:00401579                 mov     [ebp+var_C], eax
.text:0040157C                 jmp     short loc_40159C
.text:0040157E ; ---------------------------------------------------------------------------
.text:0040157E
.text:0040157E loc_40157E:                             ; CODE XREF: _traverse+34?j
.text:0040157E                 mov     eax, [ebp+var_C]
.text:00401581                 mov     eax, [eax]
.text:00401583                 mov     [esp+28h+var_24], eax
.text:00401587                 mov     [esp+28h+Format], offset Format ; "%d,"
.text:0040158E                 call    _printf
.text:00401593                 mov     eax, [ebp+var_C]
.text:00401596                 mov     eax, [eax+4]
.text:00401599                 mov     [ebp+var_C], eax
.text:0040159C
.text:0040159C loc_40159C:                             ; CODE XREF: _traverse+C?j
.text:0040159C                 mov     eax, [ebp+var_C]
.text:0040159F                 mov     eax, [eax+4]
.text:004015A2                 test    eax, eax
.text:004015A4                 jnz     short loc_40157E
.text:004015A6                 mov     eax, [ebp+var_C]
.text:004015A9                 mov     eax, [eax]
.text:004015AB                 mov     [esp+28h+var_24], eax
.text:004015AF                 mov     [esp+28h+Format], offset aD_0 ; "%d"
.text:004015B6                 call    _printf
.text:004015BB                 nop
.text:004015BC                 leave
.text:004015BD                 retn
.text:004015BD _traverse       endp
```


## Disassembly [ 64 bits ]

```
; int __cdecl main(int argc, const char **argv, const char **envp)
public main
main proc near


var_18= qword ptr -18h
var_10= qword ptr -10h
var_8= qword ptr -8


push    rbp
mov     rbp, rsp
sub     rsp, 40h
call    __main
mov     [rbp+var_8], 0
mov     [rbp+var_10], 0
mov     [rbp+var_18], 0
mov     ecx, 10h        ; Size
call    malloc
mov     [rbp+var_8], rax
mov     ecx, 10h        ; Size
call    malloc
mov     [rbp+var_10], rax
mov     ecx, 10h        ; Size
call    malloc
mov     [rbp+var_18], rax
mov     rax, [rbp+var_8]
mov     dword ptr [rax], 1
mov     rax, [rbp+var_8]
mov     rdx, [rbp+var_10]
mov     [rax+8], rdx
mov     rax, [rbp+var_10]
mov     dword ptr [rax], 2
mov     rax, [rbp+var_10]
mov     rdx, [rbp+var_18]
mov     [rax+8], rdx
mov     rax, [rbp+var_18]
mov     dword ptr [rax], 3
mov     rax, [rbp+var_18]
mov     qword ptr [rax+8], 0
mov     rax, [rbp+var_8]
mov     rcx, rax
call    traverse
mov     eax, 0
add     rsp, 40h
pop     rbp
retn
main endp



# FOR TRAVERSE FUNCTION

.text:00000000004015B0 arg_0           = qword ptr  10h
.text:00000000004015B0
.text:00000000004015B0                 push    rbp
.text:00000000004015B1                 mov     rbp, rsp
.text:00000000004015B4                 sub     rsp, 30h
.text:00000000004015B8                 mov     [rbp+arg_0], rcx
.text:00000000004015BC                 mov     rax, [rbp+arg_0]
.text:00000000004015C0                 mov     [rbp+var_8], rax
.text:00000000004015C4                 jmp     short loc_4015E6
.text:00000000004015C6 ; ---------------------------------------------------------------------------
.text:00000000004015C6
.text:00000000004015C6 loc_4015C6:                             ; CODE XREF: traverse+41?j
.text:00000000004015C6                 mov     rax, [rbp+var_8]
.text:00000000004015CA                 mov     eax, [rax]
.text:00000000004015CC                 mov     edx, eax
.text:00000000004015CE                 lea     rcx, Format     ; "%d,"
.text:00000000004015D5                 call    printf
.text:00000000004015DA                 mov     rax, [rbp+var_8]
.text:00000000004015DE                 mov     rax, [rax+8]
.text:00000000004015E2                 mov     [rbp+var_8], rax
.text:00000000004015E6
.text:00000000004015E6 loc_4015E6:                             ; CODE XREF: traverse+14?j
.text:00000000004015E6                 mov     rax, [rbp+var_8]
.text:00000000004015EA                 mov     rax, [rax+8]
.text:00000000004015EE                 test    rax, rax
.text:00000000004015F1                 jnz     short loc_4015C6
.text:00000000004015F3                 mov     rax, [rbp+var_8]
.text:00000000004015F7                 mov     eax, [rax]
.text:00000000004015F9                 mov     edx, eax
.text:00000000004015FB                 lea     rcx, aD_0       ; "%d"
.text:0000000000401602                 call    printf
.text:0000000000401607                 nop
.text:0000000000401608                 add     rsp, 30h
.text:000000000040160C                 pop     rbp
.text:000000000040160D                 retn
.text:000000000040160D traverse        endp
```


Decompiling it with IDA pro 7.0, we get the following pseudocode

---
## Pseudocode [ 32 bits ]

```c
int __cdecl main(int argc, const char **argv, const char **envp)
{
  _DWORD *v3; // ST1C_4
  _DWORD *v4; // ST18_4
  _DWORD *v5; // eax

  __main();
  v3 = malloc(8u);
  v4 = malloc(8u);
  v5 = malloc(8u);
  *v3 = 1;
  v3[1] = v4;
  *v4 = 2;
  v4[1] = v5;
  *v5 = 3;
  v5[1] = 0;
  traverse(v3);
  return 0;
}



int __cdecl traverse(_DWORD *a1)
{
  _DWORD *i; // [esp+1Ch] [ebp-Ch]

  for ( i = a1; i[1]; i = (_DWORD *)i[1] )
    printf("%d,", *i);
  return printf("%d", *i);
}
```

## Pseudocode [ 64 bits ]

```c
int __cdecl main(int argc, const char **argv, const char **envp)
{
  unsigned int *v3; // ST38_8
  _QWORD *v4; // ST30_8
  _QWORD *v5; // rax

  _main(*(_QWORD *)&argc, argv, envp);
  v3 = (unsigned int *)malloc(0x10ui64);
  v4 = malloc(0x10ui64);
  v5 = malloc(0x10ui64);
  *v3 = 1;
  *((_QWORD *)v3 + 1) = v4;
  *(_DWORD *)v4 = 2;
  v4[1] = v5;
  *(_DWORD *)v5 = 3;
  v5[1] = 0i64;
  traverse(v3);
  return 0;
}

int __fastcall traverse(unsigned int *a1)
{
  unsigned int *i; // [rsp+28h] [rbp-8h]

  for ( i = a1; *((_QWORD *)i + 1); i = (unsigned int *)*((_QWORD *)i + 1) )
    printf("%d,", *i);
  return printf("%d", *i);
}
```

---