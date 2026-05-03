// IntegerDivision.asm
// R0 = x
// R1 = y
// R2 = quotient m
// R3 = remainder q
// R4 = invalid flag
// R4 = 1 if y == 0, otherwise 0
// Does not modify R0 or R1

// If y == 0, invalid
@R1
D=M
@VALID
D;JNE

@R4
M=1
@R2
M=0
@R3
M=0
@END
0;JMP

(VALID)
@R4
M=0

// R9 = sign of x: 0 positive, 1 negative
@R9
M=0
@R0
D=M
@X_POSITIVE
D;JGE

@R9
M=1

(X_POSITIVE)

// R10 = sign of y: 0 positive, 1 negative
@R10
M=0
@R1
D=M
@Y_POSITIVE
D;JGE

@R10
M=1

(Y_POSITIVE)

// R5 = abs(x)
@R0
D=M
@ABS_X_POSITIVE
D;JGE

@R0
D=M
D=-D
@R5
M=D
@ABS_X_DONE
0;JMP

(ABS_X_POSITIVE)
@R0
D=M
@R5
M=D

(ABS_X_DONE)

// R6 = abs(y)
@R1
D=M
@ABS_Y_POSITIVE
D;JGE

@R1
D=M
D=-D
@R6
M=D
@ABS_Y_DONE
0;JMP

(ABS_Y_POSITIVE)
@R1
D=M
@R6
M=D

(ABS_Y_DONE)

// R7 = quotient absolute value
@R7
M=0

(DIV_LOOP)
// If abs(x) - abs(y) < 0, division is done
@R5
D=M
@R6
D=D-M
@DIV_DONE
D;JLT

// abs(x) = abs(x) - abs(y)
@R5
M=D

// quotient++
@R7
M=M+1

@DIV_LOOP
0;JMP

(DIV_DONE)

// Decide sign of quotient
// If signX == signY, quotient is positive
@R9
D=M
@R10
D=D-M
@QUOTIENT_POSITIVE
D;JEQ

// Quotient is negative
@R7
D=M
D=-D
@R2
M=D
@SET_REMAINDER
0;JMP

(QUOTIENT_POSITIVE)
@R7
D=M
@R2
M=D

(SET_REMAINDER)
// Remainder has same sign as x
@R9
D=M
@REMAINDER_POSITIVE
D;JEQ

// Negative remainder
@R5
D=M
D=-D
@R3
M=D
@END
0;JMP

(REMAINDER_POSITIVE)
@R5
D=M
@R3
M=D

(END)
@END
0;JMP