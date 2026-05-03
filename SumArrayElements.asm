// SumArrayElements.asm
// Computes the sum of all elements in an array
// R0 = base address of array
// R1 = number of elements
// R2 = sum
// Does not modify R0 or R1

// sum = 0
@R2
M=0

// If R1 <= 0, end
@R1
D=M
@END
D;JLE

// R3 = current address = R0
@R0
D=M
@R3
M=D

// R4 = counter = R1
@R1
D=M
@R4
M=D

(LOOP)
// If counter == 0, end
@R4
D=M
@END
D;JEQ

// D = RAM[R3]
@R3
A=M
D=M

// R2 = R2 + RAM[R3]
@R2
M=D+M

// R3 = R3 + 1
@R3
M=M+1

// R4 = R4 - 1
@R4
M=M-1

// Repeat loop
@LOOP
0;JMP

(END)
@END
0;JMP