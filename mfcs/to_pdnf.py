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

print('''\tLogical Equation to PDNF

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
# Print PDNF notation for the given formula
pdnf = '' # PDNF notation holder
for t in table:
    f = simplified_formula

    # Replace varibles in logical equation with 0's and 1's
    # According to their truth values in the table
    for i in range(0, len(s)):
        f = f.replace(s[i], '1' if t[i] == 'T' else '0')

    f = f.replace('~', " not ")
    f = f.replace('&', " and ")
    f = f.replace('|', " or ")

    e = None
    f = "e = " + f
    exec(f)

    # PDNF
    if e == True:
        pdnf += "("
        for x in range(0, len(s)):
            pdnf += "{}".format(s[x] if t[x] == 'T' else f"~{s[x]}")
            if x != len(s) - 1:
                pdnf += " & "

        pdnf += ") | " if t != table[-1] else ")"

# Trim trailing '|'
if pdnf[-2] == '|':
    pdnf = pdnf[:-3]

# Print finalized notation
print(pdnf)
