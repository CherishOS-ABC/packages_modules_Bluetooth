/*
 * Copyright 2019 The Android Open Source Project
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

#pragma once

#include "fields/scalar_field.h"
#include "parse_location.h"

class CustomFieldFixedSize : public ScalarField {
 public:
  CustomFieldFixedSize(std::string name, std::string type_name, int size, ParseLocation loc);

  static const std::string kFieldType;

  virtual const std::string& GetFieldType() const override;

  virtual std::string GetDataType() const override;

  virtual int GenBounds(std::ostream& s, Size start_offset, Size end_offset) const override;

  virtual void GenExtractor(std::ostream& s, int num_leading_bits, bool for_struct) const override;

  virtual bool HasParameterValidator() const override;

  virtual void GenParameterValidator(std::ostream&) const override;

  virtual void GenValidator(std::ostream&) const override;

  std::string type_name_;
};
