// SumEvenIntegers.asm
// R0 = n
// R1 = sum of first n even integers
// If n < 0, R1 = -1
// If overflow, R1 = -2
// Does not modify R0

// If R0 < 0, return -1
@R0
D=M
@NEGATIVE
D;JLT

// R1 = 0
@R1
M=0

// R3 = counter = n
@R0
D=M
@R3
M=D

// R4 = current even number = 2
@2
D=A
@R4
M=D

(LOOP)
// If counter == 0, end
@R3
D=M
@END
D;JEQ

// If current even number <= 0, overflow
@R4
D=M
@OVERFLOW
D;JLE

// D = R1 + R4
@R1
D=M
@R4
D=D+M

// If result < 0, overflow
@OVERFLOW
D;JLT

// R1 = result
@R1
M=D

// current even number += 2
@2
D=A
@R4
M=D+M

// counter--
@R3
M=M-1

@LOOP
0;JMP

(NEGATIVE)
@R1
M=-1
@END
0;JMP

(OVERFLOW)
@2
D=A
D=-D
@R1
M=D

(END)
@END
0;JMP