;English
;Write a program that reads two integers from user input
;and calculates their sum

;French
;Ecrire un programme qui va obtenir deux
;entiers à partir du clavier et calculer leur
;somme.

org 100h
include "emu8086.inc" 

.data
:                                       
msg0 db 0dh, 0ah, "Insert first number: ",0 
msg1 db 0dh, 0ah, "Insert second number: ",0
msg2 db 0dh, 0ah, "Sum is ",0
msgstop db 0dh, 0ah, "Stopping...",0
.code

;prints msg0 to console
LEA SI, msg0
call print_string

;scans first number
call scan_num ; this saves input to CX

MOV AX, CX ; move the value of CX to AX, meaning AX = CX, so that AX will hold the first number

LEA SI, msg1
call print_string

call scan_num

ADD AX, CX ; AX already holds the first number so the second number (read in CX) is added to it, obtaining the sum

LEA SI, msg2
call print_string


call print_num ; print_num ALWAYS prints from AX 


stop:  
LEA SI, msgstop
call print_string

MOV AH, 0
INT 16h
RET
    
                              
DEFINE_GET_STRING          
DEFINE_PRINT_STRING
DEFINE_PRINT_NUM
DEFINE_PRINT_NUM_UNS
DEFINE_SCAN_NUM

END    