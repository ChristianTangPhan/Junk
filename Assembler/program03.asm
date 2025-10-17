; Name:  Christian Phan
; ID:    150311
; Class: CS 321
; Date:  9/9/2025

; "This assignment is my original work for CS 321, created and completed during the fall 2025 semester.  I have
; neither copied this work nor had another person or AI do any of my work for me."

;       Christian Phan

INCLUDE io.h

.DATA
number1   QWORD   ?
number2   QWORD   ?
number3   QWORD   ?
num       QWORD   ?
dem       QWORD   ?
prompt1   BYTE    "Enter first number", 0
prompt2   BYTE    "Enter second number", 0
prompt3   BYTE    "Enter third number", 0
string    BYTE    40 DUP (?)
resultLbl BYTE    "The answer is", 0
result    BYTE    "Quotient: "
quotient  BYTE    11 DUP(?), 10
          BYTE    "Remainder: "
remainder BYTE    11 DUP(?), 0

.CODE
MainProc  PROC
          sub     rsp, 120

          ; Get inputs
          input   prompt1, string, 40
          atod    string
          mov     number1, rax
          input   prompt2, string, 40
          atod    string
          mov     number2, rax
          input   prompt3, string, 40
          atod    string
          mov     number3, rax
          
          ; Move values to registers
          mov     rdx, number1
          mov     rbx, number2
          mov     rcx, number3

          ; Calculate
          mov     rax, rcx ; third number
          mul     rbx      ; times second number
          add     rdx, rax ; + first number
          mov     num, rax ; store numerator in num

          mov     rax, 2   ; 2
          mul     rbx      ; times second number
          mov     dem, rax ; store denominator in dem

          mov     rax, num ; move numerator to rax
          mov     rbx, dem ; move denominator to rbx
          cqo
          div     rbx      ; divide rdx:rax by rbx
 
          ; Convert ASCII
          mov     ebx, eax       ; move lower 32 bits of quotient to ebx
          dtoa    quotient, ebx  ; convert to ASCII
          mov     ebx, edx       ; move lower 32 bits of remainder to ebx
          dtoa    remainder, ebx ; convert to ASCII

          ; Display results
          output  resultLbl, result

          add     rsp, 120        ; restore stack
          mov     rax, 0          ; return 0
          ret
MainProc ENDP
END
