#!/env python3

'''
    Program to convert propositional logic into simplest form
    containing AND, OR and NOT
'''

# Method to resolve impication
def resolve_implication(s):
    # Keep solving until equation contains implication
    while '>' in s:
        # Remove arbitrary spaces from equation
        s = s.replace(" ", "")

        # Find index of first implication
        index = s.find('>')

        if s[index + 1] == "(":
            # If term after implication is in parenthesis then resolve it first
            # Separating part after implication and solving it recursively
            s = s[:index] + s[index] + resolve_implication(s[index + 1:])
        elif s[index + 1] == "~" and s[index + 2] == "(":
            # Take care of negation if it's present before parenthesis and then resolve
            # Separating part after implication and negation, and solving it recursively
            s = s[:index] + s[index] + "~" + resolve_implication(s[index + 2:])

        # Find index of first implication once again
        index = s.find('>')

        # Declare variables for holding equation coming before and after implication
        pre = post = ''

        # Finding equation coming before implication
        # Note: finding in reverse order
        if s[index - 2] == "~" and s[index - 1].isalpha():
            # If variable contains negation
            pre = s[index - 1] + "~"
        elif s[index - 1].isalpha():
            # If variable does not contains negation 
            pre = s[index - 1]
        else:
            # Value before implication is in parenthesis

            # Temporary string for holding equation coming before implication
            ts = s[:index]
            # Reverse the string
            ts = ts[::-1]

            # Counter for multiple parenthesis
            count = 0

            # Find equation before implication on which implication is applied
            for x in enumerate(ts):
                if x[1] == "(":
                    pre += x[1]
                    if count == 0 or count == 1:
                        # Check if there is negation before parenthesis
                        try:
                            if ts[x[0] + 1] == "~":
                                pre += "~"
                        except:
                            pass
                        break
                    else:
                        count -+ 1
                elif x[1] == ")":
                    pre += x[1]
                    count += 1
                else:
                    pre += x[1]

        # Reverse the reverse string to form original equation
        pre = pre[::-1]

        # Finding equation coming before implication
        if s[index + 1].isalpha():
            post = s[index + 1]
        elif s[index + 1] == "~" and s[index + 2].isalpha():
            # If variable contains negation
            post = "~" + s[index + 2]
        else:
            # Temporary string to hold post equation
            ts = ""

            if s[index + 1] == "~":
                # If there is negation after implication
                ts = "~" + s[index + 2:]
            else:
                ts = s[index + 1:]

            # Counter for multiple parenthesis
            count = 0

            # Find equation on which implicatin is applied
            for x in ts:
                if x == ")":
                    post += x
                    if count == 0 or count == 1:
                        break
                    else:
                        count -+ 1
                elif x == "(":
                    post += x
                    count += 1
                else:
                    post += x

        # Replace implication with equivalent implicationless logic
        s = s.replace(pre + '>' + post, "(~{}|{})".format(pre, post), 1)

        # Remove any double parenthesis, Eg. ((x | y)) to (x | y)
        s = s.replace("((~{}|{}))".format(pre, post), "(~{}|{})".format(pre, post))

        # Remove double nagation
        s = s.replace("~~", "")
    else:
        # Return the implication free logical equation
        return s

# Take logical equation from user
print("Enter value: ", end="")
logic = input()

# Solve and print equation
print(resolve_implication(logic))
