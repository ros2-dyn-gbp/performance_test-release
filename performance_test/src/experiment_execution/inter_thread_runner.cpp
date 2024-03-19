// Copyright 2024 Apex.AI, Inc.
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

#include "performance_test/experiment_execution/inter_thread_runner.hpp"

#include "performance_test/experiment_configuration/experiment_configuration.hpp"
#include "performance_test/experiment_execution/data_entity_runner.hpp"

namespace performance_test
{
InterThreadRunner::InterThreadRunner(const ExperimentConfiguration & ec)
: DataEntityRunner(ec)
{}

InterThreadRunner::~InterThreadRunner()
{
  for (auto & thread : m_thread_pool) {
    thread.join();
  }
}

void InterThreadRunner::run_pubs_and_subs()
{
  m_thread_pool.reserve(m_pubs.size() + m_subs.size());

  for (auto & sub : m_subs) {
    m_thread_pool.emplace_back(
      [&sub, this]() {
        while (m_running) {
          sub->run();
        }
      });
  }

  for (auto & pub : m_pubs) {
    m_thread_pool.emplace_back(
      [&pub, this]() {
        while (m_running) {
          pub->run();
        }
      });
  }
}

}  // namespace performance_test