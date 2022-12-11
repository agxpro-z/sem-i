#!/bin/env python3

# Method to convert infix notation to prefix and postfix using stacks
def infix_to_prefix_postfix(s, prefix=False):
    # Operator precedence
    precedence = {
        '^' : 4,
        '/' : 3,
        '*' : 3,
        '+' : 2,
        '-' : 2,
        '(' : 1,
    }

    # Stack to hold operators temporarily
    stack = []

    # List to hold prefix notation
    prefix_postfix_list = []

    # Remove white spaces from notation and prepare
    # for prefix and postfix conversion
    s = s.replace(' ', '')[::-1] if prefix else s.replace(' ', '')

    for i in s:
        if i.isalnum():
            prefix_postfix_list.append(i)
        elif i == '(':
            stack.append(i)
        elif i == ')':
            # Move all values from stack to prefix_postfix_list until opening parenthesis is found
            top_i = stack.pop()
            while top_i != '(':
                prefix_postfix_list.append(top_i)
                top_i = stack.pop()
        else:
            # Append operator in prefix_postfix_list according to it's precedences
            while (len(stack) != 0) and (precedence[stack[-1]] >= precedence[i]):
                  prefix_postfix_list.append(stack.pop())
            stack.append(i)

    # Move remaining operators from stack to prefix_postfix_list
    while len(stack) != 0:
        prefix_postfix_list.append(stack.pop())

    # Convert prefix_postfix_list to string and return
    return "".join(prefix_postfix_list[::-1]) if prefix else "".join(prefix_postfix_list)

print('\tInfix to prefix and postfix using stacks\n')
print("Enter input: ", end="")
equation = input()
print("Prefix notation: ", infix_to_prefix_postfix(equation, True))
print("Postfix notation:", infix_to_prefix_postfix(equation, False))