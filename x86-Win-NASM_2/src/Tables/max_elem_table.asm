;English
;Print on the screen the maximal element from a table
;Exemple:
;x DB 9,12,3,4,5
;n DW 5
;The value that has to be printed is : 12 


;French
;Affichage sur l'écran de l'émulateur l'élément
;maximal d'un tableau.
;Exemple:
;x DB 9,12,3,4,5
;n DW 5
;La valeur doit être imprimé est: 12 

org 100h
include "emu8086.inc"

.data
:
x DW 9,12,3,4,5
n DW 5
msgsum db 0dh, 0ah, "Max is ",0
msgstop db 0dh, 0ah, "Stopping...",0

.code
MOV CX, [n]
MOV AX, 0 ; AX will store the maximal element
LEA SI, x
looper:
    CMP AX, [SI] ;checks if the current value of the table is larger than AX
    JL f_max ; if AX is less (JL == JUMP LESS), AX gets the value [SI]
    continue:
    ADD SI,2
    LOOP looper                    

JMP print ; after all elements have been parsed, the program jumps to print
f_max:
    MOV AX, [SI]
    JMP continue ; continues to parse the elements
print:
    LEA SI, msgsum
    call print_string
    
    call print_num ; prints AX

                    
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