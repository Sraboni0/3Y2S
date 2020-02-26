INCLUDE 'EMU8086.INC'
.MODEL SMALL
.STACK 100H

.DATA
    N DB ?
    sum DB ?
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    PRINTN "Enter a number:"
    MOV AH,1
    INT 21H
    SUB AL,48
    
    CMP AL,0
    JE ZERO   
        MOV N,AL
        DEC N
        FOR_LOOP:
            CMP N,0
            JE ZERO
            MUL N
            DEC N
            JMP FOR_LOOP
        ZERO:
       MOV SUM,AL
       ;ADD SUM,48 
        PRINTN
        ;CALL NEWLINE
        AAM  ;adjust ascii
                
        MOV CH,AH  ;upper part store in ch
        MOV CL,AL
        
        MOV DL,CH ;Move first part of mul to DL register
        ADD DL,48
        MOV AH,2     ;Print first digit of multiplication
        INT 21H   
        
        MOV DL,CL
        ADD DL,48
        MOV AH,2  ;Print 2nd digit of multiplication
        INT 21H
       
       ;without Ascii Adjust
       CALL NEWLINE
       PRINTN "IN SIMPLY: "
       MOV AH,2
       MOV DL,SUM
       INT 21H 
       
    MOV AH, 4CH
    INT 21H
    
    MAIN ENDP
    
    NEWLINE PROC
        MOV AH,2
        MOV DL,0AH
        INT 21H
        MOV DL,0DH
        INT 21H
        RET    
    NEWLINE ENDP
END MAIN