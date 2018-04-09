# Langton's Ant

Implementation of a program that simulates Langton’s Ant. For explanation please read it on Wikipedia:  https://en.wikipedia.org/wiki/Langton%27s_ant

Langton’s Ant Rule

The rule of Langton’s Ant is very simple: the ant is placed onto the board that is filled with white spaces, and starts moving forward. For each step forward, the Langton’s ant will follow 2 rules:

    If the ant is on a white space, turn right 90 degrees and change the space to black.
    If the ant is on a black space, turn left 90 degrees and change the space to white.

After that the ant moves to the next step and continue moving forward. The ant will follow these rules, and continue moving around the board, until the number of steps runs out.

## Installing and Running the Program

Compile the program with this command:

```
make langton
```

Run the program with this command:

```
./langton
```

Clean files with this command:

```
make clean
```

## Built With

* C++
