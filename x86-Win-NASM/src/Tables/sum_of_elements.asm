;English
;Print on the screen the sum of the elements
;of a table
;Example:
;x DW 1,2,2,3,3
;n DW 5
;The value that has to be printed is : 11

;French
;Affichage sur l'écran de l'émulateur la
;somme des éléments d'un tableau.
;Exemple:
;x DW 1,2,2,3,3
;n DW 5
;La valeur doit être imprimé est: 11


org 100h
include "emu8086.inc"

.data
:
x DW 1,2,2,3,3 ;define the table as a word
msgsum db 0dh, 0ah, "Sum is ",0
msgstop db 0dh, 0ah, "Stopping...",0

.code
MOV CX, 5 ; number of the elements of the table
MOV AX, 0 ; will hold the sum of the elements
LEA SI, x ; points SI to x (to its first element)
looper:
    ADD AX, [SI] ;adds the value of the element to AX
    ADD SI,2 ; increases SI by two, so that it will point to the next element ( WORD -> increase by 2, BYTE -> increase by 1)
    LOOP looper                    
 

LEA SI, msgsum
call print_string

call print_num ; prints AX to the screen

                    
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