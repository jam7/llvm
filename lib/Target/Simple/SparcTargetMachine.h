//===-- SparcTargetMachine.h - Define TargetMachine for Sparc ---*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares the Sparc specific subclass of TargetMachine.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_SPARC_SPARCTARGETMACHINE_H
#define LLVM_LIB_TARGET_SPARC_SPARCTARGETMACHINE_H

#include "SparcInstrInfo.h"
#include "SparcSubtarget.h"
#include "llvm/Target/TargetMachine.h"

// Use Simple related stuff instead of Sparc related stuff
#define SparcTargetMachine SimpleTargetMachine

namespace llvm {

class SparcTargetMachine : public LLVMTargetMachine {
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
  SparcSubtarget Subtarget;
  bool is64Bit;
  mutable StringMap<std::unique_ptr<SparcSubtarget>> SubtargetMap;
public:
  SparcTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                     StringRef FS, const TargetOptions &Options,
                     Optional<Reloc::Model> RM, Optional<CodeModel::Model> CM,
                     CodeGenOpt::Level OL, bool JIT, bool is64bit);
  ~SparcTargetMachine() override;

  const SparcSubtarget *getSubtargetImpl() const { return &Subtarget; }
  const SparcSubtarget *getSubtargetImpl(const Function &) const override;

  // Pass Pipeline Configuration
  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
  TargetLoweringObjectFile *getObjFileLowering() const override {
    return TLOF.get();
  }

  bool isMachineVerifierClean() const override {
    return false;
  }
};

/// Sparc 32-bit target machine
///
class Simple32TargetMachine : public SparcTargetMachine {
  virtual void anchor();
public:
  Simple32TargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                       StringRef FS, const TargetOptions &Options,
                       Optional<Reloc::Model> RM, Optional<CodeModel::Model> CM,
                       CodeGenOpt::Level OL, bool JIT);
};

/// Sparc 64-bit target machine
///
class Simple64TargetMachine : public SparcTargetMachine {
  virtual void anchor();
public:
  Simple64TargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                       StringRef FS, const TargetOptions &Options,
                       Optional<Reloc::Model> RM, Optional<CodeModel::Model> CM,
                       CodeGenOpt::Level OL, bool JIT);
};

} // end namespace llvm

#endif
