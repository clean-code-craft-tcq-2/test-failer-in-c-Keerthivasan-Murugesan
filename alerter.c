#include <stdio.h>
#include <assert.h>

#define SW_STUBBED_FOR_TEST 0
#define SW_FOR_PRODUCTION 1

#define SW SW_STUBBED_FOR_TEST

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    if(celcius<=200){
        // Return 200 for ok  
        return 200;
    }
    else{
        printf("ALERT: Temperature is %.1f celcius.\n", celcius);
        // Return 500 for not-ok
        return 500;
    }
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    #if(SW == SW_STUBBED_FOR_TEST)
    int returnCode = networkAlertStub(celcius);
    #endif
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

int main() {
    alertInCelcius(400.5);
    assert(alertFailureCount==1);
    alertInCelcius(303.6);
    assert(alertFailureCount==1);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
