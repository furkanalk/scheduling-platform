[![Build Status][badge-action-image]][badge-action-url] ![C++23][badge-cpp] ![Go][badge-go] ![CMake][badge-cmake] ![License][badge-license]

**Scheduling Platform** is a general-purpose system for modeling, solving, and analyzing scheduling problems with complex operational constraints.

Instead of hard-coding a scheduler for one domain, it represents planning problems through reusable concepts such as **resources, activities, time, assignments, constraints, and objectives**. Domain-specific rules are expressed on top of that common model.

<br>

<p align="center"> <img src="https://i.imgur.com/MTpXgQ2.png" alt="Scheduling Platform overview" width="850"/>

## Overview

Real-world scheduling combines resource capabilities, availability, temporal requirements, dependencies, operational policy, and competing business objectives.

The platform provides a common scheduling foundation that can be adapted to different planning domains without rebuilding the optimization engine around domain-specific classes.

Typical problem families include:

- academic timetabling,
- workforce and shift planning,
- production scheduling,
- aircraft, gate, and crew assignment,
- maintenance and resource allocation.

## Features

- **Configurable scheduling models** — represent domain-specific resources, activities, attributes, and relationships on a generic core.
- **Constraint-based planning** — distinguish mandatory requirements from optimization preferences.
- **Declarative rule model** — keep scheduling policy structured, inspectable, and solver-independent.
- **Multiple solving strategies** — allow different optimization backends to operate on the same scheduling model.
- **Explainable diagnostics** — preserve the relationship between results and the rules that produced them.
- **Scenario analysis** — compare alternative decisions without losing the original planning context.
- **Incremental replanning** — repair an existing schedule when conditions change instead of starting from zero.

## Scheduling Model

The platform reasons about a small set of generic scheduling primitives.
Domain concepts are mapped onto these primitives rather than hard-coded into the engine.

```text
Academic                    Aviation                    Manufacturing

Teacher  -> Resource        Aircraft -> Resource        Machine       -> Resource
Room     -> Resource        Gate     -> Resource        ProductionJob -> Activity
Course   -> Activity        Flight   -> Activity
```

At a high level, a feasible schedule satisfies the hard constraints:

$$
C_h(x) = \mathrm{true}
$$

Among feasible schedules, quality can be optimized through weighted objective components:

$$
\min_x \sum_{i=1}^{n} w_i P_i(x)
$$

where \(x\) is the schedule, \(C_h\) represents hard constraints, and \(P_i(x)\) represents individual penalty or objective components.

## Rule Modeling

Scheduling policy is represented as structured, declarative rules rather than arbitrary solver code.

```text
Assigned Resource.capacity
    >=
Activity.requiredCapacity
```

```text
A resource cannot be assigned to overlapping activities.
```

```text
An activity must be scheduled inside the assigned resource's availability.
```

The target product experience is a high-level visual rule builder that converts domain policy into a validated scheduling representation.

## Constraint Intelligence

Producing a schedule is only part of a practical scheduling system.

When the model is infeasible, the platform is designed to retain enough structured evidence to answer questions such as:

> Which rules are blocking the schedule?  
> Which resources and activities are involved?  
> What is the smallest practical change that restores feasibility?  
> What operational impact would that change create?

Example diagnostic output:

```text
No feasible schedule

Blocking constraints
  R-14  Resource unavailable until 17:40
  R-27  Activity must start before 18:00
  R-31  Minimum turnaround is 45 minutes

Recovery candidates
  -> Delay the activity
  -> Assign another compatible resource
  -> Evaluate a policy relaxation
```

This provides the foundation for conflict analysis, counterfactual scenarios, relaxation guidance, constraint impact analysis, and explainable replanning.

## Reference Domain

**Academic Scheduling** is the first reference implementation used to validate the generic model against practical constraints such as instructor availability, room capacity, course requirements, timetable conflicts, repeated sessions, and scheduling preferences.

Additional domains are used to verify that the platform abstractions remain genuinely reusable rather than evolving into a domain-specific scheduler.

## Getting Started

The current foundation requires a **C++23-compatible compiler** and **CMake 3.24+**.

```powershell
git clone https://github.com/furkanalk/scheduling-platform.git
cd scheduling-platform

cmake --preset windows-x64-debug
cmake --build --preset windows-x64-debug
ctest --preset windows-x64-debug
```

## License

Copyright © 2026 Furkan Alk. All rights reserved.

Scheduling Platform is proprietary software. See [`LICENSE`](LICENSE) for licensing terms.

[platform-diagram]: https://i.imgur.com/MTpXgQ2.png
[badge-action-url]: https://github.com/furkanalk/scheduling-platform/actions
[badge-action-image]: https://img.shields.io/github/actions/workflow/status/furkanalk/scheduling-platform/build.yml?style=flat-square&logo=github&label=Build
[badge-cpp]: https://img.shields.io/badge/C%2B%2B-23-00599C?style=flat-square&logo=cplusplus&logoColor=white
[badge-go]: https://img.shields.io/badge/Go-Control%20Plane-00ADD8?style=flat-square&logo=go&logoColor=white
[badge-cmake]: https://img.shields.io/badge/CMake-3.24%2B-064F8C?style=flat-square&logo=cmake&logoColor=white
[badge-license]: https://img.shields.io/badge/License-Proprietary-c0392b?style=flat-square