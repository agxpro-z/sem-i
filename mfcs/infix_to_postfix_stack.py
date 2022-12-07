#!/bin/env python3

# Method to convert infix notation to postfix using stacks
def infix_to_postfix(s):
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

    # List to hold postfix notation
    postfix_list = []

    # Remove white spaces from notation
    s = s.replace(' ', '')

    for i in s:
        if i.isalnum():
            postfix_list.append(i)
        elif i == '(':
            stack.append(i)
        elif i == ')':
            # Move all values from stack to postfix list until opening parenthesis is found
            top_i = stack.pop()
            while top_i != '(':
                postfix_list.append(top_i)
                top_i = stack.pop()
        else:
            # Append operator in postfix list according to it's precedence
            while (len(stack) != 0) and (precedence[stack[-1]] >= precedence[i]):
                  postfix_list.append(stack.pop())
            stack.append(i)

    # Move remaining operators from stack to postfix list
    while len(stack) != 0:
        postfix_list.append(stack.pop())

    # Convert postfix list to string and return
    return "".join(postfix_list)

print('\tInfix to postfix using stacks\n')
print("Enter input: ", end="")
print(infix_to_postfix(input()))