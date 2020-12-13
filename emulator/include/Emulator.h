#ifndef EMULATOR_H
#define EMULATOR_H

#include <map>
#include <memory>

#include "Instruction.h"
#include "Memory.h"
#include "RegisterFile.h"

#define STACK_START   0x10000

class Emulator {

public:
    Emulator(uint32_t instMemSize, uint32_t dataMemSize);
    void init();
    void load_instructions(const uint8_t *insn, size_t size);
    void set_pc(uint32_t pc);
    void execute();
    void execute(uint32_t opcode);

    RegisterFile regFile;
    Memory instMemory;
    Memory dataMemory;

private:
    uint32_t pc;
    std::map<uint32_t, std::unique_ptr<Instruction>> op2InstMap;
};

#endif