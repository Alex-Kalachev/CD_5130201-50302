#pragma once

enum LEVEL{STANDART, FAST};
enum TYPE {SYSTEM, FAST_MESSAGE, APP};
struct System
{
    const char* message;
    LEVEL severity;
};

struct Fast_Message
{
    const char* name;
    const char* message;
};

struct App
{
    const char* name_app;
    const char* head;
    const char* text;
};