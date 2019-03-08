/**
 * Copyright (c) 2017-present, Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef GLOW_BACKENDS_CPU_CPUFUNCTION_H
#define GLOW_BACKENDS_CPU_CPUFUNCTION_H

#include "glow/LLVMIRCodeGen/GlowJIT.h"
#include "glow/LLVMIRCodeGen/LLVMCompiledFunction.h"

#include "glow/Backends/Backend.h"
#include "glow/Backends/BackendUtils.h"
#include "glow/Backends/CompiledFunction.h"

namespace glow {
/// A Glow IR function compiled for the CPU using LLVM.
class CPUFunction final : public LLVMCompiledFunction {
public:
  CPUFunction(std::unique_ptr<llvm::orc::GlowJIT> JIT,
              const runtime::RuntimeBundle &runtimeBundle);

  /// \name CompiledFunction interface
  ///@{
  ~CPUFunction() override = default;
  void execute(ExecutionContext *context) override;

  /// \returns the Kind of Backend used to compile this function.
  virtual BackendKind getCompileBackendKind() const override {
    return BackendKind::CPU;
  }
  ///@}
  //
};
} // end namespace glow

#endif // GLOW_BACKENDS_CPU_CPUFUNCTION_H
