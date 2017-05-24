# Corewar
 In this project, you will create a virtual “arena” in which programs will fight against one another (the “Champions”). You will also create an assembler to compile those Champions as well as a Champion to show the world that you can create life from coffee.

[ASM Explanation](https://github.com/vomnes/Corewar/blob/master/ASM_/README.md)

## ASM
- The assembler: this is the program that will compile your champions and translate them from the language you will write them in (assembly language) into “Bytecode”. Bytecode is a machine code, which will be directly interpreted by the virtual machine.

![alt text](https://github.com/vomnes/Corewar/blob/master/screenshot/usage_asm.png "Usage asm")

### file.s (Pseudo-ASM) to file.cor (Binary file)
![alt text](https://github.com/vomnes/Corewar/blob/master/screenshot/asm_input.png "Assembler input") → ![alt text](https://github.com/vomnes/Corewar/blob/master/screenshot/hexdump_cor.png "Binary created")

### Details binary compilation
![alt text](https://github.com/vomnes/Corewar/blob/master/screenshot/asm_details.png "Details binary compilation")

## VM
- The virtual machine: It’s the “arena” in which your champions will be executed. It offers various functions, all of which will be useful for the battle of the champions. Obviously, the virtual machine should allow for numerous simultaneous processes; we are asking you for a gladiator fight, not a one-man show simulator.

![alt text](https://github.com/vomnes/Corewar/blob/master/screenshot/usage_vm.png "Usage vm")

### Corewar Visual with ncurses
![alt text](https://github.com/vomnes/Corewar/blob/master/screenshot/corewar_visual.png "Corewar visual")

### Corewar Visual end
![alt text](https://github.com/vomnes/Corewar/blob/master/screenshot/corewar_finish.png "Corewar finish")

### Corewar Verbose mode
![alt text](https://github.com/vomnes/Corewar/blob/master/screenshot/corewar_verbose_mode.png "Corewar verbose")

### Corewar Dump mode
![alt text](https://github.com/vomnes/Corewar/blob/master/screenshot/corewar_dump.png "Corewar dump")
