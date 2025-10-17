; Name:  Christian Phan
; ID:    150311
; Class: CS 321
; Date:  9/9/2025

; "This assignment is my original work for CS 321, created and completed during the fall 2025 semester.  I have
; neither copied this work nor had another person or AI do any of my work for me."

;       Christian Phan

.586
.MODEL FLAT

.STACK 4096

.DATA
var1 DWORD 1357h
var2 DWORD 9bdfh
var3 DWORD 2468h

.CODE
main PROC
     mov eax,  var3
     mov ebx,  var1
     mov var3, ebx
     mov ebx,  var2
     mov var1, ebx
     mov var2, eax

; check values in each variable
     mov eax,  var1
     mov eax,  var2
     mov eax,  var3

     mov eax, 0
     ret            ; returns eax by default
main ENDP

END
