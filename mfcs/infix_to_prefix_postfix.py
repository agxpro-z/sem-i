#!/bin/env python3
#
# (C) @agxpro
#

def infix_to_prefix_postfix(s, prefix=False):
    """
        Method to convert simple mathematical infix notation to prefix
        and postfix using recursion and wihout using stacks.

        @ param
            s = string containing infix notation
    """

    # Find index of the op(erator) which is outside '{}'
    def operator_index(s, op):
        # Counter for braces
        count = 0

        # Find index of operator which is not inside braces
        for x in enumerate(s):
            if x[1] == '{':
                count += 1
            elif x[1] == '}':
                count -= 1
            elif count == 0 and x[1] == op:
                # Return index of the operator
                return x[0]

        # Return -1 if index not found
        return -1

    # Convert infix notation to prefix or postfix
    def convert(s, prefix):
        # Remove white spaces
        s = s.replace(' ', '')

        # Remove parenthesis from notation
        # Do until all pairs of parenthesis are removed
        while '(' in s and ')' in s:
            # Count parenthesis
            count = 1

            # Index of outer most parenthesis
            pre_index = s.find('(') # Index of first opening outer most parenthesis
            post_index = len(s) - 1

            # Find the index of the first ending outer most parenthesis
            for x in enumerate(s[pre_index + 1:]):
                if x[1] == '(':
                    count += 1
                elif x[1] == ')':
                    if count == 1:
                        post_index = pre_index + 1 + x[0] # Set index
                        break
                    else:
                        count -= 1

            # Recurse again with the notation inside parenthesis
            # This substring may contain more pair of parenthesis
            # which requires further removal, if not then convert
            # the notation from infix to prefix or postfix
            new_s = convert(s[pre_index + 1 : post_index], prefix)

            # Replace notation inside parenthesis containing more
            # pairs of parenthesis and infix notation with prefix
            # or postfix
            s = s[:pre_index] + new_s + s[post_index + 1:]

        def solve(s, c):
            # Repeat until all notations and sub-notations (notations inside
            # parenthesis) are converted to prefix or postfix
            while (index := operator_index(s, c)) != -1:
                # Temporary strings to hold notation before conversion
                pre_string_first = ''
                pre_string_second = ''
                operator = s[index]
                post_string_first = ''
                post_string_second = ''

                # Find values before operator
                if s[index - 1].isalnum():
                    # Set values if there is only one character before operator
                    pre_string_first = s[:index - 1]
                    pre_string_second = s[index - 1]
                else:
                    # Set values if there is set of values inside braces
                    count = 0
                    for i in reversed(range(len(s[:index]))):
                        if s[i] == '}' and count >= 0:
                            pre_string_second = s[i] + pre_string_second
                            count += 1
                        elif s[i] == '{' and count >= 1:
                            pre_string_second = s[i] + pre_string_second
                            count -= 1
                        else:
                            if count > 0:
                                pre_string_second = s[i] + pre_string_second
                            else:
                                pre_string_first = s[i] + pre_string_first

                # Find values after operator
                if s[index + 1].isalnum():
                    # Set values if there is only one character after operator
                    post_string_first = s[index + 1]
                    post_string_second = s[index + 2:]
                else:
                    # Set values if there is set of values inside braces
                    count = 0
                    for i in range(index + 1, len(s)):
                        if s[i] == '{' and count >= 0:
                            post_string_first = post_string_first + s[i]
                            count += 1
                        elif s[i] == '}' and count >= 1:
                            post_string_first = post_string_first + s[i]
                            count -= 1
                        else:
                            if count > 0:
                                post_string_first = post_string_first + s[i]
                            else:
                                post_string_second = post_string_second + s[i]

                # Merge all value into one, forming prefix or postfix notation
                if prefix:
                    s = pre_string_first + '{' + operator + pre_string_second + post_string_first + '}' + post_string_second
                else:
                    s = pre_string_first + '{' + pre_string_second + post_string_first + operator + '}' + post_string_second

            # Return converted values
            return s

        # Convert all opertors sequentially and return the string
        return solve(solve(solve(solve(solve(s, '^'), '/'), '*'), '+'), '-')

    # Convert infix notation to prefix or postfix
    s = convert(s, prefix)

    # Remove all braces
    s = s.replace('{', '')
    s = s.replace('}', '')

    # Return prefix or postfix notation
    return s

print('\tInfix to prefix and postfix\n')
print("Enter input: ", end="")
equation = input()
print("Prefix notation: ", infix_to_prefix_postfix(equation, True))
print("Postfix notation:", infix_to_prefix_postfix(equation, False))