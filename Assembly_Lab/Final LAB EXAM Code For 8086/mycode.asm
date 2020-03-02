                            INCLUDE 'EMU8086.INC'
.MODEL SMALL
.STACK 100H

.DATA
    STR DB 80 DUP(?)
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    PRINTN "Enter STRINGS: "
    
    MOV SI,0
    MOV AH,1
    INPUT:
        INT 21H
        CMP AL,0DH
        JE OUT1
        MOV STR[SI],AL
        INC SI
        JMP INPUT
    OUT1:
       PRINTN
       PRINTN "NUMBER OF WORD: "
        MOV BX,0
        
        MOV AH,2
        PUT:
            JE PRNT
            CMP STR[SI],32
            JE PR
            DEC SI
            JMP PUT       
       PRNT:
          MOV DL,SI
          INT 21H
           
    MOV AH, 4CH
    INT 21H
    
    MAIN ENDP
END MAIN