/*
    Q2. In a town, the percentage of men is 52. The percentage of total literacy
        is 48. If total percentage of literate men is 35 of the total population,
        write a program to find the total number of illiterate men and women if
        the population of the town is 80,000.
*/

#include <iostream>

using namespace std;
 
void printQ() {
    cout << "Q2. In a town, the percentage of men is 52. The percentage of total literacy\n"
                "is 48. If total percentage of literate men is 35 of the total population,\n"
                "write a program to find the total number of illiterate men and women if\n"
                "the population of the town is 80,000.\n";
}

void printAns() {
    int percentageOfPopulation = 100;
    int percentageOfMen = 52;
    int percentageOfWomen = percentageOfPopulation - percentageOfMen;
    int percentageOfTotalLiteracy = 48;
    int percentageOfTotalIlliteracy = 100 - 48;
    int percentageOfLiterateMen = 35;
    int percentageOfIlliterateMen = percentageOfMen - percentageOfLiterateMen;
    int percentageOfLiterateWomen = percentageOfTotalLiteracy - percentageOfLiterateMen;
    int percentageOfIlliterateWomen = percentageOfWomen - percentageOfLiterateWomen;

    int totalPopulation = 80000;
    int totalLiterateMen = totalPopulation * percentageOfLiterateMen / 100;
    int totalIlliterateMen = totalPopulation * percentageOfIlliterateMen / 100;
    int totalLiterateWomen = totalPopulation * percentageOfLiterateWomen / 100;
    int totalIlliterateWomen = totalPopulation * percentageOfIlliterateWomen / 100;

    cout << "\nAns.:";
    cout << "\tTotal literate men = " << totalLiterateMen << '\n';
    cout << "\tTotal literate women = " << totalLiterateWomen << '\n';
    cout << "\tTotal illiterate men = " << totalIlliterateMen << '\n';
    cout << "\tTotal illiterate women = " << totalIlliterateWomen << '\n';
}

int main() {
    printQ();
    printAns();
    return 0;
}

/*
        -- OUTPUT --

Q2. In a town, the percentage of men is 52. The percentage of total literacy
is 48. If total percentage of literate men is 35 of the total population,
write a program to find the total number of illiterate men and women if
the population of the town is 80,000.

Ans.:   Total literate men = 28000
        Total literate women = 10400
        Total illiterate men = 13600
        Total illiterate women = 28000

*/