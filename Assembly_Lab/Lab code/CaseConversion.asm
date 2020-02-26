.MODEL SMALL
.STACK 100H
.DATA
    MSG DB "ENTER A STRING: $"
    MSG2 DB "CASE CONVERTED STRING: $"
    STR DB 80 DUP(?)
.CODE

MAIN PROC       
    
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AH,9
    LEA DX,MSG
    INT 21H
    
    ;INPUT STRING
    MOV SI,0
    MOV AH,1
    
    INPUT:
        INT 21H
        CMP AL,0DH
        JZ NEXT
        MOV STR[SI],AL
        INC SI
        JMP INPUT
    NEXT:
          MOV AH,2
        MOV DL,0DH
        INT 21H
        MOV DL,0AH
        INT 21H
        
        MOV AH,9
        LEA DX,MSG2
        INT 21H
        
        MOV AH,2
        MOV BX,SI ;KEEP SI(SOURCE INDEX)
        MOV SI,0
        
        OUTPUT:
            CMP SI,BX
            JZ END_OUT
            MOV DL,STR[SI]
            
            CMP DL,'z'
            JG NOTCHAR
            
            CMP DL,'a'
            JGE LOWERCASE
            
            CMP DL,'Z'
            JG NOTCHAR
            
            CMP DL,'A'
            JGE UPPERCASE
            
            JMP NOTCHAR
           
           ;SUB DL BY 20H TO MAKE IT UPPERCASE
           ;ADD DL BY 20H TO MAKE IT LOWERCASE 
            LOWERCASE:
                SUB DL,20H
                JMP PRINT
            UPPERCASE:
                ADD DL,20H
                JMP PRINT
            NOTCHAR:
                JMP PRINT
                
            PRINT:
                INT 21H
                INC SI
                JMP OUTPUT
     END_OUT:
    
    ; RETURNS CONTROL TO THE OS             
    MOV AH , 4CH
    INT 21H
    MAIN ENDP
END MAIN