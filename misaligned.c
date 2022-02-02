#include <stdio.h>
#include <assert.h>

const char* MajorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* MinorColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

typedef struct {
    const char* majorColor;
    const char* minorColor;
} ColorPair;

ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    colorPair.majorColor = MajorColorNames[(pairNumber / numberOfMinorColors)];
    colorPair.minorColor = MinorColorNames[(pairNumber % numberOfMinorColors)];
    return colorPair;
}

void testNumberToPair(int pairNumber, const char* expectedMajor, const char* expectedMinor){
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    assert(colorPair.majorColor == expectedMajor);
    assert(colorPair.minorColor == expectedMinor);
}

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[j]);
            testNumberToPair(i * 5 + j, majorColor[i], minorColor[j]);
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
