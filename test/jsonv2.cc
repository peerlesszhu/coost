#include "co/all.h"
#include "co/json.h"

int main(int argc, char** argv) {
    flag::init(argc, argv);
    log::init();

    json::Root r;
    CLOG << r.is_null();

    r.add_member("name", "Bob");
    CLOG << "name: " << r["name"].get_string();

    r.add_member("age", 23);
    CLOG << "age: " << r["age"].get_int();

    r.add_member("male", true);
    CLOG << "male: " << r["male"].get_bool();

    r.add_member("height", 1.88);
    CLOG << "height: " << r["height"].get_double();

    json::Value v = r.add_array("num", 3);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    CLOG << "num: ";
    json::Value n = r["num"];
    for (auto it = n.begin(); it != n.end(); ++it) {
        CLOG << (*it).get_int();
    }

    for (auto it = r.begin(); it != r.end(); ++it) {
        CLOG << it.key() << ":" << it.value();
    }

    auto x = v.push_object();
    x.add_member("x", 3.14);
    
    auto y = x.add_array("yy");
    y.push_back("ddd");
    y.push_back("....");


    CLOG << "size: " << r.size();
    CLOG << "array size: " << n.size();
    CLOG << "string size: " << r["name"].size();
    CLOG << "str:" << r.str();
    CLOG << "pretty: " << r.pretty();

    return 0;
}