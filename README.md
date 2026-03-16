*This project has been created as part of the 42 curriculum by asauvage*

## Description

The Philosophers project is a simulation of the classic “Dining Philosophers” problem, a fundamental problem in computer science used to illustrate the challenges of thread synchronization and shared resource management.

The goal is to design a program in which several philosophers are seated around a round table with a bowl of food in the center. Each philosopher has a fork to their left and one to their right. To eat, a philosopher must hold two forks simultaneously. The challenge lies in managing threads and mutexes to avoid deadlocks and data races while preventing the philosophers from starving to death.

## Instructions

### Compilation

The project includes a `Makefile` with standard rules.

- To compile the Mandatory executable:
``` bash
	make
```

- To remove object files:
```bash
  make clean
```

- To remove object files and compiled binaries:
```bash
  make fclean
```

-To remake all:
```bash
  make re
```

### Execution

The program use the following arguments

```bash
./philo nb_philo time_to_die time_to_eat time_to_sleep [nb_times_must_eat]
```

## Resources

-[visualizer](https://nafuka11.github.io/philosophers-visualizer/)

-https://www.codequoi.com/threads-mutex-et-programmation-concurrente-en-c/

### IA Usage

-AI was used primarily to help me write this Readme and also to deepen my understanding of mutexes.