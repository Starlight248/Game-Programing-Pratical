#pragma once
#include <Windows.h>
enum class KeyCode
{
    LEFT_MOUSE_BUTTON = 0x01,
    RIGHT_MOUSE_BUTTON = 0x02,
    CONTROL_BREAK = 0x03, // Cancel (Ctrl+Pause)
    MIDDLE_MOUSE_BUTTON = 0x04,
    X1_MOUSE_BUTTON = 0x05,
    X2_MOUSE_BUTTON = 0x06,
    BACKSPACE = 0x08,
    TAB = 0x09,
    CLEAR = 0x0C,
    ENTER = 0x0D, // Return
    SHIFT = 0x10,
    CONTROL = 0x11, // Ctrl
    ALT = 0x12, // Menu
    PAUSE = 0x13,
    CAPS_LOCK = 0x14,
    ESCAPE = 0x1B, // Esc
    SPACE = 0x20,
    PAGE_UP = 0x21,
    PAGE_DOWN = 0x22,
    END = 0x23,
    HOME = 0x24,
    LEFT_ARROW = 0x25,
    UP_ARROW = 0x26,
    RIGHT_ARROW = 0x27,
    DOWN_ARROW = 0x28,
    SELECT = 0x29,
    PRINT = 0x2A,
    EXECUTE = 0x2B,
    PRINT_SCREEN = 0x2C,
    INSERT = 0x2D,
    DELETE_KEY = 0x2E,
    HELP = 0x2F,
    KEY_0 = 0x30,
    KEY_1 = 0x31,
    KEY_2 = 0x32,
    KEY_3 = 0x33,
    KEY_4 = 0x34,
    KEY_5 = 0x35,
    KEY_6 = 0x36,
    KEY_7 = 0x37,
    KEY_8 = 0x38,
    KEY_9 = 0x39,
    KEY_A = 0x41,
    KEY_B = 0x42,
    KEY_C = 0x43,
    KEY_D = 0x44,
    KEY_E = 0x45,
    KEY_F = 0x46,
    KEY_G = 0x47,
    KEY_H = 0x48,
    KEY_I = 0x49,
    KEY_J = 0x4A,
    KEY_K = 0x4B,
    KEY_L = 0x4C,
    KEY_M = 0x4D,
    KEY_N = 0x4E,
    KEY_O = 0x4F,
    KEY_P = 0x50,
    KEY_Q = 0x51,
    KEY_R = 0x52,
    KEY_S = 0x53,
    KEY_T = 0x54,
    KEY_U = 0x55,
    KEY_V = 0x56,
    KEY_W = 0x57,
    KEY_X = 0x58,
    KEY_Y = 0x59,
    KEY_Z = 0x5A,
    LEFT_WINDOWS = 0x5B,
    RIGHT_WINDOWS = 0x5C,
    NUMPAD_0 = 0x60,
    NUMPAD_1 = 0x61,
    NUMPAD_2 = 0x62,
    NUMPAD_3 = 0x63,
    NUMPAD_4 = 0x64,
    NUMPAD_5 = 0x65,
    NUMPAD_6 = 0x66,
    NUMPAD_7 = 0x67,
    NUMPAD_8 = 0x68,
    NUMPAD_9 = 0x69,
    MULTIPLY = 0x6A, // *
    ADD_KEY = 0x6B, // +
    SEPARATOR = 0x6C,
    SUBTRACT = 0x6D, // -
    DECIMAL = 0x6E, // .
    DIVIDE = 0x6F, // /
    F1 = 0x70,
    F2 = 0x71,
    F3 = 0x72,
    F4 = 0x73,
    F5 = 0x74,
    F6 = 0x75,
    F7 = 0x76,
    F8 = 0x77,
    F9 = 0x78,
    F10 = 0x79,
    F11 = 0x7A,
    F12 = 0x7B,
    NUM_LOCK = 0x90,
    SCROLL_LOCK = 0x91,
    LEFT_SHIFT = 0xA0,
    RIGHT_SHIFT = 0xA1,
    LEFT_CONTROL = 0xA2,
    RIGHT_CONTROL = 0xA3,
    LEFT_ALT = 0xA4,
    RIGHT_ALT = 0xA5
};


enum class TextureType {
    BG1,
    CURSOR,
    NUMBER,

    COUNT,//This must Be last element.

};

enum class SpriteType {
    CHARACTER,
    CURSOR,
    NUM,

    COUNT,//This must Be last element.
};