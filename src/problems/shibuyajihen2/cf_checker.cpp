#include "testlib.h"

int main(int argc, char *argv[]) {
    // This command initializes checker environment.
    registerTestlibCmd(argc, argv);
    // Now there are three global variables specifying testlib streams:
    // inf - stream with the testdata.
    // ouf - stream with the contestant output.
    // ans - stream with the jury answer.
    // All those streams provide the similar interface for reading data.

    // This function reads a single integer from the participant output that
    // should be between -2000 and 2000. If it doesn't belong to the specified
    // range, checker finishes with verdict _pe and comment saying that [sum of numbers]
    // is outside of the specified range.
    int pans = ouf.readInt(1, 210, "Exit");

    // This function reads a single integer from the jury output. Here we suppose
    // that jury's answer is correct and we do not need to additionally verify it.
    int jans = ans.readInt(); // We suppose that jury's answer is correct

    if (pans == jans) {
        quitf(_ok, "Is Jury");
        return 0;
    }

    int primes[] = {2, 3, 5, 7};
    int pansPrime = primes[pans - 1];

    if (jans % pansPrime == 0)
        quitf(_ok, "Correct Exit"); // This finishes checker with verdit OK.
    else
        // quitf handles a comment like printf, i. e. you may use specifiers like
        // %d, %s etc in the comment.
        quitf(_wa, "Incorrect Exit");
}
