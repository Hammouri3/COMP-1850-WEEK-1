// FindMaximumArrayElement.asm
// R0 = base address of array
// R1 = number of elements
// R2 = maximum element
// Does not modify R0 or R1

// If R1 <= 0, set R2 = 0 and stop
@R1
D=M
@NONEMPTY
D;JGT

@R2
M=0
@END
0;JMP

(NONEMPTY)
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

// max = RAM[R3]
@R3
A=M
D=M
@R2
M=D

// Move to next element
@R3
M=M+1
@R4
M=M-1

(LOOP)
// If counter == 0, stop
@R4
D=M
@END
D;JEQ

// D = RAM[R3] - R2
@R3
A=M
D=M
@R2
D=D-M

// If current <= max, do not update
@SKIP_UPDATE
D;JLE

// R2 = RAM[R3]
@R3
A=M
D=M
@R2
M=D

(SKIP_UPDATE)
// current address++
@R3
M=M+1

// counter--
@R4
M=M-1

@LOOP
0;JMP

(END)
@END
0;JMP