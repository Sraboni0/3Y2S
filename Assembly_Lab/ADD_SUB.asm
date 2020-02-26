.MODEL
.STACK 100H
.DATA

    A DB ?
    B DB ?
.CODE
MAIN PROC
    
    ;INPUT CHAR
    MOV AH,1
    INT 21H
    
    MOV A,AL
    SUB A,48
    
    INT 21H
    MOV B,AL
    SUB B,48
    ;INT 21H
    
    MOV BH,A ;BH = A
    ADD BH,B ;BH= BH+B
    ADD BH,48
    
    MOV AH,2
    
    MOV DL,0AH
    INT 21H
    MOV DL,0DH
    INT 21H
    
    MOV DL,BH
    INT 21H
    
    MOV AH,4CH
    INT 21H
    MAIN ENDP
END MAIN
    