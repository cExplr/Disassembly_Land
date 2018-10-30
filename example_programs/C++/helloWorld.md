# Hello World
---

This program is written in C++

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

Which results in the disassembly of bizarre names

---
## Disassembly [Mangled]
```
push    rbp
mov     rbp, rsp
sub     rsp, 20h
call    __main
lea     rdx, aHelloWorld ; "Hello world!"
mov     rcx, cs:_refptr__ZSt4cout
call    _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc ; std::operator<<<std::char_traits<char>>(std::basic_ostream<char,std::char_traits<char>> &,char const*)
mov     rdx, cs:_refptr__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
mov     rcx, rax
call    _ZNSolsEPFRSoS_E ; std::ostream::operator<<(std::ostream & (*)(std::ostream &))
mov     eax, 0
add     rsp, 20h
pop     rbp
retn
main endp
```

## Disassembly [Demangled]
After Demangling the names, it has names that are way more readable

```
push    rbp
mov     rbp, rsp
sub     rsp, 20h
call    __main
lea     rdx, aHelloWorld ; "Hello world!"
mov     rcx, cs:_refptr__ZSt4cout
call    std::operator<<<std::char_traits<char>>(std::basic_ostream<char,std::char_traits<char>> &,char const*)
mov     rdx, cs:_refptr__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
mov     rcx, rax
call    std::ostream::operator<<(std::ostream & (*)(std::ostream &))
mov     eax, 0
add     rsp, 20h
pop     rbp
retn
main endp
```

Decompiling it with IDA pro 7.0, we get the following pseudocode

---
## Pseudocode

```cpp
int __cdecl main(int argc, const char **argv, const char **envp)
{
  __int64 v3; // rax

  _main(*(_QWORD *)&argc, argv, envp);
  v3 = std::operator<<<std::char_traits<char>>(*(_QWORD *)&argc, argv, "Hello world!", refptr__ZSt4cout);
  std::ostream::operator<<(
    *(_QWORD *)&argc,
    argv,
    refptr__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_,
    v3);
  return 0;
}
```

Comparing with source code

```cpp
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
```

There is a `refptr__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_` which I can find under the rdata section.

```
.rdata:00000000004AF2A0                 public _refptr__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
.rdata:00000000004AF2A0 _refptr__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_ dq offset std::endl<char,std::char_traits<char>>(std::basic_ostream<char,std::char_traits<char>> &)
```
---