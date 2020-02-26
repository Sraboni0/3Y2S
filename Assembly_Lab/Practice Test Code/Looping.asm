INCLUDE 'EMU8086.INC'
.MODEL
.STACK 100H
.DATA
.CODE
MAIN PROC    
    
    MOV CX,5
    MOV BX,0
    
    START:
        CMP BX,CX
        JE LAST
        
        PRINTN "GOOD BYE"  
        INC BX    
        JNC START
    LAST:
        PRINTN "PROGRAM tERMINATED"
        
    MOV AH,4CH
    INT 21H
    MAIN ENDP
END MAIN
    