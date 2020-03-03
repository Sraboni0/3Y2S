INCLUDE 'EMU8086.INC'
.MODEL SMALL
.STACK 100H
.DATA
    STR DB 80 DUP (?)
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    PRINTN "ENTER STRING: "
    MOV SI,0
    MOV AH,1
        INPUT:
            INT 21H
            CMP AL,0DH
            JE NEXT
            MOV STR[SI],AL
            INC SI
            JMP INPUT
        NEXT:
            PRINTN
    ; CALL COUNT_DIGIT
    
    ; COUNT_DIGIT PROC
            MOV BX,SI
            MOV SI,0
            MOV CX,0
            
            PRINT "NUMBER OF DIGIT="  
            MOV AH,2
            DIGIT:
                CMP SI,BX
                JE END_DIGIT
                
                CMP STR[SI],'9'
                JG UPPER_BOUND
                
                CMP STR[SI],'0'
                JGE DIGIT_CNT
                
                INC SI
                JMP DIGIT
           DIGIT_CNT:
                INC SI
                INC CX
                JMP DIGIT
           UPPER_BOUND:
                INC SI
                JMP DIGIT
           END_DIGIT:
                MOV DX,CX
                ADD DX,48
                INT 21H
           PRINTN
     ;COUNT_DIGIT ENDP
     
        PRINT "NUMBER OF SPACE="  
            MOV SI,0
            MOV CX,0
            MOV AH,2
            SPACE:
                CMP SI,BX
                JE END_SPACE
                
                CMP STR[SI],' '
                JE SPACE_CNT
                
                INC SI
                JMP SPACE
           SPACE_CNT:
                INC SI
                INC CX
                JMP SPACE
           END_SPACE:
                MOV DX,CX
                ADD DX,48
                INT 21H
    
           PRINTN
    
    MOV AH,4CH
    INT 21H
     
    MAIN ENDP
END MAIN
