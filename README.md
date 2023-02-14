# Philosophers

@42-Born2Code

## About

This project is a version of the [Dining Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem).

The goal of this project was to learn to avoid deadlock and race conditions when creating multithreaded applications.

## Common Instructions

- Must be written in C
- Should not quit unexpectedly
- No leaks will be tolerated.
- Makefile width flags -Wall -Wextra -Werror
- Makefile: all clean fclean re

## Overview

- One or more philosophers sit at a round table.
There is a large bowl of spaghetti in the middle of the table.
- The philosophers alternatively eat, think, or sleep.
While they are eating, they are not thinking nor sleeping;
while thinking, they are not eating nor sleeping;
and, of course, while sleeping, they are not eating nor thinking.
- There are also forks on the table. There are as many forks as philosophers.
- Because serving and eating spaghetti with only one fork is very inconvenient, a
philosopher takes their right and their left forks to eat, one in each hand.
- When a philosopher has finished eating, they put their forks back on the table and
start sleeping. Once awake, they start thinking again. The simulation stops when
a philosopher dies of starvation.
- Every philosopher needs to eat and should never starve.
- Philosophers don’t speak with each other.
- Philosophers don’t know if another philosopher is about to die.
- No need to say that philosophers should avoid dying!

## Global rules

- Global variables are forbidden!
- Program should take the following arguments:
`number_of_philosophers` `time_to_die` `time_to_eat` `time_to_sleep`
`[number_of_times_each_philosopher_must_eat]`
  - `number_of_philosophers`: The number of philosophers and also the number of forks.
  - `time_to_die` (in milliseconds): If a philosopher didn’t start eating `time_to_die` milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
  - `time_to_eat` (in milliseconds): The time it takes for a philosopher to eat. During that time, they will need to hold two forks.
  - `time_to_sleep` (in milliseconds): The time a philosopher will spend sleeping.
  - `number_of_times_each_philosopher_must_eat` (optional argument): If all philosophers have eaten at least `number_of_times_each_philosopher_must_eat` times, the simulation stops. If not specified, the simulation stops when a philosopher dies.
- Each philosopher has a number ranging from 1 to `number_of_philosophers`.
- Philosopher number 1 sits next to philosopher `number number_of_philosophers`. Any other philosopher number N sits between philosopher number N - 1 and philosopher number N + 1.
- Any state change of a philosopher must be formatted as follows:
  - `timestamp_in_ms` X has taken a fork
  - `timestamp_in_ms` X is eating
  - `timestamp_in_ms` X is sleeping
  - `timestamp_in_ms` X is thinking
  - `timestamp_in_ms` X died
  
`timestamp_in_ms` is the current timestamp in milliseconds and X with the philosopher number.

## Installation && Usage

### Requirements
The only Requirements are:
- GNU make
- CC

### Building the program
1. Download/Clone this repo

```bash
  git clone https://github.com/suhovhan/philo.git
```
2. `cd` into the root directory and run `make`
```bash
cd philo
make
```
### Running the program
After building the source, run `./philo number_of_philosophers time_to_die time_to_eat time_to_sleep` from the project root.

## Usage/Examples

```bash
./philo 5 800 200 200
./philo 5 800 200 200 7
./philo 4 310 200 100
```
This program depends on the capabilities of your computer.                                       
Don't check out over 200 `number_of_philosophers`.                                           
Don't check under 60 `time_to_die` `time_to_eat` `time_to_sleep`
