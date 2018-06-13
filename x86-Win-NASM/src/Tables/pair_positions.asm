;English
;Print on the screen the sum of the elements on pair positions
;Exemple 1:
;x DB 1,9,3,4,5,8
;n DB 6
;This will print 9 (the sum of x[0], x[2], x[4])

;Exemple 2:
;x DB 1,9,3,4,5,8,2
;n DB 7
;This will print: 11 (the sum of x[0], x[2], x[4], x[6])


;French
;Affichage sur l'écran de l'émulateur la somme des
;éléments de la position même pour un tableau.
;Exemple 1:
;x DB 1,9,3,4,5,8
;n DB 6
;La valeur doit être imprimée est: 9 (somme de x [0], x
;[2], x [4])
;Exemple 2:
;x DB 1,9,3,4,5,8,2
;n DB 7
;La valeur doit être imprimée est: 11 (somme de x [0], x
;[2], x [4], x [6]) 

org 100h
include "emu8086.inc"

.data
:
x DW 1,9,3,4,5,8,2  ; define the table
n DW 7 ;define the number of elements as a word
msgsum db 0dh, 0ah, "Sum of elements on pair positions is ",0
msgstop db 0dh, 0ah, "Stopping...",0

.code
MOV CX, [n] ; CX gets the value of the word n
LEA SI, x 
MOV AX, 0 ;AX will hold the sum  
MOV BX, 1 ;BX will work as a FLAG: it will be BX == 1, if the element is pair, 0 otherwise
looper:
    CMP BX, 1
    JE pair
    JL npair
    continue:
    ADD SI,2 
    LOOP looper                    
JMP print

pair:
    ADD AX, [SI] ;adds the value of the current element of the table to AX
    MOV BX, 0 ; BX takes the value 0, because the next element will be on IMPAIR indice
    JMP continue    
npair:
    MOV BX,1 ; Next element will be on pair indice
    JMP continue   


print:
    LEA SI, msgsum
    call print_string
    
    call print_num

                    
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