#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <cpprest/json.h>

using namespace web;
using namespace web::http;
using namespace web::http::client;
using namespace concurrency::streams;

pplx::task<void> BingSearch()
{
    http_client client(U("https://api.cognitive.microsoft.com/bing/v7.0/search?q=Microsoft&count=10&offset=0&mkt=en-us&safesearch=Moderate"));
    client.request(methods::GET).then([](http_response response)
    {
        if (response.status_code() == status_codes::OK)
        {
            return response.extract_json();
        }
        return pplx::task_from_result(json::value());
    })
    .then([](json::value jsonValue)
    {
        // Do something with JSON value
    })
    .wait();
}

int main()
{
    BingSearch();
}