#include <stdio.h>
#include <assert.h>

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

float convertFarenheitToCelcius(float farenheit){
    float celcius = (farenheit - 32) * 5 / 9;
    return celcius
}

void alertInCelcius(float farenheit, int (*fnptrNetworkAlert)(float)) {

    float celcius = convertFarenheitToCelcius(farenheit);
    int returnCode = fnptrNetworkAlert(celcius);

    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        alertFailureCount += 1;
    }
    else{
        //ok response
        //do nothing
    }
}
void test_main(){
    alertInCelcius(400.5, &networkAlertStub);
    assert(alertFailureCount==1);
    alertInCelcius(303.6, &networkAlertStub);
    assert(alertFailureCount==1);
    printf("%d alerts failed.\n", alertFailureCount);
}
int main() {
    test_main();
    printf("All is well (maybe!)\n");
    return 0;
}
