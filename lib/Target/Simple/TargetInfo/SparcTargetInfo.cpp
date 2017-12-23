//===-- SparcTargetInfo.cpp - Sparc Target Implementation -----------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "Sparc.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/TargetRegistry.h"
using namespace llvm;

Target &llvm::getTheSimpleTarget() {
  static Target TheSimpleTarget;
  return TheSimpleTarget;
}
Target &llvm::getTheSimple64Target() {
  static Target TheSimple64Target;
  return TheSimple64Target;
}

extern "C" void LLVMInitializeSimpleTargetInfo() {
  RegisterTarget<Triple::simple, /*HasJIT=*/true> X(
      getTheSimpleTarget(), "simple", "Simple", "Simple");
  RegisterTarget<Triple::simple64, /*HasJIT=*/true> Y(
      getTheSimple64Target(), "simple64", "Simple 64", "Simple");
}
