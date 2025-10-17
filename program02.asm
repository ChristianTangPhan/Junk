; Calculate the area and perimeter
; Name:    Christian Phan
; ID:      150311
; Class:   CS 321
; Date:    9/15/2025

; "This assignment is my original work for CS 321, created and completed during the fall 2025 semester.  I have
; neither copied this work nor had another person or AI do any of my work for me."

;       Christian Phan

.586
.MODEL FLAT

INCLUDE io.h 

.STACK 4096

.DATA
base       DWORD   ?
height     DWORD   ?
area       DWORD   ?
perimeter  DWORD   ?
prompt1    BYTE    "Enter the base",    0
prompt2    BYTE    "Enter the height",  0

resultLbl BYTE "The answers:",          0

resultTxt BYTE "The base is "
printN1   BYTE 11 DUP (?),             10
          BYTE "The height is "
printN2   BYTE 11 DUP (?),             10
          BYTE "The area is  "
printN3   BYTE 11 DUP (?),             10
          BYTE "The perimeter is "
printN4   BYTE 11 DUP (?),             10



.CODE
_MainProc PROC
        ; Get base and height
        input   prompt1,   printN1, 40
        input   prompt2,   printN2, 40 

        ; Covert base and height
        atod    printN1 
        mov     base,       eax 
        atod    printN2
        mov     height,     eax 
        
        ; Calculate and store area
        mov     eax,        base
        mul     height

        ; Calculate and store perimeter
        mov     eax,        base 
        add     eax,        height 
        mov     ebx,        2
        mul     ebx
        mov     perimeter,  eax

        ; Display area and perimeter
        dtoa printN1, base
        dtoa printN2, height
        dtoa printN3, area
        dtoa printN4, perimeter

        output  resultLbl, resultTxt

        ; Reset and terminate
        mov     eax, 0
        ret
_MainProc ENDP
END 

