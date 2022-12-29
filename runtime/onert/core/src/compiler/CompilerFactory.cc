/*
 * Copyright (c) 2022 Samsung Electronics Co., Ltd. All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "compiler/CompilerFactory.h"

#include "compiler/Compiler.h"

namespace onert
{
namespace compiler
{

CompilerFactory &CompilerFactory::get()
{
  static CompilerFactory singleton;
  return singleton;
}

std::unique_ptr<ICompiler>
CompilerFactory::create(const std::shared_ptr<ir::NNPkg> &nnpkg,
                        std::vector<std::unique_ptr<CompilerOptions>> &copts)
{
  // TODO Use more compiler type: single/multi model
  return std::make_unique<Compiler>(nnpkg, copts);
}

} // namespace compiler
} // namespace onert