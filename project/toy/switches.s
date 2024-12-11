    .text                           ; Start of the code section
    .global switch_update_interrupt_sense
    .global switch_init

; Function: switch_update_interrupt_sense


switch_update_interrupt_sense:


    ; Read P2IN into r12
    mov P2IN, r12            ; r12 = P2IN (P2 input register)
    
    ; P2IES |= (p2val & SWITCHES)  (Set interrupt edge for pressed switches)
    mov r12, r13             ; Copy P2IN value to r13
    and r13, #SWITCHES       ; r13 = P2IN & SWITCHES
    bis P2IES, r13           ; P2IES |= (P2IN & SWITCHES)
    
    ; P2IES &= (p2val | ~SWITCHES)  (Clear interrupt edge for non-pressed switches)
    mov r12, r13             ; Copy P2IN value to r13 again
    not r13                  ; r13 = ~P2IN
    or r13, #SWITCHES       ; r13 = P2IN | ~SWITCHES
    bic P2IES, r13           ; P2IES &= (P2IN | ~SWITCHES)
    
    ; Return P2IN value in r12
    ret                      ; Return from function, P2IN value is already in r12

; Function: switch_init
; This function initializes the switches, enabling pull-up resistors and interrupts.


switch_init:


    ; Enable pull-up resistors for switches
    bis P2REN, #SWITCHES     ; P2REN |= SWITCHES

    ; Enable interrupts for switches
    bis P2IE, #SWITCHES      ; P2IE |= SWITCHES

    ; Set the output to high (enables pull-up resistors)
    bis P2OUT, #SWITCHES     ; P2OUT |= SWITCHES

    ; Set the port direction to input (P2DIR &= ~SWITCHES)
    bic P2DIR, #SWITCHES     ; P2DIR &= ~SWITCHES

    ; Update the interrupt sense (call switch_update_interrupt_sense)
    call #switch_update_interrupt_sense

    ; Return the value from switch_update_interrupt_sense (already in r12)
    
    ret                      ; Return from function
