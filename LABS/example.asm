TITLE Add two registers (example.asm)
; The comments are given after the semi colon on a line
; This program adds 32-bit unsigned
; integers and stores the sum in the ecx register
Include irvine32.inc
.data
;variable declarations go here
.code
Main Proc
;instructions go here
Mov	eax, 30	;Assembly Language is NOT case sensitive
Mov	ebx, 20
Mov     ecx, 0
Add 	ecx, eax
Add 	ecx, ebx
Call 	dumpregs	;displays the result on the screen by displaying
                 ;all register values
Exit
Main endp
End main
