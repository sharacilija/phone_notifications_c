// this code uses libcurl to send a post request to the
// http server to send a message to your phone via
// the ntfy.sh app

#include <stdio.h>
#include <curl/curl.h>

int main(void)
{
    printf("PROGRAM STARTED\n");

    // curl_version_info_data *info = curl_version_info(CURLVERSION_NOW);
    
    // if (info == NULL)
    // {
    //     printf("curl_version_info returned NULL\n");
    //     return 1;
    // }

    // printf("libcurl version: %s\n", info->version);
    // printf("PROGRAM FINISHED\n");

    // return 0;

    CURL *curl;
    CURLcode result;

    result = curl_global_init(CURL_GLOBAL_ALL);
    if (result != CURLE_OK)
        return (int) result;

    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, 
            "ntfy.sh/ilija_test_notifications");

        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, 
            "testing one last time.");

        result = curl_easy_perform(curl);
    }
}

// $env:PATH = "C:\msys64\mingw64\bin;" + $env:PATH

// curl.exe -d "hi" https://ntfy.sh/ilija_test_notifications