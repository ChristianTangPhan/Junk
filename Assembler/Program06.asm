; Example assembly language program -- adds two numbers
; Author:  R. Detmer
; Date:    1/2008

.586
.MODEL FLAT

INCLUDE io.h            ; header file for input/output

.STACK 4096

.DATA
invalid_input  DWORD   ?
length_count   DWORD   ?
binaryString   DWORD   ?
convertedValue DWORD   ?
prompt BYTE    "Enter binary string", 0
string  BYTE    40 DUP (?)
resultLbl BYTE  "The converted integer is", 0
resulttxt BYTE    11 DUP (?), 0

.CODE
_MainProc PROC
restart:
    input   prompt, string, 9

    mov     eax, 0
    mov     edx, 0
    mov     invalid_input, 0       ; clear flag
    mov     length_count, 0

    lea     ebx, string
    mov     ecx, 9

string_loop:
    mov     al, BYTE PTR [ebx]
    cmp al, 0
    je done

    inc     length_count
    cmp     length_count, 9
    jge      done

    cmp     al, '0'
    je      zero_bit
    cmp     al, '1'
    je      one_bit
    mov     invalid_input, 1
    jmp next_char

one_bit:
    shl     edx, 1
    add     edx, 1
    jmp     next_char

zero_bit:
    shl     edx, 1
    jmp     next_char

next_char:
    inc     ebx
    jmp     string_loop

done:
    cmp     invalid_input, 1       ; check if input was invalid
    je      restart

    dtoa    resulttxt, edx        ; convert to ASCII characters
    output  resultLbl, resulttxt          ; output label and sum

    mov     eax, 0  ; exit with return code 0
    ret
_MainProc ENDP
END                             ; end of source code

