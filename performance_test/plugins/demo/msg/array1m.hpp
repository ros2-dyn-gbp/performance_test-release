// Copyright 2021-2024 Apex.AI, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef PERFORMANCE_TEST__PLUGINS__DEMO__MSG__ARRAY1M_HPP_
#define PERFORMANCE_TEST__PLUGINS__DEMO__MSG__ARRAY1M_HPP_

#include <cstdint>

namespace performance_test
{
namespace msg
{
struct Array1m
{
  std::int64_t time;
  std::uint64_t id;
  std::uint8_t data[1048576];
};
}  // namespace msg
}  // namespace performance_test

#endif  // PERFORMANCE_TEST__PLUGINS__DEMO__MSG__ARRAY1M_HPP_