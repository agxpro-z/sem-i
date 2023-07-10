/*
    Q6. Write a program in C++ to print Floyd's Triangle by using the
        constructor destructor.
*/

#include <iostream>

using namespace std;

class FloydsTriangle {
    // Pointer member variables
    int* steps, steps_per_step, counter;

  public:
    // Constructor
    FloydsTriangle(int a) : steps_per_step(1), counter(1) {
        if (a <= 0) {
            cout << "Steps cannot be less than 1.\n";
            // Set steps to zero if input is less than 1.
            steps = new int(0);
        } else {
            // Allocate memory and set value.
            steps = new int(a);
        }
    }

    // Destructor
    ~FloydsTriangle() {
        delete steps;
    }

    // Print Floyd's Triangle declaration
    void printTriangle();
};

// Print Floyd's Triangle definition
void FloydsTriangle::printTriangle() {
    for (int i = 0; i < *steps; i++) {
        for (int j = 0; j < steps_per_step; j++) {
            cout << (counter > 99 ? " " : (counter > 9 ? "  " : "   ")) << counter;
            counter++;
        }
        cout << endl;
        steps_per_step++;
    }

    // Reset counter and steps_per_step after printing triangle
    counter = 1;
    steps_per_step = 1;
}

int main() {
    cout << "Enter no. of steps: ";
    int steps;
    cin >> steps;

    FloydsTriangle f(steps);
    f.printTriangle();
    f.printTriangle();

    return 0;
}

/*
        -- OUTPUT --

Test 1:
Enter no. of steps: 10
   1
   2   3
   4   5   6
   7   8   9  10
  11  12  13  14  15
  16  17  18  19  20  21
  22  23  24  25  26  27  28
  29  30  31  32  33  34  35  36
  37  38  39  40  41  42  43  44  45
  46  47  48  49  50  51  52  53  54  55

Test 2:
Enter no. of steps: 15
   1
   2   3
   4   5   6
   7   8   9  10
  11  12  13  14  15
  16  17  18  19  20  21
  22  23  24  25  26  27  28
  29  30  31  32  33  34  35  36
  37  38  39  40  41  42  43  44  45
  46  47  48  49  50  51  52  53  54  55
  56  57  58  59  60  61  62  63  64  65  66
  67  68  69  70  71  72  73  74  75  76  77  78
  79  80  81  82  83  84  85  86  87  88  89  90  91
  92  93  94  95  96  97  98  99 100 101 102 103 104 105
 106 107 108 109 110 111 112 113 114 115 116 117 118 119 120

*/