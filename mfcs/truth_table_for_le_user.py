#!/bin/env python3
#
# (C) @agxpro
#

from simplify_logic import simplify

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

print('''\tTruth Table for Logical Equation Generator User

  Usage: AND = '&, OR = '|', NOT = '~'
        IMPLICATION = '>', BICONDITIONAL = '-'
''')

# Take logical equation from user
print("Enter value: ", end="")
formula = input()

# List of total variables in the logical equation
s = total_variables(formula)

# Get simplified logical equation
simplified_formula = simplify(formula)

# Take Truth values from user
user = []
print("Truth values for the variables: ")
for x in s:
    print(x, " (T/F): ", end="")
    user.append(input())

print("")
# Print truth table for the given formula
f = simplified_formula

# Replace varibles in logical equation with 0's and 1's
# According to their truth values in the table
for i in range(0, len(s)):
    f = f.replace(s[i], '1' if user[i] == 'T' else '0')

f = f.replace('~', " not ")
f = f.replace('&', " and ")
f = f.replace('|', " or ")

# Print logical equation with variables truth values take from the table
for x in range(0, len(s)):
    print(f"{s[x]}='{user[x]}'", end="")
    if x == len(s) - 1:
        print(": ", end="")
    else:
        print(", ", end="")

e = None
f = "e = " + f
exec(f)

# Print truth value of the equation
print('True' if e else 'False')
