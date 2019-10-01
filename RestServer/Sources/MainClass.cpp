/**
 * @Author: Victor Sousa <vicostudio>
 * @Date:   18/04/2018 14:17:52
 * @Email:  victor.sousa@epitech.eu
 * @Last modified by:   vicostudio
 * @Last modified time: 22/04/2018 03:26:00
 */


#include <Rest/Rest.h>
#include "MainClass.h"

MainClass::MainClass(int argc, char *argv[]): AMain(argc, argv, "MainClass") {

}

MainClass::~MainClass() {

}


ArgParser::parser MainClass::setupArgParser() const {
    return ArgParser::parser {{
        { "help", {"-h", "--help"}, "Shows this help message.\n", 0},
        { "port", {"-p", "--port"}, KRED + "[required]" + KNRM + " Set the server port.\n", 1},
        { "router", {"-r", "--router"}, KRED + "[required]" + KNRM + " Set the base router library path.\n", 1}
    }};
}

bool MainClass::Run(ArgParser::parser_results const &args) {

    if (!this->checkArgument(args)) {
        return false;
    }

    API::Rest server(args["router"].as<std::string>(), args["port"].as<u_short>());

    server.run();

    return true;
}

bool MainClass::checkArgument(ArgParser::parser_results const &args) const {
    if (args["help"]) {
        ArgParser::fmt_ostream(std::cerr) << "Usage:" << std::endl << this->setupArgParser();
        return false;
    }

    if (!args["port"]) {
        ArgParser::fmt_ostream(std::cerr) << KRED + "\nYou must provide a server port using -p or --port\n" + KNRM << std::endl << this->setupArgParser();
        return false;
    }

    if (!args["router"]) {
        ArgParser::fmt_ostream(std::cerr) << KRED + "\nYou must provide a base router library path using using -r or --router\n" + KNRM << std::endl << this->setupArgParser();
        return false;
    }

    return true;
}
