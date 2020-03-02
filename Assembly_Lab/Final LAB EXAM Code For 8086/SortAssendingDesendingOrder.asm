; PROGRAM TO SORT A STRING (A WORD)
INCLUDE 'EMU8086.INC'
.MODEL SMALL
.STACK 100H 

.DATA
    MSG DB "ENTER A STRING: $"
    MSG2 DB "THE SORTED STRING IN ASCENDING ORDER: $"
    MSG3 DB "THE SORTED STRING IN DESCENDING ORDER: $"
    ; UNINITIALIZED STRING TO TAKE INPUT        
    STR DB 80 DUP (?)
    ; ARRAY TO KEEP COUNT OF LETTERS                 
    CNT DB 127 DUP (0)         
    
    
.CODE
MAIN PROC
    ;IMPORT DATA
    MOV AX , @DATA
    MOV DS , AX    
                
    ; SHOW MSG
    MOV AH , 9
    LEA DX , MSG
    INT 21H
    
    ; TAKE STRING INPUT
    MOV SI , 0   ; COUNTER VARIABLE
    
    MOV AH , 1   ; SINGLE CHARACTER INPUT FUNCTION
    
    INPUT:
        INT 21H
        CMP AL , 0DH        ; TAKE INPUT UNTIL NEWLINE
        JZ NEXT             ; IF NEWLINE IS FOUND GO OUT OF LOOP
        MOV STR[SI] , AL    ; INPUT CHARACTER IS IN AL
        MOV BX , SI         ; KEEP BACKUP OF SI
        MOV DL , STR[SI]
        MOV DH , 0
        MOV SI , DX     ; KEEP AL IN SI
        INC CNT[SI]
        MOV SI , BX         ; RESTORE THE ORIGINAL VALUE
        INC SI              ; INCREASE SI
        
        JMP INPUT          
                
    NEXT:                                    
        PRINTN                              
        
        MOV AH , 9
        LEA DX , MSG2
        INT 21H
        
        ;NOW OUTPUT THE STRING IN ASCENDING ORDER
        MOV BX , 0              ; BX IS THE VALUE OF THE CHARACTER TO CHECK
        MOV AH , 2
        
        OP:     
            MOV SI , BX         ; MOV BX TO SI, AS WE NEED TO USE THIS AS INDEX
            MOV CL , CNT[SI]    ; MOV THE NUMBER OF OCCURENCE OF THE CHARACTER IN BX
                                ; TO LOOP COUNTER REGISTER CL, THEN ITERATE THIS TIME
            REP:
                CMP CL , 0      ; KEEP ITERATING UNTIL CL IS 0
                JZ NR           ; GO TO NR IF TRUE
                MOV DX , BX     ; DISPLAY CHARACTER IN BX
                INT 21H
                DEC CL
                JMP REP
            NR:
            CMP BX , 127        ; CHECK IF BX IS 127
            JZ EXOUT            ; IF TRUE, EXIT THE LOOP
            INC BX              ; ELSE INCREASE BX, AND GO TO OP
            JMP OP            
EXOUT:
        PRINTN  
        
        MOV AH , 9
        LEA DX , MSG3
        INT 21H
        
        ;OUTPUT THE STRING IN DESCENDING ORDER
        MOV BX , 127              ; BX IS THE VALUE OF THE CHARACTER TO CHECK
        MOV AH , 2
        
        OP2:     
            MOV SI , BX         ; MOV BX TO SI, AS WE NEED TO USE THIS AS INDEX
            MOV CL , CNT[SI]    ; MOV THE NUMBER OF OCCURENCE OF THE CHARACTER IN BX
                                ; TO LOOP COUNTER REGISTER CL, THEN ITERATE THIS TIME
            REP2:
                CMP CL , 0      ; KEEP ITERATING UNTIL CL IS 0
                JZ NR2          ; GO TO NR2 IF TRUE
                MOV DX , BX     ; DISPLAY CHARACTER IN BX
                INT 21H
                DEC CL
                JMP REP2
            NR2:
            CMP BX , 0          ; CHECK IF BX IS 0
            JZ EXOUT2           ; IF TRUE, EXIT THE LOOP
            DEC BX              ; ELSE DECREASE BX, AND GO TO OP2
            JMP OP2
EXOUT2:  
    MOV AH, 41H
    INT 21H
    MAIN ENDP
END MAIN