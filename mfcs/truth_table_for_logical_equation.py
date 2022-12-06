#!/bin/env python3
#
# (C) @agxpro
#

from simplify_logic import simplify

# Table to store all possible truth values of all variables in the equation
table = []

# Generate truth table for all the possible combinations
def generate_table(s, n):
    if n == 0:
        table.append(s)
    else:
        for i in range(2):
            if i == 0:
                generate_table(s + 'T', n - 1)
            else:
                generate_table(s + 'F', n - 1)

# Return list of total variables
def total_variables(f):
    # Find number of variables in the equation
    s = set()
    for z in formula:
        if z.isalpha():
            s.add(z)

    # List of all variables in the equation
    s = list(s)
    # Sort variables list
    s.sort()

    return s

print('''\tTruth Table for Logical Equation Generator

  Usage: AND = '&, OR = '|', NOT = '~'
        IMPLICATION = '>', BICONDITIONAL = '-'
''')

# Take logical equation from user
print("Enter value: ", end="")
formula = input()

# List of total variables in the logical equation
s = total_variables(formula)

# Generate truth values for all variables
generate_table("", len(s))

# Get simplified logical equation
simplified_formula = simplify(formula)

print("")
# Print truth table for the given formula
for t in table:
    f = simplified_formula

    # Replace varibles in logical equation with 0's and 1's
    # According to their truth values in the table
    for i in range(0, len(s)):
        f = f.replace(s[i], 'True' if t[i] == 'T' else 'False')

    f = f.replace('~', " not ")
    f = f.replace('&', " and ")
    f = f.replace('|', " or ")

    # Print logical equation with variables truth values take from the table
    for x in range(0, len(s)):
        print(f"{s[x]}='{t[x]}'", end="")
        if x == len(s) - 1:
            print(": ", end="")
        else:
            print(", ", end="")

    e = None
    f = "e = " + f
    exec(f)

    # Print truth value of the equation
    print(e)
