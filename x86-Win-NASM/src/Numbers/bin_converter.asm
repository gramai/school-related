
;English
;Read a binary number and convert in in decimal, octal and hexadecimal

;French
;Lisez un nombre binaire et vous devez le convertir en décimal, octal et hexadécimal.

ORG 100h
include "emu8086.inc"

.data
:
DB "0"

s1 DB "00000000", 0 ; s1 will be used to store the binary number
s2 DB "00", 0 ; stores the choice of the user
s_octal DB "GGGGGGGG", 0 
l DB "0", 0 ;length of the binary number
sum DW 0  ; result.
flag DB 0 
msg0 DB 0dh, 0ah, "Insert binary length (min 1 max 8) ", 0
msg1 DB 0dh, 0ah, "Insert binary ", 0
msg2 DB 0dh, 0ah, "decimal: ", 0
msg3 DB 0dh, 0ah, "unsigned decimal: ", 0
msg4 DB 0dh, 0ah, "signed decimal: ", 0
msg5 DB 0dh, 0ah, "error: only zeros and ones are allowed!", 0
msg6 DB 0dh, 0ah, "Execution finished...", 0  
      
msg7 DB 0dh, 0ah, "1=to decimal, 2=to octal, 3= to hex : ", 0
msg8 DB 0dh, 0ah, "Octal: ", 0
msg9 DB 0dh, 0ah, "Hexadecimal: ", 0
                               
msgok0 DB 0dh, 0ah, " is 0 ", 0 
msgok1 DB 0dh, 0ah, " is 1 ", 0 
msgokfalse DB 0dh, 0ah, " OK IS FALSE ", 0                  
.code

;print msg0
LEA SI, msg0
CALL print_string

;get the length of the binary number
MOV DX,2
LEA DI, l
CALL GET_STRING
      
               
               
LEA SI, msg1
CALL print_string

;get the binary number
MOV DX, 9 
LEA DI, s1
CALL GET_STRING

;print the options
LEA SI, msg7
CALL print_string

;get the user option
MOV DX, 2
LEA DI, s2
CALL GET_STRING
                        
MOV SI, OFFSET s2
CMP [SI], 32h ; compares the user option to 2
JL decim ; if less -> 1 -> transform binary to decimal
JE octal ; == 2 -> transform binary to octal        
JG hexa  ; == 3 -> transform binary to hexadecimal

          
;binary to decimal algorithm           
;SI will point to the last element of the binary number

;Characters will be afterwards parsed right-to-left, and the corresponding decimal values (powers of 2)
;will be added to AL

decim:     
    MOV SI, OFFSET s1 ; SI will point to the first character of the binary number
    
    MOV DI, OFFSET l ; get the length of the binary number
    MOV AX, [DI] ;ax will store the length
    SUB AX, 31h ; transforms it to integer
    MOV CX, AX ; CX will take the length of the binary number, to be able to execute LOOPs
    incr: ; go to the last element of the binary number
        INC SI
        LOOP incr
    
    MOV BL, 1 ; BL will hold powers of 2 (1, 2, 4, 8...)
    MOV AX, 0 ;AX will hold the value of the decimal number
    MOV CX, 8 ; CX is the maximal length of the binary number
        
    parser:       
        JCXZ stop ; if CX == 0, jump to stop
        CMP [SI], 31h ; check if the current element is == 1
        JL ok0 ; if [SI] == 0
        JE ok1 ; if [SI] == 1
        JG okfalse   ; else -> error
          
    JMP stop             

ok0:
    SHL BL, 1 ; Shift Left BL -> BL = BL * 2
    DEC SI ; backwards parsing
    DEC CX 
    JMP parser ;continues to parse the elements    
ok1:
    ADD AL, BL ;adds to AL BL, that is a power of 2 
    SHL BL, 1   
    DEC SI
    DEC CX  
    JMP parser
okfalse: ;error
    LEA SI, msgokfalse 
    CALL print_string    
    JMP parser    
    
 stop:     
  
    LEA SI, msg2
    call print_string         
             
    call print_num
                         
    MOV AH, 0
    INT 16h
    RET   
    
 
    
;the binary number will be parsed in batches of three characters
;BL will take the values : 1,2,4 in this order, and no other values


octal:
    PUTC 10
    PUTC 13
    MOV SI, OFFSET s1
    
    MOV DI, OFFSET l
    MOV AX, [DI] 
    SUB AX, 31h
    MOV CX, AX   
    incr_octal:
        INC SI
        LOOP incr_octal
    
    MOV BL, 1
    MOV AX, 0
    MOV CX, 8
        
    parser_octal:       
        JCXZ stop_octal            
        CMP [SI], 31h
        JL ok0_octal
        JE ok1_octal 
        JG okfalse   
                     
                  
    
ok0_octal:
    SHL BL, 1 
    DEC SI
    DEC CX    
        
    CMP BL, 8 ;if BL == 8 -> the batch is finished ->BL has to retake the first value (1)
    JGE redo
    JMP parser_octal    
    
ok1_octal: 
    ADD AL, BL     
    
    SHL BL, 1
    DEC SI
    DEC CX   
    
    CMP BL, 8
    JGE redo
    JMP parser_octal 

redo:
        MOV BL,1      
        
        MOV DI, SI ; the element that is stored in AX has to replace the value of the corresponding octal 
                   ;string character
        MOV SI, OFFSET s_octal ;first element of the octal string       
        looper:
            CMP [SI], 47h ; if character == 47h == "G" it means that the element hasn't been replaced and
                          ;has to be replaces 
            JE replace      
            JL cont_redo
        continue:                        
            MOV SI, DI
            MOV AX, 0
            
            JMP parser_octal                
        
replace:           
    ADD AX, 30h
    MOV [SI], AX
    JMP continue   
cont_redo:
    INC SI 
    JMP looper
    
stop_octal:     
    LEA SI, msg8
    call print_string         
    MOV CX, 8
    MOV SI, OFFSET s_octal
    switcher: ;parses the elements of the octal string until it gets to an element that hasn't been replaced
        CMP [SI], 47H ;checks if current element was replaced or is still == 47H == "G"
        JNE go_go  ;if it is replaced, get to the next element
        JE stop_stop ; if it is == "G", we have reached the final element of the octal string
        cont:
            LOOP switcher
    MOV CX, 8
    printer: ;prints the octal number
        JCXZ continue_gtp
        JMP gtp
    continue_gtp:          
        LEA SI, msg6
        call print_string         
                         
        PUTC 10
        PUTC 13     
              
        MOV AH, 0
        INT 16h
        RET

gtp:                     
    CMP AX, 0 ; if there is a value in AX, meaning that binary number length % 3 != 0, the number is printed
    JG clean_up ;prints AX
    CALL print_string ;prints the current element of the string
    DEC SI
    DEC CX
    JMP printer
go_go:
    INC SI  
    JMP cont
stop_stop:
    DEC SI
    JMP printer
clean_up:
    CALL print_num     
    MOV AX, 0
    JMP gtp
      

;hexa works similar to octal but in batches of 4 elements
;BL can take the values 1,2,4,8 in this order.
           
hexa:
    PUTC 10
    PUTC 13
    MOV SI, OFFSET s1
    
    MOV DI, OFFSET l
    MOV AX, [DI] 
    SUB AX, 31h
    MOV CX, AX   
    incr_hexa:
        INC SI
        LOOP incr_hexa
    
    MOV BL, 1
    MOV AX, 0
    MOV CX, 8
        
    parser_hexa:       
        JCXZ stop_hexa
        CMP [SI], 31h
        JL ok0_hexa
        JE ok1_hexa
        JG okfalse   
                     
                  
    
ok0_hexa:
    SHL BL, 1 
    DEC SI
    DEC CX    
        
    CMP BL, 16
    JGE redo_hexa
    JMP parser_hexa    
    
ok1_hexa: 
    ADD AL, BL     
    
    SHL BL, 1
    DEC SI
    DEC CX   
    
    CMP BL, 16
    JGE redo_hexa
    JMP parser_hexa 

redo_hexa:
        MOV BL,1      
        
        MOV DI, SI
        MOV SI, OFFSET s_octal       
        looper_hexa:
            CMP [SI], 47h
            JE replace_hexa      
            JL cont_redo_hexa
        continue_hexa: 
            MOV BL, 1                       
            MOV SI, DI
            MOV AX, 0
            
            JMP parser_hexa
        
replace_hexa:
    CMP AX, 9 ;checks if AX is greater than 9. 
    ;If this is the case, that means that it has to be converted to the corresponding character
    JG greater
    JLE rh_continue                  

rh_continue:
    ADD AX, 30h
    MOV [SI], AX
    JMP continue_hexa   

greater:
    MOV BX, AX ; the value of AX is stored as backup in BX
    MOV AX, 0
    MOV CX, 0
    search_hex: ;substracts 1 from BX until it gets to the value 9
                ; the value held in CX will be the value of the character
                ;CX, 1 -> A, 2 -> B, 3->C, 4-> D, 5-> E, 6-> F
        INC CX 
        DEC BX
        CMP BX, 9
        JG search_hex
        JLE done_search_hex

done_search_hex:
;for CX, 1 -> A, 2 -> B, 3->C, 4-> D, 5-> E, 6-> F
    CMP CX, 1
    JE A_found
    JG B_check
    
A_found:          
    MOV AX, 'A'
    MOV [SI], AX
    JMP continue_hexa
B_check:
    CMP CX, 2
    JE B_found
    JG C_check
    
B_found:        
    MOV AX, 'B'
    MOV [SI], AX
    JMP continue_hexa
C_check:
    CMP CX, 3
    JE C_found
    JG D_check
    
C_found:        
    MOV AX, 'C'
    MOV [SI], AX
    JMP continue_hexa
D_check:
    CMP CX, 4
    JE D_found
    JG E_check
        
D_found:        
    MOV AX, 'D'
    MOV [SI], AX
    JMP continue_hexa
E_check:
    CMP CX, 5
    JE E_found
    JG F_check
        
E_found:        
    MOV AX, 'E'
    MOV [SI], AX
    JMP continue_hexa
F_check:
    CMP CX, 6
    JE F_found
    JG error_not_valid

F_found:    
    MOV AX, 'F'
    MOV [SI], AX
    JMP continue_hexa
    
     
cont_redo_hexa:
    INC SI 
    JMP looper_hexa
    
stop_hexa:  
    LEA SI, msg9
    call print_string         
    MOV CX, 8
    MOV SI, OFFSET s_octal
    switcher_hexa:
        CMP [SI], 47H
        JNE go_go_hexa
        JE stop_stop_hexa
        cont_hexa:
            LOOP switcher_hexa
    MOV CX, 8
    printer_hexa:
        JCXZ continue_gtp_hexa
        CMP [SI], 47H
        JL gtp_hexa
    continue_gtp_hexa:          
        LEA SI, msg6
        call print_string         
                         
        PUTC 10
        PUTC 13     
                      
        MOV AH, 0
        INT 16h
        RET

gtp_hexa:                     
    CALL print_string
    DEC SI
    DEC CX
    JMP printer_hexa
go_go_hexa:
    INC SI  
    JMP cont_hexa
stop_stop_hexa:
    DEC SI
    JMP printer_hexa
clean_up_hexa:
    CALL print_num     
    MOV AX, 0
    JMP gtp_hexa
     
        
        
error_not_valid:
LEA SI, msg5
call print_string
                           
DEFINE_GET_STRING          
DEFINE_PRINT_STRING
DEFINE_PRINT_NUM
DEFINE_PRINT_NUM_UNS
DEFINE_SCAN_NUM

END