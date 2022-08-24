assembly = '''
   @123
   D=A              // D = first number
   @R1
   D=D-M;JMP            // D = first number - second number
   @OUTPUT_FIRST
   D;JGT            // if D>0 (first is greater) goto output_first
   @R1
   D=M              // D = second number
   @OUTPUT_D
   0;JMP            // goto output_d
(OUTPUT_FIRST)
   @2137            
   D=M              // D = first number
(OUTPUT_D)
   @R2
   M=D              // M[2] = D (greatest number)
(INFINITE_LOOP)
   @INFINITE_LOOP
   0;JMP            // infinite loop
'''

def assemble(assembly):
   symbol = { 
      'SP': 0, 'LCL': 1, 'ARG': 2, 'THIS': 3, 'THAT': 4, 'R0': 0, 'R1': 1,
      'R2': 2, 'R3': 3, 'R4': 4, 'R5': 5, 'R6': 6, 'R7': 7, 'R8': 8,
      'R9': 9, 'R10': 10, 'R11': 11, 'R12': 12, 'R13': 13, 'R14': 14,
      'R15': 15, 'SCREEN': 16384, 'KBD': 24576
   }
   dest = {
      'null': '000', 'M': '001', 'D': '010', 'MD': '011', 'A': '100', 'AM': '101',
      'AD': '110', 'AMD': '111'
   }
   comp = {
      '0': '0101010', '1': '0111111', '-1': '0111010', 'D': '0001100', 'A': '0110000',
      'M': '1110000', '!D': '0001101', '!A': '0110001', '!M': '1110001',
      '-D': '0001111', '-A': '0110011', '-M': '1110011', 'D+1': '0011111',
      'A+1': '0110111', 'M+1': '1110111', 'D-1': '0001110', 'A-1': '0110010',
      'M-1': '1110010', 'D+A': '0000010', 'D+M': '1000010', 'D-A': '0010011',
      'D-M': '1010011', 'A-D': '0000111', 'M-D': '1000111', 'D&A': '0000000',
      'D&M': '1000000', 'D|A': '0010101', 'D|M': '1010101'
   }
   jump = {
      'null': '000', 'JGT': '001', 'JEQ': '010', 'JGE': '011', 'JLT': '100',
      'JNE': '101', 'JLE': '110', 'JMP': '111'
   }

   asm_code = []
   asm_split = assembly.split("\n")
   asm_inst = []
   index_ram = 16
   for line in asm_split:
      if(line == ''):
         continue
      if('//' in line):
         line = line.split("//")
         if(line[0].strip() != ''):
            asm_inst.append(line[0].strip())
      else:
         asm_inst.append(line.strip())
   #print(asm_inst)

   index = 0;
   for inst in asm_inst:
      if(inst[0] == '('):
         label = inst[1:-1]
         #print(label)
         symbol[label] = index
      else:
         index += 1
   #print(symbol)

   for inst in asm_inst:
      check = inst[0]
      #print('--> ' + inst)
      if(check == '@'):
         if(inst[1:].isdigit()):
            binary = f'{int(inst[1:]):016b}'
            #print(binary)
         else:
            if(inst[1:] in symbol):
               binary = f'{symbol[inst[1:]]:016b}'
            else:
               symbol[inst[1:]] = index_ram
               index_ram += 1
               binary = f'{symbol[inst[1:]]:016b}'
            #print(binary)
         asm_code.append(int(binary,2))
      elif(check == '('):
         pass
      else:
         if('=' in inst and ';' in inst):
            inst = inst.split(";")
            inst[0] = inst[0].split("=")
            #print(c_inst)
            jump_field = jump[inst[1]]
            compute_field = comp[inst[0][1]]
            dest_field = dest[inst[0][0]]
            c_inst = '111' + compute_field + dest_field + jump_field
            #print(c_inst)
            asm_code.append(int(c_inst,2))
         elif('=' in inst):
            inst = inst.split('=')
            jump_field = jump['null']
            compute_field = comp[inst[1]]
            dest_field = dest[inst[0]]
            c_inst = '111' + compute_field + dest_field + jump_field
            asm_code.append(int(c_inst,2))
         else:
            inst = inst.split(';')
            jump_field = jump[inst[1]]
            compute_field = comp[inst[0]]
            dest_field = dest['null']
            c_inst = '111' + compute_field + dest_field + jump_field
            asm_code.append(int(c_inst,2))
   print(asm_code)



assemble(assembly)
#a = '111'
#print(int(a, 2))