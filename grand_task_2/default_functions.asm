global default_f1, default_f2, default_f3
global default_f1_derivative
global default_f2_derivative
global default_f3_derivative
global default_f1_formula
global default_f2_formula
global default_f3_formula

section .data
default_f1_formula: db "y = 1 + 4/(x^2 + 1)", 0
default_f2_formula: db "y = x^3", 0
default_f3_formula: db "y = 2^(-x)", 0

section .text

default_f1:
    push ebp
    mov ebp, esp

    finit

    fld1 ; for scale
    
    fld1 ; for division

    fld dword [ebp + 8]
    fld dword [ebp + 8]
    fmulp ; x * x
    fld1
    faddp ; x^2 + 1

    fdivp ; 1 / (x ^ 2 + 1)

    fscale ; 2 / (x^2 + 1)
    fscale  ; 4 / (x^2 + 1)
    
    faddp ; 1 + 4 / (x^2 + 1)

    leave
    ret


default_f1_derivative: ; -8x / (x^2 + 1)^2
    push ebp
    mov ebp, esp

    finit
    
    fld1
    fld dword [ebp + 8] ; x
    fscale ; 2*x
    fscale ; 4 * x
    fscale ; 8 * x
    fstp st1 ; pop
    fchs ; - 8 * x

    fld dword [ebp + 8]
    fld dword [ebp + 8]
    fmulp ; x ^ 2
    fld1
    faddp ; x ^ 2 + 1
    fld st0 ; push st0
    fmulp ; (x ^ 2 + 1) ^ 2
    fdivp ; -8x / (x ^ 2 + 1)^2

    leave
    ret


default_f2:
    push ebp
    mov ebp, esp


    finit
    fld dword [ebp + 8]
    fld dword [ebp + 8]
    fld dword [ebp + 8]
    fmulp
    fmulp ; x ^ 3

    leave
    ret


default_f2_derivative:
    push ebp
    mov ebp, esp

    finit
    fld dword [ebp + 8]
    fld dword [ebp + 8]
    mov dword [ebp + 8], 3
    fild dword [ebp + 8]
    fmulp
    fmulp ; 3 * x^2

    leave
    ret

exp2:
    push ebp
    mov ebp, esp


    finit
    
    fld dword [ebp + 8]
    fist dword [ebp + 8] ; [x]
    fild dword [ebp + 8]
    fsubp ; x - [x] = {x}
    f2xm1 ; 2^{x} - 1
    fld1
    faddp ; 2 ^ {x}
    fild dword [ebp + 8]
    fld1
    fscale ; 2 ^ [x]
    fstp st1

    fmulp

    leave
    ret

default_f3: ; 2^(-x)
    push ebp
    mov ebp, esp
    sub esp, 8

    finit
    
    fld dword [ebp + 8]
    fchs
    fstp dword [esp]

    call exp2

    leave
    ret


default_f3_derivative: ; -2^(-x) * ln2
    push ebp
    mov ebp, esp
    sub esp, 8

    finit
    
    fld dword [ebp + 8]
    fchs
    fstp dword [esp]
    call exp2
    fchs    
    fldln2
    fmulp

    leave
    ret
