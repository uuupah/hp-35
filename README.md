### hp-35
 this tool aims to emulate the input method and calculation style used by the hp-35 calculator, first used in 1972. the program uses reverse polish notation for its input, which allows for calculations without the use of parentheses. number inputs add values to the program's stack, and operations act on the two most recent values (registers x and y), placing the result back at the start of the stack and shifting the remaining numbers one space closer to the start to avoid a gap. single value operations act on the start of the stack (register x) and return it without modifying the other values or their locations. once the calculation is complete the program returns the value in the x register. for example: 
 
 ```
 - memory -
 [ ] [ ] [ ] [ ]
  x   y   z   t

 - input -
 5 7 + 4 sqrt /
 
 
 5 (add value to start of stack, shift other values back)
 [5] [ ] [ ] [ ]
 
 7 (add value to start of stack, shift other values back)
 [7] [5] [ ] [ ]
 
 + (add x and y registers)
 [12] [ ] [ ] [ ]
 
 4 (add value to start of stack, shift other values back)
 [4] [12] [ ] [ ]
 
 sqrt (replace the first value with its square root)
 [2] [12] [ ] [ ]
 
 / (divide y by x)
 [6] [ ] [ ] [ ]
 ```
 
 which is functionally identical to (5 + 7) / sqrt(4)
 
 ### operators
 
 #### binary arithmetic `+`, `-`, `*`, `/`
 ```
 4.62 3.38 +       // results in 8
 9.87 2.56 -       // results in 7.31
 12 4 *            // results in 48
 21 7 /            // results in 3
 
 ```
 
 #### scientific operators `chs`, `recip`, `log`, `ln`, `exp`, `sqrt`, `sin`, `cos`, `tan`, `arcsin`, `arccos`, `arctan`, `pow`, `PI`
 ```
 68 CHS            // results in -68      -> change sign
 4 RECIP           // results in 0.25     -> reciprocal
 1000 LOG          // results in 3        -> decimal log
 1000 LN           // results in 6.907... -> natural log
 1000 EXP LN       // results in 3        -> exponent
 16 SQRT           // results in 4        -> square root
 PI COS            // results in -1, equal to cos(pi). 
                      other trigonometric functions work in the same manner.
 7 2 POW           // results in 49, equal to 7^2
 ``` 
 
 #### memory functions `STO`, `RCL`, `CLR`, `CLX`
 ```
 2 STO 7 RCL -     // results in 5. store moves the first value in the stack to a 
                      separate memory register and recall returns it to the start of 
                      the stack, shifting the other values up
 4 8 CLR 7 3 +     // results in 10. clears entire stack.
 4 8 CLX 7 +       // results in 11. clears first (x) register.
 ```
 
 #### stack control `SWAP`, `ROLL`, `ENTER`
 ```
 7 21 SWAP /       // results in 3. swaps x and y register
 1 2 3 4 ROLL      // results in 3. 
                      stack should look like [4] [3] [2] [1] before roll
                      and [3] [2] [1] [4] after roll (x is shifted to t location)
 2 ENTER           // results in 2.
                      stack should look like [2] [2] [] [] after enter
 
 ```
 
