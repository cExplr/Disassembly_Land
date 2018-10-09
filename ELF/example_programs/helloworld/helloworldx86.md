# Hello World
---

This program is written in C++ 
Compiled with g++

## Source Code

```cpp
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
```

---

## Disassembly - Intel x86
Disassembled with Radare2

```
$ r2 -d hello
.
.
.
[0x7f6ba35ffc30]> aaa
[x] Analyze all flags starting with sym. and entry0 (aa)
[x] Analyze function calls (aac)
[x] Analyze len bytes of instructions for references (aar)
[x] Constructing a function name for fcn.* and sym.func.* functions (aan)
[TOFIX: afta can't run in debugger mode.ions (afta)
[x] Type matching analysis for all functions (afta)
[x] Use -AA or aaaa to perform additional experimental analysis.
= attach 11135 11135
11135
[0x7f6ba35ffc30]> s main
[0x00400846]> pdf
            ;-- main:
/ (fcn) sym.main 39
|   sym.main (int argc, char **argv, char **envp);
|           ; DATA XREF from entry0 (0x40076d)
|           0x00400846      55             push rbp
|           0x00400847      4889e5         mov rbp, rsp
|           0x0040084a      be44094000     mov esi, str.Hello_world    ; 0x400944 ; "Hello world!"
|           0x0040084f      bf60106000     mov edi, sym.std::cout      ; loc.std::cout ; 0x601060
|           0x00400854      e8b7feffff     call sym.std::basic_ostream_char_std::char_traits_char___std::operator___std::char_traits_char___std::basic_ostream_char_std::char_traits_char____charconst
|           0x00400859      be30074000     mov esi, sym.std::basic_ostream_char_std::char_traits_char___std::endl_char_std::char_traits_char___std::basic_ostream_char_std::char_traits_char ; 0x400730
|           0x0040085e      4889c7         mov rdi, rax
|           0x00400861      e8bafeffff     call sym.std::ostream::operator___stsd::ostream_____std::ostream
|           0x00400866      b800000000     mov eax, 0
|           0x0040086b      5d             pop rbp
\           0x0040086c      c3             ret
[0x00400846]>
```

---

## Disassembly - Intel x64

```
$ r2 -d ./hellox64 
.
.
.
[0xf7758a20]> aaa
[x] Analyze all flags starting with sym. and entry0 (aa)
[x] Analyze function calls (aac)
[x] Analyze len bytes of instructions for references (aar)
[x] Constructing a function name for fcn.* and sym.func.* functions (aan)
[TOFIX: afta can't run in debugger mode.ions (afta)
[x] Type matching analysis for all functions (afta)
[x] Use -AA or aaaa to perform additional experimental analysis.
= attach 11357 11357
11357
[0xf7758a20]> s main
[0x080486ab]> pdf
            ;-- main:
/ (fcn) sym.main 68
|   sym.main (int argc, char **argv, char **envp);
|           ; var int local_4h @ ebp-0x4
|           ; arg int arg_4h @ esp+0x4
|           ; DATA XREF from entry0 (0x80485c7)
|           0x080486ab      8d4c2404       lea ecx, [arg_4h]           ; 4
|           0x080486af      83e4f0         and esp, 0xfffffff0
|           0x080486b2      ff71fc         push dword [ecx - 4]
|           0x080486b5      55             push ebp
|           0x080486b6      89e5           mov ebp, esp
|           0x080486b8      51             push ecx
|           0x080486b9      83ec04         sub esp, 4
|           0x080486bc      83ec08         sub esp, 8
|           0x080486bf      68d0870408     push str.Hello_world        ; 0x80487d0 ; "Hello world!"
|           0x080486c4      6840a00408     push sym.std::cout          ; obj.std::cout ; 0x804a040
|           0x080486c9      e8a2feffff     call sym.std::basic_ostream_char_std::char_traits_char___std::operator___std::char_traits_char___std::basic_ostream_char_std::char_traits_char____charconst
|           0x080486ce      83c410         add esp, 0x10
|           0x080486d1      83ec08         sub esp, 8
|           0x080486d4      6890850408     push sym.std::basic_ostream_char_std::char_traits_char___std::endl_char_std::char_traits_char___std::basic_ostream_char_std::char_traits_char ; 0x8048590
|           0x080486d9      50             push eax
|           0x080486da      e8a1feffff     call sym.std::ostream::operator___std::ostream_____std::ostream
|           0x080486df      83c410         add esp, 0x10
|           0x080486e2      b800000000     mov eax, 0
|           0x080486e7      8b4dfc         mov ecx, dword [local_4h]
|           0x080486ea      c9             leave
|           0x080486eb      8d61fc         lea esp, [ecx - 4]
\           0x080486ee      c3             ret
[0x080486ab]> 
```

---
## Pseudocode coming soon

```

```

---