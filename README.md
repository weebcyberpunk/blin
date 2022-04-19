# Blin

Blin stands for "Breakline in". Started as an exercise, I actually founded it very useful. It receives input from stdin or file and copies it to stdout or file, breaking lines in the last blank before an character limit.

## Installation

Arch Linux and Arch-based Linux distributions users can install it from AUR with the package `blin-git`.  
Others can install via `# make install` and uninstall via `# make uninstall`

## Usage

The basic use is: `$ blin <num>`. This will receive input from _stdin_ and print to _stdout_, breaking the lines in the last blank character before the character limit.

You can specify files too: `$ blin <num> <input file> <output file>` will receive input from `input file` and print to `output file`. If one of the files specified is `-`, it defaults to _stdin_ or _stdout_.
