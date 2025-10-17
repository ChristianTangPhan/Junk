; Name:  Christian Phan
; ID:    150311
; Class: CS 321
; Date:  10/11/2025

; "This assignment is my original work for CS 321, created and completed during the fall 2025 semester.  I have
; neither copied this work nor had another person or AI do any of my work for me."

;       Christian Phan

INCLUDE io.h

.DATA
prompt          BYTE "Enter a string", 0
string          BYTE 101 DUP(?)

length_count    QWORD 0
lower_case      QWORD 0
upper_case      QWORD 0
digit_count     QWORD 0
space_count     QWORD 0

resultLbl   BYTE "The result is", 0

resulttxt   BYTE "Length: "
printN1     BYTE 11 DUP(?),            10
            BYTE "Uppercase: "
printN2     BYTE 11 DUP(?),            10
            BYTE "Lowercase: "
printN3     BYTE 11 DUP(?),            10
            BYTE "Digits: "
printN4     BYTE 11 DUP(?),            10
            BYTE "Spaces: "
printN5     BYTE 11 DUP(?),            10

.CODE
MainProc PROC
    sub     rsp, 120

    input   prompt, string, 101

    mov     rax, 0
    mov     qword ptr length_count, rax
    mov     qword ptr lower_case, rax
    mov     qword ptr upper_case, rax
    mov     qword ptr digit_count, rax
    mov     qword ptr space_count, rax

    lea     r8, string

string_loop:
    mov     al, BYTE PTR [r8]
    cmp     al, 0
    je      done

    inc     qword ptr length_count

    cmp     al, 'a'
    jb      check_upper
    cmp     al, 'z'
    ja      check_upper
    inc     qword ptr lower_case
    jmp     next_character

check_upper:
    cmp     al, 'A'
    jb      check_digit
    cmp     al, 'Z'
    ja      check_digit
    inc     qword ptr upper_case
    jmp     next_character

check_digit:
    cmp     al, '0'
    jb      check_space
    cmp     al, '9'
    ja      check_space
    inc     qword ptr digit_count
    jmp     next_character

check_space:
    cmp     al, ' '
    jne     next_character
    inc     qword ptr space_count

next_character:
    inc     r8
    jmp     string_loop

done:
    mov     eax, dword ptr length_count
    dtoa    printN1, eax
    mov     eax, dword ptr lower_case
    dtoa    printN2, eax
    mov     eax, dword ptr upper_case
    dtoa    printN3, eax
    mov     eax, dword ptr digit_count
    dtoa    printN4, eax
    mov     eax, dword ptr space_count
    dtoa    printN5, eax

    output  resultLbl,resulttxt

    add     rsp, 120
    mov     rax, 0
    ret
MainProc ENDP
END
