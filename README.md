# Advent of Code2021
Find the calendar [here](https://adventofcode.com/2021)

## Setup
Clone the repository and build it via the Makefile by running <i>make</i>
from the command line in the project root.\
Optionally, create a directory named <i>input</i> as the default location for the
input files.

## How it works
<pre>
./aoc21 <i>day [path to input file]</i>
</pre>
The <i>day</i> is expected to be a number between 1 and 25. If it is outside
this range, an error will be issued.\
If no path is provided, the program will look for it in the default <i>input</i>
directory at the project root.
