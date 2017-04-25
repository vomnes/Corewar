# ASM
Program that convert .s to .cor.

### OpCode

| Op Name | Opcode  | Dir | Description |
|:-------:|:-------:|:---:|:----------- |
| live | 0x01 | T_DIR | alive (1) |
| ld | 0x02 | T_DIR \| T_IND, T_REG | load (2) |
| st | 0x03 | T_REG, T_IND \| T_REG | store (3) |
| add | 0x04 | T_REG, T_REG, T_REG | addition (4) |
| sub | 0x05 | T_REG, T_REG, T_REG | substraction (5) |
| and | 0x06 | T_REG \| T_DIR \| T_IND, T_REG \| T_IND \| T_DIR, T_REG | et (and  r1, r2, r3   r1&r2 -> r3 (6) |
| or | 0x07 | T_REG \| T_IND \| T_DIR, T_REG \| T_IND \| T_DIR, T_REG | ou  (or   r1, r2, r3   r1 \| r2 -> r3 (7) |
| xor | 0x08 | T_REG \| T_IND \| T_DIR, T_REG \| T_IND \| T_DIR, T_REG | ou (xor  r1, r2, r3   r1^r2 -> r3 (8) |
| zjmp | 0x09 | T_DIR | jump if zero (9) |
| ldi | 0x0a | T_REG \| T_DIR \| T_IND, T_DIR \| T_REG, T_REG | load index (10) |
| sti | 0x0b | T_REG, T_REG \| T_DIR \| T_IND, T_DIR \| T_REG | store index (11) |
| fork | 0x0c | T_DIR | fork (12) |
| lld | 0x0d | T_DIR \| T_IND, T_REG | long load (13) |
| lldi | 0x0e | T_REG \| T_DIR \| T_IND, T_DIR \| T_REG, T_REG | long load index (14) |
| lfork | 0x0f | T_DIR | long fork (15) |
| aff | 0x10 | T_REG | aff (16) |

(1) - Allows a process to stay alive.

(2) - Take a random argument and a registry. Load the value of the first argument in the registry.

(3) - Take a registry and a registry or an indirect and store the value of the registry toward a second argument.

(4) - Take three registries, add the first two, and place the result in the third, right before modifying the carry.

(5) - Same as add, uses a substraction.

(6) - Apply an & (bit-to-bit AND) over the first two arguments and store the result in a registry, which is the third argument.

(7) - This operation is an bit-to-bit OR, in the same spirit and principle of and.

(8) - Acts like and with an exclusive OR.

(9) - It will take an index and jump to this address if the carry is 1.

(10) - It will use 2 indexes and 1 registry, adding the first two, treating that like an address, reading a value of a registry’s size and putting it on the third.

(11) - Take a registry, and two indexes (potentially registries) add the two indexes, and use this result as an address where the value of the first parameter will be copied.

(12) - Create a new process that will inherit the different states of its father, except its PC, which will be put at (PC + (1st parameter % IDX_MOD)).

(13) - It the same as ld, but without % IDX_MOD.

(14) - Same as ldi, but does not apply any modulo to the addresses.

(15) - To be able to fork abut straw from a distance of 15 meters, exactly like with its opcode. Same as a fork without modulo in the address.

(16) - There is an argument’s coding byte, even if it’s a bit silly because there is only 1 argument that is a registry, which is a registry, and its content is interpreted by the character’s ASCII value to display on the standard output. The code is modulo 256.

### Arguments
| Name | Symbole | Binary Code | Nb bits |
|:----:|:-------:|:-----------:|:--------:|
|T_REG | r       | 01          | 1 bit  |
|T_IND |         | 11          | 2 bits |
|T_DIR | %       | 10          | 4 bits |

## Example Code Arguments
```
r2 23 %34

>> r2  --> 01 --> 1 bit
>> 23  --> 11 --> 2 bits
>> %34 --> 10 --> 4 bits

Binary value --> 0b01111000 --> 0x78
```
