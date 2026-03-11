#include "environment.h"

Environment::Environment() {}

QString Environment::GetBaseUrl()
{
    return "http://localhost:3000";
    // ideana, että voidaan tarvittaessa helposti vaihtaa
    //return "https://myserver.com";
}
