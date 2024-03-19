// Copyright 2017-2024 Apex.AI, Inc.
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

#ifndef PERFORMANCE_TEST__EXPERIMENT_EXECUTION__ROUND_TRIP_RELAY_RUNNER_HPP_
#define PERFORMANCE_TEST__EXPERIMENT_EXECUTION__ROUND_TRIP_RELAY_RUNNER_HPP_

#include <memory>
#include <thread>

#include "performance_test/execution_tasks/round_trip_relay_task.hpp"
#include "performance_test/experiment_configuration/experiment_configuration.hpp"
#include "performance_test/experiment_execution/runner.hpp"

namespace performance_test
{
class RoundTripRelayRunner : public Runner
{
public:
  explicit RoundTripRelayRunner(const ExperimentConfiguration & ec);

  virtual ~RoundTripRelayRunner();

protected:
  virtual void run_pubs_and_subs();

private:
  RoundTripRelayTask m_relay;
  std::unique_ptr<std::thread> m_thread;
};

}  // namespace performance_test

#endif  // PERFORMANCE_TEST__EXPERIMENT_EXECUTION__ROUND_TRIP_RELAY_RUNNER_HPP_