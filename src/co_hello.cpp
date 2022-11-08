// http server support both ipv4 and ipv6
//
// build:
//   xmake -b http_serv
//
// start http server:
//   xmake r http_serv                              # 0.0.0.0:80
//   xmake r http_serv -ip 127.0.0.1 -port 7777     # 127.0.0.1:7777
//   xmake r http_serv -ip ::                       # [::]:80  (ipv6)
//   xmake r http_serv -key "key.pem" -ca "ca.pem"  # https://0.0.0.0:443
//   
// NOTE:
//   For ipv6 link-local address, we have to specify the network interface:
//   xmake r http_serv ip=fe80::a00:27ff:fea7:a888%eth0

#include "co/so.h"
#include "co/flag.h"
#include "co/log.h"
#include "co/time.h"

DEF_string(ip, "0.0.0.0", "http server ip");
DEF_int32(port, 8080, "http server port");
DEF_bool(log, false, "log to std out");
DEF_string(key, "", "private key file");
DEF_string(ca, "", "certificate file");

int main(int argc, char** argv) {
    flag::init(argc, argv);
    FLG_cout = FLG_log;

    http::Server serv;
    serv.on_req(
        [](const http::Req& req, http::Res& res) {
            res.set_status(200);
            res.set_body("Hello, World!");
            /*
            if (req.is_method_get()) {
                if (req.url() == "/plaintext") {
                    res.set_status(200);
                    res.set_body("Hello, World!");
                } else {
                    res.set_status(404);
                }
            } else {
                res.set_status(405); // method not allowed
            }
            */
        }
    );

    if (!FLG_key.empty() && !FLG_ca.empty()) {
        if (FLG_port == 80) FLG_port = 443;
        serv.start(FLG_ip.c_str(), FLG_port, FLG_key.c_str(), FLG_ca.c_str());
    } else {
        serv.start(FLG_ip.c_str(), FLG_port);
    }

    while (true) sleep::sec(1024);
    return 0;
}
