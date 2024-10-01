# Philosophers

This repository contains the "Philosophers" project, a classic problem in concurrency and synchronization. The project is part of the 42 curriculum and aims to teach students about process synchronization, mutexes, threads, and avoiding deadlocks.

## Table of Contents

- [Overview](#overview)
- [Rules of the Problem](#rules-of-the-problem)
- [Concepts Covered](#concepts-covered)
- [Installation](#installation)
- [Usage](#usage)
- [How It Works](#how-it-works)
- [Contributing](#contributing)
- [License](#license)

## Overview

In the "Philosophers" project, you are tasked with simulating a problem involving philosophers sitting at a table, alternating between eating, thinking, and sleeping. The problem's challenge lies in synchronizing the philosophers' actions such that no philosopher starves, and no deadlock occurs. The solution must be efficient and thread-safe.

The project is typically divided into two parts:
1. **Philosophers with threads**.
2. **Philosophers with processes (bonus)**.

The goal is to explore the difference between using threads and processes, along with the synchronization mechanisms for each.

## Rules of the Problem

- Five philosophers sit at a table and do only three things: **eat**, **think**, and **sleep**.
- Each philosopher has a fork on their left and right. To eat, a philosopher must pick up both forks.
- Philosophers cannot speak to each other.
- The program needs to prevent **deadlock** (where no philosopher can eat) and **starvation** (where a philosopher cannot eat indefinitely).
- The simulation ends when a philosopher dies from hunger or all philosophers have eaten a certain number of times (if provided as input).

## Concepts Covered

- **Multithreading**: Using threads to simulate philosophers' simultaneous actions.
- **Mutexes**: For controlling access to shared resources (forks).
- **Race Conditions**: Avoiding race conditions to prevent data corruption.
- **Deadlock Avoidance**: Ensuring that philosophers can always access the necessary resources to eat.
- **Concurrency**: Managing philosophers' concurrent actions with proper synchronization.

## Installation

1. Clone this repository to your local machine:

   ```bash
   git clone https://github.com/aitomarabdeljalil/Philosophers.git
   cd Philosophers
   ```

2. Build the program using `make`:

   ```bash
   make
   ```

This will generate the `philo` executable for the main part of the project.

For the bonus part (processes version), you can run:

```bash
make bonus
```

## Usage

To run the program, use the following syntax:

```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

### Arguments

- `number_of_philosophers`: Number of philosophers and forks.
- `time_to_die`: Time (in milliseconds) a philosopher can live without eating.
- `time_to_eat`: Time (in milliseconds) it takes a philosopher to eat.
- `time_to_sleep`: Time (in milliseconds) a philosopher spends sleeping.
- `number_of_times_each_philosopher_must_eat` (optional): If provided, the simulation will stop after all philosophers have eaten at least this number of times.

### Example

```bash
./philo 5 800 200 200
```

This will simulate 5 philosophers, each needing to eat within 800ms, taking 200ms to eat and 200ms to sleep.

### Bonus Version

For the bonus version, run:

```bash
./philo_bonus <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

## How It Works

Each philosopher is represented by a thread (or process in the bonus version), and their actions (eating, sleeping, thinking) are controlled by the program’s logic. The forks are represented by mutexes (or semaphores in the bonus version), ensuring only one philosopher can hold each fork at a time.

### Key Features:
- **Synchronization**: Ensuring that no two philosophers pick up the same fork at the same time.
- **Thread Management**: Creating and managing threads that run in parallel.
- **State Monitoring**: Continuously checking whether a philosopher has died or if all philosophers have eaten the required number of times.

## Contributing

If you would like to contribute to this project, feel free to fork the repository and submit a pull request. Contributions, suggestions, and feedback are always welcome!

### How to Contribute

1. Fork the repository.
2. Create a new branch (`git checkout -b feature/new-feature`).
3. Commit your changes (`git commit -m 'Add some new feature'`).
4. Push to the branch (`git push origin feature/new-feature`).
5. Open a pull request.

## License

This project is licensed under the MIT License. Please look at the [LICENSE](LICENSE) file for details.

