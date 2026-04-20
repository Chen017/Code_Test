
typedef unsigned char boolean;

extern boolean isEven(int value);
extern boolean isOdd(int value);
extern int max(int a, int b);
extern int maximum(const int * values, int size);

extern boolean not(boolean a);
extern boolean and(boolean a, boolean b);
extern boolean or(boolean a, boolean b);
extern boolean xor(boolean a, boolean b);
extern boolean all(const boolean * values, int size);

extern int write(const char * string, int length);
extern int strLength(const char * string);
extern int length(const char * string);
extern char char_at(const char * string, int index);
extern int indexOf(const char * string, char symbol);
extern int lastIndexOf(const char * string, char symbol);
extern char * toUppercase(const char * string);
extern char * toLowercase(const char * string);
extern char digitToChar(const unsigned int digit);


void andTruthTable(void);
void xorTruthTable(void);
void orTruthTable(void);
void notTruthTable(void);

void fullAdderTable(void);

boolean evenOddCheck(void);
boolean booleanFunctionsCheck(void);
void extraTaskChecks(void);

boolean fullAdder(boolean a, boolean b, boolean carry, boolean * carryOut);
void printFullAdderResults_line(boolean a, boolean b, boolean carryIn, boolean carryOut, boolean res);

void main(void) {
    const char * helloWorld = "Hello world\n";
    write(helloWorld, strLength(helloWorld));

    write("\n", 1);
    
    notTruthTable();
    write("\n", 1);
    andTruthTable();
    write("\n", 1);
    orTruthTable();
    write("\n", 1);
    xorTruthTable();
    write("\n", 1);

    fullAdderTable();

    const char * oddAndEvenSeemsCorrect = "Both functions even and odd appear to work correctly!\n";
    const char * oddAndEvenAreIncorrect = "Either the even function, odd function, or both, are incorrect!\n";

    if (evenOddCheck()) {
        write(oddAndEvenSeemsCorrect, strLength(oddAndEvenSeemsCorrect));
    } else {
        write(oddAndEvenAreIncorrect, strLength(oddAndEvenAreIncorrect));
    }

    const char * max_1_2_correct = "max(1,2) == 2\n";
    const char * max_1_2_incorrect = "max(1,2) != 2 ???\n";
    const char * max_2_1_correct = "max(2,1) == 2\n";
    const char * max_2_1_incorrect = "max(2,1) != 2 ???\n";

    if (max(1, 2) == 2) {
        write(max_1_2_correct, strLength(max_1_2_correct));
    } else {
        write(max_1_2_incorrect, strLength(max_1_2_incorrect));
    }

    if (max(2, 1) == 2) {
        write(max_2_1_correct, strLength(max_2_1_correct));
    } else {
        write(max_2_1_incorrect, strLength(max_2_1_incorrect));
    }

    write("\n", 1);
    extraTaskChecks();
}

void andTruthTable(void) {
    const char * andTruthTableHeader = "a | b | a and b\n";
    const char * andTruthTableHeaderSeparator = "===============\n";
    write(andTruthTableHeader, strLength(andTruthTableHeader));
    write(andTruthTableHeaderSeparator, strLength(andTruthTableHeaderSeparator));
    for (boolean a = 0; a < 2; a++) {
        for (boolean b = 0; b < 2; b++) {
            char aAndBChar = digitToChar(and(a, b));
            char aChar = digitToChar(a);
            char bChar = digitToChar(b);
            write(&aChar, 1);
            write(" | ", 3);
            write(&bChar, 1);
            write(" |    ", 6);
            write(&aAndBChar, 1);
            write("\n", 1);
        }
    }
}

void xorTruthTable(void) {
    const char * xorTruthTableHeader = "a | b | a xor b\n";
    const char * xorTruthTableHeaderSeparator = "===============\n";
    write(xorTruthTableHeader, strLength(xorTruthTableHeader));
    write(xorTruthTableHeaderSeparator, strLength(xorTruthTableHeaderSeparator));
    for (boolean a = 0; a < 2; a++) {
        for (boolean b = 0; b < 2; b++) {
            char aXorBChar = digitToChar(xor(a, b));
            char aChar = digitToChar(a);
            char bChar = digitToChar(b);
            write(&aChar, 1);
            write(" | ", 3);
            write(&bChar, 1);
            write(" |    ", 6);
            write(&aXorBChar, 1);
            write("\n", 1);
        }
    }
}

void orTruthTable(void) {
    const char * orTruthTableHeader = "a | b | a or b\n";
    const char * orTruthTableHeaderSeparator = "===============\n";
    write(orTruthTableHeader, strLength(orTruthTableHeader));
    write(orTruthTableHeaderSeparator, strLength(orTruthTableHeaderSeparator));
    for (boolean a = 0; a < 2; a++) {
        for (boolean b = 0; b < 2; b++) {
            char aOrBChar = digitToChar(or(a, b));
            char aChar = digitToChar(a);
            char bChar = digitToChar(b);
            write(&aChar, 1);
            write(" | ", 3);
            write(&bChar, 1);
            write(" |    ", 6);
            write(&aOrBChar, 1);
            write("\n", 1);
        }
    }
}

void notTruthTable(void) {
    const char * notTruthTableHeader = "a | not a\n";
    const char * notTruthTableHeaderSeparator = "=========\n";
    write(notTruthTableHeader, strLength(notTruthTableHeader));
    write(notTruthTableHeaderSeparator, strLength(notTruthTableHeaderSeparator));
    for (boolean a = 0; a < 2; a++) {
        char notAChar = digitToChar(not(a));
        char aChar = digitToChar(a);
        write(&aChar, 1);
        write(" |    ", 6);
        write(&notAChar, 1);
        write("\n", 1);
    }
}


boolean evenOddCheck(void) {
    #define EVEN_VALUE 42
    #define ODD_VALUE 47
    const char * isEven42Label = "isEven(42): ";
    const char * isEven47Label = "isEven(47): ";
    const char * isOdd42Label = "isOdd(42): ";
    const char * isOdd47Label = "isOdd(47): ";

    char evenIsEvenChar = digitToChar(isEven(EVEN_VALUE));
    char evenIsOddChar = digitToChar(isOdd(EVEN_VALUE));
    char oddIsEvenChar = digitToChar(isEven(ODD_VALUE));
    char oddIsOddChar = digitToChar(isOdd(ODD_VALUE));
    

    write(isEven42Label, strLength(isEven42Label));
    write(&evenIsEvenChar, 1);
    write("\n", 1);

    write(isEven47Label, strLength(isEven47Label));
    write(&oddIsEvenChar, 1);
    write("\n", 1);

    write(isOdd42Label, strLength(isOdd42Label));
    write(&evenIsOddChar, 1);
    write("\n", 1);

    write(isOdd47Label, strLength(isOdd47Label));
    write(&oddIsOddChar, 1);
    write("\n", 1);
    
    boolean evenIsEven = isEven(EVEN_VALUE);
    boolean evenIsNotOdd = not(isOdd(EVEN_VALUE));
    boolean oddIsOdd = isOdd(ODD_VALUE);
    boolean oddIsNotEven = not(isEven(ODD_VALUE));

    return and(and(evenIsEven, oddIsOdd), and(evenIsNotOdd, oddIsNotEven));
}

boolean booleanFunctionsCheck(void) {
    #define TRUE 1
    #define FALSE 0
    boolean notTrueIsFalse = ! not(TRUE);
    boolean notFalseIsTrue = not(FALSE);
    boolean a = TRUE;
    boolean b = FALSE;
    
    boolean andNeutral = and((and(TRUE, a) == a), (and(TRUE, b) == b));
    boolean andNeutral_reverse = and((and(a, TRUE) == a), (and(b, TRUE) == b));
    
    boolean andFalse = and (! and(FALSE, a), ! and(FALSE, b));
    boolean andFalse_reverse = and (! and(a, FALSE), ! and(b, FALSE));

    boolean values[2] = {TRUE, FALSE};
    boolean deMorgan = TRUE;
    // and A B eq not (not A or not B)
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            boolean a = values[i];
            boolean b = values[j];
            boolean aANDb = and(a, b);
            boolean naORnb = or(not(a), not(b));
            deMorgan = and(deMorgan, aANDb == not(naORnb));
        }
    }
    boolean andNeutralCorrect = and(andNeutral, andNeutral_reverse);
    boolean andFalseCorrect = and(andFalse, andFalse_reverse);
    return and(deMorgan, and(andNeutralCorrect, andFalseCorrect));
}

void extraTaskChecks(void) {
    const char * sample = "assembly";
    const char * charAtLabel = "char_at(\"assembly\", 1): ";
    const char * lengthLabel = "length(\"assembly\"): ";
    const char * indexLabel = "indexOf(\"assembly\", 's'): ";
    const char * lastIndexLabel = "lastIndexOf(\"assembly\", 's'): ";
    const char * maximumLabel = "maximum({4,9,2,7,5}): ";
    const char * allTrueLabel = "all({1,1,1}): ";
    const char * allFalseLabel = "all({1,0,1}): ";
    const char * upperLabel = "toUppercase(\"hello\"): ";
    const char * lowerLabel = "toLowercase(\"WORLD\"): ";
    char sampleSecond = char_at(sample, 1);
    char sampleIndexOfS = digitToChar(indexOf(sample, 's'));
    char sampleLastIndexOfS = digitToChar(lastIndexOf(sample, 's'));
    char sampleLength = digitToChar(length(sample));

    write(charAtLabel, strLength(charAtLabel));
    write(&sampleSecond, 1);
    write("\n", 1);

    write(lengthLabel, strLength(lengthLabel));
    write(&sampleLength, 1);
    write("\n", 1);

    write(indexLabel, strLength(indexLabel));
    write(&sampleIndexOfS, 1);
    write("\n", 1);

    write(lastIndexLabel, strLength(lastIndexLabel));
    write(&sampleLastIndexOfS, 1);
    write("\n", 1);

    int numbers[5] = {4, 9, 2, 7, 5};
    char maximumValue = digitToChar(maximum(numbers, 5));
    write(maximumLabel, strLength(maximumLabel));
    write(&maximumValue, 1);
    write("\n", 1);

    boolean valuesAllTrue[3] = {1, 1, 1};
    boolean valuesNotAllTrue[3] = {1, 0, 1};
    char allTrueResult = digitToChar(all(valuesAllTrue, 3));
    char allFalseResult = digitToChar(all(valuesNotAllTrue, 3));

    write(allTrueLabel, strLength(allTrueLabel));
    write(&allTrueResult, 1);
    write("\n", 1);

    write(allFalseLabel, strLength(allFalseLabel));
    write(&allFalseResult, 1);
    write("\n", 1);

    char upperWord[] = "hello";
    char lowerWord[] = "WORLD";

    toUppercase(upperWord);
    toLowercase(lowerWord);

    write(upperLabel, strLength(upperLabel));
    write(upperWord, strLength(upperWord));
    write("\n", 1);

    write(lowerLabel, strLength(lowerLabel));
    write(lowerWord, strLength(lowerWord));
    write("\n", 1);
}

void fullAdderTable(void) {
    const char * fullAdderResults_header = "a | b | carryIn | res | carryOut\n";
    const char * fullAdderResults_separator = "================================\n";
    write(fullAdderResults_header, strLength(fullAdderResults_header));
    write(fullAdderResults_separator, strLength(fullAdderResults_separator));
    for (boolean a = 0; a < 2; a++) {
        for (boolean b = 0; b < 2; b++) {
            for (boolean carryIn = 0; carryIn < 2; carryIn++) {
                boolean carryOut;
                boolean res = fullAdder(a, b, carryIn, &carryOut);
                printFullAdderResults_line(a, b, carryIn, carryOut, res);
            }
        }
    }
    write("\n", 1);
}

boolean fullAdder(boolean a, boolean b, boolean carry, boolean * carryOut) {
    boolean xor_a_b = xor(a, b);
    boolean sum = xor(carry, xor_a_b);

    boolean and_cin_xor_a_b = and(carry, xor_a_b);
    boolean and_a_b = and(a, b);
    boolean cout = or(and_a_b, and_cin_xor_a_b);

    *carryOut = cout;
    return sum;
}

void printFullAdderResults_line(boolean a, boolean b, boolean carryIn, boolean carryOut, boolean res) {
    char aChar = digitToChar(a);
    char bChar = digitToChar(b);
    char carryInChar = digitToChar(carryIn);
    char carryOutChar = digitToChar(carryOut);
    char resChar = digitToChar(res);
    write(&aChar, 1);
    write(" | ", 3);
    write(&bChar, 1);
    write(" |    ", 6);
    write(&carryInChar, 1);
    write("    |  ", 7);
    write(&resChar, 1);
    write("  |     ", 8);
    write(&carryOutChar, 1);
    write("\n", 1);
}

