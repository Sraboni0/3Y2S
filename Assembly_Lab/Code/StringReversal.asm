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
        OUTPUT:
            MOV DL,STR[SI]
            INT 21H
            CMP SI,0
            JZ DONE
            DEC SI
            JMP OUTPUT
       DONE:
    
    ; RETURNS CONTROL TO THE OPERATING SYSTEM             
    MOV AH , 4CH
    INT 21H
    MAIN ENDP
END MAIN