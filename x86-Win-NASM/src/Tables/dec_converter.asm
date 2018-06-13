;English
;Read a decimal number and convert it in binary, octal and hexadecimal

;French
;Lisez un nombre décimal et vous devez le convertir en binaire, octal et hexadécimal.

;Similar to bin_converter (find explanation there)

ORG 100H
include "emu8086.inc"

.data
:
l DB "00",0
s1 DB "0000",0
s2 DB "00",0
s_binary DB "00000000",0
s_octal DB "GGGGGGGG",0

msg0 DB 0dh, 0ah, "Insert decimal number length: ",0
msg1 DB 0dh, 0ah, "Insert decimal number (between 0 - 255 ) : ",0
msg2 DB 0dh, 0ah, "1=b, 2=o, 3=h : ",0



msgbin DB 0dh, 0ah, "Binary= ",0   
msgoct DB 0dh, 0ah, "Octal= ",0
msghex DB 0dh, 0ah, "Hexal= ",0   
msgtest DB 0dh, 0ah, "Testing... ",0
msgstop DB 0dh, 0ah, "Stopping... ",0

.code
LEA SI, msg0
CALL print_string

MOV DX, 2
LEA DI, l
call get_string

LEA SI, msg1
CALL print_string

CALL scan_num

LEA SI, msg2
CALL print_string

MOV DX, 2
LEA DI, s2
CALL get_string

MOV DI, OFFSET s2
MOV AX, [DI]
SUB AX, 30H
CMP AX, 2
JL binary
JE octal
JG hexa
            
binary:
    MOV AX, CX
    MOV BX, 1
    SHL BX, 8
    MOV SI, OFFSET s_binary
    continue_binary:                            
        CMP BX, 255
        JG pass
        INC SI
        pass:
            CMP AX, BX
            JL smaller
            JE equal        
            JG greater
    exit_first_binary:
        INC SI
        MOV [SI], 0
        CMP DH, 1
        JE continue_octal
        JG continue_hexa_prime
        
        LEA SI, msgbin
        CALL print_string
        
        MOV SI, OFFSET s_binary
        CALL print_string 
        
        JMP stop

smaller:
    SHR BX, 1
    CMP BX, 0
    JE exit_first_binary
    JMP continue_binary
equal: 
    MOV [SI], 31H
    JMP exit_first_binary
greater:
    MOV [SI], 31H
    SUB AX, BX
    SHR BX, 1          
    CMP BX, 0
    JE exit_first_binary
    JMP continue_binary
    
 
    
octal:
    MOV DH, 1
    JMP binary
    continue_octal: 
        MOV AX, 0
        MOV SI, OFFSET s_binary          
        MOV CX, 8
        out_0:
            CMP [SI], 30H
            JE zero_freeze 
            JG stop_freeze
            continue_out_0:
                LOOP out_0
        stop_freeze:
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
                      

zero_freeze:
    INC SI
    JMP continue_out_0
        
ok0_octal:
    SHL BL, 1 
    DEC SI
    DEC CX    
        
    CMP BL, 8
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
        
        MOV DI, SI
        MOV SI, OFFSET s_octal       
        looper:
            CMP [SI], 47h
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
    LEA SI, msgoct
    call print_string         
    MOV CX, 9
    MOV SI, OFFSET s_octal
    switcher:
        CMP [SI], 47H
        JNE go_go
        JE stop_stop
        cont:
            LOOP switcher
    MOV CX, 8
    printer:
        JCXZ continue_gtp
        CMP [SI], 47h
        JMP gtp
    continue_gtp:          
        LEA SI, msgstop
        call print_string         
                         
        PUTC 10
        PUTC 13     
              
        MOV AH, 0
        INT 16h
        RET

gtp:                     
    CMP AX, 0
    JG clean_up
    CALL print_string
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

    
  
  
           
hexa:
    MOV DH, 2
    JMP binary
    continue_hexa_prime: 
        MOV AX, 0
        MOV SI, OFFSET s_binary          
        MOV CX, 8
        out_0_hexa:
            CMP [SI], 30H
            JE zero_freeze_hexa 
            JG stop_freeze_hexa
            continue_out_0_hexa:
                LOOP out_0_hexa
        stop_freeze_hexa:
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
zero_freeze_hexa:
    INC SI
    JMP continue_out_0_hexa                     
                  
    
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
    CMP AX, 9
    JG greater_hexa
    JLE rh_continue            ;check if number > 10           

rh_continue:
    ADD AX, 30h
    MOV [SI], AX
    JMP continue_hexa   

greater_hexa:
    MOV BX, AX
    MOV AX, 0
    MOV CX, 0
    search_hex: 
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

F_found:    
    MOV AX, 'F'
    MOV [SI], AX
    JMP continue_hexa
    
     
cont_redo_hexa:
    INC SI 
    JMP looper_hexa
    
stop_hexa:  
    LEA SI, msghex
    call print_string         
    MOV CX, 9
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
        LEA SI, msgstop
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