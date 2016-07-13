/* This is the source code of Brain Programming Language.
 * It is licensed under GNU GPL v. 3 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Luiz Peres, 2016.
 */

#ifndef BOOTSTRAP_H
#define BOOTSTRAP_H

#include <llvm/ExecutionEngine/SectionMemoryManager.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/ExecutionEngine/MCJIT.h>

#include <llvm/Support/ManagedStatic.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Support/SourceMgr.h>

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Value.h>
#include <llvm/IRReader/IRReader.h>

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <streambuf>
#include <memory>

#include "../parser/Parser.h"
#include "ArgsHandler.h"
#include "ArgsOptions.h"

/**
 * @brief Class that starts Brain, it has all the needed components to
 * initialize the Brain interpreter.
 */
class Bootstrap
{
private:
    /// The name of the main module
    std::string MODULE_NAME;
    /// The path to the default lib in Brain.
    std::string IO_LIB;

    llvm::ExecutionEngine *execution_engine;
    llvm::EngineBuilder *engine_builder;
public:
    Bootstrap();
    ~Bootstrap();

    /**
     * @brief Initializes Brain by passing the arguments to be handled and
     * parsing the source file.
     * @param argc The integer representing how many arguments were passed.
     * @param argv The array of characters representing the arguments passed.
     */
    bool init(int argc, char** argv);
};

#endif // BOOTSTRAP_H
