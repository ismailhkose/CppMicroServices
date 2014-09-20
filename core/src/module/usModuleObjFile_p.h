/*=============================================================================

  Library: CppMicroServices

  Copyright (c) German Cancer Research Center,
    Division of Medical and Biological Informatics

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=============================================================================*/

#ifndef USMODULEOBJFILE_P_H
#define USMODULEOBJFILE_P_H

#include "usGlobalConfig.h"

#include <string>
#include <vector>

US_BEGIN_NAMESPACE

struct InvalidObjFileException : public std::exception
{
  ~InvalidObjFileException() throw() {}
  InvalidObjFileException(const std::string& what, int errorNumber = 0);

  virtual const char* what() const throw();

  std::string m_What;
};

class ModuleObjFile
{
public:

  virtual ~ModuleObjFile() {}

  virtual std::vector<std::string> GetDependencies() const = 0;
  virtual std::string GetLibName() const = 0;
  virtual std::string GetModuleName() const = 0;

protected:

  static bool ExtractModuleName(const std::string& name, std::string& out);

};

US_END_NAMESPACE

#endif // USMODULEOBJFILE_P_H
