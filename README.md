<h1 align="center">
	🧩 Pipex
</h1>

<p align="center">
	<b><i>Shell pipes reproduction project </i></b><br>
</p>

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)

## Introduction

The primary objective of this project is to implement pipe functionality, and exploring Inter-Process Communication (IPC) using the fork() and execve() functions. The goal is to gain a better understanding of how processes can communicate and share data in a Unix-like environment.

## Features

- OS : 
This project is designed to function on both Linux and macOS systems.

- Here_Doc Implementation : 
the bonus part of this project.
In my implementation i would not read the hole input and save it aside. Instead, the project opens all the necessary pipes and reads input line by line, transferring it to the next pipe.  To ensure continuous input reading, we adopt a strategy of opening the entire pipe, reading line by line, and periodically clearing the output of the pipe between each process. This approach mitigates potential bottlenecks associated with pipe buffer size limitations (since in modern operating systems, the buffer size of a pipe is typically capped at 64 KB). 
- leak tool: at your disposal a leak tool inside makefile : use ```bash make leak``` to run. 
## Installation

In order to run pipex, first clone the project using 

```bash
  git clone https://github.com/your-username/pipex.git
```
  than cd to the repository and run make command to build the Pipex program:
  ```bash
  make 
  ```
  for the bonuses use 

  ```bash
  make bonus
  ```


## Usage

the input should implement the same as the original pipe command ```bash $> < file1 cmd1 | cmd2 > file2```  the correct usage to run pipex is:
```bash ./pipex (<infile> | here_doc <LIMITER>) <cmd1> ... <cmdn> <outfile> ```
example :

```shell
./pipex "in_file" "cat -e" "grep hello" "out_file"
```

for the bonus the use is ```bash $> ./pipex here_doc <limiter> <cmd1> <cmd2> <cmd3> ... <outfile>```

- The here_doc functionality in this project is the equivalent of STDIN (<<).
- After running the program, you should notice an 'outfile' created with the content of the process after the pipe operations.