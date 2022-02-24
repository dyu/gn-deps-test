#include <uWS.h>

int main(int argc, char** argv)
{
    if (argc == 1) {
        printf("First arg (port) is required.\n");
        return 1;
    }
    
    int port = std::stoi(argv[1]);
    uWS::Hub h;

    h.onMessage([](uWS::WebSocket<uWS::SERVER> *ws, char *message, size_t length, uWS::OpCode opCode) {
        ws->send(message, length, opCode);
    });
    
    h.onHttpRequest([](uWS::HttpResponse *res, uWS::HttpRequest req, char *data, size_t length, size_t remainingBytes) {
        res->end("hello get", 9);
    });

    h.listen("127.0.0.1", port);
    h.run();
    
    return 0;
}
