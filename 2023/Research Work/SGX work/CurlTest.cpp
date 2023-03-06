#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eni.h"
#include <curl/curl.h>

// Function to perform web search
ENI_RESULT search_web(const char* query)
{
    ENI_RESULT result = ENI_SUCCESS;

    // Initialize CURL
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();

    if(curl) {
        // Create URL
        char url[100] = "";
        strcat(url, "https://www.youtube.com/results?search_query=");
        strcat(url, query);

        // Set CURL options
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);

        // Perform CURL request
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            printf("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            result = ENI_FAILURE;
        }

        // Cleanup CURL
        curl_easy_cleanup(curl);
    }
    else {
        printf("curl initialization failed\n");
        result = ENI_FAILURE;
    }

    return result;
}

int main()
{
    const char* query = "pop+mix";

    // Initialize ENI
    eni_init();

    // Call ENI function to perform web search
    ENI_RESULT result = eni_call_function(search_web, query);

    // Check if ENI call was successful
    if (result != ENI_SUCCESS) {
        printf("ENI call failed\n");
    }

    // Cleanup ENI
    eni_destroy();

    return 0;
}
