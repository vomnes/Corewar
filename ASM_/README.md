# ASM
Program that convert .s to .cor.

### OpCode

| Op Name | Opcode  | Dir | Description | Name |
|:-------:|:-------:|:---:|:----------- |:----:|
| live | 0x01 | T_DIR | Allows a process to stay alive. | alive |
| ld | 0x02 | T_DIR \| T_IND, T_REG | Take a random argument and a registry. Load the value of the first argument in the registry. | load |
| st | 0x03 | T_REG, T_IND \| T_REG | Take a registry and a registry or an indirect and store the value of the registry toward a second argument. | store |
| add | 0x04 | T_REG, T_REG, T_REG | Take three registries, add the first two, and place the result in the third, right before modifying the carry. | addition |
| sub | 0x05 | T_REG, T_REG, T_REG | Same as add, uses a substraction. | substraction |
| and | 0x06 | T_REG \| T_DIR \| T_IND, T_REG \| T_IND \| T_DIR, T_REG | Apply an & (bit-to-bit AND) over the first two arguments and store the result in a registry, which is the third argument. | et (and  r1, r2, r3   r1&r2 -> r3 |
| or | 0x07 | T_REG \| T_IND \| T_DIR, T_REG \| T_IND \| T_DIR, T_REG | This operation is an bit-to-bit OR, in the same spirit and principle of and. | ou  (or   r1, r2, r3   r1 | r2 -> r3 |
| xor | 0x08 | T_REG \| T_IND \| T_DIR, T_REG \| T_IND \| T_DIR, T_REG | Acts like and with an exclusive OR. | ou (xor  r1, r2, r3   r1^r2 -> r3 |
| zjmp | 0x09 | T_DIR | It will take an index and jump to this address if the carry is 1. | jump if zero |
| ldi | 0x0a | T_REG \| T_DIR \| T_IND, T_DIR \| T_REG, T_REG | It will use 2 indexes and 1 registry, adding the first two, treating that like an address, reading a value of a registry’s size and putting it on the third. | load index |
| sti | 0x0b | T_REG, T_REG \| T_DIR \| T_IND, T_DIR \| T_REG | Take a registry, and two indexes (potentially registries) add the two indexes, and use this result as an address where the value of the first parameter will be copied. | store index |
| fork | 0x0c | T_DIR | Create a new process that will inherit the different states of its father, except its PC, which will be put at (PC + (1st parameter % IDX_MOD)). | fork |
| lld | 0x0d | T_DIR \| T_IND, T_REG | It the same as ld, but without % IDX_MOD. | long load |
| lldi | 0x0e | T_REG \| T_DIR \| T_IND, T_DIR \| T_REG, T_REG | Same as ldi, but does not apply any modulo to the addresses. | long load index |
| lfork | 0x0f | T_DIR | To be able to fork abut straw from a distance of 15 meters, exactly like with its opcode. Same as a fork without modulo in the address. | long fork |
| aff | 0x10 | T_REG | There is an argument’s coding byte, even if it’s a bit silly because there is only 1 argument that is a registry, which is a registry, and its content is interpreted by the character’s ASCII value to display on the standard output. The code is modulo 256. | aff |

### Arguments
| Name | Symbole | Binary Code | Nb octet |
|:----:|:-------:|:-----------:|:--------:|
|T_REG | r       | 01          | 1 octet  |
|T_IND |         | 11          | 2 octets |
|T_DIR | %       | 10          | 4 octets |

## Example Code Arguments
```
r2 23 %34

>> r2  --> 01 --> 1 octet
>> 23  --> 11 --> 2 octets
>> %34 --> 10 --> 4 octets

Binary value --> 0b01111000 --> 0x78
```
