### Using GLPK and MathProg with CPLEX

The implementation of mathematical model for optimization problem
is a requirement to final class project. You should express the model
using the MathProg language. Formulation must be developed in separeted
to input data, thus the same model should be able to be used with 
several instances of the problem. 

This directory includes the files [aero.mod](aero.mod) and 
[aero.dat](aero.dat), refering to a problem presented in laboratory
practice March, 26 - 2019. You can use GLPK to compile a LP file,
which can be read using CPLEX interative shell. To do so, run the 
command ``glpsol`` command as follows.

```bash
$ glpsol -m aero.dat -d aero.dat --check --wlp aero.lp
```

In this command, ``-m`` specifies which file contains the formulation,
``-d`` specified the input data, ``--check`` tells to GLPK to generate the
complete model of the problem but not solving it. Finally ``--wlp`` indicates
that GLPK should write a LP file with the complete formulation of the problem.
If the above command runs sucessfully, the file aero.lp should something like
this:

```
\* Problem: aero *\

Maximize
 lucro: + 600 x(Pel,Poa,A) + 440 x(Pel,Poa,B) + 200 x(Pel,Poa,C)
 + 720 x(Pel,Tor,A) + 560 x(Pel,Tor,B) + 280 x(Pel,Tor,C)
 + 320 x(Poa,Tor,A) + 260 x(Poa,Tor,B) + 160 x(Poa,Tor,C)

Subject To
 limReservas(Pel,Poa,A): + x(Pel,Poa,A) <= 4
 limReservas(Pel,Poa,B): + x(Pel,Poa,B) <= 8
 limReservas(Pel,Poa,C): + x(Pel,Poa,C) <= 22
 limReservas(Pel,Tor,A): + x(Pel,Tor,A) <= 3
 limReservas(Pel,Tor,B): + x(Pel,Tor,B) <= 10
 limReservas(Pel,Tor,C): + x(Pel,Tor,C) <= 18
 limReservas(Poa,Tor,A): + x(Poa,Tor,A) <= 8
 limReservas(Poa,Tor,B): + x(Poa,Tor,B) <= 13
 limReservas(Poa,Tor,C): + x(Poa,Tor,C) <= 20
 limPassageirosPel: + x(Pel,Poa,A) + x(Pel,Poa,B) + x(Pel,Poa,C)
 + x(Pel,Tor,A) + x(Pel,Tor,B) + x(Pel,Tor,C) <= 30
 limPassageirosPoa: + x(Pel,Tor,A) + x(Pel,Tor,B) + x(Pel,Tor,C)
 + x(Poa,Tor,A) + x(Poa,Tor,B) + x(Poa,Tor,C) <= 30

End
```

To solve the problem with CPLEX, use the following command lines.

```
$ cplex

Welcome to IBM(R) ILOG(R) CPLEX(R) Interactive Optimizer 12.9.0.0
  with Simplex, Mixed Integer & Barrier Optimizers
5725-A06 5725-A29 5724-Y48 5724-Y49 5724-Y54 5724-Y55 5655-Y21
Copyright IBM Corp. 1988, 2019.  All Rights Reserved.

Type 'help' for a list of available commands.
Type 'help' followed by a command name for more
information on commands.

CPLEX>
```

This drops you in CPLEX interative solver. Proceed reading the problem from
file aero.lp, calling the ``read`` command. Then, solve the problem using 
``opt``.

```
CPLEX> read aero.lp
Problem 'aero.lp' read.
Read time = 0.01 sec. (0.00 ticks)
CPLEX> opt
Tried aggregator 1 time.
LP Presolve eliminated 9 rows and 0 columns.
Reduced LP has 2 rows, 9 columns, and 12 nonzeros.
Presolve time = 0.00 sec. (0.01 ticks)

Iteration log . . .
Iteration:     1   Dual objective     =         23160.000000

Dual simplex - Optimal:  Objective =  1.9580000000e+04
Solution time =    0.08 sec.  Iterations = 4 (0)
Deterministic time = 0.01 ticks  (0.16 ticks/sec)

CPLEX>
```

Once the problem is solved, you can query the status of objective function
value using ``disp sol obj`` command. Similarly, you can query the values
of decision variables using the command ``disp sol var *``.

```
CPLEX> disp sol obj
Dual simplex - Optimal:  Objective =  1.9580000000e+04
CPLEX> disp sol var *
Variable Name           Solution Value
x(Pel,Poa,A)                  4.000000
x(Pel,Poa,B)                  8.000000
x(Pel,Poa,C)                  5.000000
x(Pel,Tor,A)                  3.000000
x(Pel,Tor,B)                 10.000000
x(Poa,Tor,A)                  8.000000
x(Poa,Tor,B)                  9.000000
All other variables matching '\*' are 0.
CPLEX> quit
$
```

To save a copy of entire solution of the problem, use the command ``write ``. 
This command receives a output file name, which must have the extension ``.sol``.
This extension tell to CPLEX to store the solution of the problem into the 
output file.

